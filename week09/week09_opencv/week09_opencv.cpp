#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("earth.jpg");///Ū��
    cvShowImage("week09", img);///show ��
    cvWaitKey(0);
}
