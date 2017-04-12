#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

int min(int a, int b, int c)
{
	int minimum = a;
	if (b < minimum)
	{
		minimum = b;
	}
	if (c < minimum)
	{
		minimum = c;
	}
	return minimum;
}

int edit_distance(const string &str1, const string &str2) 
{
  //write your code here
  
  int m = str1.size() + 1;
  int n = str2.size() + 1;
  vector<vector<int>> distance;
  distance.resize(m);
  for (int i = 0; i < m; i ++)
  {
	  distance[i].resize(n);
  }
  for (int j = 0; j < n; j ++)
  {
	  distance[0][j] = j;
  }
  for (int i = 0; i < m; i ++)
  {
	  distance[i][0] = i;
  }
  for (int j = 1; j < n; j ++)
  {
	  for (int i = 1; i < m; i ++)
	  {
		  int insertion = distance[i][j - 1] + 1;
		  int deletion = distance[i - 1][j] + 1;
		  int match = distance[i - 1][j - 1];
		  int mismatch = distance[i - 1][j - 1] + 1;
		  if (str1[i - 1] == str2[j - 1])
		  {
			  distance[i][j] = min(insertion, deletion, match);
		  }
		  else
		  {
			  distance[i][j] = min(insertion, deletion, mismatch);
		  }
	  }
  }
  
  return distance[m - 1][n - 1];

}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
