#include <iostream>
#include "splay.cpp"
#include "ab.cpp"
#include "teste.cpp"

int main() {
    int MIN= 0;
    Splay<int> splay;
    btree tree;
    Teste teste;
    teste.LerValorEntrada();
    teste.IniciarContagem();
    int aleatorioAgrupado[1000000]={0};
    int aleatorios[1000000]={0};
    int numAleatorio = 0;
    
    /**Preenche vetor com numeros aleatorios para que depois seja possível testar as estruturas
       com o mesmo conjunto de aleatorios.
     **/
    for (int i = 0; i < teste.getN(); ++i) {
        numAleatorio = teste.random(MIN, teste.getN());
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
    cout << string(50, '\n');
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\nChaves Geradas: " << teste.getN();
    cout << "\nChaves Iguais: " << tree.getChavesIguais();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Tempo Processamento Arvore Binaria: " << tempoProcessamentoArvoreBinaria;
    cout << "\n Tempo Processamento Splay: " << tempoProcessamentoArvoreSplay;
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Altura Arvore Binaria: " << tree.height(tree.getRoot());
    cout << "\n Altura arvore Splay: " << splay.height(splay.root);
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Número de Comparacoes Arvore Binaria: " << tree.getComparacoes() << "\n";
    cout << "\n Número de Comparacoes Arvore Splay: " << splay.getComparacoes() << "\n";
    cout << "\n Média de Comparacoes Arvore Binaria: " << tree.getComparacoes()/teste.getN() << "\n";
    cout << "\n Média de Comparacoes Arvore Splay: " << splay.getComparacoes()/teste.getN()<< "\n";
    cout << "\n-------------------------------------------------------------------------\n";
    teste.printChavesIguais(aleatorios,aleatorioAgrupado,teste.getN());
    return 0;
    
}
