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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode * temp1 = l1;
        ListNode * temp2 = l2;
        ListNode * dummy = new ListNode();
        ListNode * curr = dummy;

        while(temp1 != NULL || temp2 != NULL){
            int val1 = (temp1 != NULL) ? (temp1->val) : 0;
            int val2 = (temp2 != NULL) ? (temp2->val) : 0;

            int sum  = val1 + val2 + carry;

            carry = sum/10;
            
            curr->next = new ListNode(sum%10);

            if(temp1 != NULL){
                temp1 = temp1->next;
            }

            if(temp2 != NULL){
                temp2 = temp2->next;
            }
            curr = curr->next;          
        }

        if(carry == 1){
            curr->next = new ListNode(1);
        }
        return dummy->next;
    }
};