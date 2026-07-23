#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

//global pointer to fn carries the addr of isr functions for each of
//the exti according to index
void (*EXTI_CallBack[3]) (void) = { NULL }; 

//for the prebuild config "EXTI_config.h"
void EXTI_voidInit      ( void ){

	#ifdef EXTI_LINE

		/*  Check for EXTI line  */
		#if EXTI_LINE == EXTI_LINE1

			/* Check for Sence Mode  */
			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR_REG , 2 ); CLR_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR_REG , 2 ); SET_BIT( MCUCR_REG , 3 );

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR_REG , 2 ); SET_BIT( MCUCR_REG , 3 );

			#endif


		#elif EXTI_LINE == EXTI_LINE0

			#if     EXTI_SENSE_MODE == EXTI_LOW_LEVEL

				CLR_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_ON_CHANGE

				SET_BIT( MCUCR_REG , 0 ); CLR_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

				CLR_BIT( MCUCR_REG , 0 ); SET_BIT( MCUCR_REG , 1 );

			#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

				SET_BIT( MCUCR_REG , 0 ); SET_BIT( MCUCR_REG , 1 );

			#endif

		#elif EXTI_LINE == EXTI_LINE2

				#if     EXTI_SENSE_MODE == EXTI_FALLING_EDGE

					CLR_BIT( MCUCSR_REG , 6 );

				#elif     EXTI_SENSE_MODE == EXTI_RISING_EDGE

					SET_BIT( MCUCSR_REG , 6 );

				#endif

		#else
				#error "Wrong INT0_SENSE configuration option"
		
		#endif

	#endif

}

/*
Description:  A function to set the required sense control of INT0 using postbuild configuration
Input:	Copy_u8Sense , options are: 1-  LOW_LEVEL
  	                                2-  ON_CHANGE
  	                                3-  FALLING_EDGE
  	                                4-  RISING_EDGE
*/
void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line ){

	/* For EXTI0 & EXTI1 */
	if( Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <= EXTI_LINE1 ){

		Copy_u8Line = ( 6 - Copy_u8Line ) * -2 ;

		switch( Copy_u8SenseMode ){

		/* INT Sence Control (Trigger) For EXTI0 & EXTI1   */
		case EXTI_LOW_LEVEL    : CLR_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
		case EXTI_ON_CHANGE    : SET_BIT( MCUCR_REG , Copy_u8Line ); CLR_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCR_REG , Copy_u8Line ); SET_BIT( MCUCR_REG , Copy_u8Line + 1 ); break;

		}
	}

	/* For EXTI2 */
	else{

		switch( Copy_u8SenseMode ){
		
		/* INT Sence Control (Trigger) For EXTI0 & EXTI1   */
		case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR_REG , 6 );  break;
		case EXTI_RISING_EDGE  : SET_BIT( MCUCSR_REG , 6 );  break;

		}

	}

}

u8 EXTI_voidDisableInterrupt   ( u8 Copy_u8Line ){

	u8 Local_u8ErrorState = OK ;
	if ( (Copy_u8Line>EXTI_LINE2) && (Copy_u8Line<EXTI_LINE1) )  /* Check [5:7] */
	{
		/* Clear The Required BIT */
		CLR_BIT( GICR_REG , Copy_u8Line );
	}
	else 
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState ;

}

u8 EXTI_voidEnableInterrupt    ( u8 Copy_u8Line ){

	u8 Local_u8ErrorState = OK ;
	if ( (Copy_u8Line>EXTI_LINE2) && (Copy_u8Line<EXTI_LINE1) )  /* Check [5:7] */
	{
		/* Set The Required BIT */
		SET_BIT( GICR_REG , Copy_u8Line );
	}
	else 
	{
		Local_u8ErrorState = NOK ;
	}
	
	return Local_u8ErrorState ;

}

void EXTI_voidClearFlag ( u8 Copy_u8Line ){

	SET_BIT( GIFR_REG , Copy_u8Line );

}

u8 EXTI_u8GetFlag( u8 Copy_u8Line ){

	return GET_BIT( GIFR_REG , Copy_u8Line );

}

void EXTI_voidSetCallBack( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine ){

	if( Copy_pvoidCallBack != NULL ){

		EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack ;

	}

}

