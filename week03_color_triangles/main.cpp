///將程式碼全刪掉
#include <GL/freeglut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
            glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
        glEnd();
    glutSwapBuffers();///2被交換的buffer
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week03的彩色三角形視窗");///建視窗

    glutDisplayFunc( display );///畫圖函式

    glutMainLoop();///主要迴圈
    return 0;
}

