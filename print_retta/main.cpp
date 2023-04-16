/*
	Name: print-retta
	Copyright: 
	Author: Giuseppe Albamonte
	Date: 27/02/23 08:40
	Description: 
*/
#include <iostream>
using namespace std;

int main(){
	char pianoCartesiano[19][19];
	for (int i=0; i<19; i++){
		for(int j=0; j<19; j++){
			pianoCartesiano[i][j]='+';
		}
	}
	for(int i=-9; i<19; i++){
		pianoCartesiano[i+9][10]=(char)i+'0';
	}
	for (int i=-9; i<19; i++){
		pianoCartesiano[10][i+19]=(char)i+'0';
	}
	for (int i=0; i<19; i++){
		for(int j=0; j<19; j++){
			cout<<pianoCartesiano[i][j];
		}
		cout<<endl;
	}
}
