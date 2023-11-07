#ifndef _sysDef_h
#define _sysDef_h


#define ALL_TRIAC_OP_PIN	_pcc1=_pcc4=_pcc5=_pac1=0

#define LED_OUTPUT			_pac0=0
#define LED					_pa0
#define BUZZER				_pa7

#define	AC_VOL_IP			_pbc0=1
#define	AC_VOL_IP_INPT		_pbs0=0			//pbs is pinshared function while changing design check this carefully
#define	AC_INPT_FLAG		_int0f
#define	AC_INPT_BOTH_EDGE	_integ=0x03;	// while using both interrupt int0 and int1 be careful
#define	AC_INPT_EN			_int0e
//for old board
//#define	TRI_1				_pc1	//_pc5
//#define	TRI_2				_pc4	//_pc1
//#define	TRI_3				_pa1	//_pc4
//#define	TRI_4				_pc5	//_pa1

//for new board
#define	TRI_1			_pc5
#define	TRI_2			_pc1
#define	TRI_3			_pc4
#define	TRI_4			_pa1
#define POWER_ON								0
#define POWER_OFF								1

#define _1SEC_COUNT 	244//actually 4msec timer is used
#define _500MSEC_COUNT 122
#define _250MSEC_COUNT 61//122 //61

#define LNG_PRESS_DLY	3
#define LNG_PRESS_UNIT	5

#define MODE_POWER_ON 				0
#define MODE_PROCESS_REMOTE  		1
#define MODE_SPEED_CHANGE  			2
#define	MODE_TRIAC_CHANGE			3
#define MODE_LOW_VLT  				4
#define	MODE_IDLE					6
#define	MODE_RECOVERY				7


#define MAX_FAN_SPEED 7

#define	POWER_ON_DELAY	3


#define SKIP_ZERO_CROSS_COUNT	 4
#define NO_ZERO_CROSS_LIMIT		 7
#define RECOVERY_COUNTDOWN		 6


#define SPEEDSIZE	 3

#define	SPEED_CHANGE_WAIT_COUNT	4

typedef struct {

volatile unsigned char Bit0:1;
volatile unsigned char Bit1:1;
volatile unsigned char Bit2:1;
volatile unsigned char Bit3:1;
volatile unsigned char Bit4:1;
volatile unsigned char Bit5:1;
volatile unsigned char Bit6:1;
volatile unsigned char Bit7:1;
}Sflags;

//extern Sflags gFlags;
//#define	SEC_LOOP_FLG		gFlags.Bit0
//#define	_250MSEC_TGL_FLG	gFlags.Bit1
//#define	_250MSEC_LOOP_FLG	gFlags.Bit2
//#define	g_powerBtn			gFlags.Bit3
//#define	_250MSEC_LOOP_FLG		gFlags.Bit2
//#define	_250MSEC_LOOP_FLG		gFlags.Bit2
//#define	_250MSEC_LOOP_FLG		gFlags.Bit2
//#define	_250MSEC_LOOP_FLG		gFlags.Bit2

//________________motor fault codes_____________________________________
struct Triac_Status_bits
	{
	unsigned char pre_tr1 	: 1;
	unsigned char pre_tr2 	: 1;
	unsigned char pre_tr3 	: 1;
	unsigned char pre_tr4	: 1;
	unsigned char past_tr1	: 1;
	unsigned char past_tr2	: 1;
	unsigned char past_tr3	: 1;
	unsigned char past_tr4	: 1;

	};
	
union Triac_state
{
	unsigned char byte;
	struct Triac_Status_bits TriacStatus_bits;
};

extern union Triac_state TriacState;


#define PRESENT_TRIAC_1				TriacState.TriacStatus_bits.pre_tr1		//Present state of Triac 1, which will be used in zero crossing interrupt 
#define PRESENT_TRIAC_2				TriacState.TriacStatus_bits.pre_tr2
#define PRESENT_TRIAC_3				TriacState.TriacStatus_bits.pre_tr3
#define PRESENT_TRIAC_4				TriacState.TriacStatus_bits.pre_tr4
#define PAST_TRIAC_1				TriacState.TriacStatus_bits.past_tr1	// last state before present state of triac 1
#define PAST_TRIAC_2				TriacState.TriacStatus_bits.past_tr2
#define PAST_TRIAC_3				TriacState.TriacStatus_bits.past_tr3
#define PAST_TRIAC_4				TriacState.TriacStatus_bits.past_tr4
#define TRIAC_STATE_BYTE			TriacState.byte


