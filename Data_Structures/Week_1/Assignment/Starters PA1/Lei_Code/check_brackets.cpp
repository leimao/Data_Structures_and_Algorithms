#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(int type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
	bool pass = true;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
			opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
			// Check whether the stack is empty
			if (opening_brackets_stack.empty())
			{
				std::cout << position + 1;
				pass = false;
				break;
			}
			// Check whether the brackets match
			Bracket top = opening_brackets_stack.top();
			if (top.Matchc(next))
			{
				opening_brackets_stack.pop();
			}
			else
			{
				std::cout << position + 1;
				pass = false;
				break;
			}
		}
    }
	

    // Printing answer, write your code here
	while (opening_brackets_stack.size() > 1 && pass == true)
	{
		opening_brackets_stack.pop();
	}
	if (opening_brackets_stack.size() == 1 && pass == true)
	{
		std::cout << opening_brackets_stack.top().position + 1;
		pass = false;
	}
	if (pass)
	{
		std::cout << "Success";
	}

    return 0;
}
