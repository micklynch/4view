#ifndef MYVTKCELLPICKED_H
#define MYVTKCELLPICKED_H
// taken from http://vis.computer.org/vis2004/DVD/tutorial/tut_5/notes_4.pdf slide 35

#include <vtkCommand.h>
#include <vtkCellPicker.h>
#include <QDebug>

class myVtkCellPicked: public vtkCommand
{
public:
    static myVtkCellPicked* New()
    {
        return new myVtkCellPicked;
    }
    virtual void Execute(vtkObject *caller, unsigned long eventId, void *callData)
    {
        vtkCellPicker *picker = vtkCellPicker::SafeDownCast(caller);
        qDebug() << "Picked cell id " << picker->GetCellId() << endl;
    }

};


#endif // MYVTKCELLPICKED_H
