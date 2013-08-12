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
    static bool listComparator(const ListNode *n1, const ListNode *n2) {
        if (n1 == NULL || n2 == NULL) {
            if (n1 == NULL && n2 == NULL)
                return true;
            if (n1 == NULL)
                return true;
            else
                return false;
        }
        return n1->val < n2->val;
    }
    
    ListNode *minNode(vector<ListNode *> &lists, int &n) {
        const int len = lists.size();
        if (n >= len)
            return NULL;
        
        ListNode *node = lists[n];
        for (int i = n+1; i < len; ++i) {
            if (node == NULL) {
                if (lists[i] != NULL) {
                    n = i;
                    break;
                }
            } else {
                if (lists[i]->val < lists[i-1]->val) {
                    std::swap(lists[i], lists[i-1]);
                } else {
                    break;
                }
            }
            
        }
        if (n >= len)
            return NULL;

        node = lists[n];        
        if (node != NULL) {
            lists[n] = node->next;
        }
        return node;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // k: number of sorted linked list
        // n: average ListNode count of each sorted linked list
        // totally time complexity: n x (lg(n) + k/2)

        if (lists.empty())
            return NULL;

        // n x lg(n)
        std::sort(lists.begin(), lists.end(), Solution::listComparator);
        
        ListNode *head = NULL, *next = NULL;
        int n = 0;
        // n
        do {
            // k/2
            ListNode *tmp = minNode(lists, n);
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

