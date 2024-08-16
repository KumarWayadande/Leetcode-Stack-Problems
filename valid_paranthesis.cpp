#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    char getCorrespondingParantheses(char parantheses)
    {
        switch (parantheses)
        {
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return '_';
        }
    }

    bool isValid(string s)
    {
        stack<char> stack;

        for (char parantheses : s)
        {
            if (parantheses == '(' || parantheses == '[' || parantheses == '{')
                stack.push(parantheses);
            else
            {
                if (stack.empty())
                    return false;
                char poppedParantheses = stack.top();
                char corrParantheses = getCorrespondingParantheses(parantheses);
                if (stack.top() == corrParantheses)
                    stack.pop();
                else
                    return false;
            }
        }

        if(stack.empty())
            return true;
        else
            return false;
    }
};

int main()
{

    string str = "([])}";
    Solution s;

    bool result = s.isValid(str);
    cout << result;
    return 0;
}