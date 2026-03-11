class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int total=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    total+= 2+ (4*grid[i][j]);
                }
                if(i!=0){
                    total-=2*min(grid[i][j],grid[i-1][j]);
                }
                if(j!=0){
                    total-=2* min(grid[i][j],grid[i][j-1]);
                }
            }
        }
        return total;    
    }
};