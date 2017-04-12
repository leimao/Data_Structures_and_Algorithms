#include <iostream>
#include <vector>
#include <math.h>

// Some explanation
// num_summand = 1, n1 = 1
// num_summand = 2, n2 = 1 + 2 = 3
// num_summand = 3, n3 = 1 + 2 + 3 = 6
// ...
// Any number between n_x and n_x+1 have num_summand = x 

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int num_summands = 0;
  num_summands = 1.0/2*(-1+sqrt(1+4*2*(double)n));
  //std::cout << "aaa" << num_summands << "aaa";
  for (int i = 0; i < num_summands - 1; ++ i)
  {
	  summands.push_back(i + 1);
  }
  summands.push_back(n - (num_summands-1)*num_summands/2);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}