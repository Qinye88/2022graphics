#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ��x�}
        glRotated(180, 0, 0, 1);///��180��
        glColor3f(1, 1, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 Rotate");

    glutDisplayFunc(display);
    glutMainLoop();
}
