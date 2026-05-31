#include <iostream>
using namespace std;
#include <vector>

// pair sum in sorted array


vector<int>finderrornums (vector<int>&nums){
for(int i=0;i<nums.size();i++){
if(nums[i]=!i+1 && nums[i]==i ){

  cout<<i<<", "<<(i+1)<<endl;
}

}


int main(){
vector<int>nums={1,2,2,4,5,6,7};
finderrornums(nums);
return 0;
}