#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);///大茶壺
    glutSwapBuffers();
}
void motion(int x, int y)
{
    glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影
    glLoadIdentity();///原始矩陣
    gluLookAt((x-150)/150.0, (y-150)/150.0, 3,///eye
              0, 0, 0,///Center
              0, 1, 0);///Up
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///投影，把3D投射到2D畫面
    glLoadIdentity();///原始矩陣
    gluPerspective(60,ar,0.1,100);

    glMatrixMode(GL_MODELVIEW);///3D經過轉換到你最後的攝影機
    glLoadIdentity();///原始矩陣
    gluLookAt(0,0,3,///eye
              0,0,0,///center
              0,1,0);///up
}
int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week16_interpolation");///建視窗

    glutReshapeFunc(reshape);
    glutDisplayFunc( display );///畫圖函式
    glutMotionFunc(motion);

    glutMainLoop();///主要迴圈
}
