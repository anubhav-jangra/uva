#include<iostream>
using namespace std;

int find_count(long int n)
{
    int count = 1;
    while(n != 1)
    {
        if(n % 2 == 1)
        {
            n = 3 * n + 1;
            n >>= 1;
            count++;
        }
        else
            n >>= 1;
            //n /= 2;
        count++;
    }
    return count;
}

int main()
{
    int a, b;
    while(cin>>a>>b)
    {
        cout<<a<<" "<<b<<" ";
        int max_count = find_count(a);
        if(a<b)  
            for(int i = a + 1; i <= b; i++)
            {
                int current_count = find_count(i);
                if(max_count < current_count)
                    max_count = current_count;
            }
        else
            for(int i = a - 1; i >= b; i--)
            {
                int current_count = find_count(i);
                if(max_count < current_count)
                    max_count = current_count;
            }
        cout<<max_count<<"\n";
    }
}
