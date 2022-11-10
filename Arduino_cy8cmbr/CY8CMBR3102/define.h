#ifndef __DEFINE_H
#define __DEFINE_H

/* CY8CMBR3116 Register Map Offset Address */
#define REGMAP_ORIGIN        0x00  
#define SENSOR_PATTERN      0x00  //Sensor EN
#define FSS_EN              0x02
#define TOGGLE_EN           0x04
#define LED_ON_EN           0x06
#define SENSITIVITY0        0x08
#define SENSITIVITY1        0x09
#define SENSITIVITY2        0x0A
#define SENSITIVITY3        0x0B
#define BASE_THRESHOLD0     0x0C
#define BASE_THRESHOLD1     0x0D
#define FINGER_THRESHOLD2   0x0E
#define FINGER_THRESHOLD3   0x0F
#define FINGER_THRESHOLD4   0x10
#define FINGER_THRESHOLD5   0x11
#define FINGER_THRESHOLD6   0x12
#define FINGER_THRESHOLD7   0x13
#define FINGER_THRESHOLD8   0x14
#define FINGER_THRESHOLD9   0x15
#define FINGER_THRESHOLD10  0x16
#define FINGER_THRESHOLD11  0x17
#define FINGER_THRESHOLD12  0x18
#define FINGER_THRESHOLD13  0x19
#define FINGER_THRESHOLD14  0x1A
#define FINGER_THRESHOLD15  0x1B
#define SENSOR_DEBOUNCE     0x1C
#define BUTTON_HYS          0x1D
#define BUTTON_BUT          0x1E
#define BUTTON_LBR          0x1F
#define BUTTON_NNT          0x20
#define BUTTON_NT           0x21
#define PROX_EN             0x26
#define PROX_CFG            0x27
#define PROX_CFG2           0x28
#define PROX_TOUCH_TH0      0x2A
#define PROX_TOUCH_TH1      0x2C
#define PROX_HYS            0x30
#define PROX_BUT            0x31
#define PROX_LBR            0x32
#define PROX_NNT            0x33
#define PROX_NT             0x34
#define PROX_POSITIVE_TH0   0x35
#define PROX_POSITIVE_TH1   0x36
#define PROX_NEGATIVE_TH0   0x39
#define PROX_NEGATIVE_TH1   0x3A
#define LED_ON_TIME         0x3D
#define BUZZER_CFG          0x3E
#define BUZZER_ON_TIME      0x3F
#define GPO_CFG             0x40
#define PWM_DUTYCYCLE_CFG0    0x41
#define PWM_DUTYCYCLE_CFG1    0x42
#define PWM_DUTYCYCLE_CFG2    0x43
#define PWM_DUTYCYCLE_CFG3    0x44
#define PWM_DUTYCYCLE_CFG4    0x45
#define PWM_DUTYCYCLE_CFG5    0x46
#define PWM_DUTYCYCLE_CFG6    0x47
#define PWM_DUTYCYCLE_CFG7    0x48
#define SPO_CFG             0x4C
#define DEVICE_CFG0         0x4D
#define DEVICE_CFG1         0x4E
#define DEVICE_CFG2         0x4F
#define I2C_ADDR            0x51
#define REFRESH_CTRL        0x52
#define STATE_TIMEOUT       0x55
#define SLIDER_CFG          0x5D
#define SLIDER1_CFG         0x61
#define SLIDER1_RESOLUTION  0x62
#define SLIDER1_THRESHOLD   0x63
#define SLIDER2_CFG         0x67
#define SLIDER2_RESOLUTION  0x68
#define SLIDER2_THRESHOLD   0x69
#define SLIDER_DEBOUNCE     0x6F
#define SLIDER_BUT          0x70
#define SLIDER_LBR          0x71
#define SLIDER_NNT          0x72
#define SLIDER_NT           0x73
#define SCRATCHPAD0         0x7A
#define SCRATCHPAD1         0x7B
#define CONFIG_CRC          0x7E
#define GPO_OUTPUT_STATE    0x80
#define SENSOR_ID           0x82
#define CTRL_CMD            0x86
#define BUTTON_STATUS       0xAA
#define PROX_STAT           0xAE
#define LATCHED_BUTTON_STAT 0xAF
//#define SLIDER1_POSITION    0xB0 //NOT FOR CY8CMBR3102
//#define LIFTOFF_SLIDER1_POSITION   0xB1 //NOT FOR CY8CMBR3102
//#define SLIDER2_POSITION    0xB2  //NOT FOR CY8CMBR3102
//#define LIFTOFF_SLIDER2_POSITION    0xB3  //NOT FOR CY8CMBR3102
#define SYNC_COUNTER0   0xB9
#define DIFFERENCE_COUNT_SENSOR0    0xBA
#define DIFFERENCE_COUNT_SENSOR1    0xBC
#define DIFFERENCE_COUNT_SENSOR2    0xBE
#define DIFFERENCE_COUNT_SENSOR3    0xC0
#define DIFFERENCE_COUNT_SENSOR4    0xC2
#define DIFFERENCE_COUNT_SENSOR5    0xC4
#define DIFFERENCE_COUNT_SENSOR6    0xC6
#define DIFFERENCE_COUNT_SENSOR7    0xC8
#define DIFFERENCE_COUNT_SENSOR8    0xCA
#define DIFFERENCE_COUNT_SENSOR9    0xCC
#define DIFFERENCE_COUNT_SENSOR10   0xCE
#define DIFFERENCE_COUNT_SENSOR11   0xD0
#define DIFFERENCE_COUNT_SENSOR12   0xD2
#define DIFFERENCE_COUNT_SENSOR13   0xD4
#define DIFFERENCE_COUNT_SENSOR14   0xD6
#define DIFFERENCE_COUNT_SENSOR15   0xD8
#define GPO_DATA                  0xDA
#define SYNC_COUNTER1             0xDB
#define DEBUG_SENSOR_ID           0xDC
#define DEBUG_CP                  0xDD
#define DEBUG_DIFFERENCE_COUNT0   0xDE
#define DEBUG_BASELINE0           0xE0
#define DEBUG_RAW_COUNT0          0xE2
#define DEBUG_AVG_RAW_COUNT0      0xE4
#define SYNC_CUNTER2              0xE7


/* Command Codes */
#define CMD_NULL                0x00
#define SAVE_CHECK_CRC          0x02
#define CALC_CRC                0x03
#define LOAD_FACTORY            0x04
#define LOAD_PRIMARY            0x05
#define LOAD_SECONDARY          0x06
#define SLEEP                   0x07
#define CLEAR_LATCHED_STATUS    0x08
#define CMD_RESET_PROX0_FILTER  0x09
#define CMD_RESET_PROX1_FILTER  0x0A
#define ENTER_CONFIG_MODE       0x0B
#define EXIT_CONTROL_RUN        0xFE
#define SW_RESET                0xFF

/* Total number of configuration registers */
#define TOTAL_CONFIG_REG_COUNT  0x80

/* Length of Register Map */
#define REG_MAP_LEN 256

/* Slave Address (Default) */
#define SLAVE_ADDR  0x37
  
#define NO_OF_KIT_BUTTONS 4

#define BUZ_ON_1_33kHz          0x85
#define BUZ_OFF_1_33kHz         0x05
#define SPO_ENABLE              0x03
#define SPO_DISABLE             0x00

#endif
