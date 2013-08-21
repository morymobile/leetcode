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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k <= 1) {
            return head;
        }
        
        ListNode *curTail = NULL, *ret = NULL;
        
        while (head != NULL) {
            int count = 0;
            ListNode *start = head;
            while (count < k && head != NULL) {
                head = head->next;
                ++count;
            }
            
            if (count == k) {
                ListNode *next = start, *prev = NULL;
                while (next != head) {
                    ListNode *right = next->next;
                    next->next = prev;
                    prev = next;
                    next = right;
                }
                if (ret == NULL) {
                    ret = prev;
                } else {
                    curTail->next = prev;
                }
                curTail = start;
            } else {
                if (ret == NULL) {
                    ret = start;
                } else {
                    curTail->next = start;
                }
            }
        }
        
        return ret;
    }
};
