#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//------------------------------------------------------------------------------

namespace Ui {
class MainWindow;
}

//------------------------------------------------------------------------------

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

protected:
  void createActions();
  void open();

private:
  Ui::MainWindow* m_ui;
};

#endif // MAINWINDOW_H
