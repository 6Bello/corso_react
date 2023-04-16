/*
	Name: compito N3
	Copyright: 
	Author: giuseppe Albamonte
	Date: 25/02/23 13:06
	Description: Scrivere un programma in linguaggio C++ per
	determinare le soluzioni di una equazione di secondo
	grado ax2+bx+c=0.
	(Suggerimento: si tratta di stabilire i vari casi per il
	discriminante ed in funzione di esso determinare le
	soluzioni o meno).
*/
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

void trovaNumeriEquazioni(string formula, float (&numeri)[3]);
float trovaDelta(float (&numeri)[3]);
void soluzione(float delta, float (&numeri)[3]);

int main(){
	string formula;
	cout<<"scrivi un'equazione di secondo grado (senza usare frazioni o moltiplicazioni) in questo modo esempio:\n3x^2+11x+3=0\n";
	cin>>formula;
	float numeri[3];
	trovaNumeriEquazioni(formula, numeri);  
	float delta = trovaDelta(numeri);
	soluzione(delta, numeri);
	return 1;
}

void trovaNumeriEquazioni(string formula, float (&numeri)[3]){
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

float trovaDelta(float (&numeri)[3]){
	float delta=pow(numeri[1],2)-4*numeri[0]*numeri[2];
	return delta;
}

void soluzione(float delta, float (&numeri)[3]){
	if (delta<0){
		cout<<"non ci sono soluzioni!";
	}else if(delta==0){
		float risultato=(-numeri[1])/(2*numeri[0]);
		cout<<"il risultato e' "<<risultato;
	}else{
		float risultato1=(-numeri[1]-sqrt(delta))/(2*numeri[0]), risultato2=(-numeri[1]+sqrt(delta))/(2*numeri[0]);
		cout<<"il primo risultato e' "<<risultato1<<" ed il secondo e' "<<risultato2;
	}
}



