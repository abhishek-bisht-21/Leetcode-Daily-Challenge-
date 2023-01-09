class Solution {
public:

    void preOrderTraversal(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }

        ans.push_back(root->val);
        preOrderTraversal(root->left,ans);
        preOrderTraversal(root->right,ans);
        
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrderTraversal(root,ans);
        return ans;
    }
};