# -------------------------------------------------
# Project created by QtCreator 2010-02-16T19:43:29
# -------------------------------------------------
TARGET = 4view
TEMPLATE = app
SOURCES += main.cpp \
    mprviewer.cpp \
    dicominout.cpp \
    dataedit.cpp \
    imageml.cpp \
    volumeml.cpp \
    volumetml.cpp
HEADERS += mprviewer.h \
    dicominout.h \
    dicominout.h \
    dataedit.h \
    imageml.h \
    volumeml.h \
    volumetml.h \
    myvtkcellpicked.h
FORMS += mprviewer.ui
win32:debug:LIBS += -Lc:/GDCM/lib
unix:debug:LIBS += -L/usr/local/lib/gdcm-2.0
win32:LIBS += -lvtkgdcm.dll \
    -lgdcmCommon.dll \
    -lgdcmDICT.dll \
    -lgdcmDSED.dll \
    -lgdcmexpat.dll \
    -lgdcmgetopt.dll \
    -lgdcmIOD.dll \
    -lgdcmjpeg12.dll \
    -lgdcmjpeg16.dll \
    -lgdcmjpeg8.dll \
    -lgdcmMSFF.dll \
    -lgdcmopenjpeg.dll \
    -lgdcmzlib.dll
unix:LIBS += -lvtkgdcm \
    -lgdcmCommon \
    -lgdcmDICT \
    -lgdcmDSED \
    -lgdcmIOD \
    -lgdcmjpeg12 \
    -lgdcmjpeg16 \
    -lgdcmjpeg8 \
    -lgdcmMSFF

unix:debug:LIBS += -L/usr/local/lib/vtk-5.4
win32:debug:LIBS += -Lc:/vtk/debug/lib/vtk-5.4
win32:release:LIBS += -Lc:/vtk/release/lib/vtk-5.4
win32:LIBS += -lvtkCommon.dll \
    -lvtkVolumeRendering.dll \
    -lvtksys.dll \
    -lQVTK.dll \
    -lvtkQtChart.dll \
    -lvtkViews.dll \
    -lvtkWidgets.dll \
    -lvtkInfovis.dll \
    -lvtkRendering.dll \
    -lvtkGraphics.dll \
    -lvtkImaging.dll \
    -lvtkIO.dll \
    -lvtkFiltering.dll \
    -lvtklibxml2.dll \
    -lvtkDICOMParser.dll \
    -lvtkpng.dll \
    -lvtkpng.dll \
    -lvtktiff.dll \
    -lvtkzlib.dll \
    -lvtkjpeg.dll \
    -lvtkalglib.dll \
    -lvtkexpat.dll \
    -lvtkverdict.dll \
    -lvtkmetaio.dll \
    -lvtkNetCDF.dll \
    -lvtkexoIIc.dll \
    -lvtkftgl.dll \
    -lvtkfreetype.dll \
    -lvtkHybrid.dll
unix:LIBS += -lvtkCommon \
    -lvtkVolumeRendering \
    -lvtksys \
    -lQVTK \
    -lvtkQtChart \
    -lvtkViews \
    -lvtkWidgets \
    -lvtkInfovis \
    -lvtkRendering \
    -lvtkGraphics \
    -lvtkImaging \
    -lvtkIO \
    -lvtkFiltering \
    -lvtklibxml2 \
    -lvtkDICOMParser \
    -lvtkpng \
    -lvtkpng \
    -lvtktiff \
    -lvtkzlib \
    -lvtkjpeg \
    -lvtkalglib \
    -lvtkexpat \
    -lvtkverdict \
    -lvtkmetaio \
    -lvtkNetCDF \
    -lvtkexoIIc \
    -lvtkftgl \
    -lvtkfreetype \
    -lvtkHybrid

unix:debug:INCLUDEPATH += /usr/local/include/vtk-5.4
unix:debug:INCLUDEPATH += /usr/local/include/gdcm-2.0
win32:debug:INCLUDEPATH += C:/vtk/debug/include/vtk-5.4
win32:debug:INCLUDEPATH += C:/gdcm/include/gdcm-2.0
win32:release:INCLUDEPATH += C:/vtk/release/include/vtk-5.4
OTHER_FILES += todo.txt
