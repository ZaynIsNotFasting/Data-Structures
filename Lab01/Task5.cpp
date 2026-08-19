#include "iostream"
#include <cstring>
using namespace std;
class Product {
    private:
        char *productName;
        int *quantity;

    public:
        Product() : productName(nullptr), quantity(nullptr) {}

        Product(const char* name, int q){
            int size = strlen(name);

            productName = new char[size + 1];

            for(int i = 0; i < size; i++){
                productName[i] = name[i];
            }

            productName[size] = '\0';

            quantity = new int;
            *quantity = q;
        }

        ~Product(){
            cout<<"Destruction from beerus"<<endl;
            delete[] productName;
            delete quantity;
        }

        Product(const Product& p){
            if(p.productName != nullptr){
                int size = strlen(p.productName);

                productName = new char[size + 1];

                for(int i = 0; i < size; i++){
                    productName[i] = p.productName[i];
                }

                productName[size] = '\0';
            }
            else{
                productName = nullptr;
            }

            if(p.quantity != nullptr){
                quantity = new int;
                *quantity = *(p.quantity);
            }
            else{
                quantity = nullptr;
            }
        }

        Product& operator=(const Product& p){
            if(this == &p){
                return *this;
            }

            delete[] productName;
            delete quantity;

            if(p.productName != nullptr){
                int size = strlen(p.productName);

                productName = new char[size + 1];

                for(int i = 0; i < size; i++){
                    productName[i] = p.productName[i];
                }

                productName[size] = '\0';
            }
            else{
                productName = nullptr;
            }

            if(p.quantity != nullptr){
                quantity = new int;
                *quantity = *(p.quantity);
            }
            else{
                quantity = nullptr;
            }

            return *this;
        }

        void show(){
            cout<<"Product Name: "<<productName<<endl;
            cout<<"Quantity: "<<*quantity<<endl;
        }

        void modifyQuantity(int q){
            *quantity = q;
        }
};

int main(){

    Product p1("Dragon Ball z ", 10);

    Product p2 = p1;

    cout<<endl;
    cout<<"Beforee:"<<endl;
    p1.show();
    p2.show();

    cout<<endl;
    cout<<"Modifying p2:"<<endl;
    p2.modifyQuantity(67);

    cout<<endl;
    cout<<"After:"<<endl;
    p1.show();
    p2.show();

    cout<<endl;

    return 0;
}