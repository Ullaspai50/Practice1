#ifndef _DEBUG_H
#define _DEBUG_H


unsigned char* itoa(unsigned long num, unsigned char* str) ;
void reverse(unsigned char str[], int length) ;
void swap(unsigned char *xp, unsigned char *yp) ;
void putUart1Int(unsigned long value);
void uart1_put_value(const  char *msg,unsigned long value);


#endif