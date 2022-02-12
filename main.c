#define F_CPU 16000000UL

/////////////////////include/////////////////////////////

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h> 

int cnt = 0;
void Uart_Init();
void Uart_Putch(unsigned char data);
void Uart_U16Bit_PutNum(unsigned int NumData);
void Position_of_Dynamixel(int id, int position);
void Velocity_of_Dynamixel(int id, int speed);
volatile unsigned char flag;
/////////READY//////////
void Ready();
void Ready2();
//////////GO////////////
void GoStraight1_1();
void GoStraight1_2();
void GoStraight2_1();
void GoStraight2_2();
void GoStraight2_3();
void GoStraight3_1();
void GoStraight3_1_2();
void GoStraight3_2();
void GoStraight3_2_1();
void GoStraight4_1();
void GoStraight4_2();
void GoStraight4_3();
//////////TURN//////////
void Turn_right1();
void Turn_right2_1();
void Turn_right2_2();
void Turn_right3_1();
void Turn_right3_2();
void Turn_right4_1();
void Turn_right4_2();
void Turn_right5_1();
void Turn_right5_2();

void Turn_left1();
void Turn_left2_1();
void Turn_left2_2();
void Turn_left3_1();
void Turn_left3_2();
void Turn_left4_1();
void Turn_left4_2();
void Turn_left5_1();
void Turn_left5_2();
//////////BACK//////////
void Back1_1();
void Back1_2();
void Back2_1();
void Back2_2();
void Back3_1();
void Back3_2();
void Back4_1();
void Back4_2();
void Back4_3();

///////////////////////////////////////////////////////////

ISR(TIMER3_OVF_vect)
{
	TCNT3 = 64911;
   unsigned char data1 = 0;

   data1 = Uart_Rec();

   if(data1 == 'A')
      {
         GoForward();
         _delay_ms(500);
      }
   
   else if(data1 == 'B')
      {
         TurnLeft();
         _delay_ms(500);
      }
   else if(data1 == 'C')
      {
         TurnRight();
         _delay_ms(500);
      }
   else if(data1 == 'D')
      {
         RollingMotion();
         _delay_ms(1000);
      //   RollingStart();
      //   _delay_ms(1000);
      //   RollingEnd();
      //   _delay_ms(1000);
      }
   else if(data1 == 'F')
      {
         RollingStart();
         _delay_ms(100);
         RollingEnd();
         _delay_ms(1000);
      }

	cnt++;
}

ISR(USART0_RX_vect)
{
    flag=UDR0;
}

