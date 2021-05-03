#include<iostream>
#include<cstdlib>
using namespace std;

struct no{char op; int e;  int d;};
no S[200];
int V[100000001], V1[50000001], V2[50000001], i, n, topo, maxpil, cont;
long long int comp;

void Merge(int V[], int e, int d){
int i, j, k, m;
	m = (e+d)/2;
    for (i=1; i<= m-e+1; i++){
        V1[i]=V[e+i-1];  
		V2[i]=V[m+i];
    }
    V1[m-e+2] = V2[d-m+1] = max(V[m],V[d])+1;
    i=1;  j=1;
    for (k=e; k<=d; k++){
        if (V1[i]<V2[j]) 
			V[k]=V1[i++];
        else 
			V[k]=V2[j++];
    }
    comp += d - e + 1; 
}

void MergeSortPil(int V[], int c, int n){
    no noa, nob;   int m;
    topo = 0;   maxpil = 0; cont = 0;
	noa = {'O', c, n};
    S[++topo] = noa;
    while(topo > 0){
        noa = S[topo--];
		cout<<"Saindo da pilha: "<<noa.op<<" "<<noa.e<<" "<<noa.d<<endl;
        m = (noa.e +noa.d)/2;
		if (noa.op == 'M'){
			Merge(V, noa.e, noa.d);
            maxpil = 0;
        }
		else if (noa.d > noa.e){	
		    nob = {'M', noa.e, noa.d};   S[++topo] = nob;
		    nob = {'O', m+1, noa.d};     S[++topo] = nob;
		    nob = {'O', noa.e, m};       S[++topo] = nob;
            maxpil += 3;
		}
        if (maxpil > cont)
            cont = maxpil; 
    }
}
int main(){
    while(true){
        cout<<"n = ";  cin>>n;   
		comp=0;  
		maxpil=0;
        for(i=1; i<=n; i++) 
			V[i]= rand()%n;
        cout<<endl<<"Situacao inicial - primeiros "<<min(n, 40)<<" elementos:"<<endl;
        for(i=1; i<=min(n,40); i++) 
			cout<<V[i]<<" ";  
		cout<<endl;
        MergeSortPil(V, 1, n);
        cout<<endl<<"Situacao final - primeiros "<<min(n, 40)<<" elementos:"<<endl;
        for(i=1; i<=min(n,40); i++) 
			cout<<V[i]<<" ";  
		cout<<endl;
        cout<<endl<<"Comparacoes efetuadas: "<<comp<<" Tamanho maximo da pilha: "<<cont<<endl;        
    }
    return 0;
}
