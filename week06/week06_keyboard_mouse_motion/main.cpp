///�q�W�g�ƻs�{���X
#include <GL/freeglut.h>
#include <stdio.h>
float x=250, y=250, z=0, scale=1.0, angle=0.0, oldx, oldy;
int now=1;///1.���� 2.���� 3.�Y��
void display()
{
    glClearColor(0.5,0.5,0.5,1);///�Ψ�clear����m R,G,B,A�AA���z���סA�ݥt�~�}�Ҥ~�i�ϥ�
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///�ƥ��x�}
        glTranslatef( (x-250)/250.0 , -(y-250)/250.0 , z);///Maya:w
        glRotated(angle, 0, 0, 1);///Maya:e
        glScaled(scale, scale, scale);///Maya:r
        glColor3f(1,1,0);///�C�����
        glutSolidTeapot(0.3);///0.3 ��߯���
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();///2�Q�洫��buffer
}
void keyboard(unsigned char key, int mouseX, int mouseY)
{
    printf("�{�b���U:%c �y�Цb:%d %d\n", key, mouseX, mouseY);
    if(key=='w' || key=='W') now = 1;///����(���i�ϥΤ���)
    if(key=='e' || key=='E') now = 2;///����(���i�ϥΤ���)
    if(key=='r' || key=='R') now = 3;///�Y��(���i�ϥΤ���)
}
void mouse(int button, int state, int mouseX, int mouseY)
{
    oldx = mouseX; oldy = mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now == 1){///����
        x += (mouseX-oldx);
        y += (mouseY-oldy);
    }else if(now == 2){
        angle += (mouseX-oldx);
    }else if(now == 3){///�Y��
        if( mouseX > oldx ) scale = scale * 1.01;
        if( mouseX < oldx ) scale = scale * 0.99;
    }
    oldx = mouseX; oldy=mouseY;
    display();
}
int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutInitWindowSize(500,500);
    glutCreateWindow("week06 keyboard mouse motion");///�ص���

    glutDisplayFunc( display );///�e�Ϩ禡
    glutKeyboardFunc(keyboard);///��L�禡
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();///�D�n�j��
    return 0;
}
