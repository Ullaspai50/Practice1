#include "HT66F3185.h"
#include "sysDef.h"
#include "ee_mem.h"
#include "irRemote.h"
#include "adc.h"
#include "debug.h"


void secUpCounter(unsigned char* ptr);
void secDownCounter(unsigned char* ptr);
void _250msecDownCounter(unsigned char* ptr);
void SysInit();






bit SEC_LOOP_FLG,_250MSEC_TGL_FLG,_250MSEC_LOOP_FLG;
bit powerBtn=0;
//bit PRESENT_TRIAC_1,PRESENT_TRIAC_2,PRESENT_TRIAC_3,PRESENT_TRIAC_4;
unsigned char _250msecCntr=0,counter_128Msec=0,secCntr=0;
unsigned char No_zero_cross_counter=0;
unsigned char gMode;
unsigned char gDownCounterValue,TRIAC_1_TIMEOUT_COUNTER,TRIAC_2_TIMEOUT_COUNTER,TRIAC_3_TIMEOUT_COUNTER,LED_COUNTER;
extern unsigned long irData;
extern unsigned char TRIAC_INT;


union Triac_state TriacState;
union Fan_Speed_State FanSpeedState;
union Triac_state TriacCheckState;
union Fan_Speed_State FanSpeedValue;
union Triac_Timeout_Flag	TriacTimeoutFlag;



void turnOn_triac(void)
{
	
	if(!(FUTURE_TRIAC_1))
	{
		PRESENT_TRIAC_1=0;
//		TRIAC_TIMEOUT_COUNTER=2;
		TRIAC_1_TIMEOUT_COUNTER=0;
	}
	if(!(FUTURE_TRIAC_2))
	{
		PRESENT_TRIAC_2=0;
		TRIAC_2_TIMEOUT_COUNTER=0;
//		TRIAC_TIMEOUT_COUNTER=4;
	}
	if(!(FUTURE_TRIAC_3))
	{
		PRESENT_TRIAC_3=0;
		TRIAC_3_TIMEOUT_COUNTER=0;
//		TRIAC_TIMEOUT_COUNTER=6;
	}
	if(!(FUTURE_TRIAC_4))
	{
		PRESENT_TRIAC_4=0;
//		TRI_4=1;
//		TRIAC_TIMEOUT_COUNTER=0;
	}
	TRIAC_INT=TRIAC_STATE_BYTE	&	0x0F;

	
}
void turnoff_triac(void)
{
	if((FUTURE_TRIAC_1)&&(!PRESENT_TRIAC_1))
	{
		PRESENT_TRIAC_1=1;
		TRIAC_1_TIMEOUT_COUNTER=10;
		
	}
	if((FUTURE_TRIAC_2)&&(!PRESENT_TRIAC_2))
	{
		PRESENT_TRIAC_2=1;
		TRIAC_2_TIMEOUT_COUNTER=16;
	}
	if((FUTURE_TRIAC_3)&&(!PRESENT_TRIAC_3))
	{
		PRESENT_TRIAC_3=1;
		TRIAC_3_TIMEOUT_COUNTER=24;
	}
	if((FUTURE_TRIAC_4)&&(!PRESENT_TRIAC_4))
	{

//		uart1_put_value("TRIAC_STATE_BYTE is",TRIAC_STATE_BYTE);
		PRESENT_TRIAC_4=1;
		TRIAC_INT=TRIAC_STATE_BYTE	&	0x0F;
		TRI_4=1;
	//	TRIAC_TIMEOUT_COUNTER=0;
	//		uart1_put_value("TRIAC_STATE_BYTE is",TRIAC_STATE_BYTE);
	
	//	while(1);
	}
			TRIAC_INT=TRIAC_STATE_BYTE	&	0x0F;

	
}

void checkSpeedChange(void)
{
	unsigned char tempo;
	if(newSpeed!=fanSpeed)
	{
		lastSpeed=fanSpeed;
		fanSpeed=newSpeed;
		
		switch(fanSpeed)
		{
			case 0:
					TriacCheckState_byte=0x0F;		//first nibble is for triac and next nibble says whether it has to be changed. so making all triac high to turn off the fan and clearing the status
					break;
					
			case 1:
					TriacCheckState_byte=0x0E;
					break;
					
			case 2:
					TriacCheckState_byte=0x0D;
					break;
					
			case 3:
					TriacCheckState_byte=0x0B;
					break;
					
			case 4:
					TriacCheckState_byte=0x0A;
					break;
			case 5:
					TriacCheckState_byte=0x09;
					break;
			case 6:
					TriacCheckState_byte=0x08;
					break;
			case 7:
					TriacCheckState_byte=0x07;
					break;
			
		}
		
		tempo=TriacCheckState_byte;												//
		TriacCheckState_byte=(TriacCheckState_byte<<4)^(TRIAC_STATE_BYTE<<4);	//updating the change state of each triac
		TriacCheckState_byte=TriacCheckState_byte | tempo;
		
//		uart1_put_value("TriacCheckState_byte is",TriacCheckState_byte);
		
		
	}
}

