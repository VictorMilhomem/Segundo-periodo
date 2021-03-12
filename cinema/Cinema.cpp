#include<iostream>
#include <iomanip>
#include<time.h>
#include<stdlib.h>
using namespace std;

int M[1001][1001], Ma[1001][1001],
    n, nt, c, mini, x1, x2, y1, y2;

void Inicializa(){
    int i, j, x;
    for(i=1; i<=n; i++) for (j=1; j<=n; j++)
        if ((nt % 4) == 0) M[i][j] = 1;
        else M[i][j] = rand() % 2;
    //Gera acumulado
    for (i=0; i<=n; i++){ Ma[0][i]=0;   Ma[i][0]=0;}
    for (i=1; i<=n; i++){
        x=0;
        for (j=1; j<=n; j++){
            if (M[i][j]== 0) x++;
            Ma[i][j]=Ma[i-1][j]+x;
        }
    }
    //Imprime matriz gerada
    cout <<"Matriz gerada:" <<endl;
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++) cout <<setw(4)<<M[i][j];
        cout<<endl;
    }
    cout<<endl;
    //Imprime matriz acumulada}
    cout <<"Matriz acumulada:" <<endl;
    for (i=1; i<=n; i++){
        for (j=1; j<=n; j++) cout << setw(4) << Ma[i][j];
        cout<<endl;
    }
    cout<<endl;
}
void Algn4(){
    int i,j,p,q,t;
    mini = n*n+1;
    for (i=0; i<=n; i++)
        for (j=0; j<=n; j++)
          for (p=i; p<=n; p++)
            for (q=j; q<=n; q++){            
                t = Ma[p][q]-Ma[i-1][q]-Ma[p][j-1]+Ma[i-1][j-1];
                if ((t >= c) && (((p-i+1)*(q-j+1))< mini)){
                   mini = (p-i+1)*(q-j+1);
                   x1 = i, x2 = p , y1 = j , y2 = q;

                }
            }
    
}
int main(){
    srand(time(NULL));
    n = 1;  nt = 0;
    while (n > 0){
        nt++;
        cout << "Informe n e c (0 0 para acabar): "; cin >> n >> c;
        Inicializa();
        Algn4();
        cout <<"Algoritmo n4 -> min = " << mini <<endl;
        cout <<"Submatriz: " <<x1 <<" "<< y1 <<" "<< x2 <<" "<< y2 <<endl<<endl;
    }
    return 0;
}
