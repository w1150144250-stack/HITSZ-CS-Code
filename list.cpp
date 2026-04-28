#include <iostream>

using namespace std;

// 1. 定义极其核心的“寻宝卡片” —— 节点
struct Node {
    int data;       // 数据域：存储真正的数值
    Node* next;     // 指针域：存储下一个节点的内存地址 (极其关键！)

    // 构造函数：每当 new 一个新节点时，自动把它的 next 指向空(nullptr)
    Node(int val) {
        data = val;
        next = nullptr; 
    }
};

// 2. 链表管理器
class LinkedList {
private:
    Node* head; // 整个链表的灵魂：头指针（也就是第一张线索卡片的位置）

public:
    // 初始化时，链表是空的，所以 head 指向 nullptr
    LinkedList() {
        head = nullptr;
    }

    // ----------------------------------------------------
    // 🟥 你的主战场：实现下面这两个极其基础的函数
    // ----------------------------------------------------

    // 【TODO 1: 头插法】把新节点插在整个链表的最前面
    void prepend(int val) {
        // 1. 凭空向操作系统申请一块新内存，造一个新节点
        Node* newNode = new Node(val);
        
        // 2. 怎么把新节点挂到最前面？（想想沙盘里的箭头怎么指）
        // 提示：newNode 的下一个是谁？head 又该指向谁？
        newNode->next = head;
        head = newNode;
    }

    // 【TODO 2: 遍历打印】从头走到尾，打印出所有元素
    void printList() {
        // 提示：你不能直接移动 head，否则你永远找不到起点。
        // 你需要一个“游标指针”代替你往下走，直到游标指向 nullptr 为止。
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    
    list.prepend(30);
    list.prepend(20);
    list.prepend(10);

    // 预期输出: 10 -> 20 -> 30 -> NULL
    cout << "当前链表为: ";
    list.printList(); 

    return 0;
}