#ifndef MPRVIEWER_H
#define MPRVIEWER_H
// QT
#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QDebug>

// vtk
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkImageCast.h>
#include <vtkVolumeRayCastCompositeFunction.h>
#include <vtkSmartPointer.h>
#include <vtkImageReslice.h>
#include <vtkImageViewer.h>
#include <vtkTransform.h>
//vtk mappers
#include <vtkVolumeRayCastMapper.h>
#include <vtkPolyDataMapper.h>
#include <vtkImageMapper.h>
// vtk actor
#include <vtkVolume.h>
#include <vtkActor2D.h>
// vtk interactor
#include <vtkRenderWindowInteractor.h>
#include <vtkCellPicker.h>
#include <myvtkcellpicked.h>

//testing
#include <vtkTextSource.h>

#include "dicominout.h"
#include "dataedit.h"

namespace Ui
{
    class MPRviewer;
}

class MPRviewer : public QMainWindow
{
    Q_OBJECT

public:
    MPRviewer(QWidget *parent = 0);
    ~MPRviewer();

private: //functions
    void addOrthognalImagesToPanes();
    void addRenderPanels();
    void addVolumeImageToPane();
    void updatePanels();
    void testPanels();

private:    //members
    Ui::MPRviewer *ui;
    vtkRenderWindow *renWin;
    vtkRenderer *renPanelX;
    vtkRenderer *renPanelY;
    vtkRenderer *renPanelZ;
    vtkRenderer *renPanelvol;
    DICOMinout *mdicomreader;
    vtkImageData *dicomdata;

private slots:
    void on_actionGaussian_Blur_triggered();
    void on_actionOpen_Series_triggered();
    void on_actionOpen_Files_triggered();
};

#endif // MPRVIEWER_H
