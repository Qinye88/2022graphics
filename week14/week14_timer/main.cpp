#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer (int t)
{   ///1000�N��1��A1500�N��1.5��
    printf("�x��%d, �ڰ_�ɤF\n", t);///�_�ɰ���
    PlaySound("Ding-dong.wav", NULL, SND_ASYNC);///�u���wav��
//    printf("�]�w�U�@�Ӿx��\n");
    printf("�a�n�T�_~\n");
    glutTimerFunc(1000, timer, t+1);
//    printf("�]�n�x���A�^�h��\n");
}
void display(){ }
int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week13_Rectangle");///�ص���
    glutTimerFunc(3000, timer, 0);
    glutDisplayFunc( display );///�e�Ϩ禡
    glutMainLoop();///�D�n�j��
}
