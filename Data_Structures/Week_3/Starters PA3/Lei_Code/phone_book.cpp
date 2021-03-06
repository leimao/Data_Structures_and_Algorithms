#include <iostream>
#include <vector>
#include <string>


using std::string;
using std::vector;
using std::cin;


struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
	vector<string> contactor(10000000, "not found");
	vector<string> result;
	for (size_t i = 0; i < queries.size(); ++i)
	{
		if (queries[i].type == "add")
		{
			contactor[queries[i].number] = queries[i].name;
		}
		if (queries[i].type == "del")
		{
			contactor[queries[i].number] = "not found";
		}
		if (queries[i].type == "find")
		{
			result.push_back(contactor[queries[i].number]);
		}
	}
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
