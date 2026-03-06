class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for(int i:nums){s.insert(i);}
        while(head!=nullptr && s.count(head->val)){
            head=head->next;
        }
        ListNode* dummy=head;
        while(dummy!=nullptr && dummy->next!=nullptr){
            if(s.count(dummy->next->val)){
                dummy->next=dummy->next->next;
            }
            else{
                dummy=dummy->next;
            }
        }
        return head;
    }
};