class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop(); // Remove the closest non-digit character
                }
            } else {
                st.push(c); // Push letters onto the stack
            }
        }
        
        string result;
        // Rebuild the string from the stack
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());  // Since we are using a stack, reverse the result string
        
        return result;
    }
};
