class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros=count(nums.begin(),nums.end(),0);
        if(zeros>1){
            vector<int> v(nums.size(),0);
            return v;
        }
        int totpro=1;
        for(int i:nums){
            if(i!=0){
            totpro*=i;
            }
        }
        vector<int> res;
        if(zeros==0){
            for(int i:nums){
            res.push_back(totpro/i);
            }
        }
        if(zeros==1){
            for(int i:nums){
                if(i==0){
                    res.push_back(totpro);
                }
                else{
                    res.push_back(0);
                }
            }
        }
        return res;
    }
};