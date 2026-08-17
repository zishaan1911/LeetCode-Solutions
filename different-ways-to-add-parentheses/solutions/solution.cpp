class Solution {
public:
    int calculate(int x, int y, char op) {
        if(op == '+') return x+y;
        if(op == '-') return x-y;
        if(op == '*') return x*y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        bool isNum = 1;

        for(int i = 0; i < expression.length(); i++) {
            if(!isdigit(expression[i])) {

                isNum = 0;

                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for(int x : left) {
                    for(int y : right) {
                        int val = calculate(x, y, expression[i]);
                        results.push_back(val);
                    }
                }
            }
        }
        if(isNum == 1) results.push_back(stoi(expression));
        return results;
    }
};