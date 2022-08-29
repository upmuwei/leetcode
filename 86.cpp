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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = new ListNode(0, head),  *p1 = new ListNode(0), *p2 = new ListNode(0), *head1 = p1,* head2 = p2;;
        while(p->next != nullptr) {
            if(p->next->val < x) {
                p1->next = p->next;
                p1 = p1->next;
            } else {
                p2->next = p->next;
                p2 = p2->next;
            }
            p->next = p->next->next;
        }
        p1->next = head2->next;
        p2->next = nullptr;
        delete p;
        delete head2;
        return head1->next;
    }
};