#ifndef __MPU6000_H
#define __MPU6000_H

#include "mpu6000hal.h"

#define MPU6000_SELF_TEST_DELAY_MS  10

//Product ID Description for MPU6000:  | High 4 bits  | Low 4 bits        |
//                                     | Product Name | Product Revision  |
#define MPU6000_REV_C4_ES     0x14  //        0001           0100
#define MPU6000_REV_C5_ES     0x15  //        0001           0101
#define MPU6000_REV_D6_ES     0x16  //        0001           0110
#define MPU6000_REV_D7_ES     0x17  //        0001           0111
#define MPU6000_REV_D8_ES     0x18  //        0001           1000
#define MPU6000_REV_C4        0x54  //        0101           0100
#define MPU6000_REV_C5        0x55  //        0101           0101
#define MPU6000_REV_D6        0x56  //        0101           0110
#define MPU6000_REV_D7        0x57  //        0101           0111
#define MPU6000_REV_D8        0x58  //        0101           1000
#define MPU6000_REV_D9        0x59  //        0101           1001

/*
 *  MPU6000 register addresses from crazyfile source code
 *  TODO: Find a compelete description about hidden regiters
 */
#define MPU6000_RA_XG_OFFS_TC       0x00 //[7] PWR_MODE, [6:1] XG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6000_RA_YG_OFFS_TC       0x01 //[7] PWR_MODE, [6:1] YG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6000_RA_ZG_OFFS_TC       0x02 //[7] PWR_MODE, [6:1] ZG_OFFS_TC, [0] OTP_BNK_VLD
#define MPU6000_RA_X_FINE_GAIN      0x03 //[7:0] X_FINE_GAIN
#define MPU6000_RA_Y_FINE_GAIN      0x04 //[7:0] Y_FINE_GAIN
#define MPU6000_RA_Z_FINE_GAIN      0x05 //[7:0] Z_FINE_GAIN
#define MPU6000_RA_XA_OFFS_H        0x06 //[15:0] XA_OFFS
#define MPU6000_RA_XA_OFFS_L_TC     0x07
#define MPU6000_RA_YA_OFFS_H        0x08 //[15:0] YA_OFFS
#define MPU6000_RA_YA_OFFS_L_TC     0x09
#define MPU6000_RA_ZA_OFFS_H        0x0A //[15:0] ZA_OFFS
#define MPU6000_RA_ZA_OFFS_L_TC     0x0B
#define MPU6000_RA_PRODUCT_ID       0x0C
#define MPU6000_RA_XG_OFFS_USRH     0x13 //[15:0] XG_OFFS_USR
#define MPU6000_RA_XG_OFFS_USRL     0x14
#define MPU6000_RA_YG_OFFS_USRH     0x15 //[15:0] YG_OFFS_USR
#define MPU6000_RA_YG_OFFS_USRL     0x16
#define MPU6000_RA_ZG_OFFS_USRH     0x17 //[15:0] ZG_OFFS_USR
#define MPU6000_RA_ZG_OFFS_USRL     0x18
#define MPU6000_RA_SMPLRT_DIV       0x19
#define MPU6000_RA_CONFIG           0x1A
#define MPU6000_RA_GYRO_CONFIG      0x1B
#define MPU6000_RA_ACCEL_CONFIG     0x1C
#define MPU6000_RA_FF_THR           0x1D
#define MPU6000_RA_FF_DUR           0x1E
#define MPU6000_RA_MOT_THR          0x1F
#define MPU6000_RA_MOT_DUR          0x20
#define MPU6000_RA_ZRMOT_THR        0x21
#define MPU6000_RA_ZRMOT_DUR        0x22
#define MPU6000_RA_FIFO_EN          0x23
#define MPU6000_RA_I2C_MST_CTRL     0x24
#define MPU6000_RA_I2C_SLV0_ADDR    0x25
#define MPU6000_RA_I2C_SLV0_REG     0x26
#define MPU6000_RA_I2C_SLV0_CTRL    0x27
#define MPU6000_RA_I2C_SLV1_ADDR    0x28
#define MPU6000_RA_I2C_SLV1_REG     0x29
#define MPU6000_RA_I2C_SLV1_CTRL    0x2A
#define MPU6000_RA_I2C_SLV2_ADDR    0x2B
#define MPU6000_RA_I2C_SLV2_REG     0x2C
#define MPU6000_RA_I2C_SLV2_CTRL    0x2D
#define MPU6000_RA_I2C_SLV3_ADDR    0x2E
#define MPU6000_RA_I2C_SLV3_REG     0x2F
#define MPU6000_RA_I2C_SLV3_CTRL    0x30
#define MPU6000_RA_I2C_SLV4_ADDR    0x31
#define MPU6000_RA_I2C_SLV4_REG     0x32
#define MPU6000_RA_I2C_SLV4_DO      0x33
#define MPU6000_RA_I2C_SLV4_CTRL    0x34
#define MPU6000_RA_I2C_SLV4_DI      0x35
#define MPU6000_RA_I2C_MST_STATUS   0x36
#define MPU6000_RA_INT_PIN_CFG      0x37
#define MPU6000_RA_INT_ENABLE       0x38
#define MPU6000_RA_DMP_INT_STATUS   0x39
#define MPU6000_RA_INT_STATUS       0x3A
#define MPU6000_RA_ACCEL_XOUT_H     0x3B
#define MPU6000_RA_ACCEL_XOUT_L     0x3C
#define MPU6000_RA_ACCEL_YOUT_H     0x3D
#define MPU6000_RA_ACCEL_YOUT_L     0x3E
#define MPU6000_RA_ACCEL_ZOUT_H     0x3F
#define MPU6000_RA_ACCEL_ZOUT_L     0x40
#define MPU6000_RA_TEMP_OUT_H       0x41
#define MPU6000_RA_TEMP_OUT_L       0x42
#define MPU6000_RA_GYRO_XOUT_H      0x43
#define MPU6000_RA_GYRO_XOUT_L      0x44
#define MPU6000_RA_GYRO_YOUT_H      0x45
#define MPU6000_RA_GYRO_YOUT_L      0x46
#define MPU6000_RA_GYRO_ZOUT_H      0x47
#define MPU6000_RA_GYRO_ZOUT_L      0x48
#define MPU6000_RA_EXT_SENS_DATA_00 0x49
#define MPU6000_RA_EXT_SENS_DATA_01 0x4A
#define MPU6000_RA_EXT_SENS_DATA_02 0x4B
#define MPU6000_RA_EXT_SENS_DATA_03 0x4C
#define MPU6000_RA_EXT_SENS_DATA_04 0x4D
#define MPU6000_RA_EXT_SENS_DATA_05 0x4E
#define MPU6000_RA_EXT_SENS_DATA_06 0x4F
#define MPU6000_RA_EXT_SENS_DATA_07 0x50
#define MPU6000_RA_EXT_SENS_DATA_08 0x51
#define MPU6000_RA_EXT_SENS_DATA_09 0x52
#define MPU6000_RA_EXT_SENS_DATA_10 0x53
#define MPU6000_RA_EXT_SENS_DATA_11 0x54
#define MPU6000_RA_EXT_SENS_DATA_12 0x55
#define MPU6000_RA_EXT_SENS_DATA_13 0x56
#define MPU6000_RA_EXT_SENS_DATA_14 0x57
#define MPU6000_RA_EXT_SENS_DATA_15 0x58
#define MPU6000_RA_EXT_SENS_DATA_16 0x59
#define MPU6000_RA_EXT_SENS_DATA_17 0x5A
#define MPU6000_RA_EXT_SENS_DATA_18 0x5B
#define MPU6000_RA_EXT_SENS_DATA_19 0x5C
#define MPU6000_RA_EXT_SENS_DATA_20 0x5D
#define MPU6000_RA_EXT_SENS_DATA_21 0x5E
#define MPU6000_RA_EXT_SENS_DATA_22 0x5F
#define MPU6000_RA_EXT_SENS_DATA_23 0x60
#define MPU6000_RA_MOT_DETECT_STATUS    0x61
#define MPU6000_RA_I2C_SLV0_DO      0x63
#define MPU6000_RA_I2C_SLV1_DO      0x64
#define MPU6000_RA_I2C_SLV2_DO      0x65
#define MPU6000_RA_I2C_SLV3_DO      0x66
#define MPU6000_RA_I2C_MST_DELAY_CTRL   0x67
#define MPU6000_RA_SIGNAL_PATH_RESET    0x68
#define MPU6000_RA_MOT_DETECT_CTRL      0x69
#define MPU6000_RA_USER_CTRL        0x6A
#define MPU6000_RA_PWR_MGMT_1       0x6B
#define MPU6000_RA_PWR_MGMT_2       0x6C
#define MPU6000_RA_BANK_SEL         0x6D
#define MPU6000_RA_MEM_START_ADDR   0x6E
#define MPU6000_RA_MEM_R_W          0x6F
#define MPU6000_RA_DMP_CFG_1        0x70
#define MPU6000_RA_DMP_CFG_2        0x71
#define MPU6000_RA_FIFO_COUNTH      0x72
#define MPU6000_RA_FIFO_COUNTL      0x73
#define MPU6000_RA_FIFO_R_W         0x74
#define MPU6000_RA_WHO_AM_I         0x75

