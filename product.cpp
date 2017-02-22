#include "product.h"

product::product(days day, int supplied, int sold, string name)
    {
        day = day;
        supplied = supplied;
        sold = sold;
        name = name;
    }

//read info from file and form our product
void product::getInfo() {
    ifstream f;
    string product;
    f.open("text.txt");
    while(!f.eof()) {
        getline(f, product);
        
    }
    f.close();
    cout<< product << endl;
    //return product;
}
/*
//display our info on srceen
void displayInfo() {
}

//count all products sold on one day
void doMagic() {
}

//write our result in a file
void writeInfoToFile() {
}
*/