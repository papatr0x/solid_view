#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <vtkSmartPointer.h>

//------------------------------------------------------------------------------

class QVTKOpenGLWidget;
class vtkRenderer;
class vtkRenderWindow;
class vtkRenderWindowInteractor;
class vtkDataSet;

//------------------------------------------------------------------------------

class DisplayWindow : public QWidget
{
   Q_OBJECT
public:
   explicit DisplayWindow(QWidget *parent = nullptr);

   void setDataSet(vtkSmartPointer<vtkDataSet> data);
   void saveDataSet(QString& filename);
signals:

public slots:

private:
   QVTKOpenGLWidget* m_vtkWidget;
   vtkSmartPointer<vtkRenderer> m_renderer;
   vtkSmartPointer<vtkRenderWindow> m_renderWindow;
   vtkSmartPointer<vtkRenderWindowInteractor> m_windowInteractor;
   vtkSmartPointer<vtkDataSet> m_dataSet;
};

//------------------------------------------------------------------------------

#endif // DISPLAYWINDOW_H
