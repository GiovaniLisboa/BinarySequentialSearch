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
void sequencial (vector <int> &, int);
void fillvector (vector <int> &);

bool teste = false;
int cont;
int exec_bin = 0;
int exec_seq = 0;

int main(int argc, char **argv)
{
    srand (time(NULL)); //Redefine os números aleatórios a cada execução
    
    int ITER = 10;
    int novotamanho;
    
    vector<int> meuvetor (0);
    
    while (meuvetor.size() < 2 || meuvetor.size() > 20)
    {
        cout << "Insira o tamanho do vetor (2 a 20): \n";
        cin >> novotamanho;
        meuvetor.resize( novotamanho );
    }
    
    for (int i = 0; i < ITER; i++)
    {
        cout << "ITERACAO " << i+1 << "\n\n";
        
        fillvector( meuvetor );
        
        bubblesort( meuvetor );
    
        int premio = meuvetor [rand() % (meuvetor.size() - 1)];
        cout << "Premio: " << premio << "\n\n";
    
        // Fazer média das execuções
        cout << "Binary Search\n";
        binary (meuvetor, premio, 1, meuvetor.size());
    
        cout << "\n\n";
    
        cout << "Sequencial Search\n";
        sequencial (meuvetor, premio);
    
        cout << "\n\n";
    }
    
    cout << "Media de tentativas em Binary Search: " << exec_bin / ITER << "\n";
    cout << "Media de tentativas em Sequencial Search: " << exec_seq / ITER << "\n";
    
    return 0;
}

void bubblesort (vector <int> &vetor)
{
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

void binary (vector <int> &vetor, int chave, int inicio, int fim)
{
    exec_bin++;
    
    int meio = (inicio + fim) / 2;
    
    cout << "A[" << meio+1 << "]: " << vetor [meio] << "\n";
    
    if (vetor [meio] == chave)
    {
        cout << "\nA[" << meio+1 << "] = Premio\n";
    }
        else    if (inicio >= fim)
                cout << "Nao encontrado\n";
                else    if (vetor [meio] < chave)
                            {
                                binary(vetor, chave, meio+1, fim);
                            }
                            else    if (vetor [meio] > chave)
                                    {
                                        binary(vetor, chave, inicio, meio-1);
                                    }
}

void sequencial (vector <int> &vetor, int chave)
{
    for (int i = 0; i < vetor.size() - 1; i++)
    {
        exec_seq++;
        
        cout << "A[" << i+1 << "]: " << vetor [i] << "\n";
        
        if (vetor[i] == chave)
        {
            cout << "\nA[" << i+1 << "] = Premio\n";
            break;
        }
        
        if (vetor [i] != chave && i == vetor.size()-1)
            cout << "Nao encontrado\n";
    }
}

void fillvector (vector <int> &vetor)
{   
    for (int i = 0; i < vetor.size(); i++)
    {
        vetor [ i ] = rand() % 20;
        cout << "A[" << i+1 << "]: " << vetor [ i ] << "\n";
    }
    cout << "\n";
}