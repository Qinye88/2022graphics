#include <GL/glut.h>
float angle=0, angle_1=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);///白色
    glutSolidTeapot( 0.3 );///0.3大小實心大茶壺

    glPushMatrix();
        glTranslatef(0.3, 0, 0 );///把旋轉中的東西"掛在"某處
        glRotatef( angle, 0, 0, 1);///旋轉
        glTranslatef(0.2, 0, 0);///將茶壺旋轉中心，移到空間的中心(把茶壺把手移到中心)
        glColor3f(1, 0, 0);///紅色
        glutSolidTeapot( 0.2 );///0.2大小實心小茶壺

        glPushMatrix();
            glTranslatef(0.25, 0, 0 );///把旋轉中的東西"掛在"某處
            glRotatef( angle_1, 0, 0, 1);///旋轉
            glTranslatef(0.3, 0, 0);///將茶壺旋轉中心，移到空間的中心(把茶壺把手移到中心)
            glColor3f(1, 0, 0);///紅色
            glutSolidTeapot( 0.2 );///0.2大小實心小茶壺
        glPopMatrix();
        ///angle_1+=0.03;

    glPopMatrix();
    glutSwapBuffers();///2被交換的buffer
    angle+=0.03;
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
