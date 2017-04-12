#include <iostream>

long long get_fibonaccihuge(long long n, long long m)
{
	long long F_remainder[2];
	F_remainder[0] = 0;
	F_remainder[1] = 1;
	long long F_remainder_temp[2];
	long long period = 0;
	long long remainder = 0;
	if (n <= 1)
	{
		return F_remainder[n]; //F0 = 0 0 has remainder of 0 for all dividers
	}
	else
	{
		long long i = 2;
		while(i < n + 1)
		{
			F_remainder_temp[0] = F_remainder[0];
			F_remainder_temp[1] = F_remainder[1];
			F_remainder[0] = F_remainder_temp[1];
			F_remainder[1] = (F_remainder_temp[0] + F_remainder_temp[1])%m;
			//std::cout << F_remainder[i];
			if (F_remainder[0] == 0 && F_remainder[1] == 1)
			{
				period = i - 1;
				remainder = get_fibonaccihuge(n%period, m);
				break;
			}
			if (i == n)
			{
				remainder = F_remainder[1];
				break;
			}
			i ++;
		}

	}
	return remainder;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
