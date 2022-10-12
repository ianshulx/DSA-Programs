   int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m));
        dp[0][0] = 1;
        if(grid[0][0] == 1) return 0;
        for(int i=1; i<m; i++) {
            if(grid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i-1];   
            }    
        }
        
        for(int i=1; i<n; i++) {
            if(grid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i-1][0];   
            }    
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[n-1][m-1];
        
        
    }
