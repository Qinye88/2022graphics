 #include <GL/freeglut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);///�C�����
    glutSolidTeapot(0.3);///0.3 ��߯���

    glutSwapBuffers();///2�Q�洫��buffer
}

int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutCreateWindow("week03������");///�ص���

    glutDisplayFunc( display );///�e�Ϩ禡

    glutMainLoop();///�D�n�j��
    return 0;
}
