#include <iostream>

int get_fibonacci_last_digit(int n) {
  //write your code here
  	int i = 0;
	if (n <= 1)
	{
		return n;
	}
	else
	{
		int F[n + 1];
		F[0] = 0;
		F[1] = 1;
		for (i = 2; i < n + 1; i ++)
		{
			F[i] = (F[i - 1] + F[i - 2])%10;
		}
		return F[n];
	}
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
