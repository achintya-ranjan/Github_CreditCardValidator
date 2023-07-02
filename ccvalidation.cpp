#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool checkIfAllNum(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')           //checking if the input is correct or not
            return false;
    }
    return true;
}

int main() {
    string ccNum;
    //This program uses the Luhn Algorigthm to validate a credit card number.
    cout << "You can enter 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a CC number to validate: ";
        cin >> ccNum;
        if (ccNum == "exit")
            break;
        else if (checkIfAllNum(ccNum)==false) {
            cout << " Wrong Input "<<endl;
            continue;
        }
            
        int len = ccNum.length();
        int finalSum = 0;
        
        for (int i = len - 2; i >= 0; i = i - 2) {
            int rdigit = (((int)ccNum[i] - 48) * 2);      //doubling every second digit from right
            if (rdigit > 9) {
                rdigit = (rdigit / 10) + (rdigit % 10);           //bringing it into a single digit answer 
            }
            finalSum += rdigit;      //adding it to the final sum
        }
        
        // Step 2 is to add every odd placed digit from the right to the value
        
        for (int i = len - 1; i >= 0; i = i - 2) {
            finalSum += ((int)ccNum[i] - 48);   //adding all the remaining digits
        }
        
        cout << (finalSum % 10 == 0 ? "This number is valid" : "This number is invalid") << endl;     //Checking if the final sum is a multiple of 10 or not.
        cout<<"Do you want to check another credit card number ? Please enter yes or no."<<endl;
        string last; cin>>last;
        if(last=="yes")
        continue;      
        else
        break;  
    }
    cout<<endl<<"Thank you";

    return 0;
}
