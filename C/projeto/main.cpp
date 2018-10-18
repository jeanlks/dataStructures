#include <iostream>
#include "arvoreABB.cpp"
#include "arvoreSplay.cpp"
#include "teste.cpp"
#include <map>

int main() {
    const int MIN= 0;
    const int MAX_RANDOM =32767;
    Splay<int> splay;
    Abb abbTree;
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
        numAleatorio = teste.random(MIN, MAX_RANDOM);
        aleatorioAgrupado[numAleatorio]++;
        aleatorios[i] = numAleatorio;
    }
    /**
     Construcao da arvore binaria
     **/
    teste.IniciarContagem();
    for (int i = 0; i< teste.getN(); ++i) {
        abbTree.setRoot(abbTree.insert_tree(abbTree.getRoot(), aleatorios[i]));
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
    cout << "\nChaves Iguais: " << abbTree.getChavesIguais();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Tempo Processamento Arvore Binaria: " << tempoProcessamentoArvoreBinaria;
    cout << "\n Tempo Processamento Splay: " << tempoProcessamentoArvoreSplay;
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Altura Arvore Binaria: " << abbTree.height(abbTree.getRoot());
    cout << "\n Altura arvore Splay: " << splay.height(splay.root);
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\n Número de Comparacoes Arvore Binaria: " << abbTree.getComparacoes() << "\n";
    cout << "\n Número de Comparacoes Arvore Splay: " << splay.getComparacoes() << "\n";
    cout << "\n Média de Comparacoes Arvore Binaria: " << (double) abbTree.getComparacoes()/teste.getN() << "\n";
    cout << "\n Média de Comparacoes Arvore Splay: " << (double) splay.getComparacoes()/teste.getN()<< "\n";
    cout << "\n-------------------------------------------------------------------------\n";
     cout << "\nQuantidade de duplicados\n";
    teste.getCountEquals(aleatorios,teste.getN());
     cout << "\n-------------------------------------------------------------------------\n";
    return 0;
    
}
