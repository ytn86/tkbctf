#include <stdio.h>

int main()
{
	char flag[] = "Congrats! So you have already gotten flag. Find it :)\n";
	int i;
	int key = 0xa8;

	for(i = 0; i < sizeof(flag); i++){
		flag[i] ^= key;
	}
	puts(flag);


	for(i = 0; i < sizeof(flag); i++){
		flag[i] ^= key;
	}
	puts(flag);
	return 0;	
}