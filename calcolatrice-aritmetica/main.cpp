#include <iostream>
#include "functions/calculation.h"
#include "functions/reader.h"

using namespace std;

int readNum();
char readOperator();

int main(){
	int firstNum, secondNum, result;
	char operation;
	firstNum=readNum();
	operation=readOperator();
	secondNum=readNum();
	calculation(firstNum, operation, secondNum, result);
	cout<<firstNum<<operation<<secondNum<<"="<<result;
	
}



