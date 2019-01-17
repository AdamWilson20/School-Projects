#ifndef GUN_H_INCLUDED
#define GUN_H_INCLUDED

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

using namespace std;

class guns{



public:
     vector<double> threat;
    guns(){}
    ~guns(){}
    void generateThreat();



private:


    int burst;
    int successRate;
    int maxBurst = 5;
    int minBurst = 1;
    int randomThreat;
    int maxTargets = 10;
    int minTargets = 4;

};

#endif // GUN_H_INCLUDED
