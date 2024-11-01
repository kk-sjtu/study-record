#include <iostream>
#include <vector>
#include <string>
#include "tree.hpp"
#include <stack>
using namespace std;
const char RefValue = '#'; // 定义 RefValue 为特殊字符 #
template<typename T>

void create_tree(binary_tree_node<T> * &root){
    stack<binary_tree_node<T> * > s; // stack
    // create root
    root = nullptr;

    binary_tree_node<T> *p = nullptr, *t = nullptr;

    int k; // left or right child
    T x; // data
    cin >> x;

    while(x != RefValue){
        
        switch(x){
            case '(':
                s.push(p);
                k = 1;
                break; 
            case ')':
                s.pop();
                break;
            case ',':
                k = 2;
                break;
            default:

                t = new binary_tree_node<T>(x); // create a new node
                if(root == nullptr){
                    root = t;
                }else{
                    p = s.top();
                    if(k == 1){
                        p->left = t;
                    }else{
                        p->right = t;
                    }
                }
                break;
        
        
        }
        cin >> x; // read next character
    }
    
}

template<typename T>
void create_tree_preorder(binary_tree_node<T> * &subtree){
    T x;
    cin >> x;
    if(x == RefValue){
        subtree = nullptr;
    }else{
        subtree = new binary_tree_node<T>(x);
        create_tree_preorder(subtree->left);
        create_tree_preorder(subtree->right);
    }
}

template<typename T>
void create_tree_pre_in(binary_tree_node<T> * &cur, const char *pre, const char *in,int n){
    if( n <= 0){
        cur = nullptr;
        return;
    }
    int k = 0;
    while(pre[0] != in[k]){
        k++;
    }
    cur = new binary_tree_node<T>(in[k]);
    create_tree_pre_in(cur->left, pre + 1, in, k);
    create_tree_pre_in(cur->right, pre + k + 1, in + k + 1, n - k - 1);

}

template<typename T>
void create_tree_post_in(binary_tree_node<T> * &cur, const char *post, const char *in, int n){
    if(n <= 0){
        cur = nullptr;
        return;
    }

    char r = *(post + n - 1); // root
    cur = new binary_tree_node<T>(r);
    int k = 0;
    const char *p = in;
    while(*p != r){
        k++;
        p++;
    } // find the root in in-order traversal    
    create_tree_post_in(cur->left, post, in, k);
    create_tree_post_in(cur->right, post + k, in + k + 1, n - k - 1); 
}

template<typename T>
void preorder(binary_tree_node<T> *subtree){
    if(subtree != nullptr){
        cout << subtree->data << " ";
        preorder(subtree->left);
        preorder(subtree->right);
    }
}

template<typename T>
void inorder(binary_tree_node<T> *subtree){
    if(subtree != nullptr){
        inorder(subtree->left);
        cout << subtree->data << " ";
        inorder(subtree->right);
    }
}

template<typename T>
void postorder(binary_tree_node<T> *subtree){
    if(subtree != nullptr){
        postorder(subtree->left);
        postorder(subtree->right);
        cout << subtree->data << " ";
    }
}
