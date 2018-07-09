#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut , &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut , wColor);
    }
    return;

}
void main()
{
    int i,c=51,r,l , ctr=256;
    char arr[100];
    system("cls");
    gotoxy(51,1);
    system("COLOR 5F");
    printf("Enter any String:- ");
    gotoxy(51,3);
    gets(arr);
    l = strlen(arr);
    system("cls");
    system("COLOR 0F");
    //Loops to Drop the letters.
    for(i=0;i<l;i++)
    {
        for(r=4;r<=24;r++ , ctr--)
        {
            SetColor(ctr);
            gotoxy(c,r);
            printf(" ");
            gotoxy(c,r+1);
            printf("%c",arr[i]);
            Sleep(50);
        }
        c++;
    }
    //Loops to move the letters to the left of the screen.
    r=25;
    ctr=256;
    for(i=0;i<l;i++)
    {
        for(c=(51+i);c>i;c-- , ctr--)
        {
            SetColor(ctr);
            gotoxy(c,r);
            printf(" ");
            gotoxy(c-1,r);
            printf("%c",arr[i]);
            Sleep(50);
        }
    }
    //Loops to move the letters back to the right.
    ctr=256;
    for(i=l-1;i>=0;i--)
    {
        for(c=i;c<=(50+i);c++ , ctr--)
        {
            SetColor(ctr);
            gotoxy(c,r);
            printf(" ");
            gotoxy(c+1 , r);
            printf("%c",arr[i]);
            Sleep(50);
        }
    }
    //Loops to move the letters upwards.
    c=51;
    ctr=256;
    for(i=0;i<l;i++)
    {
        for(r=25;r>=4;r-- , ctr--)
        {
            SetColor(ctr);
            gotoxy(c,r);
            printf(" ");
            gotoxy(c,r-1);
            printf("%c",arr[i]);
            Sleep(50);
        }
        c=c+1;
    }
}
