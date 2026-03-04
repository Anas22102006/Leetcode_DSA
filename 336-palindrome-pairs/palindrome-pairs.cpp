#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPal(const string& s, int l, int r){
        while(l < r) if(s[l++] != s[r--]) return false;
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> pos;
        int n = words.size();
        for(int i=0;i<n;i++) pos[words[i]] = i;

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            string &w = words[i];
            int L = w.size();

            for(int k=0;k<=L;k++){
                if(isPal(w, 0, k-1)){
                    string right = w.substr(k);
                    reverse(right.begin(), right.end());
                    auto it = pos.find(right);
                    if(it != pos.end() && it->second != i){
                        ans.push_back({it->second, i});
                    }
                }
                if(k != L && isPal(w, k, L-1)){
                    string left = w.substr(0, k);
                    reverse(left.begin(), left.end());
                    auto it = pos.find(left);
                    if(it != pos.end() && it->second != i){
                        ans.push_back({i, it->second});
                    }
                }
            }
        }
        return ans;
    }
};