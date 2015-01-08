#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>

#include "Afficheur.h"
#include "Percolateur.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  Percolateur *perco;
  Afficheur *afficheur1;
  QString OutPutMessage(int, int);

private:
  Ui::MainWindow *ui;
  bool doIt;

signals:
  void SIGNAL_display(Percolateur*, int = 0);

public slots:
    void SLOT_new();
    void SLOT_run();
    void SLOT_StepByStep();
};

#endif // MAINWINDOW_H
