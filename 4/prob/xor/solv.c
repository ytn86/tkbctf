#include <stdio.h>


char flag1[] = "SYNT{Ra";
char flag2[] = "wblrqZl";
char flag3[] = "SvefgCe";
char flag4[] = "boyrz?}";

void p_xor(char *chr, int add)
{

	int key = 0x90^add;
	int i;
	for(i = 0; i < sizeof(chr)/sizeof(char); i++){
		chr[i] ^= key;
	}

	puts(chr);
}

int main()
{


	p_xor(flag1, 1);
	p_xor(flag2, 2);
	p_xor(flag3, 3);
	p_xor(flag4, 4);
	
	return 0;
}