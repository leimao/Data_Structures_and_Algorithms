#include <iostream>
#include <vector>

using std::vector;
using std::swap;

class tuple
{
	public:
	int m1;
	int m2;
};

tuple partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  tuple m;
  m.m1 = l;
  m.m2 = j;
  for (int i = l + 1; i <= r; i++) 
  {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
	else if (a[i] == x)
	{
		j++;
		swap(a[i], a[j]);
		m.m1++;
		swap(a[j], a[m.m1]);
	}
  }
  for (int i = l; i <= m.m1; i++)
  {
	  swap(a[i], a[l + j -i]);
  }
  m.m1 = j - m.m1 + l;
  m.m2 = j;
  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  tuple m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.m1 - 1);
  randomized_quick_sort(a, m.m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
