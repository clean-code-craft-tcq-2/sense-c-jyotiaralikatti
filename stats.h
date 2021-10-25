#include<stdbool.h>

struct Stats
{
	float average;
	float min;
	float max;
};

#define NAN 0;// remove this
const float maxThreshold = 10.2 ;
struct Stats compute_statistics(const float* numberset, int setlength);

typedef void (*alerter_funcptr)(void);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

bool emailAlerter(void);
bool ledAlerter(void);

//alerter_funcptr alerters[2] = {emailAlerter, ledAlerter};

extern int emailAlertCallCount;
extern int ledAlertCallCount;


