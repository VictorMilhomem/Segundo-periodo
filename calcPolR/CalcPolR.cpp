#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
const string  tchar = " +-*0123456789"; 
int j, n;  string E;

string GeraExpPolRev(int n){
    int i, nopn, nopr, tg;  string s = " ";
    nopn = 0;  nopr = 0;
    for (i=1; i<=n; i++){
        if (nopn == (n+1)/2)       tg = 1;
        else if (nopn <= (nopr+1)) tg = 2;
        else                       tg = rand()%2+1;
        if (tg == 1) {s = s + tchar[rand()%3+1];  nopr++;}
        else         {s = s + tchar[rand()%10+4]; nopn++;}   
    }
    cout<<"Expressao gerada ocupando as posicoes 1 a "<<s.length()-1<<" : "<<s<<endl;
	return s;  
}

int Resultado(int op1,int op2,char opr){
	if(opr == '+') return op1+op2;
	else if(opr == '-') return op1-op2;
	else if(opr == '*') return op1*op2;	
}

int CalcPolRev(string E){
	int i,topo, op1, op2, S[101];

    topo = 0;
    for (i = 1; i <= E.length()-1; i++)
    {
        int conv = E[i]-'0';
        if (conv >= 0 && conv <= 9 )
            S[++topo] = conv;
        else
        {
            op2 = S[topo--];
            op1 = S[topo--];
            S[++topo] = Resultado(op1, op2, E[i]);
        }
    }
    return S[1];

}

int main(){
    srand(time(NULL)); 
    while(true){
		n = 2*(rand()%10)+1;
        E = GeraExpPolRev(n);
		cout <<"Resultado: " << CalcPolRev(E) << endl;
		cin.get();
	}
	return 0;	
}




