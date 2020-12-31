#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
class play
{
    protected:
    char a[3][3];
    public:
    play()//initialization
    {
        int i,j;
        system("cls");
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                a[i][j]=' ';
    }
    int show()//Print the Game
    {
        int i,j;
        system("cls");
        //Prototype
        cout<<"\\n\n\t1||2||3\n\t=======\n\t4||5||6\n\t=======\n\t7||8||9";
        //Game Board
        cout<<"\n\t\t     ||     ||     \n\t\t  "<<a[0][0]<<"  ||  "<<a[0][1]<<"  ||  "<<a[0][2]<<"  \n\t\t     ||     ||     ";
        cout<<"\n\t\t===================";
        cout<<"\n\t\t     ||     ||     \n\t\t  "<<a[1][0]<<"  ||  "<<a[1][1]<<"  ||  "<<a[1][2]<<"  \n\t\t     ||     ||     ";
        cout<<"\n\t\t===================";
        cout<<"\n\t\t     ||     ||     \n\t\t  "<<a[2][0]<<"  ||  "<<a[2][1]<<"  ||  "<<a[2][2]<<"  \n\t\t     ||     ||     ";
    return 0;
    }
    int inputp(int i)//Input of Player
    {
        int n,r,p;
        p=(i%2)+1;
        cout<<"\n\n Enter Input for Player "<<p<<" : ";
        do{
            cin>>n;
            if(n>-1&&n<10&&a[(n-1)/3][(n-1)%3]==' ')
                break;
            else if(n==0)
                goto j;
            else
                cout<<"\n Wrong Input, Renter Input : ";
        }while(true);
        a[(n-1)/3][(n-1)%3]=(p==1?'X':'O');
        show();
        r=result();
        if(r==1)
        {
            cout<<"\n Player "<<p<<" Win !!";
        }
        return r;
        j:
        return -2;
    }
    int result()//Check who win
    {
        int i,r;
        for(i=0;i<3;i++)
        {
            if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]&&a[i][1]!=' ')
                return 1;
            if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]&&a[1][i]!=' ')
                return 1;
        }
        if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[1][1]!=' ')
            return 1;
        if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[1][1]!=' ')
            return 1;
        return 0;
    }
    int pvsp()
    {
        int i,r;
        show();
        for(i=0;i<9;i++)
        {
            r=inputp(i);
            if(r==1)
                break;
        }
        if(r==0)
            cout<<"\n Match is Draw ";
        getch();
        return 0;
    }
};
class bot: public play
{
    public:
    int intial()
    {
        if(a[0][1]=='X')
            a[0][2]='O';
        else if(a[1][0]=='X')
            a[2][0]='O';
        else if(a[1][2]=='X')
            a[2][2]='O';
        else if(a[2][1]=='X')
            a[2][2]='O';
        else if(a[1][1]=='X')
            a[0][0]='O';
        else
            a[1][1]='O';
        show();
        return 0;
    }
    int check()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            if(a[i%3][i%3]==a[(i+1)%3][(i+1)%3]&&a[(i+1)%3][(i+1)%3]!=' '&&a[(i+2)%3][(i+2)%3]==' ')
                return ((((i+2)%3)*3)+((i+2)%3));
            if(a[i%3][2-(i%3)]==a[(i+1)%3][2-((i+1)%3)]&&a[(i+1)%3][2-((i+1)%3)]!=' '&&a[(i+2)%3][2-((i+2)%3)]==' ')
                return ((((i+2)%3)*3)+(2-((i+2)%3)));
            for(j=0;j<3;j++)
            {
                if(a[i][j%3]==a[i][(j+1)%3]&&a[i][(j+1)%3]!=' '&&a[i][(j+2)%3]==' ')
                    return (3*i+((j+2)%3));
                if(a[j%3][i]==a[(j+1)%3][i]&&a[(j+1)%3][i]!=' '&&a[(j+2)%3][i]==' ')
                    return (i+(((j+2)%3)*3));
            }
        }
        return -1;
    }
    int self()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                /*if(a[i][j%3]==a[i][(j+1)%3]&&a[i][(j+1)%3]==' '&&a[i][(j+2)%3]=='O')
                    return ((3*i)+((j+1)%3));*/
                if(a[j%3][i]==a[(j+1)%3][i]&&a[(j+1)%3][i]==' '&&a[(j+2)%3][i]=='O')
                    return (i+((j+1)%3)*3);
            }
        }
        for(i=0;i<3;i++)
        {
            if(a[i%3][i%3]==a[(i+1)%3][(i+1)%3]&&a[(i+1)%3][(i+1)%3]==' '&&a[(i+2)%3][(i+2)%3]=='O')
                    return ((((i)%3)*3)+((i)%3));
            if(a[i%3][2-(i%3)]==a[(i+1)%3][2-((i+1)%3)]&&a[(i+1)%3][2-((i+1)%3)]==' '&&a[(i+2)%3][2-((i+2)%3)]=='O')
                    return ((((i)%3)*3)+(2-((i)%3)));

        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(a[i][j%3]==a[i][(j+1)%3]&&a[i][(j+1)%3]==' '&&a[i][(j+2)%3]=='O')
                    return ((3*i)+((j+1)%3));
               /* if(a[j%3][i]==a[(j+1)%3][i]&&a[(j+1)%3][i]==' '&&a[(j+2)%3][i]=='O')
                    return (i+((j+1)%3)*3);*/
            }
        }
        return -1;
    }
    int ramplay()
    {
        int n,r=0,i;
        do{
            srand (time(NULL));
            n=rand()%9;
            if(a[n/3][n%3]==' ')
                r=1;
        }while(r!=1);
        return n;
    }
    int inputc(int l)
    {
        int n,r;
        if(l==1)
            n=ramplay();
        else if(l==2)
        {
            n=check();
            if(n==-1)
                n=ramplay();
        }
        else if(l==3)
        {
            n=check();
        cout<<n;
            if(n==-1)
                n=self();
            if(n==-1)
                n=ramplay();
        }
        a[n/3][n%3]='O';
        show();
        r=result();
        if(r==1)
            cout<<"\n Computer Win !!";
        return r;
    }
    int pvsc(int l)
    {
        int i,r=0,n=0;
        show();
        for(i=0;i<9;i++)
        {
            if(i%2==0)
            {
                r=inputp(i);
                if(r==1)
                    break;
                else if(r==-2)
                    goto f;
            }
            else
            {
                if(i==1&&l!=2)
                {
                    n=ramplay();
                    a[n/3][n%3]=='O';
                }
                if(i==1&&l==3)
                    intial();
                else
                {
                    r=inputc(l);
                    if(r==1)
                        break;
                }
            }
        }
        if(r==0)
            cout<<"\n Match is Draw ";
        getch();
        f:
        return 0;
    }
};
int main()
{
    int o,n;

    do{
            bot plays;
        cout<<"\n Enter your Choice :\n 1.Player vs Player\n 2.Player vs Bot\n 3.Exit\t";
        cin>>o;
        switch(o)
        {
            case 1:{plays.pvsp();
                    }break;
            case 2:{cout<<"\n 1.Easy\n 2.Medium\n 3.Hard\n 4.Exit";
                    cin>>n;
                    if(n==4)
                    {
                        cout<<"\n Wrong Choice ";
                        break;
                    }
                    plays.pvsc(n);
                    }break;
            case 3:{cout<<"\n Exiting ";
                    }break;
            default:{cout<<"\n Wrong Choice ";
                    }break;
        }
    }while(o!=3);
return 0;
}
