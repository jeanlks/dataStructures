#include <iostream>
#include "splay.cpp"
#include "ab.cpp"
#include "teste.cpp"

int main() {
    int MAX=32768;
    int MIN= 0;
    Splay<int> splay;
    btree tree;
    Teste teste;
    teste.LerValorEntrada();
    teste.IniciarContagem();
    int aleatorioAgrupado[32768]={0};
    int aleatorios[32768]={0};
    int numAleatorio = 0;
    
    /**Preenche vetor com numeros aleatorios para que depois seja possível testar as estruturas
       com o mesmo conjunto de aleatorios.
     **/
    for (int i = 0; i < teste.getN(); ++i) {
        numAleatorio = teste.random(MIN, MAX);
        aleatorioAgrupado[numAleatorio]++;
        aleatorios[i] = numAleatorio;
    }
    /**
     Construcao da arvore binaria
     **/
    teste.IniciarContagem();
    for (int i = 0; i< teste.getN(); ++i) {
        tree.setRoot(tree.insert_tree(tree.getRoot(), aleatorios[i]));
    }
    teste.FinalizarContagem();
    double tempoProcessamentoArvoreBinaria = teste.getTempoDecorrido();
   
    /**
     Construcao da arvore Splay
     **/
    teste.IniciarContagem();
    for (int i = 0; i< teste.getN(); ++i) {
        splay.insert(aleatorios[i]);
    }
    teste.FinalizarContagem();
    double tempoProcessamentoArvoreSplay = teste.getTempoDecorrido();
    
    
    
    
    cout << "\n Chaves iguais Arvore Binaria: " << tree.getContadorChavesIguais();
    cout << "\n Chaves iguais Arvore Splay: " << splay.getContadorChavesIguais();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Tempo Processamento Arvore Binaria: " << tempoProcessamentoArvoreBinaria;
    cout << "\n Tempo Processamento Splay: " << tempoProcessamentoArvoreSplay;
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Altura Arvore Binaria: " << tree.height(tree.getRoot());
    cout << "\n Altura arvore Splay: " << splay.height(splay.root);
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Comparacoes Arvore Binaria: " << tree.getComparacoes() << "\n";
    cout << "\n Comparacoes Arvore Splay: " << splay.getComparacoes() << "\n";
    return 0;
    
}
