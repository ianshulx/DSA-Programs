//PROBLEM : https://leetcode.com/problems/max-area-of-island/
//Asked in Intuit Interview



class Solution {
public:
    
    
    void DFSrec(int i, int j, int m,int n, vector<vector<int>>& grid, int &currarea)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1)
            return;
        currarea++;
        grid[i][j] = 2;
        DFSrec(i+1,j,m,n,grid,currarea);
        DFSrec(i-1,j,m,n,grid,currarea);
        DFSrec(i,j-1,m,n,grid,currarea);
        DFSrec(i,j+1,m,n,grid,currarea);
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    int currarea=0;
                    DFSrec(i,j,m,n,grid,currarea);
                    area = max(area,currarea);
                }
            }
        }
        return area;
    }
};
