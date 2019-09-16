/*Alexa Brown
 * CSC 112
 * Project 2
 * Given a random list of numbers, this program uses recursion and functions to complete the Merge Sort algorithm
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

    vector<int> leftVector(left1); //temporary vectors to help with merging
    vector<int> rightVector(right1);

    //used brackets instead of .at() because .at() was continuing to throw an error

    //putting parts of each side of the vector in to separate vectors
    for (i = 0; i < left1; i++) {
        leftVector[i] = a[left + i];
    }

    for (j = 0; j < right1; j++) {
        rightVector[j] = a[middle + j + 1];
    }

    i=0;
    j=0;
    //reset i and j to use again but differently

    //filling the left and right vectors with ascending numbers
    //aka sorting them
    for (k = left; (i < left1) && (j < right1); k++) {
        if (leftVector[i] < rightVector[j]) {
            a[k] = leftVector[i++];
        } else {
            a[k] = rightVector[j++];
        }
    }

    //filling in any leftover elements
    while (i < left1) {
        a[k++] = leftVector[i++];
    }
    while (j < right1) {
        a[k++] = rightVector[j++];
    }

} // end of mergeSortedLists function

void mergeSort(vector<int>& a, vector<int>& temp, int left, int right){

    int middle;

    //base case
    if (a.size() == 1){
        return;
    }

    //recursive case
    else if (left < right){
        middle = (left+right) /2;
        mergeSort(a, temp, left, middle);
        //recursion to sort and merge each part of the left
        mergeSort(a, temp, middle+1, right);
        //recursion to sort and merge each part of the right
        mergeSortedLists (a, temp, left, middle, right);
        //merging all the little parts of the sorted vector before sorting and merging the next parts again
    }

    return;
} //end of mergeSort function

int main() {

    vector<int> temp = {0,0,0,0,0};

    // get input: first is random seed, second is vector length
    int seed, length;

    //asked separately to ensure accuracy
    cout << " Please enter your seed number" << endl;
    cin >> seed;

    cout << " Please enter your vector length" << endl;
    cin >> length;
    srand(seed);

    // vector to be sorted
    vector<int> v(length);

    //filling in the random vector
    for(int i =0; i <v.size(); i++){
        v.at(i) = rand() % length + 1;
    }

    // initialize and print the original random list
    cout << "The original List is" << endl;
    for (int i= 0; i < length; i++) {
        cout << v.at(i) << " ";
    }

    //testing MergeSortedLists to ensure the vector is still the same size
    //want to make sure it stays the same size before calling mergeSort
    int middle = v.size() /2;
    mergeSortedLists(v,temp, 0, middle, length-1);
    assert(v.size() == length);

    // sort v
    mergeSort(v, temp, 0, length-1);

    cout << endl;
    cout << "The sorted list is: " << endl;

    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
          assert(v.at(i-1) <= v.at(i));
    }

    //end of program
    return 0;
}

