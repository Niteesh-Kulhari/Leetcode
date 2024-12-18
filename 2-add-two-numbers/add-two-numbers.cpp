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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode* dummy = new ListNode(0, NULL);
        ListNode* curr = dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry;

            if( l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum, NULL);
            curr->next = newNode;
            curr = curr->next;
        }

        return dummy->next;

    }
};