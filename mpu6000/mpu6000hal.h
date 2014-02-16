#ifndef __MPU6000_HAL_H
#define __MPU6000_HAL_H

#include <stdbool.h>
#include "stm32f10x.h"

/*
 *  Hardware abstract layer typedef
 */
typedef struct
{
	SPI_TypeDef	*spi;
	void	        (*spiPeriphClockCmd)();
	uint32_t	spiPeriphClk;
	uint32_t	spiGpioClk;
	GPIO_TypeDef	*spiGpioPort;
	uint16_t	spiSckPin;
	uint16_t	spiMisoPin;
	uint16_t	spiMosiPin;
	uint16_t	spiBaudRatePrescaler1M;
	uint16_t	spiBaudRatePrescaler20M;
	
	uint32_t	extiLine;
	uint8_t	        irqGpioPortSource;
	uint8_t	        irqGpioPinSource;
	bool		irqHandlerEnable;
	IRQn_Type	extiIRQn;
	uint8_t	        irqCPP;	/* IRQ Channel Preemption Priority */
	uint8_t	        irqCSP;	/* IRQ Channel Subpriority */

	uint32_t	csGpioClk;
	GPIO_TypeDef	*csGpioPort;
	uint16_t	csGpioPin;

	uint32_t	intGpioClk;	/* If not used, leave this variable unmodified (0x0000) */
	GPIO_TypeDef	*intGpioPort;
	uint16_t	intGpioPin;

	uint32_t	fsyncGpioClk;	/* If not used, leave this variable unmodified (0x0000) */
	GPIO_TypeDef	*fsyncGpioPort;
	uint16_t	fsyncGpioPin;
} mpu6000Hal_t;

void mpu6000AssertCs(mpu6000Hal_t *hal);
void mpu6000ReleaseCs(mpu6000Hal_t *hal);

void mpu6000DelayMs(uint8_t ms);
bool mpu6000Read(mpu6000Hal_t *hal, uint8_t addr, uint8_t len, uint8_t *data);

bool mpu6000ReadByte(mpu6000Hal_t *hal, uint8_t addr, uint8_t *data);
void mpu6000Write(mpu6000Hal_t *hal, uint8_t addr, uint16_t len, uint8_t *data);
void mpu6000WriteByte(mpu6000Hal_t *hal, uint8_t addr, uint8_t data);
bool mpu6000ReadBit(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitNum, uint8_t *data);
bool mpu6000ReadBits(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitStart, uint8_t length, uint8_t *data);
void mpu6000WriteBit(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitNum, uint8_t data);
void mpu6000WriteBits(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitStart, uint8_t length, uint8_t data);

void mpu6000GpioInit(mpu6000Hal_t *hal);
void mpu6000IrqInit(mpu6000Hal_t *hal);
void mpu6000SpiInit(mpu6000Hal_t *hal);

void mpu6000SetSpiFreq20M(mpu6000Hal_t *hal);
void mpu6000SetSpiFreq1M(mpu6000Hal_t *hal);

bool mpu6000GetIntPinStatus(mpu6000Hal_t *hal);

void mpu6000HalInit(mpu6000Hal_t *hal);

#endif

