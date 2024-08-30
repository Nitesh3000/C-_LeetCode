#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Problem217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int num:nums){
            auto it = s.find(num);
            if(it == s.end()){
                s.insert(num);
            }
            else{
                return true;
            }
        }
        return false;
    }
   
};
 int main(){
        Problem217 problem217;
        vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
        cout<<problem217.containsDuplicate(nums)<<"\n";
        return 0;
    }