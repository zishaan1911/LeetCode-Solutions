#include <cstdint>
#include <vector>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        const size_t BUCKET_COUNT = 2048;
        std::vector<uintptr_t> buckets[BUCKET_COUNT];

        ListNode* curr = head;

        while (curr != nullptr) {
            uintptr_t addr = reinterpret_cast<uintptr_t>(curr);
            
            uintptr_t compressed_addr = addr >> 4;

            size_t bucket_idx = compressed_addr & (BUCKET_COUNT - 1);

            for (uintptr_t stored_addr : buckets[bucket_idx]) {
                if (stored_addr == addr) {
                    return curr;
                }
            }

            buckets[bucket_idx].push_back(addr);

            curr = curr->next;
        }

        return nullptr;
    }
};