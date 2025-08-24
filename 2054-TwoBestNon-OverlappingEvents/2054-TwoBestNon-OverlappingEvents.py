# Last updated: 8/24/2025, 6:55:14 PM
import heapq

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        n = len(events)
        pq = []
        events.sort()
        maxSum , ans = 0 , 0
        for i in range(n):
            st = events[i][0]
            end = events[i][1]
            currSum = events[i][2]
            while pq and st > pq[0][0]:
                _, value = heapq.heappop(pq)
                maxSum = max(maxSum, value)
            ans = max(ans, currSum + maxSum)
            heapq.heappush(pq, [end, currSum])
        return ans
            
