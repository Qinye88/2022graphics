#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h" ///Ū�J�ҫ�
GLMmodel * pmodel = NULL;///Ū�J�ҫ�������
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if( pmodel == NULL ){///�{����J
            pmodel = glmReadOBJ("data/Gundam.obj");///Ū�J�ҫ�
            glmUnitize( pmodel );///�վ㦨���j�p(-1...~...+1����)���ܤj�p�m��
            glmFacetNormals( pmodel );///��facet�����k�V�qNnormals��X��
            glmVertexNormals( pmodel, 90 );///��Vertex���k�V�q�A�έ�������X�ӡA���׮t90��
        }

    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel, GLM_MATERIAL |GLM_TEXTURE );///��W����&�}��3D�K��
    glPopMatrix();
    glutSwapBuffers();///2�Q�洫��buffer
    angle+=1;
}
int main(int argc, char**argv)
{///�i����main�禡
    glutInit( &argc, argv);///��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);///�⭿�洫�קK�e���{�{+3D�`��
    glutCreateWindow("week11_gundam");///�ص���

    glutDisplayFunc( display );///�e�Ϩ禡
    glutIdleFunc(display);///���ŴN�I�sdisplay�A�Y�S�[�J�h���|����
    myTexture("data/Diffuse.jpg");///�쬰earth.jpg
    glEnable(GL_DEPTH_TEST);///�}��3D�\��

    glutMainLoop();///�D�n�j��
}
