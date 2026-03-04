class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower);
        for(char &ch:paragraph){
            if(!isalpha(ch)){
                ch=' ';
            }
        }
        unordered_set<string> sb;
        for(string s:banned){
            sb.insert(s);
        }
        unordered_map<string,int> mp;
        string word;
        stringstream ss(paragraph);
        while(ss>>word){
            if(!sb.count(word)){
                mp[word]++;
            }
        }
        int maxcount=0;
        string ans="";
        for(auto p:mp){
            if(p.second > maxcount){
                ans=p.first;
                maxcount=p.second;
            }
        }
        return ans;
    }
};