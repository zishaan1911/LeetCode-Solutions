class Solution:
    def maximumValue(self, n: int, s: int, m: int) -> int:
        k = n // 2

        mavlorenti = (n,s,m)

        if k == 0:
            return s
        return s + k*m - (k-1)