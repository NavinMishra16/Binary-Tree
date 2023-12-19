#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;


class BinaryTree {
private:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;

       Node(int d){
        this->data = d;
        this->left = NULL ;
        this->right = NULL;
       }
    };

    Node* root;

    Node* insertRec(Node* curr, int val) {
        if (curr == nullptr) {
            return new Node(val);
        }
        if (val < curr->data) {
            curr->left = insertRec(curr->left, val);
        } else if (val >= curr->data) {
            curr->right = insertRec(curr->right, val);
        }
        return curr;
    }

    Node* BuildLevelorder(Node *curr,int val){
        if(curr==NULL){
            return new Node(val);
        }
        queue<Node*>q;
        q.push(curr);
        while(!q.empty()){
            Node *tmp = q.front();
            q.pop();
            if(tmp->left==NULL){
                tmp->left  = new Node(val);
                break;
            }
            else q.push(tmp->left);
            if(tmp->right==NULL){
                tmp->right = new Node(val);
                break;
            }
            else q.push(tmp->right);
        }
        return curr;
    }

    void inorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        inorderRec(root->left);
        std::cout << root->data << " ";
        inorderRec(root->right);
    }

    void preorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->data << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(Node* root) {
        if (root == nullptr) {
            return;
        }
        postorderRec(root->left);
        postorderRec(root->right);
        std::cout << root->data << " ";
    }

    void levelOrder(Node* root) {
        if (root == nullptr) {
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            std::cout << tmp->data << " ";

            if (tmp->left != nullptr) {
                q.push(tmp->left);
            }
            if (tmp->right != nullptr) {
                q.push(tmp->right);
            }
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
       // root = insertRec(root, val);
       root = BuildLevelorder(root,val);
    }
    void printInorder() {
        inorderRec(root);
    }

    void printPreorder() {
        preorderRec(root);
    }

    void printPostorder() {
        postorderRec(root);
    }

    void printLevelOrder() {
        levelOrder(root);
    }
    
};

int main() {
    BinaryTree *tree =new BinaryTree();

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        tree->insert(val);
    }

    std::cout << "Inorder traversal: ";
    tree->printInorder();
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    tree->printPreorder();
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    tree->printPostorder();
    std::cout << std::endl;

    std::cout << "Level-order traversal: ";
    tree->printLevelOrder();
    std::cout << std::endl;

    return 0;
}