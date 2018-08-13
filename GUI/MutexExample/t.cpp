#include "t.h"

#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>


DataContainer::DataContainer() : dataAvailable(false) {
  mutex = new QMutex();
  waitCondition = new QWaitCondition();
}

void DataContainer::setValue(int value) {
  QMutexLocker locker(mutex);
  while (dataAvailable) {
    waitCondition->wait(mutex);
  }
  this->value = value;
  dataAvailable = true;
  waitCondition->wakeAll();
}

int DataContainer::getValue() {
  QMutexLocker locker(mutex);
  while (!dataAvailable) {
    waitCondition->wait(mutex);
  }
  dataAvailable = false;
  waitCondition->wakeAll();
  return value;
}

int Writer::idGenerator = 0;

Writer::Writer(DataContainer *c) : running(true), c(c) {
  id = idGenerator;
  idGenerator++;
}

void Writer::run() {
  srand(time(0));
  while (running) {
    int v = rand() % 1000;
    c->setValue(v);
    qDebug() << id << " writes " << v;
    msleep(rand() % 200);
  }
}

void Writer::stopThread() {
  running = false;
}

int Reader::idGenerator = 1000;

Reader::Reader(DataContainer *c) : running(true), c(c) {
  id = idGenerator;
  idGenerator++;
}

void Reader::run() {
  srand(time(0));
  int v;
  while (running) {
    int v = c->getValue();
    qDebug() << id << " reads " << v;
    msleep(rand() % 200);
  }
}

void Reader::stopThread() {
  running = false;
}
