class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector to store all the unique triplets that sum up to 0
        vector<vector<int>> result;

        // sort the array to make duplicate handling and two pointer logic easier
        sort(nums.begin(), nums.end());
        // store the size of the array
        int n = nums.size();

        // loop through each element treating it as the first number in the triplet
        for(int i = 0; i < n - 2; i++){// n - 2 because you need at least 3 elemnts to form a triplet
            if(i > 0 && nums[i] == nums[i - 1]) continue; // dont compare the first elemtn see if the current element equals the previous one and skip it if it does

            // initialize the 2 pointers
            int left = i + 1;
            int right = n - 1;
            // move pointers towards each other
            while(left < right){
                // calcualte the sum of the current triplet
                int sum = nums[i] + nums[left] + nums[right];
                // case 1 if the sum = 0
                if(sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                    left ++;
                    right--;
                    // skip the dupicate for the left 
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
                // case 2 if the sum is less than 0 need a larger value so move left
                else if(sum < 0){
                    left++;
                } 
                // case 3 sum is greater than 0 need a smaller value so move the right pointer
                else{
                    right--;
                }
            }
        } 

        // return the final lists of unique results
        return result;
    }
};
