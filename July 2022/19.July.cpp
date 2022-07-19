class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        res.push_back({1});
        
        if(numRows == 1){
            return res;
        }
        
        
        for(int i=1;i<numRows;i++){
            
            vector<int> temp;
            temp.push_back({1});
            
            for(int j=1;j<i;j++){
                int t = res[i-1][j-1] + res[i-1][j];
                temp.push_back(t);
            }
            temp.push_back({1});
            res.push_back(temp);
        }
        
        
        return res;
    }
};