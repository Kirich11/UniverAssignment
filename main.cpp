#include "product.h"

int main() {
    setlocale(LC_ALL, "");
    product prod;
    cout <<"Го пошаманим"<< endl;

    vector<product> arr;
    arr = prod.getInfo();
    cout<<"Данные из файла: "<<endl;
    prod.displayInfo(arr);

    vector<product> oneDay;
    oneDay = prod.doMagic(arr);
    prod.displayInfo(oneDay);
    //delete &arr;
    return 0;
}