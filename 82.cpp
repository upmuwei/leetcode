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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = new ListNode(1000, head);
        ListNode *p = head, *sign = pre, *left;
        bool isSame = false;
        while(p !=nullptr) {
            if(p->val == pre->val) {
                pre->next = p->next;
                delete p;
                isSame = true;
                p = pre->next;
            } else {
                if(isSame) {
                    left->next = p;
                    delete pre;
                    isSame = false;
                    pre = p;
                    p = p->next;
                } else {
                    left = pre;
                    pre = pre->next;
                    p = p->next;
                }
            }
        }
        if(isSame) {
            left->next = p;
            delete pre;
        }
        return sign->next;
    }
};