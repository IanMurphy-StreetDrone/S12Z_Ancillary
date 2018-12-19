/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : OUT3.h
**     Project     : S12Z
**     Processor   : MC9S12ZVCA192MLF
**     Component   : BitIO
**     Version     : Component 02.086, Driver 03.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2018-12-11, 17:10, # CodeGen: 38
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
**                       34            |  PT4_IOC0_4_MISO0_DBGEEV
**             ----------------------------------------------------
**
**         Port name                   : T
**
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : down
**
**         Port data register          : PTT       [0x02C0]
**         Port control register       : DDRT      [0x02C2]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool OUT3_GetVal(void);
**         PutVal - void OUT3_PutVal(bool Val);
**         ClrVal - void OUT3_ClrVal(void);
**         SetVal - void OUT3_SetVal(void);
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
** @file OUT3.h
** @version 03.00
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup OUT3_module OUT3 module documentation
**  @{
*/         

#ifndef OUT3_H_
#define OUT3_H_

/* MODULE OUT3. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG OUT3_CODE
/*
** ===================================================================
**     Method      :  OUT3_GetVal (component BitIO)
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
#define OUT3_GetVal() ( \
    (bool)((getReg8(PTT) & 0x10U))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  OUT3_PutVal (component BitIO)
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
void OUT3_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  OUT3_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define OUT3_ClrVal() ( \
    (void)clrReg8Bits(PTT, 0x10U)      /* PTT4=0x00U */ \
  )

/*
** ===================================================================
**     Method      :  OUT3_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define OUT3_SetVal() ( \
    (void)setReg8Bits(PTT, 0x10U)      /* PTT4=0x01U */ \
  )

#pragma CODE_SEG DEFAULT

/* END OUT3. */
#endif /* #ifndef __OUT3_H_ */
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
