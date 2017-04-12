#include <iostream>
#include <vector>

using std::vector;
using std::swap;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  vector<int> d;
  size_t left_start = left;
  size_t left_end = ave;
  size_t right_start = ave;
  size_t right_end = right;
  
  /*for (size_t i = 0; i < a.size(); i++) {
    std::cout << a[i];
  }*/  

  while (left_start < left_end && right_start < right_end)
  {
	  if (a[left_start] <= a[right_start])
	  {
		  d.push_back(a[left_start]);
		  left_start ++;
	  }
	  else
	  {
		  d.push_back(a[right_start]);
		  right_start ++;
		  number_of_inversions = number_of_inversions + left_end - left_start;
	  }
  }
  while (left_start < left_end)
  {
	  d.push_back(a[left_start]);
	  left_start ++;
  }
  while (right_start < right_end)
  {
	  d.push_back(a[right_start]);
	  right_start ++;
  }
  for (size_t i = left; i < right; i ++)
  {
	  a[i] = d[i - left];
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}