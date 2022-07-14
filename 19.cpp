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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode p;
        p.next = head;
        ListNode* p1 =&p, *p2 = head;
        while(n--&& p2!=nullptr) {
            p2 = p2 -> next;
        }
    
        while(p2!= nullptr) {
            p2 = p2 ->next;
            p1 = p1-> next;
        }
        
        if((p1 != nullptr) &&(p1->next != nullptr) ) {
            p1-> next = p1->next ->next;
        } else {
            return nullptr;
        }
        
        return p.next;
    }
};