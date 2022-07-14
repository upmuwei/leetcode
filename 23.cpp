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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0 ||(lists.size() == 1 && lists[0] == nullptr)) {
            return nullptr;
        }
        if(lists.size() == 1) {
            return lists[0];
        }
        ListNode *p = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            p = merge2Lists(p, lists[i]);         
        }
        return p;
    }
    ListNode* merge2Lists(ListNode * list1, ListNode * list2) {
        ListNode p, *p1 = &p;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                p1 -> next = list1;
                list1 = list1->next;
            } else {
                p1 -> next  = list2;
                list2 = list2 ->next;
            }
            p1 = p1 -> next;
        }
        if(list1 != nullptr) {
            p1->next = list1;
        }
        if(list2 != nullptr) {
            p1->next = list2;
        }
        return p.next;
    }
};