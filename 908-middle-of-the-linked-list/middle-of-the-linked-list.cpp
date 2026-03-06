/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy=head;
        int length=0;
        while(dummy!=nullptr){
            length++;
            dummy=dummy->next;
        }
        int l= (length/2);
        int temp=0;
        while(head!=nullptr){
            if(temp>=l){
                break;
            }
            else{
                temp++;
                head=head->next;
            }
        }
        return head;
    }
};