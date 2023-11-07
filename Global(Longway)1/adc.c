//#include "vdm.h"
//#include "app.h"
#include "adc.h"
//#include "cus_typdef.h"
//#include "config.h"
//#include "display.h"
		
///*-----------------------------Global Variables------------------------------*/
//	extern void delay_1x_sec(void);
////	unsigned int sample_per_cycle=0;
//	extern unsigned short g_shortvar;
//	extern unsigned char flg;
//
//	#ifdef FRQ_CORRECTION
//		unsigned int low_sample_per_cycle,high_sample_per_cycle;
//		unsigned char frq_flag=0;
//	#endif
//	extern unsigned int ctOffset;
///*-----------------------------Read Adc Function-----------------------------*/
//unsigned int read_adc(unsigned char channel)
//{
//	union conv16bitint ret;
//		
//	_sadc0 = channel;
//
//	_start =0;
//	_start =1;
//	_start =0;
//	
//	while(_adbz);
//	
//	ret.byte[0] = _sadol;
//	ret.byte[1] = _sadoh;	
//	return ret.integer;
//}
//
///*-----------------------------Get RMS AC Value Function---------------------*/
//unsigned int get_rms_ac_value(unsigned char adcChannel)
//{
//
//	unsigned int count;
//	unsigned long sumval;
//	unsigned char a;
//		union conv16bitint adc_value;
//	#ifdef FRQ_CORRECTION	
//		unsigned char retry_loop=0;
//	#endif
//
//#ifdef FRQ_CORRECTION
//	LOOP:
//#endif
//	sumval =0;
//	count=0;
//	a=0;
// 
// 		_sadc0 = adcChannel;
// 
//	while(a<VAL_SMPL)
//	{
//	//	adc_value = read_adc(adcChannel);
//		
//		
//	   START_ADC
//	
//		if((adc_value.integer > ADC_H))
//		{
//			a++;	
//		}else {
//			a=0;	
//		}
//		
//		if(count++>500)	return 0;
//		
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//			
//		
//	}
//	count=0;
//	a=0;
//	
//
//	while(a<VAL_SMPL){
//		//adc_value = read_adc(adcChannel);
//		START_ADC
//		if((adc_value.integer < ADC_L)){
//			a++;	
//		}else {
//			a=0;	
//		}
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//		
//
//	}
//
//	a=0;
////_pa0 = 1;
//	do{
//		
//		//adc_value = read_adc(adcChannel);
//		START_ADC
//		//sumval   += adc_value.integer ;
//		//count++;
//		if(adc_value.integer  >ADC_L){
//			a++;	
//		}else {
//			a=0;	
//		}
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//		
//		if(count > 500){
//			return 0;
//		}
//	}while(a < 3/*VAL_SMPL*/ );	
//	
//	a=0;
//
//	do{
//		
//	//	adc_value = read_adc(adcChannel);
//		START_ADC
//		sumval   += adc_value.integer ;
//		count++;
//		if(adc_value.integer  <ADC_L){
//			a++;	
//		}else {
//			a=0;	
//		}
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//
//		
//	}while(a < VAL_SMPL );
//
//
//	//sample_per_cycle = count<<1;
////	_pa0 = 0;
//	
//#ifdef FRQ_CORRECTION	
//	if(frq_flag && retry_loop <25){
//		if((sample_per_cycle <low_sample_per_cycle)||(sample_per_cycle >high_sample_per_cycle))
//		{	retry_loop++;
//			goto LOOP;
//		}
//	}
//
//#endif
////	peakSp1 = (unsigned int)((sumval)/(count>>1));
//	sumval = (unsigned int)((sumval)/(count));
//
//	return sumval;
//}
//
//
///*-----------------------------Zerocross Function----------------------------*/
//void detect_zerocross_ac(void)
//{
//	/*unsigned int count=0;
//	union conv16bitint adc_value;
//	unsigned char a=0;	
//
//	_sadc0 = INPUT_VOLTAGE;
//	while(a<10)
//	{
//	//	adc_value = read_adc(INPUT_VOLTAGE);
//		_start =0;
//		_start =1;
//		_start =0;
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//		if((adc_value.integer > 300))
//		{
//			a++;	
//		}else {
//			a=0;	
//		}
//		if(count++>500){
//			return ;
//		}
//	}
//
//	a=0;
//	while(a<10)
//	{
//		//adc_value = read_adc(INPUT_VOLTAGE);
//		_start =0;
//		_start =1;
//		_start =0;
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;	
//		if((adc_value.integer < 80))
//		{
//			a++;	
//		}else {
//			a=0;	
//		}
//	}	*/
///*-----------------------------End-------------------------------------------*/
//}
//
//#ifdef ENABLE_CT_COIL
//unsigned int get_amps(void)
//{
//	//unsigned int ctMul;
//	//unsigned char mul;
//	unsigned long val=0,ct_val;
//
//	get_rms_ac_value(OUTPUT_VOLTAGE);
//	ct_val=get_rms_CT(CT_COIL);
//
//	if(ct_val<35 )return 0;
//	if(ct_val<CT_BASE)
//	{
//		//val=((unsigned long)(ctBase-ct_val)*1000l)/1400l;
//		val=(ct_val*40)/CT_BASE;
//		return val;		
//	}else{
//		val=((unsigned long)(ct_val-CT_BASE)*1000l)/CT_GAIN;
//		//val=((unsigned long)(ct_val)*1000l)/gain;
//		return((40+val));
//	}
//}
//#endif
////unsigned long get_rms_CT(unsigned char adcChannel)
////{
////	unsigned int count=0/*,adc_value*/;//,in;
////	unsigned long peakSp1=0,sumval=0;
////	unsigned int loop=sample_per_cycle+6;
////	union conv16bitint adc_value;
////
////	_start =0;
////	_sadc0 = adcChannel;
////	_ptma1f = 0;
////	_pt1on = 1;
////	_pa2 = 1;
//////	while(loop!=0)
////	while(_ptma1f==0)
////	{
////		
////		_start =1;
////		_start =0;
////		if(adc_value.integer >ct_offset)
////		{
////			
////			sumval   += (adc_value.integer -ct_offset);
////		count++;
////		}
//////		sumval   += adc_value.integer ct_offset;
//////		count++;
//////		loop--;
////		while(_adbz);
////		adc_value.byte[0] = _sadol;
////		adc_value.byte[1] = _sadoh;
////		//asm("nop");//asm("nop");asm("nop");
////
////		
////
////	}	
////	_pa2 = 0;
////	_pt1on = 0;
////
//////	peakSp1 = (unsigned int)((sumval)/(count>>1));
////	peakSp1 = (unsigned int)((sumval)/(count));
////	return peakSp1;
////}
////unsigned long get_rms_CT(unsigned char adcChannel)
////{
//////	unsigned int count=0/*,adc_value*/;//,in;
//////	unsigned long peakSp1=0,sumval=0;
//////	unsigned int loop=sample_per_cycle+6,peak=0;
////	union conv16bitint adc_value;
////	unsigned int peak =0;
////adc_value.integer =0;
////	_start =0;
////	_sadc0 = adcChannel;
////	_ptma1f = 0;
////	_pt1on = 1;
//////	_pa2 = 1;
//////	while(loop!=0)
////	while(_ptma1f==0)
////	{
////		
////		_start =1;
////		_start =0;
////		if(peak<adc_value.integer)
////		{
////			peak = adc_value.integer;
////		}
////		/*if(adc_value.integer >ct_offset)
////		{
////			
////			sumval   += (adc_value.integer -ct_offset);
////		count++;
////		}*/
//////		sumval   += adc_value.integer ct_offset;
//////		count++;
//////		loop--;
////		while(_adbz);
////		adc_value.byte[0] = _sadol;
////		adc_value.byte[1] = _sadoh;
////		//asm("nop");//asm("nop");asm("nop");
////
////		
////
////	}	
//////	_pa2 = 0;
////	_pt1on = 0;
////
//////	peakSp1 = (unsigned int)((sumval)/(count>>1));
//////	peakSp1 = (unsigned int)((sumval)/(count));
////	return peak;
////}
//
//unsigned int get_rms_CT(void)
//{
//
//	union conv16bitint adc_value;
//	unsigned int count=0;
//	unsigned long sumval=0;
//	adc_value.integer =0;
//	_start =0;
//	_sadc0 = ANI0;
//	_ptma1f = 0;
//	_pt1on = 1;
////	_pa2 = 1;
////	while(loop!=0)
//
//	while(_ptma1f==0)
//	{
//		
//		_start =1;
//		_start =0;
//		
//		
//		
//		
//		
//
//		if(adc_value.integer >ctOffset)
//		{
//			
//			sumval   += (adc_value.integer );
//		count++;
//		}
//
//
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//	
//
//		
//
//	}	
////	_pa2 = 0;
//	
//	_pt1on =0;
//	adc_value.integer = count;
//	 if(count>128)
//	 {
//		while(adc_value.integer--)
//		{
//			sumval   = (sumval-( ctOffset));
//			
//		}
//	 }else
//	 {
//		return 0;
//	 }
//
//	return sumval/count;
//	//return count;
//}
//
//
//unsigned int isInPutSqrWav(void)
//{
//	
//		union conv16bitint adc_value;
//		unsigned int max,min;
//		unsigned char a=0,b=0;
//		
//	adc_value.integer =0;
//	a=0;
//	b=0;
//	max =0;min=4095;
//	_start =0;
//	_sadc0 = INPUT_VOLTAGE;
//	_ptma1f = 0;
//	_pt1on = 1;
////	_pa2 = 1;
////	while(loop!=0)
//
//	while(_ptma1f==0)
//	{
//		
//		_start =1;
//		_start =0;
//		
//
//		if(adc_value.integer >50)
//		{
//			if(a>50)
//			{
//				if(b<200)
//				{
//					if(max <adc_value.integer) max =adc_value.integer;
//					if(min >adc_value.integer) min =adc_value.integer;
//					b++;
//				}
//			}else
//			{
//				a++;
//			}
//	
//		}
//
//
//		while(_adbz);
//		adc_value.byte[0] = _sadol;
//		adc_value.byte[1] = _sadoh;
//	
//
//		
//
//	}
//	
//		_pt1on =0;		
//		
//		return (max -min);
//}


