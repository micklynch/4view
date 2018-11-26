#ifndef DATAEDIT_H
#define DATAEDIT_H

//#include <qDebug.h>

#include <vtkImageData.h>
#include <vtkImageGaussianSmooth.h>
#include <vtkSmartPointer.h>

class DataEdit
{
public:
    DataEdit();
    void loadData(vtkImageData*);
    void gaussBlur(vtkImageData*);
    vtkImageData* getData();
    void simpleThres(int, vtkImageData*);

private:
    vtkImageData *m_img;
};

#endif // DATAEDIT_H
