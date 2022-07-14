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
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    }
    ListNode * swap(ListNode *head) {
        if(head == nullptr) {
            return head;
        }
        if(head->next == nullptr) {
            return head;
        }
        ListNode *p = head->next->next;
        ListNode *p1 = head -> next;
        head->next->next = head;
        head->next = swap(p);
        return p1;
    }
};