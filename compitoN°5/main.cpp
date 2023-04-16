/*
	Name: Compito N°5
	Copyright: 
	Author: Giuseppe Albamonte con l'aiuto del professore Paolo Sabatini
	Date: 03/03/23 11:17
	Description: creare un tris
*/

#include <iostream>
using namespace std;
bool trisRiga(bool, int, int, int[3][3]);
bool trisColonna(bool, int, int, int[3][3]);
bool trisObliquo(bool, int, int, int[3][3]);
void disegnaMappa(int[3][3]);
int main(){
	int quadrati[3][3]={{2,2,2},{2,2,2},{2,2,2}}; 
	int giocati=0;
	bool player=0;
	cout<<"non scrivere duplicati"<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			disegnaMappa(quadrati);
			int riga, colonna;
			char lettera;

			do {
				cout<<"scrivi riga: ";
				cin>>riga;
				riga--;
				cout<<"scrivi colonna: ";
				cin>>lettera;
				cout<<endl;
				colonna=(int)lettera;
				colonna-=65;
			} while ( quadrati[riga][colonna]!=2 );

			quadrati[riga][colonna]=player;
			if(trisRiga(player, colonna, riga, quadrati)){
				disegnaMappa(quadrati);
				return 0;
			}else if(trisColonna(player, colonna, riga, quadrati)){
				disegnaMappa(quadrati);
				return 0;
			}else if(trisObliquo(player, colonna, riga, quadrati)){
				disegnaMappa(quadrati);
				return 0;
			}
			player=!player;	
		}
	}
	cout<<"patta";
	return 0;
}
void disegnaMappa(int quadrati[3][3]){
	cout<<"     A   B   C  "<<endl;
	for(int i=0; i<3;i++){
		cout<<" "<<i+1<<" ";
		for(int j=0; j<3; j++){
			char lettera;
			if(quadrati[i][j]==2){
				lettera=' ';
			}else if(quadrati[i][j]){
				lettera='X';
			}else{
				lettera='O';
			}
			cout<<"| "<<lettera<<" ";
		}
		cout<<"|"<<endl;
		cout<<"   -------------"<<endl;
	}	
}


	bool trisColonna(bool player, int lettera, int numero, int quadrati[3][3]){
	if(numero==0){
		if((quadrati[numero+1][lettera]==player)&&(quadrati[numero+2][lettera]==player)){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;
		}
	}else if(numero==1){
		if((quadrati[numero+1][lettera]==player)&&(quadrati[numero-1][lettera]==player)){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;	
		}
	}else{
		if((quadrati[numero-1][lettera]==player)&&(quadrati[numero-2][lettera]==player)){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;	
		}
	}
	return 0;
}
bool trisRiga (bool player, int lettera, int numero, int quadrati[3][3]){
	if(lettera==0){
		if((quadrati[numero][lettera+1]==player)&&(quadrati[numero][lettera+2]==player)){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;
		}
	}else if(lettera==1){
		if((quadrati[numero][lettera+1]==player)&&(quadrati[numero][lettera-1]==player)){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;	
		}
	}else{
		if((quadrati[numero][lettera-1]==player)&&(quadrati[numero][lettera-2]==player)){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;	
		}
	}
	return 0;
}

bool trisObliquo(bool player, int lettera, int numero, int quadrati[3][3]){
	if(quadrati[1][1]!=player || (lettera==1 || numero==1)){
		return 0;
	}else if(lettera==0){
		if(numero==0 && quadrati[2][2]==player){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;
		}else if(numero==2 && quadrati[0][2]==player){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;
		}
	}else{
		if(numero==0 && quadrati[2][0]==player){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;
		}else if(numero==2 && quadrati[0][0]==player){
			cout<<"player "<<player<<" ha vinto"<<endl;
			return 1;
		}
	}
	return 0;
}
