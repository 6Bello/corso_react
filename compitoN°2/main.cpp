/*
	Name: compito N°2
	Copyright: 
	Author: Giuseppe Albamonte
	Date: 24/02/23 15:20
	Description: Scrivere un programma in linguaggio C++ per
	determinare i punti di intersezione di una retta di
	equazione y=x+5 con y=7-x.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

float trovaN(string equazione);
bool trovaSegno(string equazione);
float trovaIntersezioneY(bool, float, float);
float trovaIntersezioneX(bool, float, float);

int main(){
	string equazione1, equazione2;
	cin>>equazione1;
	cout<<"\n";
	cin>>equazione2;
	bool segnoX1=trovaSegno(equazione1), segnoX2=trovaSegno(equazione2);
	if(segnoX1==segnoX2){
		cout<<"nessuna soluzione";
		return 0;
	}
	float nEquazione1=trovaN(equazione1), nEquazione2=trovaN(equazione2);
	float intersezioneY=trovaIntersezioneY(segnoX1, nEquazione1, nEquazione2);
	float intersezioneX=trovaIntersezioneX(segnoX1, intersezioneY, nEquazione1);
	cout<<"l'intersezione sull'asse y e' "<<intersezioneY;
	cout<<" e l'intersezione sull'asse x e' "<<intersezioneX;
}

float trovaN(string equazione){
	int nEquazione;
	if(equazione.substr(equazione.length()-1,1)!="x"){
		for(int i=equazione.length()-1; i>2; i--){						
			if(equazione.substr(i-1,1)=="x"){											
				stringstream ss;
				ss<<equazione.substr(i,equazione.length()+1-i);
				ss>>nEquazione;
			}
		}
	}else{
		for(int i=2; i<equazione.length()-1;i++){
			if(equazione.substr(i+2,1)=="x"||equazione.substr(i+2,1)=="X"){
				stringstream ss; 
				ss<<equazione.substr(2,i);
				ss>>nEquazione;
			}
		}
	}
	return nEquazione;
}

bool trovaSegno(string equazione){
	for(int i=0; i<equazione.length();i++){
		if(equazione.substr(i,1)=="x"||equazione.substr(i,1)=="X"){
			if(equazione.substr(i-1,1)=="-"){
				return 0;
			}else{
				return 1;
			}
		}
	}
}

float trovaIntersezioneY(bool segnoX1, float nEquazione1, float nEquazione2){
	float intersezioneY;
	if(!segnoX1){
		intersezioneY=nEquazione1-nEquazione2;
	}else{
		intersezioneY=nEquazione2-nEquazione1;
	}
	intersezioneY/=2;
	return intersezioneY;
}

float trovaIntersezioneX(bool segnoX1, float intersezioneY, float nEquazione1){
	float intersezioneX;
	if(segnoX1==0){
		intersezioneX=-intersezioneY+nEquazione1;
	}else{
		intersezioneX=intersezioneY+nEquazione1;
	}
	return intersezioneX;
}

