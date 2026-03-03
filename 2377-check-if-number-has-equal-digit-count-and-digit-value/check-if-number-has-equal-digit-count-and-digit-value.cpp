class Solution {
public:
    bool digitCount(string num) {
    int arr[10];
    for(char c:num){
        arr[c-'0']++;
    }
    bool con=true;
    for(int i=0;i<num.size();i++){
        if(num[i]-'0' != arr[i]){
            con=false;
            break;
        }
    }
    return con;    
    }
};