#include <iostream>
#include <cstring>
using namespace std;

char* concat(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char* finalRez = new char[len1 + len2 + 1];
    strcpy(finalRez, s1);
    strcat(finalRez, s2);
    return finalRez;
}

char* repeat(const char* s, int n) {
    int len = strlen(s);
    char* finalRez = new char[len * n + 1];
    finalRez[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(finalRez, s);
    }
    return finalRez;
}

char* reverse(const char* s) {
    int len = strlen(s);
    char* finalRez = new char[len + 1];
    for (int i = 0; i < len; i++) {
        finalRez[i] = s[len - 1 - i];
    }
    finalRez[len] = '\0';
    return finalRez;
}

char* extract(const char* s, int i, int j) {
    if (i > j || i < 0 || j >= strlen(s)) return nullptr;
    int len = j - i + 1;
    char* finalRez = new char[len + 1];
    strncpy(finalRez, s + i, len);
    finalRez[len] = '\0';
    return finalRez;
}

char* replace(const char* s, const char* sub, const char* new_sub) {
    const char* pos = strstr(s, sub);
    if (!pos) return strdup(s);
    int berfore_len = pos - s;
    int sublen = strlen(sub);
    int new_sublen = strlen(new_sub);
    int total = berfore_len + new_sublen + strlen(pos + sublen);
    char* finalRez = new char[total + 1];
    strncpy(finalRez, s, berfore_len);
    strcpy(finalRez + berfore_len, new_sub);
    strcpy(finalRez + berfore_len + new_sublen, pos + sublen);
    return finalRez;
}

int main() {
    const char word[] = "x1a5b2";
    
    char* rez1 = concat(word, "c3");
    char* rez2 = repeat(word, 2);
    char* rez3 = reverse(word);
    char* rez4 = extract(word, 1, 3);
    char* rez5 = replace(word, "a5", "z9");

    return 0;
}
