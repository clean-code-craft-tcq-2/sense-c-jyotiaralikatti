#include "stats.h"
#include <stdio.h>

/* global variables */
//maxThreshold = 10.2;
int emailAlertCallCount = 0 ;
int ledAlertCallCount = 0;

int main()
{
    float numberset[] = {1.5, 8.9};// pointer to constant flaot
    int i,setlength = sizeof(numberset) / sizeof(numberset[0]);
    struct Stats computedStats = compute_statistics(numberset, setlength);
    
    //Printing elements of computedStats
    printf("\n Elements of numberset ");
    for (i=0; i<setlength; i++)
    {
    printf("\n %f \t",numberset[i]);
    }
    printf("\n Elements of computedStats ");
    printf("\n %f \t %f \t %f \t ",computedStats.max,computedStats.min,computedStats.average);
    
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    
    
}

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    /* Elemts of Struct Stats*/
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    int emailAlertCallCount = 0;
    int ledAlertCallCount = 0;
    
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