/*
 *  MPU6000 register discription from crazyfile firmware
 */
#define MPU6000_TC_PWR_MODE_BIT     7
#define MPU6000_TC_OFFSET_BIT       6
#define MPU6000_TC_OFFSET_LENGTH    6
#define MPU6000_TC_OTP_BNK_VLD_BIT  0

#define MPU6000_VDDIO_LEVEL_VLOGIC  0
#define MPU6000_VDDIO_LEVEL_VDD     1

#define MPU6000_CFG_EXT_SYNC_SET_BIT    5
#define MPU6000_CFG_EXT_SYNC_SET_LENGTH 3
#define MPU6000_CFG_DLPF_CFG_BIT    2
#define MPU6000_CFG_DLPF_CFG_LENGTH 3

#define MPU6000_EXT_SYNC_DISABLED       0x0
#define MPU6000_EXT_SYNC_TEMP_OUT_L     0x1
#define MPU6000_EXT_SYNC_GYRO_XOUT_L    0x2
#define MPU6000_EXT_SYNC_GYRO_YOUT_L    0x3
#define MPU6000_EXT_SYNC_GYRO_ZOUT_L    0x4
#define MPU6000_EXT_SYNC_ACCEL_XOUT_L   0x5
#define MPU6000_EXT_SYNC_ACCEL_YOUT_L   0x6
#define MPU6000_EXT_SYNC_ACCEL_ZOUT_L   0x7

#define MPU6000_DLPF_BW_256         0x00
#define MPU6000_DLPF_BW_188         0x01
#define MPU6000_DLPF_BW_98          0x02
#define MPU6000_DLPF_BW_42          0x03
#define MPU6000_DLPF_BW_20          0x04
#define MPU6000_DLPF_BW_10          0x05
#define MPU6000_DLPF_BW_5           0x06

#define MPU6000_GCONFIG_XG_ST_BIT       7
#define MPU6000_GCONFIG_YG_ST_BIT       6
#define MPU6000_GCONFIG_ZG_ST_BIT       5
#define MPU6000_GCONFIG_FS_SEL_BIT      4
#define MPU6000_GCONFIG_FS_SEL_LENGTH   2


#define MPU6000_GYRO_FS_250         0x00
#define MPU6000_GYRO_FS_500         0x01
#define MPU6000_GYRO_FS_1000        0x02
#define MPU6000_GYRO_FS_2000        0x03

#define MPU6000_ACONFIG_XA_ST_BIT           7
#define MPU6000_ACONFIG_YA_ST_BIT           6
#define MPU6000_ACONFIG_ZA_ST_BIT           5
#define MPU6000_ACONFIG_AFS_SEL_BIT         4
#define MPU6000_ACONFIG_AFS_SEL_LENGTH      2
#define MPU6000_ACONFIG_ACCEL_HPF_BIT       2
#define MPU6000_ACONFIG_ACCEL_HPF_LENGTH    3

