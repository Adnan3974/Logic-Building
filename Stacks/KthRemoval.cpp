#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string data;
public:
    void push(char ch) {
        data.push_back(ch);
    }
    
    void pop() {
        if (!empty()) {
            data.pop_back();
        }
    }
    
    char top() {
        if (!empty()) {
            return data.back();
        }
        return '\0';
    }
    
    bool empty() {
        return data.empty();
    }
    
    string getResult() {
        return data;
    }
};

string removeKdigits(string num, int k) {
    Stack stk;
    
    for (char digit : num) {
        while (k > 0 && !stk.empty() && stk.top() > digit) {
            stk.pop();
            k--;
        }
        stk.push(digit);
    }
    
    // Remove remaining digits from the end if k > 0
    while (k > 0 && !stk.empty()) {
        stk.pop();
        k--;
    }
    
    string result = stk.getResult();
    
    // Remove leading zeros
    int start = 0;
    while (start < result.length() && result[start] == '0') {
        start++;
    }
    result = result.substr(start);
    
    return result.empty() ? "0" : result;
}

int main() {
    cout<<"Enter number: ";
    string n; cin>>n;
    cout<<"Enter k: ";
    int k; cin>>k;
    cout<<"After removing Kth integers: ";
    cout<<removeKdigits(n,k) << endl;
    return 0;
}