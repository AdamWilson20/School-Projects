#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>  //for rand
#include <time.h>  //for time
#include "rabbits.h"

using namespace std;


void PrintRabbits()
{
    ofstream outFile;
    outFile.open("rabbitsData.txt");
   for(int i = 0; i < 1000; i++)
   {
    int x = rand() % 2;
    int y = rand() % 2;

   if (x == 0)
   {
       outFile << "A";
       if (y == 0)
       {
           outFile << "A";
       }
       else if (y == 1)
       {
           outFile << "a";
       }
   }
   else if (x == 1)
   {
       outFile << "a";
       outFile << "a";
   }
    int z = rand() % 2;
    int c = rand() % 2;

   if (z == 0)
   {
       outFile << "B";
       if (c == 0)
       {
           outFile << "B";
       }
       else if (c == 1)
       {
           outFile << "b";
       }
   }
   else if (z == 1)
   {
       outFile << "b";
       outFile << "b";
   }
   int q = rand() % 2;
    int e = rand() % 2;

   if (q == 0)
   {
       outFile << "C";
       if (e == 0)
       {
           outFile << "C";
       }
       else if (e == 1)
       {
           outFile << "c";
       }
   }
   else if (q == 1)
   {
       outFile << "c";
       outFile << "c";
   }
   int m = rand() % 2;
    int n = rand() % 2;

   if (m == 0)
   {
       outFile << "D";
       if (n == 0)
       {
           outFile << "D";
       }
       else if (n == 1)
       {
           outFile << "d";
       }
   }
   else if (m == 1)
   {
       outFile << "d";
       outFile << "d";
   }
    int j = rand() % 2;
    int k = rand() % 2;

   if (j == 0)
   {
       outFile << "E";
       if (k == 0)
       {
           outFile << "E" << endl;
       }
       else if (k == 1)
       {
           outFile << "e" << endl;
       }
   }
   else if (j == 1)
   {
       outFile << "e";
       outFile << "e" << endl;
   }

   }

    outFile.close();
}
