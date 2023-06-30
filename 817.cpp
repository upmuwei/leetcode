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
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int> exists(nums.begin(), nums.end());
        int count = 0;
        int sign = true;
        while(head != nullptr) {
            if(exists.count(head->val)) {
                if(sign) {
                    count++;
                    sign = false;
                }
            } else {
                sign = true;
            }
            head = head->next;
        }
        return count;
    }
};