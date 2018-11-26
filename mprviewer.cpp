#include "mprviewer.h"
#include "ui_mprviewer.h"


MPRviewer::MPRviewer(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MPRviewer)
{
    ui->setupUi(this);

    // Create the widget to put in qmainwindow
    QVTKWidget *widget;
    widget = new QVTKWidget;
    setCentralWidget(widget); // place the widget centrally

    renWin = vtkRenderWindow::New();

    widget->SetRenderWindow(renWin);

    // add the render panels
    addRenderPanels();

    // test panel locations
    //testPanels();

    // Open DICOM Series
    mdicomreader = new DICOMinout();

    renWin->Render();
    return;
}

MPRviewer::~MPRviewer()
{    
    delete ui;
    renPanelvol->Delete();
    renPanelX->Delete();
    renPanelY->Delete();
    renPanelZ->Delete();

    renWin->Delete();
}

void MPRviewer::addRenderPanels()
{
    renPanelX = vtkRenderer::New();
    renPanelY = vtkRenderer::New();
    renPanelZ = vtkRenderer::New();
    renPanelvol = vtkRenderer::New();

    renPanelX->SetBackground(0.4,0.6,0.8);
    renPanelY->SetBackground(0.4,0.6,0.8);
    renPanelZ->SetBackground(0.4,0.6,0.8);
    renPanelvol->SetBackground(0.2, 0.2, 0.2);

    renPanelX->SetViewport(0.0, 0.0, 0.5, 0.5);
    renPanelY->SetViewport(0.0, 0.5, 0.5, 1.0);
    renPanelZ->SetViewport(0.5, 0.0, 1.0, 0.5);
    renPanelvol->SetViewport(0.5, 0.5, 1.0, 1.0);

    renWin->AddRenderer(renPanelX);
    renWin->AddRenderer(renPanelY);
    renWin->AddRenderer(renPanelZ);
    renWin->AddRenderer(renPanelvol);
    return;
}

void MPRviewer::addOrthognalImagesToPanes()
{    
    // Read this for implementing the orthogonal views
    // http://markmail.org/message/ylhqngrsqcz7cgss#query:vtkImageReslice%20vtkrenderer+page:1+mid:ylhqngrsqcz7cgss+state:results
    //************************************


    double spacing[3], origin[3];
    dicomdata->GetSpacing(spacing);
    dicomdata->GetOrigin(origin);
    vtkSmartPointer<vtkCellPicker> picker = vtkSmartPointer<vtkCellPicker>::New();
    myVtkCellPicked *pickerCmd = myVtkCellPicked::New();
    picker->SetTolerance(0.05);
    picker->AddObserver(vtkCommand::EndPickEvent, pickerCmd);

    vtkSmartPointer<vtkRenderWindowInteractor> axial_iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();


    {
    // Sagittal - bottom-right
    // sagittal transform
      vtkSmartPointer<vtkTransform> sagittal_transform = vtkSmartPointer<vtkTransform>::New();
      sagittal_transform->RotateX(0);
      sagittal_transform->RotateY(-90);
      sagittal_transform->RotateZ(180);
    // end sagittal transform

    // sagittal cut
      vtkSmartPointer<vtkImageReslice> sagittal_reslice = vtkSmartPointer<vtkImageReslice>::New();
      sagittal_reslice->SetInput(dicomdata);
      sagittal_reslice->SetResliceTransform(sagittal_transform);
      sagittal_reslice->InterpolateOn();      
    //end of sagittal cut

    // sagital cut to viewer
      vtkSmartPointer<vtkImageViewer> sagittal_viewer = vtkSmartPointer<vtkImageViewer>::New();
      sagittal_viewer->SetInput(sagittal_reslice->GetOutput());
      sagittal_viewer->SetZSlice(4);//x_dimension_volumen-1);


    // end sagital cut to viewer

    // assign actor to the sagittal renderer
      vtkSmartPointer<vtkActor2D> sagittal_actor = vtkSmartPointer<vtkActor2D>::New();
      sagittal_actor = sagittal_viewer->GetActor2D();
      sagittal_actor->SetPosition(20, 20);

      renPanelZ->AddActor2D(sagittal_actor);
    // end assign actor to the sagittal renderer
  }
      //************************************

      // axial
        // top-left in 4 view
      vtkSmartPointer<vtkTransform> axial_transform = vtkSmartPointer<vtkTransform>::New();
      axial_transform->RotateX(0);
      axial_transform->RotateY(0);
      axial_transform->RotateZ(0);      
      // end axial transform

    // axial cut
      vtkSmartPointer<vtkImageReslice> axial_reslice = vtkSmartPointer<vtkImageReslice>::New();
      axial_reslice->SetInput(dicomdata);      
      axial_reslice->InterpolateOn();
    //end of axial cut

    // axial cut to viewer
      vtkSmartPointer<vtkImageViewer> axial_viewer = vtkSmartPointer<vtkImageViewer>::New();
      axial_viewer->SetInput(axial_reslice->GetOutput());
      axial_viewer->SetZSlice(1);
      axial_iren->SetPicker(picker);
      axial_viewer->SetupInteractor(axial_iren);


    // end axial cut to viewer

      // start axial actor definition
      vtkSmartPointer<vtkActor2D> axial_actor = vtkSmartPointer<vtkActor2D>::New();
      axial_actor = axial_viewer->GetActor2D();
      axial_actor->SetPosition(20, 20); // offset actor postion
      // end axial actor definition


    // assign actor to the axial renderer
      renPanelY->AddActor(axial_actor);
    // end assign actor to the axial renderer


      {
    //************************************
     // coronal
     // bottom-left
      vtkSmartPointer<vtkTransform> coronal_transform = vtkSmartPointer<vtkTransform>::New();
      coronal_transform->RotateX(-90);
      coronal_transform->RotateY(180);
      //coronal_transform->RotateY(-90);
      coronal_transform->RotateZ(0);
    // end coronal transform

    // coronal cut
      vtkSmartPointer<vtkImageReslice> coronal_reslice = vtkSmartPointer<vtkImageReslice>::New();
      coronal_reslice->SetInput(dicomdata);      
      coronal_reslice->SetResliceTransform(coronal_transform);
      coronal_reslice->InterpolateOn();      
    //end of coronal cut

    // coronal cut to viewer
      vtkSmartPointer<vtkImageViewer> coronal_viewer = vtkSmartPointer<vtkImageViewer>::New();
      coronal_viewer->SetInput(coronal_reslice->GetOutput());
      coronal_viewer->SetZSlice(2);      
    // end coronal cut to viewer

    // assign actor to the coronal renderer
      vtkSmartPointer<vtkActor2D> coronal_actor = vtkSmartPointer<vtkActor2D>::New();
      coronal_actor = coronal_viewer->GetActor2D();
      coronal_actor->SetPosition(20, 20);

      renPanelX->AddActor2D(coronal_actor);
    // end assign actor to the coronal renderer
  }

    // Check http://www.vtk.org/pipermail/vtkusers/2006-August/086623.html

    return;
}

