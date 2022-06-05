///week15-3 播放mp3
///mp3檔案小 vs. wav檔案大
///有壓縮/難     原始資料
#include "CMP3_MCI.h" ///下載，放同目錄
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("現在正在播放羊的聲音\n");
    int N;///直到N才結束
    scanf("%d", &N);
}
