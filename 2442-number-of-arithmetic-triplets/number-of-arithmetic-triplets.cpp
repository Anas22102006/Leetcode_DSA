class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
    unordered_set s(nums.begin(),nums.end());
    int count=0;
    for(int x:nums){
        if(s.count(x-diff) && s.count(x+diff)){
            count++;
        }
    }
    return count;     
    }
};