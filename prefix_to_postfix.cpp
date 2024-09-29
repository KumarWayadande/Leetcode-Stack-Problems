//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> temp;
        for(int i = pre_exp.length(); i >= 0; i--){
            char x = pre_exp[i];
            if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^'){
                string a = temp.top();
                temp.pop();
                string b = temp.top();
                temp.pop();
                temp.push(a + b + string(1, x));
            }else{
                temp.push(string(1, x));
            }
        }
        return temp.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends