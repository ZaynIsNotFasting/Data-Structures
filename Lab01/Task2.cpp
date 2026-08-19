#include "iostream"
using namespace std;

void minMax(int arr[],int *min, int *max){
    int size = 7;
    *min = arr[0];
    *max = arr[0];

    for(int i = 1; i< size; ++i){
        if(arr[i]<*min){
            *min = arr[i];
        }
        if(arr[i]>*max){
            *max = arr[i];
        }
    }
    cout<<"Max element of the array: "<<*max<<endl;
    cout<<"Min element of the array: "<<*min<<endl;


}

int main(){
    int arr[7] = {25, 10, 45, 5, 30, 60, 15};

    int min, max;

    minMax(arr, &min, &max);
    return 0;
}