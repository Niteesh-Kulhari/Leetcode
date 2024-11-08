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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> temp;
        for(ListNode* list: lists){
            while(list){
                temp.push_back(list->val);
                list = list->next;
            }
        }
        if(temp.size() == 0) return nullptr;
        sort(temp.begin(), temp.end());
        ListNode *head = new ListNode(temp[0]);
        ListNode *curr = head;
        for(int i=1; i<temp.size(); i++){
            curr -> next = new ListNode(temp[i]);
            curr = curr->next;
        }

        return head;
    }
};