class Solution {
public:
    bool isPalindrome(string s) {
        // create 2 pointers
        int left = 0;
        int right = s.length() - 1;
        // skip non - alphanumeric
        while(left < right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
