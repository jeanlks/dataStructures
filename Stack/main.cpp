//
//  main.cpp
//  Stack
//
//  Created by Jean Lucas Monte Carvalho on 9/26/17.
//  Copyright © 2017 Jean Lucas Monte Carvalho. All rights reserved.
//

#include <iostream>

struct node {
    int info;
    node *prox;
};

class LinkedList {
private:
    node *head, *tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void createNode(int value) {
        node *temp = new node;
        temp->info = value;
        temp->prox = NULL;
        if(head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        }else {
            tail->prox = temp;
            tail = temp;
        }
    }
    bool searchForElement(int value) {
        bool found = false;
        node *temp = new node;
        temp = head;
        while(temp!=NULL and !found){
            if(temp->info == value){
                found = true;
            }
            temp = temp->prox;
        }
        return found;
    }
    
    void insertStart(int value) {
        node *temp = new node;
        temp->prox = head;
        temp->info = value;
        head = temp;
    }
    
    void insertPosition(int value, int position){
        node *current = new node;
        node *previous = new node;
        node *temp = new node;
        temp->info = value;
        current = head;
        if(!isListEmpty()){
            for(int i = 0; i<position;i++){
                previous = current;
                current = current->prox;
            }
            
            previous->prox = temp;
            temp->prox = current;
        }
    }
    
    void deleteFirst(){
        node *temp = new node;
        temp = head;
        head = head->prox;
        delete temp;
    }
    
    void deletePosition(int position){
        node *current = new node;
        node *previous = new node;
        
        current = head;
        if(!isListEmpty()){
            for(int i =0; i<position;i++){
                previous = current;
                current = current->prox;
            }
            previous->prox = current->prox;
        }
        
    }
    
    int getLast() {
        node *current = new node;
        current = head;
        
        while(current->prox != NULL){
            current = current->prox;
        }
        return current->info;
    }
    
    void insertLast(int value){
        if(head==NULL){
            createNode(value);
        }else {
            node *temp = new node;
            temp->info = value;
            temp->prox= NULL;
            tail->prox = temp;
            tail = temp;
        }
        
    }
    
    void deleteLast() {
        node *current = new node;
        node *previous = new node;
        current = head;
        while(current->prox != NULL){
            previous = current;
            current = current->prox;
        }
        
        tail = previous;
        previous->prox = NULL;
        delete current;
    }
    
    void display() {
        node *temp = new node;
        temp = head;
        while(temp!=NULL){
            std::cout <<temp->info<<"\n";
            temp = temp->prox;
        }
    }
    
    bool isListEmpty(){
        if(head == NULL){
            return true;
        }
        return false;
    }
};

class Stack{
    LinkedList list;
public:
    void stackUp(int value){
        list.insertLast(value);
    }
    void unpack(){
        std::cout << "\nValor desempilhado: " << list.getLast() << "\n";
        list.deleteLast();
    }
    void display(){
        list.display();
    }
};

int main(int argc, const char * argv[]) {
    Stack stack;
    int m = 10000000;
    for(int i=0; i<m;i++){
        stack.stackUp(i);
    }
    stack.display();
    return 0;
}
