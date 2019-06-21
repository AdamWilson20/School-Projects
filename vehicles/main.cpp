#include <iostream> //for cout, cin
#include <iomanip> // for setw, fixed, setprecision() manipulators
#include <fstream> //for file input/output
#include <string.h> //for string types usage
#include <cstdlib>
#include <ctime>
using namespace std;

/*
 Structure to store the date
 */
struct Date
{
    int month;
    int day;
    int year;
};

/*
 Structure to store Vehicle Options
 */
struct Option
{
    string seatMaterial;
    int wheelSize;
    string stereo;
    string winterPackage;
};

/*
 Structure to store Vehicles data
 */
struct Vehicle
{
    int ID;
    string make;
    int cylinder;
    string trans;

    Date manufDate;
    Date shipDate;

    Option vehicleOptions;

    char receiverFlag; // I or D

    //for individuals
    string ind_first, ind_last, ind_address;

    //for dealers
    int deal_zip;


};

Vehicle* readVehicleFromFile(int &totalVehicles);
void menu(Vehicle *vehicle, int totalVehicle);
void printHorizontalLine(int width, char border_char );
void printVehicle(Vehicle *vehicle, int totalVehicle, char flags);

/*
 * Entry point
 */
int main()
{
    Vehicle *allVehicle;
    int totalVehicle = 0;
    allVehicle = readVehicleFromFile(totalVehicle);

    if( allVehicle == NULL )
    {
        cout << "allVehicle is NULL" << endl;
        return 0;
    }

    printVehicle(allVehicle, totalVehicle, ' ');
    menu(allVehicle, totalVehicle);

    return 0;
}



/*
 * Responsible for reading Vehicle records from vehicles.txt into Vehicle array of structs
 *
 *
 * @param totalVehicle: reference variable which post execution, contains size of Vehicle
 * @param return: pointer pointing to the array of structs containing Vehicle data
 */
Vehicle* readVehicleFromFile(int &totalVehicle)
{
    char delimiter;
    Vehicle *allVehiclePointer;
    //input stream for Vehicle data
    ifstream allVehicleInFile;

    //open Vehicles file
    allVehicleInFile.open("vehicles.txt");

    //error handling in case file does not exist - start
    if( !allVehicleInFile )
    {
        cout << "Error opening vehicles.txt" << endl;
        return NULL;
    }
    //error handling in case file does not exist - end
    cout << "Success opening vehicles.txt" << endl;

    allVehicleInFile >> totalVehicle;
    allVehiclePointer = new Vehicle[totalVehicle];

    cout << "totalVehicles: " << totalVehicle << endl;

    for(int i = 0; i < totalVehicle; i++)
    {
        allVehicleInFile >> allVehiclePointer[i].ID;
        allVehicleInFile >> allVehiclePointer[i].make;
        allVehicleInFile >> allVehiclePointer[i].cylinder;
        allVehicleInFile >> allVehiclePointer[i].trans;
        //get dates and delimiter = ':'
        allVehicleInFile >> allVehiclePointer[i].manufDate.month;
        allVehicleInFile >> delimiter;
        allVehicleInFile >> allVehiclePointer[i].manufDate.day;
        allVehicleInFile >> delimiter;
        allVehicleInFile >> allVehiclePointer[i].manufDate.year;

        allVehicleInFile >> allVehiclePointer[i].shipDate.month;
        allVehicleInFile >> delimiter;
        allVehicleInFile >> allVehiclePointer[i].shipDate.day;
        allVehicleInFile >> delimiter;
        allVehicleInFile >> allVehiclePointer[i].shipDate.year;

    }
    allVehicleInFile.close();

    int dummyID = 0;
    allVehicleInFile.open("options.txt");
    if( !allVehicleInFile)
    {
      cout << "Error opening options.txt" << endl;
      return NULL;
    }





    //read vehicle options
    for (int j = 0; j < totalVehicle; j++){
        allVehicleInFile >> dummyID;
       // if (dummyID == 20)
         //   dummyID = 0;
        allVehicleInFile >> allVehiclePointer[dummyID].vehicleOptions.seatMaterial;
        allVehicleInFile >> allVehiclePointer[dummyID].vehicleOptions.wheelSize;
        allVehicleInFile >> allVehiclePointer[dummyID].vehicleOptions.stereo;
        allVehicleInFile >> allVehiclePointer[dummyID].vehicleOptions.winterPackage;
    }

    allVehicleInFile.close();
    allVehicleInFile.open("owners.txt");
    if( !allVehicleInFile )
    {
      cout << "Error opening owners.txt" << endl;
    }
    //read owner information
    for (int k = 0; k < totalVehicle; k++){
        allVehicleInFile >> dummyID;
        //if (dummyID == 20)
          //dummyID = 0;
        allVehicleInFile >> allVehiclePointer[dummyID].receiverFlag;

        if (allVehiclePointer[dummyID].receiverFlag == 'D') //this is a dealer vehicle
            allVehicleInFile >> allVehiclePointer[dummyID].deal_zip;
        else{ // this is an individual's vehicle
            allVehicleInFile >> allVehiclePointer[dummyID].ind_first;
            allVehicleInFile >> allVehiclePointer[dummyID].ind_last;
            getline(allVehicleInFile, allVehiclePointer[dummyID].ind_address);
        }
    }
    allVehicleInFile.close();

    return allVehiclePointer;
}


