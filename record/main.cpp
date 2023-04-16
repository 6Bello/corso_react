#include <iostream>
using namespace std;


int main(){
	struct utente{
		char nome[10], cognome[10];
		unsigned long int numero;
	};
	struct rubrica{
		utente;
	};
	utente giuseppe={"giuseppe", "albamonte", 3496969524};
	cout<<utente[0].nome<<"-"<<giuseppe.cognome<<"-"<<giuseppe.numero;
}
