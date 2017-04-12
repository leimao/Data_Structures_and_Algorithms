#include <iostream>

int gcd(int a, int b) 
{
  int max = 0;
  int min = 0;
  if (b >= a)
  {
	  max = b;
	  min = a;
  }
  else
  {
	  max = a;
	  min = b;
  }

  if (min == 0)
  {
	  return max;
  }
  else
  {
	  return gcd(min, max%min);
  }
}

long long int lcm(int a, int b) {
  //write your code here
  long long int p = (long long) a/(long long)gcd(a,b)*(long long)b;
  return p;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}