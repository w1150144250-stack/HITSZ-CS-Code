#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q; // 准备一个队列来装时间戳

public:
    RecentCounter() {
        // 构造函数，这里什么都不用写，队列自带初始化
    }
    
    int ping(int t) {
        // 1. 新请求来了，先把当前时间 t 塞进队尾
        q.push(t);
        // 2. 严师警告：如果队首的人太老了（时间小于 t - 3000），就把他踢出去！
        // 这是一个循环，因为可能不止一个人过期了。
        // 注意：每次取 q.front() 之前，最好确保 !q.empty()
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        // 3. 淘汰完过期的人之后，队列里剩下的人数，就是最终答案
        return q.size();
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << " (期望: 1)" << endl;
    cout << obj->ping(100) << " (期望: 2)" << endl;
    cout << obj->ping(3001) << " (期望: 3)" << endl;
    cout << obj->ping(3002) << " (期望: 3)" << endl;
    
    delete obj; // 打扫战场
    return 0;
}