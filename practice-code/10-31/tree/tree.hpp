#ifndef TREE_HPP
#define TREE_HPP


template<typename T>

// binary tree node
struct binary_tree_node
{
    T data;
    binary_tree_node<T> *left; // pointer to left child
    binary_tree_node<T> *right;     // pointer to right child
    binary_tree_node(): left(nullptr), right(nullptr) {}
    binary_tree_node(T data,binary_tree_node<T> *left = nullptr, binary_tree_node<T> *right = nullptr): 
    data(data), left(left), right(right) {} // constructor

    // destructor

    ~binary_tree_node()
    {
        delete left;
        delete right;
    }
};

template<typename T>
void create_tree(binary_tree_node<T> * &root);

template<typename T>
void preorder(binary_tree_node<T> *subtree);


#endif

template<typename T>
class binary_tree{
public:
    
    binary_tree(): root(nullptr) {} // constructor
    
    binary_tree(T value): RefValue(value), root(nullptr) {} // constructor

    ~binary_tree() // destructor
    {
        delete root;
    }

    void create_tree(){
        create_tree(root);
    }

    void create_tree_preorder(){ // create tree using preorder traversal
        create_tree_preorder(root);}

    void create_tree_pre_in(const char *pre, const char *in){ // create tree using preorder and inorder traversal
        int n = strlen(pre); // length of the string
        create_tree_pre_in(root, pre, in);}

    void create_tree_post_in(const char *post, const char *in){ // create tree using postorder and inorder traversal
        int n = strlen(post); // length of the string
        create_tree_post_in(root, post, in);}

    void create_tree_post_in(const char *post, const char *in, int n){}// create tree using postorder and inorder traversal

    void preorder(){ // preorder traversal
        preorder(root);}

    void inorder(){ // inorder traversal
        inorder(root);}

    void postorder(){ // postorder traversal
        postorder(root);}
    
    void preorder_norecurve(){ // preorder traversal without using recursion
        preorder_norecurve(root);}

    void inorder_norecurve(){ // inorder traversal without using recursion
        inorder_norecurve(root);}

    void postorder_norecurve(){ // postorder traversal without using recursion
        postorder_norecurve(root);}

    void levelorder(){ // levelorder traversal
        levelorder(root);}

    // 获取接点

    binary_tree_node<T> *get_root() const {return root;}

    binary_tree_node<T> *parent(binary_tree_node<T> *current) 
    {
        return (root == nullptr || root == current) ? nullptr : parent(root, current);
    }

    binary_tree_node<T> *left_child(binary_tree_node<T> *current) 
    {
        return current == nullptr ? nullptr : current->left;
    }

    binary_tree_node<T> *right_child(binary_tree_node<T> *current) 
    {
        return current == nullptr ? nullptr : current->right;
    }

    // 成员函数

    void destroy_tree() // destroy tree
    {
        destroy_tree(root);
    }
    

    binary_tree(binary_tree<T> &tree) // copy constructor
    {
        root = copy(tree.getroot());
    }

    bool operator == (binary_tree<T> &tree) // overload operator ==
    {
        return (equal(this->root, tree.getroot()));
    }

    int size(){

        return size(root);
    }

    int height(){
        return height(root);
    }

    bool empty(){
        return root == nullptr;
    }

    void print_binary_tree(){
        print_binary_tree(root, 0);
    }



private:

    binary_tree_node<T> *root; // pointer to root node
    T RefValue; // reference value
};



