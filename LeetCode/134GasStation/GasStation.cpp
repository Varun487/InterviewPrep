class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Greedy -> Time:O(n), Space:O(1)
        int total = 0, start = 0, gas_sum = 0, cost_sum = 0, n = gas.size();
        for (int i = 0; i < n; i++) {
            gas_sum += gas[i];
            cost_sum += cost[i];
        }
        if (gas_sum < cost_sum) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            if (total < 0) {
                total = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
