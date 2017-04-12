#include <iostream>
#include <vector>

using std::vector;
using std::swap;

class tuple
{
	public:
	int m1;
	int m2;
	void initialize(int a);
};

void tuple::initialize(int a)
{
	m1 = a;
	m2 = a;
}

tuple partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);

  tuple m;
  m.initialize(j);
  for (int i = l; i < j; i++)
  {
	  if(a[i] == a[j])
	  {
		  swap(a[i], a[j-1]);
		  m.m1 = j -1;
	  }
  }
  for (int i = j + 1; i < r; i ++)
  {
	  if(a[i] == a[j])
	  {
		  swap(a[i], a[j+1]);
		  m.m2 = j + 1;
	  }
  }
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
