#include "HT66F3185.h"
#include "customdef.h"
//#include "irRemote.h"
#include "LONGWAY_remote.h"
#include "debug.h"
#ifdef UART_EN
#include "debug.h"
#endif

#include "sysDef.h"
#include "ee_mem.h"

//extern unsigned char fanSpeed,lastSpeed;
unsigned int tmArry[64],speed_temp;
unsigned char tmindex=0;
union int_bytes timerCount;
unsigned char irDataStage=0,irDataIndex=0,irIndex=0;
unsigned long irData=0;
bit irDatavalid=0;
//extern bit powerBtn,LED_INDICATON_FLAG,LED_FLAG;
extern unsigned int timer_count,count;
extern unsigned long keyPressIndiVal;
//extern void uart1_put_value(const  char *msg,unsigned long value);
//extern unsigned int buzz_count,BUZZ_STOP,change;
//extern bit BUZZ_FLAG,writeflag;
unsigned char toggle = 0;
extern bit powerBtn;

/************************
************************************************************************************/
/*    Capture interrupt subroutine                                                                   */
/************************************************************************************************************/



  // @brief external Interruption 0 routine.
  // @par Parameters:
  // None
  // @retval
 // None
  
void __attribute((interrupt(0x24))) INT1_ISR(void)
{
		_ston = 0;
		timerCount.byte[1] = _stmdh;
		timerCount.byte[0] = _stmdl;

		_ston = 1;
//		timerModeCounter++;
	
		
	switch(irDataStage)
	{
		case 0:
				{
					/*	if(irDataIndex<32)
						tmArry[irDataIndex++] = timerCount.intVal;*/
					
					
					
					
					if((timerCount.intVal >SART_BIT_RNG_L) &&(timerCount.intVal <SART_BIT_RNG_H))
					{
						irDataStage =1;
						//	printf("irDataStage =1\n\r");
					}
					
				}
				break;
		case 1:
				{
					if((timerCount.intVal >SART_BIT2_RNG_L) &&(timerCount.intVal <SART_BIT2_RNG_H))
					{
						irDataStage = 2; 
						irDataIndex=0;
						irIndex=0;
						irData =0;
					}else
					{
						
						irDataStage =0;
					}
					
				}
				break;
		case 2:
				{
					irIndex++;
					
					if(irIndex &0x01)
					{
					}else
					{
						tmArry[irDataIndex++] = timerCount.intVal;
						if(irDataIndex > 32) 
						{
							irDatavalid =1;
							irDataStage =0;
							_int1e =0;
							_ston = 0;
						}
					}
					
				}
				break;		
		
	}
	
	
}


//
//void Capture_ISR (void) 
//{
//	
//		/*timerCount.byte[1] = C2L;
//		timerCount.byte[0] = C2H;
//		clr_CAPCON0_CAPF2;
//		clr_T2CON_TF2;*/
////	if(irDataIndex < 64) 
////	tmArry[irDataIndex++] = timerCount.intVal;
////printf("ISR\n\r");
//		if((timerCount.intVal >SART_BIT_RNG_L) &&(timerCount.intVal <SART_BIT_RNG_H))
//		{
//			irDataStage =1;
//			//	printf("irDataStage =1\n\r");
//		}else if((timerCount.intVal >SART_BIT2_RNG_L) &&(timerCount.intVal <SART_BIT2_RNG_H))
//		{
//			if(irDataStage ==1)
//			{
//				irDataStage = 2; 
//				irDataIndex=0;
//				irIndex=0;
//				irData =0;
//				//printf("irDataStage =2\n\r");
//			}
//			else irDataStage =0;
//		}else if(irDataStage ==2)					// picking thedata bits 
//		{
//			irIndex++;
//			
//			if(irIndex &0x01)
//			{
//			}else
//			{
//				tmArry[irDataIndex++] = timerCount.intVal;
//				if(irDataIndex > 32) 
//				{
//					irDatavalid =1;
//					irDataStage =0;
//					//clr_EIE_ECAP ;
//				}
//			}
//			
//		}
//
//	
//		//_pop_(SFRS);
//}


unsigned char getIrRemotedata(unsigned long* value)
{
	unsigned long dataValue=0;
	unsigned char i;
	/*	uart1_put_value("timervalue",timerCount.intVal);
		uart1_put_value("datastage",irDataStage);*/
		
		if(irDatavalid)
		{			
			//printf("irDatavalid:%d \n\r",(unsigned int)irDatavalid);
			for(i=0;i<32;i++)
			{
				dataValue =dataValue<<1;
					//printf("tmArry:%u \n\r",(unsigned int)tmArry[i]);
				if((tmArry[i] >LOW_BIT_RNG_L) &&(tmArry[i] <LOW_BIT_RNG_H))
				{
					 
				}else if((tmArry[i] >HI_BIT_RNG_L) &&((tmArry[i] <HI_BIT_RNG_H)))
				{
					dataValue |=0x00000001;
				}else
				{
					irDataStage =0;
					irDatavalid=0;
					_int1e =1;
				
					return 0;
				}
			}
			irDatavalid=0;
			*value = dataValue;
			_int1e = 1;
			//printf("dataValue:%u \n\r",(unsigned int)dataValue);
			return 1;
			
		}else
		{
			return 0;
		}

		
	
}


