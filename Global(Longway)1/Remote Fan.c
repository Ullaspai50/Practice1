#include "HT66F3185.h"
#include "sysDef.h"
#include "ee_mem.h"

#include "irRemote.h"
#include "adc.h"

extern unsigned long irData;
#define FILTER_VAR_SIZE 3
//volatile unsigned char g_filter[FILTER_VAR_SIZE];
//unsigned int isInPutSqrWav(void);
union conv16bitint
{
    unsigned short integer;
    unsigned char byte[2];
};
//unsigned char ms240_temp=0,ms400_temp=0, new_speed;
extern unsigned char EEReadChar(unsigned char adr);
extern void EEWriteChar(unsigned char adr,unsigned char Data);
extern void irKeyProcess(unsigned long key);
extern void uart1_put_value(const  char *msg,unsigned long value);
//unsigned char /*g_chng_spd_flg=0,*/ 
//unsigned char fanSpeed,lastSpeed;			//3bit each is enough
//bit powerBtn=0,keyPressFlag,fanModeFlag,LED_INDICATON_FLAG =0;
//unsigned int timerModeCounter;
unsigned long keyPressIndiVal;
//unsigned int count = 0,timer_count=0;
//unsigned int  speed_sec_counter;//,SQR_MIN_COUNT= 105,SQR_MIN_VAL=825;
//unsigned int buzz_count = 0,BUZZ_STOP = 0,change_count=0,change=0;
//bit BUZZ_FLAG=0,write_flag=0,triac_4_flag;
//bit LED_FLAG=0,ms8_flag=0,ms120_flag=0,ms240_flag=0,ms400_flag=0;
//unsigned int i=0,write_count = 0,ms8_counter=0;
extern unsigned char toggle;
extern unsigned char gDownCounterValue;
extern unsigned char No_zero_cross_counter;
//bit powerBtn=0;
//extern bit SKIP_ZERO_CROSS_FLAG;
//___________________Function Protos____________________________
void sysInit(void);
extern void get_ir_remote_status(void);
void sysInit();
void initialize(void);
void poweroff();
unsigned char filter(unsigned char value);
void app();
//extern unsigned char PRESENT_TRIAC_1,PRESENT_TRIAC_2,PRESENT_TRIAC_3,PRESENT_TRIAC_4;

