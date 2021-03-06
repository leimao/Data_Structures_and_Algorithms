// Calculate tree height from leaves to root. Time out in test.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class TreeHeight {
	int n;
	vector<int> parent;
	

public:
	void read()
	{
		std::cin >> n;
		parent.resize(n);
		for (int i = 0; i < n; i++)
			std::cin >> parent[i];
	}


	int compute_height()
	{
		// Create children relationship
		vector<vector<int>> children(n);
		for (int i = 0; i < n; i++)
		{
			if (parent[i] != -1)
			{
				children[parent[i]].push_back(i);
			}
		}
		int height_max = 0;
		for (int i = 0; i < n; i++)
		{
			if (children[i].empty() == true)
			{
				int height = 0;
				for (int j = i; j != -1; j = parent[j])
				{
					height++;
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
