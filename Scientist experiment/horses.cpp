#include <iostream>
#include <string>
#include <stdlib.h>  //for rand
#include <time.h>  //for time
#include <fstream>
#include "horses.h"

using namespace std;

string RandomName(){
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    string name;
    int max_value = 15; //sets the max
    int min_value = 6; //set the min
    int range = max_value - min_value; //formula for range

    int Random_Size = rand() % range + min_value; //range + min gives you the boundaries

    for (int i = 0; i < Random_Size ; ++i) {
        name += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return name;
}

int RandomAge() //creates random date
{
 int random_age;
 int max_age = 11; //sets the max age
 int min_age = 2; //sets the min age
 int range = max_age - min_age; //formula for range

 random_age = (rand() % range + min_age); //range + min gives the boundaries

    return random_age;
}


string color()
{
    string color[6] = {"B","C","W","G","L","S"};
    int x = rand() % 6;
    if (x == 0)
    {
        return color[0]; //returns B
    }
    else if (x == 1)
    {
        return color[1]; //returns C
    }
    else if (x == 2)
    {
        return color[2]; //returns W
    }
    else if (x == 3)
    {
        return color[3]; //returns G
    }
    else if (x == 4)
    {
        return color[4]; //returns L
    }
    else if (x == 5)
    {
        return color[5]; //returns S
    }

}
string pattern()
{
    string pattern[3] = {"L","A","P"};
    int x = rand() % 3;
    if (x == 0)
    {
        return pattern[0]; //returns L
    }
    else if (x == 1)
    {
        return pattern[1]; //returns A
    }
    else if (x == 2)
    {
        return pattern[2]; //returns P
    }

}

string markings()
{
    string markings[2] = {"L","F"};
    int x = rand() % 3;
    if (x == 0)
    {
        return markings[0]; //returns L
    }
    else if (x == 1)
    {
        return markings[1]; //returns F
    }
    else if (x == 2)
    {
        return markings[0] + markings[1]; //if the random number is 2 then it returns both L and F.

    }
}

void PrintHorses()
{
      ofstream myFile;
    myFile.open("horsesData.txt");
    for(int i = 0; i < 3000; i++)
    {
    myFile << RandomName() << " ";
    myFile << RandomAge();
    myFile << color();
    myFile << pattern();
    myFile << markings() << endl;
    }
}

