///week14-2.cpp step01-2
///�m�߶}�ɡB�g��write�B����
///�m�߶}�ɡBŪ��Read�B����
#include <stdio.h>
int main ()
{
    FILE * fout = fopen("file2.txt", "w+");
    fprintf(fout,"angle1 %d\n", 999);///�O�ƥ���r
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt", "r");
    fscanf(fin, "%s %d", line, &a);///&
    printf("Ū��r��:%s �ξ��%d\n", line, a);///�p�µ���
    fclose(fin);
}
