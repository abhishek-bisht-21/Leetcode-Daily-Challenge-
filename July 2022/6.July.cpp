class Solution {
public:
    int fib(int n) {
        
        if(n == 0 || n == 1){
            return n;
        }
        
        int a = 0;
        int b = 1;
        int res;
        
        for(int i=2;i<=n;i++){
            
            res = a+b;
            a = b;
            b = res;
        }
        
        return res;
    }
};