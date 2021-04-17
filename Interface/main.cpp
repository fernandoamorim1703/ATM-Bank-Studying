#include"personaccount.h"
#include "interface.h"
#include"accountvector.h"

#include<stdio.h>
#include<stdlib.h>
#include <QApplication>

AccountVector *accounts = new AccountVector();

int main(int argc, char *argv[])
 {

  QApplication a(argc, argv);
  interface w;
  w.show();
  return a.exec();
 }
