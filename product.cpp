#include "product.h"

product::product(string day, int supplied, int sold, string name)
    {
        this->day = day;
        this->supplied = supplied;
        this->sold = sold;
        this->name = name;
    }

int product::getSold() {
    return this->sold;
}

int product::getSuppl() {
    return this->supplied;
}

string product::getName() {
    return this->name;
}

string product::getDay() {
    return this->day;
}

//read info from file and form our product
//TODO all strings to lowercase
vector<product> product::getInfo(const char* filename) {
    vector<product> container;
    string headers[1];
    ifstream f;
    f.open(filename);
    int i = 0;
    while(!f.eof() && f.good()) {
        if(i!=0) {
            //cout<< i<< endl;
            string productS;
            product prod;
            getline(f, productS);
            productS.erase(remove(productS.begin(), productS.end(), '\t'), productS.end()); // remove tabs
            productS.erase(remove(productS.begin(), productS.end(), ' '), productS.end()); // remove whitespaces
            size_t pos = 0;
            string token;
            string delimiter = ";";
            int j = 0;
            while ((pos = productS.find(delimiter)) != string::npos) {
                token = productS.substr(0, pos);
                productS.erase(0, pos + delimiter.length());
                switch (j) {
                    case 0: {
                        /*for (string::size_type k=0; k<token.length(); ++k){
                            token[k] =  std::tolower(token[k], std::locale(""));
                        }*/
                        prod.name = token;
                        break;
                        }
                    case 1: {
                        /*for (string::size_type k=0; k<token.length(); ++k){
                            token[k] = tolower(token[k]);
                        }*/
                        prod.day = token;
                        break;
                        }
                    case 2 : {
                        prod.supplied = atoi(token.c_str());
                        break;
                        }
                    }
                    j++;
                }
            prod.sold = atoi(productS.c_str());
            container.insert(container.end(),prod);
        } else {
            string header;
            getline(f, header);
            header.erase(remove(header.begin(), header.end(), '\t'), header.end()); // remove tabs
            header.erase(remove(header.begin(), header.end(), ' '), header.end()); // remove whitespaces
            headers[0] = header;
            cout<<"наши поля: "<< headers[0] << endl;
        }
        i++;
    }
    f.close();
    return container;
}


//display our info on srceen
void product::displayInfo(vector<product> arr) {
    cout <<""<<endl<< "Товар || " << "День недели || " << "Поступление || " << "Продажа ||" << endl;
    for(int i =0; i<arr.size(); i++) {
        string name = arr[i].getName();
        string day = arr[i].getDay();
        int suppl = arr[i].getSuppl();
        int sold = arr[i].getSold();
        cout << name << " || " << day << " || " << suppl << " || " << sold <<  " ||" << endl;
    }
}

//count all products sold on one day
vector<product> product::doMagic(vector<product> arr) {
    vector<product> result;
    string a;
    cout<< "Введите день продажи (Понедельник,Вторник,Среда,Четверг,Пятница,Суббота,Воскресенье): "<<endl;
    int sum =0;
    do {
        cin>> a;
        if (a!="Понедельник"&&a!="Вторник"&&a!="Среда"&&a!="Четверг"&&a!="Пятница"&& a!="Суббота" && a!="Воскресенье") {
            cout<< "Введите день продажи корректно(Понедельник,Вторник,Среда,Четверг,Пятница,Суббота,Воскресенье): "<<endl;
        }
    } while (a!="Понедельник"&&a!="Вторник"&&a!="Среда"&&a!="Четверг"&&a!="Пятница"&& a!="Суббота" && a!="Воскресенье");
    for (int i=0; i< arr.size(); i++) {
        string day = arr[i].getDay();
        int sold = arr[i].getSold();
        if (day == a && sold != 0) {
            result.insert(result.end(),arr[i]);
        }
    }
    return result;
}

void product::writeInfoToFile(const char* filename, vector<product> arr) {
    fstream f;
    f.open(filename, fstream::out);

    for (int i=0; i<arr.size(); i++){
        f <<"Название товара:"<< arr[i].getName() <<" День недели:"<< arr[i].getDay() <<" Кол-во поступлений:"<< arr[i].getSuppl() <<" Кол-во продаж:"<< arr[i].getSold() << "\n";
    }
    f.close();
}
