class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->val);
            
            while(size-- > 0){
                TreeNode* rv = q.front();
                q.pop();
                
                if(rv->right){
                    q.push(rv->right);
                }
                
                if(rv->left){
                    q.push(rv->left);
                }
            }
        }
        
        return ans;
    }
};