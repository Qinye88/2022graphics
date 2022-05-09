#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///讀入模型
GLMmodel * pmodel = NULL;///讀入模型的指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if( pmodel == NULL ){///程式放入
            pmodel = glmReadOBJ("data/Gundam.obj");///讀入模型
            glmUnitize( pmodel );///調整成單位大小(-1...~...+1之間)改變大小置中
            glmFacetNormals( pmodel );///把facet面的法向量Nnormals算出來
            glmVertexNormals( pmodel, 90 );///把Vertex的法向量，用面平均算出來，角度差90度
        }

    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel, GLM_MATERIAL |GLM_TEXTURE );///放上材質&開啟3D貼圖
    glPopMatrix();
    glutSwapBuffers();///2被交換的buffer
    angle+=1;
}
int main(int argc, char**argv)
{///進階的main函式
    glutInit( &argc, argv);///初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///兩倍交換避免畫面閃爍+3D深度
    glutCreateWindow("week11_gundam");///建視窗

    glutDisplayFunc( display );///畫圖函式
    glutIdleFunc(display);///有空就呼叫display，若沒加入則不會旋轉
    myTexture("data/Diffuse.jpg");///原為earth.jpg
    glEnable(GL_DEPTH_TEST);///開啟3D功能

    glutMainLoop();///主要迴圈
}
