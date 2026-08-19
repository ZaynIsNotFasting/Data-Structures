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

};

int main(){
    MyString s1("Hey there Saiyan!");
    MyString s2 = s1;

    s2 = s2("Super Saiyan!!!!!!!");
    cout<<"\\n"<<endl;
    cout<<"After modification:"<<endl;
    s1.show();
    s2.show();




    return 0;
}