#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class TreeHeight {
  int n;
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
  }
  

  int compute_height() 
  {
	  int height_max = 0;
	  for (int i = 0; i < n; i++)
	  {
		  if (children[i].empty() == true)
		  {
			  int height = 0;
			  for (int j = i; j != -1; j = parent[j])
			  {
				  height ++;
			  }
			  height_max = std::max(height_max, height);
		  }
	  }	
	  return height_max;
  }
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
