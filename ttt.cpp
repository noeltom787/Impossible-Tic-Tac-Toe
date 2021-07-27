#include<iostream>
#include<windows.h>
#include<fstream>
#include<process.h>

#define pm printmatrix
#define endl cout<<'\n'
#define fm firstmove
using namespace std;

void logic(char M[3][3],char tok, char mytok,int ui,int uj);
void urmove(char M[3][3],char tok,char mytok);
void firstmove(char M[3][3],char tok,char mytok);
void mymove(char M[3][3],char i,char j,char tok,char mytok);

int endd=0,first=0,count=0,re=0,win=0;

char choose()
{
    char c;
    cout<<"\nChoose your symbol(X/O): ";
    cin>>c;
    return toupper(c);
}

void pause(int n)
{
    endl;
    cout<<".";Sleep(500*n);
    cout<<".";Sleep(500*n);
    cout<<".";Sleep(500*n);
    endl;endl;
}

void printmatrix(char M[3][3])
{
    printf("   A B C\n\n");
    for(int i=0;i<3;i++)
      {
          printf("%d  ",i+1);
          for(int j=0;j<3;j++)
            {
               cout<<M[i][j]<<" ";
            }
            endl;
      }
}




main()
{
    char M[3][3];
    char tok,mytok;
    retry:
     for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            M[i][j]='-';
        }
         token_select:
            tok=choose();
            pause(1);
            if(tok=='O')
            {
                mytok='X';
            }
            else if(tok=='X')
            {
                mytok='O';
            }
            else
            {
                cout<<"Please enter the correct symbol\n";
                goto token_select;
            }
      pm(M);
      cout<<"Enter \'ex\' to exit\nEnter \'re\' to start again\nMake your move (eg: \'A1\',\'C2\')\n";
      first=1;
      urmove(M,tok,mytok);
      if(re==1)
        goto retry;

      if(win==1)
        cout<<"\nYOU LOSE!\n";
}




void logic(char M[3][3],char tok, char mytok,int ui,int uj)
{
    int my=0,ur=0,j1,i1;
    if(first==1)
    {
        first=0;
        if(ui+uj==3 || ui+uj==1)
        {
            if(ui==1)
            {
                mymove(M,ui+1,uj,tok,mytok);
                return;
            }
            if(uj==1)
            {
                mymove(M,ui,uj+1,tok,mytok);
                return;
            }
        }

    }
    if(count==3)
    {
        if((M[0][0]==tok && M[1][1]==mytok && M[2][2]==tok) ||
           (M[2][0]==tok && M[1][1]==mytok && M[0][2]==tok) )
        {
            mymove(M,1,0,tok,mytok);
            return;
        }
    }

     for(int i=0;i<3;i++)
     {
         my=ur=0;
         for(int j=0;j<3;j++)
         {
             if(M[i][j]==tok)
                 ur++;
             else if(M[i][j]==mytok)
                 my++;
             else
                 j1=j;
         }
         if((ur==2 && my==0) ||(ur==0 && my==2))
         {
             mymove(M,i,j1,tok,mytok);
             return;
         }
     }
     for(int j=0;j<3;j++)
     {
         my=ur=0;
         for(int i=0;i<3;i++)
         {
             if(M[i][j]==tok)
                 ur++;
             else if(M[i][j]==mytok)
                 my++;
             else
                 i1=i;
         }
         if((ur==2 && my==0) ||(ur==0 && my==2))
         {
             mymove(M,i1,j,tok,mytok);
             return;
         }
     }

     my=ur=0;

     for(int i=0;i<3;i++)
     {
         if(M[i][i]==tok)
                 ur++;
             else if(M[i][i]==mytok)
                 my++;
             else
                 i1=i;
     }
     if((ur==2 && my==0) ||(ur==0 && my==2))
         {
             mymove(M,i1,i1,tok,mytok);
             return;
         }

     my=ur=0;

     for(int i=0,j=2;i<3;i++,j--)
     {
         if(M[i][j]==tok)
                 ur++;
             else if(M[i][j]==mytok)
                 my++;
             else
                {
                    i1=i;
                    j1=j;
                }
     }
     if((ur==2 && my==0) ||(ur==0 && my==2))
         {
             mymove(M,i1,j1,tok,mytok);
             return;
         }

     if(M[1][1]=='-')
     {
         mymove(M,1,1,tok,mytok);
             return;
     }
     if(M[0][0]=='-')
     {
         mymove(M,0,0,tok,mytok);
             return;
     }
     if(M[0][2]=='-')
     {
         mymove(M,0,2,tok,mytok);
             return;
     }
     if(M[2][2]=='-')
     {
         mymove(M,2,2,tok,mytok);
             return;
     }
     if(M[2][0]=='-')
     {
         mymove(M,2,0,tok,mytok);
             return;
     }
     if(M[2][1]=='-')
     {
         mymove(M,2,1,tok,mytok);
             return;
     }
     if(M[1][0]=='-')
     {
         mymove(M,1,0,tok,mytok);
             return;
     }
     if(M[1][2]=='-')
     {
         mymove(M,1,2,tok,mytok);
             return;
     }
     else
     {
         mymove(M,0,1,tok,mytok);
             return;
     }
}


void urmove(char M[3][3],char tok,char mytok)
{
     char i1,j1;
     int i,j;
        cout<<"->";
        cin>>i1>>j1;
        if(i1=='e' && j1=='x')
         exit(0);
        if(i1=='r' && j1=='e')
        {
            first=endd=count=0;
            re=1;
            return;
        }
        if(!(((i1>='A' && i1<='C')||(i1>='a' && i1<='c'))&&(j1>='1' && j1<='3')))
        {
            cout<<"\nPlease follow the format(eg: \'A1\',\'C2\')\n";
            urmove(M,tok,mytok);
        }
        j=(int)toupper(i1)-65;
        i=(int)j1-49;
        if(M[i][j]!='-')
         {
             cout<<"Invalid move!\n";
             urmove(M,tok,mytok);
             return;
         }
        M[i][j]=tok;
        count++;
        pause(1);
        pm(M);
        if(endd==1)
            return;
        logic(M,tok,mytok,i,j);
}

void mymove(char M[3][3],char i,char j,char tok,char mytok)
{
    M[i][j]=mytok;
    count++;
    int blank=0,my;
    pause(2);
    pm(M);

    for(int k=0;k<3;k++)
    {
        my=0;
        for(int l=0;l<3;l++)
        {
            if(M[k][l]=='-')
             blank++;
            else if(M[k][l]==mytok)
             my++;
        }
        if(my==3)
        {
            win=1;
            endd=1;
            return;
        }
    }

    if(blank==1)
        endd=1;

    for(int k=0;k<3;k++)
    {
        my=0;
        for(int l=0;l<3;l++)
        {
            if(M[k][l]==mytok)
             my++;
        }
        if(my==3)
        {
            win=1;
            endd=1;
            return;
        }
    }
    if((M[0][0]==mytok && M[1][1]==mytok && M[2][2]==mytok) ||
       (M[0][2]==mytok && M[1][1]==mytok && M[2][0]==mytok))
       {
           win=1;
           endd=1;
           return;
       }
    urmove(M,tok,mytok);
}
