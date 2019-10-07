
/* User lib */
#include "main.hpp"

/* Global --------------------------------------------------------------------*/
uint32_t Mass_Memory_Size = 0;
uint32_t Mass_Block_Size = 0;
uint32_t Mass_Block_Count = 0;

/**
 * @brief General functions main
 */
int main()
{
    Main();
}

/**
 * @brief General functions main in class
 */
Main::Main() : _Drv(NUM_DRV)
{
    // Set NVIC Priority Group (4 bits for preemption priority, 0 bits for subpriority)
    Interrupt::setPriorityGroup(Interrupt::PriorityGroup::_4);

    // Get Instance
    auto systick = Systick::getInstance();
    // Configure 1 tick - 1 msec
    systick->init(SystemCoreClock, 1000);

    // Initialisation RTC
    _Rtc = Rtc::getInstance();

    while(true) {
    }
}