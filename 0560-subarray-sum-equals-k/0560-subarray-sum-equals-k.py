class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        seen = {0: 1}
        total = 0
        count = 0

        for num in nums:
            total += num
            count += seen.get(total - k, 0)
            seen[total] = seen.get(total, 0) + 1

        return count