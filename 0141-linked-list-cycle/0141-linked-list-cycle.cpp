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
        ListNode* slow = head;
        ListNode* fast = head;
        while( fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast= fast->next->next;

            if(slow == fast) return true;
        }
        return false;

        // unordered_set<ListNode*> visited;
        // while(head != nullptr){
        //     if(visited.count(head)){
        //         return true; //cycle found
        //     }
        //     visited.insert(head);
        //     head=head->next;
        // }
        // return false; // no cycle
    }
};