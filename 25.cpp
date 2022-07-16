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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) {
            return head;
        }
        ListNode x, *g = &x;
        x.next = nullptr;
        ListNode *p = head, *p2 =head;
        while(p != nullptr) {
            int  n = k;
            while(--n&& p != nullptr) {
                p = p->next;
            }
            if(p == nullptr) {
                break;
            }
            ListNode *p1 = p->next;
            p ->next = nullptr;
            p = p1;
            ListNode * t = swap(p2);
            g->next = t;
            g = p2;
            p2 = p;
        }
        g->next = p2;
        return x.next;
    }

    ListNode* swap(ListNode * head) {
        if(head -> next == nullptr) {
            return head;
        } else {
            ListNode * p = swap(head->next);
            ListNode * p1 = p;
            while(p1->next != nullptr) {
                p1 = p1 ->next;
            }
            p1 ->next = head;
            head-> next = nullptr;
            return p;
        }
    }
};