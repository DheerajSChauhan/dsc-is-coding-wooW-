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
    ListNode* middleNode(ListNode* head) {
        
        //Optimal Solution
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

        //Brute Force Solution
        // int cnt = 0;
        // ListNode* temp = head;
        // while( temp != nullptr){
        //     cnt++;
        //     temp= temp->next;
        // }
        // int midNode = cnt/2 + 1;
        // temp = head;
        // while(temp != nullptr){
        //     midNode = midNode-1;
        //     if(midNode == 0){
        //         break;
        //     }
        //     temp= temp->next;
        // }
        // return temp;
    }
};