#include "mpu6000hal.h"

void mpu6000AssertCs(mpu6000Hal_t *hal)
{
	GPIO_ResetBits(hal->csGpioPort, hal->csGpioPin);
}

void mpu6000ReleaseCs(mpu6000Hal_t *hal)
{
	GPIO_SetBits(hal->csGpioPort, hal->csGpioPin);
}

void mpu6000DelayMs(uint8_t ms)
{
	uint32_t n = ms * 72000;
	while(n--)
		__NOP();
}

/*
 *  Standard SPI operations.
 *  Refer to STM32F10xxx ref. manual Figure 239
 *  and MPU6000 Product Spec.
 */
bool mpu6000Read(mpu6000Hal_t *hal, uint8_t addr, uint8_t len, uint8_t *data)
{
	uint8_t n;

        /* Assert CS pin to start transmission */
	mpu6000AssertCs(hal);
	
        /* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Send read command with address */
	hal->spi->DR = (0x80 | addr);

	/* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Drive the clock by sending something */ 
	hal->spi->DR = 0xAA;

	/* Wait until RXNE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));

	/* Clear RXNE flag by read operation */
	SPI_I2S_ReceiveData(hal->spi);

	for (n=0; n<(len-1); n++)
	{
		while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));
		hal->spi->DR = 0xAA;
		while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));
		data[n] = hal->spi->DR;
	}

	/* Receive the last byte */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));
	data[len - 1] = hal->spi->DR;

	/* Release CS pin to terminate transmission */
	mpu6000ReleaseCs(hal);
	return true;
}

bool mpu6000ReadByte(mpu6000Hal_t *hal, uint8_t addr, uint8_t *data)
{
	/* Assert CS pin to start transmission */
	mpu6000AssertCs(hal);
	
        /* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Send read command with address */
	hal->spi->DR = (0x80 | addr);

	/* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Drive the clock by sending something */ 
	hal->spi->DR = 0xAA;

	/* Wait until RXNE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));

	/* Clear RXNE flag by read operation */
	SPI_I2S_ReceiveData(hal->spi);

	/* Receive the returned byte */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));
	*data = hal->spi->DR;

	/* Release CS pin to terminate transmission */
	mpu6000ReleaseCs(hal);

	return true;
}

void mpu6000Write(mpu6000Hal_t *hal, uint8_t addr, uint16_t len, uint8_t *data)
{
	uint8_t n;

        /* Assert CS pin to start transmission */
	mpu6000AssertCs(hal);
	
        /* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Send address */
	hal->spi->DR = addr;

	/* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Send the first byte of data */ 
	hal->spi->DR = data[0];

	/* Wait until RXNE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));

	/* Clear RXNE flag by read operation */
	SPI_I2S_ReceiveData(hal->spi);

	for (n=1; n<len; n++)
	{
		while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));
		hal->spi->DR = data[n];
		while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));
		SPI_I2S_ReceiveData(hal->spi);
	}

	/* Clear the last RXNE */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));
	SPI_I2S_ReceiveData(hal->spi);

	/* Release CS pin to terminate transmission */
	mpu6000ReleaseCs(hal);
}
	
void mpu6000WriteByte(mpu6000Hal_t *hal, uint8_t addr, uint8_t data)
{	
	/* Assert CS pin to start transmission */
	mpu6000AssertCs(hal);
	
        /* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Send address */
	hal->spi->DR = addr;

	/* Wait until TXE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_TXE));

	/* Send data */ 
	hal->spi->DR = data;

	/* Wait until RXNE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));

	/* Clear RXNE flag by read operation */
	SPI_I2S_ReceiveData(hal->spi);

	/* Wait until RXNE high */
	while(!(hal->spi->SR & SPI_I2S_FLAG_RXNE));

	/* Clear RXNE flag by read operation */
	SPI_I2S_ReceiveData(hal->spi);

	/* Release CS pin to terminate transmission */
	mpu6000ReleaseCs(hal);
}


/*
 *  Register bit operations
 */

bool mpu6000ReadBit(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitNum, uint8_t *data)
{
	uint8_t byte;
	mpu6000ReadByte(hal, addr, &byte);
	*data = byte & (1 << bitNum);
	return true;
}

bool mpu6000ReadBits(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitStart, uint8_t length, uint8_t *data)
{
	uint8_t byte;
	uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
	mpu6000ReadByte(hal, addr, &byte);
	*data = byte & mask;
	return true;
}

void mpu6000WriteBit(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitNum, uint8_t data)
{
	uint8_t byte;
	mpu6000ReadByte(hal, addr, &byte);
	byte = (data != 0) ? (byte | (1 << bitNum)) : (byte & ~(1 << bitNum));
	mpu6000WriteByte(hal, addr, byte);
}

void mpu6000WriteBits(mpu6000Hal_t *hal, uint8_t addr, uint8_t bitStart, uint8_t length, uint8_t data)
{
	uint8_t byte;
	uint8_t mask = ((1 << length) - 1) << (bitStart - length + 1);
	mpu6000ReadByte(hal, addr, &byte);

	data <<= (bitStart - length + 1); // shift data into correct position
	data &= mask; // zero all non-important bits in data
	byte &= ~(mask); // zero all important bits in existing byte
	byte |= data; // combine data with existing byte
	mpu6000WriteByte(hal, addr, byte);
}

