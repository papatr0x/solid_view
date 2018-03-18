#include "DisplayWindow.h"

#include <QVBoxLayout>
#include <QVTKOpenGLWidget.h>

#include <vtkActor.h>
#include <vtkCellData.h>
#include <vtkDataSet.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPointData.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkXMLDataSetWriter.h>

//------------------------------------------------------------------------------

DisplayWindow::DisplayWindow(QWidget *parent) : QWidget(parent)
{
   m_renderer = vtkSmartPointer<vtkRenderer>::New();
   m_renderer->SetBackground(.1, .2, .5);

   m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
   m_renderWindow->AddRenderer(m_renderer);

   m_vtkWidget = new QVTKOpenGLWidget();
   m_vtkWidget->SetRenderWindow(m_renderWindow);

   QVBoxLayout* layout = new QVBoxLayout(this);
   setLayout(layout);

   layout->addWidget(m_vtkWidget);
}

//------------------------------------------------------------------------------

void DisplayWindow::setDataSet( vtkSmartPointer<vtkDataSet> data )
{
   m_dataSet = data;

   // remove data if there is anything
   m_dataSet->GetCellData()->Initialize();
   m_dataSet->GetPointData()->Initialize();

   // build rendering chain
   // data->mapper->actor->renderer
   auto mapper = vtkSmartPointer<vtkDataSetMapper>::New();
   mapper->SetInputData(m_dataSet);

   auto actor = vtkSmartPointer<vtkActor>::New();
   actor->SetMapper(mapper);

   m_renderer->AddActor(actor);
   m_renderer->ResetCamera();
}

//------------------------------------------------------------------------------

void DisplayWindow::saveDataSet(QString& filename)
{
   auto writer = vtkXMLDataSetWriter::New();
   writer->SetInputData(m_dataSet);
   filename += ".vtp";
   writer->SetFileName(filename.toLatin1());
   writer->Write();
}

