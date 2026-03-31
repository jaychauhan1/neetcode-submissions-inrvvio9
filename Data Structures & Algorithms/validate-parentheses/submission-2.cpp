#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // stack to hold opening brackets

        for (char c : s) {
            // Correct check for opening brackets
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // Stack must not be empty for a closing bracket
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // Correct matching logic
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // If stack is empty, all brackets matched
        return st.empty();
    }
};
