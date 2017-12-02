#include <time.h>
#include <iostream>
#include <map>
#include <vector>

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
    static bool sortinrev(const pair<int,int> &a,
                   const pair<int,int> &b)
    {
        return (a.second > b.second);
    }
    
    void getCountEquals(int R[], int number) {
        map<int, int> counts;
        for (int i = 0; i < number; i++) {
            counts[R[i]]++;
        }
        vector<pair<int, int> > v;
        copy(counts.begin(),
             counts.end(),
             back_inserter<vector<pair<int, int> > >(v));
        
        sort(v.begin(), v.end(), sortinrev);
        
        for (size_t i = 0; i < 12; ++i) {
            cout << v[i].first << " , " << v[i].second << "\n";
        }


    }

};