#define MPU6000_ACCEL_FS_2          0x00
#define MPU6000_ACCEL_FS_4          0x01
#define MPU6000_ACCEL_FS_8          0x02
#define MPU6000_ACCEL_FS_16         0x03

#define MPU6000_DHPF_RESET          0x00
#define MPU6000_DHPF_5              0x01
#define MPU6000_DHPF_2P5            0x02
#define MPU6000_DHPF_1P25           0x03
#define MPU6000_DHPF_0P63           0x04
#define MPU6000_DHPF_HOLD           0x07

#define MPU6000_TEMP_FIFO_EN_BIT    7
#define MPU6000_XG_FIFO_EN_BIT      6
#define MPU6000_YG_FIFO_EN_BIT      5
#define MPU6000_ZG_FIFO_EN_BIT      4
#define MPU6000_ACCEL_FIFO_EN_BIT   3
#define MPU6000_SLV2_FIFO_EN_BIT    2
#define MPU6000_SLV1_FIFO_EN_BIT    1
#define MPU6000_SLV0_FIFO_EN_BIT    0

#define MPU6000_MULT_MST_EN_BIT     7
#define MPU6000_WAIT_FOR_ES_BIT     6
#define MPU6000_SLV_3_FIFO_EN_BIT   5
#define MPU6000_I2C_MST_P_NSR_BIT   4
#define MPU6000_I2C_MST_CLK_BIT     3
#define MPU6000_I2C_MST_CLK_LENGTH  4

#define MPU6000_CLOCK_DIV_348       0x0
#define MPU6000_CLOCK_DIV_333       0x1
#define MPU6000_CLOCK_DIV_320       0x2
#define MPU6000_CLOCK_DIV_308       0x3
#define MPU6000_CLOCK_DIV_296       0x4
#define MPU6000_CLOCK_DIV_286       0x5
#define MPU6000_CLOCK_DIV_276       0x6
#define MPU6000_CLOCK_DIV_267       0x7
#define MPU6000_CLOCK_DIV_258       0x8
#define MPU6000_CLOCK_DIV_500       0x9
#define MPU6000_CLOCK_DIV_471       0xA
#define MPU6000_CLOCK_DIV_444       0xB
#define MPU6000_CLOCK_DIV_421       0xC
#define MPU6000_CLOCK_DIV_400       0xD
#define MPU6000_CLOCK_DIV_381       0xE
#define MPU6000_CLOCK_DIV_364       0xF

#define MPU6000_I2C_SLV_RW_BIT      7
#define MPU6000_I2C_SLV_ADDR_BIT    6
#define MPU6000_I2C_SLV_ADDR_LENGTH 7
#define MPU6000_I2C_SLV_EN_BIT      7
#define MPU6000_I2C_SLV_BYTE_SW_BIT 6
#define MPU6000_I2C_SLV_REG_DIS_BIT 5
#define MPU6000_I2C_SLV_GRP_BIT     4
#define MPU6000_I2C_SLV_LEN_BIT     3
#define MPU6000_I2C_SLV_LEN_LENGTH  4

#define MPU6000_I2C_SLV4_RW_BIT         7
#define MPU6000_I2C_SLV4_ADDR_BIT       6
#define MPU6000_I2C_SLV4_ADDR_LENGTH    7
#define MPU6000_I2C_SLV4_EN_BIT         7
#define MPU6000_I2C_SLV4_INT_EN_BIT     6
#define MPU6000_I2C_SLV4_REG_DIS_BIT    5
#define MPU6000_I2C_SLV4_MST_DLY_BIT    4
#define MPU6000_I2C_SLV4_MST_DLY_LENGTH 5

#define MPU6000_MST_PASS_THROUGH_BIT    7
#define MPU6000_MST_I2C_SLV4_DONE_BIT   6
#define MPU6000_MST_I2C_LOST_ARB_BIT    5
#define MPU6000_MST_I2C_SLV4_NACK_BIT   4
#define MPU6000_MST_I2C_SLV3_NACK_BIT   3
#define MPU6000_MST_I2C_SLV2_NACK_BIT   2
#define MPU6000_MST_I2C_SLV1_NACK_BIT   1
#define MPU6000_MST_I2C_SLV0_NACK_BIT   0

#define MPU6000_INTCFG_INT_LEVEL_BIT        7
#define MPU6000_INTCFG_INT_OPEN_BIT         6
#define MPU6000_INTCFG_LATCH_INT_EN_BIT     5
#define MPU6000_INTCFG_INT_RD_CLEAR_BIT     4
#define MPU6000_INTCFG_FSYNC_INT_LEVEL_BIT  3
#define MPU6000_INTCFG_FSYNC_INT_EN_BIT     2
#define MPU6000_INTCFG_I2C_BYPASS_EN_BIT    1
#define MPU6000_INTCFG_CLKOUT_EN_BIT        0

#define MPU6000_INTMODE_ACTIVEHIGH  0x00
#define MPU6000_INTMODE_ACTIVELOW   0x01

#define MPU6000_INTDRV_PUSHPULL     0x00
#define MPU6000_INTDRV_OPENDRAIN    0x01

#define MPU6000_INTLATCH_50USPULSE  0x00
#define MPU6000_INTLATCH_WAITCLEAR  0x01

#define MPU6000_INTCLEAR_STATUSREAD 0x00
#define MPU6000_INTCLEAR_ANYREAD    0x01

#define MPU6000_INTERRUPT_FF_BIT            7
#define MPU6000_INTERRUPT_MOT_BIT           6
#define MPU6000_INTERRUPT_ZMOT_BIT          5
#define MPU6000_INTERRUPT_FIFO_OFLOW_BIT    4
#define MPU6000_INTERRUPT_I2C_MST_INT_BIT   3
#define MPU6000_INTERRUPT_PLL_RDY_INT_BIT   2
#define MPU6000_INTERRUPT_DMP_INT_BIT       1
#define MPU6000_INTERRUPT_DATA_RDY_BIT      0

