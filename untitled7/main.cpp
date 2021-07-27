#include <iostream>
using namespace std;
#define ll long long
class Davlat{
    string nomi;
    string poytaxti;
    ll aholi_soni;
public:
    void setGov(string nomi,string poytaxti,ll aholi_soni){
        this->nomi=nomi;
        this->poytaxti=poytaxti;
        this->aholi_soni=aholi_soni;
    }
    void getGov(){
        cout<<"nomi="<<this->nomi<<'\n';
        cout<<"poytaxti="<<this->poytaxti<<'\n';
        cout<<"aholi soni="<<this->aholi_soni<<'\n';
    }
};

int main()
{
    Davlat obj;
    string nomi,poytaxti;
    ll aholi_soni;
    cin>>nomi>>poytaxti>>aholi_soni;
    obj.setGov(nomi,poytaxti,aholi_soni);
    obj.getGov();
    system("pause");
    return 0;
}
