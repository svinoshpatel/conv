#include "list.h"
#include <stdio.h>

char find(char value, char str[])
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (value == str[i])
			return value;
	}
	return '\0';
}

void infToPost(char str[], char operators[], char output[])
{
	int j = 0;
	Node *stack = NULL;
	for (int i = 0; str[i] != '\0'; i++) {
		char opr = find(str[i], operators);
		if (str[i] == ')') {
			output[j++] = stack->key[0];
			pop(stack);
		} else if (opr == '\0' && str[i] != '(') {
			output[j++] = str[i];
		} else if (opr != '\0') {
			push(stack, str[i], 0);
		}
	}
	while (stack != NULL) {
		output[j] = stack->key[0];
		j++;
		pop(stack);
	}
	output[j] = '\0';
}

// void infToPref(char str[], char operators[], char output[])
// {
// 	int j = 0;
// 	Node *stack = NULL;
// 	for (int i = 0; str[i] != '\0'; i++) {
// 		char opr = find(str[i], operators);
// 		if (str[i] == ')') {
// 			output[j++] = stack->key[0];
// 			pop(stack);
// 		} else if (opr == '\0' && str[i] != '(') {
// 			output[j++] = str[i];
// 		} else if (opr != '\0') {
// 			push(stack, str[i], 0);
// 		}
// 	}
// 	while (stack != NULL) {
// 		output[j++] = stack->key[0];
// 		pop(stack);
// 	}
// 	output[j] = '\0';
// }

void postToInf(char str[], char operators[], char output[])
{
	int j = 0;
	Node *stack = NULL;
	for (int i =0; str[i] != '\0'; i++) {
		char opr = find(str[i], operators);
		if (opr != '\0') {
			output[j+2] = stack->key[0];
			pop(stack);
			output[j] = stack->key[0];
			pop(stack);
			output[j+1] = opr;
			j += 3;
			push(stack, );
		} else {
			push(stack, str[i], 0);
		}
	}
}

void postToPref(char str[], char operators[], char output[])
{
}
