//
//  main.cpp
//  linkedList
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
    
    void getLast() {
        node *current = new node;
        current = head;
        
        while(current->prox != NULL){
            current = current->prox;
        }
        std::cout<< "Ultimo valor:" << current->info<< "\n";
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
            std::cout <<temp->info<<"\t";
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



int main(int argc, const char * argv[]) {
    LinkedList list;
    list.createNode(5);
    list.createNode(4);
    list.insertStart(1);
    list.insertStart(8);
    list.insertPosition(3, 2);
    list.deleteFirst();
    list.deleteFirst();
    list.getLast();
    list.display();
    
    return 0;
}
