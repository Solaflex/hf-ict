#include <QApplication>

#include "t.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  // create container
  DataContainer *c = new DataContainer();

  Writer w1(c);
  w1.start();

  Writer w2(c);
  w2.start();

  Reader r1(c);
  r1.start();

  Reader r2(c);
  r2.start();

  return app.exec();
}
