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
    vector <TreeNode*> allPossibleFBT(int n) 
    {
        vector <vector <TreeNode*>> dp((n + 1), vector <TreeNode*> ());
        int i = 3, j, k;

        dp[1] = {new TreeNode(0)}; 

        if(n % 2)
        {
            for(; i <= n; i += 2)
            {
                for(j = 1; j < i; j++)
                {
                    k = (i - j - 1);

                    for(auto leftTree : dp[j])
                    {
                        for(auto rightTree : dp[k])
                        {
                            auto temp = new TreeNode(0);
                            temp->left = leftTree;
                            temp->right = rightTree;

                            dp[i].push_back(temp);
                        }
                    }
                }
            }
        }

        return dp[n];
    }
};