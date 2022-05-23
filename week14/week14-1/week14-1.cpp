///week14-1.cpp step01-1
///練習開檔、寫檔write、關檔
#include <stdio.h>
int main ()
{
    FILE * fout = fopen("file.txt", "w+");

    printf("Hello World!!\n");///小黑視窗
    fprintf(fout,"Hello World\n");///記事本文字

    fclose(fout);
}

