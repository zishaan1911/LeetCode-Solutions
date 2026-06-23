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
            // Convert the node pointer to a raw address integer
            uintptr_t addr = reinterpret_cast<uintptr_t>(curr);
            
            // Bitwise compression: Drop the lower 4 bits (since nodes are 16-byte aligned)
            uintptr_t compressed_addr = addr >> 4;

            // Bitwise Masking: Equivalent to (compressed_addr % 2048) but much faster
            size_t bucket_idx = compressed_addr & (BUCKET_COUNT - 1);

            // Scan the bucket to see if we've encountered this exact address before
            for (uintptr_t stored_addr : buckets[bucket_idx]) {
                if (stored_addr == addr) {
                    return curr; // Exact match found! True cycle detected.
                }
            }

            // If it's a new address, push the raw address into the bucket
            buckets[bucket_idx].push_back(addr);

            curr = curr->next;
        }

        return nullptr; // No cycle found (handles pos = -1 perfectly)
    }
};