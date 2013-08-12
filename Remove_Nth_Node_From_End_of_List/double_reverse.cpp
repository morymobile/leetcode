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
        
        ListNode *prev = NULL;
        while (head != NULL) {
            ListNode *tmp = head;
            head = head->next;
            tmp->next = prev;
            prev = tmp;
        }
        
        int i = 1;
        head = prev;
        prev = NULL;
        while (head != NULL) {
            if (i == n) {
                head = head->next;
            } else {
                ListNode *tmp = head;
                head = head->next;
                tmp->next = prev;
                prev = tmp;
            }
            ++i;
        }
        
        return prev;
    }
};
