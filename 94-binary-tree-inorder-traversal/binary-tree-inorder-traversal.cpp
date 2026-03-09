class Solution {
public:
    void dfs(TreeNode* root, vector<int>& v){
        if(root==nullptr) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return v;
    }
};