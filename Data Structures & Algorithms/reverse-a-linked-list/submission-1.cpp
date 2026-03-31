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
    ListNode* reverseList(ListNode* head) {
        // base case 1: if the list is empty
        if(head == nullptr){
            return nullptr;
        }
        // if there's only 1 node
        if(head -> next == nullptr){
            return head;
        }
        // recursive step
        ListNode* new_head = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return new_head;

      
        
    }
};
