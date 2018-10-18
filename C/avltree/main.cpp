//
//  main.cpp
//  avltree
//
//  Created by Jean Lucas Monte Carvalho on 10/15/17.
//  Copyright © 2017 Jean Lucas Monte Carvalho. All rights reserved.
//

#include <iostream>
using namespace std;
struct node {
    int value;
    node *esq;
    node *dir;
    int altura;
};

class avltree{
public:
    int max(int a, int b){
        return (a>b)? a : b;
    }
    
    int altura(node *n){
        if(n==NULL){
            return 0;
        }
        return n->altura;
    }
    
    node *newNode(int key){
        node *node = new struct node;
        node->value = key;
        node->esq = NULL;
        node->dir = NULL;
        node->altura = 1;
        return node;
    }
    
    node *rotacaoDireita(node *y){
        node *x = y->esq;
        node *t2 = x->dir;
        x->dir = y;
        x->esq = t2;
        
        y->altura = max(altura(y->esq), altura(y->dir)) +1;
        x->altura = max(altura(x->esq), altura(x->dir)) +1;
        return x;
    }
    
    node *rotacaoEsquerda(node *x){
        node *y = x->dir;
        node *t2 = y->esq;
        y->esq = x;
        y->dir = t2;
        
        x->altura = max(altura(x->esq), altura(x->dir)) +1;
        y->altura = max(altura(y->esq), altura(y->dir)) +1;
        return y;
    }
    
    int getBalance(node *n) {
        if(n==NULL){
            return 0;
        }else {
            return altura(n->esq) - altura(n->dir);
        }
    }
    
    node *insert(node *tree, int value){
        if(tree == NULL){
            return newNode(value);
        }
        if(value < tree->value){
            tree->esq = insert(tree->esq, value);
        }
        else if(value > tree->value){
            tree->dir = insert(tree->dir, value);
        }
        else {
            return tree;
        }
        
        tree->altura = 1 + max(altura(tree->esq), altura(tree->dir));
        
        int balance = getBalance(tree);
        
        if(balance > 1 && value < tree->esq->value){
            return rotacaoDireita(tree);
        }
        if(balance < -1 && value > tree->dir->value){
            return rotacaoEsquerda(tree);
        }
        if(balance >1 && value > tree->esq->value){
            tree->esq = rotacaoEsquerda(tree->esq);
            return rotacaoDireita(tree);
        }
        if(balance <-1 && value < tree->dir->value){
            tree->dir = rotacaoDireita(tree->dir);
            return rotacaoEsquerda(tree);
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
    
};
int main(int argc, const char * argv[]) {
    node *root = NULL;
    avltree tree;
    root = tree.insert(root, 1);
    root = tree.insert(root, 10);
    root = tree.insert(root, 100);
    root = tree.insert(root, 100);
    root = tree.insert(root, 50);
    
//    int m = 10000;
//    for(int i=0;i<m;i++){
//        root = tree.insert(root, rand());
//    }
    cout<< tree.altura(root) <<"\n";
    return 0;
}
