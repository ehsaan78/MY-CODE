#include <iostream>
using namespace std;
#include <vector>
    // getting ith bit
 //int getbit(int num, int pos){
    /*int bitmask=1<<pos; // imptt point
    if (!(num & bitmask))  {    // == 0
       return 0;
    }  else {
       return 1;
    }       
 }

int main(){
      cout<<getbit(7,3)<<endl;
      cout<<getbit(6,2)<<endl;
      cout<<getbit(10,3)<<endl;
      return 0;
}


// set ith bit

int setithbit(int num,int pos){
    int bitmask=1<<pos;
    return (num|bitmask);
}
int main(){
cout<<setithbit(7,3)<<endl;
cout<<setithbit(8,3)<<endl;
cout<<setithbit(7,4)<<endl;
return 0;
}



// clear ith bit
int clearithbit(int num, int i){
   int mask=~(1<<i);
   return num & mask;
}
int main(){
     cout<<clearithbit(6,1)<<endl;
     cout<<clearithbit(6,2)<<endl;
     cout<<clearithbit(6,3)<<endl;
     cout<<clearithbit(6,0)<<endl;
     return 0;
}

// power of two

int poweroftwo(int num){
    if ((num &  num-1)==0){
      cout<<num <<" is power of 2"<<endl;
    }else{
      cout<<num<<" not power of 2"<<endl;
    }
}
int main(){

poweroftwo(8);
poweroftwo(7);
poweroftwo(2);

}

// check for power of 2

bool ispowof2(int num){
   if ((num & num-1)==0){
      return true;
   }else {
      return false;
   }
}

int main(){
cout<<ispowof2(8);
return 0;
}


// clear and set ith bit using a single function
int updateithbit(int num,int i, int val){
  num=num & ~(1<<i);     // clear ith bit
  num=num|(val<<i);         //  update ith bit by the val
  return num;
}


int main(){
   cout<<updateithbit(7,3,1);
   return 0;
}


// clear i bits

int clearibits(int num, int i){

  

   return num &( ~0<<i);;
}



int main(){
   cout<<clearibits(15,2)<<endl;
   cout<<clearibits(13,3)<<endl;
   cout<<clearibits(15,4)<<endl;
   cout<<clearibits(16,2)<<endl;

   return 0;
}



//  count set bits

void countsetbits(int num){
   int count=0;
   while(num>0){
    int lastdig=(num & 1);
    count+=lastdig;
    num=num>>1;
   }
cout<<count<<endl;

}


int main(){
   countsetbits(10);  
   countsetbits(7);  
   return 0;

}