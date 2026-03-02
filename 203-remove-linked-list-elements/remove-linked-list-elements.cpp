class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* tail= &dummy;
        while(head!=nullptr){
            if(head->val == val){
                head=head->next;
            }
            else{
                tail->next=head;
                tail=tail->next;
                head=head->next;
            }
        }
        tail->next=nullptr;
        return dummy.next;    
    }
};