void mpu6000GpioInit(mpu6000Hal_t *hal)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	
	/* Enable GPIO & AFIO Clocks */
	RCC_APB2PeriphClockCmd(hal->spiGpioClk | hal->intGpioClk | \
				RCC_APB2Periph_AFIO | hal->fsyncGpioClk | \
				hal->csGpioClk , ENABLE);
	
	/* Initialize SPI GPIOs */
	GPIO_InitStructure.GPIO_Pin = hal->spiSckPin | hal->spiMisoPin | hal->spiMosiPin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(hal->spiGpioPort, &GPIO_InitStructure);
	
	/* Initialize CS GPIO Pin */
	GPIO_InitStructure.GPIO_Pin = hal->csGpioPin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(hal->csGpioPort, &GPIO_InitStructure);
	
	mpu6000ReleaseCs(hal);
	
	/* Initialize FSYNC GPIO Pin */
	if(hal->fsyncGpioPort != 0)
	{
		GPIO_InitStructure.GPIO_Pin = hal->fsyncGpioPin;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(hal->fsyncGpioPort, &GPIO_InitStructure);
	}
	
	/* Initialize INT GPIO Pin */
	if(hal->intGpioClk != 0)
	{
		GPIO_InitStructure.GPIO_Pin = hal->intGpioClk;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(hal->intGpioPort, &GPIO_InitStructure);
	}
}

void mpu6000IrqInit(mpu6000Hal_t *hal)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_StructInit(&EXTI_InitStructure);
		
	/* IMPORTANT: Do Not Forget to Configure NVIC */
	if(hal->irqHandlerEnable)
	{
		NVIC_InitTypeDef NVIC_InitStruct;

		NVIC_InitStruct.NVIC_IRQChannel = hal->extiIRQn;
		NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = hal->irqCPP;
		NVIC_InitStruct.NVIC_IRQChannelSubPriority = hal->irqCSP;
		NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;

		NVIC_Init(&NVIC_InitStruct);
	}
		
	/* EXTI Line Mode Config */
	GPIO_EXTILineConfig(hal->irqGpioPortSource, hal->irqGpioPinSource); 
	EXTI_InitStructure.EXTI_Line = hal->extiLine;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void mpu6000SpiInit(mpu6000Hal_t *hal)
{
	SPI_InitTypeDef SPI_InitStructure;
	SPI_StructInit(&SPI_InitStructure);

	/* Enable SPI clock */
	(*(hal->spiPeriphClockCmd))(hal->spiPeriphClk, ENABLE);
	
	/* Disable SPI */
	SPI_Cmd(hal->spi, DISABLE);
	
	/* CPOL = 1, CPHA = 1
	 * So mpu6000.c is not really the c code version of 
	 * MPU6000 Product Specification :P
	 */
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = hal->spiBaudRatePrescaler1M;	//Parameter check will be performed in SPI_Init()
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(hal->spi, &SPI_InitStructure);
	
	/* Enable SPI */
	SPI_Cmd(hal->spi, ENABLE);
}

/*
 *  SPI Operating Frequency = 20MHz +/- 10%
 *  Sensor and Interrupt Registers Read Only
 */
void mpu6000SetSpiFreq20M(mpu6000Hal_t *hal)
{
	while(hal->spi->SR & SPI_I2S_FLAG_BSY);

	SPI_Cmd(hal->spi, DISABLE);
	
	hal->spi->CR1 &= 0xFFC7;
	hal->spi->CR1 |= hal->spiBaudRatePrescaler20M;

	SPI_Cmd(hal->spi, ENABLE);
}

/*
 *  SPI Operating Frequency = 1MHz +/- 10%:
 *  All Registers Read/Write
 */
void mpu6000SetSpiFreq1M(mpu6000Hal_t *hal)
{
	while(hal->spi->SR & SPI_I2S_FLAG_BSY);

	SPI_Cmd(hal->spi, DISABLE);
	
	hal->spi->CR1 &= 0xFFC7;
	hal->spi->CR1 |= hal->spiBaudRatePrescaler1M;

	SPI_Cmd(hal->spi, ENABLE);
}

/*
 *  true = high(set), false = low(reset)
 */
bool mpu6000GetIntPinStatus(mpu6000Hal_t *hal)
{
	return GPIO_ReadInputDataBit(hal->intGpioPort, hal->intGpioPin);
}

void mpu6000HalInit(mpu6000Hal_t *hal)
{
	mpu6000GpioInit(hal);
	mpu6000SpiInit(hal);
	mpu6000IrqInit(hal);
//	
//	MPU_WriteReg(0x6B, 0x80);
//	MPU_Delay(180000);
//	
//	/* Write to register PWR_MGMT_1 after power up
//		 otherwise you can not write any register.
//		 What the hell.. */
//	/* Oh wait I figured out why..
//		 SLEEP bit high by default so it needs waking */
//	MPU_WriteReg(0x6B, 0x0B);	
//	MPU_WriteReg(0x6A, 0x10);
//	MPU_WriteReg(0x19, 0x07);
//	MPU_WriteReg(0x1A, 0x00);
//	MPU_WriteReg(0x37, 0x10);
//	MPU_WriteReg(0x38, 0x01);
//	MPU_WriteReg(0x1C, 0x08);	//+-4g
//	
////	MPU_WriteReg(0x0D, 0xFF);
////	MPU_WriteReg(0x0E, 0xFF);
////	MPU_WriteReg(0x0F, 0xFF);
//	
//	MPU_WriteReg(0x1B, 0x08);	//500deg/s
//	
//	MPU_ReadReg(0x1B, &temp123, 1);
//		
//	MPU_SPI_Init_Running();
//	
//	MPU_GyrCalibration();
}

