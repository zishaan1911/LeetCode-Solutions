class Solution:
    def maxSum(self, nums: list[int], k: int, mul: int) -> int:
        nums.sort()
        n = len(nums)
        i, j = 0, n-1
        total = 0
        
        for p in range(k):
            m = mul - p
            
            valf = nums[i]
            valb = nums[j]

            if valf >= valb:
                v = valf
                i+=1
            else:
                v = valb
                j-=1

            total += v * m if v * m > v else v
            
        return total
        