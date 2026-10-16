class Solution:
    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        cols = len(matrix[0])
        heights = [0] * (cols + 1)
        best = 0

        for row in matrix:
            for i in range(cols):
                heights[i] = heights[i] + 1 if row[i] == '1' else 0

            stack = []

            for i in range(cols + 1):
                while stack and heights[stack[-1]] > heights[i]:
                    h = heights[stack.pop()]
                    width = i if not stack else i - stack[-1] - 1
                    best = max(best, h * width)
                stack.append(i)
        return best