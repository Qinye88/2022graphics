#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
float angle=0;///�V���W����45��(X�b��0)
float oldX=0;///��X�y��
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
    glRectf(0.5, 0.5, -0.5, -0.5);///�|���Rectangle�A��զ⨭��
    glPushMatrix();
        glTranslatef(0.5, 0.5, 0);///���U�n����0.5,0.5
        glRotatef(angle, 0, 0, 1);///Z�b�A(2)����45��
        glTranslatef(-0.5, -0.4, 0);///(1)����त�ߩ�쥿����
        glColor3f(1, 0, 0);
        glRectf(0.5, 0.5, 1.0, 0.3);///�e���u
    glPopMatrix();
    glutSwapBuffers();///2�Q�洫��buffer
}

int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week13_Rectangle");///�ص���

    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc( display );///�e�Ϩ禡
    glutMainLoop();///�D�n�j��
}
