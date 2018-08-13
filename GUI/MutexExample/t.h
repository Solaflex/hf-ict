#ifndef T_H
#define T_H

#include <QThread>

class QMutex;
class QWaitCondition;

class DataContainer {
private:
  int value;
  bool dataAvailable;
  QMutex *mutex;
  QWaitCondition *waitCondition;
public:
  DataContainer();
  void setValue(int value);
  int getValue();
};

class Writer : public QThread {
private:
  DataContainer *c;
  bool running;
  int id;
  static int idGenerator;
public:
  Writer(DataContainer *c);
  void run();
  void stopThread();
};

class Reader : public QThread {
private:
  DataContainer *c;
  bool running;
  int id;
  static int idGenerator;
public:
  Reader(DataContainer *c);
  void run();
  void stopThread();
};


#endif