// TODO: figure out what these actually do
// UMPL source code is not very obivous
#define MPU6000_DMPINT_5_BIT            5
#define MPU6000_DMPINT_4_BIT            4
#define MPU6000_DMPINT_3_BIT            3
#define MPU6000_DMPINT_2_BIT            2
#define MPU6000_DMPINT_1_BIT            1
#define MPU6000_DMPINT_0_BIT            0

#define MPU6000_MOTION_MOT_XNEG_BIT     7
#define MPU6000_MOTION_MOT_XPOS_BIT     6
#define MPU6000_MOTION_MOT_YNEG_BIT     5
#define MPU6000_MOTION_MOT_YPOS_BIT     4
#define MPU6000_MOTION_MOT_ZNEG_BIT     3
#define MPU6000_MOTION_MOT_ZPOS_BIT     2
#define MPU6000_MOTION_MOT_ZRMOT_BIT    0

#define MPU6000_DELAYCTRL_DELAY_ES_SHADOW_BIT   7
#define MPU6000_DELAYCTRL_I2C_SLV4_DLY_EN_BIT   4
#define MPU6000_DELAYCTRL_I2C_SLV3_DLY_EN_BIT   3
#define MPU6000_DELAYCTRL_I2C_SLV2_DLY_EN_BIT   2
#define MPU6000_DELAYCTRL_I2C_SLV1_DLY_EN_BIT   1
#define MPU6000_DELAYCTRL_I2C_SLV0_DLY_EN_BIT   0

#define MPU6000_PATHRESET_GYRO_RESET_BIT    2
#define MPU6000_PATHRESET_ACCEL_RESET_BIT   1
#define MPU6000_PATHRESET_TEMP_RESET_BIT    0

#define MPU6000_DETECT_ACCEL_ON_DELAY_BIT       5
#define MPU6000_DETECT_ACCEL_ON_DELAY_LENGTH    2
#define MPU6000_DETECT_FF_COUNT_BIT             3
#define MPU6000_DETECT_FF_COUNT_LENGTH          2
#define MPU6000_DETECT_MOT_COUNT_BIT            1
#define MPU6000_DETECT_MOT_COUNT_LENGTH         2

#define MPU6000_DETECT_DECREMENT_RESET  0x0
#define MPU6000_DETECT_DECREMENT_1      0x1
#define MPU6000_DETECT_DECREMENT_2      0x2
#define MPU6000_DETECT_DECREMENT_4      0x3

#define MPU6000_USERCTRL_DMP_EN_BIT             7
#define MPU6000_USERCTRL_FIFO_EN_BIT            6
#define MPU6000_USERCTRL_I2C_MST_EN_BIT         5
#define MPU6000_USERCTRL_I2C_IF_DIS_BIT         4
#define MPU6000_USERCTRL_DMP_RESET_BIT          3
#define MPU6000_USERCTRL_FIFO_RESET_BIT         2
#define MPU6000_USERCTRL_I2C_MST_RESET_BIT      1
#define MPU6000_USERCTRL_SIG_COND_RESET_BIT     0

#define MPU6000_PWR1_DEVICE_RESET_BIT   7
#define MPU6000_PWR1_SLEEP_BIT          6
#define MPU6000_PWR1_CYCLE_BIT          5
#define MPU6000_PWR1_TEMP_DIS_BIT       3
#define MPU6000_PWR1_CLKSEL_BIT         2
#define MPU6000_PWR1_CLKSEL_LENGTH      3

#define MPU6000_CLOCK_INTERNAL          0x00
#define MPU6000_CLOCK_PLL_XGYRO         0x01
#define MPU6000_CLOCK_PLL_YGYRO         0x02
#define MPU6000_CLOCK_PLL_ZGYRO         0x03
#define MPU6000_CLOCK_PLL_EXT32K        0x04
#define MPU6000_CLOCK_PLL_EXT19M        0x05
#define MPU6000_CLOCK_KEEP_RESET        0x07

#define MPU6000_PWR2_LP_WAKE_CTRL_BIT       7
#define MPU6000_PWR2_LP_WAKE_CTRL_LENGTH    2
#define MPU6000_PWR2_STBY_XA_BIT            5
#define MPU6000_PWR2_STBY_YA_BIT            4
#define MPU6000_PWR2_STBY_ZA_BIT            3
#define MPU6000_PWR2_STBY_XG_BIT            2
#define MPU6000_PWR2_STBY_YG_BIT            1
#define MPU6000_PWR2_STBY_ZG_BIT            0

#define MPU6000_WAKE_FREQ_1P25      0x0
#define MPU6000_WAKE_FREQ_2P5       0x1
#define MPU6000_WAKE_FREQ_5         0x2
#define MPU6000_WAKE_FREQ_10        0x3

#define MPU6000_BANKSEL_PRFTCH_EN_BIT       6
#define MPU6000_BANKSEL_CFG_USER_BANK_BIT   5
#define MPU6000_BANKSEL_MEM_SEL_BIT         4
#define MPU6000_BANKSEL_MEM_SEL_LENGTH      5

#define MPU6000_WHO_AM_I_BIT        6
#define MPU6000_WHO_AM_I_LENGTH     6

#define MPU6000_DMP_MEMORY_BANKS        8
#define MPU6000_DMP_MEMORY_BANK_SIZE    256
#define MPU6000_DMP_MEMORY_CHUNK_SIZE   16

#define MPU6000_DEG_PER_LSB_250  (float)((2 * 250.0) / 65536.0)
#define MPU6000_DEG_PER_LSB_500  (float)((2 * 500.0) / 65536.0)
#define MPU6000_DEG_PER_LSB_1000 (float)((2 * 1000.0) / 65536.0)
#define MPU6000_DEG_PER_LSB_2000 (float)((2 * 2000.0) / 65536.0)

#define MPU6000_G_PER_LSB_2      (float)((2 * 2) / 65536.0)
#define MPU6000_G_PER_LSB_4      (float)((2 * 4) / 65536.0)
#define MPU6000_G_PER_LSB_8      (float)((2 * 8) / 65536.0)
#define MPU6000_G_PER_LSB_16     (float)((2 * 16) / 65536.0)

