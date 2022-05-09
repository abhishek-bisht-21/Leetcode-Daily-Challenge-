class Solution {
public:
    
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    
    void printKPC(string ques, string psf,vector<string> &ans){
    if (ques.length() == 0){
        ans.push_back(psf);
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    for (char chcode : pad[ch - 48]){
        printKPC(roq, psf + chcode,ans);
    }
}

    
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()){
            return {};
        }
        string psf = "";
        vector<string> ans;
        printKPC(digits,psf,ans);
        return ans;
    }
};