#include <cstdlib>
#include<iostream>
using namespace std;
class EthiopianDate
{
   private:
   	int eday;
   	int emonth;
   	int eyear;
  public:
  	EthiopianDate();
  	EthiopianDate(int,int,int);
  	int checkEthiopianDate(int,int,int);
  	int EthiopianToJDN(int eday,int emonth,int eyear);
  	EthiopianDate JDNtoEthiopian(int jdn2);
  	void printEthiopianDate();
};

class GregorianDate
{
   private:
   	int gday;
   	int gmonth;
   	int gyear;
  public:
	GregorianDate();
	GregorianDate(int,int,int);
  	int checkGregorianDate(int,int,int);
  	int GregorianToJDN(int gday,int gmonth,int gyear);
  	GregorianDate JDNtoGregorian(int jdn1);
  	void printGregorianDate();
};
EthiopianDate::EthiopianDate()
{
   eday=0;
   emonth=0;
   eyear=0;
}
EthiopianDate::EthiopianDate(int edd,int emm,int eyy)
{
   eday=edd;
   emonth=emm;
   eyear=eyy;
}
int EthiopianDate::checkEthiopianDate(int eday,int emonth,int eyear)
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
                         cout<<"Sorry your date is Invalid!"<<endl;
                         exit(1);
                      }
        }
         else
  {
     cout<<"Sorry your date is Invalid!"<<endl;
     exit(1);
  }
      if(eday>=1 &&eday<=days)
          {
	       return true;

          }
      else
      {
           cout<<"Sorry your date is Invalid!"<<endl;
           exit(1);
      }

}
int EthiopianDate::EthiopianToJDN(int eday,int emonth,int eyear)
{
            int joffset = 1723856;
            int jdne = ( joffset + 365 )+ 365 * ( eyear - 1 )+  (eyear/ 4 ) + 30 * emonth+ eday - 31 ;
            return jdne;
}
EthiopianDate EthiopianDate::JDNtoEthiopian(int jdn1)
{
	int edd,emm,eyy;
         int joffset=1723856;
        int r =  (jdn1- joffset)%1461 ;
        int n = (r%365) + (365*(r/1460));
        eyy = 4*((jdn1 - joffset)/1461)+ (r/365) - (r/1460);
        emm = (n/30)+ 1;
        edd = (n%30) + 1 ;
	return EthiopianDate(edd,emm,eyy);
}
void EthiopianDate::printEthiopianDate()
{
   cout<<"Date in Ethiopian Calendar in dd mm yyyy Format: "<< eday<< " "<<emonth<< " "<<eyear<<endl;
}

GregorianDate::GregorianDate()
{
   gday=0;
   gmonth=0;
   gyear=0;
}
GregorianDate::GregorianDate(int gdd,int gmm,int gyy)
{
   gday=gdd;
   gmonth=gmm;
   gyear=gyy;
}
int GregorianDate::checkGregorianDate(int gday,int gmonth,int gyear)
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
                         cout<<"Sorry your date is Invalid!"<<endl;
                         exit(1);
                      }
        }
         else
  {
     cout<<"Sorry your date is Invalid!"<<endl;
      exit(1);
       }
      if(gday>=1 &&gday<=days)
          {
        return true;

           }
      else
      {
           cout<<"Sorry your date is Invalid!"<<endl;
           exit(1);
      }
}
int GregorianDate::GregorianToJDN(int gday,int gmonth,int gyear)
{
	int jdng = ( 1461 * ( gyear + 4800 + ( gmonth - 14 ) / 12 ) ) / 4 +
          ( 367 * ( gmonth - 2 - 12 * ( ( gmonth - 14 ) / 12 ) ) ) / 12 -
          ( 3 * ( ( gyear + 4900 + ( gmonth - 14 ) / 12 ) / 100 ) ) / 4 +
          gday - 32075 ;
          return jdng;
}
GregorianDate GregorianDate::JDNtoGregorian(int jdn2)
{
        int gdd,gmm,gyy;
	        int  l = jdn2+ 68569;
	       int N= ( 4 * l ) / 146097;
	        l = l - ( 146097 * N+ 3 ) / 4;
	        int i = ( 4000 * ( l + 1 ) ) / 1461001;
	        l = l - ( 1461 * i ) / 4 + 31;
	        int j = ( 80 * l ) / 2447;
	         gdd = l - ( 2447 * j ) / 80;
	        l = j / 11;
	         gmm = j + 2 - ( 12 * l );
	       gyy= 100 * ( N - 49 ) + i + l ;
		return GregorianDate(gdd,gmm,gyy);
}
void GregorianDate::printGregorianDate()
{
cout<<"Date in Gregorian Calendar in dd  mm yyyy Format: "<<gday<<" "<<gmonth<<" "<<gyear<<endl;
}


int main()
{
   EthiopianDate edate,ethioDate;
   GregorianDate gdate,greDate;
   int type;
   cout<<"Which conversion do you want?"<<endl;
  cout<<"1-EC to GC     2-GC to EC " <<endl;
   cin>>type;
   switch(type)
   {
       case 1:
           int ed,em,ey,jdn1;
           cout<<"Enter the Ethiopian calendar date in dd mm yyyy Format:";
           cin>>ed>>em>>ey;
            edate.checkEthiopianDate(ed,em,ey);
            jdn1=edate.EthiopianToJDN(ed,em,ey);
            greDate=gdate.JDNtoGregorian(jdn1);
            greDate.printGregorianDate();
        break;
        case 2:
             int gd,gm,gy,jdn2;
            cout<<"Enter the Gregorian calendar date in dd mm yyyy Format:";
            cin>>gd>>gm>>gy;
            gdate.checkGregorianDate(gd,gm,gy);
            jdn2=gdate.GregorianToJDN(gd,gm,gy);
            ethioDate=edate.JDNtoEthiopian(jdn2);
            ethioDate.printEthiopianDate();
         break;
        default:
       cout<<"Invalid entry"<<endl;
   }
return 0;
}

