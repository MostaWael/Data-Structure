#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

bool arePairs(char open,char close) {
    if (open == '(' && close == ')') {
        return true;
    }
    else if (open == '[' && close == ']') {
        return true;
    }
    else if(open == '{' && close == '}')
    {
        return true;
    }
    return false;
}

bool areBalanced(string exp) {
    
    stack<char>bracs;

    for (size_t i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{') {
            bracs.push(exp[i]);
        }
        else if (exp[i] == ']' || exp[i] == ')' || exp[i] == '}'){ 
            //it means that the exp start with close bracet
            //arePairs check if the lastTopElement equal to the last element
            //which i will enter
            if (bracs.empty() || (!arePairs(bracs.top(),exp[i]))) {
                return false;
            }
            //it means that the stack already have open brackets 
            //so you can poped it when you found the close bracaet for it
            else {
                bracs.pop();
            }
            
        }
    }

    return bracs.empty();
}

int main()
{
    string exp;
    cout << "Enter An Expression for Check : "; cin >>exp;

    if (areBalanced(exp)) {
        cout << "yes are balanced";
    }
    else {
        cout << "No are not balancde\n\n";

    }
}
