
#include <iostream>
#include <stack>
#include "tree.hpp"
using namespace std;

int main() {
    binary_tree_node<char> *root = nullptr;
    cout << "请输入树的节点数据（以 # 结束）：";
    

    cout << "前序遍历结果：";
    preorder(root);
    cout << endl;

    return 0;
}