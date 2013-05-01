/*
 * startup.c
 *
 *  Created on: 28.10.2012
 *      Author: pyro
 */
#include "stm32f30x.h"

void __attribute__((weak)) Reset_Handler(void);
void __attribute__((weak)) NMI_Handler(void);
void __attribute__((weak)) HardFault_Handler(void);
void __attribute__((weak)) MemManage_Handler(void);
void __attribute__((weak)) BusFault_Handler(void);
void __attribute__((weak)) UsageFault_Handler(void);
void __attribute__((weak)) SVC_Handler(void);
void __attribute__((weak)) DebugMon_Handler(void);
void __attribute__((weak)) PendSV_Handler(void);
void __attribute__((weak)) SysTick_Handler(void);

/* External Interrupts */
void __attribute__((weak)) WWDG_IRQHandler(void); /* Window WatchDog              */
void __attribute__((weak)) PVD_IRQHandler(void); /* PVD through EXTI Line detection */
void __attribute__((weak)) TAMPER_STAMP_IRQHandler(void); /* Tamper and TimeStamps through the EXTI line */
void __attribute__((weak)) RTC_WKUP_IRQHandler(void); /* RTC Wakeup through the EXTI line */
void __attribute__((weak)) FLASH_IRQHandler(void); /* FLASH                        */
void __attribute__((weak)) RCC_IRQHandler(void); /* RCC                          */
void __attribute__((weak)) EXTI0_IRQHandler(void); /* EXTI Line0                   */
void __attribute__((weak)) EXTI1_IRQHandler(void); /* EXTI Line1                   */
void __attribute__((weak)) EXTI2_IRQHandler(void); /* EXTI Line2                   */
void __attribute__((weak)) EXTI3_IRQHandler(void); /* EXTI Line3                   */
void __attribute__((weak)) EXTI4_IRQHandler(void); /* EXTI Line4                   */
void __attribute__((weak)) DMA1_Channel1_IRQHandler(void); /* DMA1 Stream 0                */
void __attribute__((weak)) DMA1_Channel2_IRQHandler(void); /* DMA1 Stream 1                */
void __attribute__((weak)) DMA1_Channel3_IRQHandler(void); /* DMA1 Stream 2                */
void __attribute__((weak)) DMA1_Channel4_IRQHandler(void); /* DMA1 Stream 3                */
void __attribute__((weak)) DMA1_Channel5_IRQHandler(void); /* DMA1 Stream 4                */
void __attribute__((weak)) DMA1_Channel6_IRQHandler(void); /* DMA1 Stream 5                */
void __attribute__((weak)) DMA1_Channel7_IRQHandler(void); /* DMA1 Stream 6                */
void __attribute__((weak)) ADC1_2_IRQHandler(void); /* ADC1, ADC2 and ADC3s         */
void __attribute__((weak)) USB_HP_CAN1_TX_IRQHandler(void); /* CAN1 TX                      */
void __attribute__((weak)) USB_LP_CAN1_RX0_IRQHandler(void); /* CAN1 RX0                     */
void __attribute__((weak)) CAN1_RX1_IRQHandler(void); /* CAN1 RX1                     */
void __attribute__((weak)) CAN1_SCE_IRQHandler(void); /* CAN1 SCE                     */
void __attribute__((weak)) EXTI9_5_IRQHandler(void); /* External Line[9:5]s          */
void __attribute__((weak)) TIM1_BRK_TIM15_IRQHandler(void); /* TIM1 Break and TIM9          */
void __attribute__((weak)) TIM1_UP_TIM16_IRQHandler(void); /* TIM1 Update and TIM10        */
void __attribute__((weak)) TIM1_TRG_COM_TIM17_IRQHandler(void); /* TIM1 Trigger and Commutation and TIM11 */
void __attribute__((weak)) TIM1_CC_IRQHandler(void); /* TIM1 Capture Compare         */
void __attribute__((weak)) TIM2_IRQHandler(void); /* TIM2                         */
void __attribute__((weak)) TIM3_IRQHandler(void); /* TIM3                         */
void __attribute__((weak)) TIM4_IRQHandler(void); /* TIM4                         */
void __attribute__((weak)) I2C1_EV_IRQHandler(void); /* I2C1 Event                   */
void __attribute__((weak)) I2C1_ER_IRQHandler(void); /* I2C1 Error                   */
void __attribute__((weak)) I2C2_EV_IRQHandler(void); /* I2C2 Event                   */
void __attribute__((weak)) I2C2_ER_IRQHandler(void); /* I2C2 Error                   */
void __attribute__((weak)) SPI1_IRQHandler(void); /* SPI1                         */
void __attribute__((weak)) SPI2_IRQHandler(void); /* SPI2                         */
void __attribute__((weak)) USART1_IRQHandler(void); /* USART1                       */
void __attribute__((weak)) USART2_IRQHandler(void); /* USART2                       */
void __attribute__((weak)) USART3_IRQHandler(void); /* USART3                       */
void __attribute__((weak)) EXTI15_10_IRQHandler(void); /* External Line[15:10]s        */
void __attribute__((weak)) RTC_Alarm_IRQHandler(void); /* RTC Alarm (A and B) through EXTI Line */
void __attribute__((weak)) USBWakeUp_IRQHandler(void); /* USB OTG FS Wakeup through EXTI line */
void __attribute__((weak)) TIM8_BRK_TIM12_IRQHandler(void); /* TIM8 Break and TIM12         */
void __attribute__((weak)) TIM8_UP_TIM13_IRQHandler(void); /* TIM8 Update and TIM13        */
void __attribute__((weak)) TIM8_TRG_COM_TIM14_IRQHandler(void); /* TIM8 Trigger and Commutation and TIM14 */
void __attribute__((weak)) TIM8_CC_IRQHandler(void); /* TIM8 Capture Compare         */
void __attribute__((weak)) ADC3_IRQHandler(void); /* DMA1 Stream7                 */
void __attribute__((weak)) FSMC_IRQHandler(void); /* FSMC                         */
void __attribute__((weak)) SDIO_IRQHandler(void); /* SDIO                         */
void __attribute__((weak)) TIM5_IRQHandler(void); /* TIM5                         */
void __attribute__((weak)) SPI3_IRQHandler(void); /* SPI3                         */
void __attribute__((weak)) UART4_IRQHandler(void); /* UART4                        */
void __attribute__((weak)) UART5_IRQHandler(void); /* UART5                        */
void __attribute__((weak)) TIM6_DAC_IRQHandler(void); /* TIM6 and DAC1&2 underrun errors */
void __attribute__((weak)) TIM7_IRQHandler(void); /* TIM7                         */
void __attribute__((weak)) DMA2_Channel1_IRQHandler(void); /* DMA2 Stream 0                */
void __attribute__((weak)) DMA2_Channel2_IRQHandler(void); /* DMA2 Stream 1                */
void __attribute__((weak)) DMA2_Channel3_IRQHandler(void); /* DMA2 Stream 2                */
void __attribute__((weak)) DMA2_Channel4_IRQHandler(void); /* DMA2 Stream 3                */
void __attribute__((weak)) DMA2_Channel5_IRQHandler(void); /* DMA2 Stream 4                */
void __attribute__((weak)) ADC4_IRQHandler(void); /* Ethernet                     */
void __attribute__((weak)) ETH_WKUP_IRQHandler(void); /* Ethernet Wakeup through EXTI line */
void __attribute__((weak)) COMP1_2_3_IRQHandler(void); /* CAN2 TX                      */
void __attribute__((weak)) COMP4_5_6_IRQHandler(void); /* CAN2 RX0                     */
void __attribute__((weak)) COMP7_IRQHandler(void); /* CAN2 RX1                     */
void __attribute__((weak)) CAN2_SCE_IRQHandler(void); /* CAN2 SCE                     */
void __attribute__((weak)) OTG_FS_IRQHandler(void); /* USB OTG FS                   */
void __attribute__((weak)) DMA2_Stream5_IRQHandler(void); /* DMA2 Stream 5                */
void __attribute__((weak)) DMA2_Stream6_IRQHandler(void); /* DMA2 Stream 6                */
void __attribute__((weak)) DMA2_Stream7_IRQHandler(void); /* DMA2 Stream 7                */
void __attribute__((weak)) USART6_IRQHandler(void); /* USART6                       */
void __attribute__((weak)) I2C3_EV_IRQHandler(void); /* I2C3 event                   */
void __attribute__((weak)) I2C3_ER_IRQHandler(void); /* I2C3 error                   */
void __attribute__((weak)) OTG_HS_EP1_OUT_IRQHandler(void); /* USB OTG HS End Point 1 Out   */
void __attribute__((weak)) OTG_HS_EP1_IN_IRQHandler(void); /* USB OTG HS End Point 1 In    */
void __attribute__((weak)) OTG_HS_WKUP_IRQHandler(void); /* USB OTG HS Wakeup through EXTI */
void __attribute__((weak)) OTG_HS_IRQHandler(void); /* USB OTG HS                   */
void __attribute__((weak)) USB_HP_IRQHandler(void); /* DCMI                         */
void __attribute__((weak)) USB_LP_IRQHandler(void); /* CRYP crypto                  */
void __attribute__((weak)) USBWakeUp_RMP_IRQHandler(void); /* Hash and Rng                 */
void __attribute__((weak)) FPU_IRQHandler(void); /* FPU                          */

