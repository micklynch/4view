#include "imageml.h"

#define ROWS 256
#define COLUMNS 256

struct PointXY
{
    int x;
    int y;
};

static unsigned char image[ROWS][COLUMNS];

ImageML::ImageML()
{
    for (int i=0;i<ROWS;i++)
        for (int j=0;j<COLUMNS;j++)
        {
            image[i][j] = i+j;
        }

    std::cout << "Image" << std::endl;
}

void ImageML::test()
{
    qDebug() << "test out" ;
}


