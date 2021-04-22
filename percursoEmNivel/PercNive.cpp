#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct no* arv;
typedef struct no{ int c;  arv le, ld; }no;
arv T,  Q[100000001];  int nc, n;

void EsvaziaFila(int &f, int &r){
    f = r = 0;
}

void Enfila(arv Q[], int &f, int &r, arv p){
    if (p != NULL){
        Q[++r] = p;
        if (f==0) 
			f = 1;
    }
}
arv Desenfila(arv Q[], int &f, int &r){
    arv p;
    p = Q[f];
    if (f == r) 
		EsvaziaFila(f, r);
    else 
		f++;
    return p;
}

arv CriaArv(int n){
    arv p, s, T;  int i, f, r;
    EsvaziaFila(f, r);
    T = new(no);  T->c = 1;  T->le = T->ld = NULL; Enfila(Q, f, r, T);
    i=1;
    while (f != 0){
        p=Q[f];
        // O valor maior vai para a ramificação a direita do no
        if (i > n){
            i++;  s = new(no);  s->c = i;  s->le = s->ld = NULL;
            p->ld = s;  Enfila(Q, f, r, s);
        }
        if (i < n){
            i++;  s = new(no);  s->c = i;  s->le = s->ld = NULL;
            p->le = s;  Enfila(Q, f, r, s);
        }
        p = Desenfila(Q, f, r);
    }
    return T;
}  
   
void PercNiv(arv T){
    arv p;   int f, r, v;

    EsvaziaFila(f, r);
    Enfila(Q, f, r, T);
    v = 0;
    while (f > 0)
    {
        v++;
        p = Q[f];
        if (v <= 100)
            cout<<p->c<<" ";
        Enfila(Q, f, r, p->le);
        Enfila(Q, f, r, p->ld);
        p = Desenfila(Q, f, r);
    }
    cout<<endl;

}
int main(){
    while (true){
        cout<<endl<<"Numero de nos: "; cin >> n;
        if (!n) break;
        T = CriaArv(n);
        PercNiv(T);
    }
}

