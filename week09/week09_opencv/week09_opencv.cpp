#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("earth.jpg");///Åª¹Ï
    cvShowImage("week09", img);///show ¹Ï
    cvWaitKey(0);
}
