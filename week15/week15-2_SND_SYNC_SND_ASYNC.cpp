///week15-2 SND_SYNC�n���ݦP�B
///vs.
///SND_ASYNC ���ε��ݡB���P�B
#include <stdio.h>
#include <windows.h>///�t�@�ؼg�k�A���G�@��
int main()
{
    printf("�{�b�bPlaySound()�e\n");
    PlaySound("07042111.wav", NULL, SND_ASYNC);///SND_ASYNC������
    printf("�{�b�bPlaySound()��\n");
    int N;
    scanf("%d", &N);
}