#define MPU6000_ST_GYRO_LOW      10.0   // deg/s
#define MPU6000_ST_GYRO_HIGH     105.0  // deg/s
#define MPU6000_ST_ACCEL_LOW     0.300  // G
#define MPU6000_ST_ACCEL_HIGH    0.950  // G

/*
 *  Basic configuration
 */
typedef enum 
{
	A260G256 = 0x00,
	A184G188 = 0x01,
	A94G98 = 0x02,
	A44G42 = 0x03,
	A21G20 = 0x04,
	A10G10 = 0x05,
	A5G5 = 0x06
} mpu6000Dlpf;

typedef enum 
{
	accFullScale2 = 0x00,
	accFullScale4 = 0x08,
	accFullScale8 = 0x10,
	accFullScale16 = 0x18
} mpu6000AccFullScale;

typedef enum 
{
	gyrFullScale250 = 0x00,
	gyrFullScale500 = 0x08,
	gyrFullScale1000 = 0x10,
	gyrFullScale2000 = 0x18
} mpu6000GyrFullScale;

typedef enum 
{
	tempSensorDisable = 0x08,
	tempSensorEnable = 0x00
} mpu6000TempSensorState;

typedef enum 
{
	internal8MHz = 0x00,
	gyrX = 0x01,
	gyrY = 0x02,
	gyrZ = 0x03,
	external32768Hz = 0x04,
	external19200kHz = 0x05
} mpu6000ClockSource;

typedef struct 
{
	uint8_t			sampleRateDiv;
	mpu6000Dlpf		dlpf;	/* Digital low pass filter */
	mpu6000GyrFullScale	gyrFullScale;
	mpu6000AccFullScale	accFullScale;
	mpu6000TempSensorState	tempSensorState;
	mpu6000ClockSource	clockSource;
} mpu6000BasicConfig_t;

/*
 *  FIFO configuration
 */
typedef enum 
{
	TempFifoEnable = 0x80,
	TempFifoDisable = 0x00
} mpu6000TempFifo;

typedef enum 
{
	XgFifoEnable = 0x40,
	XgFifoDisable = 0x00
} mpu6000XgFifo;

typedef enum 
{
	YgFifoEnable = 0x20,
	YgFifoDisable = 0x00
} mpu6000YgFifo;

typedef enum 
{
	ZgFifoEnable = 0x10,
	ZgFifoDisable = 0x00
} mpu6000ZgFifo;

typedef enum 
{
	AccFifoEnable = 0x08,
	AccFifoDisable = 0x00
} mpu6000AccFifo;

typedef enum 
{
	Slv2FifoEnable = 0x04,
	Slv2FifoDisable = 0x00
} mpu6000Slv2Fifo;
;
typedef enum 
{
	Slv1FifoEnable = 0x02,
	Slv1FifoDisable = 0x00
} mpu6000Slv1Fifo;

typedef enum 
{
	Slv0FifoEnable = 0x01,
	Slv0FifoDisable = 0x00
} mpu6000Slv0Fifo;

typedef enum 
{
	fifoEnable = 0x40,
	fifoDisable = 0x00
} mpu6000Fifo;

typedef struct 
{
	mpu6000Fifo	fifo;
	mpu6000TempFifo	tempFifo;
	mpu6000XgFifo	xgFifo;
	mpu6000YgFifo	ygFifo;
	mpu6000ZgFifo	zgFifo;
	mpu6000AccFifo	accFifo;
	mpu6000Slv0Fifo	slv0Fifo;
	mpu6000Slv1Fifo	slv1Fifo;
	mpu6000Slv2Fifo	slv2Fifo;
} mpu6000FifoConfig_t;
/*
 *  Device interrupt configutaion
 */

typedef enum 
{
	intActiveL = 0x80,
	intActiveH = 0x00
} mpu6000IntLevel;

typedef enum 
{
	intOutputOpenDrain = 0x40,
	intOutputPushPull = 0x00
} mpu6000IntOut;

typedef enum 
{
	intLatchEnable = 0x20,	/* Hold until cleared */
	intLatchDisable = 0x00	/* Emits 50us pulse */
} mpu6000IntLatch;

typedef enum 
{
	intClearReadAny = 0x10,
	intClearReadStatus = 0x00
} mpu6000IntClear;

typedef enum 
{
	fsyncIntEnable = 0x04,
	fsyncIntDisable = 0x00
} mpu6000FsyncInt;

typedef enum 
{
	fifoOverflowIntEnable = 0x10,
	fifoOverflowIntDisable = 0x00
} mpu6000FifoOverflowInt;

typedef enum 
{
	i2cMasterIntEnable = 0x08,
	i2cMasterIntDisable = 0x00
} mpu6000I2cMasterInt;

typedef enum 
{
	dataReadyIntEnable = 0x01,
	dataReadyIntDisable = 0x00
} mpu6000DataReadyInt;

typedef struct 
{
	mpu6000IntLevel	intLevel;
	mpu6000IntOut	intOut;
	mpu6000IntLatch	intLatch;
	mpu6000IntClear	intClear;
	mpu6000FsyncInt fsyncInterrupt;
	mpu6000FifoOverflowInt	fifoOverflowInterrupt;
	mpu6000I2cMasterInt	i2cMasterInterrupt;
	mpu6000DataReadyInt	dataReadyInterrupt;
} mpu6000InterruptConfig_t;

/*
 *  Frame synchronization input configuration
 */
typedef enum 
{
	fsyncDisabled= 0x00,
	fsyncTempL= 0x08,
	fsyncGyroXL= 0x10,
	fsyncGyroYL= 0x18,
	fsyncGyroZL= 0x20,
	fsyncAccXL= 0x28,
	fsyncAccYL= 0x30,
	fsyncAccZL= 0x38
} mpu6000FsyncPos;

typedef enum 
{
	fsyncActiveL = 0x08,
	fsyncActiveH = 0x00
} mpu6000FsyncLevel;

