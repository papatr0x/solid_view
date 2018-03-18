#ifndef FILELOADER_H
#define FILELOADER_H

#include <QStringList>
#include <vtkSmartPointer.h>

//------------------------------------------------------------------------------

class vtkDataSet;
class vtkAlgorithm;

//------------------------------------------------------------------------------

class FileLoader
{
public:

   FileLoader(/*const QString& filename = ""*/);

   static const QString supportedFormats();
   bool load(const QString& filename);
   vtkSmartPointer<vtkDataSet> getOutput();
protected:
   vtkSmartPointer<vtkAlgorithm> m_reader;
};

#endif // FILELOADER_H