void MPRviewer::addVolumeImageToPane()
{
    // test
        double *origin = dicomdata->GetOrigin();
        qDebug() << "x: " << origin[0] << "y: " << origin[1] << "z: " << origin[2];
        // endtest

    vtkSmartPointer<vtkVolumeRayCastCompositeFunction> compositeFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New();
    vtkSmartPointer<vtkVolumeRayCastMapper> volumemap = vtkSmartPointer<vtkVolumeRayCastMapper>::New();

    volumemap->SetInput(dicomdata);
    volumemap->SetVolumeRayCastFunction(compositeFunction);

    vtkSmartPointer<vtkVolume> volume =vtkSmartPointer<vtkVolume>::New();
    volume->SetMapper(volumemap);

    volume->SetOrigin(origin);

    renPanelvol->AddVolume(volume);
    renPanelvol->ResetCamera();

    return;
}
/*
  Add images to all panels
  */
void MPRviewer::updatePanels()
{
    addOrthognalImagesToPanes();
    addVolumeImageToPane();
    return;
}

void MPRviewer::on_actionOpen_Series_triggered()
{
    // Open DICOM Series
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Choose files", "../testData/", "*.dcm", 0, 0);

    for (QStringList::Iterator it = filenames.begin(); it != filenames.end(); ++it)
    {
        QString str = *it;
        qDebug() << str.toStdString().c_str();
    }

    mdicomreader->readImagesFrom(filenames);
    dicomdata = mdicomreader->getVolumeData();

    updatePanels();
    return;
}

void MPRviewer::on_actionOpen_Files_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose file", "C:/temp/Data/testdata", "*.dcm", 0, 0);

    mdicomreader->readImageFrom(filename);
    dicomdata = mdicomreader->getVolumeData();

    updatePanels();

    return;
}
void MPRviewer::testPanels()
{
    // add numbers to render windows
    vtkTextSource *text[4];
    vtkPolyDataMapper *polyMapper[4];
    vtkActor *m_actor[4];
    QString *str = new QString();
    for (int i=0;i<=3;i++)
    {
        text[i] = vtkTextSource::New();
        polyMapper[i] = vtkPolyDataMapper::New();
        m_actor[i] = vtkActor::New();

        str->setNum(i);
        text[i]->SetText(str->toStdString().c_str());

        polyMapper[i]->SetInput(text[i]->GetOutput());
        m_actor[i]->SetMapper(polyMapper[i]);
    }
    renPanelX->AddActor(m_actor[0]);
    renPanelY->AddActor(m_actor[1]);
    renPanelZ->AddActor(m_actor[2]);
    renPanelvol->AddActor(m_actor[3]);

    delete str;

    for (int i=0;i<=3;i++)
    {
        polyMapper[i]->Delete();
        m_actor[i]->Delete();
    }
    return;
}

void MPRviewer::on_actionGaussian_Blur_triggered()
{
    DataEdit *mdataedit = new DataEdit();    
    //mdataedit->gaussBlur(dicomdata);
    //dicomdata = mdataedit->getData();
    mdataedit->simpleThres(160, dicomdata);
    updatePanels();

    delete mdataedit;
    return;
}

