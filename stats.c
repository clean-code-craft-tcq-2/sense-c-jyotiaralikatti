#include "stats.h"
#include <stdio.h>

/* global variables */

int emailAlertCallCount = 0 ;
int ledAlertCallCount = 0;
alerter_funcptr alerters[] = {emailAlerter, ledAlerter} ;

int main()
{
    /* Enter different values of array elements or use scanf for the same*/
    float numberset[] =  {99.8, 34.2, 4.5};//= {1.5, 8.9};// pointer to constant flaot
    
    int i,setlength = sizeof(numberset) / sizeof(numberset[0]);
    
    struct Stats computedStats = compute_statistics(numberset, setlength);
    
    check_and_alert(maxThreshold, alerters, computedStats);
    
    //Printing elements of computedStats
    printf("\n Elements of numberset ");
    for (i=0; i<setlength; i++)
    {
    printf("\n %f \t",numberset[i]);
    }
    printf("\n Elements of computedStats ");
    printf("\n %f \t %f \t %f \t ",computedStats.max,computedStats.min,computedStats.average);
    
    //Printing check and alert status
    if (emailAlertCallCount && ledAlertCallCount)
    {/* max > Threshhold*/
        printf("\n ALERT !!..emailAlertCallCount: %d \t ledAlertCallCount: %d", emailAlertCallCount,ledAlertCallCount);
        emailAlertCallCount = 0;
        ledAlertCallCount = 0;
    }
    else
    printf("\n emailAlertCallCount: %d \t ledAlertCallCount: %d", emailAlertCallCount,ledAlertCallCount );
    
    
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
  
  if(computedStats.max > maxThreshold)
  {
      /* Send alerts */
     (alerters[0])();//emailAlerter();
      (alerters[1])();//ledAlerter();
  }
  else
  { /* Do nothing*/
  }

}

void emailAlerter()
{
     emailAlertCallCount = 1;
}
void ledAlerter()
{
     ledAlertCallCount = 1;
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    /* Elemts of Struct Stats*/
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
     emailAlertCallCount = 0;
     ledAlertCallCount = 0;
    
    float sum = 0;
    int  i=0;
    
    s.max=numberset[0];
    s.min=numberset[0];
    
    if((numberset != NULL) && (setlength != 0))
    {       
        for (i=0; i<setlength; i++)
        {
          if (numberset[i]> s.max)
          {
              s.max=numberset[i];
          }
          else if (numberset[i]<s.min)
          {
             s.min=numberset[i];
          }
          else
          {
              /* do nothing */
          }    
          sum += numberset[i];
        }
        s.average =(float)(sum/setlength);
    }
    else
    {
        s.max = NAN;
        s.min = NAN;
        s.average = NAN;
    }

    return s;
}
