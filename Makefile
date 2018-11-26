#############################################################################
# Makefile for building: 4view
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Nov 23 18:17:18 2012
# Project:  4view.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile 4view.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/usr/local/include/vtk-5.4 -I/usr/local/include/gdcm-2.0 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib/gdcm-2.0 -lvtkgdcm -lgdcmCommon -lgdcmDICT -lgdcmDSED -lgdcmIOD -lgdcmjpeg12 -lgdcmjpeg16 -lgdcmjpeg8 -lgdcmMSFF -L/usr/local/lib/vtk-5.4 -lvtkCommon -lvtkVolumeRendering -lvtksys -lQVTK -lvtkQtChart -lvtkViews -lvtkWidgets -lvtkInfovis -lvtkRendering -lvtkGraphics -lvtkImaging -lvtkIO -lvtkFiltering -lvtklibxml2 -lvtkDICOMParser -lvtkpng -lvtktiff -lvtkzlib -lvtkjpeg -lvtkalglib -lvtkexpat -lvtkverdict -lvtkmetaio -lvtkNetCDF -lvtkexoIIc -lvtkftgl -lvtkfreetype -lvtkHybrid -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mprviewer.cpp \
		dicominout.cpp \
		dataedit.cpp \
		imageml.cpp \
		volumeml.cpp \
		volumetml.cpp moc_mprviewer.cpp
OBJECTS       = main.o \
		mprviewer.o \
		dicominout.o \
		dataedit.o \
		imageml.o \
		volumeml.o \
		volumetml.o \
		moc_mprviewer.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		4view.pro
QMAKE_TARGET  = 4view
DESTDIR       = 
TARGET        = 4view

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mprviewer.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: 4view.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile 4view.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile 4view.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/4view1.0.0 || $(MKDIR) .tmp/4view1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/4view1.0.0/ && $(COPY_FILE) --parents mprviewer.h dicominout.h dicominout.h dataedit.h imageml.h volumeml.h volumetml.h myvtkcellpicked.h .tmp/4view1.0.0/ && $(COPY_FILE) --parents main.cpp mprviewer.cpp dicominout.cpp dataedit.cpp imageml.cpp volumeml.cpp volumetml.cpp .tmp/4view1.0.0/ && $(COPY_FILE) --parents mprviewer.ui .tmp/4view1.0.0/ && (cd `dirname .tmp/4view1.0.0` && $(TAR) 4view1.0.0.tar 4view1.0.0 && $(COMPRESS) 4view1.0.0.tar) && $(MOVE) `dirname .tmp/4view1.0.0`/4view1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/4view1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mprviewer.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mprviewer.cpp
moc_mprviewer.cpp: myvtkcellpicked.h \
		dicominout.h \
		dataedit.h \
		mprviewer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mprviewer.h -o moc_mprviewer.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mprviewer.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mprviewer.h
ui_mprviewer.h: mprviewer.ui
	/usr/bin/uic-qt4 mprviewer.ui -o ui_mprviewer.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mprviewer.h \
		myvtkcellpicked.h \
		dicominout.h \
		dataedit.h \
		imageml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mprviewer.o: mprviewer.cpp mprviewer.h \
		myvtkcellpicked.h \
		dicominout.h \
		dataedit.h \
		ui_mprviewer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mprviewer.o mprviewer.cpp

dicominout.o: dicominout.cpp dicominout.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dicominout.o dicominout.cpp

dataedit.o: dataedit.cpp dataedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataedit.o dataedit.cpp

imageml.o: imageml.cpp imageml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o imageml.o imageml.cpp

volumeml.o: volumeml.cpp volumeml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o volumeml.o volumeml.cpp

volumetml.o: volumetml.cpp volumetml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o volumetml.o volumetml.cpp

moc_mprviewer.o: moc_mprviewer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mprviewer.o moc_mprviewer.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

