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
        int valorEntrada;
        while (true){
            cout << endl << "---------------------------------------------------" << endl;
            cout << "Informe o tamanho da Arvore: ";
            cin >> valorEntrada;
            if (valorEntrada < 1 || valorEntrada > 32767){
                cout << "\n\nTamanho invalido. Tente novamente." << endl;
            } else {
                n = valorEntrada;
                break;
            }
        }
        
    }
    
};
