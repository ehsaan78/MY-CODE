#include <iostream>
using namespace std;

void mat(int arr[][3],int n,int m){

             int scol=0,srow=0;
             int erow=n-1,ecol=m-1;


             while(srow<=erow && scol<=ecol){

              // top

              for (int j=scol;j<=ecol;j++){
                            cout<<arr[srow][j]<<" ";
              }

              // right

              for(int i=srow+1;i<=erow;i++){
                                cout<<arr[i][ecol]<<" ";
              }


               // bottom

               for(int j=ecol-1;j>=scol;j--){
            if(srow==erow){
                break;
            }

                          cout<<arr[erow][j]<<" ";

               }

               // left

               for(int i=erow-1;i>=srow+1;i--){
 if(ecol==scol){
                break;
            }
                            cout<<arr[i][scol]<<" ";

               }
               srow++,scol++;
               erow--,ecol--;

}



}


int main(){

   int arr [4][3]={{1,2,3},
                     {4,5,6},
                       {7,8,9},
                     {10,11,12}  };
            mat(arr,4,3);
return 0;

}