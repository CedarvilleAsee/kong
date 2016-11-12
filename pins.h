
#ifndef PINS_H
#define PINS_H

/**
 * MOTOR CONTROLLER PINS
 *    ______________________________________
 *   |                                      |
 *   | CCW -> MC_AIN2 = HIGH, MC_AIN1 = LOW |
 *   | CW  -> MC_AIN1 = LOW, MC_AIN2 = HIGH |
 *   | Short brake -> MC_AIN1 = MC_AIN2 = 1 |
 *   | Stop -> MC_AIN1 = MC_AIN2 = 0        |
 *    --------------------------------------
 */
 
/* RIGHT MOTOR */
#define MC_PWMA       PA9
#define MC_AIN2       PB12
#define MC_AIN1       PB13

#define MC_STBY       PB14

/* LEFT MOTOR */
#define MC_BIN1       PB15
#define MC_BIN2       PA11
#define MC_PWMB       PA10

/**
 * SERVO PINS
 */
#define DUMP_SERVO    PB5
#define SCOOP_SERVO   PB6
#define CLOBBER_SERVO PB7

/**
 *   BUTTONS
 */
#define STOP_BUTTON   PA15
#define GO_BUTTON     PB4

/**
 * SENSORS
 */
 #define SENSOR_0     PA4
 #define SENSOR_1     PA5
 #define SENSOR_2     PA6
 #define SENSOR_3     PA7
 #define SENSOR_4     PB0
 #define SENSOR_5     PB1
 #define SENSOR_6     PB10
 #define SENSOR_7     PA1

//7 segment pins
#define  CS           PA3
#define CLOCK         PA8
#define DIN           PB11




 #define S_LED_ON     PA0
 #define LED_PIN      PC13

#endif

