#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            // 1. 遇到左括号，无脑压栈
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } 
            // 2. 遇到右括号
            else if (c == ']' || c == ')' || c == '}') {
                // 🟥 致命防御：如果栈已经空了，说明根本没有左括号来匹配你！
                if (st.empty()) {
                    return false;
                }
                
                char top = st.top();
                // 匹配成功，把配对的左括号弹出
                if ((c == ']' && top == '[') || 
                    (c == ')' && top == '(') || 
                    (c == '}' && top == '{')) {
                    st.pop();
                } else {
                    // 括号类型不对口
                    return false;
                }
            }
        }
        
        // 最后直接返回栈是否为空
        return st.empty(); 
    }
};

// 导师给你准备的车身，方便你本地测试
int main() {
    Solution sol;
    cout << (sol.isValid("()") ? "Pass" : "Fail") << endl;
    cout << (sol.isValid("()[]{}") ? "Pass" : "Fail") << endl;
    cout << (sol.isValid("(]") ? "Fail" : "Pass") << endl; // 这个应该是 false，所以输出 Fail 算对
    cout << (sol.isValid("([)]") ? "Fail" : "Pass") << endl;
    cout << (sol.isValid("{[]}") ? "Pass" : "Fail") << endl;
    cout << (sol.isValid("]") ? "Fail" : "Pass") << endl;   // 极度凶险的测试用例
    
    return 0;
}