#include <time.h>
#include <iostream>

using namespace std;
class Teste {
private:
    clock_t tempoInicial;
    clock_t tempoFinal;
    int n = 0;
public:
    void IniciarContagem() {
        tempoInicial = 0;
        tempoInicial = clock();
    }
    void FinalizarContagem() {
        tempoFinal = 0;
        tempoFinal = clock();
    }
    
    double getTempoDecorrido() {
        return (double)(tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
    }
    
    void setValorDeN(int value) {
        n = value;
    }
    
    int getN() {
        return n;
    }
    
    int random(int min, int max)
    {
        static bool first = true;
        if ( first )
        {
            srand(time(NULL)); 
            first = false;
        }
        return min + rand() % (max - min);
    }
    
    void LerValorEntrada() {
        int MAX = 1000000 ;
        int valorEntrada;
        while (true){
            cout << "\n-------------------------------------------------------------------------\n";
            cout << "\n---------------------Projeto EDPA 2017-----------------------------------\n";
            cout << "\n-------------------------------------------------------------------------\n";
            cout << "Informe o tamanho da Arvore: ";
            cin >> valorEntrada;
            if (valorEntrada < 1 || valorEntrada > MAX){
                cout << "\n\nTamanho invalido. Tente novamente." << endl;
            } else {
                n = valorEntrada;
                break;
            }
        }
    }
    
    
    void printChavesIguais(int R[], int agrupado[], int tamanhoVetor) {
        for (int i=0; i < tamanhoVetor; i++){
            if (R[i] > 0)
                agrupado[R[i]]++;
        }
        cout << endl;
        cout << endl;
        cout << "Chaves" << "\t\tVezes\t\tTotal";
        cout << endl;
        for (int i=0; i < 10; i++){
            if (agrupado[i] > 0){
                cout <<agrupado[i] << "\t\t" << i << "\t\t" << (agrupado[i] * i) << endl;
            }
        }
    }
};
