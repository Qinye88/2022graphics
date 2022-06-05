///上周音檔寫法:#include <mmsystem.h>

#include <windows.h>///另一種寫法，結果一樣
int main()
{
    PlaySound("07042111.wav", NULL, SND_SYNC);
//    PlaySound("aaa.wav", NULL, SND_SYNC);
}
///compile成功，但是link設定失敗
///.c .cpp =compile=> .o =link=> .exe
