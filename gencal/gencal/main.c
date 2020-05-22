//
//  main.c
//  gencal
//
//  Created by Joshua Maitoza on 11/4/19.
//  Copyright © 2019 Joshua Maitoza. All rights reserved.
//  I Joshua Maitoza, certify that this is my own work and that I have not collaborated with anyone.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int getndim(int m, int y);
int getdaycode(int m, int d, int y);
void printheader(int m, int y);
void genmonth(int m, int y);

int main()
{
    int m;
    int y;
    int n = 1;
    
    while(n >=1) //unless user inputs a 0 program will continue to run
    {
        printf("Enter number for month: ");
        scanf("%d", &m);
        printf("Enter number for year: ");
        scanf("%d", &y);
        printf("Enter the amount of months you want to be calculated: ");
        scanf("%d", &n);
        
        for(int i = 0; i < n; i++)
        {
            if(m <=12) //if the month is under 12 continue to run
            {
                printheader(m,y);
                genmonth(m,y);
                printf("\n\n");
                m++;
            }
            else //once month passes 12 resets month back to one (jan) and add a year
            {
                m = 1;
                y++;
                
                printheader(m,y);
                genmonth(m,y);
                printf("\n\n");
                m++;
            }
        }
    }
}

int getndim(int m, int y) //function gets number of days in chosen month
{
    switch(m)
    {
        case 1:
            return 31;
            
        case 3:
            return 31;
            
        case 5:
            return 31;
            
        case 7:
            return 31;
            
        case 8:
            return 31;
            
        case 10:
            return 31;
            
        case 12:
            return 31;
            
            
        case 4:
            return 30;
            
        case 6:
            return 30;
            
        case 9:
            return 30;
            
        case 11:
            return 30;
            
        
        case 2:
        {
            if(((y%4==0) && (y%100!=0)) || (y % 400 ==0))
            {
                return 29;
                
            }
            
            else
            {
                return 28;
                
            }
        }
        default: return -1;
    }
}

int getdaycode(int m, int d, int y) //gets the daycode for the first day
{
    int numdays = 0;
    int badyears = 0; //days in years before 1753
    int daycode = 0;
    
    badyears = (1752)*365 + ((1752)/4)-((1752)/100)+((1752)/400); //calculates amount of days between 12/31/1752 and 1/1/0001

    numdays = numdays + ((y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400); //calculates days in years between 12/31/((user input year)-1)
    numdays = numdays - badyears; //subtracts the amount of days from badyears from days in all years to give you only days from 1753 onward
    
    switch(m) //checks which month was chosen and adds appropriate days
    {
       case 1:
       {
           numdays = numdays;
           break;
       }
       
       case 2:
       {
           numdays = numdays + 31;
           break;
       }
       
       case 3:
       {
           numdays = numdays + 31 + 28;
           break;
       }
       
       case 4:
       {
           numdays = numdays + 31 + 28 + 31;
           break;
       }
       
       case 5:
       {
           numdays = numdays + 31 + 28 + 31 + 30;
           break;
       }
       
       case 6:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31;
           break;
       }
       
       case 7:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31 + 30;
           break;
       }
       
       case 8:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31 + 30 + 31;
           break;
       }
       
       case 9:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
           break;
       }
       
       case 10:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
           break;
       }
       
       case 11:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
           break;
       }
           
       case 12:
       {
           numdays = numdays + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
           break;
       }
       
       default: return -1;
    }
    
    numdays = numdays + d; // adds days input by user to total numdays

    if(((y%4==0) && (y%100!=0)) || (y % 400 ==0)) // if it is a leap year and march 1 or onward program adds one day to numdays
    {
        if(m >= 3)
        {
            numdays++;
        }
    }

    numdays = numdays % 7; //finds remainder for numdays
    daycode = numdays;
    

    return daycode; //returns number of days in desired year
}

void printheader(int m, int y) //prints the header for the month and year that was input
{
    switch(m)
    {
        case 1:
        {
            printf("\n         January %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
            
        case 2:
        {
            printf("\n         February %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 3:
        {
            printf("\n         March %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 4:
        {
            printf("\n         April %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 5:
        {
            printf("\n         May %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 6:
        {
            printf("\n         June %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 7:
        {
            printf("\n         July %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 8:
        {
            printf("\n         August %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 9:
        {
            printf("\n         September %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 10:
        {
            printf("\n         October %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 11:
        {
            printf("\n         November %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
        case 12:
        {
            printf("\n         December %d\n Sun Mon Tue Wed Thu Fri Sat\n", y);
            break;
        }
    }
}

void genmonth(int m, int y) //generates the month calender
{
    int ndim = getndim(m,y);
    
    int daycode = getdaycode(m,1,y);
    
    switch(daycode) //based on what number is gotten from daycode, outputs correct amount of spaces to line up with header
    {
        
        case 0:
            
            break;
        
            
        case 1:
        {
            
                printf("    ");
            
            break;
        }
            
        case 2:
        {
            
                printf("        ");
            
            break;
        }
            
        case 3:
        {
            
                printf("            ");
            
            break;
        }
            
        case 4:
        {
            
                printf("                ");
            
            break;
        }
            
        case 5:
        {
            
                printf("                    ");
            
            break;
        }
            
        case 6:
        {
            
                printf("                        ");
            
            break;
        }
    }
    
    if(ndim == 31)
    {
        for(int i = 1; i<32; i++)
        {
            if(i <= 9)
            {
                printf("   %d", i);
                if(daycode == 6)
                {
                    printf("\n");
                    daycode = 0;
                    daycode--;
                }
                daycode++;
            }
            else
            {
                printf("  %d", i);
                if(daycode == 6)
                {
                    printf("\n");
                    daycode = 0;
                    daycode--;
                }
                daycode++;
            }
        }
    }
    
    if(ndim == 30)
    {
        for(int i = 1; i<31; i++)
        {
            if(i <= 9)
            {
                printf("   %d", i);
                if(daycode == 6)
                {
                    printf("\n");
                    daycode = 0;
                    daycode--;
                }
                daycode++;
            }
            else
            {
                printf("  %d", i);
                if(daycode == 6)
                {
                    printf("\n");
                    daycode = 0;
                    daycode--;
                }
                daycode++;
            }
        }
    }
    
    if(ndim == 29)
    {
      for(int i = 1; i<30; i++)
      {
          if(i <= 9)
          {
              printf("   %d", i);
              if(daycode == 6)
              {
                  printf("\n");
                  daycode = 0;
                  daycode--;
              }
              daycode++;
          }
          else
          {
              printf("  %d", i);
              if(daycode == 6)
              {
                  printf("\n");
                  daycode = 0;
                  daycode--;
              }
              daycode++;
          }
      }
    }
    
    if(ndim == 28)
    {
        for(int i = 1; i<29; i++)
        {
            if(i <= 9)
            {
                printf("   %d", i);
                if(daycode == 6)
                {
                    printf("\n");
                    daycode = 0;
                    daycode--;
                }
                daycode++;
            }
            else
            {
                printf("  %d", i);
                if(daycode == 6)
                {
                    printf("\n");
                    daycode = 0;
                    daycode--;
                }
                daycode++;
            }
        }
    }
}
