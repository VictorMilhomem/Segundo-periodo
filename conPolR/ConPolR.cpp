#include<iostream>
#include<string.h>
#include <time.h>
#include<stdlib.h>
using namespace std;  
const char tchar[14][3] = {" ","+","-","*","0","1","2","3","4","5","6","7","8","9"}; 
int j, n;
string E, R;

string ConvPolRev(string E){
	int i, p, topo; char op, S[100]; string R = " ";

    topo = 0;
    p = 0;
    for (i = 1; i <= E.length()-1; i++)
    {
        int conv = E[i]-'0';
        if (conv >= 0 && conv <= 9)
            R = R + E[i];
        else if (E[i] != conv && E[i] != ')' && E[i] != '(')
            S[++topo] = E[i];

        else if (E[i] == ')')
        {
            char k = S[topo--];
            R = R + k;
        }
        
    }

    return R;	
}

string GeraExprTotPar(){
    int i, nopr,top, tg;  char pil[11][1000]; char s[1000];  string v=" "; 
    nopr = rand()%10 + 1; top = 0; tg = 0;
    for(i = 1; i <= nopr;i++){
        if((nopr-i+2) == top)       tg = 1;
        else if((nopr-i+1) == top)  tg = 2;
        else if(!top)               tg = 3;
        else if(top == 1)           tg = rand()%2+2;
        else                        tg = rand()%3+1;
        if(tg == 1){
            strcpy(s,"("); strcat(s,pil[top-1]); strcat(s,tchar[rand()%3+1]);
            strcat(s,pil[top]); strcat(s,")");
            top--; strcpy(pil[top],s);    
        }
        else if(tg == 2){
            strcpy(s,"("); strcat(s,tchar[rand()%10+4]);  strcat(s,tchar[rand()%3+1]); strcat(s,pil[top]);
            strcat(s,")");
            strcpy(pil[top],s);       
        }
        else{
            strcpy(s,"("); strcat(s,tchar[rand()%10+4]);  
			strcat(s,tchar[rand()%3+1]); strcat(s,tchar[rand()%10+4]);
            strcat(s,")");
            strcpy(pil[++top],s);     
        }    
    }
    n = 4*nopr+1;
    for (i=1; i<=n; i++) v = v + pil[1][i-1];
    return v;
}

int main(){
    srand ( time(NULL) );
    while(true){
        E = GeraExprTotPar();
        cout <<"Expressao inicial: "<<E<<endl;
        R = ConvPolRev(E);     
        cout <<"Expressao convertida: "<<R<<endl;
        cin.get();
    }
    return 0;
}




