#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct no *lista;
struct no{ int x;  lista prox; };
lista p, cab;  int i, n, q, k;

void ImprimeLista(lista cab){
    lista p;
    p=cab->prox;
    while(p != NULL){
        cout<<p->x<<" ";
        p = p->prox;
    } 
	cout<<endl;    
}
void CriaLista(int n){
    lista p, q;  int i;
    p = new(no);  p->x = rand()%50+1;  q=p;  cab=p;
    for (i=2; i<=n; i++){
        p->prox = new(no);
        p = p->prox;   p->x = q->x + rand()%10+1;  q=p;
    }
    p->prox = NULL;
}

void BuscaTAO(lista cab, int k){
    lista ant, pont, p;
    p = cab->prox;
    ant = cab;
    while(p != NULL)
    {
        if(p->x == k)
        {
            ant->prox = p->prox;
            p->prox = cab->prox;
            cab->prox = p;
            p = NULL;
        }
        else
        {
            ant = p;
            p = p->prox;
        }
    }
}

int main(){
    while(1){
        cout<<endl<<"Informe n: ";  cin >>n;
        if (!n) break;
        CriaLista(n);
        ImprimeLista(cab);
        k=1;
        while (k > 0){
			cout<<" Buscar (0 para a busca): ";  cin>>k;
			BuscaTAO(cab, k);
            ImprimeLista(cab); 
		}
    }
    return 0;
}
