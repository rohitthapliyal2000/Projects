#include<stdio.h>

struct attend{                          //Structure to save necessary details of Part I
int n;
int p;
int timings[1000];
}testCases[1000];

struct range{                           //Structure to save necessary details of Part II
int n1;
int n2;
}a[1000];
                                           //GLOBAL VARIABLES
int arg=0;                                 //Variable to check no. of arguments
int check1=0;                              //Variable to check file availability
int testsCheck=0;                          //Variable to check if inputted number matches constraint for the no. of test cases
int np=0;                                  //Variable to check whether inputted number of students are not less than that required as presents
int checkn=0;                              //Variable to check the limits in probability problem
int Bytes=0;                               //Variable to save the size of file. It helps us check whether the file is empty or not

                                          //FUNCTION DECLARATIONS
void A(FILE *);
void B(FILE *);
int checkArgument(int);
int checkFile(FILE *);
int checkTests(int);
int checkNP(int,int);
int checkN1N2(int,int);
int checkBytes(FILE *);

                                               //MAIN MODULE

void main(int argc, char * argv[])
{
    int choice;
    do{
        if(checkArgument(argc)==0)           //Function to check the number of arguments
        {
            exit(0);
        }
        printf("Enter your choice\n1:Project A Part 1\n2:Project A Part 2\n3:Exit the program\t");
        scanf("%d",&choice);
        if(choice==1)
        {
            FILE *fp;
            fp=fopen(argv[1],"r");
            if(checkFile(fp)==0)             //To check if the file exists
                exit(0);
            A(fp);
        }
        else if(choice==2)
        {
            FILE *fp;
            fp=fopen(argv[2],"r");
            if(checkFile(fp)==0)             //To check if the file exists
                exit(0);
            B(fp);
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            printf("\nInvalid Input");
        }
    }while(choice==1 || choice==2);
}

                                            //MODULE 1
int checkArgument(int argc)                //Function to check no. of arguments passed
{
    if(argc==3)
    {
        arg=1;
    }
    else if(argc<3)
    {
        printf("Arguments passed were less than required.");
    }
    else
    {
        printf("Too many arguments passed.");
    }
    return arg;
}

                                                //MODULE 2
int checkFile(FILE * fp)              //Function to check file availability.
{
    if(fp==NULL)
    {
        printf("\nFile does not exist.");
    }
    else
    {
        check1=1;
    }
    return check1;
}

                                                 //MODULE 3
int checkTests(int n)                  //Function to check if no. of test cases are bounded in a constraint.
{
    if(n>=0 && n<=10000)
    {
        testsCheck=1;
    }
    else
    {
        printf("This input won't work for Test cases.");
    }
    return testsCheck;
}

                                                   //MODULE 4
int checkBytes(FILE *fp)                       //Function to check if the file is empty or not.
{
    fseek(fp,0,SEEK_END);
    if(ftell(fp)==0)
        printf("\nFile is empty");
    else
        Bytes=1;
    rewind(fp);
    return Bytes;
}


                                                        //MODULE A(1)

void A(FILE *fp)                                    //Function for Problem A
{
    int tests,i,j;
    if(checkBytes(fp)==0)                     //To check if the file is not empty
        exit(0);
    fscanf(fp,"%d",&tests);
    if(checkTests(tests)==0)                  //To check if the no. of test cases are within bounds
        exit(0);
    for(i=0;i<tests;i++)
    {
        fscanf(fp,"%d %d",&testCases[i].n,&testCases[i].p);
        if(CheckNP(testCases[i].n,testCases[i].p)==0)  //To check if no. of students are greater than or equal to required present students
            exit(0);
        for(j=0;j<testCases[i].n;j++)
        {
            fscanf(fp,"%d",&testCases[i].timings[j]);
        }
    }
    fclose(fp);
    int ch;
    for(i=0;i<tests;i++)
    {
        ch=0;
        for(j=0;j<testCases[i].n;j++)
        {
            if(testCases[i].timings[j]<=0)
            {
                ch++;
            }
        }
        if(ch>=testCases[i].p)
        {
            printf("ON\n");
        }
        else
        {
            printf("OFF\n");
        }
    }
}

                                                        //MODULE A(2)
int CheckNP(int n,int p)                 //Function to check whether inputted number of students are greater than of equal to required as presents.
{
    if(n>=1 && n<=500)
    {
        if(p>=0 && p<=n)
        {
            np=1;
        }
        else
        {
            printf("\nThe input for expected students on time resulted in error.");
        }
    }
    else
    {
        printf("\nThe input for number of students in the class resulted in error.");
    }
    return np;
}


                                                         //MODULE B(1)
void B(FILE *fp)                                     //Function for Problem B
{
    int n,i,j,k,flag,check1=1;
    float c=0;
    if(checkBytes(fp)==0)               //To check if the file is not empty
        exit(0);
    fscanf(fp,"%d",&n);
    if(checkTests(n)==0)                //To check if number of test cases are within the bounds
    {
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d %d",&a[i].n1,&a[i].n2);
        if(CheckN1N2(a[i].n1,a[i].n2)==0)      //To check if range is positive
            exit(0);
    }
    fclose(fp);
    for(i=0;i<n;i++)
    {
        c=0;
        for(k=a[i].n1;k<=a[i].n2;k++)
        {
            flag=0;
            for(j=2;j<=k/2;j++)
            {
                if(k%j==0)
                {
                    flag=1;
                }
            }
            if(flag==0 && k!=1)
                c++;
        }
    printf("%06f\n",c/((a[i].n2)-(a[i].n1)+1));
    }
}

                                                      //MODULE B(2)
int CheckN1N2(int n1,int n2)                     //Function to check whether the limits are correct.
{
    if((n1>=1 && n1<=1000000)&&(n2>=1 && n2<=1000000))
    {
        if(n2>=n1)
        {
            checkn=1;
        }
        else
        {
            printf("\nLimit 2 should be equal or higher than limit 1.\n");
        }
    }
    else
    {
        printf("\nLimit is out of bounds.\n");
    }
    return checkn;
}

