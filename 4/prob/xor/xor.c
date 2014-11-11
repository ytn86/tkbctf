#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char f1[] = {
  0xc2, 0xc8, 0xdf, 0xc5, 0xea, 0xc3, 0xf0, 
};

const char f2[] = {
  0xe5, 0xf0, 0xfe, 0xe0, 0xe3, 0xc8, 0xfe,
};

const char f3[] = {
  0xc0, 0xe5, 0xf6, 0xf5, 0xf4, 0xd0, 0xf6, 
};

const char f4[] = {
  0xf6, 0xfb, 0xed, 0xe6, 0xee, 0xab, 0xe9, 
};


void pfn_sleep(int flag)
{
  int i;
  if(flag == 1)
    printf("Now checking");
  
  for(i = 0; i < 3; i++){
    sleep(1);
    printf(".");
    fflush(stdout);
  }
  puts("");
}


void fail()
{
  pfn_sleep(1);
  printf("Failed. Try again!");
  exit(1);
}


void mes()
{	
  int i;
  int key = 0xa8;
  char res[128];
  
  char message[] = {
    0xeb, 0xc7, 0xc6, 0xcf, 0xda, 0xc9, 0xdc, 0xdb,
    0x89, 0x88, 0xfb, 0xc7, 0x88, 0xd1, 0xc7, 0xdd,
    0x88, 0xc0, 0xc9, 0xde, 0xcd, 0x88, 0xc9, 0xc4,
    0xda, 0xcd, 0xc9, 0xcc, 0xd1, 0x88, 0xcf, 0xc7,
    0xdc, 0xdc, 0xcd, 0xc6, 0x88, 0xce, 0xc4, 0xc9,
    0xcf, 0x86, 0x88, 0xee, 0xc1, 0xc6, 0xcc, 0x88,
    0xc1, 0xdc, 0x88, 0x92, 0x81, 0xa2, 0xa8,
  };
  for(i = 0; i < sizeof(message) / sizeof(char); i++)
    message[i] ^= key;
  
  puts(message);
}	

char game(int stg_num)
{
  char chr[32];
  int key = 0x90;
  int i, flag;
  /*
    switch(stg_num){
    case 1:
    *stg = *f1;
    break;
    case 2:
    *stg = *f2;
    break;
    case 3:
    *stg = *f3;
    break;
    case 4:
    *stg = *f4;
    break;
    default:
    printf("Hoge");
    break;
    }
  */
  printf("Stage ");
  printf("%d", stg_num);
  printf(" Input : ");
  scanf("%s", chr);
  key ^= stg_num;
  /*
   *chr ^= key;
   */
  for(i = 0 ; i < sizeof(chr) / sizeof(char); i++){
    chr[i] ^= key;
  }
  
  switch(stg_num){
  case 1:
    flag = strncmp(chr,f1, sizeof(f1) / sizeof(char));
    break;
  case 2:
    flag = strncmp(chr,f2, sizeof(f2) / sizeof(char));			
    break;
  case 3:
    flag = strncmp(chr,f3, sizeof(f3) / sizeof(char));
    break;
  case 4:
    flag = strncmp(chr,f4, sizeof(f4) / sizeof(char));
    break;
  }
  
  if(flag == 0){
    if(stg_num != 4){
      pfn_sleep(1);
      puts("congrats! Go to next stage.");
      sleep(1);
      puts("");
    } else if(stg_num == 4) {
      pfn_sleep(1);
      puts("");
      mes();
    }
  } else {
    fail();
  }
}


int main()
{
  char chr[32];
  printf("Welcome");
  fflush(stdout);
  pfn_sleep(0);
  puts("Get flag, start !");
  
  game(1);
  game(2);
  game(3);
  game(4);
  
  return 0;
}
