///從上週複製程式碼
#include <GL/freeglut.h>
#include <stdio.h>
float x=250, y=250, z=0, scale=1.0, angle=0.0, oldx, oldy;
int now=1;///1.移動 2.旋轉 3.縮放
void display()
{
    glClearColor(0.5,0.5,0.5,1);///用來clear的色彩 R,G,B,A，A為透明度，需另外開啟才可使用
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///備份矩陣
        glTranslatef( (x-250)/250.0 , -(y-250)/250.0 , z);///Maya:w
        glRotated(angle, 0, 0, 1);///Maya:e
        glScaled(scale, scale, scale);///Maya:r
        glColor3f(1,1,0);///顏色黃色
        glutSolidTeapot(0.3);///0.3 實心茶壺
    glPopMatrix();///還原矩陣

    glutSwapBuffers();///2被交換的buffer
}
void keyboard(unsigned char key, int mouseX, int mouseY)
{
    printf("現在按下:%c 座標在:%d %d\n", key, mouseX, mouseY);
    if(key=='w' || key=='W') now = 1;///移動(不可使用中文)
    if(key=='e' || key=='E') now = 2;///旋轉(不可使用中文)
    if(key=='r' || key=='R') now = 3;///縮放(不可使用中文)
}
void mouse(int button, int state, int mouseX, int mouseY)
{
    oldx = mouseX; oldy = mouseY;
}
void motion(int mouseX, int mouseY)
{
    if(now == 1){///移動
        x += (mouseX-oldx);
        y += (mouseY-oldy);
    }else if(now == 2){
        angle += (mouseX-oldx);
    }else if(now == 3){///縮放
        if( mouseX > oldx ) scale = scale * 1.01;
        if( mouseX < oldx ) scale = scale * 0.99;
    }
    oldx = mouseX; oldy=mouseY;
    display();
}
int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutInitWindowSize(500,500);
    glutCreateWindow("week06 keyboard mouse motion");///建視窗

    glutDisplayFunc( display );///畫圖函式
    glutKeyboardFunc(keyboard);///鍵盤函式
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();///主要迴圈
    return 0;
}
