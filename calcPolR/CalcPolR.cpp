/*Neste programa voc� vai trabalhar com o c�lculo de uma uma Express�o escrita
na nota��o Polonesa Reversa.
a) O programa gera uma express�o em nota��o polonesa reversa aleat�ria.
   Observe que o string gerado tem um branco na primeira posi��o, os operandos
   cont�m apenas 1 d�gito, os operadores s�o apenas +, - e * e n�o h�
   brancos no meio do string.
b) Para facilitar o algoritmo seguinte, j� foi criada a fun��o Resultado.
c) Voc� deve escrever a fun��o CalcPolRev, cujo algoritmo est� mostrado.
d) Uma dica para transformar o caracter s[i] no d�gito inteiro d � fazer
   d = s[i] - '0';
e) As fun��es esvazia pilha, Push() e POP() devem ser implementadas de forma muito
    simplificada. Isto �, n�o precisa criar fun��es para isso.
*/
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




