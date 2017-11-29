#include <cstdio>
#include <cstdint>
#include <iostream>
using namespace std;
template<class T>
struct Node {
    T value;
    Node* l, *r, *p;
    
    Node() { l = r = p = nullptr; }
    
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
    
    void setL(Node* L) { l = L; if (l) l->p = this; }
    void setR(Node* R) { r = R; if (r) r->p = this; }
};

template<class T>
struct Splay {
    Node<T>* root = nullptr;
    
    ~Splay() { if (root) delete root; }
    
private:
    int contadorComparacoes =0;
    int contadorChavesIguais =0;
public:
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
    
    void rotate(Node<T>* A, Node<T>* B) {
        Node<T>* p = A->p;
        
        if (A->l == B) {
            A->setL(B->r);
            B->setR(A);
        } else {
            A->setR(B->l);
            B->setL(A);
        }
        
        if (!p) root = B, B->p = nullptr;
        else if (p->l == A) p->setL(B);
        else p->setR(B);
    }
    
    void splay(Node<T>* A) {
        while (A != root) {
            Node<T>* B = A->p;
            Node<T>* C = A->p->p;
            
            if (B == root) {
                rotate(B, A);
                break;
            }
            
            if ((C->l && C->l->l == A) || (C->r && C->r->r == A)) {
                rotate(C, B);
                rotate(B, A);
            } else {
                rotate(B, A);
                rotate(C, A);
            }
        }
    }
    
    void insert(T value) {
        Node<T>* B = nullptr;
        Node<T>* A = root;
        
        while (A) {
            B = A;
            if(value== A->value){
                
            }
            if (value < A->value)
                A = A->l;
            else
                A = A->r;
        }
        
        Node<T>* C = new Node<T>;
        C->value = value;
        
        if (root == nullptr) {
            root = C;
        } else {
            if (value < B->value) B->setL(C);
            else B->setR(C);
            splay(C);
        }
    }
    int height (Node<T> *n) {
        if (n == NULL)
            return -1;
        else {
            int lh = height(n->l);
            int rh = height(n->r);
            if (lh < rh) return rh + 1;
            else return lh + 1;
        }
    }
    void print(Node<T>* n, int depth = 0) {
        if (n->l) print(n->l, depth + 1);
        
        for (int i = 0; i < depth*3; ++i)
            printf(" ");
        printf("%u\n", n->value);
        
        if (n->r) print(n->r, depth + 1);
    }

};





