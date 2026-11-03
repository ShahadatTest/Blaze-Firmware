//
// Created by rich on 10/22/26.
//

#include "user_threads.h"

#include "cmsis_os.h"
#include "main.h"

void userDefaultTask(void* argument)
{
    (void)argument;
    for (;;)
    {
        // Keep the independent watchdog alive while bring-up only delays.
        // MX_IWDG_Init() starts IWDG; without a refresh the MCU resets ~every
        // (prescaler * reload) / LSI ≈ 8 s with the current Cube settings.
        HAL_IWDG_Refresh(&hiwdg);
        osDelay(1);
    }
}
