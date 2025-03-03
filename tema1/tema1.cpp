#include <iostream>
#include <cstring>
using namespace std;

char * concatenate(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char *result = new char[len1 + len2 + 1];

    strcpy(result, s1);

    strcat(result, s2);

    return result;
}


char* invers(const char* c) {
    if (!c) return NULL;
    int len = strlen(c);
    char* reversed = new char[len + 1];
    for (int i = 0; i < len; i++) {
        reversed[i] = c[len - 1 - i];
    }
    reversed[len] = '\0';
    return reversed;
}

void substitute(char a, char* b, char c) {
    if (!b) return;
    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] == a) {
            b[i] = c;
        }
    }
}

int lungime(const char* s) {
    if (!s) return 0;
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

int main()
{
    char str1[] = "aaa, ";
    char str2[] = "bbb!";

    char *result = concatenate(str1, str2);


    delete[] result;

    return 0;
}
