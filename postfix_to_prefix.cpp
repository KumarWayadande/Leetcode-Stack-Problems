//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        stack<string> temp;
        for(char x : post_exp){
            if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^'){
                string a = temp.top();
                temp.pop();
                string b = temp.top();
                temp.pop();
                temp.push(string(1, x) + b + a);
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends