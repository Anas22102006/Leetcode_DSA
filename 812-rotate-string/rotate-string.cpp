class Solution {
public:
    bool rotateString(string s, string goal) {
    if(s==goal){return true;}
    string r=s;
    r=r.substr(1,r.length()-1)+r[0];
    while(r!=s){
        if(r==goal){
            return true;
        }
        else{
            r=r.substr(1,r.length()-1)+r[0];
        }
    }
    return false;    
    }
};