class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        degree = [0] * numCourses

        for course, req in prerequisites:
            graph[req].append(course)
            degree[course] += 1

        queue = deque(i for i in range(numCourses) if degree[i] == 0)
        done = 0

        while queue:
            course = queue.popleft()
            done += 1

            for nxt in graph[course]:
                degree[nxt] -= 1
                if degree[nxt] == 0:
                    queue.append(nxt)
        return done == numCourses