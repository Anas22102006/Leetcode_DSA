#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct DSU {
        vector<int> p, r;
        int comps;

        DSU(int n) {
            p.resize(n);
            r.assign(n, 0);
            iota(p.begin(), p.end(), 0);
            comps = n;
        }

        int find(int x) {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
            comps--;
            return true;
        }
    };

    bool can(int n, vector<vector<int>>& edges, int k, int x) {
        DSU dsu(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 1) {
                if (s < x) return false;
                if (!dsu.unite(u, v)) return false;
            }
        }

        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 0 && s >= x) {
                dsu.unite(u, v);
            }
        }

        int used = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], s = e[2], must = e[3];
            if (must == 0 && s < x && 2 * s >= x) {
                if (dsu.unite(u, v)) {
                    used++;
                    if (used > k) return false;
                }
            }
        }

        return dsu.comps == 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        if (!can(n, edges, k, 1)) return -1;

        int lo = 1, hi = 200000, ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};