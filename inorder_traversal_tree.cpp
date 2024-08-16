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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nums;
        stack<TreeNode *> stack;
        TreeNode *current = root;

        while (current != nullptr)
        {
            stack.push(current);
            current = current->left;

            if (current == nullptr)
            {
                while (!stack.empty())
                {
                    TreeNode *node = stack.top();
                    stack.pop();
                    nums.insert(nums.end(), node->val);
                    if (node->right != nullptr)
                    {
                        current = node->right;
                        break;
                    }
                }
            }

        }
            return nums;
    }
};

int main()
{

    TreeNode *firstNode = new TreeNode(3);
    TreeNode *secondNode = new TreeNode(1);
    TreeNode *thirdNode = new TreeNode(2);

    firstNode->left = secondNode;
    secondNode->right = thirdNode;

    Solution s;
    vector<int> nums = s.inorderTraversal(firstNode);

    for (auto x : nums)
        cout << x << " ";

    return 0;
}