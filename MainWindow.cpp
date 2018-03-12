#include "MainWindow.h"
#include "DisplayWindow.h"
#include "ui_MainWindow.h"

#include <QAction>
#include <QFileDialog>

#include <vtkPLYReader.h>
#include <vtkOBJReader.h>
#include <vtkSmartPointer.h>

//------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);
  createActions();
}

//------------------------------------------------------------------------------

MainWindow::~MainWindow()
{
  delete m_ui;
}

//------------------------------------------------------------------------------

void MainWindow::createActions()
{
   // create file menu and toolbar
   QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
//   QToolBar* fileToolbar = addToolBar("File");

   // setup an action
   QAction* openAction = fileMenu->addAction("&Open");
   openAction->setShortcut(QKeySequence::Open);
   openAction->setToolTip(tr("Open a file"));
   connect( openAction, &QAction::triggered,
            this,       &MainWindow::open);
//   fileToolbar->addAction(openAction);

   fileMenu->addSeparator();

   // setup other action
   QAction* quitAction = fileMenu->addAction(tr("&Quit"), this, &QMainWindow::close) ;
   quitAction->setShortcut(QKeySequence::Quit);
   quitAction->setToolTip("Quit application");

   // create help menu
   QMenu* helpMenu = menuBar()->addMenu(tr("&Help"));
   QAction* aboutAction = helpMenu->addAction(tr("&About"), qApp, &QApplication::aboutQt);
   aboutAction->setToolTip(tr("Show Qt's about box"));
}

//------------------------------------------------------------------------------

void MainWindow::open()
{
   QStringList filenames = QFileDialog::getOpenFileNames(this);
   for( const QFileInfo& fileInfo : filenames )
   {
      vtkSmartPointer<vtkAbstractPolyDataReader> reader;
      if( !fileInfo.completeSuffix().compare("PLY", Qt::CaseInsensitive))
      {
         reader = vtkSmartPointer<vtkPLYReader>::New();
      }
      else if( !fileInfo.completeSuffix().compare("OBJ", Qt::CaseInsensitive))
      {
         reader = vtkSmartPointer<vtkOBJReader>::New();
      }

      reader->SetFileName(qPrintable(fileInfo.absoluteFilePath()));
      reader->Update();

      vtkSmartPointer<vtkPolyData> data = reader->GetOutput();
      data->PrintSelf(std::cout,vtkIndent(0));

      DisplayWindow* display = new DisplayWindow(this);
      setCentralWidget(display);

      display->setDataSet(data);

   }
}

