#include "iostream"
using namespace std;

int main(){
    int num;
    while(true){
        cout<<"Enter a positive integer. (or -1 if you want to exit the programmm)"<<endl;
        cin>>num;
        if(num == -1){
            cout<<"You exited!"<<endl;
            break;
        }

        if(num <= 0){
            cout<<"Error. Please enter a positive value kindly ;)"<<endl;
            continue;
        }

        int sum = 0;
        for(int i = 1; i<num/2; i++){
            if(num % i == 0){
                sum += i;
                cout<<i<<endl;
            }
        }
        sum += num;
        cout<<num<<endl;
        cout<<"Sum is: "<<sum<<endl;
    }
}