////////////////////////main/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

	DDRD = 0b00001000;
	DDRE = 0b00000010;          
      
	Uart_Init();
 	
	TCCR3A = 0x00;
	TCCR3B = (1<<CS32);
	ETIMSK = (1<<TOIE3);
	TCNT3 = 64911;

	SREG = 0x80;

	while(1){

		switch(flag){

			case 'a':
				PORTA = 0x0d;
				/*if ( cnt == 300 )
					Ready();
				if ( cnt == 400 )
					Ready();		
			
				if ( cnt == 500 )
					Ready2();
				if ( cnt == 550 )
					Ready2();			
		
				if ( cnt == 600 )
				{	
					PORTA = 0x0d;
					GoStraight1_1();
				}
		
				if ( cnt == 650 )
					GoStraight1_2();
		
				if ( cnt == 700 )
					GoStraight2_1();
		
				if ( cnt == 750 )
					GoStraight2_2();
		
				if ( cnt == 900 )
					GoStraight4_3();
		
				if ( cnt == 1000 )
					GoStraight3_1();
		
				if ( cnt == 1050 )
					GoStraight3_2();
		
				if ( cnt == 1100 )
					GoStraight4_1();
		
				if ( cnt == 1150 )
					GoStraight4_2();*/
				break;
		
		
			case 'b':
				PORTA = 0x07;
				/*if ( cnt == 300 )
					Ready();
				if ( cnt == 400 )
					Ready();
								
				if ( cnt == 500 )
					Ready2();
				if ( cnt == 550 )
					Ready2();
			
				if ( cnt == 600 )
				{	PORTA = 0x07;
					Turn_left1();
				}
		
				if ( cnt == 700 )
					Turn_left2_1();
		
				if ( cnt == 750 )
					Turn_left2_2();
		
				if ( cnt == 800 )
					Turn_left3_1();
		
				if ( cnt == 850 )
					Turn_left3_2();
		
				if ( cnt == 900 )
					Turn_left4_1();
		
				if ( cnt == 950 )
					Turn_left4_2();
		
				if ( cnt == 1000 )
					Turn_left5_1();
		
				if ( cnt == 1150 )
					Turn_left5_2();*/	
				break;



			case 'c':
				PORTA = 0x0e;
				/*if ( cnt == 300 )
					Ready();
				if ( cnt == 400 )
					Ready();
			
				if ( cnt == 500 )
					Ready2();
				if ( cnt == 550 )
					Ready2();
			
				if ( cnt == 600 )
				{	PORTA = 0x0e;
					Turn_right1();
				}
		
				if ( cnt == 700 )
					Turn_right2_1();
		
				if ( cnt == 750 )
					Turn_right2_2();
		
				if ( cnt == 800 )
					Turn_right3_1();
		
				if ( cnt == 850 )
					Turn_right3_2();
		
				if ( cnt == 900 )
					Turn_right4_1();
		
				if ( cnt == 950 )
					Turn_right4_2();
		
				if ( cnt == 1000 )
					Turn_right5_1();
		
				if ( cnt == 1150 )
					Turn_right5_2();*/
				break;

			case 'd':
				PORTA = 0x0b;
				/*if ( cnt == 300 )
					Ready();
				if ( cnt == 400 )
					Ready();
					
				if ( cnt == 500 )
					Ready2();
				if ( cnt == 550 )
					Ready2();
					
				if ( cnt == 600 )
				{	
					PORTA = 0x0b;
					Back1_1();
				}
		
				if ( cnt == 650 )
					Back1_2();
		
				if ( cnt == 700 )
					Back2_1();
		
				if ( cnt == 750 )
					Back2_2();
		
				if ( cnt == 900 )
					Back4_3();
		
				if ( cnt == 1000 )
					Back3_1();
		
				if ( cnt == 1050 )
					Back3_2();
		
				if ( cnt == 1100 )
					Back4_1();
		
				if ( cnt == 1150 )
					Back4_2();*/

				break;
				}
			
			}
	return 0;
}
///////////////////////void////////////////////////////////////////////////////////////////////////////////////////////////////

void Uart_Init()
{

      DDRA =  0xff;
      //PORTA = 0x00;
   
      UCSR1A = 0x00;
      UCSR1B = 0b0011000;
      UCSR1C = 0b00000110;

      UBRR1H = 0;
      UBRR1L = 0;

	  UCSR0A = 0x00;
      UCSR0B = 0b0011000;
      UCSR0C = 0b00000110;

      UBRR0H = 0;
      UBRR0L = 8;
}


void Uart_Putch(unsigned char data)
{
      while(!(UCSR1A & (1<<UDRE1)));
      UDR1 = data;
}


void Uart_U16Bit_PutNum(unsigned int NumData)
{
      unsigned int TempData;

   
      TempData = (NumData % 10000) / 1000;
      Uart_Putch(TempData + 48); // 1000 자리 출력
      TempData = (NumData % 1000) / 100;
      Uart_Putch(TempData + 48); // 100 자리 출력
      TempData = (NumData % 100) / 10;
      Uart_Putch(TempData + 48); // 10 자리 출력
      TempData = NumData % 10;
      Uart_Putch(TempData + 48); // 1자리는 값이 0이라도 그냥 찍는다.
}


///////////////////Dynamixel//////////////////////////////////////////////////////////////////////////////////////////////////////

void Position_of_Dynamixel(int id, int position){


	unsigned char idd = id & 0xff;
	unsigned char positionHigh = (position >> 8) & 0xff;
	unsigned char positionLow = position & 0xff;

	Uart_Putch(0xff);
	Uart_Putch(0xff);
	Uart_Putch(idd);	//ID
	Uart_Putch(0x05);	//LENGTH
	Uart_Putch(0x03);	//INSTRUCTION
	Uart_Putch(0x1e);	//주소
	Uart_Putch(positionLow);	//position
	Uart_Putch(positionHigh);	//position


	Uart_Putch((unsigned char)(~(((idd+0x05+0x03+0x1E)+positionLow + positionHigh)&0xff)));	//checksum
}


