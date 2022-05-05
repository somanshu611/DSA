// https://leetcode.com/problems/add-two-numbers/

// This is the best implementation, however, not my initial one.
// MY first approach was basically inspired from merge sort by mycodeschool.
// Scroll down below for that.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        bool flag=true;
        int sum = 0,carry=0;
        ListNode* curr;ListNode *prev;
        while((l1!=NULL) || (l2!=NULL) || (carry!=0)) {
            curr = new ListNode();
            curr->next = NULL;
            if(flag) {
                flag = false;
                head = curr;
            } else {
                prev->next = curr;
            }
            
            sum=carry;
            if(l1!=NULL) {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2 = l2->next;
            }
            
            // if(sum>=10) {
            //     carry = 1;
            //     sum -= 10;
            // } else carry = 0;  // this works too.
            carry = sum/10;
            sum = sum%10;
            
            curr->val = sum;
            prev = curr;
        }
        
        return head;
    }
};

// MY intital lengthy boiler plate code/approach

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        bool flag=true;
        int sum = 0,carry=0;
        ListNode* curr;ListNode *prev;
        while((l1!=NULL) && (l2!=NULL)) {
            curr = new ListNode();
            curr->next = NULL;
            if(flag) {
                flag = false;
                head = curr;
            } else {
                prev->next = curr;
            }
            sum = carry + (l1->val) + (l2->val);
            l1 = l1->next;l2 = l2->next;
            if(sum>=10) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            
            curr->val = sum;
            prev = curr;
        }
        // cout<<l1->val<<" "<<'\n';
        while(l1!=NULL) {
            cout<<"Inside l1"<<'\n';
            curr = new ListNode();
            curr->next = NULL;
            
            sum = carry + (l1->val);
            if(sum>=10) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            
            l1 = l1->next;
            
            curr->val = sum;
            prev->next = curr;
            prev = curr;
        }
        while(l2!=NULL) {
            curr = new ListNode();
            curr->next = NULL;
            
            sum = carry + (l2->val);
            if(sum>=10) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            l2 = l2->next;
            
            curr->val = sum;
            prev->next = curr;
            prev = curr;
        }
        if(carry!=0) {
            curr = new ListNode();
            curr->val = carry;
            prev->next = curr;
            curr->next = NULL;
        }
        return head;
    }
};