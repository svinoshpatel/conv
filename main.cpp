#include "converter.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char infp[] = "(a+(b^c))";
	char infpd[] = "(144+(25^45)+(25/40))";
	char postp[] = "abc^+";
	char postpd[] = "144|25|45|^+";
	char prefi[] = "+a^bc";
	char prefid[] = "+|25^|43|56";
	// char input[16] = "(144+25)";

	string infpost = infToPost(infp);
	string infpref = infToPref(infp);
	// string infpostd = infToPostD(infpd);
	string postinf = postToInf(postp);
	string postinfd = postToInfD(postpd);
	string prefinf = prefToInf(prefi);
	string prefinfd = prefToInfD(prefid);
	
	cout << "Infix to Postfix: "<< infpost << endl;
	cout << "Infix to Prefix: " << infpref << endl;
	// cout << infpostd << endl;
	cout << "Postfix to Infix: " << postinf << endl;
	cout << "Numeric Postfix to Infix" << postinfd << endl;
	cout << "Prefix to Infix: " << prefinf << endl;
	cout << "Numeric Prefix to Infix: " << prefinfd << endl;
}
