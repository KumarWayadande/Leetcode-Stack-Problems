/*
--------------------------------------
Code Version : 1
Author : Kumar Wayadande
Upgraded Version ? No
Test Cases : passed
--------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> preOrderTraversal(TreeNode *root)
    {
        vector<int> nums;
        stack<TreeNode *> stack;
        TreeNode *current = root;

        while (current != nullptr || !stack.empty())
        {
            if (current == nullptr)
            {
                current = stack.top();
                stack.pop();
            }

            nums.insert(nums.end(), current->val);
            if (current->right)
                stack.push(current->right);

            current = current->left;
        }
        return nums;
    }
};

int main()
{

    TreeNode *firstNode = new TreeNode(1);
    TreeNode *secondNode = new TreeNode(2);
    TreeNode *thirdNode = new TreeNode(3);

    firstNode->left = secondNode;
    secondNode->right = thirdNode;

    Solution s;
    vector<int> nums = s.preOrderTraversal(firstNode);

    for (auto x : nums)
        cout << x << " ";

    return 0;
}

/*
--------------------------------------
End of code version 1
test cases  passed
--------------------------------------
*/