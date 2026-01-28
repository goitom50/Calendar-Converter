#include<stdio.h>
int ECtoGC(int,int,int);
int GCtoEC(int,int,int);
int main()
{
    int type;
    int ed,em,ey,gd,gm,gy;
   printf("Which conversion do you want?\n");
   printf("1-EC to GC     2-GC to EC \n" );
   scanf("%d",&type);
       switch(type)
       {
      
       case 1:
           printf("Enter the Gregorian calendar date in dd mm yyyy Format:");
           scanf("%d%d%d",&gd,&gm,&gy);
           GCtoEC(gd,gm,gy);
          break;
          
           case 2:
           printf("Enter the Ethiopian calendar date in dd mm yyyy Format:");
           scanf("%d%d%d",&ed,&em,&ey);
           ECtoGC(ed,em,ey);
          break;
       default:
         printf("Invalid entry");
       }

 return 0;
}
 int GCtoEC(int gday,int gmonth,int gyear)
 {
         int days;
         if(gyear)
        {
            if(gmonth>=1 &&gmonth<=12)
                {
                   if(gmonth==1|| gmonth==3|| gmonth==5||gmonth==7|| gmonth==8|| gmonth==10||gmonth==12 )
                            days=31;
                    else if(gmonth==4|| gmonth==6|| gmonth==9||gmonth==11)
                            {
                           days=30;
                           }
                           else
                           {
                             if((gyear%4==0&&gyear%100!=0)||gyear%400==0)
                              days=29;
                            else
                            days=28;
                           }
                   }
                     else
                      {
                         printf("Sorry your date is Invalid!\n");
                         return 0;
                      }
        }
         else
  {
     printf("Sorry your date is Invalid!\n");
     return 0;
  }
      if(gday>=1 &&gday<=days)
          {
		int jdn = ( 1461 * ( gyear + 4800 + ( gmonth - 14 ) / 12 ) ) / 4 +
          ( 367 * ( gmonth - 2 - 12 * ( ( gmonth - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( gyear + 4900 + ( gmonth - 14 ) / 12 ) / 100 ) ) / 4 +
          gday - 32075 ;

        int joffset=1723856;
        int r =  (jdn- joffset)%1461 ;
        int n = (r%365) + (365*(r/1460));
        int eyear = 4*((jdn - joffset)/1461)+ (r/365) - (r/1460);
        int emonth = (n/30)+ 1;
        int eday = (n%30) + 1 ;
        printf("Date in Ethiopian Calendar in dd mm yyyy Format: %d  %d  %d \n", eday,emonth,eyear);
        return 0;

           }
      else
      {
           printf("Sorry your date is Invalid!\n");
           return 0;
      }
 }
  int ECtoGC(int eday,int emonth,int eyear)
  {
            int days;
        if(eyear)
        {
            if(emonth>=1 &&emonth<=13)
                {
                    if(emonth<=12)
                            days=30;
                     else
                            {
                            if(eyear%4==3)
                              days=6;
                            else
                            days=5;
                           }
                }
                     else
                      {
                         printf("Sorry your date is Invalid!\n");
                         return 0;
                      }
        }
         else
  {
     printf("Sorry your date is Invalid!\n");
     return 0;
  }
      if(eday>=1 &&eday<=days)
          {
            int joffset = 1723856;
            int jdn = ( joffset + 365 )+ 365 * ( eyear - 1 )+  (eyear/ 4 ) + 30 * emonth+ eday - 31 ;

	      int  l = jdn+ 68569;
	       int N= ( 4 * l ) / 146097;
	        l = l - ( 146097 * N+ 3 ) / 4;
	        int i = ( 4000 * ( l + 1 ) ) / 1461001;
	        l = l - ( 1461 * i ) / 4 + 31;
	        int j = ( 80 * l ) / 2447;
	        int gday = l - ( 2447 * j ) / 80;
	        l = j / 11;
	        int gmonth = j + 2 - ( 12 * l );
	       int gyear= 100 * ( N - 49 ) + i + l ;
	       printf("Date in Gregorian Calendar in dd mm yyyy Format: %d  %d   %d \n",gday,gmonth,gyear);
	       return 0;

          }
      else
      {
           printf("Sorry your date is Invalid!\n");
           return 0;
      }

     }
