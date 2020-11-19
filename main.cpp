/*
Cho một dãy số nguyên. Một dãy con là một số phần
tử có thể không liên tiếp trong dãy ban đầu.
1. Hãy chỉ ra dãy con “Không giảm”
nhiều phần tử nhất (hoặc dài nhất).
Yêu cầu:
+ Tạo ra file dữ liệu:
- Dòng đầu chứa số N (số phần tử <100000)
- Dòng tiếp theo gồm N số nguyên thuộc [-1000;1000]
(tỷ lệ các số âm khoảng 1/3)
+ Nhập dữ liệu từ file vừa tạo
+ Tìm dãy con KHÔNG GIẢM dài nhất
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=30;//theo y/cầu sẽ đặt lại =100000

int n;
int a[MAXN],L[MAXN],Vet[MAXN];

void tao_file_dl()
{   freopen("data.inp","w",stdout);
    srand(time(NULL));
    n=rand()%(MAXN-4)+5; //tạo số ngẫu nhiên n thuộc [5,MAXN]
    cout<<n<<endl;
    for (int i=1; i<=n; i++)//Số trong khoảng [-50,50]
        if (rand()%3==0)
            cout<<-rand()%50-1<<" ";
        else
            cout<<rand()%50+1<<" ";
    freopen("con","w",stdout);
}
void nhap_dl()
{   freopen("data.inp","r",stdin);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
}
void in_dl(int a[])
{   for (int i=1; i<=n; i++)
        cout<<setw(4)<<a[i];
    cout<<endl;
}

void tim_day_L()
{   L[1]=1;
    int maxL;
    for (int i=2; i<=n; i++)
    {   maxL=0;
        Vet[i]=0;//để truy vết tìm ra dãy con
        for(int j=1; j<i; j++)
        {   if (a[j]<=a[i])
                if (maxL<L[j])
                {   maxL=L[j];
                    Vet[i]=j;
                }
        }
        L[i]=maxL+1;
    }
}
void xuat_dl( int k)
{   if (Vet[k]>0)
    {   xuat_dl(Vet[k]);
        cout<<setw(4)<<a[k];
    }
    else cout<<setw(4)<<a[k];
}
void in_kq()
{   int maxL=L[1], vitri=1;
    for (int i=2; i<=n; i++)//Tìm vị trí và giá trị L max
        if (maxL<L[i])
        {   maxL=L[i];
            vitri=i;
        }
    cout<<"\nDay con tang dai nhat:"<<endl;
    xuat_dl(vitri);
}
void tim_day_tang_dai_nhat()// Các phần tử không liên tiếp
{   tim_day_L();
    cout<<"Day L\n";
    in_dl(L);
    cout<<"Day de truy vet\n";
    in_dl(Vet);
    in_kq();
}
int main()
{   tao_file_dl();
    nhap_dl();
    cout<<"Day so ban dau\n";
    in_dl(a);
    tim_day_tang_dai_nhat();
    return 0;
}
