class Solution {
public:
    int modPow(int a, int b){
        int res = 1;
        a %= 1337;
        while(b){
            if(b & 1) res = (res * a) % 1337;
            a = (a * a) % 1337;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for(int d : b){
            res = modPow(res,10) * modPow(a,d) % 1337;
        }
        return res;
    }
};