#include <GL/freeglut.h>
void myTeapot(float x,float y)
{
    glPushMatrix();///push�ƥ��x�}
        glTranslatef(x,y,0);///����
        glColor3f(0,0,1);///�Ŧ�
        glutSolidTeapot(0.3);///����
    glPopMatrix();///pop�٭�x�}
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(0,1,1);
    myTeapot(+0.5,+0.5);
    myTeapot(+0.5,-0.5);
    myTeapot(-0.5,-0.5);
    myTeapot(-0.5,+0.5);
    glutSwapBuffers();///2�Q�洫��buffer
}

int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutCreateWindow("week04�����ʽm�ߵ���");///�ص���

    glutDisplayFunc( display );///�e�Ϩ禡

    glutMainLoop();///�D�n�j��
    return 0;
}
