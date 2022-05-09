#include <GL/glut.h>
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef( angle, 0, 0, 1);///旋轉
        glTranslatef(0.4, -0.07, 0);///將茶壺旋轉中心，移到空間的中心(把茶壺把手移到中心)
        glutSolidTeapot(0.3);///0.3 實心茶壺
    glPopMatrix();
    glutSwapBuffers();///2被交換的buffer
    angle+=0.1;
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week12_TRT");///建視窗

    glutIdleFunc(display);///電腦有空就畫
    glutDisplayFunc( display );///畫圖函式

    glutMainLoop();///主要迴圈
}
