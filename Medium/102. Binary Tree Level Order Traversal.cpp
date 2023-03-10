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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == nullptr) return {};

        vector<vector<int>> order;     
        queue<TreeNode*> counter;
        int i, size;

        counter.push(root);

        while(counter.empty() == 0)
        {
            vector <int> level_order;
            size = counter.size();
            
            for(i = 0; i < size; i++)
            {
                TreeNode* node = counter.front();
                counter.pop();

                if(node->left != nullptr) counter.push(node->left);
                if(node->right != nullptr) counter.push(node->right);
                
                level_order.push_back(node->val);
            }
            order.push_back(level_order);
        }

        return order;
    }
};