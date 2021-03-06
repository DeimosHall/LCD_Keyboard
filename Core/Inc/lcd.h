#ifndef  __LCD__
#define  __LCD__

#include "stm32f1xx_hal_def.h"
//----------------   LCD
#define  LCDRS_PIN      		GPIO_PIN_5		//	PA5
#define  LCDRS_PORT      		GPIOA

#define  LCDE_PIN       		GPIO_PIN_4		//	PA4
#define  LCDE_PORT       		GPIOA

#define  LCD4_PIN       		GPIO_PIN_3  	//	PB3
#define  LCD4_PORT       		GPIOB

#define  LCD5_PIN       		GPIO_PIN_4  	//	PB4
#define  LCD5_PORT       		GPIOB

#define  LCD6_PIN       		GPIO_PIN_5  	//	PB5
#define  LCD6_PORT       		GPIOB

#define  LCD7_PIN       		GPIO_PIN_6		//	PB6
#define  LCD7_PORT       		GPIOB

#define  LCDRS_OFF			HAL_GPIO_WritePin(LCDRS_PORT, LCDRS_PIN, 	GPIO_PIN_RESET)
#define  LCDE_OFF       HAL_GPIO_WritePin(LCDE_PORT , LCDE_PIN, 	GPIO_PIN_RESET)

#define  LCD4_OFF       HAL_GPIO_WritePin(LCD4_PORT, 	LCD4_PIN,  	GPIO_PIN_RESET)
#define  LCD5_OFF       HAL_GPIO_WritePin(LCD5_PORT, 	LCD5_PIN, 	GPIO_PIN_RESET)
#define  LCD6_OFF       HAL_GPIO_WritePin(LCD6_PORT, 	LCD6_PIN,  	GPIO_PIN_RESET)
#define  LCD7_OFF       HAL_GPIO_WritePin(LCD7_PORT, 	LCD7_PIN,  	GPIO_PIN_RESET)

#define  LCDRS_ON   		HAL_GPIO_WritePin(LCDRS_PORT, LCDRS_PIN, 	GPIO_PIN_SET)
#define  LCDE_ON       	HAL_GPIO_WritePin(LCDE_PORT,  LCDE_PIN, 	GPIO_PIN_SET)

#define  LCD4_ON       	HAL_GPIO_WritePin(LCD4_PORT, 	LCD4_PIN,  	GPIO_PIN_SET)
#define  LCD5_ON       	HAL_GPIO_WritePin(LCD5_PORT, 	LCD5_PIN,  	GPIO_PIN_SET)
#define  LCD6_ON       	HAL_GPIO_WritePin(LCD6_PORT, 	LCD6_PIN,  	GPIO_PIN_SET)
#define  LCD7_ON       	HAL_GPIO_WritePin(LCD7_PORT, 	LCD7_PIN,  	GPIO_PIN_SET)


//#define  TLCDRW      		GPIO_PIN_8
/*
 *  RS  :   F2
 *  RW  :   F3
 *  E   :   F4
 */

//Uncomment this if LCD 4 bit interface is used
//******************************************
#define LCD_4bit
//***********************************************

#define LCD_CGRAM           6	//DB6: set CG RAM address
#define LCD_DDRAM           7	//DB7: set DD RAM address

/*
 * Function set
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *	0 	0 	0 	0 	1 	DL 	N 	F 	? 	?
 *	(DL) data length				DL=1: 8 bits, 	DL=0: 4 bits
 *	(N)  number of display lines  	N=1:  2 lines, 	 N=0: 1 line
 *	(F)	 character font  			F=1:  5x10 dots, F=0: 5x8 dots
 */
#define  SETLCD_4BITS_2LINE    	0x28	//0b00101000
/*
 * Display	on/off
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0 	0 	0 	0 	0 	0 	1 	D 	C 	B
 *	Sets entire Display on/off				(D).
 *	Cursor on/off 							(C).
 *	Blinking of cursor position character 	(B).
 */
#define  DISPLAY_ALL_ON						0b00001111
#define  DISPLAY_ON_D_OFF_CB			0x0C	//0b00001100
#define  DISPLAY_ON_D_ON_C_OFF_B	0b00001110
#define  DISPLAY_ON_D_OFF_C_ON_B	0b00001101
/*
 * Entry mode set
 * Sets cursor move direction and specifies display shift.
 * These operations are performed during data write and read.
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0 	0 	0 	0 	0 	0 	0 	1  I/D 	S
 *  I/D=1	: Increment
 *  I/D=0	: Decrement
 *  S=1	: Accompanies display shift
 */
#define	 EMS_INC_S			0b00000110
/*
 * Cursor or display shift
 * Moves cursor and shifts display without changing DDRAM contents.
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
   	0 	0 	0 	0 	0 	1  S/C R/L 	? 	?
	S/C=1: Display shift			S/C=0: Cursor move
	R/L=1: Shift to the right		R/L=0: Shift to the left
 */
#define	DISP_MOVE_RIGHT		0b00011100
#define	DISP_MOVE_LEFT		0b00011000
#define	CURSOR_MOVE_RIGHT	0b00010100
#define	CURSOR_MOVE_LEFT	0b00010000
#define CURSOR_BLINK_ON		0b00001111 // D C B, 1 = on 0 = off
#define CURSOR_BLINK_OFF	0b00001110 // D = screen, C = cursor, B = cursor blink
#define CURSOR_ON			0b00001111
#define CURSOR_OFF			0b00001100
/*
 * Set	DDRAM
 * RS R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
 *  0 	0 	1  ADD ADD ADD ADD ADD ADD ADD
 */
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54
/*******************************************************************/
#define	 RETURN_HOME		0b00000010
#define  CLEAR_DISPLAY   	0x01	//0b00000001
/********************************************************************/

void lcd_putc(unsigned char);				//forms data ready to send to 74HC164
void lcd_command(unsigned char);				//forms data ready to send to 74HC164
void lcd_init(void);								//Initializes LCD
void lcd_puts(unsigned char*, unsigned char);	//Outputs string to LCD
void lcd_gotoxy(unsigned char, unsigned char);	//Cursor to X Y position
void lcd_definechar(unsigned char *car,unsigned char CGRAM_dir);
void lcd_clear(void);

#endif
