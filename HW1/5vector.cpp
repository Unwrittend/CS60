#include <iostream>
#include <vector>

using namespace std;

//func declaration
void calculations(vector<int> vect, int suitors);

int main() {

    vector<int>place;
    int suitors;

    //intialization
    cout << "Input Number of suitors: ";
    cin >> suitors;
    for (int i = 1; i <= suitors; i++) {
        place.push_back(i);
    }
      
    //calculations
    calculations(place, suitors);

}

void calculations(vector<int>vect, int suitors) {

    vector<int>::iterator iter = vect.begin(); //initialization
    while(vect.size() > 1) {

        for(int i = 0; i < 3; i++) {
            i=i;

            if(i == 2) {
                if(iter == vect.end()-1) { //if at end remove last suitor and begin again at beginning
                    vect.erase(vect.end()-1); //end returns past-the-end iterator and need the end iterator
                    iter = vect.begin();
                }
                else { //else just erase
                    vect.erase(iter);
                }
            }


            else if (iter == vect.end()-1) { //if end restart at beginning (this acts as an iter++)
                iter = vect.begin();
            }
            else {
                iter++;
            }
        }
        cout << "Suitors left: ";
        for (int i = 0; i < vect.size(); i++) {
            cout << vect.at(i);
        }
        cout << endl;
    }

}
