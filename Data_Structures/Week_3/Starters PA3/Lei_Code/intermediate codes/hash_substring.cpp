#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

int hash_func(const string &s, const size_t prime, const size_t multiplier)
{
	unsigned long long hash = 0;
	for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
	{
		hash = (hash * multiplier + s[i]) % prime;
	}
	return hash;
}

std::vector<int> precompute_hashes(const string &text, int pattern_size, const size_t prime, const size_t multiplier)
{
	int text_size = text.size();
	std::vector<int> hashes(text_size - pattern_size + 1);
	string substring = text.substr(text_size - pattern_size - 1, pattern_size);
	hashes[text_size - pattern_size] = hash_func(substring, prime, multiplier);
	int y = 1;
	for (int i = 1; i <= pattern_size; i++)
	{
		y = (y * multiplier) % prime;
	}
	for (int i = text_size - pattern_size - 1; i >= 0; i--)
	{
		hashes[i] = (multiplier*hashes[i + 1] + text[i] - y * text[i + pattern_size]) % prime;
	}
	return hashes;
}

std::vector<int> RabinKarp_occurrences(const Data& input)
{
	const string &text = input.text;
	const string &pattern = input.pattern;
	const size_t prime = 100000010;
	const size_t multiplier = rand() % (prime - 1) + 1;
	int text_size = text.size();
	int pattern_size = pattern.size();
	std::vector<int> ans;
	int hash_pattern = hash_func(pattern, prime, multiplier);
	std::vector<int> hashes = precompute_hashes(text, pattern_size, prime, multiplier);
	for (int i = 0; i <= pattern_size - text_size; i++)
	{
		if (hash_pattern != hashes[i])
		{
			continue;
		}
		else
		{
			if (text.substr(i, pattern_size) == pattern)
			{
				ans.push_back(i);
			}
		}
	}
	return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(RabinKarp_occurrences(read_input()));
    return 0;
}
