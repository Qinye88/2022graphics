#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
float angle[20];///改為陣列
int angleID = 0 ;///0:第0個關節，1:第1個關節，2:第2個關節
float oldX=0;///舊X座標
void keyboard ( unsigned char key, int x, int y)
{
    if( key=='0' ) angleID=0;///預設第一個 angle[0]
    if( key=='1' ) angleID=1;///angle[1]
    if( key=='2' ) angleID=2;///angle[2]
    if( key=='3' ) angleID=3;///angle[3]
}
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}
void motion (int x, int y)
{
    angle[angleID] += (x-oldX);
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.2);///四邊形Rectangle，表白色身體
    glPushMatrix();
        glTranslatef(0.3, 0.5, 0);///等下要掛到0.5,0.5
        glRotatef(angle[0], 0, 0, 1);///Z軸，(2)旋轉45度
        glTranslatef(-0.3, -0.4, 0);///(1)把旋轉中心放到正中心
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///畫手臂

        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[1], 0, 0, 1);///(2)旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1)把下手肘的旋轉中心，放正中心
            glColor3f(0,1,0);
            glRectf(0.8, 0.5, 1.1, 0.3);///畫下手肘
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3, 0.5, 0);///等下要掛到0.5,0.5
        glRotatef(angle[2], 0, 0, 1);///Z軸，(2)旋轉45度
        glTranslatef(0.3, -0.4, 0);///(1)把旋轉中心放到正中心
        glColor3f(1, 0, 0);
        glRectf(-0.3, 0.5, -0.8, 0.3);///畫手臂

        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[3], 0, 0, 1);///(2)旋轉
            glTranslatef(0.8, -0.4, 0 );///(1)把下手肘的旋轉中心，放正中心
            glColor3f(0,1,0);
            glRectf(-0.8, 0.5, -1.1, 0.3);///畫下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///2被交換的buffer
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week13_Rectangle");///建視窗

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc( display );///畫圖函式
    glutMainLoop();///主要迴圈
}
