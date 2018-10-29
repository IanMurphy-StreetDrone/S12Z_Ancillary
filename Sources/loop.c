#include "globals.h"
#include "Can1.h"
#include "PWM1.h"
#include "PWM2.h"
#include "ADC0.h"
#include "SW1.h"
#include "SW2.h"
#include "SW3.h"
#include "SW4.h"
#include "SW5.h"
#include "SW6.h"
#include "SW7.h"
#include "SW8.h"
#include "lookup.h"

//Checkin
void loop();


typedef union CAN_msg_t
{
	uint8_t bytes[8];
	uint16_t words[4];
} CAN_msg_t;

void loop()
{
	CAN_msg_t data;

	uint8_t err;
	
	//err = ADC0_GetValue16(ADCs);

	// pack the CAN packets
	if(0 == (ms % 5))
	{		
		data.bytes[0] = 0;
		data.bytes[1] = 0;
		data.bytes[2] = 0;
		data.bytes[3] = 0;
		data.bytes[4] = 0;
		data.bytes[5] = 0;
		data.bytes[6] = 0;
		data.bytes[7] = 0;
		if(SW1_GetVal()) { data.bytes[0] += 0b00000001; }
		if(SW2_GetVal()) { data.bytes[0] += 0b00000010; }
		if(SW3_GetVal()) { data.bytes[0] += 0b00000100; }
		if(SW4_GetVal()) { data.bytes[0] += 0b00001000; }
		if(SW5_GetVal()) { data.bytes[0] += 0b00010000; }
		if(SW6_GetVal()) { data.bytes[0] += 0b00100000; }
		if(SW7_GetVal()) { data.bytes[0] += 0b01000000; }
		if(SW8_GetVal()) { data.bytes[0] += 0b10000000; }


						
		err = CAN1_SendFrame(0, 0x117, DATA_FRAME, 8, &data.bytes[0]);

	}

}
