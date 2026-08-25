class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        num = set(nums)
        mul = k 
        while mul in nums:
            mul+= k
        return mul
        
        