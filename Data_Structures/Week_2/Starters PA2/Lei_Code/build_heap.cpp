#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

int Left_child(int i)
{
	return 2*i + 1;
}

int Right_child(int i)
{
	return 2*i + 2;
}

void Shift_down(vector<int> &array, int i, vector<pair<int, int>> &swaps_)
{
	int size = array.size();
	int index_min = i;
	int l = Left_child(i);
	if (l < size && array[l] < array[index_min])
	{
		index_min = l;
	}
	int r = Right_child(i);
	if (r < size && array[r] < array[index_min])
	{
		index_min = r;
	}
	if (i != index_min)
	{
		swaps_.push_back(make_pair(i, index_min));
		swap(array[i], array[index_min]);
		Shift_down(array, index_min, swaps_);
	}
}

void Build_heap(vector<int> &array, vector<pair<int, int>> &swaps_)
{
	int size = array.size();
	for (int i = size / 2; i >= 0; i --)
	{
		Shift_down(array, i, swaps_);
	}
}

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    

	
	Build_heap(data_, swaps_);
	
	
	
	/*
	for (int i = 0; i < data_.size(); ++i)
      for (int j = i + 1; j < data_.size(); ++j) {
        if (data_[i] > data_[j]) {
          swap(data_[i], data_[j]);
          swaps_.push_back(make_pair(i, j));
        }
      }
	 */
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
