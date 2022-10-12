#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//maximum, sort in ascending and descending order

auto MaxArray(long arr[], int size)
{
    long max = arr[0];

    for(int i=1;i<11;i++)
    {if (max < arr[i])
        max = arr[i];}

    return max;
}

int main()
{
    srand(time(0));

    long a[10]; long b[10];
    for (int i = 0; i < 10; i++)
    {
        a[i]=rand()%100000;
        long r=rand()%26+65;
        b[i]=r;
        cout<<char(r)<<" ";

    }

    for (int x:a)
    {
        cout<<x<<" ";
    }
    cout << endl;
    cout << "The maximum number is " << MaxArray(a,sizeof(a));

    return 0;
}