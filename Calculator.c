#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 10000

void reverse(char *n1, char *n2);
int call_minus(char *large, char *small, char *result);
int validate(char []);
char * division(char[],long);
long int rem;
char * multiply(char [],char[]);
void main()
{
    printf("\a \t\t\t OPERATION ON LARGE NUMBERS \n");
    printf("\t\t\t --------------------------\n");
    int ch;
    printf("CHOICE MENU:\n\n\n");
    printf("Enter 1 for Addition\n");
    printf("Enter 2 for Subtraction\n");
    printf("Enter 3 for Multiplication\n");
    printf("Enter 4 for Division\n");
    printf("Enter q to Quit\n\n\n");
    printf("ENTER YOUR CHOICE: _\b");

    scanf("%d",&ch);
    do{
        switch(ch)
        {
            case 1:
            {
                int a[MAX],b[MAX],s[MAX];
                int ac=0,bc=0,sc=0;
                int r = 0,i;
                char num1[MAX],num2[MAX],*pa,*pb;
                printf("\aEnter first number : ");
                scanf("%s",&num1);
                printf("\nEnter second number : ");
                scanf("%s",&num2);
                pa = num1;
                pb = num2;

                while(*pa)
                {
                    a[ac++] = *pa++ - '0';
                }

                while(*pb)
                {
                     b[bc++] = *pb++ - '0';
                }

                if(ac<bc)
                {
                     for(i = ac;i > 0;i--)
                     {
                         s[sc++]= ((a[i-1] + b[--bc]) + r)%10;
                         r = ((a[i-1] + b[bc]) + r)/10;
                     }
                     while(bc>0)
                     {
                         s[sc++] = b[--bc] + r;
                         r = 0;
                     }
                }
                else
                {
                     for(i = bc;i > 0;i--)
                     {
                         s[sc++]= ((b[i-1] + a[--ac]) + r)%10;
                         r = ((b[i-1] + a[ac]) + r)/10;
                     }
                     if(ac==0 && r==1)
                         s[sc++] = r;
                     while(ac>0)
                     {
                         s[sc++] = a[--ac] + r;
                         r = 0;
                     }
                }
                printf("Sum of both number is : ");
                for(i=sc-1;i>=0;i--)
                {
                     printf("%d",s[i]);
                }
                return 0;
                }break;

    //SUBTRACTION
            case 2:
                {
                    int i;
                    char a[MAX],b[MAX],res[MAX];
                    printf("Enter Two numbers: \t");
                    while(scanf("%s %s",&a,&b)==2)
                    {
                        if(call_minus(a,b,res)==1)
                        printf("-");
                        int len = strlen(res);
                        for( i=0;i<len;i++)
                        printf("%c",res[i]);
                        printf("\n");
                    }
                }break;


    //MULTIPLICATION
            case 3:
            {

                char a[MAX];
                char b[MAX];
                char *c;
                int la,lb;
                int i;
                printf("Enter the first number : ");
                scanf("%s",a);
                printf("Enter the second number : ");
                scanf("%s",b);
                printf("Multiplication of two numbers : ");
                c = multiply(a,b);
                printf("%s",c);
                return 0;

            }break;
    //DIVISION
            case 4:
            {
                char dividend[MAX],*quotient;
                long int divisor;
                printf("Enter dividend: ");
                scanf("%s",dividend);
                if(validate(dividend))
                     return 0;
                printf("Enter divisor: ");
                scanf("%ld",&divisor);
                quotient = division(dividend,divisor);
                while(*quotient)
                     if(*quotient =='0')
                         quotient++;
                     else
                         break;
                printf("Quotient: %s / %ld  =  %s",dividend,divisor,quotient);
                printf ("\nrem: %ld",rem);
                return 0;
            }break;


            default :
                printf("\a\a\a\a Wrong choice!! :-/ \n");
        }
    }
    while (ch != 'q');
}


//______________________________________________________________________________________________________________________________

//Function for Subtraction

void reverse(char *n1, char *n2)
    {
        int len=strlen(n1);
        int l;
        for(l=0;l<len;l++)
        n2[l]=n1[len-l-1];
        n2[len]='\0';
    }


int call_minus(char *large, char *small, char *result)
    {
        char L[MAX], S[MAX];
        int l,s,now,hold,diff;
        l=strlen(large);
        s=strlen(small);
        int sign = 0;
        if(l<s)
            {
            strcpy(result,large);
            strcpy(large,small);
            strcpy(small,result);
            now=l; l=s; s=now;
            sign = 1;
            }


        if(l==s)
            {
                if(strcmp(large, small)<0)
                {
                    strcpy(result,large);
                    strcpy(large,small);
                    strcpy(small,result);
                     now=l; l=s; s=now;
                     sign =1;
                }
           }
        reverse(large,L);
        reverse(small,S);
        for(;s<l;s++)
        S[s]='0';
        S[s]='\0';
        for(now=0,hold=0;now<l;now++)
        {
            diff=L[now]-(S[now]+hold);
            if(diff<0)
            {
                hold=1;
                result[now]=10+diff+'0';
            }
            else
            {
                result[now]=diff+'0';
                hold=0;
            }
        }
        for(now=l-1;now>0;now--)
        {
            if(result[now]!='0')
            break;
        }
        result[now+1]='\0';
        reverse(result,L);
        strcpy(result,L);
        return sign;
    }


//Function for multiplication
char * multiply(char a[],char b[])
{
    char mul[MAX];
    char c[MAX];
    char temp[MAX];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
    lb=strlen(b)-1;
    for(i=0;i<=la;i++)
    {
         a[i] = a[i] - '0';
    }
    for(i=0;i<=lb;i++)
    {
         b[i] = b[i] - '0';
    }
    for(i=lb;i>=0;i--)
    {
         r=0;
         for(j=la;j>=0;j--)
         {
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y=0;y<x;y++)
         {
             temp[k++] = 0;
         }
    }
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++)
    {
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++)
         {
             if(i <= la+j)
             {
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--)
    {
         mul[j++]=c[i] + '0';
    }
    mul[j]='\0';
    return mul;
}

 //Function for division

int validate(char num[])
{
    int i=0;
    while(num[i])
    {
         if(num[i] < '0' || num[i]> '9')
         {
             printf("Invalid positive integer: %s",num);
             return 1;
         }
         i++;
    }
    return 0;
}
char * division(char dividend[],long divisor)
{
    char quotient[MAX];
    long temp=0;
    int i=0,j=0;
    while(dividend[i])
    {
        temp = temp*10 + (dividend[i] -'0');
        if(temp<divisor)
        {
            quotient[j++] = '0';
        }
        else
        {
             quotient[j++] = (temp / divisor) + '0';;
             temp = temp % divisor;
        }
        i++;
    }
    quotient[j] = '\0';
    rem = temp;
    return quotient;
}

//_____________________________________________________________THANK-You!!!!_________________________________________________________
