#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ifstream file("input.txt");
    int n, x, y, z;
    const int N=41;
    bool s0[N][N]={}, s1[N][N]={};
    file >> n;
    for(int i=0;i<n;i++)
    {
        file >> x >> y;
        s0[x][y]=true;
    }
    file.close();
    while(1)
    {
        system("cls");
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<N-1;j++)
            {
                z=0;
                if(s0[i-1][j-1]==true)
                {
                    z++;
                }
                if(s0[i-1][j]==true)
                {
                    z++;
                }
                if(s0[i][j-1]==true)
                {
                    z++;
                }
                if(s0[i+1][j+1]==true)
                {
                    z++;
                }
                if(s0[i][j+1]==true)
                {
                    z++;
                }
                if(s0[i+1][j]==true)
                {
                    z++;
                }
                if(s0[i+1][j-1]==true)
                {
                    z++;
                }
                if(s0[i-1][j+1]==true)
                {
                    z++;
                }
                if(s0[i][j]==true)
                {
                    if(z==2||z==3)
                    {
                        s1[i][j]=true;
                    }
                    else
                    {
                        s1[i][j]=false;
                    }
                }
                else
                {
                    if(z==3)
                    {
                        s1[i][j]=true;
                    }
                    else
                    {
                        s1[i][j]=false;
                    }
                }
            }
        }
        for(int i=1;i<N-1;i++)
        {
            for(int j=1;j<N-1;j++)
            {
                if(s1[i][j]==true)
                {
                    cout << " #";
                }
                else
                {
                    cout << " .";
                }
            }
            cout << endl;
        }
        swap(s0, s1);
        Sleep(350);
    }
}
