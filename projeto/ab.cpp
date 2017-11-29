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
private:
    node *root = NULL;
    int contadorComparacoes =0;
    int contadorChavesIguais =0;
public:
    node *getRoot(){
        return root;
    }
    void setRoot(node *r) {
        root = r;
    }
    int getComparacoes() {
        return contadorComparacoes;
    }
    void incrementaComparacoes(){
        contadorComparacoes++;
    }
    int getContadorChavesIguais() {
        return contadorChavesIguais;
    }
    void incrementaChavesIguais() {
        contadorChavesIguais++;
    }
    
    node *insert_tree(node *tree,int value) {
        
        
        
        if(tree == NULL){
            tree = new node;
            tree->esq = NULL;
            tree->dir = NULL;
            tree->value = value;
        }
        else if(tree-> value == value ){
            incrementaChavesIguais();
        }
        else if (value < tree->value){
            incrementaComparacoes();
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
    
    node *find_last_element_with_indice(node *tree, int i, int j ){
        if(j==i){
            return tree;
        }else{
            j++;
            if(tree->esq == NULL){
                return NULL;
            }else {
                return find_last_element_with_indice(tree->esq, i,j);
            }
        }
    }
    bool isABB(node *tree) {
        if(tree == NULL ){
            return true;
        }
        
        if(tree->esq != NULL && tree->esq->value > tree->value){
            return false;
        }
        
        if(tree ->dir != NULL && tree->dir->value < tree->value){
            return false;
        }
        
        if(!isABB(tree->esq) || !isABB(tree->dir)){
            return false;
        }
        return true;
    }
};


