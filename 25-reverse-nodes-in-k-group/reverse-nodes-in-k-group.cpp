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
private:
    ListNode* returnKthNode(ListNode* node, int k){
        if(node == NULL) return NULL;
        ListNode* temp = node;
        int count = 1;
        while(count != k && temp != NULL){
            count++;
            temp = temp->next;
        }

        return count == k ? temp : NULL;;
    }
     
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* kthNode = returnKthNode(temp, k);
            
            if(prev && kthNode == NULL){
                prev->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseList(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prev->next = kthNode;
            }
            prev = temp;
            temp = nextNode;
        }

        return head;

    }
};