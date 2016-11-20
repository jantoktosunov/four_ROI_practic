
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
using namespace cv;
using namespace std;

/*Вычислить и вывести 4 круглых ROI(Регион интереса)  у изображения т.е.
 * матрицу 1-го изоброжения умножить на матрицу 1-битного изрбражения с 4 белыми кругами(см. Лекцию №4)
 * 2-мя методами:
 * 1) Свой метод по пиксельно
 * 2) Готовой функцией OpenCV по умножению матриц. 1 изображение переведите сперва черно-белое 8-битное
 * */
void my_roi(Mat img, Mat mask,Mat output){//мой метод
    for (int y = 0; y < img.rows; y++){
        for (int x = 0; x < img.cols; x++){
            if(mask.at<uchar>(y,x)==255){
                output.at<uchar>(y,x)=img.at<uchar>(y,x);
            }
        }
    }
}
int main() {
    Mat img = imread("/home/tokjan/ClionProjects/four_ROI_practic/f4.jpeg",CV_8U);
    int rows = img.rows;
    int cols = img.cols;
    Mat mask(rows, cols, CV_8UC1, Scalar(0));
    Mat out(rows, cols, CV_8U, Scalar(0));
    Mat out2(rows, cols, CV_8U, Scalar(0));

    /* Нарисовал белые круги на Mat mask*/
    circle(mask, Point(163,110),40, Scalar(255,255,255),CV_FILLED, 8,0);
    circle(mask, Point(260,100),45, Scalar(255,255,255),CV_FILLED, 8,0);
    circle(mask, Point(373,133),45, Scalar(255,255,255),CV_FILLED, 8,0);
    circle(mask, Point(465,100),43, Scalar(255,255,255),CV_FILLED, 8,0);

    img.copyTo(out, mask);//готовый метод
    my_roi(img,mask,out2);//мой метод
    imshow("img",img);//изображение
    imshow("MASK",mask);//маска
    imshow("out",out);
    imshow("out2",out2);
   // imshow("mask",mask);
    waitKey(0);
    return 0;
}