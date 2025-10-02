class Solution {
public:
    int minDistance(string word1, string word2) {
        //convert word 1 to word 2
        //create a DP table of nxn
        int n=word1.length();
        int m=word2.length();
        //create a 2D vector and initialize it to 0
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base cases
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;

        //DP Table filling
        for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                   dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j],     // delete
                                        dp[i][j - 1],     // insert
                                        dp[i - 1][j - 1]  // replace
                                       });
                }
            }
        }

      
        return dp[n][m];
        
    }
};
