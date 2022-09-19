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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int index = 0;
        ListNode *p = new ListNode(0, head), *t = p;
        ListNode *swap = nullptr;
        while(p->next != nullptr) {
            index++;
            if(left == index) {
                swap = p -> next;
                break;
            }
            p = p -> next;
        }
        while(index < right) {
            ListNode * tmp = p->next;
            p -> next = swap -> next;
            swap -> next = swap -> next ->next;
            p->next-> next = tmp; 
            index++;
        }
        return t -> next;
    }
};