#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;

class box
{
    private:
        int value;

    public:
        box()
        {
            value = 0; //default constructor
        };

        box(int val){
            value = val;
        }

        int getValue(){
            return value;
        }
        void run();
};

class BinaryTree
{
    private:
        int data;
        int frequency = 1;
        BinaryTree* left;
        BinaryTree* right;

    public:
        BinaryTree() {
           data = 0;
           left = NULL;
           right = NULL;
        }

        void setData(int d){
            data = d;
        }

        void insertValue(int d) {
            if(d < data) {
                if(left == NULL){
                    left = new BinaryTree();
                    left->data = d;
                }

                else{
                    left->insertValue(d);
                }
            }

            else if(d == data){
                frequency++;
            }

            else if(d > data) {
                if(right == NULL){
                    right = new BinaryTree();
                    right->data = d;
                }

                else{
                    right->insertValue(d);
                }
            }
        }

        void display() {

            if(left != NULL) {
                    left->display();
                }

            cout << data << " with a Frequency of " << frequency << endl;

            if(right != NULL) {
                    right->display();
                }

            else return;
        }
};


#endif // BINARYTREE_H_INCLUDED