void Velocity_of_Dynamixel(int id, int speed){

	if(speed < 100) speed = 100;

	unsigned char idd = id & 0xff;

	unsigned char velocityHigh = (speed >> 8) & 0xff;
	unsigned char velocityLow = speed & 0xff;

	Uart_Putch(0xff);
	Uart_Putch(0xff);
	Uart_Putch(idd);	//ID
	Uart_Putch(0x05);	//LENGTH
	Uart_Putch(0x03);	//INSTRUCTION
	Uart_Putch(0x20);	//주소
	Uart_Putch(velocityLow);	//velocity
	Uart_Putch(velocityHigh);	//velocity


	Uart_Putch((unsigned char)(~(((idd+0x05+0x03+0x20)+ velocityLow + velocityHigh)&0xff)));	//checksum
}


////////////////////////////////////////////////////////////////////////////////READY/////////////////////////////////////////////////////////////

	void Ready(){

			PORTA = 0x00;		

	  		for (int id = 0; id <= 32; id++)
			{
				if ( id == 0 || id == 1 || id == 2 || id == 10 || id == 11 || id == 20 || id == 21 || id == 22 || id == 30 || id == 31 )
				{
      				Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(512));
				}

				if ( id == 1 )
				{
					Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(512));
				}
				
				if ( id == 12 || id == 32 )
				{
					Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(380));
				}
				
			}
}

	void Ready2(){
				
			PORTA = 0x00;

	  		for (int id = 0; id <= 32; id++)
			{
				if ( id == 1 || id == 2 || id == 11 || id == 31 )
				{
      				Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(350));
				
				}

				if ( id == 1 )
				{
					Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(350));
				
				}

				if ( id == 21 || id == 22 )
				{
					Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(674));
				
				}
			
				if (id == 12 || id == 32 )
				{
					Velocity_of_Dynamixel((int)(id), (int)(300));
					Position_of_Dynamixel((int)(id), (int)(230));
					
				}
				
			}
	
}

