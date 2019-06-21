#include <iostream>
#include "binaryTree.h"

void box::run(){
  default_random_engine gen(time(NULL));
    uniform_real_distribution<double> udist(1, 99);   ///random number of the value

    int numBoxes;
    queue<box> qBox;
    BinaryTree Tree;

    cout << "How Many Boxes would you like to create? ";
    cin >> numBoxes;
    cout << endl;

    for(int i = 0; i < numBoxes; i++) {
        qBox.push(udist(gen));
    }

    cout << "Contents of Each Boxes: " << endl;
    cout << qBox.front().getValue() << endl;

    Tree.setData(qBox.front().getValue());
    qBox.pop();

    for(int i = 1; i < numBoxes; i++) {
        cout << qBox.front().getValue() << endl;

        Tree.insertValue(qBox.front().getValue());
        qBox.pop();
    }

    cout << endl << endl;

    cout << "Binary Tree Contents with Frequency: " << endl;
    Tree.display();
}
