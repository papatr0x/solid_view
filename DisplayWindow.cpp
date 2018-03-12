#include "DisplayWindow.h"

#include <QVBoxLayout>
#include <QVTKOpenGLWidget.h>

#include <vtkActor.h>
#include <vtkCellData.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>

//------------------------------------------------------------------------------

DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
   m_renderer = vtkSmartPointer<vtkRenderer>::New();
   m_renderer->SetBackground(.1, .2, .5);

   m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
   m_renderWindow->AddRenderer(m_renderer);

   m_vtkWidget = new QVTKOpenGLWidget();
   m_vtkWidget->SetRenderWindow(m_renderWindow);

   // it seems this is not required for QVTKOpenGLWidget.
//   m_windowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
//   m_windowInteractor->SetRenderWindow(m_renderWindow);
//   m_windowInteractor->Start();

   QVBoxLayout* layout = new QVBoxLayout(this);
   setLayout(layout);

   layout->addWidget(m_vtkWidget);
}

//------------------------------------------------------------------------------

void DisplayWindow::setDataSet( vtkSmartPointer<vtkPolyData> data )
{
   data->GetCellData()->Initialize();
   data->GetPointData()->Initialize();
   auto mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
   mapper->SetInputData(data);

   auto actor = vtkSmartPointer<vtkActor>::New();
   actor->SetMapper(mapper);

   m_renderer->AddActor(actor);
   m_renderer->ResetCamera();
}
