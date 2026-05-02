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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;

        if (head->next == nullptr) {
            return nullptr;
        }
        else {
            while ((n+1) != 0) {
                if (fast->next == nullptr && n == 1) {
                    head = head->next;
                    return head;
                }
                else if (fast->next == nullptr && n > 1) {
                    return head;
                }
                else {
                    fast = fast->next;
                    n--;
                    continue;
                }
            }
            while (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = slow->next->next;

            return head;
        }
    }
};