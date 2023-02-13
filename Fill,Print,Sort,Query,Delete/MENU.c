#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 50

int integer[MAX], flag = 0,i,num,a,siz[MAX],flag1=0,temp,s,d, k,j;

int menu();
void Fill();
void Display();
void Sort();
void del();
void del1();
void upload();
void download();

int main ()
{
    flag=0;
    download();
  /*  if(integer[1]=='\0')
        flag=0;
    flag--; flag++; */

    if(integer[1]==-1){
            printf("DEBUG: CLEANING TRASH.....\n");
            flag=0; getch();}
        else{
           printf("DEBUG: NOT TRASH TO SEE HERE!.....\n");
           getch();
        }

    while (1){
        switch (menu()){
            case 1: Fill(); upload(); break;
            case 2: Display(); break;
            case 3:  Sort(); upload(); break;
            case 4: system("cls");
                printf("THE CONTENT OF ARRAY IS %d",flag);
                printf("\nTHE AVAILABLE ARRAY IS %d",(MAX-flag));
                getch();  break;
            case 5: flag1=0; del(); upload(); break;
            case 6: exit(0); upload(); break;
            default: system("cls"); printf("INVALID NUMBER"); getch();
        }
    }

    return 0;
}

void upload(){
    FILE*fp;
    fp=fopen("integer50.txt","w+");
        for(i=1;i<=flag;i++){
            fprintf(fp,"%d\t",integer[i]);
        }
    fclose(fp);
}

void download(){
    FILE*fp; flag=0;
    fp=fopen("integer50.txt","r+");
    if(fp==NULL){
            integer[1] =-1; upload(); main();
    }
     while(!feof(fp)){
        flag++;
        fscanf(fp,"%d\t",&integer[flag]);
    }
    fclose(fp);
}

// MAIN PROCESS FOR DELETION
void del(){
    system("cls");
    printf("THE 50 INTEGERS ARE: \n");
    for( i=1; i<=flag;i++){
       printf("[%d] %d\t",i,integer[i]);
       if (i==10|| i==20||i==30||i==40||i==50)
        printf("\n");
    }
    printf("\n\nCHOOSE THE CONTENT OF INTEGER TO BE DELETED: ");
    scanf("%d",&num);
        for(a=1;a<=flag;a++){
            if(integer[a]==num){
                temp = a;
                flag1++;
                siz[flag1]=a;
            }
        }

    if(flag1 == 1) {
        del1();
    }
    else {
        system("cls");
        for(d=1;d<=flag1;d++){
            printf("[%d] :  %d\n",siz[d],num);
        }
        printf("WHAT INDEX OF NUMBER %d SHOULD BE DELETED? ",num);
        scanf("%d",&temp); del1();
    }
    Display();
}

// DELETE FUNCTION FOR ARRAY
void del1(){
        for(s=temp;s<=flag;s++){
                integer[s] = integer[s+1];
            }
            flag--;
}

// ARRANGE THE ARRAY FROM LOWEST TO HISHEST
void Sort(){
    int index;
    for(k=2;k<=flag;k++){
        index = integer[k];
        j=k;
            while ((j>1)&&integer[j-1] > index){
                integer[j]=integer[j-1];
                integer[j-1]=index;
                j-=1;
            }
    }
    Display();
}

// DISPLAY THE LIST OF ARRAY
void Display(){
    system("cls");
    printf("THE 50 INTEGERS ARE: \n");
    for( i=1; i<=flag;i++){
       printf("[%d.] %d\t",i,integer[i]);
       if (i==10|| i==20||i==30||i==40||i==50)
        printf("\n");
    }
    getch();
}

// FILL IN THE ENTIRE ARRAY
void Fill(){
    system("cls");
    if (flag < MAX){
            flag++;
            printf("Enter one of 50's integers: ");
            scanf("%d",&integer[flag]);
            printf("--> YOU ENTER INTEGER %d <--",integer[flag]); getch();
    }
    else {
        printf("--> THE 50 INTEGER IS ALREADY FULL <--"); getch();
    }
}

// MENU FUNCTION
int menu(){
    system("cls");
    int answer;
    printf("MENU\n");
    printf("1. Fill array [ 50 integers ]\n");
    printf("2. Print the array\n");
    printf("3. Sort the array\n");
    printf("4. Query the contents of the array\n");
    printf("5. Delete the contents of array\n");
    printf("6. Terminate the program\n");
    printf("\nSELECT NUMBER FROM 1 TO 6:  ");
    while (scanf("%d",&answer) !=1){
        while(getchar() != '\n')
            printf("--->>  YOU ENTERED A CHARACTER  <<--"); getch();
            menu();
    }
    return answer;
}

