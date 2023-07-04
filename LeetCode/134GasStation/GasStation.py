class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        # Greedy solution -> Time:O(n), Space:O(1)
        if sum(gas) >= sum(cost):
            start = 0
            diff = [gas[i] - cost[i] for i in range(len(gas))]
            total = 0
            for i in range(len(gas)):
                total += gas[i] - cost[i]
                if total < 0:
                    total = 0
                    start = i + 1
            return start
        return -1

        # # Brute force -> Time:O(n^2), Space:O(1)
        # for i in range(len(gas)):
        #     if gas[i] > cost[i]:
        #         current_station = i
        #         tank = gas[current_station]
        #         while current_station != i - 1:
        #             tank -= cost[current_station]
        #             # travel to next station
        #             current_station = (current_station+1)%len(gas)
        #             tank += gas[current_station]
        #         if tank >= cost[current_station]:
        #             return i
        # return -1
