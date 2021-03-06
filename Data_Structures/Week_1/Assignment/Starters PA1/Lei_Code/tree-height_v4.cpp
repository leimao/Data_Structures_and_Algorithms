#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void measure_depth(vector<vector<int>> children, int node, int level, vector<int> &depth)
{
	depth[node] = level + 1;
	for (int i = 0; i < children[node].size(); i++)
	{
		measure_depth(children, children[node][i], depth[node], depth);
	}
}

class TreeHeight
{
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

		// Find root
		int root;
		for (int i = 0; i < n; i++)
		{
			if (parent[i] == -1)
			{
				root = i;
				break;
			}
		}

		// Create depth vector
		vector<int> depth(n);
		
		// Calculate depth of each node
		measure_depth(children, root, 0, depth);

		int max_height = 0;
		for (int i = 0; i < n; i++)
		{
			if (depth[i] > max_height)
			{
				max_height = depth[i];
			}
		}


		return max_height;
	}
};



int main() {
	std::ios_base::sync_with_stdio(0);
	TreeHeight tree;
	tree.read();
	std::cout << tree.compute_height() << std::endl;
}
