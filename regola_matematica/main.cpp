#include <iostream>

using namespace std;

int main(){
	unsigned long long int massimo = -1;
	cout<<massimo;
	for(unsigned long long int i=massimo; i>0; i--){
		unsigned long long int numero = i;
		while(numero!=1){
			if (numero%2==0){
				numero/=2;
			}else{
				numero=numero*3+1;
			}
			cout<<numero<<" ";
			if(numero==641126889442455230){
				cout<<"finito";
				system("pause");
			}
		}
	}	
}
