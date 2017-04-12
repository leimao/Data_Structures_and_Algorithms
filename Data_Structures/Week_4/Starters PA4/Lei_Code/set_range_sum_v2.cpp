#include <cstdio>
#include <iostream>

// Splay tree implementation

// Vertex of a splay tree
struct Vertex {
  int key;
  // Sum of all the keys in the subtree - remember to update
  // it after each operation that changes the tree.
  long long sum;
  Vertex* left;
  Vertex* right;
  Vertex* parent;

  Vertex(int key, long long sum, Vertex* left, Vertex* right, Vertex* parent) 
  : key(key), sum(sum), left(left), right(right), parent(parent) {}
};

void update(Vertex* v) {
  if (v == NULL) return;
  v->sum = v->key + (v->left != NULL ? v->left->sum : 0ll) + (v->right != NULL ? v->right->sum : 0ll);
  if (v->left != NULL) {
    v->left->parent = v;
  }
  if (v->right != NULL) {
    v->right->parent = v;
  }
}

void small_rotation(Vertex* v) {
  Vertex* parent = v->parent;
  if (parent == NULL) {
    return;
  }
  Vertex* grandparent = v->parent->parent;
  if (parent->left == v) {
    Vertex* m = v->right;
    v->right = parent;
    parent->left = m;
  } else {
    Vertex* m = v->left;
    v->left = parent;
    parent->right = m;
  }
  update(parent);
  update(v);
  v->parent = grandparent;
  if (grandparent != NULL) {
    if (grandparent->left == parent) {
      grandparent->left = v;
    } else {
      grandparent->right = v;
    }
  }
}

void big_rotation(Vertex* v) {
  if (v->parent->left == v && v->parent->parent->left == v->parent) {
    // Zig-zig
    small_rotation(v->parent);
    small_rotation(v);
  } else if (v->parent->right == v && v->parent->parent->right == v->parent) {
    // Zig-zig
    small_rotation(v->parent);
    small_rotation(v);
  } else {
    // Zig-zag
    small_rotation(v);
    small_rotation(v);
  }  
}

// Makes splay of the given vertex and makes
// it the new root.
void splay(Vertex*& root, Vertex* v) {
  if (v == NULL) return;
  while (v->parent != NULL) {
    if (v->parent->parent == NULL) {
      small_rotation(v);
      break;
    }
    big_rotation(v);
  }
  root = v;
}

// Searches for the given key in the tree with the given root
// and calls splay for the deepest visited node after that.
// If found, returns a pointer to the node with the given key.
// Otherwise, returns a pointer to the node with the smallest
// bigger key (next value in the order).
// If the key is bigger than all keys in the tree, 
// returns NULL.
Vertex* find(Vertex*& root, int key) {
  Vertex* v = root;
  Vertex* last = root;
  Vertex* next = NULL;
  while (v != NULL) {
    if (v->key >= key && (next == NULL || v->key < next->key)) {
      next = v;
    }
    last = v;
    if (v->key == key) {
      break;      
    }
    if (v->key < key) {
      v = v->right;
    } else {
      v = v->left;
    }
  }
  splay(root, last);
  return next;
}

void split(Vertex* root, int key, Vertex*& left, Vertex*& right) {
  right = find(root, key);
  splay(root, right);
  if (right == NULL) {
    left = root;
    return;
  }
  left = right->left;
  right->left = NULL;
  if (left != NULL) {
    left->parent = NULL;
  }
  update(left);
  update(right);
}

Vertex* merge(Vertex* left, Vertex* right) {
  if (left == NULL) return right;
  if (right == NULL) return left;
  Vertex* min_right = right;
  while (min_right->left != NULL) {
    min_right = min_right->left;
  }
  splay(right, min_right);
  right->left = left;
  update(right);
  return right;
}


Vertex* left_descendant(Vertex* node)
{
	if (node->left == NULL)
	{
		return node;
	}
	else
	{
		return left_descendant(node->left);
	}
}

Vertex* right_ancestor(Vertex* node)
{
	if (node->key < node->parent->key)
	{
		return node->parent;
	}
	else
	{
		return right_ancestor(node->parent);
	}
}

Vertex* next(Vertex* node)
{
	if (node->right != NULL)
	{
		return left_descendant(node->right);
	}
	else
	{
		return right_ancestor(node);
	}
}

// Code that uses splay tree to solve the problem

Vertex* root = NULL;

void insert(int x) {
  Vertex* left = NULL;
  Vertex* right = NULL;
  Vertex* new_vertex = NULL;  
  split(root, x, left, right);
  if (right == NULL || right->key != x) {
    new_vertex = new Vertex(x, x, NULL, NULL, NULL);
  }
  root = merge(merge(left, new_vertex), right);
}

void erase(int x) {                   
  // Implement erase yourself
  Vertex* node = NULL;
  Vertex* left = NULL;
  Vertex* right = NULL;
  node = find(root, x);
  splay(root, next(node));
  splay(root, node);
  split(root, x, left, right);
  root = merge(left, right);
}

bool find(int x) {  
  // Implement find yourself
  Vertex* node = NULL;
  node = find(root, x);
  if (node->key == x)
  {
	  return true;
  }
  else
  {
	  return false;
  }
}

long long sum(int from, int to) {
  Vertex* left = NULL;
  Vertex* middle = NULL;
  Vertex* right = NULL;
  split(root, from, left, middle);
  split(middle, to + 1, middle, right);
  long long ans = 0;
  // Complete the implementation of sum
  // Compute the sum of middle tree
  ans = middle->left->sum + middle->right->sum;

  return ans;  
}

const int MODULO = 1000000001;

int main(){
  int n;
  scanf_s("%d", &n);
  int last_sum_result = 0;
  for (int i = 0; i < n; i++) {
    char buffer[10];
    scanf_s("%s", buffer);  //read '+', '-', '?' and 's'
    char type = buffer[0];
    switch (type) {
      case '+' : {
        int x;
        scanf_s("%d", &x);
        insert((x + last_sum_result) % MODULO);
      } break;
      case '-' : {
        int x;
        scanf_s("%d", &x);
        erase((x + last_sum_result) % MODULO);
      } break;            
      case '?' : {
        int x;
        scanf_s("%d", &x);
        printf(find((x + last_sum_result) % MODULO) ? "Found\n" : "Not found\n");
      } break;
      case 's' : {
        int l, r;
        scanf_s("%d %d", &l, &r);
        long long res = sum((l + last_sum_result) % MODULO, (r + last_sum_result) % MODULO);
        printf("%lld\n", res);
        last_sum_result = int(res % MODULO);
      }
    }
  }
  return 0;
}