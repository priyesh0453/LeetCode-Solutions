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

        traversal.push_back(root->val);
        recursiveApproach(root->left, traversal);
        recursiveApproach(root->right, traversal);
    }

    public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        //Pre-Order Traversal: root - left - right

        vector <int> traversal;

        /*Recursive Approach

        recursiveApproach(root, traversal);*/

        //Iterative Approach

        if(root == nullptr) return {};

        stack <TreeNode*> trackNodes; 
        TreeNode* temp;

        trackNodes.push(root);

        while(trackNodes.empty() == 0)
        {
            temp = trackNodes.top();

            traversal.push_back(temp->val);
            trackNodes.pop();

            if(temp->right != nullptr) trackNodes.push(temp->right);
            if(temp->left != nullptr) trackNodes.push(temp->left);
        }

        return traversal;
    }
};