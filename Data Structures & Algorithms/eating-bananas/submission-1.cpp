class Solution {
private:
    // Helper function to check if a given eating speed 'k' is feasible.
    // It returns true if Koko can eat all bananas within 'h' hours with speed 'k'.
    // This is the core predicate for our binary search.
    bool canEat(const std::vector<int>& piles, int h, int k) {
        // We use a long long to prevent potential integer overflow if the number of hours is very large.
        long long hours_needed = 0;
        
        // Iterate through each pile to calculate the total time required.
        for (int pile : piles) {
            // This formula calculates the ceiling of (pile / k) using integer division.
            // For example, if pile = 10 and k = 3, (10 + 3 - 1) / 3 = 12 / 3 = 4.
            // This correctly accounts for the final partial hour needed to finish a pile.
            hours_needed += (pile + k - 1) / k;
        }

        // Return true if the total hours needed is within the allowed time 'h'.
        return hours_needed <= h;
    }

public:
    // The main function that finds the minimum eating speed.
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // Step 1: Define the search space for our binary search.
        // The minimum possible eating speed is 1 banana per hour.
        int left = 1;
        
        // The maximum possible speed is the size of the largest pile.
        // There's no benefit to eating faster than the largest pile.
        // We use *std::max_element to find this maximum value efficiently.
        int right = *std::max_element(piles.begin(), piles.end());
        
        // 'ans' stores our best possible answer found so far. We initialize it to the upper bound.
        int ans = right;

        // Step 2: The binary search loop.
        // We continue as long as our search range is valid (left is not past right).
        while (left <= right) {
            // Calculate the midpoint of the current search range.
            // The formula (left + (right - left) / 2) prevents potential integer overflow
            // that might occur with (left + right) / 2.
            int mid = left + (right - left) / 2;

            // Step 3: Use the helper function to check if our current guess 'mid' is feasible.
            if (canEat(piles, h, mid)) {
                // If 'mid' is a feasible speed, it could be our answer.
                // We store it and try to find a smaller speed by searching the left half.
                ans = mid;
                // We move the 'right' pointer to explore speeds less than 'mid'.
                right = mid - 1;
            } else {
                // If 'mid' is not a feasible speed (too slow), we need to eat faster.
                // We move the 'left' pointer to explore speeds greater than 'mid'.
                left = mid + 1;
            }
        }
        
        // Step 4: After the loop terminates, 'ans' holds the minimum feasible eating speed.
        return ans;
    }
};