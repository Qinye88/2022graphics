///week14-1.cpp step01-1
///�m�߶}�ɡB�g��write�B����
#include <stdio.h>
int main ()
{
    FILE * fout = fopen("file.txt", "w+");

    printf("Hello World!!\n");///�p�µ���
    fprintf(fout,"Hello World\n");///�O�ƥ���r

    fclose(fout);
}

