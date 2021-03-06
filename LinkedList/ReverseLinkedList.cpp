// https://leetcode.com/problems/reverse-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prv = NULL;
        ListNode* nxt = NULL;
        ListNode* temp = head;
        while(temp!=NULL) {
            nxt = temp->next;
            if(temp->next == NULL) {
                head = temp;
            }
            temp->next = prv;
            prv = temp;
            temp = nxt;
        }
        return head;
    }
};