#include <GL/freeglut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///push備份矩陣
        glTranslatef(x,y,0);///移動
        glColor3f(0,0,1);///藍色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///pop還原矩陣
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0,1,1);
    myTeapot(+0.5,+0.5);
    myTeapot(+0.5,-0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(-0.5,+0.5);
    glutSwapBuffers();///2被交換的buffer
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week04的移動練習視窗");///建視窗

    glutDisplayFunc( display );///畫圖函式

    glutMainLoop();///主要迴圈
    return 0;
}