///////////////////////////////////////////////////////////////////////////////////GO/////////////////////////////////////////////////////////////


	////////////////////////////////left_back_leg////////////////////////////////
	void GoStraight1_1(){


		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(750));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(644));

			Velocity_of_Dynamixel((int)(20), (int)(300));
			Position_of_Dynamixel((int)(20), (int)(370));

			Velocity_of_Dynamixel((int)(12), (int)(300));
			Position_of_Dynamixel((int)(12), (int)(230));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(320));
}


	void GoStraight1_2(){


		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(674));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(674));

			Velocity_of_Dynamixel((int)(12), (int)(300));
			Position_of_Dynamixel((int)(12), (int)(250));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(350));

}

    //////////////////////////////////////////////////left_foward_leg////////////////////////////////////////

	void GoStraight3_1(){


		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(340));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(385));

			Velocity_of_Dynamixel((int)(0), (int)(300));
			Position_of_Dynamixel((int)(0), (int)(512));
}

	void GoStraight3_2(){


		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(350));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(350));

		
}

    //////////////////////////////////////////////////right_back_leg////////////////////////////////////////

	void GoStraight2_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(320));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(260));

			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(650));

			Velocity_of_Dynamixel((int)(2), (int)(200));
			Position_of_Dynamixel((int)(2), (int)(340));

			Velocity_of_Dynamixel((int)(12), (int)(200));
			Position_of_Dynamixel((int)(12), (int)(220));

}

	void GoStraight2_2(){
			
			/////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(350));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(230));

			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(650));
				
		}

	//////////////////////////////////////////////////right_back_leg////////////////////////////////////////


	void GoStraight4_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(200));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(200));
			Position_of_Dynamixel((int)(12), (int)(260));

			Velocity_of_Dynamixel((int)(10), (int)(200));
			Position_of_Dynamixel((int)(10), (int)(512));
}

	void GoStraight4_2(){

		    ////////////////////down/////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(200));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(200));
			Position_of_Dynamixel((int)(12), (int)(230));
		
}

	void GoStraight4_3(){

			
			/////////////////READY_RETURN////////////////
			Velocity_of_Dynamixel((int)(10), (int)(150));
			Position_of_Dynamixel((int)(10), (int)(350));
			Velocity_of_Dynamixel((int)(11), (int)(150));
			Position_of_Dynamixel((int)(11), (int)(350));
			Velocity_of_Dynamixel((int)(12), (int)(150));
			Position_of_Dynamixel((int)(12), (int)(230));

			Velocity_of_Dynamixel((int)(30), (int)(150));
			Position_of_Dynamixel((int)(30), (int)(512));
			Velocity_of_Dynamixel((int)(31), (int)(150));
			Position_of_Dynamixel((int)(31), (int)(350));
			Velocity_of_Dynamixel((int)(32), (int)(150));
			Position_of_Dynamixel((int)(32), (int)(230));

			Velocity_of_Dynamixel((int)(0), (int)(150));
			Position_of_Dynamixel((int)(0), (int)(704));
			Velocity_of_Dynamixel((int)(1), (int)(150));
			Position_of_Dynamixel((int)(1), (int)(350));
			Velocity_of_Dynamixel((int)(2), (int)(150));
			Position_of_Dynamixel((int)(2), (int)(350));

			Velocity_of_Dynamixel((int)(20), (int)(150));
			Position_of_Dynamixel((int)(20), (int)(512));
			Velocity_of_Dynamixel((int)(21), (int)(150));
			Position_of_Dynamixel((int)(21), (int)(674));
			Velocity_of_Dynamixel((int)(22), (int)(150));
			Position_of_Dynamixel((int)(22), (int)(674));
}

    /////////////////////////////////////////////////////////////////////////////////TURN_RIGHT/////////////////////////////////////////////////////////////////////////


	void Turn_right1(){

			Velocity_of_Dynamixel((int)(10), (int)(300));
			Position_of_Dynamixel((int)(10), (int)(674));
			Velocity_of_Dynamixel((int)(20), (int)(300));
			Position_of_Dynamixel((int)(20), (int)(674));
			Velocity_of_Dynamixel((int)(0), (int)(300));
			Position_of_Dynamixel((int)(0), (int)(704));
			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(704));
}

	void Turn_right2_1(){

			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(674));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(654));

			Velocity_of_Dynamixel((int)(20), (int)(300));
			Position_of_Dynamixel((int)(20), (int)(512));
}

	void Turn_right2_2(){

			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(674));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(674));
}

	void Turn_right3_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(350));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(370));

			Velocity_of_Dynamixel((int)(0), (int)(300));
			Position_of_Dynamixel((int)(0), (int)(512));
}

	void Turn_right3_2(){

		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(350));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(350));
		
}

	void Turn_right4_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(300));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(230));

			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(512));

}

	void Turn_right4_2(){
			
			/////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(350));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(230));
}

	void Turn_right5_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(300));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(300));
			Position_of_Dynamixel((int)(12), (int)(250));

			Velocity_of_Dynamixel((int)(10), (int)(300));
			Position_of_Dynamixel((int)(10), (int)(512));
}

	void Turn_right5_2(){

		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(300));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(300));
			Position_of_Dynamixel((int)(12), (int)(230));
		
}


    /////////////////////////////////////////////////////////////////////////////////TURN_LEFT/////////////////////////////////////////////////////////////////////////


	void Turn_left1(){

			Velocity_of_Dynamixel((int)(10), (int)(300));
			Position_of_Dynamixel((int)(10), (int)(350));
			Velocity_of_Dynamixel((int)(20), (int)(300));
			Position_of_Dynamixel((int)(20), (int)(350));
			Velocity_of_Dynamixel((int)(0), (int)(300));
			Position_of_Dynamixel((int)(0), (int)(320));
			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(320));
}

	void Turn_left2_1(){

			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(674));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(654));

			Velocity_of_Dynamixel((int)(20), (int)(300));
			Position_of_Dynamixel((int)(20), (int)(512));
}

	void Turn_left2_2(){

			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(674));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(674));
}

	void Turn_left3_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(350));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(370));

			Velocity_of_Dynamixel((int)(0), (int)(300));
			Position_of_Dynamixel((int)(0), (int)(512));
}

	void Turn_left3_2(){

		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(350));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(350));
		
}

	void Turn_left4_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(350));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(210));

			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(512));

}

	void Turn_left4_2(){
			
			/////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(350));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(230));
}

	void Turn_left5_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(300));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(300));
			Position_of_Dynamixel((int)(12), (int)(250));

			Velocity_of_Dynamixel((int)(10), (int)(300));
			Position_of_Dynamixel((int)(10), (int)(512));
}

	void Turn_left5_2(){

		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(300));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(300));
			Position_of_Dynamixel((int)(12), (int)(230));
		
}

