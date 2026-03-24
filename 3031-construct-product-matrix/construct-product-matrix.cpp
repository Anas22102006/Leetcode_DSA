class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 12345;
        vector<vector<int>> consProd(m,vector<int>(n));
        long prefix = 1;
        long suffix = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                consProd[i][j] = (int)(prefix);
                prefix = (prefix * grid[i][j]) % mod;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                consProd[i][j] = (int)((suffix * consProd[i][j]) % mod);
                suffix = (suffix * grid[i][j]) % mod;
            }
        }
        return consProd;
    }
};