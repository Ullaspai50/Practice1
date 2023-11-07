#include 	"debug.h"
#include "HT66F3185.h"
void putchar(unsigned char data)
{
	
	_tx8 = 0;		
	while(!_txif)
	{
		_nop();
	}				
	_txr_rxr = data;

	while(!_tidle)		
	{
		_nop();
	}	

}
unsigned char* itoa(unsigned long num, unsigned char* str) 
{ 
    int i = 0; 
    
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  

  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % 10; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/10; 
    } 
  

  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str, i); 
  
    return str; 
} 



void reverse(unsigned char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        //swap(*(str+start), *(str+end)); 
        swap(&str[start], &str[end]); 
        start++; 
        end--; 
    } 
} 

void swap(unsigned char *xp, unsigned char *yp) 
{ 
    unsigned char temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}



void putUart1Int(unsigned long value)
{
	unsigned char d[10],i=0;
			
	itoa(value,d);
	
	/*uart0PutCh('<');*/
	while(d[i] != 0x00)
	{

	
	putchar(d[i]);
	
	i++;
	
	
	}
	putchar('\r');
	putchar('\n');
			
}


void uart1_put_value(const  char *msg,unsigned long value)
{
	unsigned char i=0;
				while(msg[i] != '\0')
				{
					
					putchar(msg[i++]);
					
				}	
				
				putUart1Int(value);
	
} 







