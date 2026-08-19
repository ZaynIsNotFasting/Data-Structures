#include "iostream"
using namespace std;

class Numbers{
    private:
        size_t size;
        int *data;
    public:
        Numbers() : size(0), data(nullptr){}

        void assignValue(const int *values, size_t s){
            size = s;
            delete[] data;

            if(size > 0 && values != nullptr){
                data = new int[size];
                for(size_t i = 0; i < size; i++){
                    data[i] = values[i];
                }
            }else{
                data = nullptr;
            }
        }

        ~Numbers(){
            cout<<"Destroyed memory at address: "<<*data<<endl;
            delete[] data;
        }
        // we can observe the shallow/deep copy here
        // if we use shallow copy, then both objects will point to the same memory location
        // and when one object is destroyed, the other object will also be destroyed
        // which will lead to a double free error
        //and if we use deep copy, then they have no relation to each other so the memory is safe 
        Numbers(const Numbers& n){
            size = n.size;
            if(n.data != nullptr){
                data = new int[size];
                for(size_t i = 0; i < size; i++){

                    data[i] = n.data[i];
                }
            }else{
                data = nullptr;
            }
        }

        Numbers& operator=(const Numbers& n){
            if(this ==  &n){
                return *this;
            }

            delete[] data;

            size = n.size;
            if(n.data != nullptr){
                data = new int[size];
                for(size_t i = 0; i < size; i++){
                    data[i] = n.data[i];
                }
            }else{
                data = nullptr;
            }
            return *this;
        }

        void print(const string& name) const{
            cout<<name<<" (Size: "<<size<<" Internal array address: "<<*data<<") ";
            if(data != nullptr && size > 0){
                for(size_t i = 0; i < size; i++){
                    cout<<data[i]<<" ";
                }
                
            }else{
                cout<<"Empty"<<endl;
            }
            cout<<endl;
        }

        void modifyValue(size_t index, int value){
            if(index < size && data != nullptr){
                data[index] = value;
                cout<<"New value at index: "<< index<< " is: "<<data[index]<<endl;
            }
            else{
                cout<<"Errorrrr!"<<endl;
            }
        }
};

int main(){
    int initData[] = {11, 22, 33};
    
    Numbers n1;
    n1.assignValue(initData, 3);
    n1.print("n1");
    n1.modifyValue(1, 99);
    n1.print("n1");

    Numbers n2;
    n2 = n1;
    n2.print("n2");

    Numbers n3;
    n3 = n1;
    n3.print("n3");

    cout<<"\n--- Modifying n3[0] ---\n";
    n3.modifyValue(0, -500);
    n3.print("n3 after modification");

    cout<<"\n--- Printing all objects again ---\n";
    n1.print("n1");
    n2.print("n2");
    n3.print("n3");

    cout<<"Exiting scope..";

    return 0;  
}