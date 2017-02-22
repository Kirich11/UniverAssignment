#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum days {Mon,Tue,Wed,Thu,Fri,Sat,Sun};

class product {
    private:
        days day;
        int supplied; //amount of supplies
        int sold; //amount of sold product
        string name; //name of the product

    public:
        product(){};
        product(days, int, int, string); //constructor with args
        ~product() {}; //destructor
        void getInfo(); //read info from file and form our products
        void displayInfo(); //display our info on srceen
        void doMagic(); //count all products sold on one day
        void writeInfoToFile(); //write our result in a file
};

