#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

struct utente {
	string name;
	string surname;
};

void print_users(vector<utente> users){
	for(int i=0; i<users.size();i++){
		cout<<users[i].name<<" "<<users[i].surname<<endl;
	}
}

void ordinamento(vector<utente>* array){
	bool tidy=0;
	while(!tidy){
		tidy=1;
		for(int i = 0; i<array->size()-1; i++){	
			for (int j=0;  j<(*array)[i].surname.length() && j<(*array)[i+1].surname.length(); j++){
				if (int((*array)[i].surname[j])>int((*array)[i+1].surname[j])){
					utente swap=(*array)[i];
					(*array)[i]=(*array)[i+1];
					(*array)[i+1]=swap;
					tidy=0;	
					break;				
				}else if(int((*array)[i].surname[j])==int((*array)[i+1].surname[j])){
					continue;
				}
				break;
			}
		}
	}

}

void assegnazioneUsers(vector<utente>* users){
	fstream utenti;
	utenti.open("utenti.txt", ios::in);
	string nome, cognome, nome_cognome;
	getline(utenti,nome_cognome);
	
	while(!utenti.eof()){
		bool assignedName=0;
		for(int i=0; i<nome_cognome.length(); i++){
			if(nome_cognome[i]==' '){
				nome=nome_cognome.substr(0, i);
				cognome=nome_cognome.substr(i+1, nome_cognome.length()+1);
				utente u = {nome, cognome};
				(*users).push_back(u);				
				break;
			}
		}getline(utenti, nome_cognome);
	}
	utenti.close();
}

int main(){
	string s;
	vector<utente> users;
	assegnazioneUsers(&users);
	ordinamento(&users);
	print_users(users);
	
	return 0;
}
