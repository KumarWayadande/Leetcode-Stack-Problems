//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        int last = pre_exp.length();
        stack<string> temp;
        for(int i = last; i >= 0; i--){
            if(pre_exp[i] == '+' || pre_exp[i] == '-' 
            || pre_exp[i] == '*' || pre_exp[i] == '/' 
            || pre_exp[i] == '%' || pre_exp[i] == '^'){
                if(!temp.empty()){
                    string a = temp.top();
                    temp.pop();
                    string b = temp.top();
                    temp.pop();
                    
                    string exp = "(" + a + "" + pre_exp[i] + "" + b + ")";
                    temp.push(exp+"");
                }
                
            }
            else{
                string s(1, pre_exp[i]); 
                temp.push(s);
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends