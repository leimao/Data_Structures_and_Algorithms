#include <iostream>

int get_change(int n) {
  //write your code here
  int m = 0;
  int integer = n;
  int coin[3] = {10, 5, 1};
  for (int i = 0; i < 3; i ++)
  {
	  if (integer >= coin[i])
	  {
		  m = m + integer/coin[i];
		  integer = integer%coin[i];
	  }
	  else
	  {
		  continue;
	  }
  }
  return m;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
