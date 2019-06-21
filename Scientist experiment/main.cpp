#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>  //for rand
#include <time.h>  //for time
#include "rabbits.h"
#include "horses.h"
#include "cats.h"

using namespace std;



int main()
{
    srand (time(NULL));
    cout << "Welcome to Assignment #6!" << endl;
    cout << "Your data is being processed!" << endl;


    PrintRabbits(); ///Prints data to RabbitsData.txt
    PrintCats();  ///Prints data to CatsData.txt
    PrintHorses(); ///Prints data to HorsesData.txt


return 0;
};




