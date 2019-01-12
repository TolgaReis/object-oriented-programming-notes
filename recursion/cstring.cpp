//There are global recursive C type string functions
/*
*strcpy()
*strncpy()
*strcat()
*strlen()
*strstr()
*strcmp()
*/
#include<iostream>
using namespace std;

//Global recursive strcpy function that copies second parameter to first parameter
//Pre: takes two character array as argument that second one is const
//Post: first character array is equal to second character array
void strcpy(char* str, const char* rightStr){
    if(*rightStr == '\0')
        *str = '\0';
    else{
        *str = *rightStr;
        strcpy(str+1, rightStr+1);
    }
}

//Global recursive strncpy function that copies n characters from second parameter
//to the first parameter
//Pre: Takes three parameters, new character array, copied character array, character numbers
//Post: first character array has first characters of the second parameter
void strncpy(char* str, const char* rightStr, int n){
    if(n == 0)
        *str = '\0';
    else{
        *str = *rightStr;
        strncpy(str+1, rightStr+1, n - 1);
    }
}

//Global recursive strcat function that concatenate two char array
//Pre: takes two character array as argument that second one is const
//Post: add second characters to first characters
void strcat(char* str, const char* rightStr){
    if(*rightStr == '\0')
        *str == '\0';
    else{
        if(*str == '\0'){
            *str = *rightStr;
            *(str + 1) = '\0';
            strcat(str+1, rightStr+1);
        }
        else
            strcat(str+1, rightStr);
    }
}

//Global recursive HELP function that helps strlenTail function
//Pre: Takes const char array and a counter as parameter
//Post: Returns length of this char array
int strHelp(const char* str, int counter){
    if(*str == '\0')
        return counter;
    else
        return strHelp(str+1, counter+1);
}

//Global TAIL recursive function that calculates and returns length of a char array
//Pre: Takes a character array
//Post: returns calling strHelp function
int strlenTail(const char* str){
    return strHelp(str, 0);
}

//Global recursive strlend function that calculates and returns length of a char array
//Pre: Takes a character array as parameter
//Post: Returns length of this string
int strlen(const char* str){
    if(*str == '\0')
        return 0;
    else{
        return 1 + strlen(str+1);
    }
}

//Global recursive strcmp function that compares two character arrays
//Pre: Takes two character arrays as argument
/*Post:
*if Return value < 0 then it indicates str1 is less than str2.
*if Return value > 0 then it indicates str2 is less than str1.
*if Return value = 0 then it indicates str1 is equal to str2.
*/
int strcmp(const char* str1, const char* str2){
    
}


int main(int argc, char const *argv[]) {
    char str[12];

    cout << "***Recursive strcpy(char* str, const char* copiedStr)***\n";
    strcpy(str, "asdf");
    cout << str << endl;
    cout << "***END***\n\n";

    cout << "***Recursive strncpy(char* str, const char* rightStrdStr, int n)***\n";
    strncpy(str, "asdfghjkl", 4);
    cout << str << endl;
    cout << "***END***\n\n";

    cout << "***Recursive strcat(char* str, const char* rightStr)***\n";
    strcat(str, "ghjkl");
    cout << str << endl;
    cout << "***END***\n\n";

    cout << "***Recursive STRLENTAIL: strlenTail(const char* str)***\n";
    cout << strlenTail("Tolga Reis") << endl;
    cout << "***END***\n\n";

    cout << "***Recursive STRLEN: strlen(const char* str)***\n";
    cout << strlen("Tolga Reis") << endl;
    cout << "***END***\n\n";

    return 0;
}
