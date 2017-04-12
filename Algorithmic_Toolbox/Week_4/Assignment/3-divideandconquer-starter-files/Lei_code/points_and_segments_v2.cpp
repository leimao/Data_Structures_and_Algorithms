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


tuple partition3(vector<int> &a, vector<int> &b, int l, int r) {
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
	  swap(b[i], b[j]);
    }
	else if (a[i] == x)
	{
		j++;
		swap(a[i], a[j]);
		swap(b[i], b[j]);
		m.m1++;
		swap(a[j], a[m.m1]);
		swap(b[j], b[m.m1]);
		/*int m3 = m.m1;
		while (m3 > l)
		{
			if (b[m3] > b[m3 - 1])
			{
				swap(b[m3], b[m3 - 1]);
				m3 --;
			}
			if (b[m3] <= b[m3 - 1])
			{
				break;
			}
		}*/
	}
  }
  for (int i = l; i <= m.m1; i++)
  {
	  swap(a[i], a[l + j -i]);
	  swap(b[i], b[l + j -i]);
  }
  m.m1 = j - m.m1 + l;
  m.m2 = j;
  return m;
}

void randomized_quick_sort(vector<int> &a, vector<int> &b, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  swap(b[l], b[k]);
  tuple m = partition3(a, b, l, r);

  randomized_quick_sort(a, b, l, m.m1 - 1);
  randomized_quick_sort(a, b, m.m2 + 1, r);
}



vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here

  //sort segments
  randomized_quick_sort(starts, ends, 0, starts.size()-1);
  //std::cout << "***************" << '\n';
  /*for (size_t i = 0; i < starts.size(); i ++)
  {
	  std::cout << starts[i] << " " << ends[i] << '\n';
  }*/
  //std::cout << "***************" << '\n';

  for (size_t i = 0; i < points.size(); i ++)
  {
	  size_t j = 0;
	  cnt[i] = 0;
	  while (points[i] >= starts[j] && j < starts.size())
	  {
		  if (points[i] <= ends[j])
		  {
			  cnt[i] ++;
		  }
		  j ++;
	  }
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
