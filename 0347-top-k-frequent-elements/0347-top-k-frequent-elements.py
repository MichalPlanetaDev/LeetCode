class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        counts = {}

        for num in nums:
            counts[num] = counts.get(num, 0) + 1

        buckets = [[] for _ in range(len(nums) + 1)]

        for num, freq in counts.items():
            buckets[freq].append(num)

        ans = []

        for freq in range(len(nums), 0, -1):
            ans.extend(buckets[freq])

            if len(ans) >= k:
                return ans[:k]
        return ans