unsigned char TRIAC_INT=0;
//______________________________________________________________
void main(void)
{


//	_lvdc =  0b00010100;
//	while(_lvdo==0)
//	{
//		fanSpeed=0;
//		_lvdo=0;
//	}
	sysInit();					//initialise all pins
//		TRI_1=1;
//						TRI_2=1;
//						TRI_3=1;
//						TRI_4=1;
//	//					while(1);
//	while(1);
	app();
//	powerBtn=0;					//System ON
//	triac_4_flag=0;
//
//	lastSpeed=EEReadChar(0);
////	uart1_put_value("lastSpeed speed: ",lastSpeed);
////	timer_count=readDataFlashInt(1);
////	count=readDataFlashInt(3);
////	toggle=EEReadChar(5);
//	
////	if (count > 14776)
////		count=0;
//	if (lastSpeed>5 || lastSpeed == 0)
//		lastSpeed=5;
////	if (timer_count!=3600 && timer_count!=7200 && timer_count!=14400)
////		timer_count=0;
////	if (toggle!=1 && toggle!=0)
////		toggle=0;
////	if (count>0)
////		_cton=1;
////	else 
////		_cton=0;
//		filter(255);
//		speed_sec_counter=0;
//	fanSpeed = lastSpeed;
//	LED=0;
//	LED_FLAG = 0;
//	ms240_temp=0;
//	ms400_temp=0;
//	BUZZER = 0;
//    LED_INDICATON_FLAG=1;
//	change=fanSpeed*2;
//	buzz_count=0;
//	BUZZ_STOP=0;
//	BUZZ_FLAG=0;
//	write_flag=0;
//	new_speed=fanSpeed;
//		uart1_put_value("fan speed: ",fanSpeed );
////		uart1_put_value("timer_count: ",timer_count );	
////		uart1_put_value("count: ",count);
////		uart1_put_value("toggle: ",toggle );
//
////			uart1_put_value("hello",irData);
////			uart1_put_value("EEPROM Data",lastSpeed);
////			uart1_put_value("fan speed",fanSpeed );
////			uart1_put_value("LED ",toggle);
//
////
//fanSpeed=5;		
//for(i=0;i<9;i++)
//{
//		GCC_DELAY(200000);GCC_DELAY(200000);		
//		GCC_DELAY(200000);GCC_DELAY(200000);		
//		GCC_DELAY(200000);GCC_DELAY(200000);
//}
//TRI_4=1;
//fanSpeed=1;
//	while(1)
////	{
////
////		triac_4_flag=0;
////		GCC_DELAY(200000);GCC_DELAY(200000);GCC_DELAY(200000);GCC_DELAY(200000);GCC_DELAY(200000);
////		triac_4_flag=1;
////		TRI_4=1;
////		GCC_DELAY(200000);
////	}
//	{
//
//	
//	
////		TRI_4=0;
////		if(_tb0f==1)
////		{
////			_tb0f =0;
////			ms8_flag=1;
////			ms8_counter++;
////		}
////		else
////			ms8_flag=0;
//			
//		ms240_temp=ms240_temp+ms8_counter;
//		ms400_temp=ms400_temp+ms8_counter;
//		ms8_counter=0;
////		if((ms8_counter%15)==0)
////			ms120_flag=1;   
////		else 
////			ms120_flag=0;
////			
//		if(ms240_temp%25==0	&& (ms240_temp))
//		{
//			ms240_temp=0;
//			ms240_flag=1;
//		}
//		else
//			ms240_flag=0;
//		
//		if(ms400_temp%125==0 && (ms400_temp))
//		{
//			ms400_temp=0;
//			ms400_flag=1;
//		}
//		else
//			ms400_flag=0;	
//
//if(ms240_flag)	triac_4_flag=0;
//
//		if(ms400_flag==1)
//		{
//			write_flag=1;
//			if(speed_sec_counter<20)
//			speed_sec_counter++;
//			if(	filter(1)>5){new_speed=fanSpeed;}
//				triac_4_flag=1;
//				if(triac_4_flag)	TRI_4=1;
////			uart1_put_value("400ms flag ",write_flag);
//		}
////			
////		if(ms400_flag==1 && LED_INDICATON_FLAG==0 )
////		{
//// 			ms400_flag=0;
////			sqwave=isInPutSqrWav();
//// 			uart1_put_value("sqwave: ",sqwave);
//// 			if(sqwave==1)
//// 			{
//// //				wait_flag=1;
//// 				fanSpeed=0;
//// 				LED=0;
//// 				BUZZER=0;
//// 				_pd2=1;
//// 			}
//// 			else
//// 			{
//// 				LED=1;
//// 				_pd2=0;
//// 			}
////		}
//		
////		if(wait_flag==1)
////		{
////			fanSpeed=0;
////			LED_INDICATON_FLAG=0;
////			BUZZER=0;
////			TRI_1=1;
////			TRI_2=1;
////			TRI_3=1;
////			TRI_4=1;
//////			uart1_put_value("check: ",sqwave);
////			
//////			wait_flag=0;
////		}
////		
//		
//		if(_lvdo ==1 && write_flag ==1)
//		{
//			uart1_put_value("Low Voltage",_lvdo);
////			fanSpeed=0;
////			_emi=0;
//			lastSpeed=EEReadChar(0);
//			if(lastSpeed!=fanSpeed && fanSpeed!=0)
//				EEWriteChar(0,fanSpeed);
////			writeDataFlashInt(1, timer_count);
////			writeDataFlashInt(3, count);
////			writeDataFlashInt(5, toggle);
//			write_flag=0;
////			uart1_put_value("Written",write_flag);
//			
//		}
//		if(_lvdo==1)
//		{
//			fanSpeed=0;
////		TRI_1=1;
////		TRI_2=1;
////		TRI_3=1;
////		TRI_4=1;
////			uart1_put_value("Low Voltage",_lvdo);
//			
//				LED=1;
//		}
//		else
//		{
////			_emi=1;
////			write_count=0;
//		}
//		
//		if(ms240_flag==1)
//		{
//			
//			
//			
//		if(getIrRemotedata(&irData) ==1)				// iR kEY
//			{
//				
////	            buzz_count=0;
////	            BUZZ_STOP=1;
////	            BUZZ_FLAG = 1;
//				speed_sec_counter=0;
//				LED_INDICATON_FLAG=1;
////				disp_count = 0;
//				change_count=0;
//				change =2;
//				irKeyProcess(irData);
//				uart1_put_value("irData: ",irData);
//				if(fanSpeed!=5)TRI_4=1;
//			}
//
////			buzz_count=buzz_count+1;
////			disp_count = disp_count+1;
////					
//
//			if (/*buzz_count >= 0 && */BUZZ_FLAG == 1)
//			{
//				BUZZER=1;
//				buzz_count=buzz_count+1;
//			}
//			if (buzz_count == BUZZ_STOP)
//			{
//				BUZZER=0;
//				buzz_count = 0;
//				BUZZ_FLAG = 0;
//			}
//			if(/*disp_count ==1 && */LED_INDICATON_FLAG == 1 && change_count<change)
//			{
//				LED_FLAG=!LED_FLAG;
//				change_count=change_count+1;
//			//	uart1_put_value("toggle now",LED_FLAG);
//				
//				
//			}
////			if(disp_count == 6600 && LED_INDICATON_FLAG ==1)
////			{
////				LED_FLAG=!LED_FLAG;
////	
////			//		uart1_put_value("toggle again",LED_FLAG);
////	
////			
////			}
////			if(disp_count==12800 && LED_INDICATON_FLAG==1)
////			{
////				disp_count=0;
////				change_count=change_count+1;
////			}	
//			if(change_count==change)
//			{
//				change_count=0;
//				LED_INDICATON_FLAG=0;
//			}
//		
//		
//			if(/*toggle==1 && */LED_INDICATON_FLAG==0 /*&& powerBtn==0*/)
//				LED_FLAG=0;
//
//			if(LED_FLAG == 1)
//			{
//				LED=1;
//			}
//			 if(LED_FLAG == 0)
//			{
//				LED=0;
//			}
////			
//		
//			
//		}//240ms loop
//	//	ms240_flag=0;
//		
//	}//end of while
	

		
}//end of void main

