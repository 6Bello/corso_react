/*
	Name: Compito N°1
	Copyright: 
	Author: Giuseppe Albamonte
	Date: 24/02/23 14:16
	Description: Scrivere un programma in linguaggio C++ per
	determinare i punti di intersezione di una retta di
	equazione y=x+5 con gli assi del piano x e y.
*/
#include <iostream>
#include <sstream>
#include <string>



using namespace std;

float trovaN(string);


int main(){
	cout<<"scrivi l'equazione:\n";
	string equazione;
	cin>>equazione;
	int n=trovaN(equazione);
	cout<<"il punto di intersezione con l'asse y e' "<<n<<" e l'intersezione con l'asse delle x e' "<<-n;	
}

float trovaN(string equazione){
		for(int i=0; i<equazione.length();i++){
		if(equazione.substr(i,2)=="x+" || equazione.substr(i,2)=="X+" || equazione.substr(i,2)=="x-" || equazione.substr(i,2)=="X-"){
			stringstream ss;
			ss<<equazione.substr(i+2, equazione.length()-i+2);
			ss>>n;
			return n;
		}
	}
}


