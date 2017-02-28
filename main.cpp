#include "product.h"

int main() {
    setlocale(LC_ALL, "");
    product prod;
    cout <<"Го пошаманим"<< endl << endl;
    /*Start of our programm
        Allocate pointer for filename & string for it
        Wait for the filename to be correct
        */
    vector<product> arr;
    const char* filename = new char[10000];
    string f;
    cout <<"Введите путь к файлу: " << endl;
    do {
        cout<<"here"<<endl;
        cin>> f;
        filename = f.c_str();
        //cin>> fi;
        //cout<< "Вы ввели: " << filename << endl;
        arr = prod.getInfo(filename);
        cout<< "arr size: "<<arr.size()<<endl;
        if (arr.size()==0) {
            cout<< "Неверное имя файла или файл пустой"<<endl << "Введите путь к файлу снова:"<< endl;
        }
    } while (arr.size() ==0);
    cout<<"Данные из файла: "<< endl;
    prod.displayInfo(arr); //display info that we got from the file
    cout<<""<<endl;

    /*Do the assignment: find all products sold on one day*/
    vector<product> oneDay;
    oneDay = prod.doMagic(arr);
    prod.displayInfo(oneDay); //display our results
    cout<<""<<endl;

    /*Write our result to a new file*/
    cout<<"Введити путь к новому файлу:" << endl;
    const char* filename2 = new char[10000];
    string f2;
    cin>> f2;
    filename2 = f2.c_str();
    prod.writeInfoToFile(filename2, oneDay);
    return 0;
}