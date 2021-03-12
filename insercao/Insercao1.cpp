#include<iostream>
#include<time.h>
using namespace std;

int V[10000001], n; long long int comp;

void Imprime(string s, int V[], int n)
{   cout <<"Situacao "<<s<<" dos primeiros elementos:"<<" n = "<<n<<endl;
    for(int j=1; j<=min(n, 50); j++) 
		cout <<V[j]<<" ";
    cout<<endl<<endl;
}

long long int Insercao(int V[], int n){
    int i, j; long long int comp=0;

    for (i = 2; i<= n; i++){
        j = i;
        V[0] = V[i];

        while (V[j-1] > V[0]){
            V[j] = V[j-1];
            comp++;
            j--;
        }
        V[j] = V[0];
    }
    return comp;
}

int main(){
    n = 10;
    while(n <= 1000000){
	    cout<<endl<<endl<<"n = "<<n<<endl<<endl;
        for(int i=1; i<= n/2; i++) 
			V[i]=2*i;
        for(int i=1; i<= n/2; i++) 
			V[n/2+i]=2*i-1;
        Imprime("inicial", V, n);
        comp = Insercao(V, n);
        Imprime("final", V, n);
        cout<<"Total de comparacoes: "<<comp<<endl<<endl;
        n = 10* n;
    }
    return 0;
}
