#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<vector<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
	// class objects have to be initialized by constructors
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), elems(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
		if (query.type == "check")
		{
			if (elems[query.ind].empty())
			{
				std::cout << "\n";
			}
			else
			{
				for (int i = static_cast<int>(elems[query.ind].size() -1); i >= 0; i--)
				{
					 std::cout << elems[query.ind][i] << " ";
				}
				std::cout << "\n";
			}
		}
		else
		{
			vector<string> &substring = elems[hash_func(query.s)];
			vector<string>::iterator it = std::find(substring.begin(), substring.end(), query.s);
			if (query.type == "find")
			{
				writeSearchResult(it != substring.end());
			}
			else if (query.type == "add")
			{
				if (it == substring.end())
				{
					substring.push_back(query.s);
				}
			}
			else if (query.type == "del")
			{
				if (it != substring.end())
				{
					substring.erase(it);
				}
			}
		}
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
