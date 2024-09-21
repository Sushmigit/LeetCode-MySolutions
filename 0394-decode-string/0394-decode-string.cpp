class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;    // Stack to store numbers (repeat counts)
        stack<string> strStack; // Stack to store intermediate strings
        string currentStr = ""; // Holds the current substring being formed
        int currentNum = 0;     // Holds the current number being formed

        for (char c : s) {
            if (isdigit(c)) {
                // If it's a digit, build the current number (handles multiple digits)
                currentNum = currentNum * 10 + (c - '0');
            } 
            else if (c == '[') {
                // Push the current number and string to their respective stacks
                numStack.push(currentNum);
                strStack.push(currentStr);
                // Reset for the next segment
                currentNum = 0;
                currentStr = "";
            } 
            else if (c == ']') {
                // Pop from the stack and repeat the string the required number of times
                int repeatTimes = numStack.top(); numStack.pop();
                string repeatedStr = "";
                for (int i = 0; i < repeatTimes; ++i) {
                    repeatedStr += currentStr;
                }
                // Append the repeated string to the string on top of the stack
                currentStr = strStack.top() + repeatedStr; // Combine with previous part
                strStack.pop();
            } 
            else {
                // Otherwise, it's a character, so we append it to the current string
                currentStr += c;
            }
        }

        // The final result is in currentStr
        return currentStr;
        
    }
};