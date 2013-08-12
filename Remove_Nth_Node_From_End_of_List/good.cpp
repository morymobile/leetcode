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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert (n > 0);
        assert (head != NULL);
        
        int step = 1;
        ListNode *first = NULL, *second = head;
        while (second->next != NULL) {
            if (step != n) {
                second = second->next;
                ++step;
            } else {
                if (first == NULL) {
                    first = head;
                } else {
                    first = first->next;
                }
                second = second->next;
            }
        }
        
        if (first == NULL) {
            return head->next;
        } else {
            first->next = first->next->next;
        }
        return head;
  }
};

