class Solution {
    public boolean isvow(char c){
        return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' ||c =='e' ||c=='i' || c=='o' || c== 'u');
    }
    public String reverseVowels(String s) { 
        char[] arr= s.toCharArray();
        int left =0;
        int right= s.length()-1;
        while(left<right){ 
            if(isvow(s.charAt(left)) && isvow(s.charAt(right))){
                char temp= arr[left];
                arr[left]= arr[right];
                arr[right]=temp;
                left++;
                right--; 
            }
            else if(isvow(s.charAt(left)) && !isvow(s.charAt(right))){
                right--;
            }
            else if(!isvow(s.charAt(left)) && isvow(s.charAt(right))){
                left++;
            }
            else{
                right--;
                left++;
            }
            
        }
        s= new String(arr);
        return s;
    }
}