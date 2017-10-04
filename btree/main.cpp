//
//  main.cpp
//  btree
//
//  Created by Jean Lucas Monte Carvalho on 10/3/17.
//  Copyright © 2017 Jean Lucas Monte Carvalho. All rights reserved.
//

#include <iostream>
using namespace std;
struct node {
    int value;
    node *esq;
    node *dir;
};

class btree {
public:
  node *insert_tree(node *tree,int value) {
       if(tree == NULL){
           tree = new node;
           tree->esq = NULL;
           tree->dir = NULL;
           tree->value = value;
       }
       else if (value < tree->value){
           tree->esq = insert_tree(tree->esq, value);
       }
       else{
          tree->dir = insert_tree(tree->dir, value);
       }
      
      return tree;
   }
   void pre_order(node *tree) {
       if(tree!=NULL){
           cout<< tree->value <<"\n";
           pre_order(tree->esq);
           pre_order(tree->dir);
    }
   }
    
    void in_order(node* tree) {
        if(tree!=NULL){
            in_order(tree->esq);
            cout<< tree->value <<"\n";
            in_order(tree->dir);
        }
    }
    
    int size(node *tree){
        if(tree == NULL) {
            return 0;
        }else {
            return size(tree->esq) + 1 + size(tree->dir);
        }
    }
    
    int height(node *tree) {
          if(tree == NULL) {
              return -1;
          }else{
              int he = height(tree->esq);
              int hd = height(tree->dir);
              if(he<hd){
                  return hd+1;
              }else{
                  return he+1;
              }
          }
    }
};
int main(int argc, const char * argv[]) {
    node *root = NULL;
    btree tree;
    for(int i=0; i<100000;i++){
        root = tree.insert_tree(root, rand());
    }
    tree.in_order(root);
    cout << "tamanho: " << tree.size(root) << "\n";
    cout << "altura: " << tree.height(root) << "\n";
    return 0;
}
