#include <iostream>
using namespace std;

  //   TIME COMPLEXITY= O(N^2)

/*int sumofdiag(int arr[][4],int n ){

                 int sum=0;
          for(int i=0;i<n;i++){
            
               for(int j=0;j<n;j++){
                    
                     if (i==j){               // PRIMARY DIAGONAL CONDITION
                      sum+=arr[i][j];
                                  
                   } else if(j=n-i-1){         //sec diag condition
                     sum+=arr[i][j];
                   }
                }
             }
       cout<<"sum="<<sum<<endl;
          return sum;
                         } */

 // TC =0(N)
int sumofdiag(int arr[][4],int n){

          int sum=0;
          for(int i=0;i<n;i++){
                 sum+=arr[i][i];  // pd
                 if(i!=n-i-1){    // sd
                  sum+=arr[i][n-i-1];
                 }
             }
cout<<sum<<endl;
return sum;}

int main(){
int arr[4][4]={{1,2,3,4},
              {5,6,7,8},
                {9,10,11,12},
                  {13,14,15,16}};

  sumofdiag(arr,4);
return 0;
}