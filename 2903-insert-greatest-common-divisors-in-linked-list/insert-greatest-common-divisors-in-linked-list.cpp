class Solution {
public:
    int commondiv(int a,int b){
        int div=1;
        for(int i=1;i<=min(a,b);i++){
            if(a%i==0 && b%i==0){
                div=i;
            }
        }
        return div;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummy=head;
        while(dummy!=nullptr && dummy->next!=nullptr){
            ListNode* prev=dummy->next;
            ListNode* gcd=new ListNode((commondiv(dummy->val,prev->val)));
            dummy->next=gcd;
            gcd->next=prev;
            dummy=prev;
        }
        return head;    
    }
};