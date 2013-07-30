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
        ListNode *h1 = l1, *h2 = l2, *cur = NULL;
        
        if (h1 == NULL) {
            return h2;
        } else if (h2 == NULL) {
            return h1;
        }

        bool carry = false;
        while (h1 != NULL && h2 != NULL) {
            int val = h1->val + h2->val + carry;
            carry = val/10;
            val %= 10;
            cur = h1;
            cur->val = val;
            
            h1 = h1->next;
            h2 = h2->next;
        }
        
        cur->next = (h1 != NULL) ? h1 : h2;
        while (cur->next != NULL) {
            cur->next->val += carry;
            carry = cur->next->val / 10;
            cur->next->val %= 10;
            cur = cur->next;
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        
        return l1;
    }
};