void irKeyProcess(unsigned long key)
{
				keyPressIndiVal =key;
			
	/*	if(powerBtn == POWER_OFF)
		{
			if(key == IR_PWR_ON)
			{
				//setFanSpeed(fanSpeed);
//				powerBtn = POWER_ON;
//				lastSpeed=EEReadChar(0);
//				if (lastSpeed>5 || lastSpeed == 0)
//					lastSpeed=5;
//					fanSpeed = lastSpeed;
				newSpeed=MAX_FAN_SPEED;
				LED=0;
				LED_FLAG = 0;
				BUZZER = 0;
			    LED_INDICATON_FLAG=1;
				change=fanSpeed*2;
				buzz_count=0;
				BUZZ_STOP=2;
				BUZZ_FLAG=1;*/
				//uart1_put_value("fan speed",fanSpeed );
			//	uart1_put_value("last speed",lastSpeed );		
			//	uart1_put_value("////////////////POWER ON///////////////",1111);
		//	}
		//	else
		//	{
			/*	buzz_count=0;
				BUZZ_STOP=4;
				BUZZ_FLAG=1;*/
		//	}
	
	//	}
	//	else*/
		{
//			fanModeFlag=0;
			
			//printf("key value %d\n",key);
	//		uart1_put_value("IR remote.c Key value",key);
	
				switch(key)
				{
												
					case IR_SPEED_1:
													{
													//printf("IR_SPEED_1");	
														/*lastSpeed = fanSpeed;
													//	strtup();
														fanSpeed =1;*/
													//	Digi_mod_speed=1;
														/*buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
														change =2;
														LED_INDICATON_FLAG=1;*/
													//	writeflag = 1;
														newSpeed=1;
														#ifdef UART_EN

														uart1_put_value("IR_SPEED_1",fanSpeed);
														#endif
													//digismart_speedchanger();
													
														//setFanSpeed(fanSpeed);
														
													
													}
													break;
					
					case IR_SPEED_2:
													{
													
													//	lastSpeed = fanSpeed;
													//	startup();
														newSpeed = 2;
													//	Digi_mod_speed=2;
													/*	buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
														change =4;
														LED_INDICATON_FLAG=1;*/
													//	writeflag = 1;
													#ifdef UART_EN

														uart1_put_value("IR_SPEED_2",fanSpeed);
														#endif
													//digismart_speedchanger();
													//	setFanSpeed(fanSpeed);
													//	printf("IR_SPEED_2");
														
													}
													break;
					case IR_SPEED_3:
					case IR_SPEED_3_AL:
													{
												
														//lastSpeed = fanSpeed;
													//	startup();
														newSpeed =3;
													//	Digi_mod_speed=3;
													/*	buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
														change =6;*/
														//LED_INDICATON_FLAG=1;
													//	writeflag = 1;
													#ifdef UART_EN

														uart1_put_value("IR_SPEED_3",fanSpeed);
														#endif
													//digismart_speedchanger();
														//setFanSpeed(fanSpeed);
													//	printf("IR_SPEED_3");
														
													}
													break;		
					case IR_SPEED_4:
					case IR_SPEED_4_AL:
													{
												
													//	lastSpeed = fanSpeed;
													//	startup();	
														newSpeed=4;
													//	Digi_mod_speed=4;
														/*buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
														change =8;*/
//														LED_INDICATON_FLAG=1;
													//	writeflag = 1;
													#ifdef UART_EN

														uart1_put_value("IR_SPEED_4",fanSpeed);
														#endif
													//digismart_speedchanger();
														//setFanSpeed(fanSpeed);
													//	printf("IR_SPEED_4");
														
													}
													break;	
						case IR_SPEED_5:
						case IR_SPEED_5_AL:
													{
												
													//	lastSpeed = fanSpeed;
													//	startup();	
														newSpeed =5;
														/*buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
													//	Digi_mod_speed=5;
														change =10;
														LED_INDICATON_FLAG=1;*/
													//	writeflag = 1;
													#ifdef UART_EN

														uart1_put_value("IR_SPEED_5",fanSpeed);
														#endif
													//digismart_speedchanger();
														//setFanSpeed(fanSpeed);
													//	printf("IR_SPEED_5");
													
													}
													break; 	
						case IR_SPEED_6:
						case IR_SPEED_6_AL:
													{
												
													//	lastSpeed = fanSpeed;
													//	startup();	
														newSpeed =6;
														/*buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
													//	Digi_mod_speed=5;
														change =10;
														LED_INDICATON_FLAG=1;*/
													//	writeflag = 1;
													#ifdef UART_EN

														uart1_put_value("IR_SPEED_6",fanSpeed);
														#endif
													//digismart_speedchanger();
														//setFanSpeed(fanSpeed);
													//	printf("IR_SPEED_5");
													
													}
													break; 	
						case IR_SPEED_7:
						case IR_SPEED_7_AL:
													{
												
													//	lastSpeed = fanSpeed;
													//	startup();	
														newSpeed =7;
														/*buzz_count=0;
														BUZZ_STOP=2;
														BUZZ_FLAG=1;
													//	Digi_mod_speed=5;
														change =10;
														LED_INDICATON_FLAG=1;*/
													//	writeflag = 1;
													#ifdef UART_EN

														uart1_put_value("IR_SPEED_7",fanSpeed);
														#endif
													//digismart_speedchanger();
														//setFanSpeed(fanSpeed);
													//	printf("IR_SPEED_5");
													
													}
													break; 	
//					case IR_SPEED_6:
//													{
//													
//													
//														lastSpeed = fanSpeed;
//													//	startup();	
//														fanSpeed =6;
//														buzz_count=0;
//														BUZZ_STOP=2;
//														BUZZ_FLAG=1;
//													//	Digi_mod_speed=6;
//														change =12;
//														LED_INDICATON_FLAG=1;
//													//	writeflag = 1;
//													//	uart1_put_value("IR_SPEED_6",fanSpeed);
//													//digismart_speedchanger();
//														//setFanSpeed(fanSpeed);
//														//printf("IR_SPEED_5");
//													
//													}
//													break; 	
//						case IR_SPEED_7:
//													{
//													
//													
//														lastSpeed = fanSpeed;
//													//	startup();	
//														fanSpeed =7;
//														buzz_count=0;
//														BUZZ_STOP=2;
//														BUZZ_FLAG=1;
//													//	Digi_mod_speed=7;
//														change =14;
//														LED_INDICATON_FLAG=1;
//													//	writeflag = 1;
//													//	uart1_put_value("IR_SPEED_7",fanSpeed);
//													//digismart_speedchanger();
//														//setFanSpeed(fanSpeed);
//														//printf("IR_SPEED_5");
//													
//													}
//													break; 

							case IR_PWR_OFF :
							case IR_PWR_OFF_AL:	
												if(newSpeed!=0)	
												{	
														powerBtn = POWER_OFF;									
													//	LED_FLAG=0;
													//	lastSpeed=fanSpeed;
														EEWriteChar(0,newSpeed);
														newSpeed=0;
														LED=1;
													/*	change =2;
												//		g_chng_spd_flg=1;
														buzz_count=0;
          												BUZZ_STOP=4;
        											    BUZZ_FLAG = 1;*/
												/*		count=0;
														timer_count=0;
														uart1_put_value("fan speed",fanSpeed );
														uart1_put_value("last speed",lastSpeed );	*/	
														#ifdef UART_EN

														uart1_put_value("////////////POWER OFF From REMOTE/////////",0000);
														#endif
														//powerBtn = POWER_OFF;
												}
												
												

												
													
													break; 	
													
							case IR_PWR_ON:
							case IR_PWR_ON_AL:
												//if(powerBtn==POWER_OFF)
												{
													powerBtn = POWER_ON;

														if(newSpeed==0)
													{
														
														newSpeed=EEReadChar(0);
														if (newSpeed>MAX_FAN_SPEED || newSpeed == 0)
															newSpeed=MAX_FAN_SPEED;
													}
													//fanSpeed = lastSpeed;
												//	newSpeed=MAX_FAN_SPEED;
												/*	LED_INDICATON_FLAG=1;
													change=fanSpeed*2;
													buzz_count=0;
													BUZZ_STOP=2;
													BUZZ_FLAG=1;*/
													#ifdef UART_EN

													uart1_put_value("////////////POWER OFF From REMOTE/////////",0000);
													#endif
												}
				
													break; 
												
							case IR_INC:
							
												{
												speed_temp=newSpeed;
												speed_temp=speed_temp+1;
												if(speed_temp>=7)
													speed_temp=7;
												newSpeed=speed_temp;
												/*LED_INDICATON_FLAG=1;
												change=fanSpeed*2;
												buzz_count=0;
												BUZZ_STOP=2;
												BUZZ_FLAG=1;*/	

												#ifdef UART_EN

												uart1_put_value("Increase: ",newSpeed);
												#endif
												}
													break; 
													
							case IR_DEC:
									
												{
												speed_temp=newSpeed;
												if(speed_temp!=0)
													speed_temp=speed_temp-1;
												if(speed_temp<=3)
													speed_temp=3;
												newSpeed=speed_temp;
												/*change=fanSpeed*2;
												buzz_count=0;
												BUZZ_STOP=2;
												BUZZ_FLAG=1;*/	
												#ifdef UART_EN

												uart1_put_value("Decrease: ",newSpeed);
												#endif
												}
													break; 		

				}	
//				uart1_put_value("g_chng_spd_flg is",g_chng_spd_flg);		
//				uart1_put_value("POWER STATUS-------------",powerBtn);
//				uart1_put_value("lastspeed is",lastSpeed);
//				uart1_put_value("From KeyProcess Fanspeed is________________________________",fanSpeed);
		}
		
//		LED_INDICATON_FLAG=1;
//		change=2;
	
}	
	
	
