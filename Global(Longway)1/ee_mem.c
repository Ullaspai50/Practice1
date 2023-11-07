
#include "HT66F3185.h"
#include "ee_mem.h"
//#include "cus_typdef.h"



unsigned char EEReadChar(unsigned char adr){
	unsigned char TempEEC;
	unsigned char EP_Read_Data;
	
	/* config EEPROM init */
	_mp2h = 1;
	_mp2l = 0x40;
	
	TempEEC = _iar2;
	
	_iar2 &= 0x6f;
	/*config EEPROM address*/
	
	_eea = adr;	
	
	/*config EEPROM Read mode*/
	_iar2 |= 0x02;
	_iar2 |= 0x01;
	
	/* waitting for EEPROM Read finishing */
	while(_iar2 & 0x01);
	_iar2 = TempEEC;
	_mp2h = 0;
		
	EP_Read_Data = _eed;		//Read data
	return EP_Read_Data;			

	
}




void EEWriteChar(unsigned char adr,unsigned char Data){

	unsigned char  TempEMI,TempEEC;
	
	TempEMI = _emi;	
	
	/*config EEPROM init*/
	_mp2h = 1;			

	_mp2l = 0x40;
	
	TempEEC = _iar2;
	
	_iar2 &= 0x6f;
	/*config EEPROM address*/	
	_eea = adr;	
	
	/*Write data*/
	_eed = Data;
	
/********** EEPROM Erase and Write time select **********/
	#ifdef	Erase_3200us_Write_2200us	
		_iar2 &= 0x7f;
		
	#else
		_iar2 |= 0x80;
	
	#endif	
/******* end of EEPROM Erase and Write time select ******/			
	_emi = 0;		//disable global interrupt		
	/*config EEPROM Write mode*/
	_iar2 |= 0x08;
	_iar2 |= 0x04;
	
	_emi = TempEMI;		//enable global interrupt		
	
	/* waitting for EEPROM write finishing */
	while(_iar2 & 0x04);
	_iar2 = TempEEC;
	_mp2h = 0;
		
	return;
	
	
}
//void EEWriteMem(unsigned char nobytes,unsigned char startadd)
//{
//
//
//	while(nobytes--)
//	{
//		EEWriteChar(startadd,getRam1_Char(startadd));
//		startadd++;
//	}	
//	
//	
//	
//}

void writeDataFlashInt(unsigned char startadd,unsigned int value)
{

	EEWriteChar(startadd,(unsigned char)value);
	EEWriteChar((startadd+1),(unsigned char)(value>>8));

}


 

unsigned int readDataFlashInt(unsigned char addr)
{

	unsigned int data;

	data =	EEReadChar(addr++);
	data = ((unsigned int)(((unsigned int)EEReadChar(addr))<<8) | data);

	return data;
}

/**
  * @brief EEPROM erase page function.
  * @param[in] Specifies EEPROM page, It can be 0x00,0x10,0x20~0x70.
  * It can be 0~7,page 0 is mapping to address 0x00~0x0f,
  * page 1 is mapping to address 0x10~0x1f,page n is mapping to address (n-1)*16~(n-1)*16+15.
  * @param[in] The Byte number, it's length can up to 16.  
  * @retval None
  */
void EEPROM_Erase_page(unsigned char page,unsigned char len)
{
	unsigned char  i;
	unsigned char TempEMI,TempEEC;
	
	if (len > 16)	len = 16;
	
	TempEMI = _emi;
	
	/*config EEPROM init*/
	_mp2h = 1;			

	_mp2l = 0x40;
	TempEEC = _iar2;
	
	_iar2 &= 0x6f;
	/*config EEPROM page*/
	
	_eea = page<<4;

/********** EEPROM Erase and Write time select **********/
	#ifdef	Erase_3200us_Write_2200us	
		_iar2 &= 0x7f;
		
	#else
		_iar2 |= 0x80;
	
	#endif	
/******* end of EEPROM Erase and Write time select ******/		

	_iar2 |= 0x10;
	/*Write data*/
	for(i = 0; i < 16; i++)
		_eed = 0x55;	
	
	_mp2h = 1;	
	_mp2l = 0x40;
	
	_emi = 0;		//disable global interrupt	
	
	/*config EEPROM Write mode*/
	_iar2 |= 0x40;
	_iar2 |= 0x20;
	
	_emi = TempEMI;		//enable global interrupt			
	/* waitting for EEPROM write finishing */
	while(_iar2 & 0x20);
	_iar2 = TempEEC;
	_mp2h = 0;
		
	return;
}


void EERROM_eraseChip(void)
{
	unsigned char page;
	for(page=0;page<8;page++)
	EEPROM_Erase_page( page,16);
	
}