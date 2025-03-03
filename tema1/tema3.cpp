#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool palindrom(const char *s, int length)
{
    for (int left = 0, right = length - 1; left < right; left++, right--)
    {
        if (s[left] != s[right])
            return false;
    }
    return true;
}

void generate(char *current, int pos, int maxi, const vector<char> &alphabet)
{
    if (pos == maxi)
    {
        current[pos] = '\0'; 
        if (palindrom(current, maxi))
        {
            cout << current << " ";
        }
        return;
    }
    
    for (char c : alphabet)
    {
        current[pos] = c;
        generate(current, pos + 1, maxi, alphabet);
    }
}

int main()
{
    vector<char> alphabet = {'0', '1', '2'};
    char current[6];

    for (int i = 1; i <= 5; i++)
    {
        cout << "lungime " << i <<endl;
        generate(current, 0, i, alphabet);
        cout << "\n\n";
    }

    return 0;
}
