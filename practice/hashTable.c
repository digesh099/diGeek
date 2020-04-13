#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int Frequency[26];

int hashFunc(char c)
{
    return (c - 'a');
}

void countFre(char *str)
{
    for(int i = 0;i < strlen(str);++i)
    {
        int index = hashFunc(str[i]);
        Frequency[index]++;
    }
}

int main()
{
    char *str = "ababacdefdscdf";
    countFre(str);
    int i = 0;
    for(i = 0;i < 26;++i)
        cout << (char)(i+'a') << ' ' << Frequency[i] << endl;
    return 0;
}
