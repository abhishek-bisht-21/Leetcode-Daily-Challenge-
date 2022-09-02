// 637. Average of Levels in Binary Tree
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            long temp = 0;
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* t = q.front();
                q.pop();
                temp+=t->val;
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            
            res.push_back((double)temp/s);
        }
        
        return res;
    }
};