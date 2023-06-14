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
    int minDistance;
    TreeNode* temp;

    private:
    void compare(TreeNode* root)
    {
        if(root == nullptr) return;

        compare(root->left);

        if(temp != nullptr) minDistance = min(minDistance, (root->val - temp->val));

        temp = root;

        compare(root->right);
    }
    
    public:
    int getMinimumDifference(TreeNode* root) 
    {
        temp = nullptr;
        minDistance = INT_MAX;
        
        compare(root);

        return minDistance;
    }    
};