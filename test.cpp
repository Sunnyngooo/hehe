#include <iostream> 
using namespace std;

 int foo3(int*arr, int n, int x){
    int i1 =0, i2 = (n- 1),pos;
    while (i1 <=i2 && x >= arr[i1]&& x < arr[i2]) { 
        if (i1 ==i2) {
            if (arr[i1]== x) 
                return i1;
            return-1;
        }
        //Line 1
        pos = i1 + float(i2 - i1) * ((x - arr[i1]) / (arr[i2] - arr[i1]));
        if (arr[pos]== x) 
            return pos;
        if (arr[pos]< x) 
            i1 = pos + 1;
        else    
            i2 =pos- 1;
    }
    return-1;
 }
int main(){
    int arr[]{1,5,5,11,19,22,22,22,22,45,48,48,48};
    cout << foo3(arr, 13, 22);
    return 0; 
}