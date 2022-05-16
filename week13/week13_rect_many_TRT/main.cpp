#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
float angle[20];///�אּ�}�C
int angleID = 0 ;///0:��0�����`�A1:��1�����`�A2:��2�����`
float oldX=0;///��X�y��
void keyboard ( unsigned char key, int x, int y)
{
    if( key=='0' ) angleID=0;///�w�]�Ĥ@�� angle[0]
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
    glRectf(0.3, 0.5, -0.3, -0.2);///�|���Rectangle�A��զ⨭��
    glPushMatrix();
        glTranslatef(0.3, 0.5, 0);///���U�n����0.5,0.5
        glRotatef(angle[0], 0, 0, 1);///Z�b�A(2)����45��
        glTranslatef(-0.3, -0.4, 0);///(1)����त�ߩ�쥿����
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///�e���u

        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3)��U��y���b���`�W
            glRotatef(angle[1], 0, 0, 1);///(2)����
            glTranslatef(-0.8, -0.4, 0 );///(1)��U��y�����त�ߡA�񥿤���
            glColor3f(0,1,0);
            glRectf(0.8, 0.5, 1.1, 0.3);///�e�U��y
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3, 0.5, 0);///���U�n����0.5,0.5
        glRotatef(angle[2], 0, 0, 1);///Z�b�A(2)����45��
        glTranslatef(0.3, -0.4, 0);///(1)����त�ߩ�쥿����
        glColor3f(1, 0, 0);
        glRectf(-0.3, 0.5, -0.8, 0.3);///�e���u

        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3)��U��y���b���`�W
            glRotatef(angle[3], 0, 0, 1);///(2)����
            glTranslatef(0.8, -0.4, 0 );///(1)��U��y�����त�ߡA�񥿤���
            glColor3f(0,1,0);
            glRectf(-0.8, 0.5, -1.1, 0.3);///�e�U��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///2�Q�洫��buffer
}

int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week13_Rectangle");///�ص���

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc( display );///�e�Ϩ禡
    glutMainLoop();///�D�n�j��
}