void app()
{
	unsigned char temp;
	
	temp=20;
	while(temp--)
	GCC_DELAY(2000);
	
	powerBtn = POWER_ON;				//Initially considering power button is on
	gMode=MODE_POWER_ON;
	TriacTimeoutFlag.byte=0;
	TriacCheckState_byte=0x0F;
	gDownCounterValue=POWER_ON_DELAY;
	fanSpeed=EEReadChar(0);
	if(fanSpeed==0)
	{
		newSpeed=0;//MAX_FAN_SPEED;
		TRIAC_STATE_BYTE=0x0F;
		TRIAC_INT=0x0F;		
		
	}
	else
	{
	fanSpeed=0;
	
	newSpeed=MAX_FAN_SPEED;
	TRIAC_STATE_BYTE=0x07;
	TRIAC_INT=7;
	}

	_tb0on=1;
	LED_COUNTER=14;
	TRIAC_1_TIMEOUT_COUNTER=0;
	TRIAC_2_TIMEOUT_COUNTER=0;
	TRIAC_3_TIMEOUT_COUNTER=0;
//**********configure watch dog timer here *************//


	

	SysInit();
	while(1)
			{
							
		        temp = counter_128Msec;
		        counter_128Msec = 0;
				secCntr += temp;
				_250msecCntr += temp;
				if(_250msecCntr > _250MSEC_COUNT )
				{
					_250msecCntr = _250msecCntr % _250MSEC_COUNT;
					_250MSEC_LOOP_FLG=1;
					_250MSEC_TGL_FLG = !_250MSEC_TGL_FLG;
					if(secCntr> _1SEC_COUNT)
					{
						secCntr = secCntr % _1SEC_COUNT;
						SEC_LOOP_FLG = 1;
					}
				}
				
				
				if(_250MSEC_LOOP_FLG)
				{
					if(getIrRemotedata(&irData) ==1)				// iR kEY
					{
						gMode=MODE_PROCESS_REMOTE;

					}
					_250msecDownCounter(&LED_COUNTER);
					if(!LED_COUNTER)LED=0;
					else	LED=_250MSEC_TGL_FLG;
	
				}
				

//				if(SEC_LOOP_FLG)
//				{
//					uart1_put_value("TRIAC_1_TIMEOUT_COUNTER is ",TRIAC_1_TIMEOUT_COUNTER);
//					uart1_put_value("TRIAC_2_TIMEOUT_COUNTER is ",TRIAC_2_TIMEOUT_COUNTER);
//					uart1_put_value("TRIAC_3_TIMEOUT_COUNTER is ",TRIAC_3_TIMEOUT_COUNTER);
//				}
				
				
				if(TRIAC_TIMEOUT_FLAG)
				{
					_250msecDownCounter(&TRIAC_1_TIMEOUT_COUNTER);
					_250msecDownCounter(&TRIAC_2_TIMEOUT_COUNTER);
					_250msecDownCounter(&TRIAC_3_TIMEOUT_COUNTER);
					
					if((TRIAC_1_TIMEOUT_COUNTER==0)&&(TRIAC_2_TIMEOUT_COUNTER==0)&&(TRIAC_3_TIMEOUT_COUNTER==0))
					{
						TRIAC_TIMEOUT_FLAG=0;
					}
				}

				if(_lvdo ==1 )
				{
					gMode=MODE_LOW_VLT;
				
				}
				//------------------Mode operation begins-----------------------//
				//___________________________________________________________________________________________			 			 
				 
				switch (gMode)
				{
				
					case MODE_POWER_ON:
									{
											
										secDownCounter(&gDownCounterValue);
										if(!gDownCounterValue)
										{
											lastSpeed=fanSpeed;
											newSpeed=EEReadChar(0);
											if((newSpeed>MAX_FAN_SPEED)/* || (!newSpeed)*/)newSpeed=MAX_FAN_SPEED;
											gMode=MODE_SPEED_CHANGE;
											gDownCounterValue=2;
											
										//	newSpeed=1;
										}
										
										
									}
									break;
					case MODE_PROCESS_REMOTE:
									{
													 						
										irKeyProcess(irData);
									//	if(fanSpeed!=5)TRI_4=1;			//if the IR pressed fanspeed is not maximum speed turn off triac 4 to start getting zero crossing 
										if(newSpeed!=fanSpeed)
										gDownCounterValue=SPEED_CHANGE_WAIT_COUNT;
										else gDownCounterValue=0;
										gMode=MODE_SPEED_CHANGE;
										LED_COUNTER=(newSpeed<<1)+1;
										
									}
									break;
									
									
					case MODE_SPEED_CHANGE:
									{
										_250msecDownCounter(&gDownCounterValue);
										if(!gDownCounterValue)
										{
											
											checkSpeedChange();	
											if(TRIAC_TIMEOUT_FLAG==0)
											{
												turnoff_triac();//turn off triac here
												gMode=MODE_TRIAC_CHANGE;
												gDownCounterValue=SKIP_ZERO_CROSS_COUNT;
												SKIP_ZERO_CROSS_FLAG=1;
												TRIAC_TIMEOUT_FLAG=1;//start triac timer
											}
											
												 
										}
																	
									
										
										
									}
									break;
									
									
					case MODE_TRIAC_CHANGE:
									{
									//	_250msecDownCounter(&gDownCounterValue);
										if(!gDownCounterValue)
										{
											
											SKIP_ZERO_CROSS_FLAG=0;
											turnOn_triac();	//turn on triac here
											gMode=MODE_IDLE;
												
										
										}
												
									}
									break;
					case MODE_LOW_VLT:
									{
											lastSpeed=EEReadChar(0);
											if(lastSpeed!=newSpeed)
											{
												EEWriteChar(0,newSpeed);
												gMode=MODE_IDLE;
											}
											
									
										
									}
									break;	
									
									
					case	MODE_IDLE:
									{
							
										if(TRI_4)
										{
											if(No_zero_cross_counter>NO_ZERO_CROSS_LIMIT)
											{
												TRI_1=1;
												TRI_2=1;
												TRI_3=1;
												TRI_4=1;
												gMode=MODE_RECOVERY;
												gDownCounterValue=RECOVERY_COUNTDOWN;
												TRIAC_INT=15;
											}
										}
											
									}
									break;	
									
					case	MODE_RECOVERY:
									{
										secDownCounter(&gDownCounterValue);
										if(!gDownCounterValue)
										{
											if(No_zero_cross_counter<NO_ZERO_CROSS_LIMIT)
											{
												fanSpeed=0;
												gMode=MODE_SPEED_CHANGE;
											}
											
											//discuss this with chethan sir
										}
										//what if zero crossing starts
									}
									break;
					
				
				}
				
			/*	if(_250MSEC_LOOP_FLG)
				{
					switch (gMode)
					{
							
						case MODE_POWER_ON:
										{
												
											uart1_put_value("gMode is power on",gDownCounterValue);
											uart1_put_value("newSpeed is ",newSpeed);
											
											
										}
										break;
						case MODE_PROCESS_REMOTE:
										{
														 						
											uart1_put_value("gMode is MODE_PROCESS_REMOTE",gDownCounterValue);
											uart1_put_value("FAN_SPEED is",newSpeed);

											
										}
										break;
										
										
						case MODE_SPEED_CHANGE:
										{
														
											
											uart1_put_value("gMode is speed change",gDownCounterValue);
											uart1_put_value("TRIAC_INT is",TRIAC_INT);
											uart1_put_value("PRESENT_TRIAC_1 is",PRESENT_TRIAC_1);
											uart1_put_value("PRESENT_TRIAC_2 is",PRESENT_TRIAC_2);
											uart1_put_value("PRESENT_TRIAC_3 is",PRESENT_TRIAC_3);
											uart1_put_value("PRESENT_TRIAC_4 is",PRESENT_TRIAC_4);
											
											
										}
										break;
										
										
						case MODE_TRIAC_CHANGE:
										{
											
											
											uart1_put_value("gMode is MODE_TRIAC_CHANGE",PRESENT_TRIAC_1);
											uart1_put_value("PRESENT_TRIAC_2 is",PRESENT_TRIAC_2);
											uart1_put_value("PRESENT_TRIAC_3 is",PRESENT_TRIAC_3);
											uart1_put_value("PRESENT_TRIAC_4 is",PRESENT_TRIAC_4);
												
										}
										break;						
						case MODE_IDLE:
										{
											
											
											uart1_put_value("gMode is MODE_IDLE",PRESENT_TRIAC_1);
											uart1_put_value("PRESENT_TRIAC_2 is",PRESENT_TRIAC_2);
											uart1_put_value("PRESENT_TRIAC_3 is",PRESENT_TRIAC_3);
											uart1_put_value("PRESENT_TRIAC_4 is",PRESENT_TRIAC_4);
												
										}
										break;	
					
						
				}	}
		*/
				//________________________loopflags clear
				_250MSEC_LOOP_FLG=0;					
				SEC_LOOP_FLG=0;
			
				
			}
}
void SysInit()
{






//---init timer base for 1 sec delay
	//_psc0r = 0x03;
	_tb0f =0;
	_tb0c = 0x87;
	_tb0e =1;
	
}
void __attribute((interrupt(0x1C))) timer_128mSec(void)
{
	
	{
		_tb0f=0;
		counter_128Msec++;	
		if(No_zero_cross_counter<100)
		No_zero_cross_counter++;
		//	_pb6=!_pb6;
	}
}


void secUpCounter(unsigned char* ptr)
{
	
		if(SEC_LOOP_FLG)
		{
			(*ptr)++;
		}

}
void secDownCounter(unsigned char* ptr)
{
	
		if(SEC_LOOP_FLG)
		{
			if(*ptr!=0)
			(*ptr)--;
		}

}
void _250msecDownCounter(unsigned char* ptr)
{
	
		if(_250MSEC_LOOP_FLG)
		{
			if(*ptr!=0)
			(*ptr)--;
		}
//final code finishedd//
}