#pragma once
using namespace std;

int readNum(){
	int N;
	cout<<"numero dell'operazione: ";
	cin>>N;
	return N;
}

char readOperator(){
	char O;
	cout<<"operatore: ";
	cin>>O;
	if(O != '+' && O !='-' && O != '*' && O != '/'){
		cout<<"riscrivi l'operatore"<<endl;
		O=readOperator();
	}
	return O;
}

