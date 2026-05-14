class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* old_tail = head;
        int n = 1; 
        while (old_tail->next) {
            old_tail = old_tail->next;
            n++;
        }

        old_tail->next = head;

        k = k % n;
        int steps_to_new_tail = n - k - 1;
        ListNode* new_tail = head;
        for (int i = 0; i < steps_to_new_tail; i++) {
            new_tail = new_tail->next;
        }
        
        ListNode* new_head = new_tail->next;

        new_tail->next = nullptr;

        return new_head;
    }
};