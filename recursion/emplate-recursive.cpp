//There are template recursive global function examples
/*
*average()
*greatest()
*common()
*find()
*duplicate()
*/
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//Global template function that calculates and return average of a template vector
//Pre: takes 3 parameters template vector, index of vector and ans for summation
//Post: returns average of this vector
template<class T>
T average(vector<T> array, int index, T ans){
    //base case of the recursion
    if(array.size() == index){
        return ans / array.size();
    }
    else{
        return average(array, index+1, ans + array[index]);
    }
}//ends function



//Global template recursive function that finds and returns greatest element of an array
//Pre: Takes template array, array size and default greatest number as parameters
//Post: Returns the greatest number of this array
template<class T>
T greatest(T array[], int size, T great){
    if(size - 1 == 0)
        return great;
    else{
        if(array[size - 1] > great)
            great = array[size - 1];
        greatest(array, size - 1, great);
    }
}

//Global template recursive function that finds common elements of two arrays then returns them
//as array
//Pre:
//Post
//CANNOT DO
template<class T>
vector<T> common(T array1[], T array2[], int size1, int size2, int i, int j, vector<T> temp){
    if(i == size1 - 1 && j == size2)
        return temp;
    if(array1[i] == array2[j])
        temp.push_back(array1[i]);
    if(size1 - 1 == i){
        i = 0;
        j += 1;
    }
    return common(array1, array2, size1, size2, i+1, j, temp);
}

//Global template recursive function that finds searching element in a vector
//Pre: Takes template vector, wanted element and index iterator
//Post: Returns true if there is, false there is not
template<class T>
bool find(vector<T> array, T param, int index){
    if(index == array.size())
        return false;
    else{
        if(array[index] == param)
            return true;
        else
            return find(array, param, index + 1);
    }
}

//Global template recursive function that returns duplicate element in vector
//Pre: Takes template vector return vector and index as argument
//Post: Return duplicate elements vector
template<class T>
vector<T> duplicate(vector<T> array, vector<T> newVect, int index){
    if(index == array.size())
        return newVect;
    else{
        if(find(array, array[index], index + 1))
            newVect.push_back(array[index]);
        return duplicate(array, newVect, index+1);
    }
}

int main(int argc, char const *argv[]) {

    cout << "***Recursive Template Vector: average(vector<T> array, int index, ans + array[index])***\n";
    vector<int> array;
    array.push_back(2);
    array.push_back(2);
    array.push_back(4);
    array.push_back(6);
    array.push_back(6);
    cout << "Average of 2 4 6: " << average(array, 0, 0) << endl;
    cout << "***END***\n\n";

    cout << "***Recursive Template Greatest Finder: greatest(T array[], int index, T great)***\n";
    char array2[] = {'a', 'z', 'x', 'd', 'b'};
    cout << greatest(array2, 5, array2[0]) << endl;
    cout << "***END***\n\n";

    /*
    vector<int> vect;
    int temp1[] = {0, 2, 7, 13};
    int temp2[] = {2, 1, 4, 7};
    vect = common(temp1, temp2, 4, 4, 0, 0, vect);
    cout << vect[1] << endl; */

    cout << "***Recursive Template Find Element: find(T array[], T param, int index)***\n";
    cout << find(array, 12, 0) << endl;
    cout << find(array, 4, 0) << endl;
    cout << "***END***\n\n";

    cout << "***Recursive Template Duplicate: duplicate(vector<T> array, int index)***\n";
    vector<int> temp2;
    cout << duplicate(array, temp2, 0)[0] << " ";
    cout << duplicate(array, temp2, 0)[1] << endl;
    cout << "***END***\n\n";

    return 0;
}
