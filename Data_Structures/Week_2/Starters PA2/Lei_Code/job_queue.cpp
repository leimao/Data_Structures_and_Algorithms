#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;

int Left_child(int i)
{
	return 2*i + 1;
}

int Right_child(int i)
{
	return 2*i + 2;
}

void Shift_down(vector<long long> &array, vector<int> &thread_priority_queue, int i)
{
	int size = array.size();
	int index_min = i;
	int l = Left_child(i);
	if (l < size && array[l] <= array[index_min])
	{
		if (array[l] == array[index_min])
		{
			if (thread_priority_queue[l] < thread_priority_queue[index_min])
			{
				index_min = l;
			}
			else
			{
				index_min = index_min;
			}
		}
		else
		{
			index_min = l;
		}
	}
	int r = Right_child(i);
	if (r < size && array[r] <= array[index_min])
	{
		if (array[r] == array[index_min])
		{
			if (thread_priority_queue[r] < thread_priority_queue[index_min])
			{
				index_min = r;
			}
			else
			{
				index_min = index_min;
			}
		}
		else
		{
			index_min = r;
		}
	}
	if (i != index_min)
	{
		swap(array[i], array[index_min]);
		swap(thread_priority_queue[i], thread_priority_queue[index_min]);
		Shift_down(array, thread_priority_queue, index_min);
	}
}


class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
	vector<int> thread_priority_queue(num_workers_);
	// Initialize thread_priority_queue
	for (int i = 0; i < num_workers_; i++)
	{
		thread_priority_queue[i] = i;
	}

	for (int i = 0; i < jobs_.size(); i++)
	{
		assigned_workers_[i] = thread_priority_queue[0];
		start_times_[i] = next_free_time[0];
		next_free_time[0] = next_free_time[0] + jobs_[i];
		Shift_down(next_free_time, thread_priority_queue, 0);
	}




	/*
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    vector<long long> next_free_time(num_workers_, 0);
    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }
	*/

  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
