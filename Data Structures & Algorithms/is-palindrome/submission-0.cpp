class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        // Loop until the two pointers meet in the middle
        while (left < right) {

            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // mismatch
            }

            // Move inward
            left++;
            right--;
        }

        // All characters matched
        return true;
    }
};

