# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: list[ListNode | None]) -> ListNode | None:
        heap = []

        for i in range(len(lists)):
            if lists[i]:
                node = lists[i]
                heap.append((node.val, i, node))
        
        heapq.heapify(heap)

        head = tail = ListNode()

        while heap:
            _, i, node = heapq.heappop(heap)
            tail.next = node
            tail = node

            if node.next:
                nxt = node.next
                heapq.heappush(heap, (nxt.val, i, nxt))
        return head.next