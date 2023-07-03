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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode *> left, right;
        ListNode * p1 = l1, *p2 = l2;
        while(p1 != nullptr) {
            left.push_back(p1);
            p1 = p1->next;
        }
        while(p2 != nullptr) {
            right.push_back(p2);
            p2 = p2->next;
        }
        int carry = 0;
        ListNode *p = nullptr;
        while(left.size()&&right.size()) {
            int sum = left.back()->val + right.back()->val + carry;
            left.pop_back();
            right.pop_back();
            carry = sum / 10;
            ListNode *t = new ListNode(sum%10, p);
            p = t;
        }
        if(left.size()) {
            left.back()->next = p;
            while(left.size()) {
                if(carry == 0) {
                    break;
                }
                ListNode *t = left.back();
                left.pop_back();
                int sum = t->val + carry;
                t->val = sum % 10;
                carry = sum / 10;
            }
            p = l1;
        } else if(right.size()){
            right.back()->next = p;
            while(right.size()) {
                if(carry == 0) {
                    break;
                }
                ListNode *t = right.back();
                right.pop_back();
                int sum = t->val + carry;
                t->val = sum % 10;
                carry = sum / 10;
            }
            p = l2;
        } 
        if(carry != 0) {
            ListNode *t = new ListNode(carry, p);
            p = t;
        }
        return p;
    }
};