#include <GL/glut.h>
float angle=0, oldX = 0;///�s�W�@���ׯB�I�ƩM�ª�X�y�Ц�m
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotated(angle, 0, 0, 1);///��180��
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}
///�s�W�@�ƹ��禡
void mouse (int button, int state, int x, int y)
{///���Umouse,��}mouse
    oldX = x;
}
///�s�W�@�ʧ@�禡
void motion(int x, int y)
{///�즲
    angle += ( x - oldX );///newX-oldX=�ƹ�����(�즲)�q
    oldX = x;///�s�y�Ш��N�®y�Ц����§���
    display();
}
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///�s�W�ƹ��禡
    glutMotionFunc(motion);///�s�W�ʧ@�禡
    glutMainLoop();
}
