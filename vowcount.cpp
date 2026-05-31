#include <iostream>
#include<string>
using namespace std; 
 
// Question 1 : Count how many times lowercase vowels occurred in a String entered 
//by the user.


int main(){
  int vowcount=0;
  string str="seeing";
  for(int i=0;i<str.length();i++){
    
    if(str[i]=='a'|| str[i]=='e'||str[i]=='i'|| str[i]=='o'||str[i]=='u')

                     vowcount++;
    
    
  }
    cout<<vowcount;
      return vowcount;
}