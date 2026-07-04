class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
    }
    
    void push(int value) {
        mainStack.push(value);
        
        if (minStack.empty()) {
            minStack.push(value);
        } else {
            minStack.push(std::min(value, minStack.top()));
        }
    }
    
    void pop() {
        if (!mainStack.empty()) {
            mainStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};