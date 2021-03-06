#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class TreeHeight {
  int n;
  int root;
  vector<int> parent;
  vector<vector<int>> children;

public:
  void read() 
  {
    std::cin >> n;
    parent.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> parent[i];
	// Create children relationship
	for (int i = 0; i < n; i++)
	{
		children[parent[i]].push_back(i);
	}
	// Find root
	for (int i = 0; i < n; i++)
	{
		if (parent[i] == -1)
		{
			root = i;
			break;
		}
	}
  }
  

  int compute_height(vector<vector<int>> children = &children, int node = &root) 
  {
	  if (children[node].empty())
	  {
		  return 0;
	  }
	  else
	  {
		  int max = 0;
		  for (int i = 0; i < children[node].size(); i++)
		  {
			  int temp = compute_height(children, children[node][i]);
			  if (temp > max)
			  {
				  max = temp;
			  }

		  }
		  return 1 + max;
	  }
	  
  }
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
