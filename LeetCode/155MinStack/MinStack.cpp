class MinStack {
public:
    MinStack() {
    }
    
    vector<int> runStack;
    vector<int> minStack;
    
    void push(int val) {
        runStack.push_back(val);
        if (minStack.size() == 0 || val < minStack[minStack.size() - 1]){
            minStack.push_back(val);
        }
        else {
            minStack.push_back(minStack[minStack.size() - 1]);
        }
    }
    
    void pop() {
        minStack.erase(minStack.begin() + minStack.size() - 1);
        runStack.erase(runStack.begin() + runStack.size() - 1);
    }
    
    int top() {
        return runStack[runStack.size() - 1];
    }
    
    int getMin() {
        return minStack[minStack.size() - 1];
    }
};
