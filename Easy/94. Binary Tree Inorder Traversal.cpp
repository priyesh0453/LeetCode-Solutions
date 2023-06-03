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
        traversal.push_back(root->val);
        recursiveApproach(root->right, traversal);
    }

    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        //In-Order Traversal: left - node - right

        vector <int> traversal;

        /*Recursive Approach

        recursiveApproach(root, traversal);*/

        //Iterative Approach

        if(root == nullptr) return {};

        stack <TreeNode*> trackNodes; 
        TreeNode* temp = root;

        while(trackNodes.empty() == 0 || temp != nullptr)
        {
            while(temp != nullptr)
            {
                trackNodes.push(temp);
                temp = temp->left;
            }

            temp = trackNodes.top();

            traversal.push_back(temp->val);
            
            temp = temp->right;
            trackNodes.pop();
        }

        return traversal;
    }
};