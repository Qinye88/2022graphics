#include <GL/glut.h>
#include <stdio.h>///為了引用printf、fprintf、fopen、fclose...
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * bot = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;

float angle[20];///改為陣列
float oldX=0;///舊X座標
int angleID = 0 ;///0:第0個關節，1:第1個關節，2:第2個關節
FILE * fout = NULL, * fin = NULL;///指標
void myWrite()
{
    if(fin!=NULL){
        fclose(fin);
        fin=NULL;
        ///加messagebox
    }
    if(fout==NULL){
       fout = fopen("file.txt", "w+");///如果是空指標則會產生一檔案
    }
    for(int i=0; i<20; i++)
    {
        printf(      "%.2f",angle[i]);
        fprintf(fout, "%.2f ",angle[i] );///%.2f:小數點下兩位的float
    }
    printf("\n");
    fprintf(fout, "\n");
    ///少了fclose,因為不想只印一行就結束
}
void myRead()
{
    if(fout!=NULL)
    {
        fclose(fout);///還在讀的檔案要關掉
        fout=NULL;
    }
    if(fin == NULL)
        fin = fopen("file.txt","r");
    for(int i=0; i<20; i++)
    {
        fscanf(fin, "%f", &angle[i] );
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard ( unsigned char key, int x, int y)
{
    if( key=='r' ) myRead();///按一下執行一行write紀錄的座標
    if( key=='s' ) myWrite();///save
    if( key=='0' ) angleID=0;///預設第一個 angle[0]
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
    ///myWrite();///不必一直寫檔
    oldX = x;
    glutPostRedisplay();
}

GLMmodel * myReadOne(char * filename)///讀進一個檔案
{
    GLMmodel * one = NULL;
    if(one==NULL){
        one = glmReadOBJ(filename);
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}

void display()///最新的display
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(head==NULL) head=myReadOne("data/head.obj");
//    if(body==NULL) body=myReadOne("data/body.obj");
    glmDraw(head, GLM_SMOOTH);
    glutSwapBuffers();
}
void displayNotParts()///week11的鋼彈
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( pmodel == NULL ){
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_SMOOTH);
    glutSwapBuffers();
}
void displayOld()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.2);///四邊形Rectangle，表白色身體
    glPushMatrix();
        glTranslatef(0.3, 0.5, 0);///等下要掛到0.5,0.5
        glRotatef(angle[0], 0, 0, 1);///Z軸，(2)旋轉45度
        glTranslatef(-0.3, -0.4, 0);///(1)把旋轉中心放到正中心
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///畫手臂

        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[1], 0, 0, 1);///(2)旋轉
            glTranslatef(-0.8, -0.4, 0 );///(1)把下手肘的旋轉中心，放正中心
            glColor3f(0,1,0);
            glRectf(0.8, 0.5, 1.1, 0.3);///畫下手肘
            glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3, 0.5, 0);///等下要掛到0.5,0.5
        glRotatef(angle[2], 0, 0, 1);///Z軸，(2)旋轉45度
        glTranslatef(0.3, -0.4, 0);///(1)把旋轉中心放到正中心
        glColor3f(1, 0, 0);
        glRectf(-0.3, 0.5, -0.8, 0.3);///畫手臂

        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3)把下手肘掛在關節上
            glRotatef(angle[3], 0, 0, 1);///(2)旋轉
            glTranslatef(0.8, -0.4, 0 );///(1)把下手肘的旋轉中心，放正中心
            glColor3f(0,1,0);
            glRectf(-0.8, 0.5, -1.1, 0.3);///畫下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///2被交換的buffer
}

int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
//    glutInitWindowSize(600, 600);
    glutCreateWindow("week15_gundam");///建視窗

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc(display);///畫圖函式
    glutMainLoop();///主要迴圈
}
