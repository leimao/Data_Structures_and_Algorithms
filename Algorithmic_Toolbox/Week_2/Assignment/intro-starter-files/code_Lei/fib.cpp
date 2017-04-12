#include <iostream>

int calc_fib(int n) {
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
			F[i] = F[i - 1] + F[i - 2];
		}
		return F[n];
	}
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << calc_fib(n) << '\n';
    return 0;
}