typedef struct 
{
	mpu6000FsyncPos		fsyncPos;
	mpu6000FsyncLevel	fsyncLevel;
} mpu6000FsyncConfig_t;

typedef struct 
{
	bool				isInit;
	mpu6000Hal_t			hal;
	mpu6000BasicConfig_t		basicConfig;
	mpu6000InterruptConfig_t	interruptConfig;
	mpu6000FifoConfig_t		fifoConfig;
	mpu6000FsyncConfig_t		fsyncConfig;
} mpu6000Object_t;

//TODO: Add slave i2c control related type definition.

//TODO: Add cycle sleep mode control related type definition.

/*
 *  Externed function prototypes
 */
void mpu6000Init(mpu6000Object_t *pD);
bool mpu6000Test(mpu6000Object_t *pD);

bool mpu6000TestConnection(mpu6000Object_t *pD);
bool mpu6000EvaluateSelfTest(float low, float high, float value, char* string);
bool mpu6000SelfTest(mpu6000Object_t *pD);

void mpu6000SetSpiFreqForConfig(mpu6000Object_t *pD);
void mpu6000SetSpiFreqForRunning(mpu6000Object_t *pD);
bool mpu6000IsIntAsserted(mpu6000Object_t *pD);

// SMPLRT_DIV register
uint8_t mpu6000GetRate(mpu6000Object_t *pD);
void mpu6000SetRate(mpu6000Object_t *pD, uint8_t rate);

// CONFIG register
uint8_t mpu6000GetExternalFrameSync(mpu6000Object_t *pD);
void mpu6000SetExternalFrameSync(mpu6000Object_t *pD, uint8_t sync);
uint8_t mpu6000GetDLPFMode(mpu6000Object_t *pD);
void mpu6000SetDLPFMode(mpu6000Object_t *pD, uint8_t bandwidth);

// GYRO_CONFIG register
void mpu6000SetGyroXSelfTest(mpu6000Object_t *pD, bool enabled);
void mpu6000SetGyroYSelfTest(mpu6000Object_t *pD, bool enabled);
void mpu6000SetGyroZSelfTest(mpu6000Object_t *pD, bool enabled);
uint8_t mpu6000GetFullScaleGyroRangeId(mpu6000Object_t *pD);
float mpu6000GetFullScaleGyroDPL(mpu6000Object_t *pD);
void mpu6000SetFullScaleGyroRange(mpu6000Object_t *pD, uint8_t range);

