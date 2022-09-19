/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *p1 = head->next->next, *p2 = head->next;
        while(p1 != nullptr&&p1->next != nullptr && p1!= p2) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        if(p1==nullptr||p1->next == nullptr) {
            return false;
        }
        return true;
    }
};