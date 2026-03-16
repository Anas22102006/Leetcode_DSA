class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> st;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                st.insert(grid[r][c]);

                int maxK = min({r, m - 1 - r, c, n - 1 - c});
                for (int k = 1; k <= maxK; k++) {
                    int sum = 0;

                    for (int i = 0; i < k; i++)
                        sum += grid[r - k + i][c + i];
                    for (int i = 0; i < k; i++)
                        sum += grid[r + i][c + k - i];
                    for (int i = 0; i < k; i++)
                        sum += grid[r + k - i][c - i];
                    for (int i = 0; i < k; i++)
                        sum += grid[r - i][c - k + i];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans;
        for (int x : st) {
            ans.push_back(x);
            if (ans.size() == 3)
                break;
        }
        return ans;
    }
};