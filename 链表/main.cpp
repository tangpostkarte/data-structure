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
        Node *p = head_;
        // 节点释放,head_指针用不上了，可以利用一下
        while (p != nullptr) {
            head_ = head_->next_;
            delete p;
            p = head_;
        }

    }

public:
    // 链表的尾插法 O(n)
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

    // 链表的头插法 O(1)
    void insertHead(int val) {
        //创建新节点
        Node * node = new Node(val);
        //
        node->next_ = head_ -> next_;
        head_->next_ = node;
    }

    // 链表节点的删除
    void remove(int val) {
        // 定义两个指针，p指向某一个节点，q指向p的前一个节点
        Node *p = head_ -> next_;
        Node *q = head_;

        while (p != nullptr) {
            if (p->data_ == val) {
                // 找到了
                q->next_ = p-> next_;
                delete p;
                return;
            } else {
                //没找到，p和q向后移动一位
                p = p->next_;
                q = q->next_;
            }
        }
    }

    // 删除多个节点,删除所有值为val的节点
    void removeAll(int val) {
        // 定义两个指针，p指向某一个节点，q指向p的前一个节点
        Node *p = head_ -> next_;
        Node *q = head_;

        while (p != nullptr) {
            if (p->data_ == val) {
                // 找到了
                q->next_ = p-> next_;
                delete p;
                // 对指针p进行重置
                p = q->next_;
            } else {
                //没找到，p和q向后移动一位
                p = p->next_;
                q = q->next_;
            }
        }
    }

    // 链表打印

    void show () {
        Node *p = head_ -> next_;

        while (p != nullptr) {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }
private:
    Node *head_; // 指向链表的头节点

};

int main() {
    std::cout << "Hello, World!555" << std::endl;
    Clink clink;
    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int val = rand() % 100;
        clink.insertTail(val);
    }

    clink.show();
//    clink.insertHead(44);
//    clink.show();

    // 测试删除
//    clink.remove(44);
//    clink.show();

    // 测试删除所有
    clink.insertTail(44);
    clink.insertHead(44);
    clink.show();
    clink.removeAll(44);
    clink.show();
    return 0;
}
