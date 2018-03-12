#include "MainWindow.h"

#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

//------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
   // this is required to use QVTKOpenGLWidget
   QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

   QApplication a(argc, argv);
   MainWindow w;
   w.show();

  return a.exec();
}