extern union Triac_state TriacCheckState;
#define FUTURE_TRIAC_1						TriacCheckState.TriacStatus_bits.pre_tr1		//new  of Triac 1, which will be used in zero crossing interrupt 
#define FUTURE_TRIAC_2						TriacCheckState.TriacStatus_bits.pre_tr2
#define FUTURE_TRIAC_3						TriacCheckState.TriacStatus_bits.pre_tr3
#define FUTURE_TRIAC_4						TriacCheckState.TriacStatus_bits.pre_tr4
#define CHANGE_STATE_TRIAC_1				TriacCheckState.TriacStatus_bits.past_tr1		// change state of triac 1 
#define CHANGE_STATE_TRIAC_2				TriacCheckState.TriacStatus_bits.past_tr2
#define CHANGE_STATE_TRIAC_3				TriacCheckState.TriacStatus_bits.past_tr3
#define CHANGE_STATE_TRIAC_4				TriacCheckState.TriacStatus_bits.past_tr4
#define TriacCheckState_byte				TriacCheckState.byte




struct Triac_Timeout_Flag_bits
	{
	unsigned char flag_tr1 	: 1;				
	unsigned char flag_tr2 	: 1;
	unsigned char flag_tr3 	: 1;
	unsigned char flag_tr4	: 1;
	unsigned char skip_zero_cross_flag	: 1;
	unsigned char triac_timeout_flag	: 1;
	unsigned char new_tr3_state	: 1;
	unsigned char new_tr4_state	: 1;

	};
	
union Triac_Timeout_Flag
{
	unsigned byte;
	struct Triac_Timeout_Flag_bits	TriacTimeoutFlag_bits;
};	
	
extern union Triac_Timeout_Flag	TriacTimeoutFlag;

#define TRIAC_1_TIMEOUT_FLAG				TriacTimeoutFlag.TriacTimeoutFlag_bits.flag_tr1		//new  of Triac 1, which will be used in zero crossing interrupt 
#define TRIAC_2_TIMEOUT_FLAG				TriacTimeoutFlag.TriacTimeoutFlag_bits.flag_tr2
#define TRIAC_3_TIMEOUT_FLAG				TriacTimeoutFlag.TriacTimeoutFlag_bits.flag_tr3
#define TRIAC_4_TIMEOUT_FLAG				TriacTimeoutFlag.TriacTimeoutFlag_bits.flag_tr4
#define SKIP_ZERO_CROSS_FLAG				TriacTimeoutFlag.TriacTimeoutFlag_bits.skip_zero_cross_flag		// change state of triac 1 
#define TRIAC_TIMEOUT_FLAG					TriacTimeoutFlag.TriacTimeoutFlag_bits.triac_timeout_flag
//#define CHANGE_STATE_TRIAC_3				TriacCheckState.TriacStatus_bits.past_tr3
//#define CHANGE_STATE_TRIAC_4				TriacCheckState.TriacStatus_bits.past_tr4
//#define TriacCheckState_byte				TriacCheckState.byte
		
struct Fan_Speed_nibble
	{
	unsigned char pastSpeed 	: 4;
	unsigned char presentSpeed 	: 4;

	};	
	
union Fan_Speed_State
{
	unsigned byte;
	struct Fan_Speed_nibble	FanSpeed_nibble;
};
extern union Fan_Speed_State FanSpeedState;
extern union Fan_Speed_State FanSpeedValue;

#define fanSpeed				FanSpeedState.FanSpeed_nibble.presentSpeed		//Present state of fan speed, which will be used in zero crossing interrupt 
#define lastSpeed				FanSpeedState.FanSpeed_nibble.pastSpeed		//Present state of fan speed,  
#define newSpeed				FanSpeedValue.FanSpeed_nibble.presentSpeed		//Present state of fan speed,  
//#define LED_COUNTER				FanSpeedValue.FanSpeed_nibble.pastSpeed		//To check if the capacitor in which triac is connected is completely discharged or not before turning it on. to avoid large dv/dt  
//struct Triac_State_bits
//	{
//	unsigned char change_tr1 	: 1;				
//	unsigned char change_tr2 	: 1;
//	unsigned char change_tr3 	: 1;
//	unsigned char change_tr4	: 1;
//	unsigned char new_tr1_state	: 1;
//	unsigned char new_tr2_state	: 1;
//	unsigned char new_tr3_state	: 1;
//	unsigned char new_tr4_state	: 1;
//
//	};

#endif