class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string temp;

        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") {
                continue;
            }
            if (temp == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(temp);
            }
        }

        string res = "";
        for (const string& dir : stack) {
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }
};