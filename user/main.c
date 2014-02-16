#include "stm32f10x.h"
#include "mpu6000.h"

mpu6000Object_t mpu6000;

void hw_config(void)
{
	mpu6000.hal.spi = SPI1;
	mpu6000.hal.spiPeriphClockCmd = RCC_APB2PeriphClockCmd;
	mpu6000.hal.spiPeriphClk = RCC_APB2Periph_SPI1;
	mpu6000.hal.spiGpioClk = RCC_APB2Periph_GPIOA;
	mpu6000.hal.spiGpioPort = GPIOA;
	mpu6000.hal.spiSckPin = GPIO_Pin_5;
	mpu6000.hal.spiMisoPin = GPIO_Pin_6;
	mpu6000.hal.spiMosiPin = GPIO_Pin_7;
	mpu6000.hal.spiBaudRatePrescaler1M = SPI_BaudRatePrescaler_64;
	mpu6000.hal.spiBaudRatePrescaler20M = SPI_BaudRatePrescaler_8;

	mpu6000.hal.irqHandlerEnable = true;
	mpu6000.hal.extiLine = EXTI_Line3;
	mpu6000.hal.extiIRQn = EXTI3_IRQn;
	mpu6000.hal.irqGpioPortSource = GPIO_PortSourceGPIOA;
	mpu6000.hal.irqGpioPinSource = GPIO_PinSource3;
	mpu6000.hal.irqCPP = 0;
	mpu6000.hal.irqCSP = 0;

	mpu6000.hal.intGpioClk = RCC_APB2Periph_GPIOA;
	mpu6000.hal.intGpioPort = GPIOA;
	mpu6000.hal.intGpioPin = GPIO_Pin_3;

	mpu6000.hal.csGpioClk = RCC_APB2Periph_GPIOB;
	mpu6000.hal.csGpioPort = GPIOB;
	mpu6000.hal.csGpioPin = GPIO_Pin_1;

	mpu6000.basicConfig.accFullScale = accFullScale4;
	mpu6000.basicConfig.gyrFullScale = gyrFullScale500;
	mpu6000.basicConfig.clockSource = gyrZ;
	mpu6000.basicConfig.tempSensorState = tempSensorEnable;
	mpu6000.basicConfig.sampleRateDiv = 7;
	mpu6000.basicConfig.dlpf = A260G256;

	mpu6000.fifoConfig.fifo = fifoDisable;

	mpu6000.interruptConfig.dataReadyInterrupt = dataReadyIntEnable;
	mpu6000.interruptConfig.fifoOverflowInterrupt = fifoOverflowIntDisable;
	mpu6000.interruptConfig.fsyncInterrupt = fsyncIntEnable;
	mpu6000.interruptConfig.i2cMasterInterrupt = i2cMasterIntDisable;

	mpu6000.interruptConfig.intLevel = intActiveH;
	mpu6000.interruptConfig.intClear = intClearReadAny;
	mpu6000.interruptConfig.intLatch = intLatchEnable;
	mpu6000.interruptConfig.intOut = intOutputPushPull;

	mpu6000Init(&mpu6000);
}

void EXTI3_IRQHandler(void)
{
	static int16_t raw[7];
	mpu6000GetSensorRaw(&mpu6000, raw);
}

int main()
{
	hw_config();
	while(1);
}

void assert_failed(uint8_t* file, uint32_t line)
{
	while(1);
}
