    #include "dataedit.h"

DataEdit::DataEdit()
{
}

void DataEdit::loadData(vtkImageData* imageData)
{
    m_img = imageData;
    int *dims = m_img->GetDimensions();
    //qDebug() << dims[0] ;
}
void DataEdit::gaussBlur(vtkImageData* img)
{
    vtkSmartPointer<vtkImageData> tmpImg = vtkSmartPointer<vtkImageData>::New();
    tmpImg->ShallowCopy(img);;
    vtkImageGaussianSmooth *gaussblur = vtkImageGaussianSmooth::New();
    //gaussblur->SetDimensionality(3);
    gaussblur->SetStandardDeviation(1.4, 1.4, 1.4);
    gaussblur->SetInput(tmpImg);

    m_img = gaussblur->GetOutput();

//    int *dims = m_img->GetDimensions();
//    qDebug() << "test  :  " << dims[0];
    return;
}

vtkImageData* DataEdit::getData()
{
    return (vtkImageData*)m_img;
}

void DataEdit::simpleThres(int thres, vtkImageData* img)
{
    int* dims = img->GetDimensions();
    //qDebug() << "Dimensions: " << dims[0];

    for (int z=0; z<dims[2]; z++)
    {
        for (int y=0; y<dims[1]; y++)
        {
            for (int x=0; x<dims[0]; x++)
            {
                // zero is the component, add another loop if you have more
                // than one component
                double v = img->GetScalarComponentAsDouble(x,y,z,0);
                // do something with v
                if (v>thres)
                {
                    img->SetScalarComponentFromDouble(x, y, z, 0, 120);
                }
                else
                {
                    img->SetScalarComponentFromDouble(x, y, z, 0, 400);
                }
            }
        }
    }

}

