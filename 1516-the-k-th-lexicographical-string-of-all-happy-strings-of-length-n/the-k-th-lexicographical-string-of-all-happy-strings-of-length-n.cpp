class Solution {
public:
    string getHappyString(int n, int k) {
        int total= 3* pow(2,(n-1));
        if(k>total){
            return "";
        }
        string ans="";
        char prev='#';
        vector<char> c={'a','b','c'};
        for(int i=0;i<n;i++){
            for(char ch:c){
                if(ch==prev){
                    continue;
                }
                int rem= n-i-1;
                int count= 1 << rem;
                if(k>count){
                    k-=count;
                }
                else{
                    ans+=ch;
                    prev=ch;
                    break;
                }
            }
        }
        return ans;    
    }
};