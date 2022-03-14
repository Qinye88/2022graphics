# 2022graphics
# week01
# week03
1.開啟git bash，將下載的檔案存到桌面，輸入:

```$ cd desktop```

2.輸入自己git hub網址:

```$ git clon https://github.com/Qinye88/2022graphics```

3.確認是否有下載
4.到老師的網站下載範例(https://jsyeh.org/3dcg10/ )下載win32，解壓縮至windows
5.開啟Shapes.exe，可按右鍵進行點、線與顏色等調整

```glBegin(GL_POLYGON); ///開始畫(ploygon為多邊形)```

```glVertex3f(x,y,z); ///頂點 Vertex```

```glColor3f(r,g,b); ///色彩 Color```

```glEnd(); ///結束畫```

6.開啟上週作業(需開啟副檔名為.cdp的檔案)，因教室電腦會初始化，需先將freeglut檔案從moodle下載解壓縮到桌面，並將:
C:\Users\Administrator\Desktop\freeglut\lib\libfreeglut.a 檔案名稱改為 libglut32.a
7.開啟code:blocks開啟上週作業，並新增(FileàNewàProject)GLUT專案，命名:week03_color(*詳細見week01-3)
8.開啟後將所有程式碼刪掉，輸入今天教學的程式碼，成功將出現黃色茶壺
```///將程式碼全刪掉
#include <GL/freeglut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);///顏色黃色
    glutSolidTeapot(0.3);///0.3 實心茶壺
  
    glutSwapBuffers();///2被交換的buffer
}
   
int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week03的視窗");///建視窗

    glutDisplayFunc( display );///畫圖函式
 
    glutMainLoop();///主要迴圈
    return 0;
}
```
9.開啟新檔(FileàNewàProject)，命名:week03_color_triangle，做彩色三角形
```///將程式碼全刪掉
#include <GL/freeglut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);///顏色黃色
            glBegin(GL_TRIANGLES);
                    glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                    glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                    glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
            glEnd();
    glutSwapBuffers();///2被交換的buffer
}
   
int main(int argc, char**argv)
{///進階的main函式
glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week03的視窗");///建視窗
    
    glutDisplayFunc( display );///畫圖函式

    glutMainLoop();///主要迴圈
    return 0;
}
```
10.上傳到git hub
