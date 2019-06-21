#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>  //for rand
#include <time.h>  //for time
#include "cats.h"

using namespace std;

int RandomMonth() //creates random month
{
    int random_month;

    random_month = (rand() % 11 + 1);

    return random_month;

};

int RandomDate() //creates random date
{
 int random_date;

 random_date = (rand() % 27 + 1);
    return random_date;
};

string A()
{
    ofstream myF;
    string length[4] = {"S","M","L","H"};
    int x = rand() % 3;
    if (x == 0)
    {
        return length[0];
    }
    else if (x == 1)
    {
        return length[1];
    }
    else if (x == 2)
    {
        return length[2];
    }
    else if (x == 3)
    {
        return length[3];
    }

}

string B()
{
    ofstream myF;
    string color[7] = {"WH","BA","RE","BU","CR","BR","CI"};
    int x = rand() % 7;
    if (x == 0)
    {
    return color[0];
    }
    else if (x == 1)
    {
        return color[1];
    }
    else if (x == 2)
    {
        return color[2];
    }
    else if (x == 3)
    {
        return color[3];
    }
    else if (x == 4)
    {
        return color[4];
    }
     else if (x == 5)
    {
        return color[5];
    }
     else if (x == 6)
    {
        return color[6];
    }
     else if (x == 7)
    {
        return color[7];
    }
}

string C()
{
    ofstream myF;
     string pattern[6] = {"SO","TA","BC","CA","TS","CP"};
    int x = rand() % 6;
    if (x == 0)
    {
        return pattern[0];
    }
    else if (x == 1)
    {
        return pattern[1];
    }
    else if (x == 2)
    {
        return pattern[2];
    }
    else if (x == 3)
    {
        return pattern[3];
    }
    else if (x == 4)
    {
        return pattern[4];
    }
     else if (x == 5)
    {
        return pattern[5];
    }
     else if (x == 6)
    {
        return pattern[6];
    }
}

string D()
{
    ofstream myF;
    string properties[3] = {"TI","SH","SM"};
    int x = rand() % 3;
    if (x == 0)
    {
        return properties[0];
    }
    else if (x == 1)
    {
        return properties[1];
    }
    else if (x == 2)
    {
        return properties[2];
    }

}

void PrintCats()
{
        ofstream myF;
    myF.open("catData.txt");
    for(int i = 0; i < 2000; i++)
    {
myF << A() << "-";
myF << B() << "-";
myF << C() << "-";
myF << D() << " ";
myF << RandomMonth() <<":"<< RandomDate() << ":" << "2016" << endl;
    }
}
