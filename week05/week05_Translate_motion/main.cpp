#include <GL/freeglut.h>
#include <stdio.h>///printf()
int mouseX=0, mouseY=0, N=0;///N為滑鼠的總點擊數
int mx[100],my[100];///陣列空間預設到100
///補充(3/21):最多可以有1000個頂點，陣列位置可設1000較保險
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);///黃色的
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){///迴圈+陣列
            glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
        }
    glEnd();
    glutSwapBuffers();///2被交換的buffer
}
///void mouse(int button,int state,int x,int y)
void motion (int x,int y)
{
    ///printf("%d %d %d %d\n",button,state,x,y);
    ///mouseX=x;    mouseY=y;
    ///if(state == GLUT_DOWN){
        N++;
        mx[N-1]=x;     my[N-1]=y;///陣列 備份座標
        printf("    glVertex2f((%d-150)/150.0,-(%d-150)/150.0);\n",x,y);
    ///}
}
int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week05_複習_mouse");///建視窗

    glutDisplayFunc( display );///畫圖函式
    ///glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();///主要迴圈
    return 0;
}
