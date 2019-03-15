#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Zip_code {
public:
    Zip_code(int code);
    Zip_code(string zip);
    int getInt();
    string getString();

private:
    int zip;

};

int main(){
    Zip_code z1(92610);
    cout << z1.getInt() << endl;
    cout << z1.getString() << endl;
    Zip_code z2("110100101000101011000010011");
    cout << z2.getInt() << endl;
    cout << z2.getString() << endl;


    return 0;
}

Zip_code::Zip_code(int code){
    zip = code;
}

Zip_code::Zip_code(string code){
    zip = 0;
    int counter = 0;
    for(int i = 1; i < 26; i += 5) {
        //start at 1 to skip 1 at beginning of barcode and less than 27 to avoid 1 at end
        //i+5 to iterate in intervals of 5
        int digit = 0;
        for(int j = i; j < i+5; j++) { //takes a chunk of five
            if(j == i) {
                if(code.at(j) == '1')
                    digit += 7;
            }
            else if (j == i+1) {
                if(code.at(j) == '1')
                    digit += 4;
            }
            else if (j == i+2) {
                if(code.at(j) == '1')
                    digit += 2;
            }
            else if (j == i+3) {
                if(code.at(j) == '1')
                    digit += 1;
            }
            else if (j == i+4) {
                if(code.at(j) == '1')
                    digit += 0;
            }
            else {
                digit = -1;
            }
            if (digit == 11)
                digit = 0;
        }
        counter++;
        zip += digit * pow(10,5-counter); //eash iteration gets the next digit of the zip code
    }
}


int Zip_code:: getInt() {
    return zip;
}

string Zip_code:: getString(){
    string code = "";
    code += "1";
    int cleanUpVariable = zip;

    for(int i = 0; i < 5; i++){
        int leaveOnlyHighestDigit = cleanUpVariable % static_cast<int>(pow(10,4-i));
        int removeExtraDigits = pow(10,4-i);
        int digit = ((cleanUpVariable - (leaveOnlyHighestDigit)) / removeExtraDigits);
        if(digit == 0){
            code += "11000";
        }
        else if(digit == 1){
            code += "00011";
        }
        else if(digit == 2){
            code += "00101";
        }
        else if(digit == 3){
            code += "00110";
        }
        else if(digit == 4){
            code += "01001";
        }
        else if(digit == 5){
            code += "01010";
        }
        else if(digit == 6){
            code += "01100";
        }
        else if(digit == 7){
            code += "10001";
        }
        else if(digit == 8){
            code += "10010";
        }
        else if(digit == 9){
            code += "10100";
        }
        /*else
            code = "-1";*/
        cleanUpVariable -= pow(10,4-i) * digit;
    }
    code += "1";
    return code;
}
