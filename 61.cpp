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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0 ||head->next == nullptr) {
            return head;
        }
        ListNode* p1 = head, *p2 = head;
        ListNode t1,t2;
        int t = 0;
        while(p2!=nullptr) {
            p2 = p2->next;
            t++;
        }
        k %= t;
        p2 = head;
        int i = 0;
        while(i!= k) {
            while(p1 != nullptr&&i<k) {
                p1 = p1-> next;
                i++;
            }
            if(p1==nullptr) {
                p1 = head;
            }
        }
        while(p1 != nullptr) {
            t1.next = p1;
            t2.next = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p2!= nullptr) {
            t1.next->next = head;
            t2.next->next = nullptr;
        } else {
            p2 = head;
        }
        
        return p2;
    }
};