#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int measure_height(vector<vector<int>> children, int node)
{
	if (children[node].empty())
	{
		return 1;
	}
	else
	{
		int max = 0;
		for (int i = 0; i < children[node].size(); i++)
		{
			int temp = measure_height(children, children[node][i]);
			if (temp > max)
			{
				max = temp;
			}
		}
		return 1 + max;
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

		return measure_height(children, root);
	}
};



int main() {
	std::ios_base::sync_with_stdio(0);
	TreeHeight tree;
	tree.read();
	std::cout << tree.compute_height() << std::endl;
}
