class Solution {
public:
    string reversePrefix(string word, char ch) {
    int index=0;
    if(word.find(ch)==string::npos){
        return word;
    }
    for(char chr:word){
        if(chr==ch){
            break;
        }
        index++;
    }
    string pref=word.substr(0,index+1);
    string suf=word.substr(index+1,(word.length()-index-1));
    reverse(pref.begin(),pref.end());
    return pref+suf;  
    }
};