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
    
    int count = 0;
    
    vector <int> countSumNodes(TreeNode* root)
    {
        if(root == nullptr) return {0, 0};

        vector <int> leftSubTree = countSumNodes(root->left), rightSubTree = countSumNodes(root->right);
        int tempAvg = (root->val + leftSubTree[0] + rightSubTree[0]) / (1 + leftSubTree[1] + rightSubTree[1]);

        if(tempAvg == root->val) count++;

        return {(root->val + leftSubTree[0] + rightSubTree[0]), (1 + leftSubTree[1] + rightSubTree[1])};
    }

    public:
    
    int averageOfSubtree(TreeNode* root) 
    {    
        if(root == nullptr) return 0;

        countSumNodes(root);

        return count;
    }
};