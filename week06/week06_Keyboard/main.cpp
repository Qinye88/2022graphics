///從上週複製程式碼
#include <GL/freeglut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);///顏色黃色
        glutSolidTeapot(0.3);///0.3 實心茶壺
    glutSwapBuffers();///2被交換的buffer
}
void keyboard(unsigned char key, int x, int y)
{
    printf("現在按下:%c 座標在:%d %d\n", key,x,y);
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///畫圖函式
    glutKeyboardFunc(keyboard);///鍵盤函式

    glutMainLoop();///主要迴圈
    return 0;
}
