#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

void print_val(bool arr[], int i, int j)
{
    int ans = 0;
    
    for(int a = max(i - 1, 0); a <= min(i + 1, n - 1); a++)
    {
        for(int b = max(j - 1, 0); b <= min(j + 1, m - 1); b++)
        {
            if(arr[a * m + b])
            {
                ans++;
            }
        }
    }
    cout<<ans;
}

int main()
{
    int count = 0;
    cin>>n>>m;
    while(n != 0 && m != 0)
    {
        if(count != 0)
            cout<<endl;
        char temp;
        bool arr[n * m] = {};
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                cin>>temp;
                if(temp == ' ' || temp == '\n')
                    cin>>temp;
                if(temp == '*')
                    arr[i * m + j] = true;
                else
                    arr[i * m + j] = false;
            }
        cout << "Field #" << ++count << ":\n";
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!arr[i * m + j])
                    print_val(arr, i, j);
                else
                    cout<<"*";
            }
            cout<<'\n';
        }
        cin>>n>>m;
    }
}

