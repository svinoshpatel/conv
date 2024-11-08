#include "list.h"
#include <cctype>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

char find(char value)
{
	char opr[] = "+-*^/";
	for (int i = 0; opr[i] != '\0'; i++) {
		if (value == opr[i])
			return value;
	}
	return '\0';
}

string infToPost(char str[])
{
	string output;
	Node *stack = NULL;
	for (int i = 0; str[i] != '\0'; i++) {
		char opr = find(str[i]);
		if (str[i] == ')') {
			output += stack->key;
			pop(stack);
		} else if (opr == '\0' && str[i] != '(') {
			output += str[i];
		} else if (opr != '\0') {
			push(stack, str[i]);
		}
	}
	while (stack != NULL) {
		output += stack->key;
		pop(stack);
	}
	return output;
}

// string infToPostD(char str[])
// {
// 	string output;
// 	bool one = false;
// 	Node *stack = NULL;
// 	for (int i = 0; str[i] != '\0'; i++) {
// 		char opr = find(str[i]);
// 		if (str[i] == ')') {
// 			if (!one)
// 				output += '|';
// 			output += stack->key;
// 			pop(stack);
// 			one = true;
// 		} else if (opr == '\0' && str[i] != '(') {
// 			output += str[i];
// 		} else if (opr != '\0') {
// 			output += '|';
// 			push(stack, str[i]);
// 		}
// 	}
// 	while (stack != NULL) {
// 		output += stack->key;
// 		pop(stack);
// 	}
// 	return output;
// }

string infToPref(char str[])
{
	string output;
	Node *stack = NULL;
	string infix(str);
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++) {
		if (infix[i] == '(')
			infix[i] = ')';
		else if (infix[i] == ')')
			infix[i] = '(';
	}
	for (int i = 0; infix[i] != '\0'; i++) {
		char opr = find(infix[i]);
		if (infix[i] == ')') {
			output += stack->key;
			pop(stack);
		} else if (opr == '\0' && infix[i] != '(') {
			output += infix[i];
		} else if (opr != '\0') {
			push(stack, infix[i]);
		}
	}
	while (stack != NULL) {
		output += stack->key;
		pop(stack);
	}
	reverse(output.begin(), output.end());
	return output;
}

string postToInfD(char str[])
{
	stack<string> stack;
	string operand;
	for (int i = 0; str[i] != '\0'; i++) {
		char opr = find(str[i]);
		if (opr != '\0') {
			string operand2 = stack.top();
			stack.pop();
			string operand1 = stack.top();
			stack.pop();
			string infix = "(" + operand1 + opr + operand2 + ")";
			stack.push(infix);
		} else if (isdigit(str[i])) {
			operand += str[i];
		}
		if (str[i] == '|') {
			stack.push(operand);
			operand = "";
		}
	}
	return stack.top();
}

string postToInf(char str[])
{
	stack<string> stack;
	string operand;
	for (int i = 0; str[i] != '\0'; i++) {
		char opr = find(str[i]);
		if (opr != '\0') {
			string operand2 = stack.top();
			stack.pop();
			string operand1 = stack.top();
			stack.pop();
			string infix = "(" + operand1 + opr + operand2 + ")";
			stack.push(infix);
		} else if (opr == '\0') {
			string c(1, str[i]);
			stack.push(c);
		}
	}
	return stack.top();
}

string prefToInf(char str[])
{
	stack<string> stack;
	string operand;
	string inf(str);
	for (int i = inf.length() - 1; i >= 0; i--) {
		char opr = find(inf[i]);
		if (opr != '\0') {
			string operand2 = stack.top();
			stack.pop();
			string operand1 = stack.top();
			stack.pop();
			string infix = "(" + operand1 + opr + operand2 + ")";
			stack.push(infix);
		} else if (opr == '\0') {
			string c(1, inf[i]);
			stack.push(c);
		}
	}
	string output = stack.top();
	reverse(output.begin(), output.end());

	for (int i = 0; i < output.length(); i++) {
		if (output[i] == '(')
			output[i] = ')';
		else if (output[i] == ')')
			output[i] = '(';
	}
	return output;
}

string prefToInfD(char str[])
{
	stack<string> stack;
	string operand;
	string inf(str);
	for (int i = inf.length() - 1; i >= 0; i--) {
		char opr = find(inf[i]);
		if (opr != '\0') {
			string operand2 = stack.top();
			stack.pop();
			string operand1 = stack.top();
			stack.pop();
			string infix = "(" + operand1 + opr + operand2 + ")";
			stack.push(infix);
		} else if (isdigit(inf[i])) {
			operand += inf[i];
		}
		if (inf[i] == '|') {
			stack.push(operand);
			operand = "";
		}
	}
	string output = stack.top();
	reverse(output.begin(), output.end());

	for (int i = 0; i < output.length(); i++) {
		if (output[i] == '(')
			output[i] = ')';
		else if (output[i] == ')')
			output[i] = '(';
	}
	return output;
}

