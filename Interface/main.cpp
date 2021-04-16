#include"personaccount.h"
#include "interface.h"

#include<stdio.h>
#include<stdlib.h>
#include <QApplication>


int main(int argc, char *argv[])
 {

  QApplication a(argc, argv);
  interface w;
  w.show();
  return a.exec();
 }
