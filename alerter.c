#include "stats.h"
#include "alerter.h"


/* global variables */
int emailAlertCallCount = 0 ;
int ledAlertCallCount = 0;

void emailAlerter()
{
     emailAlertCallCount = 1;
}
void ledAlerter()
{
     ledAlertCallCount = 1;
}
