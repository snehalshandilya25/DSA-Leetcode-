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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp = head;
        int count = 0;

        // Step 1: Check whether k nodes exist
        while (count < k) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
            count++;
        }

        // Step 2: Recursively reverse the remaining list
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: Reverse the current group
        temp = head;
        count = 0;

        while (count < k) {
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;  // Fixed: increment count
        }

        return prevNode;
    }
};