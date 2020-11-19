/*Bài toán "Người du lịch"
N thành phố 1,2,...,N. Chi phí đi từ thành phố i đến
thành phố j là C(i,j).
Tìm một hành trình đi qua tất cả các thành phố, mỗi
thành phố 1 lần (và quay về thành phố ban đầu),
sao cho tổng chi phí là nhỏ nhất.

********* Thuật toán (sử dụng Nhánh cận)*************:
- Ban đầu chi phí nhỏ nhất = vô cùng
- Mỗi khi tìm được 1  hành trình, thì lưu lại hành trình có chi phí MIN
- Trong mỗi lần tìm hành trình, giả sử đã đến được thành phố thứ i
   + Tìm tất cả các thành phố j mà từ i có thể đi trực tiếp đến
   + Nếu j chưa có trong hành trình thì:
       - Ghi nhận sẽ đi đến j (đánh dấu j, tính tổng chi phí mới)
       - Đánh giá xem có nên đi tiếp không, nếu nên đi tiếp thì
         đi tiếp từ j
       - Quay lui (bỏ đánh dấu j, giảm chi phí từ i đến j)

Chuẩn bị file dữ liệu:
    - Dòng đầu N
    - Các dòng sau chứa nửa tam giác trên ma trận trọng số
    (nếu không có đường đi i-->j thì ghi -1)
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn=100;//số thành phố tối đa
const int vocung=10000;
int n,  //số thành phố
    c[maxn][maxn],//ma trận trọng số
    cmin=vocung;  //Chi phí nhỏ nhất dùng để đánh giá nhánh cận
int Smin=vocung, Stam;//Chi phí min và chi phí đường đi hiện tại
int kq[maxn],dd_tam[maxn];//đường đi min và đường đi hiện thời
bool daxet[maxn];// đánh dấu thành phố nào đã có trong hành trình
fstream f;

void nhapdl()
{   f.open("data.inp",ios::in);
    f>>n;
    for (int i=1; i<n; i++)
    {   c[i][i]=vocung;
        for (int j=i+1; j<=n; j++)
        {   f>>c[i][j];
            if (c[i][j]==-1) c[i][j]=vocung;
            c[j][i]=c[i][j];    //đối xứng qua đường chéo
            if (cmin>c[i][j])   //tìm Cmin để phục vụ đánh giá nhánh cận
                cmin=c[i][j];
        }
    }
    c[n][n]=vocung;
    f.close();
}
void chuanbi()
{   Stam=0;
    Smin=vocung;
    dd_tam[1]=1;
    daxet[1]=true;//Đỉnh xuất phát luôn là đỉnh 1
}
void in_mt(int x[][maxn])
{   for (int i=1; i<=n; i++)
    {   for (int j=1; j<=n; j++)
            if (x[i][j]!=vocung)
                cout<<setw(3)<<x[i][j];
            else
                cout<<setw(3)<<"-1";
        cout<<endl;
    }
}
void in_kq()
{   cout<<" Duong di ngan nhat ="<<Smin+c[kq[n]][1]<<endl;
    for (int i=1; i<=n; i++)
        cout<<kq[i]<<" ";
}
void ghinhan()
{   if( c[dd_tam[n]][1]<vocung)// có đường đi từ đỉnh thứ n về đỉnh 1
        if (Smin>Stam)
        {   Smin=Stam;
            for (int i=1; i<=n; i++)
                kq[i]=dd_tam[i];
        }
}
void thuchien(int i)    // i là STT thành phố trên hành trình
{   for (int j=1; j<=n; j++)
        if (!daxet[j] && c[i][j]<vocung)
        // j chưa có trong hành trình và có đường đi từ i đến j
        {   daxet[j]=true;  //đánh dấu đã đến j
            Stam=Stam+c[dd_tam[i]][j];//Tinh chi phi
            dd_tam[i+1]=j;// Kết nạp j vào đường đi
            if (i+1==n)
                ghinhan();//Ghi nhận hoàn thành 1 đường đi
            if (Stam+(n-i+1)*cmin<Smin)//đánh giá nhánh cận
                thuchien(i+1);// đi tiếp từ j
            daxet[j]=false; //quay lui
            dd_tam[i+1]=0;  // Bỏ j ra khỏi đường đi
            Stam=Stam-c[dd_tam[i]][j];// giảm khoảng cách
        }
}
int main()
{   nhapdl();
    in_mt(c);//In ra để kiểm tra xem nhập DL đã đúng chưa
    chuanbi();
    thuchien(1);
    in_kq();
    return 0;
}
