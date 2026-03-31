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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base Case 1: if the list 1 is empty
        if(list1 == nullptr){
            return list2;
        }
        // Base Case 2: if lsit 2 is empty 
        if(list2 == nullptr){
            return list1;
        }
        // Recursive step
        if(list1 -> val <= list2 -> val){
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
        else{
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
    }
};
