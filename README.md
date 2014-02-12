stm32f1tmplt
============

Keil 5 project template for STM32F1 series MCU, with CMSIS lib. and STM32 Standard Peripheral Library.

Developing MPU6000 driver in branch mpu6000experiment. The driver has true separated hardware abstraction layer and device function layer. The goal is to create a "C code version" of MPU6000 product manual in device function layer so that migrating to other platform becomes easy (just write another h.a. layer).
