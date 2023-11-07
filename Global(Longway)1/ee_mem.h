#ifndef _EE_MEM
#define _EE_MEM






//___________________________________________________________

typedef struct {
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;

} iar_bits;

DEFINE_SFR(iar_bits, iar1, 0x02);
//iar_bits iar1	@0x02;

#define iar1_4	iar1.bit4
#define iar1_3	iar1.bit3
#define iar1_2	iar1.bit2
#define iar1_1	iar1.bit1
#define iar1_0	iar1.bit0



unsigned char EEReadChar(unsigned char addr);
void EEWriteChar(unsigned char addr,unsigned char data);
void writeDataFlashInt(unsigned char startadd,unsigned int value);

unsigned int readDataFlashInt(unsigned char addr);
void EERROM_eraseChip(void);

#endif
