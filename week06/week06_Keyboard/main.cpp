///�q�W�g�ƻs�{���X
#include <GL/freeglut.h>
#include <stdio.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);///�C�����
        glutSolidTeapot(0.3);///0.3 ��߯���
    glutSwapBuffers();///2�Q�洫��buffer
}
void keyboard(unsigned char key, int x, int y)
{
    printf("�{�b���U:%c �y�Цb:%d %d\n", key,x,y);
}

int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutCreateWindow("week03������");///�ص���

    glutDisplayFunc( display );///�e�Ϩ禡
    glutKeyboardFunc(keyboard);///��L�禡

    glutMainLoop();///�D�n�j��
    return 0;
}
