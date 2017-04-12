#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


// recursive

vector<int> optimal_sequence(int n) {
  std::vector<int> array(n + 1);
  array[0] = 0;
  array[1] = 0;
  for (int i = 2; i < n + 1; i ++)
  {
	  int count = array[i - 1] + 1; // C(n-1) + 1
	  int min = count;
	  if (i % 2 == 0)
	  {
		  count = array[i / 2] + 1;
		  if (count < min)
		  {
			  min = count;
		  }
	  }
	  if (i % 3 == 0)
	  {
		  count = array[i / 3] + 1;
		  if (count < min)
		  {
			  min = count;
		  }
	  }
	  array[i] = min;
  }

  std::vector<int> sequence(array[n] + 1);
  sequence[array[n]] = n;

  for (size_t i = sequence.size() - 1; i > 0; i --)
  {
	  if (sequence[i] % 3 == 0 && array[sequence[i] / 3] == i - 1)
	  {
		  sequence[i - 1] = sequence[i] / 3;
	  }
	  else if (sequence[i] % 2 == 0 && array[sequence[i] / 2] == i - 1)
	  {
		  sequence[i - 1] = sequence[i] / 2;
	  }
	  else
	  {
		  sequence[i - 1] = sequence[i] - 1;
	  }
  }

  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
