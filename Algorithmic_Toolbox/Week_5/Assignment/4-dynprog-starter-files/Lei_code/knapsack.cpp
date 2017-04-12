#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int m = (int)w.size() + 1;
  int n = W + 1;
  vector<vector<int>> weight;
  weight.resize(m);
  for (int i = 0; i < m; i ++)
  {
	  weight[i].resize(n);
  }
  for (int j = 0; j < n; j ++)
  {
	  weight[0][j] = 0;
  }
  for (int i = 0; i < m; i ++)
  {
	  weight[i][0] = 0;
  }


  for (int i = 1; i < m; i ++)
  {
	  for (int j = 1; j < n; j ++)
	  {
		  weight[i][j] = weight[i - 1][j];
		  if (w[i - 1] <= j)
		  {
			  int weight_temp = weight[i - 1][j - w[i - 1]] + w[i - 1];
			  if (weight_temp > weight[i][j])
			  {
				  weight[i][j] = weight_temp;
			  }
		  }
	  }
  }
  /*
  for (int i = 0; i < m; i ++)
  {
	  for (int j = 0; j < n ; j ++)
	  {
		  std::cout << weight[i][j] << ' ';
	  }
	  std::cout << '\n';

  }*/
  return weight[m - 1][n - 1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
