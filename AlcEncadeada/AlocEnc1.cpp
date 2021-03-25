#include<iostream>
using namespace std;

typedef struct no *pont;
struct no { int c;  pont prox; };
pont cab,p,q;

void ImprimeLista(pont cab){
    pont p;
    p = cab;
    while (p != NULL){
        cout<< p->c <<" ";
        p = p->prox;
    }
    cout<<endl;
}
void Crialista1(){

    cab = new(no);   
	cab->c = 1;   
	p = new(no);     
	p->c = 2;  
	q = new(no);  
	q->c = 3;
    cab->prox = p;   
	p->prox = q;  
	q->prox = NULL;
    ImprimeLista(cab);         
}
void Crialista2(){

    cab = new(no);  
	cab->c = 1;   
	p = new(no);  
	p->c = 2;     
	cab->prox = p;
    p = new(no);    
	p->c = 3;     
	cab->prox->prox = p;        
	p->prox = NULL;
    ImprimeLista(cab);       
}
void Crialista3(){

	cab = new(no);
	p = cab;
	p->c = 1;
	p->prox = new(no);
	p = p->prox;
	p->c = 2;
	p->prox = new(no);
	p = p->prox;
	p->c = 3;
	p->prox = NULL;
	ImprimeLista(cab);
     
}

int main(){
    Crialista1();
    Crialista2();
    Crialista3();
    cin.get();
}
