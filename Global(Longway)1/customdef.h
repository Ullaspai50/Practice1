#ifndef _CUSTOM_DEF_H
#define _CUSTOM_DEF_H

union int_bytes
{
	unsigned char byte[2];
	unsigned int  intVal;
};
///* define structure of Port Pin*/
union conv16bitint
{
    unsigned short integer;
    unsigned char byte[2];
};
//union conv32bitlong
//{
//    unsigned long lng;
//    unsigned char byte[4];
//};

//struct nibbles
//{
//	unsigned char nib1 : 4;
//	unsigned char nib2 : 4;


//};
//union byte_nibbles
//{
//    struct nibbles nibble;
//    unsigned char byte;
//};
//struct bits
//{
//	unsigned char bit0 : 1;
//	unsigned char bit1 : 1;
//	unsigned char bit2 : 1;
//	unsigned char bit3 : 1; 
//	unsigned char bit4 : 1;
//	unsigned char bit5 : 1;
//	unsigned char bit6 : 1;
//	unsigned char bit7 : 1;

//};
//_________________s flags____________
//typedef struct {
//
//volatile unsigned int Bit0:1;
//volatile unsigned int Bit1:1;
//volatile unsigned int Bit2:1;
//volatile unsigned int Bit3:1;
//volatile unsigned int Bit4:1;
//volatile unsigned int Bit5:1;
//volatile unsigned int Bit6:1;
//volatile unsigned int Bit7:1;
//volatile unsigned int Bit8:1;
//volatile unsigned int Bit9:1;
//volatile unsigned int Bit10:1;
//volatile unsigned int Bit11:1;
//volatile unsigned int Bit12:1;
//volatile unsigned int Bit13:1;
//volatile unsigned int Bit14:1;
//volatile unsigned int Bit15:1;
//
//}Sflags;

//_______________________Product Status_______________________________________

//struct status_1_bits
//{
//	unsigned char ldr_faulty : 1;
//	unsigned char power_on_flw : 1;
//	unsigned char quick_test : 1;
//	unsigned char DRS : 1; 
//	unsigned char LPS : 1;
//	unsigned char float_lvl : 3;

//};
//union status_1
//{
//	unsigned char byte;
//	struct status_1_bits status1_bits;
//};
//struct status_2_bits{
//	unsigned char reserve : 2;
//	unsigned char LDR_cal_mode : 2;
//	unsigned char DRS_LPS_SLCT : 2;
//	unsigned char flow_meter : 2; 

//};
//union status_2
//{
//	unsigned char byte;
//	struct status_2_bits status2_bits;
//};
//struct status_3_bits{
//	unsigned char sv2 : 2;
//	unsigned char sv1 : 2;
//	unsigned char pump : 2;
//	unsigned char uv_tube : 2; 

//};
//union status_3
//{
//	unsigned char byte;
//	struct status_3_bits status3_bits;
//};
//struct status_4_bits{
//	unsigned char com : 1;
//	unsigned char TDS_read : 1;
//	unsigned char DRS_retry : 1;
//	unsigned char re_power_fault : 1;
//	unsigned char uv_led : 2;
//	unsigned char sv3 : 2; 

//};
//union status_4
//{
//	unsigned char byte;
//	struct status_4_bits status4_bits;
//};
//struct status_5_bits{
//	unsigned char life_test_mode : 2;
//	unsigned char origa_dec_sel : 1;
//	unsigned char ea_auth_scan : 1;
//	unsigned char ro_mem : 1;
//	unsigned char post_carbon_fltr_used : 1;
//	unsigned char pre_carbon_fltr_used : 1;
//	unsigned char sediment_fltr_used : 1;

//};
//union status_5
//{
//	unsigned char byte;
//	struct status_5_bits status5_bits;
//};
//struct status_6_bits
//{
//	unsigned char ro_mem_status : 2;
//	unsigned char post_carbon_fltr_status : 2;
//	unsigned char pre_carbon_fltr_status : 2;
//	unsigned char sediment_fltr_status : 2; 

//};
//union status_6
//{
//	unsigned char byte;
//	struct status_6_bits status6_bits;
//};

//struct status_8_bits
//{
//	unsigned char ldr_multi_adc_2 : 2;
//	unsigned char reserved : 6;


//};
//union status_8
//{
//	unsigned char byte;
//	struct status_8_bits status8_bits;
//};



////___________________________________________________________________________

//struct cntrl_1_bits{
//	unsigned char reserve : 1;
//	unsigned char sv3 : 1;
//	unsigned char sv2 : 1;
//	unsigned char sv1 : 1; 
//	unsigned char ro_pump : 1;
//	unsigned char uv_led : 1;
//	unsigned char uv_tube : 1;
//	unsigned char com_fault : 1;