/*
 * Responsible for printing menu and handling user selection
 *
 *
 * @param Vehicle: pointer pointing to the array of structs containing Hospital Personnel data
 * @param totalVehicle: size of Vehicle
 */

void menu(Vehicle *vehicle, int totalVehicle)
{
    int input;
    while( true )
    {
        cin >> input;
        switch( input )
        {
            case 0:
                // 0 - print all vehicles
                printVehicle(vehicle, totalVehicle, ' ');
                break;
            case 1:
                // 1 - print only vehicles manufactured for dealers
                printVehicle(vehicle, totalVehicle, 'D');
                break;
            case 2:
                // 2 - print only vehicles manufactured for individuals
                printVehicle(vehicle, totalVehicle, 'I');
                break;
            case 3:
                // 3 - print only vehicles with 4 cylinder engines
                printVehicle(vehicle, totalVehicle, '4');
                break;
            case 4:
                // 4 - print only vehicles with premium stereos
                printVehicle(vehicle, totalVehicle, 'P');
                break;
            case 5:
                // 5 - print only vehicles with leather seats
                printVehicle(vehicle, totalVehicle, 'L');
                break;
            case 6:
                // 6 - exit
                exit(0);
        }

    }
}

/*
 * Responsible for printing the Vehicle array of structs
 *
 *
 * @param vehicle: pointer pointing to the array of structs containing Vehicle data
 * @param totalVehicle: size of vehicle
 */
void printVehicle(Vehicle *vehicle, int totalVehicle, char flags){

    if(vehicle == NULL || totalVehicle < 1 )
    {
        return;
    }

    cout << endl;
    printHorizontalLine(85, '*');
    printHorizontalLine(85, '*');
    for(int i = 0; i < totalVehicle; i++)
    {

        if( flags != ' ' )
        {
            if( (flags == 'I' && vehicle[i].receiverFlag != 'I') || (flags == 'D' && vehicle[i].receiverFlag != 'D') || (flags == 'L' && vehicle[i].vehicleOptions.seatMaterial != "Leather") || (flags == '4' && vehicle[i].cylinder != 4) || (flags ==  'P' && vehicle[i].vehicleOptions.stereo != "Premium"))
            {
                // skip roles which do not match roleFlag
                continue;
            }
        }
        // filter - end

        cout.clear();
        cout.fill(' ');

        cout
        << left
        << setw(3)
        << i
        << left << setw(10)
        << vehicle[i].make
        << left << setw(3)
        << vehicle[i].cylinder

        << left << setw(10)
        << vehicle[i].trans
        << left
        << vehicle[i].manufDate.month << ':' << vehicle[i].manufDate.day << ':' << vehicle[i].manufDate.year
        << left << "\t"
        << vehicle[i].shipDate.month << ':' << vehicle[i].shipDate.day << ':' << vehicle[i].shipDate.year
        << "\t" ;

        //print options
        cout << left << setw(10)
        << vehicle[i].vehicleOptions.seatMaterial
        << left << setw(5)
        << vehicle[i].vehicleOptions.wheelSize
        << left << setw(10)
        << vehicle[i].vehicleOptions.stereo
        << left << setw(5) << vehicle[i].vehicleOptions.winterPackage;

        cout << left << setw(3) << vehicle[i].receiverFlag;

        if (vehicle[i].receiverFlag == 'D')
            cout << left << setw(7) << vehicle[i].deal_zip;
        else
            cout << left << setw(3)
            << vehicle[i].ind_first << " " << vehicle[i].ind_last
            << "   "
            << vehicle[i].ind_address;

        cout << endl;
    }
    printHorizontalLine(85, '*');
    printHorizontalLine(85, '*');
    cout << endl;
    cout << "0 - Print all vehicles" <<endl;
    cout << "1 - Print only vehicles manufactured for dealers" << endl;
    cout << "2 - Print only vehicles manufactured for individuals" << endl;
    cout << "3 - Print only vehicles with 4 cylinder engines" << endl;
    cout << "4 - Print only vehicles with premium stereos" << endl;
    cout << "5 - Print only vehicles with leather seats" << endl;
    cout << "6 - Exit: ";
}


/*
 * Responsible for printing a horizontal line which consists of border_char characters
 *
 *
 * @param width: count of border_char
 * @param border_char: width made out of characters
 */
void printHorizontalLine( int width, char border_char )
{
    cout.fill( border_char );
    cout << setw( width ) << border_char << "\n";
    cout.fill(' ');
}
