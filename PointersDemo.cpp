#include <iostream>
#include <ctime>
using namespace std;

//Duplicates the contents of a dynamic array
int* duplicate(int *array, int size){
    int *newArray = new int[size * 2];
    for(int i = 0; i < size; i++){
        newArray[i * 2] = array[i];
        newArray[i * 2 + 1] = array[i];
    }
    return newArray;
}

//Generates a dynamic array of n random integers between 1 and 100
int* generate(unsigned int n){
    srand(time(0));
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100 + 1;
    }
    return array;
}

//Displays the contents of a dynamic array. Only 8 integers per line
void display(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
        if((i + 1) % 8 == 0){
            cout << endl;
        }
    }
    cout << endl;
}

int main(){
    //Get the size of the original dynamic array
    int size;
    cout << "What size would you like your original dynamic array to be? ";
    cin >> size;
    while(size < 1){
        cout << "Please enter a positive integer: ";
        cin >> size;
    }

    //Create two dynamic arrays
    int *arrayOrig = new int[size];
    int *arrayDup = new int[size * 2];

    //Use functions
    arrayOrig = generate(size);
    cout << "Printing the original array: " << endl;
    display(arrayOrig, size);
    cout << endl;

    arrayDup = duplicate(arrayOrig, size);
    cout << "Printing the duplicated array: " << endl;
    display(arrayDup, size * 2);

    //Delete the dynamic arrays
    delete[] arrayOrig;
    delete[] arrayDup;

    return 0;
}