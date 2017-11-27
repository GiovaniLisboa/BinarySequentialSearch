#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>

using std:: cout;
using std:: cin;
using std:: vector;

void aleatorio(int &); // Função para definir os números aleatoriamente
bool trocar (int &, int &); // Função para trocar inteiros
bool trocar (double &, double &); // Função para trocar double
void bubblesort (vector <int> &);
void binary (vector <int> &, int, int, int);
//void sequencial (vector <int> &, int, int, int);

bool teste = true;
int cont;
char resposta;

int main(int argc, char **argv)
{
    srand (time(NULL)); //Redefine os números aleatórios a cada execução
    
    vector <int> meuvetor (0);
    
    while (teste == true)
    {
        meuvetor.push_back(rand() % 20);
        cout << "A[" << meuvetor.size() << "]: " << meuvetor.back() << "\n \n";
        
        resposta = 'a';
        while (resposta != 's' && resposta != 'n')
        {
            cout << "Deseja entrar com um novo valor? (s/n)\n";
            cin >> resposta;
            cout << "\n";
        }
        
        if (resposta == 's')
            teste = true;
            else teste = false;
    }
    
    bubblesort (meuvetor);
    
    int premio = meuvetor [rand() % (meuvetor.size() - 1)];
    cout << "Premio: " << premio << "\n\n";
    
    binary (meuvetor, premio, 1, meuvetor.size());
    
    //sequencial (meuvetor, premio, 0, meuvetor.size());
    
    cout << "\n";
    return 0;
}

void bubblesort (vector <int> &vetor)
{
    for (int i = 0; i < vetor.size(); i++) //Loop de repetição para definir os valores das células
    {
        cout << "A[" << i+1 << "]: " << vetor[i] << "\n";
    }

    cout << "\n";

    while (teste == false) //Loop de teste para verificar se o vetor está em ordem (Só precisa executar no mínimo uma vez)
    {
        teste = true;
        for (int i = 0; i < vetor.size() - 1; i++) //Repetição para trocar os valores
        {
            if (trocar(vetor[i], vetor[i+1]))
            {
                cont++;
                teste = false;
            }
        }
    }
        
    cout << "Trocas: " << cont << "\n"; //Informa o número de trocas
    cout << "\n";
    for (int i = 0; i < vetor.size(); i++) //Escreve o vetor
    {
        cout << "A[" << i+1 << "]: " << vetor[i] << "\n";
    }
    
    cout << "\n";
}

bool trocar (int &x, int &y)
{
    int temp;
    
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
        return true;
    }
    else return false;
}

bool trocar (double &x, double &y)
{
    int temp;
    
    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
        return true;
    }
    else return false;
}

void binary (vector <int> &vetor, int prem, int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    
    cout << "A[" << meio+1 << "]: " << vetor [meio] << "\n";
    
    if (vetor [meio] == prem)
    {
        cout << "\nA[" << meio+1 << "] = Premio\n";
    }
        else    if (inicio >= fim)
                cout << "Nao encontrado";
                else    if (vetor [meio] < prem)
                            {
                                binary(vetor, prem, meio+1, fim);
                            }
                            else    if (vetor [meio] > prem)
                                    {
                                        binary(vetor, prem, inicio, meio-1);
                                    }
}

//void sequencial (vector <int> &vetor, int prem, int inicio, int fim)
//{
    
//}