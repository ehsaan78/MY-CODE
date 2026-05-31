#include <iostream>
using namespace std;

bool canBeEqual(string s1, string s2) {
    int count = 0;
    int i1, i2 ;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            count++;

            if (count == 1)
                i1 = i;
            else if (count == 2)
                i2 = i;
            else{
            cout<<"false";
                return false;} // more than 2 mismatches
               
        }
    }

    // Case 1: already equal
    if (count == 0){
        
        return true;
    }
    
        ;;
    // Case 2: exactly 2 mismatches
    if (count == 2) {
        if (s1[i1] == s2[i2] && s1[i2] == s2[i1]){

          return true;
          
        }
    }

    return false;
    
}

int main() {
    string s1 = "cout";
    string s2 = "ocut";
if(canBeEqual(s1, s2)){
    cout<<"false";
}
else{
    cout<<"false";
}

    return 0;
}