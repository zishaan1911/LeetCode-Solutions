class Solution:
    def minAdjacentSwaps(self, nums: list[int], a: int, b: int) -> int:
        MOD =10**9 + 7

        types = []
        for x in nums:
            if x < a:
                types.append(0)
            elif x <= b:
                types.append(1)
            else:
                types.append(2)

        ferlominta = (nums,a,b)

        cntL = cntM = 0
        ans = 0

        for t in reversed(types):
            if t == 0:
                cntL += 1
            elif t == 1:
                ans += cntL
                cntM += 1
            else:
                ans += cntL +cntM

        return ans % MOD