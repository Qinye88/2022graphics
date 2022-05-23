#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer (int t)
{   ///1000代表1秒，1500代表1.5秒
    printf("鬧鐘%d, 我起床了\n", t);///起床做事
    PlaySound("Ding-dong.wav", NULL, SND_ASYNC);///只能用wav檔
//    printf("設定下一個鬧鐘\n");
    printf("鈴聲響起~\n");
    glutTimerFunc(1000, timer, t+1);
//    printf("設好鬧鐘再回去睡\n");
}
void display(){ }
int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week13_Rectangle");///建視窗
    glutTimerFunc(3000, timer, 0);
    glutDisplayFunc( display );///畫圖函式
    glutMainLoop();///主要迴圈
}
