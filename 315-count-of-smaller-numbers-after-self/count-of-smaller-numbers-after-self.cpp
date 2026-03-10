class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++)
            v.push_back({nums[i], i});

        mergeSort(v, ans, 0, n - 1);
        return ans;
    }

    void mergeSort(vector<pair<int,int>>& v, vector<int>& ans, int l, int r) {
        if(l >= r) return;
        int m = (l + r) / 2;
        mergeSort(v, ans, l, m);
        mergeSort(v, ans, m + 1, r);
        merge(v, ans, l, m, r);
    }

    void merge(vector<pair<int,int>>& v, vector<int>& ans, int l, int m, int r) {
        vector<pair<int,int>> temp;
        int i = l, j = m + 1;

        while(i <= m && j <= r) {
            if(v[i].first <= v[j].first) {
                temp.push_back(v[j++]);
            } else {
                ans[v[i].second] += (r - j + 1);
                temp.push_back(v[i++]);
            }
        }

        while(i <= m) temp.push_back(v[i++]);
        while(j <= r) temp.push_back(v[j++]);

        for(int k = l; k <= r; k++)
            v[k] = temp[k - l];
    }
};