void __attribute__((weak)) Spurious_Handler(void);

/*----------------------------------------------------------------------------
 * weak aliases for each Exception handler to the Spurious_Handler.
 * Any function with the same name will override these definitions.
 */
#pragma weak     NMI_Handler                        = Spurious_Handler
#pragma weak     HardFault_Handler                  = Spurious_Handler
#pragma weak     MemManage_Handler                  = Spurious_Handler
#pragma weak     BusFault_Handler                   = Spurious_Handler
#pragma weak     UsageFault_Handler                 = Spurious_Handler
#pragma weak     SVC_Handler                        = Spurious_Handler
#pragma weak     DebugMon_Handler                   = Spurious_Handler
#pragma weak     PendSV_Handler                     = Spurious_Handler
#pragma weak     SysTick_Handler                    = Spurious_Handler
#pragma weak     WWDG_IRQHandler                    = Spurious_Handler
#pragma weak     PVD_IRQHandler                     = Spurious_Handler
#pragma weak     TAMPER_STAMP_IRQHandler              = Spurious_Handler
#pragma weak     RTC_WKUP_IRQHandler                = Spurious_Handler
#pragma weak     FLASH_IRQHandler                   = Spurious_Handler
#pragma weak     RCC_IRQHandler                     = Spurious_Handler
#pragma weak     EXTI0_IRQHandler                   = Spurious_Handler
#pragma weak     EXTI1_IRQHandler                   = Spurious_Handler
#pragma weak     EXTI2_IRQHandler                   = Spurious_Handler
#pragma weak     EXTI3_IRQHandler                   = Spurious_Handler
#pragma weak     EXTI4_IRQHandler                   = Spurious_Handler
#pragma weak     DMA1_Channel1_IRQHandler            = Spurious_Handler
#pragma weak     DMA1_Channel2_IRQHandler            = Spurious_Handler
#pragma weak     DMA1_Channel3_IRQHandler            = Spurious_Handler
#pragma weak     DMA1_Channel4_IRQHandler            = Spurious_Handler
#pragma weak     DMA1_Channel5_IRQHandler            = Spurious_Handler
#pragma weak     DMA1_Channel6_IRQHandler            = Spurious_Handler
#pragma weak     DMA1_Channel7_IRQHandler            = Spurious_Handler
#pragma weak     ADC1_2_IRQHandler                     = Spurious_Handler
#pragma weak     USB_HP_CAN1_TX_IRQHandler                 = Spurious_Handler
#pragma weak     USB_LP_CAN1_RX0_IRQHandler                = Spurious_Handler
#pragma weak     CAN1_RX1_IRQHandler                = Spurious_Handler
#pragma weak     CAN1_SCE_IRQHandler                = Spurious_Handler
#pragma weak     EXTI9_5_IRQHandler                 = Spurious_Handler
#pragma weak     TIM1_BRK_TIM15_IRQHandler           = Spurious_Handler
#pragma weak     TIM1_UP_TIM16_IRQHandler           = Spurious_Handler
#pragma weak     TIM1_TRG_COM_TIM17_IRQHandler      = Spurious_Handler
#pragma weak     TIM1_CC_IRQHandler                 = Spurious_Handler
#pragma weak     TIM2_IRQHandler                    = Spurious_Handler
#pragma weak     TIM3_IRQHandler                    = Spurious_Handler
#pragma weak     TIM4_IRQHandler                    = Spurious_Handler
#pragma weak     I2C1_EV_IRQHandler                 = Spurious_Handler
#pragma weak     I2C1_ER_IRQHandler                 = Spurious_Handler
#pragma weak     I2C2_EV_IRQHandler                 = Spurious_Handler
#pragma weak     I2C2_ER_IRQHandler                 = Spurious_Handler
#pragma weak     SPI1_IRQHandler                    = Spurious_Handler
#pragma weak     SPI2_IRQHandler                    = Spurious_Handler
#pragma weak     USART1_IRQHandler                  = Spurious_Handler
#pragma weak     USART2_IRQHandler                  = Spurious_Handler
#pragma weak     USART3_IRQHandler                  = Spurious_Handler
#pragma weak     EXTI15_10_IRQHandler               = Spurious_Handler
#pragma weak     RTC_Alarm_IRQHandler               = Spurious_Handler
#pragma weak     USBWakeUp_IRQHandler             = Spurious_Handler
#pragma weak     TIM8_BRK_TIM12_IRQHandler          = Spurious_Handler
#pragma weak     TIM8_UP_TIM13_IRQHandler           = Spurious_Handler
#pragma weak     TIM8_TRG_COM_TIM14_IRQHandler      = Spurious_Handler
#pragma weak     TIM8_CC_IRQHandler                 = Spurious_Handler
#pragma weak     ADC3_IRQHandler            = Spurious_Handler
#pragma weak     FSMC_IRQHandler                    = Spurious_Handler
#pragma weak     SDIO_IRQHandler                    = Spurious_Handler
#pragma weak     TIM5_IRQHandler                    = Spurious_Handler
#pragma weak     SPI3_IRQHandler                    = Spurious_Handler
#pragma weak     UART4_IRQHandler                   = Spurious_Handler
#pragma weak     UART5_IRQHandler                   = Spurious_Handler
#pragma weak     TIM6_DAC_IRQHandler                = Spurious_Handler
#pragma weak     TIM7_IRQHandler                    = Spurious_Handler
#pragma weak     DMA2_Channel1_IRQHandler            = Spurious_Handler
#pragma weak     DMA2_Channel2_IRQHandler            = Spurious_Handler
#pragma weak     DMA2_Channel3_IRQHandler            = Spurious_Handler
#pragma weak     DMA2_Channel4_IRQHandler            = Spurious_Handler
#pragma weak     DMA2_Channel5_IRQHandler            = Spurious_Handler
#pragma weak     ADC4_IRQHandler                     = Spurious_Handler
#pragma weak     ETH_WKUP_IRQHandler                = Spurious_Handler
#pragma weak     COMP1_2_3_IRQHandler                 = Spurious_Handler
#pragma weak     COMP4_5_6_IRQHandler                = Spurious_Handler
#pragma weak     COMP7_IRQHandler                = Spurious_Handler
#pragma weak     CAN2_SCE_IRQHandler                = Spurious_Handler
#pragma weak     OTG_FS_IRQHandler                  = Spurious_Handler
#pragma weak     DMA2_Stream5_IRQHandler            = Spurious_Handler
#pragma weak     DMA2_Stream6_IRQHandler            = Spurious_Handler
#pragma weak     DMA2_Stream7_IRQHandler            = Spurious_Handler
#pragma weak     USART6_IRQHandler                  = Spurious_Handler
#pragma weak     I2C3_EV_IRQHandler                 = Spurious_Handler
#pragma weak     I2C3_ER_IRQHandler                 = Spurious_Handler
#pragma weak     OTG_HS_EP1_OUT_IRQHandler          = Spurious_Handler
#pragma weak     OTG_HS_EP1_IN_IRQHandler           = Spurious_Handler
#pragma weak     OTG_HS_WKUP_IRQHandler             = Spurious_Handler
#pragma weak     OTG_HS_IRQHandler                  = Spurious_Handler
#pragma weak     USB_HP_IRQHandler                    = Spurious_Handler
#pragma weak     USB_LP_IRQHandler                    = Spurious_Handler
#pragma weak     USBWakeUp_RMP_IRQHandler                = Spurious_Handler
#pragma weak     FPU_IRQHandler                     = Spurious_Handler

