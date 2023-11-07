#ifndef _IR_REMOTE_H
#define _IR_REMOTE_H

#define TGL_DISCARD_LOW			5
#define TGL_FAST_LMT			  61     // 60*25msec =1.5 sec
#define TGL_SLOW_LMT			  200     // 60*25msec =1.5 sec>  <200*25 msec


#define SART_BIT_RNG_L 4400//6600 //13500>>1
#define SART_BIT_RNG_H 5000//6800 //13600>>1
#define SART_BIT2_RNG_L 2050//3100 //6680
#define SART_BIT2_RNG_H 3350//3450 //6800
#define LOW_BIT_RNG_L 150//340 //700
#define LOW_BIT_RNG_H 350//450 //890
#define HI_BIT_RNG_L 700//1000 //2480
#define HI_BIT_RNG_H 1500//1400 //2600

//#define IR_POWER 	461246703ul
//#define IR_BOOST 	461299743ul //led button
#define IR_SPEED_1 	50151870ul
#define IR_SPEED_2 	50184510ul
#define IR_SPEED_3 	50143710ul
#define IR_SPEED_4 	50176350ul
#define IR_SPEED_5 	50160030ul
//#define IR_SPEED_6 	461285463ul //speed 6 button
//#define IR_SPEED_7  461293623ul	//ok
#define IR_INC		50174310ul
#define IR_DEC		50149830ul
#define IR_PWR_ON	50147790ul
#define IR_PWR_OFF	50188590ul
//#define IR_TIMER_2 	461279343ul //2hr
//#define IR_TIMER_3 	461244663ul	//4hr
//#define IR_TIMER_4 	461252823ul	//8hr
//#define IR_SLEEP 	461260983ul	//smart
//#define SMART		461267103ul



//#define FAN_SPEED_OFF_L	0
//#define FAN_SPEED_OFF_H	0x80
//#define FAN_SPEED_1_L	120
//#define FAN_SPEED_1_H	0x80
//#define FAN_SPEED_2_L	180
//#define FAN_SPEED_2_H	0x80
//#define FAN_SPEED_3_L	230
//#define FAN_SPEED_3_H	0x80
//#define FAN_SPEED_4_L	0x61
//#define FAN_SPEED_4_H	0x81
//#define FAN_SPEED_5_L	0xB0
//#define FAN_SPEED_5_H	0x81



#define FAN_SPEED_OFF_L	0
#define FAN_SPEED_OFF_H	0x80
#define FAN_SPEED_1_L	140
#define FAN_SPEED_1_H	0x80
#define FAN_SPEED_2_L	205
#define FAN_SPEED_2_H	0x80
#define FAN_SPEED_3_L	10
#define FAN_SPEED_3_H	0x81
#define FAN_SPEED_4_L	0x88
#define FAN_SPEED_4_H	0x81
#define FAN_SPEED_5_L	0xCF
#define FAN_SPEED_5_H	0x81
#define TIMER_MODE_TIME_2 3600
#define TIMER_MODE_TIME_3 7200
#define TIMER_MODE_TIME_4 14400

unsigned char getIrRemotedata(unsigned long* value);
void irKeyProcess(unsigned long key);
#endif