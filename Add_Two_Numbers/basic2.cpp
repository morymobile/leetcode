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
        ListNode *h1 = l1, *h2 = l2, *cur = NULL, *ret = NULL;
        
        bool carry = false;
        while (h1 != NULL || h2 != NULL) {
            int val = 0;
            ListNode *tmp;
            if (h1 != NULL && h2 != NULL) {
                val = h1->val + h2->val + carry;
                tmp = h1;
                h1 = h1->next;
                h2 = h2->next;
            } else if (h1 != NULL) {
                val = h1->val + carry;
                tmp = h1;
                h1 = h1->next;
            } else {
                val = h2->val + carry;
                tmp = h2;
                h2 = h2->next;
            }

            carry = val / 10;
            tmp->val = val % 10;
            
            if (cur == NULL) {
                ret = tmp;
            } else {
                cur->next = tmp;
            }
            cur = tmp;
        }

        if (carry) {
            cur->next = new ListNode(1);
        }
        
        return ret;
    }
};