/* exception and interrupt vector table ------------------------------------*/
typedef void (*ExceptionHandler)(void);
typedef union {
	ExceptionHandler handler;
	void *pointer;
} VectorTableEntry;

extern unsigned _estack;

/*..........................................................................*/
__attribute__ ((section(".isr_vector")))
VectorTableEntry const g_pfnVectors[] = {
		{ .pointer = &_estack },			/* initial stack pointer */
		{ .handler = &Reset_Handler },				/* Reset Handler */
		{ .handler = &NMI_Handler      },
		{ .handler = &HardFault_Handler      },
		{ .handler = &MemManage_Handler      },
		{ .handler = &BusFault_Handler      },
		{ .handler = &UsageFault_Handler      },
		{ .handler = &Spurious_Handler  },
		{ .handler = &Spurious_Handler  },
		{ .handler = &Spurious_Handler  },
		{ .handler = &Spurious_Handler  },
		{ .handler = &SVC_Handler      },
		{ .handler = &DebugMon_Handler      },
		{ .handler = &Spurious_Handler  },
		{ .handler = &PendSV_Handler      },
		{ .handler = &SysTick_Handler      },
		/* External Interrupts */
		{ .handler = &WWDG_IRQHandler      }, /* Window WatchDog              */
		{ .handler = &PVD_IRQHandler      }, /* PVD through EXTI Line detection */
		{ .handler = &TAMPER_STAMP_IRQHandler      }, /* Tamper and TimeStamps through the EXTI line */
		{ .handler = &RTC_WKUP_IRQHandler      }, /* RTC Wakeup through the EXTI line */
		{ .handler = &FLASH_IRQHandler      }, /* FLASH                        */
		{ .handler = &RCC_IRQHandler      }, /* RCC                          */
		{ .handler = &EXTI0_IRQHandler      }, /* EXTI Line0                   */
		{ .handler = &EXTI1_IRQHandler      }, /* EXTI Line1                   */
		{ .handler = &EXTI2_IRQHandler      }, /* EXTI Line2                   */
		{ .handler = &EXTI3_IRQHandler      }, /* EXTI Line3                   */
		{ .handler = &EXTI4_IRQHandler      }, /* EXTI Line4                   */
		{ .handler = &DMA1_Channel1_IRQHandler      }, /* DMA1 Stream 0                */
		{ .handler = &DMA1_Channel2_IRQHandler      }, /* DMA1 Stream 1                */
		{ .handler = &DMA1_Channel3_IRQHandler      }, /* DMA1 Stream 2                */
		{ .handler = &DMA1_Channel4_IRQHandler      }, /* DMA1 Stream 3                */
		{ .handler = &DMA1_Channel5_IRQHandler      }, /* DMA1 Stream 4                */
		{ .handler = &DMA1_Channel6_IRQHandler      }, /* DMA1 Stream 5                */
		{ .handler = &DMA1_Channel7_IRQHandler      }, /* DMA1 Stream 6                */
		{ .handler = &ADC1_2_IRQHandler      }, /* ADC1, ADC2 and ADC3s         */
		{ .handler = &USB_HP_CAN1_TX_IRQHandler      }, /* CAN1 TX                      */
		{ .handler = &USB_LP_CAN1_RX0_IRQHandler      }, /* CAN1 RX0                     */
		{ .handler = &CAN1_RX1_IRQHandler      }, /* CAN1 RX1                     */
		{ .handler = &CAN1_SCE_IRQHandler      }, /* CAN1 SCE                     */
		{ .handler = &EXTI9_5_IRQHandler      }, /* External Line[9:5]s          */
		{ .handler = &TIM1_BRK_TIM15_IRQHandler      }, /* TIM1 Break and TIM9          */
		{ .handler = &TIM1_UP_TIM16_IRQHandler      }, /* TIM1 Update and TIM10        */
		{ .handler = &TIM1_TRG_COM_TIM17_IRQHandler      }, /* TIM1 Trigger and Commutation and TIM11 */
		{ .handler = &TIM1_CC_IRQHandler      }, /* TIM1 Capture Compare         */
		{ .handler = &TIM2_IRQHandler      }, /* TIM2                         */
		{ .handler = &TIM3_IRQHandler      }, /* TIM3                         */
		{ .handler = &TIM4_IRQHandler      }, /* TIM4                         */
		{ .handler = &I2C1_EV_IRQHandler      }, /* I2C1 Event                   */
		{ .handler = &I2C1_ER_IRQHandler      }, /* I2C1 Error                   */
		{ .handler = &I2C2_EV_IRQHandler      }, /* I2C2 Event                   */
		{ .handler = &I2C2_ER_IRQHandler      }, /* I2C2 Error                   */
		{ .handler = &SPI1_IRQHandler      }, /* SPI1                         */
		{ .handler = &SPI2_IRQHandler      }, /* SPI2                         */
		{ .handler = &USART1_IRQHandler      }, /* USART1                       */
		{ .handler = &USART2_IRQHandler      }, /* USART2                       */
		{ .handler = &USART3_IRQHandler      }, /* USART3                       */
		{ .handler = &EXTI15_10_IRQHandler      }, /* External Line[15:10]s        */
		{ .handler = &RTC_Alarm_IRQHandler      }, /* RTC Alarm (A and B) through EXTI Line */
		{ .handler = &USBWakeUp_IRQHandler      }, /* USB OTG FS Wakeup through EXTI line */
		{ .handler = &TIM8_BRK_TIM12_IRQHandler      }, /* TIM8 Break and TIM12         */
		{ .handler = &TIM8_UP_TIM13_IRQHandler      }, /* TIM8 Update and TIM13        */
		{ .handler = &TIM8_TRG_COM_TIM14_IRQHandler      }, /* TIM8 Trigger and Commutation and TIM14 */
		{ .handler = &TIM8_CC_IRQHandler      }, /* TIM8 Capture Compare         */
		{ .handler = &ADC3_IRQHandler      }, /* DMA1 Stream7                 */
		
		{ .handler = &Spurious_Handler      }, /* FSMC                         */
		{ .handler = &Spurious_Handler      }, /* SDIO                         */
		{ .handler = &Spurious_Handler      }, /* TIM5                         */
		{ .handler = &SPI3_IRQHandler      }, /* SPI3                         */
		{ .handler = &UART4_IRQHandler      }, /* UART4                        */
		{ .handler = &UART5_IRQHandler      }, /* UART5                        */
		{ .handler = &TIM6_DAC_IRQHandler      }, /* TIM6 and DAC1&2 underrun errors */
		{ .handler = &TIM7_IRQHandler      }, /* TIM7                         */
		{ .handler = &DMA2_Channel1_IRQHandler      }, /* DMA2 Stream 0                */
		{ .handler = &DMA2_Channel2_IRQHandler      }, /* DMA2 Stream 1                */
		{ .handler = &DMA2_Channel3_IRQHandler      }, /* DMA2 Stream 2                */
		{ .handler = &DMA2_Channel4_IRQHandler      }, /* DMA2 Stream 3                */
		{ .handler = &DMA2_Channel5_IRQHandler      }, /* DMA2 Stream 4                */
		{ .handler = &ADC4_IRQHandler      }, /* Ethernet                     */
		
		{ .handler = &Spurious_Handler      }, /* Ethernet Wakeup through EXTI line */
		{ .handler = &Spurious_Handler      }, /* CAN2 TX                      */
		
		{ .handler = &COMP1_2_3_IRQHandler      }, /* CAN2 RX0                     */
		{ .handler = &COMP4_5_6_IRQHandler      }, /* CAN2 RX1                     */
		{ .handler = &COMP7_IRQHandler      }, /* CAN2 SCE                     */
		
		{ .handler = &Spurious_Handler      }, /* USB OTG FS                   */
		{ .handler = &Spurious_Handler      }, /* DMA2 Stream 5                */
		{ .handler = &Spurious_Handler      }, /* DMA2 Stream 6                */
		{ .handler = &Spurious_Handler      }, /* DMA2 Stream 7                */
		{ .handler = &Spurious_Handler      }, /* USART6                       */
		{ .handler = &Spurious_Handler      }, /* I2C3 event                   */
		{ .handler = &Spurious_Handler      }, /* I2C3 error                   */
		
		{ .handler = &USB_HP_IRQHandler      }, /* USB OTG HS End Point 1 Out   */
		{ .handler = &USB_LP_IRQHandler      }, /* USB OTG HS End Point 1 In    */
		{ .handler = &USBWakeUp_RMP_IRQHandler      }, /* USB OTG HS Wakeup through EXTI */
		
		{ .handler = &Spurious_Handler      }, /* USB OTG HS                   */
		{ .handler = &Spurious_Handler      }, /* DCMI                         */
		{ .handler = &Spurious_Handler      }, /* CRYP crypto                  */
		{ .handler = &Spurious_Handler      }, /* Hash and Rng                 */
		{ .handler = &FPU_IRQHandler      }, /* FPU                          */
};


