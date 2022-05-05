// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* prev;
        bool flag=true;
        
        while((list1!=NULL) || (list2!=NULL)) {
            int v1,v2;v1=v2=1000;
            if(list1!=NULL) v1 = list1->val;
            if(list2!=NULL) v2 = list2->val;
            
            if(v1<=v2) {
                if(flag) {
                    head = list1;
                    flag=false;
                } else prev->next = list1;
                prev = list1;
                list1 = list1->next;
            } else {
                if(flag) {
                    head=list2;
                    flag=false;
                } else prev->next = list2;
                prev=list2;
                list2 = list2->next;
            }
        }
        return head;
    }
};