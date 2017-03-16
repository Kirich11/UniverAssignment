#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <wchar.h>
#include <stdio.h>
using namespace std;

class product {
    private:
        string day;
        int supplied; //amount of supplies
        int sold; //amount of sold product
        string name; //name of the product

    public:
        product(){};
        product(string, int, int, string); //constructor with args
        ~product() {}; //destructor
        vector<product> getInfo(const char*); //read info from file and form our products
        string getDay();
        int getSuppl();
        int getSold();
        string getName();
        void displayInfo(vector<product>); //display our info on srceen
        vector<product> doMagic(vector<product>); //count all products sold on one day
        void writeInfoToFile(const char*, vector<product>); //write our result in a file
};

