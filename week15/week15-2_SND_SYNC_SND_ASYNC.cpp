///week15-2 SND_SYNC要等待同步
///vs.
///SND_ASYNC 不用等待、不同步
#include <stdio.h>
#include <windows.h>///另一種寫法，結果一樣
int main()
{
    printf("現在在PlaySound()前\n");
    PlaySound("07042111.wav", NULL, SND_ASYNC);///SND_ASYNC不等待
    printf("現在在PlaySound()後\n");
    int N;
    scanf("%d", &N);
}
