#include "stats.h"
#include "alerter.h"
#include <stdio.h>
#include <math.h>

/* global variable */
alerter_funcptr alerters[] = {emailAlerter, ledAlerter} ;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
  
  if(computedStats.max > maxThreshold)
  {
      /* Send alerts */
     (alerters[0])();//emailAlerter();
     (alerters[1])();//ledAlerter();
  }
  else
  {   /* Do nothing*/
      
  }
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
        if (s.average == 0)
        {
            s.max = NAN;
            s.min = NAN;
            s.average = NAN;
        }
    }
    else
    {
     /* do nothing*/
    }
    return s;
}
