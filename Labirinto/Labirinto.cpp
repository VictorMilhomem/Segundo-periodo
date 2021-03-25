#include <iostream>
#include <stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

int n, xi, yi, xf, yf, f, r, d, ff, tcm;
char L[101][101];
struct {int x,y,d,p;} Q[10000], CM[200];

void ImprimeL(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cout<<L[i][j];  cout<<endl;
    }

}

void Inicializa(){
    int i, j, k, l, p;
    memset(L, '.', sizeof(L));
    f=0;   r=0; 
    //Criação do labirinto
    for (i=1; i<=n; i++){
        L[1][i]=L[n][i]='X';  L[i][1]=L[i][n]='X';
    }
    //Criação de obstaculos
    for (k=1; k<=n/3-2; k++){
        l= 3*k+1;  i = rand()%(n/2-4)+ 3;
        if (k%2==0) 
		    for (p=i; p<=n; p++) {if (rand()%100 > 10) L[p][l]='X';  }
        else 
		    for (p=1; p<=i; p++) {if (rand()%100 > 10) L[p][l]='X';  }
    }
    xi= n/2; yi = rand()%(n-2)+2;  xf = rand()%(n-2)+2;  yf = n;
    L[xi][yi] = 'I';  L[xf][yf]='S';
    //Impressão inicial do labirinto
    ImprimeL();
}

void Enfila (int x1, int y1, int d1, int p1){
    if ((x1 >= 1) && (x1 <= n) && (y1 >= 1) && (y1 <= n) && (L[x1][y1] == 'I' || L[x1][y1] == '.'  || L[x1][y1]=='S')){
        if (L[x1][y1]=='S') 
			ff=r+1;
		L[x1][y1] = '-';
        Q[++r].x = x1;   Q[r].y = y1;   Q[r].d = d1;  Q[r].p = p1;
        if (f == 0)
			f = 1;
    }
}

void Desenfila(){
    if (f == r){
    	f = 0;  r = 0;
	}
    else f++;
}

void CaminhoMinimo(){
int i, j, xat, yat, dat, pat;
    Enfila(xi, yi,0,0);
    while (f != 0){
        xat = Q[f].x;  yat = Q[f].y;     dat = Q[f].d;   pat = Q[f].p;
        Enfila(xat-1, yat, dat+1, f);    
		Enfila(xat, yat-1, dat+1, f);
        Enfila(xat+1, yat, dat+1, f);    
		Enfila(xat, yat+1, dat+1, f);
        Desenfila();
    }
    tcm=0;  pat = ff;
    
    while(pat != 0){
		CM[++tcm] = Q[pat];
		//*****************Coloca * no caminho mínimo******************
        L[Q[pat].x][Q[pat].y] = '*';
		pat = Q[pat].p;  
    }
}
int main(){
	srand(time(NULL));
    while (true){
        cout<<"Dimensoes do labirinto:  n =";  cin >>n;  
    	Inicializa();
    	CaminhoMinimo();
		cout<<endl<<"Solucao do labirinto:"<<endl;
        //********************Imprime a solução**************************
        ImprimeL();
        cout<<endl<<"Tamanho do Caminho minimo:"<<tcm<<endl;
        //********************Imprime o tamanho do caminho mínimo********      
		cin.get();
    }
    return 0;
}
