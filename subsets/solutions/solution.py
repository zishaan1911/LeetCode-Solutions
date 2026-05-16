class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        def backtrack(start: int, current_subset: List[int]):
            # Append a copy of the current subset to the result
            result.append(list(current_subset))
            
            # Explore further elements to build larger subsets
            for i in range(start, len(nums)):
                # 1. Include nums[i] in the current subset
                current_subset.append(nums[i])
                
                # 2. Move deeper into the decision tree
                backtrack(i + 1, current_subset)
                
                # 3. Backtrack (remove nums[i]) to try the next element
                current_subset.pop()
                
        backtrack(0, [])
        return result