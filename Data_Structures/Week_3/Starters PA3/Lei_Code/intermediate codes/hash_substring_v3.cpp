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

long long hash_func(const string &s, const size_t prime, const size_t multiplier)
{
	unsigned long long hash = 0;
	for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
	{
		hash = (hash * multiplier + s[i]) % prime;
	}
	return hash;
}

std::vector<long long> precompute_hashes(const string &text, long pattern_size, const size_t prime, const size_t multiplier)
{
	long text_size = text.size();
	long n = text_size - pattern_size + 1;
	std::vector<long long> hashes(n);
	//std::cout << "qqqqqqq";
	string substring = text.substr(text_size - pattern_size, pattern_size);
	//std::cout << "substring = " << substring << "\n";
	hashes[text_size - pattern_size] = hash_func(substring, prime, multiplier);
	int y = 1;
	for (long i = 1; i <= pattern_size; i++)
	{
		y = (y * multiplier) % prime;
	}
	for (long i = (text_size - pattern_size - 1); i >= 0; i--)
	{
		//hashes[i] = (multiplier * hashes[i + 1] + text[i] - y * text[i + pattern_size]) % prime;
		hashes[i] = ((multiplier * hashes[i + 1] + text[i] - y * text[i + pattern_size])%prime + prime) % prime; // numerically stable
		//std::cout << "multiplier" << multiplier << "\n";
		//std::cout << "hashes[i + 1] " << hashes[i + 1] << "\n";
		//std::cout << "text[i] " << (int)text[i] << "\n";
		//std::cout << "y " << y << "\n";
		//std::cout << "text[i + pattern_size] " << (int)text[i + pattern_size] << "\n";
	}
	return hashes;
}

std::vector<int> RabinKarp_occurrences(const Data& input)
{
	const string &text = input.text;
	const string &pattern = input.pattern;
	const size_t prime = 1000010;
	const size_t multiplier = rand() % (prime - 1) + 1;
	long text_size = text.size();
	long pattern_size = pattern.size();
	std::vector<int> ans;
	long long hash_pattern = hash_func(pattern, prime, multiplier);
	//std::cout << "hash_pattern = " << hash_pattern << "\n";
	std::vector<long long> hashes = precompute_hashes(text, pattern_size, prime, multiplier);
	//std::cout << "pattern_size - text_size" << pattern_size - text_size << "\n";
	for (long i = 0; i <= (text_size - pattern_size); i++)
	{
		//std::cout << "hashes " <<"[" << i << "] = " << hashes[i] << "\n";
		if (hash_pattern != hashes[i])
		{
			continue;
		}
		else
		{
			//std::cout << "found potential" << "\n";
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
