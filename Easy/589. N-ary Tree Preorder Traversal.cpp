/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {

private: 
    void traversal(Node* root, vector <int> &preorder)
    {
        preorder.push_back(root->val);

        int sizeOfChildren = root->children.size(), i = 0;

        for(; i < sizeOfChildren; i++)
        {
            traversal(root->children[i], preorder);        
        }
    }

public:
    vector<int> preorder(Node* root) 
    {
        if(root == nullptr) return {};
        
        vector <int> preorder;

        traversal(root, preorder);

        return preorder;
    }
};