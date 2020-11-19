#include <bits/stdc++.h>
#define Max_N 100
using namespace std;
const int dong[8]= {0,-1,-1,-1,0,1,1,1};
const int  cot[8]= {1,1,0,-1,-1,-1,0,1};
int d,c;
int bd_md[Max_N][Max_N];//bản đồ mật độ
int bd_min[Max_N][Max_N];//bản đồ mìn

void sinh_dl()//sinh ra bản đồ mìn (để tạo ra bản đồ mật độ cho chắc ăn :))
{   srand(time(NULL));
    freopen("Min.inp","w",stdout);
    d=rand()%20+3;//số dòng tối đa của ma trận mìn
    c=rand()%10+3;//số cột tối đa (cho nho nhỏ để thử trước khi test với bản đồ to)
    cout<<d<<" "<<c<<endl;
    for(int i=1; i<=d; i++)
    {   for(int j=1; j<=c; j++)
            cout<<rand()%2<<" ";
        cout<<endl;
    }    // tim số x ngẫu nhiên trong [a,b]: x=rand()%(b-a+1)+a;
    freopen("con","w",stdout);
}
int xung_quanh(int i, int j)//Hàm đếm số mìn xung quanh ô (i,j)
{   int x=0;
    for (int k=0; k<8; k++)
        x=x+bd_min[i+dong[k]][j+cot[k]];
    return x;
}
void tao_dl()//tạo file chứa bản đồ mật độ từ file bản đồ mìn
{   freopen("Min.inp","r",stdin);
    freopen("matdo.inp","w",stdout);
    cin>>d>>c;
    cout<<d<<" "<<c<<endl;
    for(int i=1; i<=d; i++)
        for(int j=1; j<=c; j++)
            cin>>bd_min[i][j];
    for(int i=1; i<=d; i++)
    {   for(int j=1; j<=c; j++)
            cout<<xung_quanh(i,j)<<" ";
        cout<<endl;
    }
    freopen("con","r",stdin);
    freopen("con","w",stdout);
}
void nhapdl()//Nhập bản đồ mật độ
{   freopen("matdo.inp","r",stdin);
    cin>>d>>c;
    for(int i=1; i<=d; i++)
        for(int j=1; j<=c; j++)
            cin>>bd_md[i][j];
    freopen("con","r",stdin);
}
void xuatdl(int x[][Max_N])//in ra màn hình ma trận x
{   for(int i=1; i<=d; i++)
    {   for(int j=1; j<=c; j++)
            cout<<setw(3)<<x[i][j];
        cout<<endl;
    }
}
void chuanbi()
{   for(int i=0; i<=d+1; i++)
        for(int j=0; j<=c+1; j++)
            bd_min[i][j]=0;
}
bool kiemtra()//Kiểm tra bản đồ mìn tìm được xem có vị trí nào không đúng (có số mìn xung quanh nó khác với dữ liệu ban đầu)
{   for(int i=1; i<=d; i++)
        for(int j=1; j<=c; j++)
            if (xung_quanh(i,j)!=bd_md[i][j])
                return false;
    return true;
}
bool tiep_ko(int d1, int c1) // kiểm tra xem có nên đi tiếp không
{   for (int i=1; i<=c1-2; i++)
        if(xung_quanh(d1-1,i)!=bd_md[d1-1][i])//có 1 vị trí ở dòng phía trên bị sai so với bản đồ mật độ gốc
            return false;
    return true;
}
void thuchien(int d1, int c1)
{   if (d1<=d)
    {   if (c1<=c)
            for (int k=0; k<2; k++)
            {   bd_min[d1][c1]=k;//thử lần lượt vị trí [d1,c1] = 0,1
                if (d1>1 && c1>2) //bắt đầu từ dòng 2, nếu cột đã lớn hơn 2 thì các vị trí ở dòng trên nó và trước nó 2 cột phải đúng thì mới thử tiếp
                {if (tiep_ko(d1,c1))
                        thuchien(d1,c1+1);
                }
                else thuchien(d1,c1+1);// nếu dòng=1 hoặc cột mới là cột 1,2 thì cứ làm bình thường
            }
        else thuchien(d1+1,1);//Khi đã thử hết 1 dòng thì thử đến dòng tiếp theo với cột đầu tiên
    }
    else if (kiemtra()) //kiểm tra bản đồ mìn tìm được có phù hợp với bd mật độ không?
        xuatdl(bd_min);
}
int  main()
{   sinh_dl();//sinh ra bản đồ mìn
    tao_dl();// tạo bản đồ mật độ

    nhapdl();
    xuatdl(bd_md);//in bản đồ mật độ
    long t1=clock();//lấy thời gian hệ thống ở thời điểm bắt đầu
    chuanbi();
    thuchien(1,1);//bắt đầu thử từ dòng 1, cột 1
    long t2=clock();//lấy thời gian hệ thống ở thời điểm kết thúc
    cout<<"thoi gian thuc hien:"<<(float) (t2-t1)/CLOCKS_PER_SEC;
    return 0;
}
