#include <bits/stdc++.h>
using namespace std;
int main(){
    char str[20000];
    char b[27]="efghijklmnopqrstuvwxyzabcd";
    char B[27]="EFGHIJKLMNOPQRSTUVWXYZABCD";
    cin.getline(str,20000);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            int d=int(str[i])-65;
            cout<<B[d];
        }
        else if(str[i]>='a'&&str[i]<='z'){
            int d=int(str[i])-97;
            cout<<b[d];
        }
        else cout<<str[i];
    }
}
