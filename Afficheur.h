#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QString>
#include "Percolateur.h"

class Afficheur : public QWidget
{
  Q_OBJECT

private:
  int unSite;
  Percolateur* myPercolateur;
  bool draw;
  bool drawPercolateur;

public:
  explicit Afficheur(QWidget *parent = 0);
  ~Afficheur();
  void paintEvent(QPaintEvent * /* event */);
   // le cote de la grille d'affichage
  size_t size;


signals:

public slots:
  void SLOT_display(Percolateur*);
  void SLOT_display(Percolateur*, int);
};

#endif // AFFICHEUR_H
