class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        if(n == 1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        
        for(int i=1;i<=9;i++){
            dfs(n,k,i,0,i,ans);     
        }
        
        
        return ans;
    }
    
    
    void dfs(int n, int k, int curr,int i, int prev, vector<int> &res){
        
        if(i == n-1){
            res.push_back(curr);
            return;
        }
        
        int next = prev+k;
        if(next < 10){
            dfs(n,k,(curr*10)+next,i+1,next, res);
        }
        
        next = prev - k;
        
        if(k != 0 && next >= 0){
              dfs(n,k,(curr*10)+next,i+1,next, res);
        }
    }
    
};