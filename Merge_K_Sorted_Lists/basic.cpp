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
    ListNode *minNode(vector<ListNode *> &lists) {
        const size_t len = lists.size();
        int index = -1;
        ListNode *node = NULL;
        for (int i = 0; i < len; ++i) {
            if (lists[i] != NULL) {
                if (node == NULL || lists[i]->val < node->val) {
                    node = lists[i];
                    index = i;
                }
            }
        }
        if (node != NULL) {
            lists[index] = node->next;
        }
        return node;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // k: number of sorted linked list
        // n: average ListNode count of each sorted linked list
        // total time complexity: n x k

        ListNode *head = NULL, *next = NULL;
        // n times
        do {
            // k times
            ListNode *tmp = minNode(lists);
            if (next == NULL) {
                next = tmp;
                head = next;
            } else {
                next->next = tmp;
                next = tmp;
            }
        } while (next != NULL);
        return head;
    }
};
