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
    int diaCalc(TreeNode* root, int& dia)
    {
        if(root == nullptr) return 0;

        int left = diaCalc(root->left, dia), right = diaCalc(root->right, dia);

        dia = max(dia, (left + right));

        return (max(left, right) + 1);
    }

    public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int dia = 0;

        diaCalc(root, dia);

        return dia;
    }
};