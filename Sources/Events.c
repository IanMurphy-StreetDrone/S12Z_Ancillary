/* ###################################################################
**     Filename    : Events.c
**     Project     : Test_S12Z
**     Processor   : MC9S12ZVCA192MLF
**     Component   : Events
**     Version     : Driver 01.04
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2017-06-30, 22:54, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.04
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#include "globals.h"
#include "IO_Map.h"

#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Event       :  CAN1_OnFullRxBuffer (module Events)
**
**     Component   :  CAN1 [FreescaleCAN]
**     Description :
**         This event is called when the receive buffer is full after a
**         successful reception of a message. The event is available
**         only if Interrupt service/event is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/*
struct CANIDR_struct
{
	union
	{
		VUINT32	R;
		struct
		{
			VUINT16	W1;
			VUINT16	W2;
		} WORDS;
		struct
		{
			VUINT8	DUMMY	:3;
			VUINT8	IDE		:1;
			VUINT8	SRR		:1;
			VUINT16	STD_ID	:11;
			VUINT16	DUMMY2;
		} IDR_STD;
		struct
		{
			VUINT8	MID3	:3;
			VUINT8	IDE		:1;
			VUINT8	SRR		:1;
			VUINT16	TOP11	:11;
			VUINT8	RTR		:1;
			VUINT16	BOT15	:15;
		} IDR_EXT;
    } IDR;
};

volatile struct CANIDR_struct *CANRX = (struct CANIDR_struct *)(REG_BASE + 0x00000820);

#define CAN0RXIDR CANRX->IDR
*/

void CAN1_OnFullRxBuffer(void)
{
  /* Write your code here ... */

	dword Message_Rx;	
	byte  FrameType_Rx;
	byte FrameFormat_Rx;
	byte Length_Rx;
	byte Data[8];
	
	static VUINT16 timestamp;
	static VUINT8 dlc,filter;
	VUINT8 i;
	
	//id = CAN0RXIDR.IDR_STD.STD_ID;
	CAN1_ReadFrame(&Message_Rx, &FrameType_Rx, &FrameFormat_Rx, &Length_Rx, Data);


	switch(Message_Rx){
	case 0x104: //Customer_Control_2
		CANRX_timestamp[3] = CAN0RXTSR;
		
		
		for (i=0;i<CAN0RXDLR_DLC;i++)
			CANRX_data[3][i] = CAN0RXDSR_ARR[i];
		
		
		break;
	case 0x100: //StreetDrone_Control_1
		
		CANRX_timestamp[0] = CAN0RXTSR;
		
		
		for (i=0;i<CAN0RXDLR_DLC;i++)
			CANRX_data[0][i] = CAN0RXDSR_ARR[i];
	
		break;
		
	}
	
	
	
	filter = CAN0IDAC_IDHIT;
	dlc = CAN0RXDLR_DLC;
	
		
	CAN0RFLG |= CAN0RFLG_RXF_MASK; // clear Rx flag
}

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  /* Write your code here ... */
	
	extern uint16_t ms;
	extern uint16_t ms_rollovers;
	
	if(0xFFFF == ms) ms_rollovers++;
	ms++;
}

/*
** ===================================================================
**     Event       :  CAN1_OnFreeTxBuffer (module Events)
**
**     Component   :  CAN1 [FreescaleCAN]
**     Description :
**         This event is called after a successful transmission of a
**         message. The event is available only if Interrupt
**         service/event is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferMask      - Transmit buffer mask. The
**                           mask can be used to check what message
**                           buffer caused the transmit interrupt.
**     Returns     : Nothing
** ===================================================================
*/
void CAN1_OnFreeTxBuffer(word BufferMask)
{
  /* Write your code here ... */
}

/* END Events */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS12Z series of microcontrollers.
**
** ###################################################################
*/
