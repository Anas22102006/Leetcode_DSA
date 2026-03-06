class Solution {
public:
    string intToRoman(int num) {
    vector<int> vi={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> vs={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string ans="";
    while(num>0){
        for(int i=0;i<vi.size();i++){
            if(num>=vi[i]){
                ans+=vs[i];
                num-=vi[i];
                break;
            }
        }
    }
    return ans;     
    }
};