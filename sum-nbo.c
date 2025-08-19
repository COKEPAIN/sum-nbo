#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char * argv[]) {
  FILE * fp = NULL;
  size_t red = 0;
  char buf[4] = {0};
  int * num = 0;

  for (; argc-1>0; argc--) {
    // printf("argc = %d!\n", argc);
    fp = fopen(argv[argc-1], "rb");
    if ( fp == NULL ) {
      // printf("fopen BAD!\n");
      break;
    } else {
      // printf("fopen GOOD!\n");
    }

    red = fread(buf, 1, 4, fp);
    if ( red > 0 ) {
      // printf("fread_s GOOD!\n");
      num = (int*)buf;
      uint32_t num1 = *num;
      // printf("%u\n", num1);
      uint32_t num2 = htonl(num1);
      printf("%d(0x%08x)", num1, num2);
    } else {
      // printf("fread_s BAD!\n");
    }
  }
}
