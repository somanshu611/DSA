// link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Approach 1 : Two pass algo
// Intuitive


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int s = 0;
        ListNode* temp = head;
        while(temp!=NULL) {
            s++;
            temp = temp->next;
        }
        temp = head;
        int k = s-n+1;
        if(k==1) head = head->next;
        else {
            ListNode* prev;
            for(int i=1;i<k;i++) {
                if(i==k-1) prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next = NULL;
        }
        return head;
    }
};

// Approach 2 : Two pointers approach 
// Efficient and optimal

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        auto d = ListNode(0,head); // dummy node
        ListNode* f = &d;ListNode* s=&d; // fast and slow pointers
        for(int i=1;i<=n;i++) {
            f = f->next;
        }
        if(f->next==NULL) return head->next; // If the head node is to be deleted.
        while(f->next!=NULL) {
            f = f->next;
            s = s->next;
        }
        s->next = s->next->next;
        return head;
    }
};