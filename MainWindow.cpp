#include "MainWindow.h"
#include "DisplayWindow.h"
#include "ui_MainWindow.h"
#include "FileLoader.h"

#include <QAction>
#include <QFileDialog>

#include <vtkSmartPointer.h>
#include <vtkDataSet.h>

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

   // setup an open action
   QAction* openAction = fileMenu->addAction("&Open");
   openAction->setShortcut(QKeySequence::Open);
   openAction->setToolTip(tr("Open a file"));
   connect( openAction, &QAction::triggered,
            this,       &MainWindow::open);

   // save action
   QAction* saveAction = fileMenu->addAction("&Save", this, &MainWindow::save);
   saveAction->setShortcut(QKeySequence::SaveAs);
   saveAction->setToolTip(tr("Save file as ..."));

   fileMenu->addSeparator();

   // setup other action
   QAction* quitAction = fileMenu->addAction(tr("&Quit"), this, &MainWindow::close) ;
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
   QStringList filenames = QFileDialog::getOpenFileNames(
            this, QString(), QString(), FileLoader::supportedFormats());

   for( const QString& filename : filenames )
   {
      vtkSmartPointer<vtkDataSet> data;

      FileLoader loader;
      if( loader.load(filename) && (data = loader.getOutput()) )
      {
         // FIX: display are not released when opening a new structure
         m_display = new DisplayWindow(this);
         setCentralWidget(m_display);

         m_display->setDataSet(data);
      }
   }
}

//------------------------------------------------------------------------------

void MainWindow::save()
{
   QString filename = QFileDialog::getSaveFileName(this);
   m_display->saveDataSet(filename);
}

