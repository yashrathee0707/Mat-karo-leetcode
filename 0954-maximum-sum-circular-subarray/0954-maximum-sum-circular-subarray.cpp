class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currentMax = 0, currentMin = 0;

        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];

            currentMax += nums[i];
            maxSum = max(maxSum, currentMax);
            if(currentMax < 0) {
                currentMax = 0;
            }

            currentMin += nums[i];
            minSum = min(minSum, currentMin);
            if(currentMin > 0) {
                currentMin = 0;
            }
        }

        if(maxSum < 0) {
            return maxSum;
        }

        return max(maxSum, totalSum - minSum);
    }
};
