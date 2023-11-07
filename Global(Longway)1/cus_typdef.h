#ifndef CUST_TYP_DEF
#define CUST_TYP_DEF


union conv16bitint
{
    unsigned short integer;
    unsigned char byte[2];
};

 struct bits{
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1; 
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;

};

union byte_bits{
    struct bits bitwise;
    unsigned char byte;
};

struct disp_flg {
	//unsigned char bit0 : 1;
	unsigned char toggle_delay : 4;
	unsigned char index : 4;
	

};
struct nibble {
	//unsigned char bit0 : 1;
	unsigned char u_nibble : 4;
	unsigned char l_nibble : 4;
	

};

struct _7_1Bits {
	
	unsigned char count : 7;
	unsigned char flag1 : 1;
	
	

};

union byte_7_1Bits{
    unsigned char byte;
    struct _7_1Bits dat;
};


union byte_nibble{
    unsigned char byte;
    struct nibble nib;
};
union disp_var{
    struct disp_flg bitwise;
    unsigned char byte;
};


#endif
