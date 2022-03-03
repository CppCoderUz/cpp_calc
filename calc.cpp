#include <bits/stdc++.h>
using namespace std;

class eval{
public:
    string text;
    double number;
    void inf(){cout << "Ushbu classdan foydalanish uchun quyidagi 2 ta buyruqdan foydalanishingiz mumkin: eval.sin() str tipida malumotni kirittadi, eval.rezault() natijani biron ozgaruvchiga taminlaydi.(double bolsa maqulroq)";}
    string Clear(char a[]){int k=strlen(a);string b="";for(int i=0;i<k;i++){if(a[i]!=' '){b+=a[i];}}return b;}
    string Clear(string a){string b="";for(int i=0;i<a.size();i++){if(a[i]!=' '){b+=a[i];}}return b;}
    string addProbel(string h){string b="0";if(h[0]=='-'){for(int i=0;i<h.size();i++){b+=h[i];}}else{b=h;}string& a=b;a+=' ';return a;}
    double fragment(string a_kb){a_kb=Clear(a_kb);string h="";int k=0;vector<double>sonlar;for(int i=0;i<a_kb.size();i++){if(a_kb[i]=='*' or a_kb[i]=='/'){sonlar.push_back(k);k=0;}else{k=k*10+int(a_kb[i])-48;}}sonlar.push_back(k);k=0;vector<char>belgi;for(int i=0;i<a_kb.size();i++){if(a_kb[i]=='*' or a_kb[i]=='/'){belgi.push_back(a_kb[i]);k++;}}double s=sonlar[0];for(int i=0;i<k;i++){if(belgi[i]=='*'){s*=sonlar[i+1];}else{s/=sonlar[i+1];}}return s;}
    double rezault(){string a=text;a=addProbel(a);string kl="";int k=0;vector<string>Qism;vector<char>belgi;for(int i=0;i<a.size();i++){if(a[i]=='+' or a[i]=='-'){belgi.push_back(a[i]);k++;}}for(int i=0;i<a.size();i++){if(a[i]=='+' or a[i]=='-'){Qism.push_back(kl);kl="";}else{kl+=a[i];}}Qism.push_back(kl);double s=fragment(Qism[0]);for(int i=0;i<k;i++){if(belgi[i]=='-'){s-=fragment(Qism[i+1]);}else if(belgi[i]=='+'){s+=fragment(Qism[i+1]);}}return s;}
    void sin(){cin>>text;}
};
