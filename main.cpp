#include "product.h"

int main() {
    setlocale(LC_ALL, "");
    product prod;
    cout <<"Го пошаманим"<< endl << endl;

    vector<product> arr;
    //arr.reserve(0);
    char* filename;
    cout <<"Введите путь к файлу: " << endl;
    do {
        cout<<"here"<<endl;
        cin>> filename;
        cout<< "Вы ввели: " << filename << endl;
        arr = prod.getInfo(filename);
        cout<< "arr size: "<<arr.size()<<endl;
        if (arr.size()==0) {
            cout<< "Неверное имя файла или файл пустой"<<endl << "Введите путь к файлу снова:"<< endl;
        }
    } while (arr.size() ==0);
    cout<<"Данные из файла: "<< endl << endl;
    prod.displayInfo(arr);

    vector<product> oneDay;
    oneDay = prod.doMagic(arr);
    prod.displayInfo(oneDay);

    cout<<"Введити путь к новому файлу:" << endl;
    char* filename2;
    //cin>> filename2;
    //prod.writeInfoToFile(filename, oneDay);
    //delete filename;
    return 0;
}