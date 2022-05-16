#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
float angle=0;///向左上旋轉45度(X軸為0)
float oldX=0;///舊X座標
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion (int x, int y)
{
    angle += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.5, 0.5, -0.5, -0.5);///四邊形Rectangle，表白色身體
    glPushMatrix();
        glTranslatef(0.5, 0.5, 0);///等下要掛到0.5,0.5
        glRotatef(angle, 0, 0, 1);///Z軸，(2)旋轉45度
        glTranslatef(-0.5, -0.4, 0);///(1)把旋轉中心放到正中心
        glColor3f(1, 0, 0);
        glRectf(0.5, 0.5, 1.0, 0.3);///畫手臂
    glPopMatrix();
    glutSwapBuffers();///2被交換的buffer
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week13_Rectangle");///建視窗

    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc( display );///畫圖函式
    glutMainLoop();///主要迴圈
}
