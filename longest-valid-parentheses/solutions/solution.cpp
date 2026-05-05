class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Initial boundary
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' is a new base boundary
                    st.push(i);
                } else {
                    // Calculation: current index - index of the last unmatched boundary
                    max_len = max(max_len, i - st.top());
                }
            }
        }

        return max_len;
    }
};