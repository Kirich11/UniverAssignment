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
    vector<string> container;
    ifstream f;
    f.open("text.txt");
    while(!f.eof()) {
        string product;
        getline(f, product);
        container.insert(container.end(),product);
    }
    f.close();
    for (int i=0; i<container.size(); i++) {
    cout<< container[i] << endl;
    }
    return product;
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