//void __attribute((interrupt(0x1C))) TB0_ISR(void)
//{
//
//	_tb0f=0;
//	ms8_counter++;	
//}

void __attribute((interrupt(0x04))) INT0_ISR(void)
	{
	
		_int0f=0;
		_pton=0;




		
			switch(TRIAC_INT)
			{
				case 7:
						TRI_4=0;
						TRI_3=1;
						TRI_2=1;			
						TRI_1=1;
						break;
				case 8:
						TRI_4=1;
						TRI_3=0;
						TRI_2=0;
						TRI_1=0;
						break;
				case 9:
						TRI_4=1;
						TRI_3=0;
						TRI_2=0;
						TRI_1=1;
						break;			
				case 10:
						TRI_4=1;
						TRI_3=0;
						TRI_2=1;
						TRI_1=0;
						break;			
				case 11:
						TRI_4=1;
						TRI_3=0;
						TRI_2=1;
						TRI_1=1;
						break;			
				case 12:
						TRI_4=1;
						TRI_3=1;
						TRI_2=0;
						TRI_1=0;
						break;			
				case 13:
						TRI_4=1;
						TRI_3=1;
						TRI_2=0;
						TRI_1=1;
						break;			
				case 14:
						TRI_4=1;
						TRI_3=1;
						TRI_2=1;
						TRI_1=0;
						break;			
				case 15:
						TRI_4=1;
						TRI_3=1;
						TRI_2=1;
						TRI_1=1;
						break;			
			}

		
		
		if(SKIP_ZERO_CROSS_FLAG)
		{
			if(gDownCounterValue!=0)
			gDownCounterValue--;	
		}
//	_pton=1;
		No_zero_cross_counter=0	;
	}
		
	
void __attribute((interrupt(0x10))) timer_i0(void)
	{
  
		_ptmaf = 0;
//		switch(fanSpeed)
//		{
//				case 0:
//					
//					break;		
//			case 1: 
//					
//					if(BUZZ_FLAG ==0 /*&& LED_INDICATON_FLAG ==0*/)
//					{
//						TRI_3=0;
////					TRI_1=0;
//					}
//					break;
//			case 2: 
//					if(BUZZ_FLAG ==0 /*&& LED_INDICATON_FLAG ==0*/)
//					{
//						TRI_1=0;
//						TRI_3=0;
////					TRI_2=0;
//					}
//					break;		
//			case 3: 
//					if(BUZZ_FLAG ==0 /*&& LED_INDICATON_FLAG ==0*/)
//					{
//						TRI_2=0;
//						TRI_3=0;
////					TRI_3=0;
//					}
//					break;		
//	
//			case 4:
//					if(BUZZ_FLAG ==0 /*&& LED_INDICATON_FLAG ==0*/)
//					{ 
//						TRI_1=0;
//						TRI_2=0;
//						TRI_3=0;
////					TRI_1=0;
////					TRI_3=0;
//					}
//					break;		
//			case 5: 
//					
//					if(BUZZ_FLAG ==0 /*&& LED_INDICATON_FLAG ==0*/)
//					{
//						TRI_4=0;
////					TRI_2=0;
////					TRI_3=0;
//					}
//					break;
// 		
//		}
	//TRI_4=0;
//		TRI_1=1;
//		TRI_2=1;
//		TRI_3=1;
//		TRI_4=1;

		_pton = 0;
	}



