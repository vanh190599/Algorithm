#include <bits/stdc++.h>

using namespace std;


void bai1()
{

    string s;
    int d[300]={};

    cin >> s;

    for (int i=0;i<s.length();i++) 
        d[s[i]]++;

    for (int i=0;i<300;i++)
        if (d[i]!=0) cout << (char)(i) << " : " << d[i]<<endl;
}

void qsort(int l, int r, int a[]) {
    
    int i=l,j=r;
    int mid = a[(i+j)/2];

    while (i<=j)
    {
        while (a[i]<mid) i++;
        while (a[j]>mid) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        if (i<r) qsort(i,r,a);
        if (l<j) qsort(l,j,a);
    }
}

void bai2() 
{
    int a[2001];
    srand(time(NULL));
    for (int i=1;i<=2000;i++)
        a[i] = rand()%10000+1;
    
    qsort(1,2000,a);

    for (int i=1;i<=2000;i++)
        cout << a[i] << " ";
}

int main()
{
    bai2();
    return 0;
}