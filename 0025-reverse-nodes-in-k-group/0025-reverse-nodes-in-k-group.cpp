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
    // Helper function to reverse a linked list from head and return new head
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        while(temp != NULL){  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front;
        }
        return prev;  
    }

    // Helper function to get the k-th node from temp
    ListNode* getkthNode(ListNode* temp, int k) {
        k = k - 1;
        while (temp != nullptr && k--) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL; 
        while(temp != NULL){
            ListNode* kThNode = getkthNode(temp, k);
            if(kThNode == NULL){
                if(prevLast){
                    prevLast -> next = temp;
                }
                break;
            }
            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            ListNode* reversedHead = reverseLinkedList(temp);
            if(temp == head){
                head = reversedHead;
            }else{
                prevLast -> next = reversedHead;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
