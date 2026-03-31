class Solution {
public:
    bool isValid(string s) {
        // handle opening brackets
        stack<char> stk;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                stk.push(c);
        }
        else{
            // no matching opener
            if(stk.empty()){
                return false;
            }
            char top = stk.top();
            stk.pop();
            if(c == ')' && top != '(') return false;
            if(c == ']' && top != '[') return false; 
            if(c == '}' && top != '{') return false;
        } 
    }
    return stk.empty();
    }
};
