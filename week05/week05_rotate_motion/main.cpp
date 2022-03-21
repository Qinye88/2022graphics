#include <GL/glut.h>
float angle=0, oldX = 0;///新增一角度浮點數和舊的X座標位置
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣
        glRotated(angle, 0, 0, 1);///轉180度
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}
///新增一滑鼠函式
void mouse (int button, int state, int x, int y)
{///按下mouse,放開mouse
    oldX = x;
}
///新增一動作函式
void motion(int x, int y)
{///拖曳
    angle += ( x - oldX );///newX-oldX=滑鼠移動(拖曳)量
    oldX = x;///新座標取代舊座標成為舊坐鏢
    display();
}
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新增滑鼠函式
    glutMotionFunc(motion);///新增動作函式
    glutMainLoop();
}
