//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <iostream>
#include <stack>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<char> temp;
        string ans = "";
        cout << "Started\n";
        for (char ch : s)
        {
            // cout << ans << endl;
            if (ch == '(')
                temp.push(ch);
            else if (ch == '^')
            {
                while (!temp.empty() && temp.top() == '^')
                {
                    ans += temp.top();
                    temp.pop();
                }
                temp.push(ch);
            }
            else if (ch == '*' || ch == '/')
            {
                if (!temp.empty())
                {
                    while (!temp.empty() && (temp.top() == '^' || temp.top() == '*' || temp.top() == '/'))
                    {
                        ans += temp.top();
                        temp.pop();
                    }
                }
                temp.push(ch);
            }
            else if (ch == '+' || ch == '-')
            {
                if (!temp.empty())
                {
                    while (!temp.empty() && (temp.top() == '+' || temp.top() == '-' || temp.top() == '/' || temp.top() == '*' || temp.top() == '^'))
                    {
                        // cout << "\t" << temp.top();
                        ans += temp.top();
                        temp.pop();
                    }
                }
                temp.push(ch);
            }
            else if (ch == ')')
            {
                while (!temp.empty() && temp.top() != '(')
                {
                    ans += temp.top();
                    temp.pop();
                }
                if (temp.top() == '(')
                    temp.pop();
            }
            else
                ans += ch;
        }

        while (!temp.empty())
        {
            ans += temp.top();
            temp.pop();
        }

        return ans;
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    Solution s;
    string ans = s.infixToPostfix(expression);
    cout << ans;
    return 0;
}

// } Driver Code Ends