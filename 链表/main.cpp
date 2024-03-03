#include <iostream>
using namespace std;

// 节点类型
struct Node {
    Node(int data = 0): data_(data),next_(nullptr) {}
    int data_;
    Node * next_;
};

// 单链表实现代码
class Clink {
public:
    Clink() {
        // 给head_初始化指向头节点
        head_ = new Node();
    }
    ~Clink() {
        // 节点释放
    }

public:
    // 链表的尾插法
    void insertTail(int val) {

        // 先找到当前链表的末尾节点
        Node * p = head_;
        while (p->next_ != nullptr) {
            p = p->next_;
        }

        // 生成新节点
        Node * node = new Node(val);

        // 把新节点挂在尾节点的后面
        p -> next_ = node;
    }
private:
    Node *head_; // 指向链表的头节点

};

int main() {
    std::cout << "Hello, World!555" << std::endl;
    return 0;
}
