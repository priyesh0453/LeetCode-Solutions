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
        bool check(TreeNode* root, long maximum, long minimum)
        {
            if(root == nullptr) return true;
            else if(maximum <= root->val || minimum >= root->val) return false;
            return check(root->left, root->val, minimum) && check(root->right, maximum, root->val);
        }

    public:
        bool isValidBST(TreeNode* root) 
        {
            return check(root, LONG_MAX, LONG_MIN);    
        }
};