//};

//union cntrl_1_byte_bits{
//    struct cntrl_1_bits bitwise;
//    unsigned char byte;
//};

//struct cntrl_2_bits{
//	unsigned char reserve : 1;
//	unsigned char LDR_cal : 1;
//	unsigned char reserve0 : 1;
//	unsigned char reserve1 : 1; 
//	unsigned char reserve2 : 1;
//	unsigned char flw_qty_reset : 1;
//	unsigned char qty_based_dispn : 1;
//	unsigned char de_cal : 1;

//};

//union cntrl_2_byte_bits{
//    struct cntrl_2_bits bitwise;
//    unsigned char byte;
//};
//struct cntrl_3_bits
//{
//	unsigned char ro_mem_life_decr : 1;
//	unsigned char post_crbn_fltr_life_decr : 1;
//	unsigned char pre_crbn_fltr_life_decr : 1;
//	unsigned char sediment_fltr_life_decr : 1; 
//	unsigned char origa_decr_sel : 1;
//	unsigned char origa_cnt_decr : 1;
//	unsigned char reserve : 1;
//	unsigned char reserve1 : 1;

//};

//union cntrl_3_byte_bits{
//    struct cntrl_3_bits bitwise;
//    unsigned char byte;
//};





//struct DispCntrFun
//{
//	
//	union cntrl_1_byte_bits cntr_1;
//	union cntrl_2_byte_bits cntr_2;
//	union cntrl_3_byte_bits cntr_3;
//	union conv16bitint flowRateQty;
//	unsigned char flowRateTime;
//};



////______________________________________________________________________________
//struct FilterLife
//{

//union conv16bitint sedimentFltr;
//union conv16bitint preCarbonFltr;
//union conv16bitint postCarbonFltr;
//union conv16bitint roMembraneFltr;
//};
////_____________Pheriferal configuration_________________________________________
//struct Pheripheral_1_dtl
//{
//	
//		unsigned char roMembrane 		: 1;
//		unsigned char postCbnFltrStaus 	: 1;
//		unsigned char preCbnFltrStaus 	: 1;
//		unsigned char sedimentFltr 		: 1;
//		unsigned char reserve 			: 1;
//		unsigned char noFilter 			: 3;
//	
//};
//union Pheripheral_1
//{
//	unsigned char byte;
//	struct Pheripheral_1_dtl detail_1;
//};
//struct Pheripheral_2_dtl
//{
//	
//		unsigned char uvLedSv3Lps 		: 2;
//		unsigned char ldrMultiFlowSelc 	: 2;
//		unsigned char fltrLifecalc 		: 1;
//		unsigned char drySensor 		: 1;
//		unsigned char ctsFloat 			: 1;
//		unsigned char reserve 			: 1;
//	
//};
//union Pheripheral_2
//{
//	unsigned char byte;
//	struct Pheripheral_2_dtl detail_2;
//};
//struct PheripheralConfig
//{
//	
//	union Pheripheral_1 pheripheral_1;
//	union Pheripheral_2 pheripheral_2;
//	
//};
//________________motor fault codes_____________________________________
struct Motor_Fault_Code_bits
	{
	unsigned char lock_0 	: 1;
	unsigned char lock_1 	: 1;
	unsigned char lock_2 	: 1;
	unsigned char fault_3	: 1;
	unsigned char lock_4	: 1;
	unsigned char lock_5	: 1;
	unsigned char reserve : 2;

};
	
union Motor_Fault_Codes
{
	unsigned char byte;
	struct Motor_Fault_Code_bits MotorFaultCode_bits;
};

//________________motor status_____________________________________
struct Motor_Status_bits
{

	unsigned char reserve 	: 4;
	unsigned char MtrLck 		: 1;
	unsigned char OverCurr 	: 1;
	unsigned char Slp_Stdby : 1;
	unsigned char OverTemp 	: 1;
};

union Motor_Status
{
	unsigned char byte;
	struct Motor_Status_bits MotorStatus_bits;
};
struct ac_input_status_bits
{
	unsigned char  hi_cut_status	:1;
	unsigned char  lo_cut_status	:1;
	unsigned char input_ac_status	:1;
	unsigned char reserved				:5;
};
union ac_input_status
{
	unsigned char byte;
		struct ac_input_status_bits acinputstatus_bits;
	
};
struct Error_Status
{
	
	union Motor_Fault_Codes MotorFaultCodes;
	union Motor_Status MotorStatus;
	union ac_input_status	acinputstatus;
};


struct Value_Buff
{
	unsigned long irDataBuff;
	unsigned int MotorCurrent;
	unsigned int SupplyVolt;
	unsigned int MotorRPM;
	unsigned int SpeedCommand;
	unsigned int SpeedCommandBuff;

};

#endif


