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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        

        for(int i=0; i<left-1; i++){
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = nullptr;

        // Reverse the sublist between left and right
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        // Return the new head, which is `dummy->next`
        return dummy->next;



    }
};