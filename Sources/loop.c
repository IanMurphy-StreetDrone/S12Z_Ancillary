#include "globals.h"
#include "Can1.h"
#include "OUT1.h" //Main_beam_B*
#include "OUT2.h" //Dipped_lights_B*
#include "OUT3.h" //Side_lights_B*
#include "OUT4.h" //Right_indicator_B*
#include "OUT5.h" //Left_Indicator_B*

//Perhaps need to move horn here
#include "OUT6.h" //Reverse_Light_B
#include "OUT7.h" //Brake_Light_B
#include "OUT8.h" //Horn_B*
#include "lookup.h"


//Checkin
void loop();

typedef union CAN_msg_t
{
	uint8_t bytes[8];
	uint16_t words[4];
} CAN_msg_t;


CAN_msg_t data_out;
CAN_msg_t Customer_Control_2;
CAN_msg_t StreetDrone_Control_1;



uint8_t err;
uint8_t err1;
bool Autonomous_Mode_B = FALSE;
bool Indicator_High_B = FALSE;

//This Cal controls how frequently the indicators pulse 
int indicator_timer_cal = 400;

byte ancillary_control;

void loop()
{
	if(0 == (ms % indicator_timer_cal)){
		if (Indicator_High_B){
			Indicator_High_B = FALSE;
		}else{
			Indicator_High_B = TRUE;
		}
	}
	
	if(0 == (ms % 5))
	{	


		// unpack the CAN packet
			if(CANRX_timestamp[3] != CANRX_timestamp_prev[3])
			{
				Customer_Control_2.words[0] = (uint16_t)CANRX_data[3][0]<<8;
				Customer_Control_2.words[0] = CANRX_data[3][1];
				Customer_Control_2.words[1] = (uint16_t)CANRX_data[3][2]<<8;
				Customer_Control_2.words[1] = CANRX_data[3][3];
				Customer_Control_2.words[2] = (uint16_t)CANRX_data[3][4]<<8;
				Customer_Control_2.words[2] = CANRX_data[3][5];
				Customer_Control_2.words[3] = (uint16_t)CANRX_data[3][6]<<8;
				Customer_Control_2.words[3] = CANRX_data[3][7];

				CANRX_timestamp_prev[3] = CANRX_timestamp[3];
			}
			
			// unpack the CAN packet
			if(CANRX_timestamp[0] != CANRX_timestamp_prev[0])
			{
				StreetDrone_Control_1.words[0] = (uint16_t)CANRX_data[0][0]<<8;
				StreetDrone_Control_1.words[0] = CANRX_data[0][1];
				StreetDrone_Control_1.words[1] = (uint16_t)CANRX_data[0][2]<<8;
				StreetDrone_Control_1.words[1] = CANRX_data[0][3];
				StreetDrone_Control_1.words[2] = (uint16_t)CANRX_data[0][4]<<8;
				StreetDrone_Control_1.words[2] = CANRX_data[0][5];
				StreetDrone_Control_1.words[3] = (uint16_t)CANRX_data[0][6]<<8;
				StreetDrone_Control_1.words[3] = CANRX_data[0][7];

				CANRX_timestamp_prev[0] = CANRX_timestamp[0];
			}
					
		/**********************	
		Decoding CAN			
		***********************/
	    //Autonomous_Mode_B
	    if(((StreetDrone_Control_1.bytes[7] & 0b00000010)>>1)||((StreetDrone_Control_1.bytes[7] & 0b00100000)>>5))
	    {	
	    	Autonomous_Mode_B = TRUE;
	    }else{
	    	Autonomous_Mode_B = FALSE;
	    }
	    
	    //Main_Beam_B
	    if(((Customer_Control_2.bytes[5] & 0b00000001)>>0)&&Autonomous_Mode_B)
	    {	
			//SW1_SetDir(TRUE);
			//SW1_PutVal(TRUE);

	    }else{
	    	//SW1_SetDir(FALSE);
	    	//SW1_PutVal(FALSE);
	    }
	    
	    //Dipped_Beam_B
	    if(((Customer_Control_2.bytes[5] & 0b00000010)>>1)&&Autonomous_Mode_B)
	    {	
			//SW2_SetDir(TRUE);
			//SW2_PutVal(TRUE);

	    }else{
	    	//SW2_SetDir(FALSE);
	    	//SW2_PutVal(FALSE);
	    }
	    
	    //Side_Beam_B
	    if(((Customer_Control_2.bytes[5] & 0b00000100)>>2)&&Autonomous_Mode_B)
	    {	
			//SW3_SetDir(TRUE);
			//SW3_PutVal(TRUE);

	    }else{
	    	//SW3_SetDir(FALSE);
	    	//SW3_PutVal(FALSE);
	    }
	    
	    //Right Indicator_B only
	    if(((Customer_Control_2.bytes[5] & 0b00001000) >>3)&&Autonomous_Mode_B)
	    {	
			//SW4_SetDir(TRUE);
			//Blink the Indicator
			if(Indicator_High_B)
			{	
			//SW4_PutVal(TRUE);
			}else{
			//SW4_PutVal(FALSE);
			}

	    }else{
	    	//SW4_SetDir(FALSE);
	    	//SW4_PutVal(FALSE);
	    }
	    
	    //Left Indicator_B only
	    if(((Customer_Control_2.bytes[5] & 0b00010000)>>4)&&Autonomous_Mode_B)
	    {	
			//SW5_SetDir(TRUE);
			
			//Blink the Indicator
			if(Indicator_High_B)
			{	
				//SW5_PutVal(TRUE);
			}else{
				//SW5_PutVal(FALSE);

			}

	    }else{
	    	//SW5_SetDir(FALSE);
	    	//SW5_PutVal(FALSE);
	    }
	    
	    
	    //Hazard Lights
	    if(((Customer_Control_2.bytes[5] & 0b01000000)>>6)&&Autonomous_Mode_B)
		{	
	   		//SW4_SetDir(TRUE);
			//SW5_SetDir(TRUE);
			//Blink the Indicators
	   		if(Indicator_High_B)
	   		{
				//SW4_PutVal(TRUE);
				//SW5_PutVal(TRUE);
    		}else{
	    				
				//SW4_PutVal(FALSE);
				//SW5_PutVal(FALSE);

	   		}

	 	 }else{
	 	//Do nothing, state already set in indicator loops.
    	 }
	    	    
	    //Horn_B
	    if(((Customer_Control_2.bytes[5] & 0b10000000)>>7)&&Autonomous_Mode_B)
	    {	
			//SW8_SetDir(TRUE);
			//SW8_PutVal(TRUE);

	    }else{
	    	//SW8_SetDir(FALSE);
	    	//SW8_PutVal(FALSE);
	    }
	    
		
		data_out.bytes[0] = 0;
		data_out.bytes[1] = 0;
		data_out.bytes[2] = 0;
		data_out.bytes[3] = 0;
		data_out.bytes[4] = 0;
		data_out.bytes[5] = 0;
		data_out.bytes[6] = 0;
		data_out.bytes[7] = 0;
		if(OUT1_GetVal()) { data_out.bytes[0] += 0b00000001; }
		if(OUT2_GetVal()) { data_out.bytes[0] += 0b00000010; }
		if(OUT3_GetVal()) { data_out.bytes[0] += 0b00000100; }
		if(OUT4_GetVal()) { data_out.bytes[0] += 0b00001000; }
		if(OUT5_GetVal()) { data_out.bytes[0] += 0b00010000; }
		if(OUT6_GetVal()) { data_out.bytes[0] += 0b00100000; }
		if(OUT7_GetVal()) { data_out.bytes[0] += 0b01000000; }
		if(OUT8_GetVal()) { data_out.bytes[0] += 0b10000000; }


						
		err = CAN1_SendFrame(0,0x117,DATA_FRAME,8, &data_out.bytes[0]);
	
	}

}
