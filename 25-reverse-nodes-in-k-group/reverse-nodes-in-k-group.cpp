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
    ListNode * returnKth(ListNode *temp, int k){
        k--;
        while(temp!= NULL && k > 0){
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseLinkedList(ListNode* head){
        ListNode *temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }   
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL){
            ListNode* kThNode = returnKth(temp, k);

            if(prevNode && kThNode == NULL){
                prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLinkedList(temp);
            if(temp == head){
                head = kThNode;
            }else{
                prevNode->next = kThNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};