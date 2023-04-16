/*
	Name: CompitoN�4
	Copyright: 
	Author: Giuseppe Albamonte
	Date: 08/03/23 13:05
	Description: Ho il seguente problema da risolvere.
Trovare i punti di intersezione tra l'equazione di secondo grado y=5x^2-3x+4 con l'equazione y=5+x.
Trovare inoltre i punti di intersezione delle due equazioni suddette con gli assi x ed y.

*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void trovaNumeriEquazioniSecondo(string formula, float (&numeri)[3]);
void trovaNumeriEquazioniPrimo(string formula, float (&numero));

int main(){
	string equazioni[2];
	cin>>equazioni[0];
	stringstream ss;
	ss<<equazioni[0].substr(2, equazioni[0].length()-2);
	ss>>equazioni[0];
	equazioni[0]+="=0";
	cin>>equazioni[1];
	float numeri[3];
	float numero;
	trovaNumeriEquazioniSecondo(equazioni[0], numeri);
	trovaNumeriEquazioniPrimo(equazioni[1],numero);
	for(int i = 0; i<3; i++){
		cout<<numeri[i]<<endl;
	}
	cout<<numero;
}

void trovaNumeriEquazioniSecondo(string formula, float (&numeri)[3]){
	int posX=0;
	bool assignedC=0;
	for (int i=0; i<formula.length(); i++){
		string l=formula.substr(i,2);
		if(l=="x^" || l=="X^"){
			stringstream ss;
			ss<<formula.substr(posX,posX-i-1);
			ss>>numeri[0];
			posX = i+3;
		}else if(l=="x+" || l=="X+" || l=="x-" || l=="X-"){
			stringstream ss;
			ss<<formula.substr(posX,posX-i-1);
			ss>>numeri[1];
			posX = i+1;
		}else if((l=="0+"||l=="0+"||l=="0-"||l=="1-"||l=="2+"||l=="2-"||l=="3+"||l=="3-"||l=="4+"||l=="4-"||l=="5+"||l=="5-"||l=="6+"||l=="6-"||l=="7+"||l=="7-"||l=="8+"||l=="8-"||l=="9+"||l=="9-") && formula.substr(i-1,1)!="^"){
			stringstream ss;
			ss<<formula.substr(posX,posX-i);
			ss>>numeri[2];
			assignedC=1;
			posX = i+1;
		}else if((l=="=0"||l=="=0") && !assignedC){
			stringstream ss;
			ss<<formula.substr(posX,posX-i-1);
			ss>>numeri[2];
		}
	}
}

void trovaNumeriEquazioniPrimo(string formula, float (&numero)){
	for(int i = 0; i<formula.length(); i++){
		if(formula[i]=='='){
			i++;
			int j=1;
			while(formula[i+j]!='+' and formula[j+j]!='-'){
				j++;
			}
			stringstream ss;
			ss<<formula.substr(i,j);
			ss>>numero;
		}
	}
}





