#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>


using namespace std;

class Array {
public:
    Array(int size = 10): mCap(size), mCur(0) {
        mpArr = new int [mCap]();
    }
    ~Array() {
        delete [] mpArr;
        mpArr = nullptr;
    }

public:
    // 尾部插入
    void push_back(int val) {
        if (mCur == mCap) {
            expand(2 * mCap);
        }
        mpArr[mCur++] = val;
    }
    // 尾部删除
    void pop_back() {
        if (mCur == 0) {
            return;
        }
        mCur--;
    }
    // 插入元素
    void insert(int pos, int val) {
        if (pos < 0 || pos > mCur) {
            return;
        }
        if (mCur == mCap) {
            expand(2 * mCap);
        }
        for (int i = mCur - 1; i >= pos; i--) {
            mpArr[i + 1] = mpArr[i];
        }

        mpArr[pos] = val;
        mCur++;

    }
    // 按位置删除某个元素
    void erase(int pos) {
        if (pos < 0 || pos >= mCur) {
            return;
        }

        for (int i = pos + 1; i < mCur; i++) {
            mpArr[i - 1] = mpArr[i];
        }
        mCur--;
    }

    // 查找
    int find(int val) {
        for (int i = 0; i < mCur; i++) {
            if (mpArr[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // 打印数据
    void show() const {
        for (int i = 0; i < mCur; ++i) {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }
private:
    void expand(int size) {
        int *p = new int [size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete[] mpArr;
        mpArr = p;
        mCap = size;
    }
private:
    int *mpArr;  // 指向数组的指针
    int mCap;    // 数组的容量
    int mCur;    // 数组中元素的个数
};

int main() {
    Array arr;
    srand(time(0));

    for(int i = 0; i < 10; i++) {
        arr.push_back(rand() % 100);
    }
    arr.show();

    arr.pop_back();
    arr.show();

    arr.insert(0, 100);
    arr.show();


}
