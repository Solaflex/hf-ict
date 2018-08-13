#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <string>


#include<QHBoxLayout>
#include<QVBoxLayout>



#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
  Node *left;
  Node *right;
  int value;
  Node(int value) : left(0), right(0), value(value) {}
};

class BinaryTree {
private:
  Node *root;
  void insert(int value, Node* node) {
    if (node->value < value) {
      // insert right
      if (node->right == 0) node->right = new Node(value);
      else insert(value, node->right);
    } else {
      // insert left
      if (node->left == 0) node->left = new Node(value);
      else insert(value, node->left);
    }
  }
  int sumEven(Node* node) {
      int internalsummary = 0;

      // Check if value is even
      if((node->value % 2) == 0) {
        internalsummary = node->value;
      }

      if(node->left != 0) {
          internalsummary += sumEven(node->left);
      }
      if(node->right != 0) {
          internalsummary += sumEven(node->right);
      }

      return internalsummary;
  }
public:
  BinaryTree() : root(0) {}
  void insert(int value) {
    if (root == 0) {
      root = new Node(value);
    } else {
      insert(value, root);
    }
  }
  int sumEven() {
      int summary = 0;
      summary = sumEven(root);
  }

};

void Encoding(std::string myString) {
    int Multiplicator = 0;
    for(char c:myString){

        if(isdigit(c)) {
            if(Multiplicator > 0) {
                Multiplicator = Multiplicator * 10 + c;
            } else {
                Multiplicator = (int)c - 48;
            }
        } else {
            for(int i = 0; i < Multiplicator; i++) {
                qDebug() << c;
            }
            qDebug() << endl;
            Multiplicator = 0;
        }
    }

    return;
}


int main(int argc, char *argv[])
{
    // Encoding
    Encoding("");
    Encoding("1a1b1c");
    Encoding("2n5b6c11v");
    qDebug("Encoding Finish -------");

    // Binary Tree
    BinaryTree bt ;
    bt.insert (9);
    bt.insert (4);
    bt.insert (6);
    bt.insert (3);
    bt.insert (5);
    bt.insert (8);
    qDebug() << "Summe : " << bt.sumEven();
    qDebug() << "Binary Tree finish -----";


    // Sortiersoftware


    QApplication a(argc, argv);


    MainWindow w;
    w.show();





    return a.exec();
}



