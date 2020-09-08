class Solution {
public:
	int matchCh(const string s,const string p,  i, j){
		if(i==0){ // i从1开始 
			return false;
		}
		if(p[j-1] == '.'){
			return true;
		}
		return s[i-1] == p[j-1];
	} 
	
    bool isMatch(string s, string  p) {
	    const int m = s.size(), n = p.size();
	    int *dp = new int [m+1][n+1];
	    for(i = 0; i <= m; i++){
	    	for(int j = 0; j <= n; j++){
	    		dp[i][j] = 0;
			}
		}

		dp[0][0] = true; // 空字符串是可以匹配成功的
		for(i = 0; i <= m; i++){
	    	for(int j = 1; j <= n; j++){
	    		if(p[j-1] == '*'){ // 重点 
	    			if(s[i-1] == p[j-2] ){
	    				dp[i][j] = dp[i-1][j];
					}
					else{
						dp[i][j] = dp[i][j-2];
					}
				}else{
					if(matchCh(s, p, i, j)){
						dp[i][j] = dp[i-1][j-1];
					}
				}
			}
		}
		return dp[m][n];
	    
	    

    }
};