/*
*   Program Created by Bryan S. Gomez. Copyright @ 2020
*   Creates a file full of binary values from Base 2 to Base 10
*/
#define BUFLEN 8
#define CHARBUFLEN 61

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * genbinfunc(size_t n, size_t base){
    static char buf[BUFLEN];
    int rem, i =  BUFLEN - 1;
    memset(buf, '0', sizeof(buf));
    while (n > 0){
        rem = n % base;
        n /= base;
        buf[i--] = rem + '0';
    }
    return buf;
}
int main(int argc, const char * argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: ./genbin fileout\n");
        exit(1);
    }
    FILE* fout = fopen(argv[1], "w");
    char charbuf[CHARBUFLEN];
    memset(charbuf, '-', sizeof(charbuf) - 1);
    for(int i = 2; i < 11; ++i){
        fprintf(fout, "\tBase %d %s\n", i, charbuf);
        for(int j = 0; j < 128; ++j){
            fprintf(fout, "%s ", genbinfunc(j, i));
            if (j % 8 == 7) {fprintf(fout, "\n"); }
        }
    }
    fclose(fout);
}
