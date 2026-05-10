class Solution:
    def minArraySum(self, nums: list[int]) -> int:
        counts = Counter(nums)
        u_nums = sorted(counts.keys())
        max_val = u_nums[-1]

        mapping = {x: x for x in u_nums}
        exists = set(u_nums)

        for v in u_nums:
            if mapping[v] < v:
                continue

            for multiple in range(2*v, max_val + 1, v):
                if multiple in exists:
                    mapping[multiple] = min(mapping[multiple], v)

        total_sum = 0
        for val, count in counts.items():
            total_sum += mapping[val] * count

        return total_sum
        return sum(nums)