#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
    char ip[4][20];

}a[4];

//validate ip
int concat(int a, int b)
{

    char s1[20];
    char s2[20];

    // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    // Concatenate both strings
    strcat(s1, s2);

    // Convert the concatenated string
    // to integer
    int c = atoi(s1);

    // return the formed integer
    return c;
}

int validate_number(char *str) {
   while (*str) {
      if(!isdigit(*str)){ //if the character is not a number, return
         return 0;
      }
      str++; //point to next character
   }
   return 1;
}
int validate_ip(char *ip) { //check whether the IP is valid or not
   int i, num, dots = 0;
   char *ptr;
   if (ip == NULL)
      return 0;
      ptr = strtok(ip, "."); //cut the string using dor delimiter
      if (ptr == NULL)
         return 0;
   while (ptr) {
      if (!validate_number(ptr)) //check whether the sub string is
         return 0;
         num = atoi(ptr); //convert substring to number
         if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, "."); //cut the next part of the string
            if (ptr != NULL)
               dots++; //increase the dot count
         } else
            return 0;
    }
    if (dots != 3) //if the number of dots are not 3, return false
       return 0;
      return 1;
}


int main()
{
    int n[4][4];
    //Intermediate router
    int router_no2;

    n[0][0]=n[1][1]=n[2][2]=n[3][3]=1;

    n[0][2]=0;
    n[0][1]=n[0][3]=1;

    n[1][0]=n[1][2]=1;
    n[1][3]=0;

    n[2][0]=0;
    n[2][1]=n[2][3]=1;

    n[3][0]=n[3][2]=1;
    n[3][1]=0;

    int i,j,k=4,l;
    printf("Routers are connected like this:\n");
    printf("  1 2 3 4\n");
    for(i=0;i<k;i++)
    {   printf("%d ",i+1);
        for(j=0;j<k;j++)
        {
            printf("%d ",n[i][j]);
        }
        printf("\n");
    }

    int num[4],max=0,count=0;
    for(i=0;i<k;i++)
    {
        do
        {
            printf("how many networks are joints in router %d: ",i+1);
            scanf("%d",&num[i]);
            if(num[i]>=0)
                count+=num[i];


        }while(num[i]<0);

        if(max<num[i])
        {
            max=num[i];
        }
    }
    printf("Total networks ip :%d",count);
    int flag1;
    char *sc[20],sd[count*2][20];
    int *im[count*2];
    memset(im,0,sizeof(im));
    for(i=0;i<k;i++)
    {
        for(j=0;j<num[i];j++)
        {
            do{
            printf("\nEnter router %d Network IP address %d: ",i+1,j+1);
            scanf("%s",a[i].ip[j]);
            strcpy(sc,a[i].ip[j]);
            flag1=validate_ip(sc);

            }while(flag1==0);

        }
    }
    printf("\n");
    int check0=0;
    int count0=0;
do{
    char source[20],temp[20],sode[40],sode1[40],source1[20];
    int check;
    int result;
    int router_no,rnc;
    do{
    printf("Enter source IP address: ");
    scanf("%s",source);
    strcpy(sode,source);
    strcat(sode,"*");
    printf(source);
    printf("\n");
    for(i=0;i<=k;i++)
    {
        for(j=0;j<num[i];j++)
        {
            check=0;
            strcpy(temp,a[i].ip[j]);
            /*printf(temp);
            printf("\n");*/
            for(l=0;l<strlen(temp);l++)
            {
                /*printf("t=%c\n",temp[l]);
                printf("s=%c\n",source[l]);*/
                if(temp[l]!=source[l])
                {
                    check=1;
                    break;
                }
            }
            if(check==0){
                router_no=i+1;
                goto lable1; }
        }
    }
    }while(check==1);

lable1:printf("\n");
    printf(check);
    if(check==0)
    {
        printf("Source router is %d",router_no);
    }
    rnc=router_no;

    //Destination
    printf("\n");
    char destination[20],destination1[20];
    int check1;
    int result1;
    int router_no1,dnc;
    do{
    printf("Enter Destination IP address: ");
    scanf("%s",destination);
    strcat(sode,destination);
    printf(destination);
    printf("\n");
    for(i=0;i<=k;i++)
    {
        for(j=0;j<num[i];j++)
        {
            check1=0;
            strcpy(temp,a[i].ip[j]);
            /*printf(temp);
            printf("\n");*/
            for(l=0;l<strlen(temp);l++)
            {
                /*printf("t=%c\n",temp[l]);
                printf("s=%c\n",destination[l]);*/
                if(temp[l]!=destination[l])
                {
                    check1=1;
                    break;
                }
            }
            if(check1==0){
                router_no1=i+1;
                goto lable2; }
        }
    }
    }while(check1==1);
lable2:printf("\n");
    printf(check1);
    if(check1==0)
    {
        printf("Destination router is %d",router_no1);
    }
        dnc=router_no1;
        int check11=0;
        int final1=0;
       
    for(int l2=0;l2<=8;l2++)
    {
       
    strcpy(sode1,sd[l2]);
    final1=l2;
    for(int l1=0;l1<18/*strlen(sd[0])*/;l1++)
            {
                //printf("t=%c\n",sode1[l1]);
                //printf("s=%c\n",sode[l1]);
                if(sode1[l1]!=sode[l1])
                {
                    check11=1;
                    break;
                }
            }
            if(check11==0){
                printf("\nSource IP address:%s \n--> Source Router: %d \n-->Destination Router: %d \n-->Destination IP address:%s",source,router_no,router_no1,destination);
                goto lable5;
            }
    }   strcpy(source1,source);
        strcat(source1,"*");
        strcpy(destination1,destination);
        strcat(source1,destination1);
        strcpy(sd[count0],source1);
        strcpy(sode1,sd[count0]);
       
    int don[5]={0,0,0,0,0};
    int i1=0;
    int i2,i3,i4;
    int con;
    if(n[rnc-1][dnc-1]==1)
        {
            printf("do you want to choose short path for routing purpose->1:");
            scanf("%d",&i4);
                if(i4==1){
                    printf("\nSource IP address:%s \n--> Source Router: %d \n-->Destination Router: %d \n-->Destination IP address:%s",source,router_no,router_no1,destination);
                    strcat(source,"*");
                    strcat(source,destination);
                    strcpy(sd[count0],source);
                    printf("\n%s",sd[count0]);
                    con=concat(router_no,router_no1);
                    im[count0]=con;
                    goto lable4;
                }
        }

lable3:do
    {
    printf("\nEnter intermediate router name:");
    scanf("%d",&router_no2);
            if(n[rnc-1][router_no2-1]==1)
            {
            don[i1]=router_no2;
            i1=i1+1;
            rnc=router_no2;
                    if(n[router_no2-1][dnc-1]==1){
                    printf("to enter more routers->1:");
                    scanf("%d",&i2);
                        if(i2==0)
                        {
                            i3=(int)(sizeof(don)/sizeof(don[0]));
                            printf("Inter mediate routers are:");
                            for(i=0;don[i]!=0;i++){
                                    printf("%d ",don[i]);

                            }
                            con=concat(con,router_no1);
                            im[0]=con;
                            printf("\nSource IP address:%s \n--> Source Router: %d \n-->Destination Router: %d \n-->Destination IP address:%s",source,router_no,router_no1,destination);
                            strcat(source,"*");
                            strcat(source,destination);
                            printf("\nHello %s\n",source);
                            strcpy(sd[count0],source);

                            goto lable4;
                        }
                        else{
                            goto lable3;
                        }
                    }
                    else{
                        goto lable3;
                    }
            }
            else{
                printf("\nInvalid router name!!");
            }
        }while(n[router_no-1][router_no2-1]==0);

        lable4:printf("\ncompleted\n");
        for(i=0;don[i]!=0;i++)
        {
            printf("don[%d]=%d",i,don[i]);
            con=concat(router_no,don[i]);
            router_no=con;
        }
        if(i4!=1)
        {
            con=concat(con,router_no1);
        }
        im[count0]=con;
        printf("\n\nSource Destination details:%s\n\n",sd[0]);
        printf("\n\nIntermediate Routers details:%d\n\n",im[count0]);
   // }
   lable5:if(check11==0)
            {printf("\n\nIntermediate Routers details:%d\n\n",im[final1]);}
printf("for continue press 0:");
scanf("%d",&check0);
count0=count0+1;
}while(check0==0 && count0<=count);
}
