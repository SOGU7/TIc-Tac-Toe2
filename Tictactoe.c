#include<stdio.h>
#include<stdbool.h>
int iswin(int a[][4],int n)
{
    int i,j,flag = 1;
    for(i=1;i<=n;i++)
    {
        if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]&&a[i][1]!=-1)
            return a[i][1];
    }
    for(j=1;j<=n;j++)
    {
        if(a[1][j]==a[2][j]&&a[2][j]==a[3][j]&&a[1][j]!=-1)
            return a[1][j];
    }
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[1][1]!=-1)
        return a[1][1];
    if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]!=-1)
        return a[1][3];
    if(a[1][1]!=-1&&a[1][2]!=-1&&a[1][3]!=-1&&a[2][1]!=-1&&a[2][2]!=-1&&a[2][3]!=-1&&a[3][1]!=-1&&a[3][2]!=-1&&a[3][3]!=-1)
    return 0;

}
void grid(int a[][4],int n)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]==-1)
                printf(" ");
            else if(a[i][j]==1)
                printf("O");
            else
                printf("X");
            if(j<n)
            {
                printf("\t|\t");

            }
        }
        if(i<n)
        {
            printf("\n");
            printf("_____________________________________");

        }
        printf("\n");
    }

}
void printWin(int a[][4],int n,int who)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]==who)
            {
                if(who==1)
                {
                    if((a[i][1]==a[i][2]&&a[i][2]==a[i][3]&&a[i][1]!=-1)||(a[1][j]==a[2][j]&&a[2][j]==a[3][j]&&a[1][j]!=-1)||(a[1][1]==a[2][2]&&a[2][2]==a[2][3]&&a[1][1]!=-1)||(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]!=-1))
                    printf("O");
                }
                else
                {
                    if((a[i][1]==a[i][2]&&a[i][2]==a[i][3]&&a[i][1]!=-1)||(a[1][j]==a[2][j]&&a[2][j]==a[3][j]&&a[1][j]!=-1)||(a[1][1]==a[2][2]&&a[2][2]==a[2][3]&&a[1][1]!=-1)||(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&a[1][3]!=-1))
                    printf("X");
                }
            }
            else
                printf(" ");
            if(j<n)
            {
                printf("\t|\t");

            }
        }
        if(i<n)
        {
            printf("\n");
            printf("_____________________________________");

        }
        printf("\n");
    }
}
int main()
{
    int n=3,i,j;
    int a[4][4];
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            a[i][j]=-1;
        }
    }
    bool player1 = true;
    bool player2 = false;
    while(true)
    {
        grid(a,n);
        if(player1)
        {
            //Player1 value = 1
            int r,c;
            label:
            printf("\nPlayer1(O) turn\nEnter the no of row and column : ");
            scanf("%d %d",&r,&c);
            if(a[r][c]!=-1)
            {
                printf("\nInvalid Cell");
                goto label;
            }
            a[r][c]=1;
            player1 = false;
            player2 = true;
        }
        else
        {
            int r,c;
            label2:
            printf("\nPlayer2(X) turn\nEnter the no of row and column : ");
            scanf("%d %d",&r,&c);
            if(a[r][c]!=-1)
            {
                printf("\nInvalid Cell");
                goto label2;
            }
            a[r][c]=2;
            player2 = false;
            player1 = true;
        }
        if(iswin(a,n)==1)
        {
            printf("\nPlayer 1 Won!\n");
            printWin(a,n,1);
            break;
        }
        if(iswin(a,n)==2)
        {
            printf("\nPlayer 2 Won!\n");
            printWin(a,n,2);
            break;
        }
        if(iswin(a,n)==0)
        {
            printf("\nMatch Draw\n");
            break;
        }
    }
    return 0;

}
