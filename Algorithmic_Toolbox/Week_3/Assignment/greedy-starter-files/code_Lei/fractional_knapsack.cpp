#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) 
{
  double value = 0.0;
  int bag_capacity = capacity;

  // write your code here
  vector<double> unit_value(n);

  
  for (int i = 0; i < n; i ++)
  {
	  unit_value[i] = (double)values[i]/weights[i];
  }
  /*
  for (int i =0; i < n; i ++)
  {
      std::cout << "****" << unit_value[i] << "****" << '\n';
  }
  */
  // Sort unit_value[n] with certain algorithm
  // The best algorithm has O(nlogn) which I am not implementing here

  // Initialize item_id
  vector<int> item_id(n);
  for (int i = 0; i < n; i ++)
  {
	  item_id[i] = i;
  }

  // Sort items based on their unit_value
  for (int i = 0; i < n; i ++)
  {
	  double max = unit_value[i];
	  int max_id = i;
	  double unit_value_temp = 0;
	  int item_id_temp = 0;

	  for (int j = i; j < n; j ++)
	  {
		  if (unit_value[j] > max)
		  {
			  max = unit_value[j];
			  max_id = j;
		  }
	  }
	  unit_value_temp = unit_value[i];
	  unit_value[i] = max;
	  unit_value[max_id] = unit_value_temp;

	  item_id_temp = item_id[i];
	  item_id[i] = item_id[max_id];
	  item_id[max_id] = item_id_temp;
	  
  }
  /*
  for (int i =0; i < n; i ++)
  {
      std::cout << unit_value[i] << '\n';
      std::cout << item_id[i] << '\n';
  }
  */
  

  // Sort weights and values accordingly
  vector<int> values_sorted(n);
  vector<int> weights_sorted(n);
  for (int i =0; i < n; i ++)
  {
	  values_sorted[i] = values[item_id[i]];
	  weights_sorted[i] = weights[item_id[i]];
  }


  // Fractional knapsack
  for (int i =0; i < n; i ++)
  {
	  if (bag_capacity == 0)
	  {
		  return value;
	  }
	  else if (bag_capacity >= weights_sorted[i])
	  {
		  value = value + values_sorted[i];
		  bag_capacity = bag_capacity - weights_sorted[i];
	  }
	  else
	  {
		  value = value + (double)values_sorted[i]*bag_capacity/weights_sorted[i];
		  bag_capacity = 0;
	  }

  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}