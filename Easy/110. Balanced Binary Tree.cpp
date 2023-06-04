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
    private:
    int heightCalc(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int left = heightCalc(root->left), right = heightCalc(root->right);

        return (max(left, right) + 1);
    }

    public:
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr) return true;

        int left = heightCalc(root->left), right = heightCalc(root->right);

        if(abs(left - right) <= 1)
        {
            return isBalanced(root->right) && isBalanced(root->left);
        }
        
        return false;
    }
};