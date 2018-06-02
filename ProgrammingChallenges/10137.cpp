#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long double floorr(long double var)
{
    long double value = (int)(var * 100);
    return (long double)value / 100;
}

long double roundd(long double var)
{
    long double value = (int)(var * 100 + .5);
    return (long double)value / 100;
}

int main()
{
    int n;
    cin>>n;
    while(n != 0)
    {
        long double A[n], total_sum = 0;;
        for(int i = 0; i < n; i++)
        {
            cin>>A[i];
            total_sum += A[i];
        }
//        cout<<"Total sum is -> "<<total_sum<<endl;
        sort(A, A + n);
        long double avg = floorr(total_sum / (long double)n);
//        cout<<"Average is -> "<<avg<<endl;
        long double B[n];
        for(int i = 0; i < n; i++)
            B[i] = avg;
        long double p = floorr((long double)abs( total_sum - (avg * n) ));
//        cout<<"p is -> "<<p<<endl;
        for(int i = n-1; p > 0; i--)
        {
//            cout<<"p is -> "<<p<<endl;
            B[i] += 0.01;
            p    -= 0.01;
            if(i == -1)
                i = n-1;
        }
/*        for(int i = 0; i < n; i++)
        {
            cout.precision(2);
            cout<<"A["<<i<<"] -> "<<fixed<<A[i]<<endl;
        }
        for(int i = 0; i < n; i++)
        {
            cout.precision(2);
            cout<<"B["<<i<<"] -> "<<fixed<<B[i]<<endl;
        }*/
        long double pos_diff = 00.00, neg_diff = 00.00;
        for(int i = 0; i < n; i++)
        {
//            cout<<"ans is -> "<<ans<<endl;
            if(B[i] - A[i] >= 0)
                pos_diff += B[i] - A[i];
            else
                neg_diff += A[i] - B[i];
        }
        cout.precision(2);
        cout<<"$"<<fixed<<roundd(pos_diff >= neg_diff? pos_diff : neg_diff)<<endl;

        cin>>n;
    }
}
