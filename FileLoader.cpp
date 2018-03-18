#include "FileLoader.h"

#include <QFileInfo>
#include <vtkSmartPointer.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPLYReader.h>
#include <vtkOBJReader.h>


//------------------------------------------------------------------------------

FileLoader::FileLoader()
{
}

//------------------------------------------------------------------------------

const QString FileLoader::supportedFormats()
{
   QStringList formats;
   formats << "All formats (*.ply *.obj *.vtp)"
           << "PLY format (*.ply)"
           << "OBJ format (*.obj)"
           << "VTK Polydata XML format (*.vtp)";

   return formats.join(";;");
}

//------------------------------------------------------------------------------

bool FileLoader::load(const QString& filename)
{
   const QFileInfo fileInfo(filename);
   const QString& suffix= fileInfo.completeSuffix();

   if( suffix.compare("vtp", Qt::CaseInsensitive) == 0)
   {
      auto reader = vtkSmartPointer<vtkXMLPolyDataReader>::New();
      reader->SetFileName(qPrintable(fileInfo.absoluteFilePath()));
      m_reader = reader;
      return true;
   }
   else if( suffix.compare("ply", Qt::CaseInsensitive) == 0)
   {
      auto reader = vtkSmartPointer<vtkPLYReader>::New();
      reader->SetFileName(qPrintable(fileInfo.absoluteFilePath()));
      m_reader = reader;
      return true;
   }
   else if( suffix.compare("obj", Qt::CaseInsensitive) == 0)
   {
      auto reader = vtkSmartPointer<vtkOBJReader>::New();
      reader->SetFileName(qPrintable(fileInfo.absoluteFilePath()));
      m_reader = reader;
      return true;
   }
   return false;
}

//------------------------------------------------------------------------------

// TODO: this should work in a separated thread and support a progress bar.
vtkSmartPointer<vtkDataSet> FileLoader::getOutput()
{
   if( !m_reader )
   {
      return nullptr;
   }

   m_reader->Update();
   auto data = vtkDataSet::SafeDownCast(m_reader->GetOutputDataObject(0));

   // describe what we have loaded
   data->PrintSelf(std::cout, vtkIndent(0));
   return data;
}

