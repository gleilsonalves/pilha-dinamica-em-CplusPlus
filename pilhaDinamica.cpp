#include <iostream>
#include <windows.h>

using namespace std;

struct pilha{
    int item;
    pilha *prox;
};

pilha *topo;
static int contador = 0;

void inicializarPilha(){
    topo = NULL;
    cout << "Pilha criada e inicializada!" << endl;
}

bool estaVazia(){
    if(topo == NULL){
        return true;
    }else{
        return false;
    }
}

void reinicializarPilha(){
    pilha *temp;

    if (estaVazia()){
        cout << "Pilha esta Vazia!" << endl;
    }else{
        while (topo != NULL){
        temp = topo;
        temp->prox = NULL;

        topo = topo->prox;

        delete(temp);
        }

        topo = NULL;
        contador = 0;
        cout << "Pilha Reiniciada." << endl;
    }
}

void pilhaPush(int valor){
    pilha *novo = new pilha;

    novo->item = valor;
    novo->prox = topo;

    topo = novo;
    contador++;
}

void pilhaPop(int &valor){
    pilha *temp;
    if (estaVazia()){
        cout << "Pilha esta Vazia." << endl;
    }else{
        valor = topo->item;

        temp = topo;
        topo = topo->prox;

        temp->prox = NULL;
        contador--;

        delete(temp);
        cout << "Valor desempilhado!" << endl;
    }
}

void exibirPilha(){
    if (estaVazia()){
        cout << "Pilha esta Vazia!" << endl;
    }else{
        pilha *aux;
        aux = topo;

        cout << "A quantidade de itens empilhados eh: " << contador << endl;

        cout << "Itens empilhados: " << endl;
        while (aux != NULL){
        cout << aux->item << "/ ";
        aux = aux->prox;
        }
        delete(aux);
    }
}

void inputValorPush(int valor){
    char op;

    do{
        cout << "Informe um valor: ";
        cin >> valor;
        pilhaPush(valor);
        system("cls");
        cout << "Quer continuar inserindo valores?" << endl;
        cout << "Digite 's' para SIM e 'n' para NAO." << endl;
        cout << "R= ";
        cin >> op;
        system("cls");
    }while(op == 's');
}

void aguardar(){
    Sleep(2000);
    system("cls");
}

void menu(){
    int valor;
    int op;

    cout << "*******************************" << endl;
    cout << "******* Pilha Dinamica ********" << endl;
    cout << "*******************************" << endl;
    cout << "1 - Inserir Valor na Pilha." << endl;
    cout << "2 - Exibir Pilha." << endl;
    cout << "3 - Desempilhar." << endl;
    cout << "4 - Reiniciar Pilha." << endl;
    cout << "0 - Sair." << endl;
    cout << "\nEscolha uma opcao: ";
    cin >> op;


    switch (op){  
        case 1:
        system("cls");
        inputValorPush(valor);
        system("cls");
        menu();
        break;

        case 2:
        system("cls");
        exibirPilha();
        aguardar();
        menu();
        break;

        case 3:
        system("cls");
        pilhaPop(topo->item);
        aguardar();
        menu();
        break;

        case 4:
        system("cls");
        reinicializarPilha();
        aguardar();
        menu();
        break;

        case 0:
        system("cls");
        cout << "Saindo do programa!!!" << endl;
        aguardar();
        break;
    }  
}

int main(){
    system("cls");
    inicializarPilha();
    aguardar();
    menu();
}