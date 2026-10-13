class Solution:
    def minOperations(self, n: int) -> int:
        ops = 0

        while n:
            if n & 1:
                if n == 1 or n & 3 == 1:
                    n -= 1
                else:
                    n += 1
                
                ops += 1     
            n >>= 1
        return ops