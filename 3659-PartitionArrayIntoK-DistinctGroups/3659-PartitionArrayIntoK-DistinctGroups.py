# Last updated: 8/24/2025, 6:59:23 PM
class Solution:
    def partitionArray(self, nums: List[int], k: int) -> bool:
        mp = {}
        n = len(nums)
        parts = n // k
        if n % k != 0 : 
            return False
        for i in range(n):
            mp[nums[i]] = mp.get(nums[i], 0) + 1
        
        for values in mp.values():
            if values > parts :
                return False
        return True