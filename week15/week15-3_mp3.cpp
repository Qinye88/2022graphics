///week15-3 ����mp3
///mp3�ɮפp vs. wav�ɮפj
///�����Y/��     ��l���
#include "CMP3_MCI.h" ///�U���A��P�ؿ�
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("�{�b���b����Ϫ��n��\n");
    int N;///����N�~����
    scanf("%d", &N);
}
