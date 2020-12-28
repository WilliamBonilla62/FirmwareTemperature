#include "FrameWork.h"

#define WATCHDOG_INTERVAL	1
#define MATRIXREAD_INTERVAL	10
uint32_t TimestampWatchdog;
uint32_t TimestampReadMatrix;

void FrameWorkInit(void)
{
	TimestampWatchdog=0;
	TimestampReadMatrix=0;
}
void FrameWorkTask(void)
{
	// HAL_IWDG_Refresh(&hiwdg);
}

uint32_t FrameWorkTimeGet(void)
{
	return HAL_GetTick();
}
uint32_t FrameWorkTimeDiff(uint32_t Compare)
{
	uint32_t TimeDiff=0;
	TimeDiff=Compare-FrameWorkTimeGet();
	return TimeDiff;
}
_Bool FrameWorkTimeIsDue(uint32_t Compare,uint32_t interval)
{
	if(FrameWorkTimeDiff(Compare)>=interval)
		return 1;
	else
		return 0;
}

