#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

COORD coord={0,0};

char name[100][50];
int quiz[100][100 ],n=0,q=0,flag,sum;
float ave[100];

void empi();
int range();
int menu();
void get();
void disp();
void del();
void gotoxy(int x, int y);
void upload();
void download();
int make();

int main()
{
    empi();
     download();
   /* if(strcmp(name[0],"")==0){
        empi();
    }*/
    while (1)
    {
        switch (menu())
        {
            case 1: system("cls"); if(range()) {gotoxy(3,7);printf("YOU ALREADY DECLARED NUMBER OF STUDENT'S AND QUIZZES");}
                                                        else {gotoxy(3,7);printf("THE NUMBER OF STUDENT'S YOU DECLARED IS %d\n",n);
                                                                    gotoxy(3,9);printf("THE NUMBER OF QUIZZES YOU DECLARED IS %d\n",q); } getch();break;
            case 2: system("cls");get();break;
            case 3: system("cls");disp();break;
            case 4: system("cls");del();break;
            case 5: upload();system("cls");
                           printf("\nLOGGING OFF!!!\n");exit(0);break;
            default: gotoxy(5,11);printf("INVALID NUMBER");getch(); system("cls");
        }
    }
}
void empi()
{ flag=0;}
int make()
{
    if (flag >  0)
        return 1;
    else
        return 2;
}
int menu()
{
    int w;
    start:
    system("cls");
    gotoxy(3,3);printf("MENU OPTIONS");
    gotoxy(3,5);printf("1.) ENTER NUMBER OF STUDENT'S AND QUIZZES");
    gotoxy(3,7);printf("2.) ENTER STUDENT'S NAME AND QUIZZES");
    gotoxy(3,9);printf("3.) DISPLAY THE WHOLE DATA OF STUDENT'S");
    gotoxy(3,11);printf("4.) DELETE DATA FROM STUDENT'S");
    gotoxy(3,13);printf("5.) EXIT");
    gotoxy(3,15);printf("SELECT NUMBER FROM 1 to 5: ");
    while (scanf("%d",&w) != 1)
    {
        while(getchar() != '\n');
        gotoxy(3,17);printf("--->>  YOU ENTERED A CHARACTER  <<--"); getch();
        goto start;
    }
  return w;
}
int range()
{
    if(n==0){
     gotoxy(3,3);printf("ENTER NUMBER OF STUDENT'S: ");
     scanf("%d",&n);
     gotoxy(3,5);printf("ENTER NUMBER OF QUIZZES: ");
     scanf("%d",&q); return 1;}
    else
    return 0;

}
void get()
{
    if (flag > n-1)
    { gotoxy(3,3); printf("-->>  NO ENOUGH STORAGE  <<--");getch();}
    else
    { int i;
    gotoxy(3,3);printf("ENTER NAME OF STUDENT'S: ");
    scanf("%s",name[flag]);
            for(i=0;i<q;i++)
            {  gotoxy(3,3+2+i);printf("ENTER SCORE IN QUIZ #%d: ",i+1);
                scanf("%d",&quiz[flag][i]);
            }
        flag++;
    }
}
void disp()
{
    int i,j;
    if(flag <= 0) { gotoxy(3,3); printf("-->>  NO STORED DATA  <<--");getch();}
    else {
    gotoxy(3,3);printf("NAME");
    for(i=0;i<q;i++)
    { gotoxy(20+(15*i),3);printf("QUIZ #%d",i+1);}  gotoxy(20+(15*(q)),3);printf("AVERAGE"); gotoxy(20+(15*(q+1)),3);printf("REMARKS");
      for(i=0;i<flag;i++)
      { gotoxy(3,5+(2*i));printf("%d.) %s",i+1,name[i]);
            sum=0;
            for(j=0;j<q;j++)
            { gotoxy(20+(15*j),5+(2*i));printf("  %d",quiz[i][j]);
                sum += quiz[i][j];
            }
            ave[i] = sum/q;
            gotoxy(20+(15*(q)),5+(2*i));printf("%.2f%%",ave[i]);
            if(ave[i] >= 75.00)
            {gotoxy(20+(15*(q+1)),5+(2*i));printf("PASSED");}
            else
             {gotoxy(20+(15*(q+1)),5+(2*i));printf("FAILED");}
      }
 getch();
}
}
void del()
{
    int a,i,j,k,t,l;

    switch (make())
    {
        case 1:
        start: system("cls"); disp();
        gotoxy(75+q,11+flag);printf("1.) DELETE DATA OF STUDENT FROM THE RECORD");
        gotoxy(75+q,12+flag);printf("2.) CHANGE SCORE FROM THE QUIZZES");
        gotoxy(75+q,13+flag);printf("SELECT NUMBER FROM 1 TO 2: "); scanf("%d",&a);
                     if(a==1)
                    {
                        go: system("cls"); disp();
                        gotoxy(75+q,11+flag);printf("SELECT NUMBER OF STUDENT TO DELETE THE DATA: "); scanf("%d",&k);
                                if(k-1< flag && k-1 > -1){
                                for(i=k-1;i<flag;i++)
                                {
                                    for(j=0;j<50;j++)
                                    {name[i][j] =name[i+1][j]; }
                                    for(j=0;j<50;j++)
                                    {quiz[i][j] =quiz[i+1][j];}
                                }
                                flag--;
                            }
                                 else {gotoxy(75+q,12+flag);printf("INVALID NUMBER");goto go;getch(); }
                    }
                    else if(a==2)
                    {
                         S: system("cls"); disp();
                          gotoxy(75+q,11+flag);printf("SELECT NUMBER OF STUDENT: "); scanf("%d",&k);k-=1;
                                            if(k<flag && k>-1)
                                                {
                                                    back: gotoxy(75+q,12+flag);printf("SELECT NUMBER OF QUIZ: "); scanf("%d",&t); t-=1;
                                                 if(t<q && t>-1) {
                                                                gotoxy(75+q,13+flag);printf("ENTER NEW VALUE OF QUIZ #%d: ",t+1); scanf("%d",&l);
                                                                    for(i=k;i<=k;i++)
                                                                            {
                                                                                for(j=0;j<q;j++)
                                                                                    if(j==t)
                                                                                            quiz[i][j]=l;

                                                                            }
                                                            }
                                                    else {gotoxy(75+q,13+flag);printf("INVALID NUMBER"); getch();goto S; }
                                                 }
                                    else {gotoxy(75+q,13+flag);printf("INVALID NUMBER"); getch();goto S;}
                                    disp();
                    }
                    else {gotoxy(75+q,15+flag);printf("INVALID NUMBER");getch();goto start;} break;
                    case 2:  gotoxy(3,3);printf("-->>  NO DATA STORED <<--");getch(); break;

        }
}
void gotoxy(int x,int y){
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord) ;
}
void upload()
{
    FILE*fp;
    int i,j;
        fp=fopen("bscs.file","w+");
        fprintf(fp,"%d\n%d\n%d\n",flag,n,q);
       for(i=0;i<flag;i++)
        {
            fprintf(fp,"%s\n",name[i]);
             for(j=0;j<q;j++)
            {fprintf(fp,"%d\n",quiz[i][j]);}

        }
        fclose(fp);
}
void download()
{
    int i,j;
    FILE*fp;
    fp=fopen("bscs.file","r+");
    if(fp==NULL){
        upload();
    }
    fscanf(fp,"%d\n%d\n%d\n",&flag,&n,&q);
      for(i=0;i<flag;i++)
        {
            fscanf(fp,"%s\n",name[i]);
             for(j=0;j<q;j++)
            {fscanf(fp,"%d\n",&quiz[i][j]);}

        }
fclose(fp);
}
