#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

void InOrderTraversal(vector<int> &key, vector<int> &left, vector<int> &right, int tree_index, vector<int> &result)
{
	if (left[tree_index] == -1 && right[tree_index] == -1)
	{
		result.push_back(key[tree_index]);
		return;
	}
	else if (left[tree_index] == -1 && right[tree_index] != -1)
	{
		result.push_back(key[tree_index]);
		InOrderTraversal(key, left, right, right[tree_index], result);
		return;
	}
	else if (left[tree_index] != -1 && right[tree_index] == -1)
	{
		InOrderTraversal(key, left, right, left[tree_index], result);
		result.push_back(key[tree_index]);
		return;
	}
	else
	{
		InOrderTraversal(key, left, right, left[tree_index], result);
		result.push_back(key[tree_index]);
		InOrderTraversal(key, left, right, right[tree_index], result);
		return;
	}
}

void PreOrderTraversal(vector<int> &key, vector<int> &left, vector<int> &right, int tree_index, vector<int> &result)
{
	if (left[tree_index] == -1 && right[tree_index] == -1)
	{
		result.push_back(key[tree_index]);
		return;
	}
	else if (left[tree_index] == -1 && right[tree_index] != -1)
	{
		result.push_back(key[tree_index]);
		PreOrderTraversal(key, left, right, right[tree_index], result);
		return;
	}
	else if (left[tree_index] != -1 && right[tree_index] == -1)
	{
		result.push_back(key[tree_index]);
		PreOrderTraversal(key, left, right, left[tree_index], result);
		return;
	}
	else
	{
		result.push_back(key[tree_index]);
		PreOrderTraversal(key, left, right, left[tree_index], result);
		PreOrderTraversal(key, left, right, right[tree_index], result);
		return;
	}
}

void PostOrderTraversal(vector<int> &key, vector<int> &left, vector<int> &right, int tree_index, vector<int> &result)
{
	if (left[tree_index] == -1 && right[tree_index] == -1)
	{
		result.push_back(key[tree_index]);
		return;
	}
	else if (left[tree_index] == -1 && right[tree_index] != -1)
	{
		PostOrderTraversal(key, left, right, right[tree_index], result);
		result.push_back(key[tree_index]);
		return;
	}
	else if (left[tree_index] != -1 && right[tree_index] == -1)
	{
		PostOrderTraversal(key, left, right, left[tree_index], result);
		result.push_back(key[tree_index]);
		return;
	}
	else
	{
		PostOrderTraversal(key, left, right, left[tree_index], result);
		PostOrderTraversal(key, left, right, right[tree_index], result);
		result.push_back(key[tree_index]);
		return;
	}
}


class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }


  vector <int> in_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
	InOrderTraversal(key, left, right, 0, result);
    return result;
  }

  vector <int> pre_order() {
    vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    PreOrderTraversal(key, left, right, 0, result);
    return result;
  }

  vector <int> post_order() {
    vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    PostOrderTraversal(key, left, right, 0, result);
    return result;
  }
};

void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}
