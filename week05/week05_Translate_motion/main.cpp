#include <GL/freeglut.h>
#include <stdio.h>///printf()
int mouseX=0, mouseY=0, N=0;///N���ƹ����`�I����
int mx[100],my[100];///�}�C�Ŷ��w�]��100
///�ɥR(3/21):�̦h�i�H��1000�ӳ��I�A�}�C��m�i�]1000���O�I
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///���⪺
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){///�j��+�}�C
            glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
        }
    glEnd();
    glutSwapBuffers();///2�Q�洫��buffer
}
///void mouse(int button,int state,int x,int y)
void motion (int x,int y)
{
    ///printf("%d %d %d %d\n",button,state,x,y);
    ///mouseX=x;    mouseY=y;
    ///if(state == GLUT_DOWN){
        N++;
        mx[N-1]=x;     my[N-1]=y;///�}�C �ƥ��y��
        printf("    glVertex2f((%d-150)/150.0,-(%d-150)/150.0);\n",x,y);
    ///}
}
int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutCreateWindow("week05_�Ʋ�_mouse");///�ص���

    glutDisplayFunc( display );///�e�Ϩ禡
    ///glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();///�D�n�j��
    return 0;
}