///////////////////////////////////////////////////////////////////////////////////BACK/////////////////////////////////////////////////////////////


	////////////////////////////////left_forward_leg////////////////////////////////
	void Back3_1(){


		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(694));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(644));

			Velocity_of_Dynamixel((int)(20), (int)(300));
			Position_of_Dynamixel((int)(20), (int)(512));

}


	void Back3_2(){


		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(21), (int)(300));
			Position_of_Dynamixel((int)(21), (int)(674));

			Velocity_of_Dynamixel((int)(22), (int)(300));
			Position_of_Dynamixel((int)(22), (int)(674));

}

    //////////////////////////////////////////////////left_foward_leg////////////////////////////////////////

	void Back1_1(){


		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(340));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(385));

			Velocity_of_Dynamixel((int)(0), (int)(300));
			Position_of_Dynamixel((int)(0), (int)(704));
}

	void Back1_2(){


		    /////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(1), (int)(300));
			Position_of_Dynamixel((int)(1), (int)(350));

			Velocity_of_Dynamixel((int)(2), (int)(300));
			Position_of_Dynamixel((int)(2), (int)(350));

		
}

    //////////////////////////////////////////////////right_back_leg////////////////////////////////////////

	void Back4_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(330));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(260));

			Velocity_of_Dynamixel((int)(30), (int)(300));
			Position_of_Dynamixel((int)(30), (int)(512));

			Velocity_of_Dynamixel((int)(2), (int)(200));
			Position_of_Dynamixel((int)(2), (int)(340));

			Velocity_of_Dynamixel((int)(12), (int)(200));
			Position_of_Dynamixel((int)(12), (int)(220));

}

	void Back4_2(){
			
			/////////////////down///////////////////////
			Velocity_of_Dynamixel((int)(31), (int)(300));
			Position_of_Dynamixel((int)(31), (int)(350));

			Velocity_of_Dynamixel((int)(32), (int)(300));
			Position_of_Dynamixel((int)(32), (int)(230));
				
		}

	//////////////////////////////////////////////////right_back_leg////////////////////////////////////////


	void Back2_1(){

		    /////////////////////up/////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(200));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(200));
			Position_of_Dynamixel((int)(12), (int)(260));

			Velocity_of_Dynamixel((int)(10), (int)(200));
			Position_of_Dynamixel((int)(10), (int)(330));
}

	void Back2_2(){

		    ////////////////////down/////////////////////
			Velocity_of_Dynamixel((int)(11), (int)(200));
			Position_of_Dynamixel((int)(11), (int)(350));

			Velocity_of_Dynamixel((int)(12), (int)(200));
			Position_of_Dynamixel((int)(12), (int)(230));
		
}

	void Back4_3(){

			
			/////////////////READY_RETURN////////////////
			Velocity_of_Dynamixel((int)(10), (int)(150));
			Position_of_Dynamixel((int)(10), (int)(512));
			Velocity_of_Dynamixel((int)(11), (int)(150));
			Position_of_Dynamixel((int)(11), (int)(350));
			Velocity_of_Dynamixel((int)(12), (int)(150));
			Position_of_Dynamixel((int)(12), (int)(230));

			Velocity_of_Dynamixel((int)(30), (int)(150));
			Position_of_Dynamixel((int)(30), (int)(674));
			Velocity_of_Dynamixel((int)(31), (int)(150));
			Position_of_Dynamixel((int)(31), (int)(350));
			Velocity_of_Dynamixel((int)(32), (int)(150));
			Position_of_Dynamixel((int)(32), (int)(230));

			Velocity_of_Dynamixel((int)(0), (int)(150));
			Position_of_Dynamixel((int)(0), (int)(512));
			Velocity_of_Dynamixel((int)(1), (int)(150));
			Position_of_Dynamixel((int)(1), (int)(350));
			Velocity_of_Dynamixel((int)(2), (int)(150));
			Position_of_Dynamixel((int)(2), (int)(350));

			Velocity_of_Dynamixel((int)(20), (int)(150));
			Position_of_Dynamixel((int)(20), (int)(380));
			Velocity_of_Dynamixel((int)(21), (int)(150));
			Position_of_Dynamixel((int)(21), (int)(674));
			Velocity_of_Dynamixel((int)(22), (int)(150));
			Position_of_Dynamixel((int)(22), (int)(674));
}

			
