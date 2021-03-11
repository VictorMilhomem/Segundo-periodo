/* Neste programa voc� vai trabalhar com a opera��o de Merge em dois vetores j�
   ordenados, representando dois conjuntos. Voc� deve obter V3 = V1-V2, ou seja,
   o conjunto diferen�a entre V1 e V2. A gera��o e a impress�o dos dados j� est�o
   programados. O valor m�ximo da entrada � 1000.
   b) Implemente a opera��o de diferen�a.
   c) Acerte a "pegadinha" na impress�o de V3.
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int V1[1001],V2[1001],V3[1001], i, n, m, k;

int Difer(int V1[], int n, int V2[], int m, int V3[]){
	int i, j, k;

    i=1, j = 1, k = 0;
    while(i <= n && j <= m)
    {
        if(V1[i] < V2[j])
        {
            k++;
            V3[k] = V1[i];
            i++;
        }
        else if(V1[i] == V2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    while(i <= n)
    {
        k++;
        V3[k] = V1[i];
        i++;
    }
    return k;
}

void Imprime(string mens, int V[], int t){
   int i;
    cout<<mens;
    for(i = 1; i<=t; i++)
		cout<<V[i]<<" "; 
	cout<<endl<<endl;
}

int main(){
    srand(time(NULL));
    n = 8;  m = 16;
    while (m < 1000){
        cout<<endl<<endl<<"n, m = "<<n<<" "<<m<<endl<<endl;
    	V1[1] = rand()%10;  
		for(i = 1; i <= n; i++) 
			V1[i] = V1[i-1]+rand()%4+1;
    	V2[1] = rand()%10;  
		for(i = 1; i <= m; i++) V2[i] = V2[i-1]+rand()%4+1;
        Imprime("V1: ", V1, n);  
		Imprime("V2: ", V2, m);
        k = Difer(V1, n, V2, m,  V3);
        Imprime("V3: ", V3, k);
        n = n*2; m = m*2;
    }
    return 0;
}
