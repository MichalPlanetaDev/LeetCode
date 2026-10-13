class Solution:
    def countDistinct(self, nums: list[int], k: int, p: int) -> int:
        root = {}
        count = 0

        for i in range(len(nums)):
            node = root
            div = 0

            for j in range(i, len(nums)):
                num = nums[j]

                if num % p == 0:
                    div += 1
                    if div > k:
                        break

                if num not in node:
                    node[num] = {}
                    count += 1

                node = node[num]

        return count
