#include "iostream"
#include <cstring>
using namespace std;

class MyString {
    private:
        char *str;
        int size;
    public:
        MyString() : str(nullptr), size(0) {}
        MyString(const char* s){
            size = strlen(s);
            str = new char[size+1];
            for(int i = 0; i < size; i++){
                str[i] = s[i];
            }
            str[size] = '\0'
        }
        
        ~MyString(){
            cout<<"Destruction from beerus"<<endl;
            delete[] str;
        }
        
        MyString(const MyString& s){
            size = s.size;
            if(s.str != nullptr){
                str = new char[size+1];
                for(int i = 0; i < size; i++){
                    str[i] = s.str[i];  
                }
                str[size] = '\0';
            }else{
                str = nullptr;
            }
        }

        MyString& operator=(const MyString& s){
            if(this == &s){
                return *this;
            }

            delete[] str;

            size = s.size;
            if(s.str != nullptr){
                str = new char[size+1];
                for(int i = 0; i < size; i++){
                    str[i] = s.str[i];
                }
                str[size] = '\0';
            }else{
                str = nullptr;
            }
            return *this;
        }

        void show(){
            cout<<"Your string is: "<<str<<endl;
        }

        void modifyString(const char* s){
            delete[] str;

            size = strlen(s);

            str = new char[size+1];
            for(int i = 0; i < size; i++){
                str[i] = s[i];
            }
            str[size] = '\0';
        }

};

int main(){
    MyString s1("Hey there Saiyan!");
    MyString s2 = s1;
    cout<<endl;
    cout<<"Beforee:"<<endl;
    s1.show();
    s2.show();
    cout<<endl;
    cout<<"Modifying s2:"<<endl;
    s2.modifyString("Super Saiyan!!!!!!");
    cout<<endl;
    cout<<"After:"<<endl;
    s1.show();
    s2.show();




    return 0;
}