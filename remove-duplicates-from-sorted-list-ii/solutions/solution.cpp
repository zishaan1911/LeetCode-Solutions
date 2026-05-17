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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pred = dummy;
        
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                while (head->next != nullptr && head->val == head->next->val) {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                }
                ListNode* lastDuplicate = head;
                pred->next = head->next; 
                head = head->next;
                delete lastDuplicate;
            } else {
                pred = pred->next;
                head = head->next;
            }
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};