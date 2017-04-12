#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  // Sort segments by start point and length
  // Firstly sort segments by start point
  int min = 0;
  int min_id = 0;

  for (size_t i = 0; i < segments.size(); ++i)
  {
	  min = segments[i].start;
	  min_id = i;
	  Segment temp;
	  for (size_t j = i; j < segments.size(); ++j)
	  {
		  if (segments[j].start < min)
		  {
			  min = segments[j].start;
			  min_id = j;
		  }
		  temp = segments[i];
		  segments[i] = segments[min_id];
		  segments[min_id] = temp;
	  }

  }
  // Initialize points[0]
  for (size_t i = 0; i < segments.size(); ++i)
  {
	  min = segments[i].end;
	  for (size_t j = i; j < segments.size(); ++j)
	  {
		  if (segments[j].start == segments[i].start)
		  {
			  if (segments[j].end < min)
			  {
				  min = segments[j].end;
				  i = i + 1;
			  }

		  }
		  else
		  {
			  points.push_back(min);
			  break;
		  }
	  }
	  break;
  }



  for (size_t i = 0; i < segments.size(); ++i)
  {
	  if (segments[i].start <= points[points.size()-1] && segments[i].end >= points[points.size()-1])
	  {
		  continue;
	  }
	  else
	  {
		  min = segments[i].end;
		  for (size_t j = i; j < segments.size(); ++j)
		  {
			  if (segments[j].start == segments[i].start)
			  {
				  if (segments[j].end < min)
				  {
					  min = segments[j].end;
					  i = i + 1;
				  }
			  }
			  else
			  {
				  points.push_back(min);
				  break;
			  }
		  }
	  }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
