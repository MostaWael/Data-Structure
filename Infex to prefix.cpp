#include <iostream>
#include<stack>
#include <string>
using namespace std;

//Function to convert infex to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1,char operator2);

//Function to check if char is operator input or not
bool IsOperator(char ope);

//Function to check that the char is alphanumeric or not
bool IsOperand(char ope);
int main()
{
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << "\n";
	return 0;
}


string InfixToPostfix(string expression) {
	stack<char>S;
	string postfix="";
	for (int i = 0; i < expression.length(); i++) {
		//if character is delemeter move in
		if (expression[i] == ' ' || expression[i] == ',') {
			continue;
		}
		else if (IsOperator(expression[i])) {
			/*
				in the case of HasHigherPrecedence
				here is still pop elements in the stack until empty the stack
				and add it to postfix
			*/
			/*This expression work for expressions only*/
			while (!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(), expression[i]))
			{
				postfix += S.top();
				S.pop();
			};
		}
		else if(IsOperand(expression[i]))
		{
			postfix += expression[i];
		}
		else if (expression[i] == '(') {
			S.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while(!S.empty() && S.top()!='('){
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	return postfix;
}

//Function to verify whether a character is english letter on numeric digit
//we are do the function to asume that operand will be a single character

bool IsOperand(char C) {
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

//Function to check if is operator or not

bool IsOperator(char C) {
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$') {
		return true;
	}
	return false;
}

bool IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}
