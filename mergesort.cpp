/*Alexa Brown
 * CSC 112
 * Project 2
 */


#include <iostream>
#include <vector>
using namespace std;
#include <cassert>

// function declarations
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

void mergeSort(vector<int>& a, vector<int>& temp, int left, int right){
    vector<int> temp2;
    int middle;

    if (a.size() == 1){
        return;
    }

    if (left < right){
        middle = (left+right) /2;
        mergeSort(a, temp, left, right);
        mergeSort(a, temp, middle+1, right);
        mergeSortedLists (a, temp, left, middle, right);
    }

       /* if(p<r)
        {
            q=(p+r)/2;
            MergeSort(A,p,q);
            MergeSort(A,q+1,r);
            Merge(A,p,q,r);
        }
    */
   /* if (a.size() == 1){
        return a;
    }

    for (int i = 0; i < a.size() /2; i++){ //left list
        int x = a.at(i);
        temp.at(i) = x;
        mergeSort(temp, temp2, left, right);
    }

    //mergeSort(temp, temp2, left, right);
*/
    return;
}
void mergeSortedLists(vector<int>& a, vector<int>& temp, int left, int middle, int right) {

   int i = 0;
   int j = 0;
   int k;

   vector <int> leftVector(left);
   vector <int> rightVector(right);

   for(i=0; i<left; i++){
       leftVector.at(i) = a.at(left+1);
   }
   for(j=0; j <right; j++){
       rightVector.at(j) = a.at(middle + j + 1);
   }

   for (int k = left; i<left && j<right; k++){
       if(leftVector.at(i) < rightVector.at(j)){
           a.at(k) = leftVector.at(i++);
       }
       else{
           a.at(k) = rightVector.at(j++);
       }
   }

   if(i<left){
       a.at(k++) = leftVector.at(i++);
   }
   else if(j<right){
       a.at(k++) = rightVector.at(j++);
   }


   /*for (k = left; i < left && i<right; k++){
       if(a.at(left) > a.at(right)){
           temp.at(left) = a.at(right);
           left++;
       }
       else{
           temp.at(left) = a.at(right);
           right++;
       }
   }
   while (i<left){
       temp.at(right) = a.at(left);
   }

   while(j<right){

   }*/

   /* if (left- 1 == middle){
        return;
    }

    if(a.at(left) == a.at(right)){
        return;
    }
if (left <= middle && a.at(left) < a.at(right)){
    temp.at(left) = a.at(left);
    left++;
}
else{
    temp.
}
    else if (a.at(left) > a.at(right)){
        temp.at(left) = a.at(right);
        left++;
    }
    else if (a.at(left) < a.at(right)){
        temp.at(left) = a.at(right);
        right++;
    }

    mergeSortedLists(a, temp, left, middle, right);
 
    */
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
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    /* your code here */
    cout << "Testing started" << endl;

    cout << "Expecting: ";
    for (int i = 0; i < v.size(); i++) {

        cout << v.at(i) << " ";
    }
    cout << endl;
    cout << "Got: ";
   mergeSortedLists(v, temp, 0, 0, 0);
    for (int i = 0; i < v.size(); i++) {

        cout << v.at(i) << " ";
    }
    cout << endl;

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */
    mergeSort(v, temp, 0,length - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
          assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

/* your code here */
