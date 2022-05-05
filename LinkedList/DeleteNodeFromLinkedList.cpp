// https://leetcode.com/problems/delete-node-in-a-linked-list/

// We are given access to nodes that we have to delete from the linked list. 
// So, whatever operation we want to do in the linked list, 
// we can operate in the right part of the linked list from the node to be deleted. 

// The approach is to copy the next node’s value in the deleted node. 
// Then, link node to next of next node. 
// This does not delete that node but indirectly it removes that node from the linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};