class Solution {
public:
    double dfs(double x, int n){
        if(n == 0){
            return 1;
        }
        double temp= dfs(x, n/2);
        if(n%2==0) return temp*temp;
        else return temp*temp*x;
    }
    double myPow(double x, int n) {
        
        int min_flag = (n== -2147483648)?1:0;
        if(min_flag) n = n + 1;

        double res = (n>0)?dfs(x, n):1/dfs(x, n);
        return (min_flag == 1)?res/x:res;

    }
};