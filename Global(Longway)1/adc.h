#ifndef _ADC_H
#define _ADC_H

#define FILTER  	(10)
#define UPPER_VAL 	(300) 		
#define LOWER_VAL 	(25)

#define ANI0	0x30	
#define ANI1	0x31	
#define ANI2	0x32	
#define ANI3	0x33	
#define ANI4	0x34	
#define ANI5	0x35	
#define ANI6	0x36	
#define ANI7	0x37



//void adc_init(void);	
//unsigned int read_adc(unsigned char channel);
//unsigned int get_rms_ac_value(unsigned char adcChannel);
//unsigned int get_rms_frq(unsigned char adcChannel);
//void detect_zerocross_ac(void);
//unsigned int get_amps(void);
//unsigned int get_rms_CT(void);
unsigned int isInPutSqrWav(void);

#endif