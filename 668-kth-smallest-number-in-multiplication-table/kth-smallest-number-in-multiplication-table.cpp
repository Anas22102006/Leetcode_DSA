class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;

        while(l < r){
            int mid = l + (r - l) / 2;
            long long count = 0;

            for(int i = 1; i <= m; i++){
                count += min(n, mid / i);
            }

            if(count < k)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};