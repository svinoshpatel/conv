#include "converter.h"
#include <stdio.h>


int main()
{
	char output[16];
	char input[16] = "((a+b)*(c+d)^x)";
	// char input[16] = "ab+cd+x^*";
	// char input[16] = "(144+25)";
	char operators[6] = {'+', '-', '*', '^', '/', '\0'};

	infToPost(input, operators, output);
	printf("%s", output);
}