//void startup()
//{
//	fanSpeed=7;
//	LED=1;
//	BUZZER=1;
//	for(i=0;i<65535;i++)
//		{
//			for(j=0;j<7;j++)
//			{
//				asm ("NOP");
//				asm ("NOP");
//				asm ("NOP");
//				asm ("NOP");		
//							
//			}		
//			if(i==8000)
//				BUZZER=0;
//		}
//		
//		for(i=0;i<65535;i++)
//		{
//			LED = 0;
//			asm ("NOP");
//			asm ("NOP");
//			asm ("NOP");
//			asm ("NOP");
//			asm ("NOP");
//		}
//}	
//void poweroff()
//{
//	fanSpeed = 0;
//	count=0;
//	timer_count=0;
//	LED_FLAG=0;
////	g_chng_spd_flg = 1;
//	buzz_count=0;
//	BUZZ_STOP=21000;
//	BUZZ_FLAG = 1;
//	powerBtn = 1; 
//}



void sysInit()
{
	//_cmpc 	= 0b00001000;		//Bit7: CLOSE C+ & C- Pin AND AS I/O Pin    Bit3: CLOSE CX Pin AND AS I/O Pin 
	//----
	
	
	_wdtc 	= 0xab;
//	_pbc4 = 1;					//PB4 set as input
//	_pbs10 = 1;	_pbs11 = 1;		//AN8
//	_lvrc	= 0b10011001;		//reset at 3.15v
//	//_lvrc	=  0b01010101;		//reset @ 2.1
//	_lvdc   =  0b00010111;		// Low voltage detection when vdd drops to less than 4v.

//#ifndef BT_11
	_lvrc	= 0b01100110;		//reset at 1.7v
	_lvdc   =  0b00010100;//0b00010111;		// Low voltage detection when vdd drops to less than 4v.
//#else	
//	_lvrc	=  0b01010101;		//reset @ 2.1
//	_lvdc   =  0b00010011;		// Low voltage detection when vdd drops to less than 2.7v.
//#endif
//	DISP_BRT_1					// segment source current set to level 1 (4m amp)
//_______________________________________________________________
//__________current source of I/O pins______________
_sledc03 = 1; _sledc02 = 1;_sledc01 = 1; _sledc00 = 1; // current for PA3 to PA0 set to maximum
_sledc13 = 1; _sledc12 = 1; _sledc11 = 1; _sledc10 = 1;  // cuttent for PC6 to PC4 and PC3 to PC0 set to maximum

//________________TRIAC PIN as Output__________
	ALL_TRIAC_OP_PIN;
//___________________ LED PIN___________________

	LED_OUTPUT;
	_pac7 = 0; //Buzzer pin 
////___________________ AC INPUT
	AC_VOL_IP;				// configure as input pin
	AC_VOL_IP_INPT;			// config as intrrupt pin
	AC_INPT_FLAG=0;			// flag is cleared
	AC_INPT_BOTH_EDGE;		// configured as bot rising and falling edge interrupt
	AC_INPT_EN=1;			// ac input interrupt enable
	
//	_pa=_pb=_pd=0;
//_________adc______________________________________________________
//	_pas1 = 0xC0;		//config AN6	
//	_ade = 0;					// disable intrupt
//	_sadc0 = 0x36;
//	_sadc1 = 0x03; 				//ADC input only comes from external pin ,fSYS/8 clock
//	_adcen = 1;		    		//Enable the ADC

	//___int1 for IR remote_______________________________________
	_int1ps = 1; _pas05 = 0; _pas04 = 0; _pac2 = 1;
	_int1s1 = 1; _int1s0 = 1;	//both edge trigger external interrupt 0
	_int1f = 0;
	_int1e = 1;

//___-__timmer for ir sensor_______________________________________
	_stm1 = 1; _stm0 = 1;				//Select STM timer/counter Mode	
	_stck2 = 0; _stck1 = 1; _stck0 = 0; //Select STM Counter clock FH/16
	_stcclr = 1;						//STM Counter Clear condition selection STM Comparator A match	
	_stmal = (37500 & 0x00ff);			//		clear @ 50 milsec (37500 => 0x927C) result- 7C i.e 124
	_stmah = (37500 >> 8);				// result- 0x92 i.e 146
	_ston = 0;	


////______________________UART__________________________//
_pcc0=0;
	_pcs01 = 0; _pcs00 = 1; 	// 		PD2_TX

	_swm = 0;
	_pren = 0;	
	_bno = 0;
	_brgh = 0;
	_stops = 0;
	_brg = 0x0c;	//Baud Rate values config
	_uren = 1;
	_txen=1;




//_____timer init for triac pin toggle_______________________________


	_ptmc0 = 0x50;				// clock selected as 32KHZ LIRC 
	_ptmc1 = 0xc1;     			//compar match A ,timer mode
	_ptmal = /*0x46;*/0xf0;				//0x109=265
	_ptmah = 0x03;				// 1/32khz=31.25usec	265*31.25=8281.25usec


	_mf1e = 1;  				//Multi-function 0 Interrupt enable Flag
	_mf1f = 0;  				//Multi-function 0 Interrupt Request Flag
	_ptmaf = 0;					//TM0 Comparator A match interrupt request flag
	_ptmae = 1; 					//TM0 Comparator A match interrupt control
	_emi = 1;
//	_pton = 1; 					//(ON)This bit controls the overall on/off function of the TM


//______timer init for timercounter of seconds timer_______

_ctm1 = 1; _ctm0 = 1;      //CTM in timer/counter mode
_ctck2 = 1; _ctck1 = 0; _ctck0 = 1;  // Use 32kHz clock
_ctcclr = 1; // clear comp A 
 _ctmal = 0x00;				/*	0x00;*/
_ctmah = 0x05;				/*0xFA;*/
_cton = 0;

	_pac7 = 0; //Buzzer pin 
	_pa7 = 0;
	_pbc6=0;
	_pb6=0;
	
//_pdc2=0;
//
//_pbc4=1;
//_ade = 0;
//_sacks2=0; _sacks1=0; _sacks0=0;
//_adcen=1;
//_sains3=0; _sains2=0; _sains1=1; _sains0=1;
//_sacs3=1; _sacs2=0; _sacs1=0; _sacs0=0;
//_adrfs=1;
//_savrs1=0; _savrs0=0;
//
//_adpgaen=0;
//
//
////_sadc0 = 0x38;
////_sadc1 = 0x03;
//_ade = 1;
//
//
//_psc0r=0x02;//0x02;
_tb0f=0;
_tb0c=0x87;// 0b10000000;
_tb0e=1;
}
//unsigned char filter(unsigned char value)
//{
//	unsigned char temp,i,ret=0;
//	
//	if(value !=255)
//	{
//		 temp = g_filter[value];	
//	}
//	for(i=0;i<FILTER_VAR_SIZE;i++)
//	{
//		g_filter[i]=0;		
//	}
//	if(value !=255)
//	{
//		g_filter[value] = temp+1;
//		ret =g_filter[value];
//	}
//	return ret;
//}

