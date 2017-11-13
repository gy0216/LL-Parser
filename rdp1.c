/*
	LRS(Language Recognition System)

	테스트 스트링 : "a,a,a,a,a$"

*/
/*
	Language Recognizer for the following CFG.

	G = ({A, B, C}, {a, ,}, P, S)
		P:  A -> CB
			B -> ,CB
			B -> ε
			C -> a
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

void pcomma()
{
	if (ch == ',')
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
	B --> ,CB
	B --> ε
*/
void pB()
{
	void pC();
	switch (ch) {
	case ',':
		pcomma(); pC(); pB();
		break;
	default:
		break;
	}
}

/*
	C --> a
*/
void pC()
{
	switch (ch) {
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
	puts("\tB --> ,A");
	puts("\tB --> ε");
	puts("\tC --> a");
	printf("$로 끝나는 입력스트링 : ");

	ch = getchar();
	pA();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}

