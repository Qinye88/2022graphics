#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);///�j����
    glutSwapBuffers();
}
void motion(int x, int y)
{
    glMatrixMode(GL_MODELVIEW);///3D�g�L�ഫ��A�̫᪺��v
    glLoadIdentity();///��l�x�}
    gluLookAt((x-150)/150.0, (y-150)/150.0, 3,///eye
              0, 0, 0,///Center
              0, 1, 0);///Up
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    const float ar = (float) w / (float) h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);///��v�A��3D��g��2D�e��
    glLoadIdentity();///��l�x�}
    gluPerspective(60,ar,0.1,100);

    glMatrixMode(GL_MODELVIEW);///3D�g�L�ഫ��A�̫᪺��v��
    glLoadIdentity();///��l�x�}
    gluLookAt(0,0,3,///eye
              0,0,0,///center
              0,1,0);///up
}
int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutCreateWindow("week16_interpolation");///�ص���

    glutReshapeFunc(reshape);
    glutDisplayFunc( display );///�e�Ϩ禡
    glutMotionFunc(motion);

    glutMainLoop();///�D�n�j��
}
