/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    int max_Sum = INT_MIN;

    private:
    int maxSum(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int leftSum = max(0, maxSum(root->left)), rightSum = max(0, maxSum(root->right));

        max_Sum = max(max_Sum, root->val + leftSum + rightSum);

        return (root->val + max(leftSum, rightSum));
    }

    public:
    int maxPathSum(TreeNode* root) 
    {    
        maxSum(root);

        return max_Sum;
    }
};