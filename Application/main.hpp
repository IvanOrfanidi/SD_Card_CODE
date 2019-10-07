/**
 ******************************************************************************
 * @file    main.hpp
 * @author  Ivan Orfanidi
 * @version V1.0.0
 * @date    28-March-2018
 * @brief   This file main programs
 ******************************************************************************
 * @attention
 *
 *
 *
 ******************************************************************************
**/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_HPP
#define __MAIN_HPP

/* Includes ------------------------------------------------------------------*/

/* Driver MCU */
#include "stm32f10x.h"

/* User */

/* Divers */
#include "systick.hpp"
#include "interrupt.hpp"
#include "uart.hpp"
#include "rtc.hpp"

/* SD Card and FatFs */
//#include "sdcard.h"
//#include "ff.h"
//#include "diskio.h"

/* USB */

#ifdef __cplusplus

/* Standart */
#include <stdint.h>
#include <time.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

// Filename extension
constexpr auto EXTENSION_LOG_FILE = ".txt";

/**
 * @brief Class Main
 */
class Main {
  public:
    /// Default value
    enum Default_t {
        NUM_DRV = 0,

        MAX_TIME_TO_SCAN_SDCARD = 10,    ///< Maximum time to scan sd card
    };

    /// All delays in msec
    enum Delay_t : time_t {
        BEFORE_REBOOT_DEVICE = 500,
        SCAN_SDCARD = 100,
        ON_ERROR = 250
    };

    /// Status
    enum Status_t {
        NO_ERROR,
        ERR_WRITE_PROTECTED,
        ERR_MOUNT_DISK,
        ERR_UNMOUNT_DISK,
        ERR_SD_CARD,
        ERR_CREATE_CONFIG_FILE,
        ERR_CREATE_FILE,
        ERR_OPEN_FILE,
        ERR_MOVE_POINTER_TO_END,
        ERR_WRITE_TO_FILE
    };

    /// File configuration
    struct File_t {
        std::string Name;
        size_t MaxSize;
    };

    Main();

  private:
    uint8_t _Drv;    ///< Number driver

    Rtc* _Rtc;    ///< Class RTC
};

extern "C" {
}

#endif    //__cplusplus

#endif