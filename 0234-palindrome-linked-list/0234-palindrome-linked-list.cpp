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
    // ListNode* reverse(ListNode* head){
    //     if(!head || !head->next) return head;
    //     ListNode* prev = nullptr;
    //     ListNode* temp = head;
    //     while(temp != nullptr){
    //         ListNode* front = temp->next;
    //         temp->next = prev;
    //         prev = temp;
    //         temp = front;
    //     }
    //     return prev;
    // }
    // bool isPalindrome(ListNode* head) {
    //     if(head == nullptr || head->next == nullptr) return true;
    //     ListNode* slow = head;
    //     ListNode* fast = head;
    //     while(fast->next != nullptr && fast->next->next != nullptr ){
    //         slow = slow->next;
    //         fast= fast->next->next;
    //     }
    //     ListNode* first = head;
    //     ListNode* second = reverse(slow->next);
    //     while(second != nullptr){
    //         if(first->val != second->val){
    //             reverse(second);
    //             return false;
    //         }
    //         first = first->next;
    //         second = second->next;
    //     }
    //     reverse(second);
    //     return true;
    // }
    bool isPalindrome(ListNode* head){
        stack<int> st;
        ListNode* temp = head;
        while(temp != nullptr){
            st.push(temp->val);
            temp= temp->next;
        }
        temp = head;
        while(temp != nullptr){
            if(temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};