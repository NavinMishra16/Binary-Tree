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
struct node{
 int data ; 
 node *left;
 node *right;
 node(int d){
    data  = d;
    left = NULL;
    right = NULL;
 }
};
class BST{
 private :
 node *root;
 node *insertBST(node *root , int val){
    if(root ==NULL){
        return new node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left,val);
    }
    else {
        root->right = insertBST(root->right,val);
    }
   return root;
 }
 void inorderTra(node *root){
     if(root==NULL)return ;
     inorderTra(root->left);
     cout<<root->data<<" ";
     inorderTra(root->right);
 }
 void preorderTrv(node *root){
    if(root==NULL)return ; 
    cout<<root->data<<" ";
    preorderTrv(root->left);
    preorderTrv(root->right);
 }
 void postorderTrv(node *root){
    if(root==NULL)return; 
    postorderTrv(root->left);
    postorderTrv(root->right);
    cout<<root->data<<" ";
 }
 bool searchinBST(node *root ,int val){
    if(root==NULL)return false;
    if(root->data ==val)return true;
    if(root->data > val){
        return searchinBST(root->left,val);
    }
    else return searchinBST(root->right,val);
  }
  node* maxVal(node *root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
  }
  node* minVal(node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
  }
  node *deleteFromBST(node *root ,int val){
    if(root==NULL)return root;

    if(root->data ==val){
        // O child 
        if(root->left ==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 CHILD 
        // LEFT CHILD 
    else if(root->left!=NULL && root->right==NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        // RIGHT CHILD
    else if(root->left==NULL && root->right!=NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
    //  2 Child 
    else if(root->left!=NULL && root->right!=NULL){
        int maxi =  maxVal(root->left)->data;
        root->data = maxi;
        root->left = deleteFromBST(root->left,maxi);
    }
    
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else {
        root->right = deleteFromBST(root->right,val);
        return root;
    }
    return root;
  }
 public:
  BST(){
    root = NULL;
  }
  void insert(int val){
    root = insertBST(root,val);
  }
  void inorder(){
    inorderTra(root);
  }
  void preorder(){
    preorderTrv(root);
  }
  void postorder(){
    postorderTrv(root);
  }

  bool search(int val){
    return searchinBST(root,val);
  }
  node *maxiVal(){
    return maxVal(root);
  }
  node *miniVal(){
    return minVal(root);
  }
  void  deleteBST(int val){
    root =  deleteFromBST(root,val);
  }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    BST tree;
    int inputval ;
    cout<<"Enter the value into BST : "<<endl;
    while(true){
        cin>>inputval;
        if(inputval==-1)break;
        tree.insert(inputval);
    }
    cout<<"Printing The BST as Inorder Traversal :"<<endl;
    tree.inorder();
    cout<<endl;
    cout<<"Printing The BST as Preorder Traversal :"<<endl;
    tree.preorder();
    cout<<endl;
    cout<<"Printing The BST as Postorder Traversal :"<<endl;
    tree.postorder();
    cout<<endl;
    tree.search(5)==true?cout<<"YES it exists":cout<<"NOT exist in BST";
    cout<<endl;
    cout<< "Maximum Value of  BST : " << tree.maxiVal()->data<<endl;
    cout<< "Minimum Value of  BST : " << tree.miniVal()->data<<endl;
    cout<<" Print BST Before Deleting the node: "<<endl;
    tree.inorder();
    tree.deleteBST(6);
    cout<<endl;
    cout<<"Print BST after deleting the node: "<<endl;
    tree.inorder();
    cout<<endl;
    return 0;
}