//unsigned int isInPutSqrWav(void)
//{
//	
//		union conv16bitint adc_value;
//		unsigned int pt1 ,diff,diffCnt,diffCntMax,maxVal;
//		unsigned char a;
//		a=0;
//		maxVal=0;
//	adc_value.integer =0;
//	_start =0;
//	_sadc0 = 0x38;   //AN8
//	_ctmaf = 0;
//	_cton = 1;
//	 pt1 =0;diff=0;diffCnt=0;diffCntMax=0;
////	_pa2 = 1;
//
////
//	while(_ctmaf==0)
//	{
//		
//		_start =1;
//		_start =0;
//		
//
//		if(adc_value.integer > 30)
//		{
//			if(adc_value.integer > pt1)
//			{
//				diff = adc_value.integer -pt1;
//			}else
//			{
//				diff = pt1 - adc_value.integer ;
//			}
//			
//			if(diff < 9)
//			{
//				
//				diffCnt++;
//				a=0;
//			}else
//			{
//				a++;
//				if(a>3)
//				{
//					
//					if(diffCntMax<diffCnt)
//					{
//						diffCntMax	 = diffCnt;
//						maxVal = pt1;
//						
//					}
//					diffCnt =0;
//					pt1	 = adc_value.integer;
//				}
//			} 
//		}
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
////		uart1_put_value("adc low:  ",_sadol);
//		adc_value.byte[1] = _sadoh;
////		uart1_put_value("adc high: ",_sadoh);
//			
//
//
//	}
//	
//		_cton =0;	
//		
//	//return (maxVal>>2); 
//	//return (diffCntMax)	;
////	uart1_put_value("diffCntMax:  ", diffCntMax);
////	uart1_put_value("maxVal:  ", maxVal);
//	/*uart1_put_value("difference count: ",diffCntMax);
//	uart1_put_value("max val: ",maxVal);	*/
//	if((	diffCntMax > SQR_MIN_COUNT) && (maxVal>SQR_MIN_VAL))
//	{
//		
//		return 1;
//	}
//	return (0);
//}
//
//
