#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std; //para utilizar cout

//Struct para pessoa
struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;
};

//Limpa a tela
void limpatela(){
    system("CLS");
}

//Conta quantos elementos tem na lista
int retornaTamanhoListaEncadeada(pessoa *ponteiroEncadeada){

   //Tamanho da lista
   int tamanho = 0;

   //Ponteiro auxiliar para percorrer a lista
   pessoa *p = ponteiroEncadeada;

   while(p != NULL){

       //Transforma o P no endereco do proximo valor, Caso o endereco seja NULL, estamos no fim da lista
        p = p->proximo;

        //Contador de tamanho da lista
        tamanho++;
   }

   return tamanho;

}

//Imprime a lista encadeada
void imprimeEncadeada(pessoa *ponteiroEncadeada) {

   //Cabeçalho da Lista
   //cout << "Lista(Tamanho:"<< retornaTamanhoListaEncadeada(*ponteiroEncadeada) << ")\n";

   //Ponteiro auxiliar para percorrer a lista
   pessoa *p = ponteiroEncadeada;

   //Mostra a posicao do elemento
   int posicao = 0;

   //Enquanto o p nao for nulo
   while(p != NULL){

        //Imprime o valor da lista
        cout << posicao << " - " << p->nome << ", " << p->rg << "\n";

        //Transforma o P no endereco do proximo valor, Caso o endereco seja NULL, estamos no fim da lista
        p = p->proximo;

        //Incrementa a variavel da posicao dos elementos
        posicao++;
   }

   //Libera Memoria
   free(p);

}

//Adiciona um elemento ao começo
void adcComecoEncadeada(pessoa *&ponteiroEncadeada, string nome, int rg){

    //Cria uma nova estrutura
    pessoa *novovalor = new pessoa;
    novovalor->nome = nome;
    novovalor->rg = rg;
    novovalor->proximo = ponteiroEncadeada;

    //Redireciona o ponteiro
    ponteiroEncadeada = novovalor;

}

//Adiciona um elemento ao fim
void adcFimEncadeada(pessoa *ponteiroEncadeada, string nome, int rg){

    //Cria um novo valor
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //Cria um cursor que percorre a lista
    pessoa *p = ponteiroEncadeada;

        //Enquanto o p nao for nulo
        while(p != NULL){

            //Se estiver no ultimo elemento
            if(p->proximo == NULL){

                //Faz ele acrescentar o novo valor e sair do while
                p->proximo = novoValor;
                return;
            }

            //Transforma o P no endereco do proximo valor
            //Caso o endereco seja NULL, estamos no fim da lista
            //E saimos do while
            p = p->proximo;

        }

    //Libera Memoria
    free(p);
    free(novoValor);

}

//Adiciona valor numa posicao especifica
void adcPosicaoEncadeada(pessoa *ponteiroEncadeada,string nome,int rg, int posicao){

    //Criar NODE com um valor
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    //Ponteiro Auxiliar
    pessoa *p = ponteiroEncadeada;

    //Variavel que percorre a lista
    int i = 0;

    //Criar o auxiliar para Salvar o endereco em K-1 ->proximo
    while(i <= posicao){

        if(i == posicao-1){

            //Auxiliar do valor
            pessoa *aux = new pessoa;

            //Precisamos armazenar o endereco a ser apontado pelo novo node
            aux->proximo = p->proximo;

            //Fazendo o elemento K-1 apontar para o novo NODE
            p->proximo = novoValor;

            //Fazendo o novo NODE apontar para a auxiliar
            novoValor->proximo = aux->proximo;

            //Libera a Memoria
            free(aux);

        }

        //Analisa o proximo membro da lista
        p = p->proximo;

        //Contador de posiÁıes
        i++;

    }

}

