/*Alexa Brown
 * CSC 112
 * Project 2
 */


#include <iostream>
#include <vector>
using namespace std;
#include <cassert>

// function declarations
void mergeSortedLists(vector<int>& a, vector<int>& temp, int left, int middle, int right) {

    int i, j, k;

    int left1 = middle - left + 1; //size of left vector
    int right1 = right - middle; //size of right vector

    vector<int> leftVector(left1);
    vector<int> rightVector(right1);

    //used brackets instead of .at() because .at() was continuing to throw an error
    for (i = 0; i < left1; i++) {
        leftVector[i] = a[left + i];
    }
    for (j = 0; j < right1; j++) {
        rightVector[j] = a[middle + j + 1];
    }
    i=0;
    j=0;
    //reset i and j

    for (k = left; (i < left1) && (j < right1); k++) {
        if (leftVector[i] < rightVector[j]) {
            a[k] = leftVector[i++];
        } else {
            a[k] = rightVector[j++];
        }
    }

    while (i < left1) {
        a[k++] = leftVector[i++];
    }
    while (j < right1) {
        a[k++] = rightVector[j++];
    }


    /*for (int m = 0; m < a.size(); m++){
        a[m] = temp[m];
    }*/


}



void mergeSort(vector<int>& a, vector<int>& temp, int left, int right){
    int middle;

    if (a.size() == 1){
        return;
    }

    else if (left < right){
        middle = (left+right) /2;
        mergeSort(a, temp, left, middle);
        mergeSort(a, temp, middle+1, right);
        mergeSortedLists (a, temp, left, middle, right);
    }

    return;
}

int main() {


    vector<int> temp = {0,0,0,0,0};
    // get input: first is random seed, second is vector length
    int seed, length;
    cout << " Please enter your seed number" << endl;
    cin >> seed;

    cout << " Please enter your vector length" << endl;
    cin >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    //vector<int> t(length);  // temporary workspace

    for(int i =0; i <v.size(); i++){
        v.at(i) = rand() % length + 1;
    }

    cout << "The original List is" << endl;
    for (int i= 0; i < length; i++) {
        cout << v.at(i) << " ";
    }

    mergeSort(v, temp, 0, length-1);

  /*  for(int i =0; i <v.size(); i++){
        v.at(i) = rand() % length + 1;
    }*/

    // unit test for merge
    /* your code here */
   /* cout << "Testing started" << endl;

    cout << "Expecting: ";
    for (int i = 0; i < v.size(); i++) {

        cout << v.at(i) << " ";
    }
    */
    cout << endl;
    cout << "Got: ";

    for (int i = 0; i < v.size(); i++) {

        cout << v.at(i) << " ";
    }
    cout << endl;

    // initialize and print input
 /*   for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;*/

    // sort v
  /*  mergeSort(v, temp, 0,length - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
          assert(v.at(i-1) <= v.at(i));
    }*/

    return 0;
}

