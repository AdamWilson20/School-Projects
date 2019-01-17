#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>
#include "gun.h"

using namespace std;

void guns::generateThreat(){

normal_distribution<double> normal (100,15);
   default_random_engine gen(time(NULL));
    srand(time(0));

  int tar=rand()%(maxTargets-minTargets+1)+minTargets;
   for(int i = 0; i < tar; i++){

        randomThreat = normal(gen);
        threat.push_back(randomThreat);
        sort(threat.begin(),threat.end()); //sorts the vector but by least to greatest
        reverse(threat.begin(),threat.end()); //reveres the vector from least to greatest to greatest to least.
   }
   for(int i = 1; i < tar; i++){
        successRate = rand()%100+1;
    burst = rand()%(maxBurst-minBurst+1)+minBurst; //randomly generates the amount of bursts if success rate is higher than 85%
        if (successRate > 85)
    {
        //cout <<" Success Rate" << successRate; //testing to see what success rate is.
        cout <<" Target " << i;
        cout <<" \tThreat " << setprecision(3) << threat[i]; //access the threat vector of element needed in for loop.
        cout <<" \tBurst " << burst << endl;
    }
    else if (successRate < 85) //enters if successRate is below 85%....I wasn't sure what you wanted if the success rate was below 85%. In my head I was thinking that if it was under 85% it would miss and then create a new random percent for success and enter and shoot a burst if correct.
    {
       // cout <<" Success Rate " << successRate;
        cout <<" Target " << i;
        cout <<" \tThreat " << setprecision(3) << threat[i];
        cout <<" \tBurst " << burst << endl;

    }


        threat.pop_back();
   }





}
