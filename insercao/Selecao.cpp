#include<iostream>
using namespace std;

int V[10000001], n; long long int comp;

void Imprime(string s, int V[], int n)
{   cout <<"Situacao "<<s<<" dos primeiros elementos:"<<" n = "<<n<<endl;
    for(int j=1; j<=min(n, 50); j++) 
		cout <<V[j]<<" ";
    cout<<endl<<endl;
}

long long int Selecao(int V[], int n){
    int i, m, j, t; long long int comp = 0;   
    for (i=1; i<= n-1; i++){
        m = i;
        for (j=i+1; j<=n; j++){
            if (V[j] < V[m]){
                m = j;   
            }
            comp = comp+1;
        }
        t = V[i];  V[i] = V[m];   V[m] = t;
    }
    return comp;
}

int main(){
    n=10;
    while(n <= 1000000){
	    cout<<endl<<"n = "<<n<<endl<<endl;
        for(int i=1; i<= n/2; i++) 
			V[i]=2*i;
        for(int i=1; i<= n/2; i++) 
			V[n/2+i]=2*i-1;
        Imprime("inicial", V, n);
        comp = Selecao(V, n);
        Imprime("final", V, n);
        cout<<"Total de comparacoes: "<<comp<<endl<<endl;
        n = n*10;
    }
    return 0;
}
