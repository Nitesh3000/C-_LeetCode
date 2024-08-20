#include <iostream>
using namespace std;
class Problem70{
    public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        int arr[2] = {1,2};
       
        
        for(int i = 3;i<=n;i++){
            int temp = arr[1];
            arr[1] = arr[1]+arr[0];
            arr[0]=temp;
        }
        return arr[1];
    }
};
int main(){
    Problem70 problem70;
    cout<<problem70.climbStairs(3)<<"\n";
}