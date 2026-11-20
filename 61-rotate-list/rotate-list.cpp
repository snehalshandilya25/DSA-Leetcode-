/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Step 1: Handle empty or single-node list
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Step 2: Calculate length and find last node
        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        // Step 3: Remove unnecessary rotations
        k = k % n;

        if (k == 0) {
            return head;
        }

        // Step 4: Make the list circular
        tail->next = head;

        // Step 5: Find the new last node
        int steps = n - k - 1;

        ListNode* newTail = head;

        while (steps--) {
            newTail = newTail->next;
        }

        // Step 6: Find new head
        ListNode* newHead = newTail->next;

        // Step 7: Break the circular list
        newTail->next = NULL;

        return newHead;
    }
};