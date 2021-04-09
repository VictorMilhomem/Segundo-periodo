#include<iostream>
using namespace std;

typedef struct no* pont;
struct no{ int x;  pont prox; };
pont p, r, t, cab;

void ImprimeLista(pont cab){
    pont p;
    p = cab;
    while (p != NULL){
        cout<< p->x <<" ";  p = p->prox;
    }
    cout<<endl;
}
void Crialista(){  
    cab = new(no);  cab->x = 1;   p = cab;
    for(int  i = 2; i <= 10; i++){
        p->prox = new(no);  p = p->prox;   p->x = i;
    }
    p->prox = NULL;
}

void Invertelista1(){ 
    p = cab;  r = NULL;
    while (p != NULL){
        t = p->prox;   
		p->prox = r;  
		r = p;  
		p = t;
    }
    cab = r;
    ImprimeLista(cab);
}

void Invertelista2(){ 
    int topo,  pil[101];

    p = cab;
    topo = 0;
    while(p != NULL)
    {
        pil[++topo] = p->x;
        p = p->prox;
    }
    p = cab;

    while(p != NULL)
    {
        p->x = pil[topo--];
        p = p->prox;
    }
    ImprimeLista(cab);
}

int main(){
    Crialista();
    ImprimeLista(cab);
    Invertelista1();
    Invertelista2();
    cin.get();
    return 0;
}
