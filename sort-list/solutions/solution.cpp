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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> vals;
        vals.reserve(50000);
        
        ListNode* curr = head;
        while (curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }

        int n = vals.size();
        vector<int> temp(n);

        for (int& v : vals) v ^= 0x80000000;

        for (int shift = 0; shift < 32; shift += 16) {
            int count[65536] = {0};

            for (int v : vals) count[(v >> shift) & 0xFFFF]++;
            for (int i = 1; i < 65536; ++i) count[i] += count[i - 1];
            for (int i = n - 1; i >= 0; --i) {
                int digit = (vals[i] >> shift) & 0xFFFF;
                temp[--count[digit]] = vals[i];
            }
            vals = temp;
        }
        
        curr = head;
        for (int v : vals) {
            curr->val = v ^ 0x80000000;
            curr = curr->next;
        }

        return head;
    }
};