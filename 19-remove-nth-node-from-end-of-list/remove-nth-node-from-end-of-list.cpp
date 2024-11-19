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
        ListNode* dummynode = new ListNode(0, head);

        ListNode* first = dummynode;
        ListNode* second = dummynode;

        for(int i=0; i<=n; i++){
            first = first->next;
        }

        while(first != NULL){
            first = first->next;
            second = second->next;
        }

        if(second->next->next != NULL){
            second->next = second->next->next;
        }else{
            second->next = NULL;
        }
        return dummynode->next;
    }
};
