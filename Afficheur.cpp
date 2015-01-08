#include "Afficheur.h"
#include <iostream>      // for debugging

using namespace std;

Afficheur::Afficheur(QWidget *parent) :
  QWidget(parent)
{
  myPercolateur = new Percolateur(0, 0);
  draw = false;
}

Afficheur::~Afficheur(){
  delete myPercolateur;
}

void Afficheur::paintEvent(QPaintEvent * /* event */) {

  QPainter painter(this);
  QPen pen(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setPen(pen);

  int pasX = this->width() / size;
  //cout<<"this->width() = "<<this->width()<<"      size = "<<this->size<<"      pasX = "<<pasX<<endl;
  int pasY = this->height() / size;

  if(draw){
      int i = unSite % myPercolateur-> Width;
      int j = unSite / myPercolateur-> Width;
      QRect r(i*pasX+1,j*pasY+1,pasX-2, pasY-2 );
      painter.fillRect(r, Qt::yellow );
    }

  if(drawPercolateur){
      for(int s = 0; s<myPercolateur->size; s++)
        if(myPercolateur->openSites->at(s) != 0){{
              int i = s % myPercolateur-> Width;
              int j = s / myPercolateur-> Width;
              QRect r(i*pasX+1,j*pasY+1,pasX-2, pasY-2 );
              painter.fillRect(r, Qt::green );
            }
          }
    }
}

void Afficheur::SLOT_display(Percolateur* unPercolateur){
  this->size = unPercolateur->Width;
  myPercolateur = unPercolateur;
  //cout<<"this->size =  "<<this->size <<endl;
  drawPercolateur = true;
  update();
}
void Afficheur::SLOT_display(Percolateur* unPercolateur, int n ){
  this->size = unPercolateur->Width;
  myPercolateur = unPercolateur;
  unSite = n;
  draw = true;
  update();
}
