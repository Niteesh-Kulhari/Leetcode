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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy;

        int size = 0;
        while(temp->next != NULL){
            size++;
            temp = temp->next;
        }

        int indexToRemove = size - n;
        temp = dummy;
        for(int i=0; i<indexToRemove; i++){
            temp = temp->next;
        }

        temp ->next = temp->next->next;

        return dummy->next;
    }
};