/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : EN1.c
**     Project     : S12Z_CAN_DBW
**     Processor   : MC9S12ZVCA192MLF
**     Component   : BitIO
**     Version     : Component 02.086, Driver 03.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2018-05-18, 16:07, # CodeGen: 0
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       33            |  PS7_KWS7_SS1_SENT_TX_IOC0_0
**             ----------------------------------------------------
**
**         Port name                   : S
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : 0x0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : PTS       [0x02D0]
**         Port control register       : DDRS      [0x02D2]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool EN1_GetVal(void);
**         PutVal - void EN1_PutVal(bool Val);
**         ClrVal - void EN1_ClrVal(void);
**         SetVal - void EN1_SetVal(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file EN1.c
** @version 03.00
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup EN1_module EN1 module documentation
**  @{
*/         

/* MODULE EN1. */

#include "EN1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG EN1_DATA              /* Select data segment "EN1_DATA" */
#pragma CODE_SEG EN1_CODE
#pragma CONST_SEG EN1_CONST            /* Constant section for this module */
/*
** ===================================================================
**     Method      :  EN1_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool EN1_GetVal(void)

**  This method is implemented as a macro. See EN1.h file.  **
*/

/*
** ===================================================================
**     Method      :  EN1_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void EN1_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTS, 0x80U);           /* PTS7=0x01U */
  } else { /* !Val */
    clrReg8Bits(PTS, 0x80U);           /* PTS7=0x00U */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  EN1_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void EN1_ClrVal(void)

**  This method is implemented as a macro. See EN1.h file.  **
*/

/*
** ===================================================================
**     Method      :  EN1_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void EN1_SetVal(void)

**  This method is implemented as a macro. See EN1.h file.  **
*/


/* END EN1. */
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
