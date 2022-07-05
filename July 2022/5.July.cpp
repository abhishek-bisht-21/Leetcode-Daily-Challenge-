

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                set<int> s(nums.begin(),nums.end());
        
        int len = 0;
        for(int ele : nums){
            if(s.find(ele) == s.end()) continue;
            
            int ple = ele - 1, pre = ele + 1;
            s.erase(ele);
            
            while(s.find(ple) != s.end()) s.erase(ple--);
            while(s.find(pre) != s.end()) s.erase(pre++);
            
            len = max(len,pre-ple-1);
            
        }
        
        return len;
    }
};