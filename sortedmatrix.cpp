#include <iostream>
using namespace std; 

// staircase method

//   TIME COMPLEXITY= (n+m)

void search(int arr[][4],int n, int m,int key){
            int i=n-1,j=0;

          while(i>=0 && j<m) {

if(key==arr[i][j]){
     cout<<"key found at ("<<i<<","<<j<<")"<<endl;
     return;

      }else if(key<arr[i][j]){
       //left
          i--;}

          else{
                 // down
                 j++;

          }


          }
          cout<<"key not found"<<endl;
}


int main(){

  int arr[4][4]={{10,20,30,40},
                  {15,25,35,45},
                  {27,29,37,48},
                  {32,33,39,50}}  ;

search(arr,4,4,20);



}