//There are global recursive function about math
/*
*binary()
*factorial()
*power()
*writeVertical()
*/
#include<iostream>
using namespace std;

//Recursive function that finds binary equivalance of the numbers
//Pre: takes and integer as parameter
//Post: prints the binary equivalance of the parameter
void binary(int number){
    if(number == 1)
        cout << 1;
    else{
        binary(number/2);
        cout << number % 2;
    }
}

//Global recursive factorial function that calculates and returns the factorial of
//a number recursively
//Pre: Takes an integer as an argument
//Post: Returns factorial of this integer
int factorial(int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return n;
    else
        return n * factorial(n-1);
}

//Global recursive power function that calculates and returns power of an integer
//Pre: Takes two integer parameter, base and power
//Post: Returns power of first integer
int power(int base, int x){
    if(x <= 0)
        return 1;
    else
        return base * power(base, x - 1);
}

//Global recursive function that prints digits of the parameters to the screen from
//last to first
//Pre: Takes a number as argument
//Post: Prints digits of this argument to the screen
void writeVertical(int number){
    if(number < 10)
        cout << number << endl;
    else{
        writeVertical(number/10);
        cout << number%10 << endl;
    }
}

int main(int argc, char const *argv[]) {
    cout << "***Recursive Integer-Binary Converter: binary(int number)***\n";
    cout << "12: ";
    binary(12);
    cout << endl;
    cout << "***END***\n\n";

    cout << "***Recursive Factorial: factorial(int n)***\n";
    cout << factorial(4) << endl;
    cout << "***END***\n\n";


    cout << "***Recursive Power: power(int base, int x)***\n";
    cout << power(2, 3) << endl;
    cout << "***END***\n\n";

    cout << "***Recursive writeVertical(int number)***\n";
    writeVertical(161044);
    cout << "***END***\n\n";

    return 0;
}