unsigned int isInPutSqrWav(void)
{
	
		union conv16bitint adc_value;
		unsigned int pt1 ,diff,diffCnt,diffCntMax,maxVal;
		unsigned char a;
		a=0;
		maxVal=0;
	adc_value.integer =0;
	_start =0;
	_sadc0 = 0x38;
//	_ptma1f = 0;
//	_pt1on = 1;
	 pt1 =0;diff=0;diffCnt=0;diffCntMax=0;
//	_pa2 = 1;

//
//	while(_ptma1f==0)
//	{
		
		_start =1;
		_start =0;
		

		if(adc_value.integer >30)
		{
			if(adc_value.integer > pt1)
			{
				diff = adc_value.integer -pt1;
			}else
			{
				diff = pt1 - adc_value.integer ;
			}
			
			if(diff < 9)
			{
				
				diffCnt++;
				a=0;
			}else
			{
				a++;
				if(a>3)
				{
					
					if(diffCntMax<diffCnt)
					{
						diffCntMax	 = diffCnt;
						maxVal = pt1;
					}
					diffCnt =0;
					pt1	 = adc_value.integer;
				}
			} 
		}
		while(_adbz);
		adc_value.byte[0] = _sadol;
		adc_value.byte[1] = _sadoh;


//	}
	
//		_pt1on =0;	
		
	//return (maxVal>>2); 
	//return (diffCntMax)	;
		
	if((	diffCntMax > SQR_MIN_COUNT) && (maxVal>SQR_MIN_VOL))
	{
		
		return 1;
	}
	return (0);
}


