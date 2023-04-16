#pragma once
void calculation(int a, char O, int b, int &result){
	switch(O){
		case '+':
			result = a+b;
			break;
		case '-':
			result= a-b;
			if(result<0){
				result=0;
			}
			break;
		case '*':
			result = a*b;
			break;
		case '/':
			result = a/b;
			break;
	}
}