int main(){

    //Vari·veis
    int funcaoDesejada = 1, tamanho;

    //Cria o inicio da lista Encadeada
    pessoa *ponteiroEncadeada;

    //Cria um novo valor para o primeiro
    pessoa *novoPrimeiroValor = new pessoa;
    novoPrimeiroValor->nome = "john";
    novoPrimeiroValor->rg = 13;
    novoPrimeiroValor->proximo = NULL;

    //Transforma o ponteiro do inicio da lista no novo valor
    ponteiroEncadeada = novoPrimeiroValor;

    //Cria um novo valor para o segundo
    pessoa *novoSegundoValor = new pessoa;
    novoSegundoValor->nome = "johnzin";
    novoSegundoValor->rg = 20;
    novoSegundoValor->proximo = NULL;

    //Colocando o segundo valor
    novoPrimeiroValor->proximo = novoSegundoValor;

     //Manipula as listas
    while(funcaoDesejada < 10 && funcaoDesejada > 0){

        cout << "Operacoes \n";
        cout << "1 - Insercao de um node no inicio da lista \n";
        cout << "2 - Insercao de um node no fim da lista \n";
        cout << "3 - Insercao de um node na posicao N \n";
        cout << "4 - Retirar um node do inicio da lista \n";
        cout << "5 - Retirar um node no fim da lista \n";
        cout << "6 - Retirar um node na posicao N \n";
        cout << "7 - Procurar um node com o campo RG \n";
        cout << "8 - Imprimir a Lista. \n";
        cout << "9 - Sair do sistema. \n";
        cout << "\nEscolha um numero e pressione ENTER: \n";

        cout << "\nTamanho Atual[" << retornaTamanhoListaEncadeada(ponteiroEncadeada) << "]\n";

        imprimeEncadeada(ponteiroEncadeada);

        //LÍ a opÁ„o
        cin >> funcaoDesejada;

        //Limpa as opÁıes
        limpatela();

        //Vari·veis para valores novos
        string nome;
        int rg, posicao,posicaoNaLista;

        //Alterna as Operacoes
        switch(funcaoDesejada){

            case 1:

                //Cabeçalho da acao
                cout << "Funcao Escolhida: Insere um node no inicio da lista\n";

                //Lendo valores do usuario
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                //Adiciona no inicio
                adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                //Exibe o usuario inserido
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado ao inicio da lista)";

                break;

            case 2:

                //Cabeçalho da acao
                cout << "Funcao Escolhida: Insere um node no fim da lista\n";

                //Lendo valores do usuario
                cout << "\nDigite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(retornaTamanhoListaEncadeada(ponteiroEncadeada) < 1){

                        //Adiciona ao inicio da Lista
                        adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else{

                        //Adiciona ao fim da Lista
                        adcFimEncadeada(ponteiroEncadeada, nome, rg);
                }

                //Exibe o usuario inserido
                cout << "Usuario: "<< nome<< ",RG: "<< rg<< " adicionado ao final da lista("<< retornaTamanhoListaEncadeada(ponteiroEncadeada) << ")";

                break;

            case 3:

                //Cabeçalho da acao
                cout << "Funcao Escolhida: Insere um node na posicao escolhida da lista\n";

                //Lendo valores do usuario
                cout << "\nDigite a Posicao: ";
                cin >> posicao;
                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o RG: ";
                cin >> rg;

                if(posicao == 0 ){

                    //Adiciona ao inicio da Lista
                    adcComecoEncadeada(ponteiroEncadeada, nome, rg);

                }else if(posicao == retornaTamanhoListaEncadeada(ponteiroEncadeada) - 1){

                    //Adiciona ao fim da Lista
                    adcFimEncadeada(ponteiroEncadeada, nome, rg);

                }else{

                    //Adiciona na posicao N da Lista
                    adcPosicaoEncadeada(ponteiroEncadeada,nome,rg, posicao);

                }

                //Exibe o usuario inserido
                cout << "Usuario: " << nome << ",RG: " << rg << " adicionado na posicao "  <<  posicao  << " da lista.";

                break;

            case 4:

                break;

            case 5:



                break;

            case 6:


                break;

            case 7:


                break;

            case 8:


                break;

        }
    }

    return 0;
}
