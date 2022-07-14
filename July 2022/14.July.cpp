class Solution {
public:
    
    TreeNode* helper(vector<int> &pre,int psi,int pei, vector<int> &in, int isi, int iei){
        
        if(psi > pei){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[psi]);
        int find_ele = pre[psi];
        
        int idx = isi;
        while(in[idx] != find_ele){
            idx++;
        }
        
        int left_ele = idx - isi;
        
        root->left = helper(pre,psi+1,psi+left_ele,in,isi,idx-1);
        root->right = helper(pre,psi+left_ele+1,pei,in,idx+1,iei);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};