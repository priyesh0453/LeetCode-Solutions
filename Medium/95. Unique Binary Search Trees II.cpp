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
    vector <TreeNode*> generatePossibleTrees(int start_Index, int end_Index)
    {   
        if(start_Index > end_Index) return {nullptr};

        int i = start_Index;
    
        vector <TreeNode*> possibleTrees, left_Subtree, right_Subtree;

        for(; i <= end_Index; i++)
        {
            left_Subtree = generatePossibleTrees(start_Index, (i - 1));
            right_Subtree = generatePossibleTrees((i + 1), end_Index);

            for(TreeNode* left_T : left_Subtree)
            {
                for(TreeNode* right_T : right_Subtree)
                {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = left_T;
                    temp->right = right_T;
                    possibleTrees.push_back(temp);
                }
            }
        }
        return possibleTrees;
    }
    
    public:
    vector <TreeNode*> generateTrees(int n) 
    {
        if(!n) return {nullptr};

        return generatePossibleTrees(1, n);
    }
};