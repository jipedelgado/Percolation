#include "MainWindow.h"
#include <QtWidgets>
#include "ui_MainWindow.h"
#include <QGroupBox>
#include <QString>
#include <iostream>      // for debugging
#include <stdio.h>       // for debugging
#include <time.h>        // for debugging

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
 // dimensionnement de la fenetre principale
    resize(1200, 800);

  // création de la barre des menus
  QMenu *menuFichier = menuBar()->addMenu("&Fichier");

     QAction *actionNew = new QAction("&Nouveau", this);
     actionNew->setShortcut(QKeySequence("Ctrl+N"));
     //actionNew->setIcon(QIcon("nouveau.png"));
     menuFichier->addAction(actionNew);

     QAction *actionQuitter = new QAction("&Quitter", this);
     actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
     //actionQuitter->setIcon(QIcon("quitter.png"));
     menuFichier->addAction(actionQuitter);

  QMenu *menuExecution = menuBar()->addMenu("&Execution");

  QAction *actionExecution = new QAction("&Execution", this);
     menuExecution->addAction(actionExecution);

     QAction *actionStepByStep = new QAction("&Pas à pas", this);
     actionStepByStep->setShortcut(QKeySequence("Ctrl+X"));
     menuExecution->addAction(actionStepByStep);

  // Création de la barre d'outils
      QToolBar *toolBarFichier = addToolBar("Fichier");
      toolBarFichier->addAction(actionNew);
      toolBarFichier->addAction(actionExecution);
      toolBarFichier->addAction(actionStepByStep);
      toolBarFichier->addAction(actionQuitter);

  // Définition de la zone centrale
      QMdiArea *zoneCentrale = new QMdiArea;

      QTextEdit *zoneTexte2 = new QTextEdit;
      QMdiSubWindow *sousFenetre2 = zoneCentrale->addSubWindow(zoneTexte2);
      sousFenetre2->resize(800,600);
      sousFenetre2->move(50,80);
      //sousFenetre2->setStyleSheet("background-color:blue;");

      // création d'un afficheur
      afficheur1 = new Afficheur;
      //afficheur1->setStyleSheet("background-color:blue;");

      QHBoxLayout *layout = new QHBoxLayout;
      layout->addWidget(afficheur1);
   // association de gridlayout à la fenetre2
      zoneTexte2->setLayout(layout);
      zoneTexte2->setStyleSheet("background-color:blue;");
      setCentralWidget(zoneCentrale);

   //Gestion des signaux
      connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
      connect(actionExecution, SIGNAL(triggered()), this, SLOT(SLOT_run()));
      connect(actionNew, SIGNAL(triggered()), this, SLOT(SLOT_new()));
      connect(actionStepByStep, SIGNAL(triggered()), this, SLOT(SLOT_StepByStep()));
      connect(this, SIGNAL(SIGNAL_display(Percolateur*, int)), afficheur1, SLOT(SLOT_display(Percolateur*, int)));

      doIt = false;
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::SLOT_new(){

  bool ok;
 int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"), tr("Percentage:"), 25, 0, 1000, 1, &ok);
 if(!ok)
 {
 exit( 0 );
 }

  size_t N = i;
  perco = new Percolateur(N, N);
  emit SIGNAL_display(perco, -1);
  doIt = true;
}

void MainWindow::SLOT_run(){
  int count = 0;
  if(doIt){
      bool again = true;
      while(again){
          int s = perco->newSite();
          count++;
          perco->open(s);
          again = !perco->percolate();
          emit SIGNAL_display(perco, s);
        }

      QMessageBox msgBox;
      msgBox.setText(OutPutMessage(perco->size, count));
      msgBox.exec();

      cout<<"nombre de sites = "<<count<<endl;
      cout<<"nombre magique  = "<<1.0*count/perco->size <<endl;
    }
}

void MainWindow::SLOT_StepByStep(){
  if(doIt and !perco->percolate()){
      int s = perco->newSite();
      cout<<endl<<endl<<"site nouveau = "<<s<<endl;
      perco->open(s);
      emit SIGNAL_display(perco, s);
    }
  cout<<"Ca y est, je percole !!!";
}
QString MainWindow::OutPutMessage(int total, int opened){
  QString qsTotal;
  qsTotal.setNum(total);

  QString qsOpened;
  qsOpened.setNum(opened);

  QString ratio;
  if(total != 0)
    ratio.setNum(1.0*opened/total);
  else
    return "division par zéro !";
  QString message;
  message.append("Nombre total de sites = "+ qsTotal);
  message.append("\nnombre de sites ouverts = " + qsOpened );
  message.append("\ntaux de percolation = "+ratio);
  return message;
}






