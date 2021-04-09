#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

typedef struct no* lista;
typedef struct no{ int chave; lista prox;}mo;          
typedef struct fila{ lista  f, r;}fila;

int n, maiorvalor; fila filas[11];


void Imprime(int t){
    lista p;  int nn=0;
    if (t == 1) cout <<endl<<"Situacao Inicial: " << endl;
    else if (t == 2) cout <<endl<<"Situacao Intermediaria: " << endl;
    else cout <<endl<<"Situacao Final: "<< endl;
    p = filas[10].f;
    while (p != NULL && nn<100){
        cout << p->chave <<" ";  p = p->prox; nn++;
    }
    cout <<endl;
    cin.get();
}

int Digito (int d, int k){
    int i, j;
    j = k;
    for (i=1; i<=(d-1); i++)
    {
        j = j/10;
    }
    j = j%10;
    return j;
}

void Enfila (int nf, int k){
    lista p;
    p = new(no);  p->chave = k;  p->prox = NULL;
    if (filas[nf].r != NULL) filas[nf].r->prox = p;
    else                     filas[nf].f = p;
    filas[nf].r = p;
}

int Desenfila (int nf){
    int k; lista p;
    if (filas[nf].f != NULL){
        p = filas[nf].f; filas[nf].f = filas[nf].f->prox;
        if (filas[nf].f == NULL) filas[nf].r = NULL;
        k = p->chave;
        free(p);
    }
    else  k = -1;
    return k;
}

void Crialista(){
    int i, k;
    for (i=0; i<=10; i++){
        filas[i].f = NULL;
        filas[i].r = NULL;
    }
    //Cria n�meros entre 0 e 1000
    maiorvalor = -1;
    for (i=1; i<=n; i++){
        k = rand()%1000;
        Enfila(10, k);
        if (k > maiorvalor)
        {
            maiorvalor = k;
        }
    }
}

void Ordena(){
    int d, i, j, k, m;
    int cont = 0;

    if(maiorvalor == 0) cont =1;
    else{
        while(maiorvalor != 0){
            cont++;
            maiorvalor = maiorvalor/10;
        }
    }
    for (d=1; d<=cont; d++){
        for (i=1; i<=n; i++){
            k = Desenfila(10);  m = Digito (d, k);
            Enfila(m,k);
        }
        for (j=0; j<=9; j++)
            while (filas[j].f != NULL){
                k = Desenfila(j);
                Enfila(10,k);
            }
        Imprime(2);
    }
}

int main(){
    while(true){
        cout <<"Numero de elementos a ordenar: "; cin >> n;
        if (!n) break;
        
        Crialista();
        Imprime(1);
        Ordena();
        Imprime(3);
    }    
    return 0;
}
