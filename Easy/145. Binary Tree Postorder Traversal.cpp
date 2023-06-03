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
    void recursiveApproach(TreeNode* root, vector <int>& traversal)
    {
        if(root == nullptr) return;

        recursiveApproach(root->left, traversal);
        recursiveApproach(root->right, traversal);
        traversal.push_back(root->val);       
    }

    public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        //Post-Order Traversal: left - right - node

        vector <int> traversal;

        /*Recursive Approach

        recursiveApproach(root, traversal);*/

        //Iterative Approach

        if(root == nullptr) return {};

        stack <TreeNode*> trackNodes; 
        TreeNode* temp1 = nullptr;
        TreeNode* temp2;

        while(trackNodes.empty() == 0 || root != nullptr)
        {
            if(root != nullptr)
            {
                trackNodes.push(root);
                root = root->left;
            }
            else
            {
                temp2 = trackNodes.top();
                
                if(temp2->right != nullptr && temp2->right != temp1)
                {
                    root = temp2->right;
                }
                else
                {
                    traversal.push_back(temp2->val);
                    trackNodes.pop();
                    temp1 = temp2;
                }
            }
        }

        return traversal;
    }
};