#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//------------------------------------------------------------------------------

namespace Ui {
class MainWindow;
}

class DisplayWindow;

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
  void save();

private:
  Ui::MainWindow* m_ui;
  DisplayWindow* m_display;
};

#endif // MAINWINDOW_H
