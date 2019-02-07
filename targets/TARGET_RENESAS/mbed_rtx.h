/* mbed Microcontroller Library
 * Copyright (c) 2016 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_MBED_RTX_H
#define MBED_MBED_RTX_H

#include <stdint.h>

#if defined(TARGET_RZ_A1H) || defined(TARGET_VK_RZ_A1H) || defined(TARGET_GR_LYCHEE)

#if defined(__ARMCC_VERSION)
    extern uint32_t Image$$ARM_LIB_STACK$$Base[];
    extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit[];
    extern uint32_t Image$$ARM_LIB_HEAP$$Base[];
    #define ISR_STACK_START       Image$$ARM_LIB_STACK$$Base
    #define ISR_STACK_SIZE        (uint32_t)(Image$$ARM_LIB_STACK$$ZI$$Limit - Image$$ARM_LIB_STACK$$Base)
    #define INITIAL_SP            Image$$ARM_LIB_STACK$$ZI$$Limit
    #define HEAP_START            Image$$ARM_LIB_HEAP$$Base
    #define HEAP_SIZE             (uint32_t)(ISR_STACK_START - HEAP_START)
#elif defined(__GNUC__)
    #define INITIAL_SP            (&__StackTop)
#elif defined(__ICCARM__)
    /* No region declarations needed */
#else
    #error "no toolchain defined"
#endif
#endif

#endif  // MBED_MBED_RTX_H
