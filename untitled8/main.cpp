#include <iostream>
using namespace std;
#define str string
class Student{
    str fam;
    str ism;
    str adress;
public:
    void setM(str ism,str fam,str adress){
        this->ism=ism;
        this->fam=fam;
        this->adress=adress;
    }
    void getfam(){
        str fam=this->fam;
        int l=fam.size();
        if(fam[l-1]=='a')
            cout<<"Salom,Qizlar guruhiga Xush kelibsiz";
        else
            cout<<"Salom,Yigitlar guruhiga Xush kelibsiz";
        cout<<'\n';
    }
};

int main()
{
    Student obj;
    str ism,fam,adr;
    cin>>ism>>fam>>adr;
    obj.setM(ism,fam,adr);
    obj.getfam();
    system("pause");
    return 0;
}
