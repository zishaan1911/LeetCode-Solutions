class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() == 0) return true;
        if (s.size() == 1) return false;
        for (char c : s) {
            if  (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty()) return false;
                
                char top = st.top();

                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    st.pop();
                }

                else return false;
            }

        }
        if (st.empty()) {
            return true;
        }
        else return false;
    }
};