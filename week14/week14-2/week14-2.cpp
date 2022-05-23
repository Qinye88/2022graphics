///week14-2.cpp step01-2
///練習開檔、寫檔write、關檔
///練習開檔、讀檔Read、關檔
#include <stdio.h>
int main ()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout,"angle1 %d\n", 999);///記事本文字
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line, &a);///&
    printf("讀到字串:%s 及整數%d\n", line, a);///小黑視窗
    fclose(fin);
}
