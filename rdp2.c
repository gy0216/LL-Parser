/*
	LRS(Language Recognition System)

	테스트 스트링 : "a+(a+a*(a+a))*a+(a)$"

*/
/*
	Language Recognizer for the following CFG.

	G = ({A, B, C, D, E}, {a, +, *, (, )}, P, S)
		P: A -> CB
			B -> +CB
			B -> ε
			C -> ED
			D -> *ED
			D ->  ε
			E -> (A)
			E -> a
*/

#include <stdio.h>

char ch;
int errflag = 0;

/*
	Recognition-failed message.
*/
void error()
{
	if (!errflag) {
		puts("FAIL");
		errflag = 1;
	}
}

void pa()
{
	if (ch == 'a')
		ch = getchar();
	else error();
}

void pplus()
{
	if (ch == '+')
		ch = getchar();
	else error();
}

void pmulti()
{
	if (ch == '*')
		ch = getchar();
	else error();
}

void pleft()
{
	if (ch == '(')
		ch = getchar();
	else error();
}

void pright()
{
	if (ch == ')')
		ch = getchar();
	else error();
}

/*
	A --> CB
*/
void pA()
{
	void pC();
	void pB();

	pC(); pB();
}

/*
	B --> +CB
	B --> ε
*/
void pB()
{
	void pC();

	switch (ch) {
	case '+':
		pplus(); pC(); pB();
		break;
	default:
		break;
	}
}

/*
	C --> ED
*/

void pC()
{
	void pE();
	void pD();

	pE(); pD();
}

/*
	D --> *ED
	D --> ε
*/

void pD()
{
	void pE();

	switch (ch) {
	case '*':
		pmulti(); pE(); pD();
		break;
	default:
		break;
	}
}

/*
	E --> (A)
	E --> a
*/

void pE()
{
	switch (ch) {
	case '(':
		pleft(); pA(); pright();
		break;
	case 'a':
		pa();
		break;
	default:
		error();
	}
}


void main()
{
	puts("Production Rules:");
	puts("\tA --> CB");
	puts("\tB --> +CB");
	puts("\tB --> ε");
	puts("\tC --> ED");
	puts("\tD --> *ED");
	puts("\tD --> ε");
	puts("\tE --> (A)");
	puts("\tE --> a");
	printf("$로 끝나는 입력스트링 : ");

	ch = getchar();
	pA();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}

