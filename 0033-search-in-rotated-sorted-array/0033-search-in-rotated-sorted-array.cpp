class Solution {
public:
    int search(vector<int>& nums, int target) {  // Function to search for target in rotated sorted array
        int start = 0;  // Initialize start pointer
        int end = nums.size() - 1;  // Initialize end pointer

        while(start <= end){  // Binary search loop
            int mid = start + (end - start)/2;  // Calculate mid to avoid integer overflow
            if(nums[mid] == target){  // If mid element is target, return its index
                return mid;
            }
            if(nums[start] <= nums[mid]){  // If left half is sorted
                if(nums[start] <= target && target < nums[mid]){  // If target is within sorted left half
                    end = mid - 1;  // Move left
                }
                else{  
                    start = mid + 1;  // Otherwise, move right
                }
            }else{  // If right half is sorted
                if(nums[end] >= target && target > nums[mid]){  // If target is within sorted right half
                    start = mid + 1;  // Move right
                }
                else{  
                    end = mid - 1;  // Otherwise, move left
                }
            }
        }
        return -1;  // Target not found
    }
};
