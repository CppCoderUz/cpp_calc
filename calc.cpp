#include <bits/stdc++.h>
using namespace std;

// string tipidagi malumotni int tipiga otkazadi va double tipida yuboradi
double str_int(string a){
    double s = 0;
    for (int i = 0; i < a.size(); i++){
        s = s * 10 + int(a[i]) - 48;
    }
    return s;
}

string str_add_probel(string a){
    string b = "";
    if (a[0] == '-'){
        b += '0';
    }
    b += a;
    return b;
}


// string tipidagi malumotni double tipiga otkazadi. str_int funksiyasi
// bolmasa ishlamaydi
double str_double(string a){
    double x, y;
    string h = "", p = "";
    for (int i = 0; i < a.size(); i++){
        if (a[i] != '.'){
            h += a[i];
        }
        else goto qw;
    }
    qw:

    for (int i = h.size() + 1; i < a.size(); i++){
        p += a[i];
    }
    x = str_int(h);
    y = str_int(p);
    double rezault = x + y/pow(10, p.size());
    return rezault;
}

// faqat * va / amali qatnashgan misollarni yecha oladi
double str_nisbat(string a){
    vector <double> sonlar;
    vector <char> belgi;
    string x = "" ;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '*' or a[i] == '/'){
            sonlar.push_back(str_double(x));
            x = "";
        }
        else x += a[i];
    }
    sonlar.push_back(str_double(x));
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '*' or a[i] == '/'){
            belgi.push_back(a[i]);
        }
    }
    double rezault = sonlar[0];

    for (int i = 0; i < belgi.size(); i++){
        if (belgi[i] == '*'){
            rezault *= sonlar[i+1];
        }
        else rezault /= sonlar[i+1];
    }
    return rezault;
}

// Kalkulyator asosiy qism.
// Ustunliklari:
//     double tipidagi sonlar ustida amallarni bajara oladi.
//     ammalar ketma-ketligiga amal qiladi.

// Kamchiliklari:
//     qavslar kiritilsa xato beradi.
//     Errorlarni aniqlay olmaydi. Xato misol kiritilsa ham javob chiqaradi ammo xato
//     matematik funksiyalarga kuchi yetmaydi
//     va boshqalar ....

double str_eval(string a){
    string b = "";
    a = str_add_probel(a);
    vector <string>qism;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '+' or a[i] == '-'){
            qism.push_back(b);
            b = "";
        }
        else if (a[i] == ' '){
            continue;
        }
        else b += a[i];
    }
    qism.push_back(b);
    vector <char>belgi;
    for (int i = 0; i < a.size(); i++){
        if (a[i] == '+' or a[i] == '-'){
            belgi.push_back(a[i]);
        }
    }
    double d = str_nisbat(qism[0]);

    for (int i = 0; i < belgi.size(); i++){
        if (belgi[i] == '+'){
            d += str_nisbat(qism[i+1]);
        }
        else if (belgi[i] == '-'){
            d -= str_nisbat(qism[i+1]);
        }
    }
    return d;
}

int main(){
    cout << "12+5*9-6/3 = " << str_eval("12+5*9-6/3") << endl;
    cout << "17*4/5+8-3 = " << str_eval("17*4/5+8-3") << endl;
    cout << "13/7-7*3+5 = " << str_eval("13/7-7*3+5") << endl;
    return 0;
}
