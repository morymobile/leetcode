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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL, *cur = NULL;
        
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            const int num1 = (l1 != NULL) ? l1->val : 0;
            const int num2 = (l2 != NULL) ? l2->val : 0;
            int val = num1 + num2 + carry;
            carry = val / 10;
            val %= 10;
            
            ListNode *tmp = new ListNode(val);
            if (cur == NULL) {
                head = tmp;
            } else {
                cur->next = tmp;
            }
            cur = tmp;
            
            if (l1 != NULL) {
                l1 = l1->next;                
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        return head;
    }
};
