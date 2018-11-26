#include "dicominout.h"

DICOMinout::DICOMinout()
{
    reader = vtkSmartPointer<vtkGDCMImageReader>::New();    
    hasReadVolumeCorrectly = 0;
}


vtkImageData* DICOMinout::getVolumeData()
{
    if (hasReadVolumeCorrectly)
    {
        //return reader->GetOutput();
        return img;
    }
    else
        return NULL;
}

double* DICOMinout::getBounds()
{    
    return reader->GetOutput()->GetBounds();
}

void DICOMinout::readImageFrom(QString filename)
{    
    reader->SetFileName(filename.toStdString().c_str());

    reader->Update();
    if (reader->GetFileDimensionality() >0)
        hasReadVolumeCorrectly = 1;

    return;
}

void DICOMinout::readImagesFrom(QStringList filenames)
{
    double spacing[3];
    double zspacing;

    // read and sort dicom files
    vtkSmartPointer<vtkStringArray> strArray = sortFilenames(filenames, zspacing);

    reader->SetFileNames(strArray);
    reader->Update();
    if (reader->GetFileDimensionality() >0){
        hasReadVolumeCorrectly = 1;
    }
    reader->GetOutput()->GetSpacing(spacing);
    spacing[2] = zspacing;
    qDebug() << "Spacing:" << "x: "<<spacing[0] << "y: "<<spacing[1] << "z: "<<spacing[2];

    // change the image information with the zSpacing found by IPPSorter
    vtkImageChangeInformation *v16 = vtkImageChangeInformation::New();
    v16->SetInput(reader->GetOutput());
    v16->SetOutputSpacing(spacing);
    v16->Update();

    img = v16->GetOutput();
    return;
}

vtkSmartPointer<vtkStringArray> DICOMinout::sortFilenames(QStringList filenames, double &zSpacing)
{
    vtkSmartPointer<vtkStringArray> vtkstrArray = vtkSmartPointer<vtkStringArray>::New();
    // Add the filenames from QStringList into a standard vector
    std::vector<std::string> strfnames;
    for (QStringList::Iterator it = filenames.begin(); it != filenames.end(); ++it)
    {
        QString str = *it;        
        strfnames.push_back(str.toStdString());
    }

    // GDCM sorter will arrange the filenames based on coordinates and time
    gdcm::IPPSorter s;
    s.SetComputeZSpacing(true);
    s.SetZSpacingTolerance( 1e-2 );
    bool b = s.Sort(strfnames);
    s.SetComputeZSpacing(true);

    zSpacing = s.GetZSpacing();

    if( b )
    {
        //qDebug() << "Sorting succeeded:" << s.GetZSpacing();

        const std::vector<std::string> & sorted = s.GetFilenames();
        std::vector<std::string>::const_iterator cii;
        for(cii=sorted.begin(); cii!=sorted.end(); cii++)
        {
            std::string str = *cii;
            vtkstrArray->InsertNextValue(str);
        }
    }
    else
    {
        qDebug() << "Failed to sort...ppft" ;
        std::cerr << "Default to unsorted volume:" << std::endl; 
        for (QStringList::Iterator it = filenames.begin(); it != filenames.end(); ++it)
        {
            QString str = *it;
            vtkstrArray->InsertNextValue(str.toStdString());
        }
    }

    return vtkstrArray;
}

int DICOMinout::hasData()
{
    return hasReadVolumeCorrectly;
}
