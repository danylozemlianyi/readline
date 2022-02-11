#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * new_char = new char[new_size];
    for (int i = 0; i<size && i<new_size; ++i) {
        new_char[i] = str[i];
    }
    delete [] str;
    return new_char;
}

char *getline()
{
    char * str = new char[1];
    int i = 0;
    char ch;
    cin.get(ch);
    
    if ((ch == '\0')||(ch == '\n')) {
    str [0] = '\0';
        return str;
    }
    str [0] = ch;
    while (true) {
        
    str = resize(str, i+1, i+2);
    cin.get(ch);
    
    if ((ch == '\0')||(ch == '\n')) {
        str [i+1] = '\0';
        return str;
        }
        
     str[i+1] = ch;
     ++i;
    }
}

int main(){
    char * str = getline();
    for (; *str != '\0'; ++str) cout<<*str;
}