class Solution {  
public:  
    int removeDuplicates(vector<int>& nums) {  
        int k = 0; // Variable to track the position of unique elements  

        // Iterate through the array starting from the second element  
        for(int i = 1; i < nums.size(); i++) {  
            // If the current element is different from the last unique element  
            if(nums[i] != nums[k]) {  
                nums[k + 1] = nums[i]; // Move the unique element forward  
                k++; // Increment the unique element count  
            }  
        }  

        return k + 1; // Return the count of unique elements  
    }  
};  
