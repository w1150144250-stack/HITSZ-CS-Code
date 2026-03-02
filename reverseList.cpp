#include <iostream>

using namespace std;

// 1. 节点定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 2. 你的完美发动机
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

// ================= 辅助测试工具 =================

// 工具 A：打印链表
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

// 工具 B：手动释放链表内存 (严防内存泄漏！)
void freeList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        ListNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

// ==============================================

int main() {
    // 1. 铺设铁轨：手动造一个 1 -> 2 -> 3 -> 4 -> 5 的链表
    // 这里用到了你刚才看到的带两个参数的构造函数，非常优雅！
    ListNode* head = new ListNode(1, 
                        new ListNode(2, 
                            new ListNode(3, 
                                new ListNode(4, 
                                    new ListNode(5)))));

    cout << "反转前: ";
    printList(head);

    // 2. 调用你写的算法
    Solution solution;
    ListNode* newHead = solution.reverseList(head);

    // 3. 验收成果
    cout << "反转后: ";
    printList(newHead);

    // 4. 打扫战场 (C++ 程序员的基本修养)
    freeList(newHead);

    return 0;
}