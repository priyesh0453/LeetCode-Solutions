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
    public:
    int maxLevelSum(TreeNode* root) 
    {
        if(root == nullptr) return 0;

        int maxSum = root->val, currentLevel = 1, result = 1, tempSum, noOfElements, i;
        TreeNode* temp;
        queue <TreeNode*> bfs;

        bfs.push(root);

        while(bfs.empty() == 0)
        {
            tempSum = 0;
            noOfElements = bfs.size();

            for(i = 0; i < noOfElements; i++)
            {
                temp = bfs.front();
                
                bfs.pop();

                tempSum += temp->val;

                if(temp->left != nullptr) bfs.push(temp->left);
                if(temp->right != nullptr) bfs.push(temp->right);
            }

            if(tempSum > maxSum)
            {
                maxSum = tempSum;
                result = currentLevel;
            }

            currentLevel++;
        }

        return result;
    }
};