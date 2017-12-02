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
    node *left;
    node *right;
};

class Abb {
private:
    node *root = NULL;
    int contadorComparacoes =0;
    int chavesIguais =0;
public:
    node *getRoot(){
        return root;
    }
    void setRoot(node *r) {
        root = r;
    }
    int getChavesIguais() {
        return chavesIguais;
    }
    void incrementaChavesIguais(){
        chavesIguais++;
    }
    int getComparacoes() {
        return contadorComparacoes;
    }
    void incrementaComparacoes(){
        contadorComparacoes++;
    }
    
    node *insert_tree(node *tree,  int value) {
        
        if(tree == NULL){
            tree = new node;
            tree->left = NULL;
            tree->right = NULL;
            tree->value = value;
        }
        else if(tree->value == value){
            incrementaChavesIguais();
        }
        else if (value < tree->value){
            incrementaComparacoes();
            tree->left = insert_tree(tree->left, value);
        }
        else{
            tree->right = insert_tree(tree->right, value);
        }
        
        return tree;
    }
    void pre_order(node *tree) {
        if(tree!=NULL){
            cout<< tree->value <<"\n";
            pre_order(tree->left);
            pre_order(tree->right);
        }
    }
    
    void in_order(node* tree) {
        if(tree!=NULL){
            in_order(tree->left);
            cout<< tree->value <<"\n";
            in_order(tree->right);
        }
    }
    
    int size(node *tree){
        if(tree == NULL) {
            return 0;
        }else {
            return size(tree->left) + 1 + size(tree->right);
        }
    }
    
    int height(node *tree) {
        if(tree == NULL) {
            return -1;
        }else{
            int he = height(tree->left);
            int hd = height(tree->right);
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
            if(tree->left == NULL){
                return NULL;
            }else {
                return find_last_element_with_indice(tree->left, i,j);
            }
        }
    }
    bool isABB(node *tree) {
        if(tree == NULL ){
            return true;
        }
        
        if(tree->left != NULL && tree->left->value > tree->value){
            return false;
        }
        
        if(tree ->right != NULL && tree->right->value < tree->value){
            return false;
        }
        
        if(!isABB(tree->left) || !isABB(tree->right)){
            return false;
        }
        return true;
    }
};


