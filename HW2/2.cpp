#include <iostream>

using namespace std;

void swap(char cstr[],int cstr_size); //reverses the c-string's contents
int countCstrSize(char c[]);


int main() {
    //for testing purposes
    char word[] = {"Los Angeles"}; //change word to test
    int cstr_size = countCstrSize(word);

    for(int index = 0; index < cstr_size; index++) {
        cout << word[index];
    }
    cout << endl;

    swap(word, cstr_size); //function call

    //TESTING
    for(int index = 0; index < cstr_size; index++) {
        cout << word[index];
    }
    cout << endl;

    return 0;
}

void swap(char cstr[], int cstr_size) {
    char *head, *tail;
    char dummy = '\0';

    for(int index = 0; index < (cstr_size/2); index++) {

        head = &cstr[index];
        tail = &cstr[cstr_size - index - 1];
        dummy = *tail;
        *tail = *head;
        *head = dummy;
    }
    cout << endl;
}

int countCstrSize(char c[]) {
    int counter = 0;
    while(c[counter] != '\0') {
        counter++;
    }
    return counter;
}
