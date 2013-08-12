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
        
        vector<ListNode *> nodes;
        ListNode *p = head;
        while(p != NULL) {
            nodes.push_back(p);
            p = p->next;
        }
        
        const size_t size = nodes.size();
        const size_t nth = size - 1 - (n - 1);
        if (nth == 0) {
            return head->next;
        } else if (nth == size - 1) {
            nodes[nth-1]->next = NULL;
            return head;
        } else {
            nodes[nth-1]->next = nodes[nth]->next;
            return head;
        }
    }
};