// ACCEL_CONFIG register
bool mpu6000GetAccelXSelfTest(mpu6000Object_t *pD);
void mpu6000SetAccelXSelfTest(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetAccelYSelfTest(mpu6000Object_t *pD);
void mpu6000SetAccelYSelfTest(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetAccelZSelfTest(mpu6000Object_t *pD);
void mpu6000SetAccelZSelfTest(mpu6000Object_t *pD, bool enabled);
uint8_t mpu6000GetFullScaleAccelRangeId(mpu6000Object_t *pD);
void mpu6000SetFullScaleAccelRange(mpu6000Object_t *pD, uint8_t range);
float mpu6000GetFullScaleAccelGPL(mpu6000Object_t *pD);
uint8_t mpu6000GetDHPFMode(mpu6000Object_t *pD);
void mpu6000SetDHPFMode(mpu6000Object_t *pD, uint8_t mode);

// FF_THR register
uint8_t mpu6000GetFreefallDetectionThreshold(mpu6000Object_t *pD);
void mpu6000SetFreefallDetectionThreshold(mpu6000Object_t *pD, uint8_t threshold);

// FF_DUR register
uint8_t mpu6000GetFreefallDetectionDuration(mpu6000Object_t *pD);
void mpu6000SetFreefallDetectionDuration(mpu6000Object_t *pD, uint8_t duration);

// MOT_THR register
uint8_t mpu6000GetMotionDetectionThreshold(mpu6000Object_t *pD);
void mpu6000SetMotionDetectionThreshold(mpu6000Object_t *pD, uint8_t threshold);

// MOT_DUR register
uint8_t mpu6000GetMotionDetectionDuration(mpu6000Object_t *pD);
void mpu6000SetMotionDetectionDuration(mpu6000Object_t *pD, uint8_t duration);

// ZRMOT_THR register
uint8_t mpu6000GetZeroMotionDetectionThreshold(mpu6000Object_t *pD);
void mpu6000SetZeroMotionDetectionThreshold(mpu6000Object_t *pD, uint8_t threshold);

// ZRMOT_DUR register
uint8_t mpu6000GetZeroMotionDetectionDuration(mpu6000Object_t *pD);
void mpu6000SetZeroMotionDetectionDuration(mpu6000Object_t *pD, uint8_t duration);

// FIFO_EN register
bool mpu6000GetTempFIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetTempFIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetXGyroFIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetXGyroFIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetYGyroFIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetYGyroFIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetZGyroFIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetZGyroFIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetAccelFIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetAccelFIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlave2FIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetSlave2FIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlave1FIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetSlave1FIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlave0FIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetSlave0FIFOEnabled(mpu6000Object_t *pD, bool enabled);

// I2C_MST_CTRL register
bool mpu6000GetMultiMasterEnabled(mpu6000Object_t *pD);
void mpu6000SetMultiMasterEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetWaitForExternalSensorEnabled(mpu6000Object_t *pD);
void mpu6000SetWaitForExternalSensorEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlave3FIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetSlave3FIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlaveReadWriteTransitionEnabled(mpu6000Object_t *pD);
void mpu6000SetSlaveReadWriteTransitionEnabled(mpu6000Object_t *pD, bool enabled);
uint8_t mpu6000GetMasterClockSpeed(mpu6000Object_t *pD);
void mpu6000SetMasterClockSpeed(mpu6000Object_t *pD, uint8_t speed);

// I2C_SLV* registers (mpu6000Object_t *pD, Slave 0-3)
uint8_t mpu6000GetSlaveAddress(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveAddress(mpu6000Object_t *pD, uint8_t num, uint8_t address);
uint8_t mpu6000GetSlaveRegister(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveRegister(mpu6000Object_t *pD, uint8_t num, uint8_t reg);
bool mpu6000GetSlaveEnabled(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveEnabled(mpu6000Object_t *pD, uint8_t num, bool enabled);
bool mpu6000GetSlaveWordByteSwap(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveWordByteSwap(mpu6000Object_t *pD, uint8_t num, bool enabled);
bool mpu6000GetSlaveWriteMode(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveWriteMode(mpu6000Object_t *pD, uint8_t num, bool mode);
bool mpu6000GetSlaveWordGroupOffmpu6000Set(mpu6000Object_t *pD, uint8_t num);
void setSlaveWordGroupOffset(mpu6000Object_t *pD, uint8_t num, bool enabled);
uint8_t mpu6000GetSlaveDataLength(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveDataLempu6000Seth(mpu6000Object_t *pD, uint8_t num, uint8_t length);

// I2C_SLV* registers (mpu6000Object_t *pD, Slave 4)
uint8_t mpu6000GetSlave4Address(mpu6000Object_t *pD);
void mpu6000SetSlave4Address(mpu6000Object_t *pD, uint8_t address);
uint8_t mpu6000GetSlave4Register(mpu6000Object_t *pD);
void mpu6000SetSlave4Register(mpu6000Object_t *pD, uint8_t reg);
void mpu6000SetSlave4OutputByte(mpu6000Object_t *pD, uint8_t data);
bool mpu6000GetSlave4Enabled(mpu6000Object_t *pD);
void mpu6000SetSlave4Enabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlave4InterruptEnabled(mpu6000Object_t *pD);
void mpu6000SetSlave4InterruptEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlave4WriteMode(mpu6000Object_t *pD);
void mpu6000SetSlave4WriteMode(mpu6000Object_t *pD, bool mode);
uint8_t mpu6000GetSlave4MasterDelay(mpu6000Object_t *pD);
void mpu6000SetSlave4MasterDelay(mpu6000Object_t *pD, uint8_t delay);
uint8_t mpu6000GetSlate4InputByte(mpu6000Object_t *pD);

// I2C_MST_STATUS register
bool mpu6000GetPassthroughStatus(mpu6000Object_t *pD);
bool mpu6000GetSlave4IsDone(mpu6000Object_t *pD);
bool mpu6000GetLostArbitration(mpu6000Object_t *pD);
bool mpu6000GetSlave4Nack(mpu6000Object_t *pD);
bool mpu6000GetSlave3Nack(mpu6000Object_t *pD);
bool mpu6000GetSlave2Nack(mpu6000Object_t *pD);
bool mpu6000GetSlave1Nack(mpu6000Object_t *pD);
bool mpu6000GetSlave0Nack(mpu6000Object_t *pD);

// INT_PIN_CFG register
bool mpu6000GetInterruptMode(mpu6000Object_t *pD);
void mpu6000SetInterruptMode(mpu6000Object_t *pD, bool mode);
bool mpu6000GetInterruptDrive(mpu6000Object_t *pD);
void mpu6000SetInterruptDrive(mpu6000Object_t *pD, bool drive);
bool mpu6000GetInterruptLatch(mpu6000Object_t *pD);
void mpu6000SetInterruptLatch(mpu6000Object_t *pD, bool latch);
bool mpu6000GetInterruptLatchClear(mpu6000Object_t *pD);
void mpu6000SetInterruptLatchClear(mpu6000Object_t *pD, bool clear);
bool mpu6000GetFSyncInterruptLevel(mpu6000Object_t *pD);
void mpu6000SetFSyncInterruptLevel(mpu6000Object_t *pD, bool level);
bool mpu6000GetFSyncInterruptEnabled(mpu6000Object_t *pD);
void mpu6000SetFSyncInterruptEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetI2CBypassEnabled(mpu6000Object_t *pD);
void mpu6000SetI2CBypassEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetClockOutputEnabled(mpu6000Object_t *pD);
void mpu6000SetClockOutputEnabled(mpu6000Object_t *pD, bool enabled);

// INT_ENABLE register
uint8_t mpu6000GetIntEnabled(mpu6000Object_t *pD);
void mpu6000SetIntEnabled(mpu6000Object_t *pD, uint8_t enabled);
bool mpu6000GetIntFreefallEnabled(mpu6000Object_t *pD);
void mpu6000SetIntFreefallEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetIntMotionEnabled(mpu6000Object_t *pD);
void mpu6000SetIntMotionEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetIntZeroMotionEnabled(mpu6000Object_t *pD);
void mpu6000SetIntZeroMotionEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetIntFIFOBufferOverflowEnabled(mpu6000Object_t *pD);
void mpu6000SetIntFIFOBufferOverflowEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetIntI2CMasterEnabled(mpu6000Object_t *pD);
void mpu6000SetIntI2CMasterEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetIntDataReadyEnabled(mpu6000Object_t *pD);
void mpu6000SetIntDataReadyEnabled(mpu6000Object_t *pD, bool enabled);

// INT_STATUS register
uint8_t mpu6000GetIntStatus(mpu6000Object_t *pD);
bool mpu6000GetIntFreefallStatus(mpu6000Object_t *pD);
bool mpu6000GetIntMotionStatus(mpu6000Object_t *pD);
bool mpu6000GetIntZeroMotionStatus(mpu6000Object_t *pD);
bool mpu6000GetIntFIFOBufferOverflowStatus(mpu6000Object_t *pD);
bool mpu6000GetIntI2CMasterStatus(mpu6000Object_t *pD);
bool mpu6000GetIntDataReadyStatus(mpu6000Object_t *pD);

// ACCEL_*OUT_* registers
void mpu6000GetMotion9(mpu6000Object_t *pD, int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz, int16_t* mx, int16_t* my, int16_t* mz);
void mpu6000GetMotion6(mpu6000Object_t *pD, int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
void mpu6000GetAcceleration(mpu6000Object_t *pD, int16_t* x, int16_t* y, int16_t* z);
int16_t mpu6000GetAccelerationX(mpu6000Object_t *pD);
int16_t mpu6000GetAccelerationY(mpu6000Object_t *pD);
int16_t mpu6000GetAccelerationZ(mpu6000Object_t *pD);

// TEMP_OUT_* registers
int16_t mpu6000GetTemperature(mpu6000Object_t *pD);

// GYRO_*OUT_* registers
void mpu6000GetRotation(mpu6000Object_t *pD, int16_t* x, int16_t* y, int16_t* z);
int16_t mpu6000GetRotationX(mpu6000Object_t *pD);
int16_t mpu6000GetRotationY(mpu6000Object_t *pD);
int16_t mpu6000GetRotationZ(mpu6000Object_t *pD);

// *OUT* registers
void mpu6000GetSensorRaw(mpu6000Object_t *pD, int16_t *data);

// EXT_SENS_DATA_* registers
uint8_t mpu6000GetExternalSensorByte(mpu6000Object_t *pD, int position);
uint16_t mpu6000GetExternalSensorWord(mpu6000Object_t *pD, int position);
uint32_t mpu6000GetExternalSensorDWord(mpu6000Object_t *pD, int position);

// MOT_DETECT_STATUS register
bool mpu6000GetXNegMotionDetected(mpu6000Object_t *pD);
bool mpu6000GetXPosMotionDetected(mpu6000Object_t *pD);
bool mpu6000GetYNegMotionDetected(mpu6000Object_t *pD);
bool mpu6000GetYPosMotionDetected(mpu6000Object_t *pD);
bool mpu6000GetZNegMotionDetected(mpu6000Object_t *pD);
bool mpu6000GetZPosMotionDetected(mpu6000Object_t *pD);
bool mpu6000GetZeroMotionDetected(mpu6000Object_t *pD);

// I2C_SLV*_DO register
void mpu6000SetSlaveOutputByte(mpu6000Object_t *pD, uint8_t num, uint8_t data);

// I2C_MST_DELAY_CTRL register
bool mpu6000GetExternalShadowDelayEnabled(mpu6000Object_t *pD);
void mpu6000SetExternalShadowDelayEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetSlaveDelayEnabled(mpu6000Object_t *pD, uint8_t num);
void mpu6000SetSlaveDelayEnabled(mpu6000Object_t *pD, uint8_t num, bool enabled);

// SIGNAL_PATH_RESET register
void mpu6000ResetGyroscopePath(mpu6000Object_t *pD);
void mpu6000ResetAccelerometerPath(mpu6000Object_t *pD);
void mpu6000ResetTemperaturePath(mpu6000Object_t *pD);

// MOT_DETECT_CTRL register
uint8_t mpu6000GetAccelerometerPowerOnDelay(mpu6000Object_t *pD);
void mpu6000SetAccelerometerPowerOnDelay(mpu6000Object_t *pD, uint8_t delay);
uint8_t mpu6000GetFreefallDetectionCounterDecrement(mpu6000Object_t *pD);
void mpu6000SetFreefallDetectionCounterDecrement(mpu6000Object_t *pD, uint8_t decrement);
uint8_t mpu6000GetMotionDetectionCounterDecrement(mpu6000Object_t *pD);
void mpu6000SetMotionDetectionCounterDecrement(mpu6000Object_t *pD, uint8_t decrement);

// USER_CTRL register
bool mpu6000GetFIFOEnabled(mpu6000Object_t *pD);
void mpu6000SetFIFOEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetI2CMasterModeEnabled(mpu6000Object_t *pD);
void mpu6000SetI2CMasterModeEnabled(mpu6000Object_t *pD, bool enabled);
void mpu6000SwitchSPIEnabled(mpu6000Object_t *pD, bool enabled);
void mpu6000ResetFIFO(mpu6000Object_t *pD);
void mpu6000ResetI2CMaster(mpu6000Object_t *pD);
void mpu6000ResetSensors(mpu6000Object_t *pD);

// PWR_MGMT_1 register
void mpu6000Reset(mpu6000Object_t *pD);
bool mpu6000GetSleepEnabled(mpu6000Object_t *pD);
void mpu6000SetSleepEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetWakeCycleEnabled(mpu6000Object_t *pD);
void mpu6000SetWakeCycleEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetTempSensorEnabled(mpu6000Object_t *pD);
void mpu6000SetTempSensorEnabled(mpu6000Object_t *pD, bool enabled);
uint8_t mpu6000GetClockSource(mpu6000Object_t *pD);
void mpu6000SetClockSource(mpu6000Object_t *pD, uint8_t source);

// PWR_MGMT_2 register
uint8_t mpu6000GetWakeFrequency(mpu6000Object_t *pD);
void mpu6000SetWakeFrequency(mpu6000Object_t *pD, uint8_t frequency);
bool mpu6000GetStandbyXAccelEnabled(mpu6000Object_t *pD);
void mpu6000SetStandbyXAccelEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetStandbyYAccelEnabled(mpu6000Object_t *pD);
void mpu6000SetStandbyYAccelEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetStandbyZAccelEnabled(mpu6000Object_t *pD);
void mpu6000SetStandbyZAccelEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetStandbyXGyroEnabled(mpu6000Object_t *pD);
void mpu6000SetStandbyXGyroEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetStandbyYGyroEnabled(mpu6000Object_t *pD);
void mpu6000SetStandbyYGyroEnabled(mpu6000Object_t *pD, bool enabled);
bool mpu6000GetStandbyZGyroEnabled(mpu6000Object_t *pD);
void mpu6000SetStandbyZGyroEnabled(mpu6000Object_t *pD, bool enabled);

// FIFO_COUNT_* registers
uint16_t mpu6000GetFIFOCount(mpu6000Object_t *pD);

// FIFO_R_W register
uint8_t mpu6000GetFIFOByte(mpu6000Object_t *pD);
void mpu6000SetFIFOByte(mpu6000Object_t *pD, uint8_t data);
void mpu6000GetFIFOBytes(mpu6000Object_t *pD, uint8_t *data, uint8_t length);

// WHO_AM_I register
uint8_t mpu6000GetDeviceID(mpu6000Object_t *pD);
void mpu6000SetDeviceID(mpu6000Object_t *pD, uint8_t id);

#endif
