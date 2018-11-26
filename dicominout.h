#ifndef DICOMINOUT_H
#define DICOMINOUT_H
// QT
#include <QString>
#include <QStringList>
#include <QDebug>
//VTK
#include <vtkImageData.h>
#include <vtkSmartPointer.h>
#include <vtkStringArray.h>
#include <vtkImageChangeInformation.h>
// DICOM -  GDCM
#include <vtkGDCMImageReader.h>
#include <gdcmIPPSorter.h>

class DICOMinout
{
public:
    DICOMinout();
    vtkImageData* getVolumeData();
    double* getBounds();
    void readImagesFrom(QStringList);
    void readImageFrom(QString);
    int hasData();

public:
    vtkSmartPointer<vtkGDCMImageReader> reader;
    vtkImageData *img;
    int hasReadVolumeCorrectly; // has read volume 0-No 1-Yes
    vtkSmartPointer<vtkStringArray> sortFilenames(QStringList, double &);
};

#endif // DICOMINOUT_H
