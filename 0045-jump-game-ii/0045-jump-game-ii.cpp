class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int current = 0, maxReach = 0, count = 0;
        for(int i=0; i<n-1; i++){
            maxReach = max(maxReach, i + nums[i]);

            if(i == current){
                count++;
                current = maxReach;
            }
        }
        return count;
    }
};