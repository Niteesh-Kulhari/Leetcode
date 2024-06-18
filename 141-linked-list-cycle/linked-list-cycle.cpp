/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, bool> map;
        ListNode * curr = head;

        while( curr != NULL){
            if(map[curr]){
                return true;
            }

            map[curr] = true;

            
                curr = curr->next;
            
        }

        return false;
    }
};