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
    char * rez = new char[1];
    int i = 0;
    char ch;
    cin.get(ch);
    int size = 1;
    
    if ((ch == '\0')||(ch == '\n')) {
    rez [0] = '\0';
        return rez;
    }
    rez [0] = ch;
    
    while (cin.get(ch) && ch != '\n' && ch != cin.eof()) {
    if (i + 1 == size) {
        rez = resize(rez, size, size*2);
        size *= 2;
    }  
    rez[i+1] = ch;
     ++i;
    }
    if (i + 1 == size) {
        rez = resize(rez, size, size+1);
        size += 1;
    }
    rez [i+1] = '\0';
    return rez;
}

int main(){
    char * str = getline();
    for (; *str != '\0'; ++str) cout<<*str;
}