#include <iostream>
using namespace std;

void odd_magic(int );
void even_magic_4(int );
void even_magic_6(int );
int main()
{
    int n;
    cout<<"please Enter your number : ";
    cin>>n;

    if(n%2==1)//for odd numbers
        odd_magic(n);

    else if(n%4==0)
        even_magic_4(n);//for set of 4

    else if(n%4==2)
        even_magic_6(n);//for set of 6

    return 0;
}

void odd_magic(int n)
{
    int magic_array[n][n]={};
    int row=0;
    int col=n/2;
    int a,b;


    for(int i=1;i<=n*n;i++)
    {
        magic_array[row][col]=i;

        a=row;
        b=col;
        row--;
        col--;

        if(row==-1)//row<0
            row=n-1;
        if(col==-1)//col<0
            col=n-1;
        if(magic_array[row][col]!=0)
        {
            row=a+1;
            col=b;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<magic_array[i][j]<<"\t";
        }
        cout<<endl;
    }
}


void even_magic_4(int n)
{
    int c=0;
    int magic_4[n][n]={};
    int k;
    k=n/4;

    int num[n*n];
    for(int c=0;c<n*n;c++)
    {
        num[c]=c+1;
    }


//part 1:
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<4*k;j++)
        {
            if(j<k)
            {
                magic_4[i][j]=num[c];
                num[c]=0;
            }
            if(j>=3*k)
            {
                magic_4[i][j]=num[c];
                num[c]=0;
            }
            num[c++];

        }
    }


//part 2:
    for(int i=k;i<3*k;i++)
    {
        for(int j=0;j<4*k;j++)
        {
            if(j>=k&&j<3*k)
            {
                magic_4[i][j]=num[c];
                num[c]=0;
            }
            num[c++];
        }
    }

//part 3:
    for(int i=3*k;i<4*k;i++)
    {
        for(int j=0;j<4*k;j++)
        {
            if(j<k)
            {
                magic_4[i][j]=num[c];
                num[c]=0;
            }
            if(j>=3*k)
            {
                magic_4[i][j]=num[c];
                num[c]=0;
            }
            num[c++];
        }
    }
c=0;
//part 4: insert recursive :
    for(int i=4*k-1;i>=0;i--)
    {
        for(int j=4*k-1;j>=0;j--)
        {
            if(magic_4[i][j]==0)
            {
                while(num[c]==0)
                {
                    c++;
                }
                magic_4[i][j]=num[c];
            }
            c++;
        }
    }


//show:
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<magic_4[i][j]<<"\t";
        }
        cout<<endl;
    }

}

void even_magic_6(int n)
{
    int c=0;
    int magic_6[n][n]={};
    int k=(n-2)/4;
    int num[n*n];

    for(int c=0;c<n*n;c++)
    {
        num[c]=c+1;
    }

//part 1:
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<4*k+2;j++)
        {
            if(j<k)
            {
                magic_6[i][j]=num[c];
                num[c]=0;
            }
            if(j>=3*k+2)
            {
                magic_6[i][j]=num[c];
                num[c]=0;
            }
            if(i<k&&j>k&&j<3*k+1)//barax va jabeja
            {
                if(j<(4*k+2)/2)
                {
                    magic_6[i+(4*k+1)][j+k]=num[c];
                    num[c]=0;
                }
                else
                {
                    magic_6[i+(4*k+1)][j-k]=num[c];
                    num[c]=0;
                }

            }
            num[c++];

        }
    }


//part 2:
    for(int i=k;i<=3*k+1;i++)
    {
        for(int j=0;j<4*k+2;j++)
        {
            if(j>=k+1&&j<3*k+1&&i>k&&i<3*k+1)
            {
                magic_6[i][j]=num[c];
                num[c]=0;
            }
            if(i==k&&j==k||i==k&&j==3*k+1||i==3*k+1&&j==k||i==3*k+1&&j==3*k+1)//baraye barchasb ha
            {
                magic_6[i][j]=num[c];
                num[c]=0;
            }
            if(i>k&&i<3*k+1&&j<k)//barax va jabeja
            {
                if(i<(4*k+2)/2)
                {
                magic_6[i+k][j+4*k+1]=num[c];
                num[c]=0;
                }
                else
                {
                  magic_6[i-k][j+4*k+1]=num[c];
                  num[c]=0;
                }
            }
            if(i>k&&i<3*k+1&&j>3*k+1)//barax va jabeja
            {
                if(i<(4*k+2)/2)
                {
                    magic_6[i+k][j-(4*k+1)]=num[c];
                    num[c]=0;
                }
                else
                {
                    magic_6[i-k][j-(4*k+1)]=num[c];
                    num[c]=0;
                }
            }
            num[c++];
        }
    }

//part 3:
    for(int i=3*k+2;i<4*k+2;i++)
    {
        for(int j=0;j<4*k+2;j++)
        {
            if(j<k)
            {
                magic_6[i][j]=num[c];
                num[c]=0;
            }
            if(j>3*k+1)
            {
                magic_6[i][j]=num[c];
                num[c]=0;
            }
            if(i>3*k+1&&j>k&&j<3*k+1)//barax va jabeja
            {
                if(j<(4*k+2)/2)
                {
                    magic_6[i-(4*k+1)][j+k]=num[c];
                    num[c]=0;
                }
                else
                {
                    magic_6[i-(4*k+1)][j-k]=num[c];
                    num[c]=0;
                }
            }
            num[c++];
        }
    }
    c=0;
//part4 : insert other number
for(int i=0;i<4*k+2;i++)
    {
    for(int j=0;j<4*k+2;j++)
    {
        if(magic_6[i][j]==0)
        {
            while(num[c]==0)
            {
                c++;
            }
            magic_6[i][j]=num[c];
        }
        c++;
    }
}

int col_navar1[n]={};
int col_navar2[n]={};

for(int z1=0,z2=n-1;z1<n;z1++,z2--)
{
    col_navar1[z1]=magic_6[z1][k];
    col_navar2[z1]=magic_6[z2][3*k+1];
}
int temp=0;
for(int i=0;i<n;i++)
{
    if(i>=k+1&&i<=3*k)
    {
        temp=col_navar2[i];
        cout<<"temp:"<<temp<<endl;
        col_navar1[i]=col_navar1[i];
        col_navar2[i]=temp;
    }
}


cout<<endl;
for(int i=0;i<n;i++)
{
    cout<<col_navar1[i]<<"\t";

}
cout<<endl;

for(int i=0;i<n;i++)
{
    cout<<col_navar2[i]<<"\t";

}

cout<<endl;
//show:
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<magic_6[i][j]<<"\t";
    }
    cout<<endl;
}

}



