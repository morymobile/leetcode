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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = NULL, *cur = NULL;
        
        ListNode *left = NULL, *right = NULL;
        while (head != NULL) {
            left = head;
            right = head->next;
            if (right != NULL) {
                head = right->next;
                if (cur == NULL) {
                    cur = left;
                    ret = right;
                    right->next = left;
                } else {
                    cur->next = right;
                    right->next = left;
                    cur = left;
                }
            } else {
                head = NULL;
                if (cur == NULL) {
                    cur = left;
                    ret = left;
                } else {
                    cur->next = left;
                }
            }
        }
        
        return ret;
    }
};