/*..........................................................................*/
void Reset_Handler(void) {
	extern int main(void);
	extern void SystemInit(void);
	extern int __libc_init_array(void);
	
	extern unsigned _sdata;
	/* start of .data in the linker script */
	extern unsigned _edata;
	/* end of .data in the linker script */
	extern unsigned const _sidata; /* initialization values for .data */
	extern unsigned __bss_start__;
	/* start of .bss in the linker script */
 	 extern unsigned __bss_end__;
 	 /* end of .bss in the linker script */
 	unsigned const *src;
	unsigned *dst;
	/* copy the data segment initializers from flash to RAM... */
	src = &_sidata;
	for (dst = &_sdata; dst < &_edata; ++dst, ++src) {
		*dst = *src;
	}
	/* zero fill the .bss segment... */
	for (dst = &__bss_start__; dst < &__bss_end__; ++dst) {
		*dst = 0;
	}

	/* configure SystemClocks */
	SystemInit();

	// Enable Usage, Bus and memory fault handler
	SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk | SCB_SHCSR_MEMFAULTENA_Msk;

	/* call all static construcors in C++ (harmless in C programs) */
	__libc_init_array();
	main();
	/* call the application's entry point */
	for (;;) {
	}
}


/*..........................................................................*/
void Spurious_Handler(void) {
	/* assert_failed() should not return, but just in case the following
	 * enless loop will tie up the CPU. */
	for (;;) {
	}
}
