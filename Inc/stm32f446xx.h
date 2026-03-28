#ifndef __STM32F446xx_H
#define __STM32F446xx_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define __CM4_REV              0x0001U
#define __MPU_PRESENT          1U
#define __NVIC_PRIO_BITS       4U
#define __Vendor_SysTickConfig 0U
#define __FPU_PRESENT          1U
    typedef enum
    {
        /******  Cortex-M4 Processor Exceptions Numbers
         ****************************************************************/
        NonMaskableInt_IRQn   = -14,
        MemoryManagement_IRQn = -12,
        BusFault_IRQn         = -11,
        UsageFault_IRQn       = -10,
        SVCall_IRQn           = -5,
        DebugMonitor_IRQn     = -4,
        PendSV_IRQn           = -2,
        SysTick_IRQn          = -1,
        /******  STM32 specific Interrupt Numbers
         **********************************************************************/
        WWDG_IRQn               = 0,
        PVD_IRQn                = 1,
        TAMP_STAMP_IRQn         = 2,
        RTC_WKUP_IRQn           = 3,
        FLASH_IRQn              = 4,
        RCC_IRQn                = 5,
        EXTI0_IRQn              = 6,
        EXTI1_IRQn              = 7,
        EXTI2_IRQn              = 8,
        EXTI3_IRQn              = 9,
        EXTI4_IRQn              = 10,
        DMA1_Stream0_IRQn       = 11,
        DMA1_Stream1_IRQn       = 12,
        DMA1_Stream2_IRQn       = 13,
        DMA1_Stream3_IRQn       = 14,
        DMA1_Stream4_IRQn       = 15,
        DMA1_Stream5_IRQn       = 16,
        DMA1_Stream6_IRQn       = 17,
        ADC_IRQn                = 18,
        CAN1_TX_IRQn            = 19,
        CAN1_RX0_IRQn           = 20,
        CAN1_RX1_IRQn           = 21,
        CAN1_SCE_IRQn           = 22,
        EXTI9_5_IRQn            = 23,
        TIM1_BRK_TIM9_IRQn      = 24,
        TIM1_UP_TIM10_IRQn      = 25,
        TIM1_TRG_COM_TIM11_IRQn = 26,
        TIM1_CC_IRQn            = 27,
        TIM2_IRQn               = 28,
        TIM3_IRQn               = 29,
        TIM4_IRQn               = 30,
        I2C1_EV_IRQn            = 31,
        I2C1_ER_IRQn            = 32,
        I2C2_EV_IRQn            = 33,
        I2C2_ER_IRQn            = 34,
        SPI1_IRQn               = 35,
        SPI2_IRQn               = 36,
        USART1_IRQn             = 37,
        USART2_IRQn             = 38,
        USART3_IRQn             = 39,
        EXTI15_10_IRQn          = 40,
        RTC_Alarm_IRQn          = 41,
        OTG_FS_WKUP_IRQn        = 42,
        TIM8_BRK_TIM12_IRQn     = 43,
        TIM8_UP_TIM13_IRQn      = 44,
        TIM8_TRG_COM_TIM14_IRQn = 45,
        TIM8_CC_IRQn            = 46,
        DMA1_Stream7_IRQn       = 47,
        FMC_IRQn                = 48,
        SDIO_IRQn               = 49,
        TIM5_IRQn               = 50,
        SPI3_IRQn               = 51,
        UART4_IRQn              = 52,
        UART5_IRQn              = 53,
        TIM6_DAC_IRQn           = 54,
        TIM7_IRQn               = 55,
        DMA2_Stream0_IRQn       = 56,
        DMA2_Stream1_IRQn       = 57,
        DMA2_Stream2_IRQn       = 58,
        DMA2_Stream3_IRQn       = 59,
        DMA2_Stream4_IRQn       = 60,
        CAN2_TX_IRQn            = 63,
        CAN2_RX0_IRQn           = 64,
        CAN2_RX1_IRQn           = 65,
        CAN2_SCE_IRQn           = 66,
        OTG_FS_IRQn             = 67,
        DMA2_Stream5_IRQn       = 68,
        DMA2_Stream6_IRQn       = 69,
        DMA2_Stream7_IRQn       = 70,
        USART6_IRQn             = 71,
        I2C3_EV_IRQn            = 72,
        I2C3_ER_IRQn            = 73,
        OTG_HS_EP1_OUT_IRQn     = 74,
        OTG_HS_EP1_IN_IRQn      = 75,
        OTG_HS_WKUP_IRQn        = 76,
        OTG_HS_IRQn             = 77,
        DCMI_IRQn               = 78,
        FPU_IRQn                = 81,
        SPI4_IRQn               = 84,
        SAI1_IRQn               = 87,
        SAI2_IRQn               = 91,
        QUADSPI_IRQn            = 92,
        CEC_IRQn                = 93,
        SPDIF_RX_IRQn           = 94,
        FMPI2C1_EV_IRQn         = 95,
        FMPI2C1_ER_IRQn         = 96
    } IRQn_Type;

#include "core_cm4.h" /* Cortex-M4 processor and core peripherals */
#include "system_stm32f4xx.h"
#include <stdint.h>

    typedef struct
    {
        __IO uint32_t SR;
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t SMPR1;
        __IO uint32_t SMPR2;
        __IO uint32_t JOFR1;
        __IO uint32_t JOFR2;
        __IO uint32_t JOFR3;
        __IO uint32_t JOFR4;
        __IO uint32_t HTR;
        __IO uint32_t LTR;
        __IO uint32_t SQR1;
        __IO uint32_t SQR2;
        __IO uint32_t SQR3;
        __IO uint32_t JSQR;
        __IO uint32_t JDR1;
        __IO uint32_t JDR2;
        __IO uint32_t JDR3;
        __IO uint32_t JDR4;
        __IO uint32_t DR;
    } ADC_TypeDef;

    typedef struct
    {
        __IO uint32_t CSR;
        __IO uint32_t CCR;
        __IO uint32_t CDR;
    } ADC_Common_TypeDef;

    typedef struct
    {
        __IO uint32_t TIR;
        __IO uint32_t TDTR;
        __IO uint32_t TDLR;
        __IO uint32_t TDHR;
    } CAN_TxMailBox_TypeDef;

    typedef struct
    {
        __IO uint32_t RIR;
        __IO uint32_t RDTR;
        __IO uint32_t RDLR;
        __IO uint32_t RDHR;
    } CAN_FIFOMailBox_TypeDef;

    typedef struct
    {
        __IO uint32_t FR1;
        __IO uint32_t FR2;
    } CAN_FilterRegister_TypeDef;

    typedef struct
    {
        __IO uint32_t MCR;
        __IO uint32_t MSR;
        __IO uint32_t TSR;
        __IO uint32_t RF0R;
        __IO uint32_t RF1R;
        __IO uint32_t IER;
        __IO uint32_t ESR;
        __IO uint32_t BTR;
        uint32_t RESERVED0[88];
        CAN_TxMailBox_TypeDef sTxMailBox[3];
        CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
        uint32_t RESERVED1[12];
        __IO uint32_t FMR;
        __IO uint32_t FM1R;
        uint32_t RESERVED2;
        __IO uint32_t FS1R;
        uint32_t RESERVED3;
        __IO uint32_t FFA1R;
        uint32_t RESERVED4;
        __IO uint32_t FA1R;
        uint32_t RESERVED5[8];
        CAN_FilterRegister_TypeDef sFilterRegister[28];
    } CAN_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t CFGR;
        __IO uint32_t TXDR;
        __IO uint32_t RXDR;
        __IO uint32_t ISR;
        __IO uint32_t IER;
    } CEC_TypeDef;

    typedef struct
    {
        __IO uint32_t DR;
        __IO uint8_t IDR;
        uint8_t RESERVED0;
        uint16_t RESERVED1;
        __IO uint32_t CR;
    } CRC_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t SWTRIGR;
        __IO uint32_t DHR12R1;
        __IO uint32_t DHR12L1;
        __IO uint32_t DHR8R1;
        __IO uint32_t DHR12R2;
        __IO uint32_t DHR12L2;
        __IO uint32_t DHR8R2;
        __IO uint32_t DHR12RD;
        __IO uint32_t DHR12LD;
        __IO uint32_t DHR8RD;
        __IO uint32_t DOR1;
        __IO uint32_t DOR2;
        __IO uint32_t SR;
    } DAC_TypeDef;

    typedef struct
    {
        __IO uint32_t IDCODE;
        __IO uint32_t CR;
        __IO uint32_t APB1FZ;
        __IO uint32_t APB2FZ;
    } DBGMCU_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t SR;
        __IO uint32_t RISR;
        __IO uint32_t IER;
        __IO uint32_t MISR;
        __IO uint32_t ICR;
        __IO uint32_t ESCR;
        __IO uint32_t ESUR;
        __IO uint32_t CWSTRTR;
        __IO uint32_t CWSIZER;
        __IO uint32_t DR;
    } DCMI_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t NDTR;
        __IO uint32_t PAR;
        __IO uint32_t M0AR;
        __IO uint32_t M1AR;
        __IO uint32_t FCR;
    } DMA_Stream_TypeDef;

    typedef struct
    {
        __IO uint32_t LISR;
        __IO uint32_t HISR;
        __IO uint32_t LIFCR;
        __IO uint32_t HIFCR;
    } DMA_TypeDef;

    typedef struct
    {
        __IO uint32_t IMR;
        __IO uint32_t EMR;
        __IO uint32_t RTSR;
        __IO uint32_t FTSR;
        __IO uint32_t SWIER;
        __IO uint32_t PR;
    } EXTI_TypeDef;

    typedef struct
    {
        __IO uint32_t ACR;
        __IO uint32_t KEYR;
        __IO uint32_t OPTKEYR;
        __IO uint32_t SR;
        __IO uint32_t CR;
        __IO uint32_t OPTCR;
        __IO uint32_t OPTCR1;
    } FLASH_TypeDef;

    typedef struct
    {
        __IO uint32_t BTCR[8];
    } FMC_Bank1_TypeDef;

    typedef struct
    {
        __IO uint32_t BWTR[7];
    } FMC_Bank1E_TypeDef;

    typedef struct
    {
        __IO uint32_t PCR;
        __IO uint32_t SR;
        __IO uint32_t PMEM;
        __IO uint32_t PATT;
        uint32_t RESERVED;
        __IO uint32_t ECCR;
    } FMC_Bank3_TypeDef;

    typedef struct
    {
        __IO uint32_t SDCR[2];
        __IO uint32_t SDTR[2];
        __IO uint32_t SDCMR;
        __IO uint32_t SDRTR;
        __IO uint32_t SDSR;
    } FMC_Bank5_6_TypeDef;

    typedef struct
    {
        __IO uint32_t MODER;
        __IO uint32_t OTYPER;
        __IO uint32_t OSPEEDR;
        __IO uint32_t PUPDR;
        __IO uint32_t IDR;
        __IO uint32_t ODR;
        __IO uint32_t BSRR;
        __IO uint32_t LCKR;
        __IO uint32_t AFR[2];
    } GPIO_TypeDef;

    typedef struct
    {
        __IO uint32_t MEMRMP;
        __IO uint32_t PMC;
        __IO uint32_t EXTICR[4];
        uint32_t RESERVED[2];
        __IO uint32_t CMPCR;
        uint32_t RESERVED1[2];
        __IO uint32_t CFGR;
    } SYSCFG_TypeDef;

    typedef struct
    {
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t OAR1;
        __IO uint32_t OAR2;
        __IO uint32_t DR;
        __IO uint32_t SR1;
        __IO uint32_t SR2;
        __IO uint32_t CCR;
        __IO uint32_t TRISE;
        __IO uint32_t FLTR;
    } I2C_TypeDef;

    typedef struct
    {
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t OAR1;
        __IO uint32_t OAR2;
        __IO uint32_t TIMINGR;
        __IO uint32_t TIMEOUTR;
        __IO uint32_t ISR;
        __IO uint32_t ICR;
        __IO uint32_t PECR;
        __IO uint32_t RXDR;
        __IO uint32_t TXDR;
    } FMPI2C_TypeDef;

    typedef struct
    {
        __IO uint32_t KR;
        __IO uint32_t PR;
        __IO uint32_t RLR;
        __IO uint32_t SR;
    } IWDG_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t CSR;
    } PWR_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t PLLCFGR;
        __IO uint32_t CFGR;
        __IO uint32_t CIR;
        __IO uint32_t AHB1RSTR;
        __IO uint32_t AHB2RSTR;
        __IO uint32_t AHB3RSTR;
        uint32_t RESERVED0;
        __IO uint32_t APB1RSTR;
        __IO uint32_t APB2RSTR;
        uint32_t RESERVED1[2];
        __IO uint32_t AHB1ENR;
        __IO uint32_t AHB2ENR;
        __IO uint32_t AHB3ENR;
        uint32_t RESERVED2;
        __IO uint32_t APB1ENR;
        __IO uint32_t APB2ENR;
        uint32_t RESERVED3[2];
        __IO uint32_t AHB1LPENR;
        __IO uint32_t AHB2LPENR;
        __IO uint32_t AHB3LPENR;
        uint32_t RESERVED4;
        __IO uint32_t APB1LPENR;
        __IO uint32_t APB2LPENR;
        uint32_t RESERVED5[2];
        __IO uint32_t BDCR;
        __IO uint32_t CSR;
        uint32_t RESERVED6[2];
        __IO uint32_t SSCGR;
        __IO uint32_t PLLI2SCFGR;
        __IO uint32_t PLLSAICFGR;
        __IO uint32_t DCKCFGR;
        __IO uint32_t CKGATENR;
        __IO uint32_t DCKCFGR2;
    } RCC_TypeDef;

    typedef struct
    {
        __IO uint32_t TR;
        __IO uint32_t DR;
        __IO uint32_t CR;
        __IO uint32_t ISR;
        __IO uint32_t PRER;
        __IO uint32_t WUTR;
        __IO uint32_t CALIBR;
        __IO uint32_t ALRMAR;
        __IO uint32_t ALRMBR;
        __IO uint32_t WPR;
        __IO uint32_t SSR;
        __IO uint32_t SHIFTR;
        __IO uint32_t TSTR;
        __IO uint32_t TSDR;
        __IO uint32_t TSSSR;
        __IO uint32_t CALR;
        __IO uint32_t TAFCR;
        __IO uint32_t ALRMASSR;
        __IO uint32_t ALRMBSSR;
        uint32_t RESERVED7;
        __IO uint32_t BKP0R;
        __IO uint32_t BKP1R;
        __IO uint32_t BKP2R;
        __IO uint32_t BKP3R;
        __IO uint32_t BKP4R;
        __IO uint32_t BKP5R;
        __IO uint32_t BKP6R;
        __IO uint32_t BKP7R;
        __IO uint32_t BKP8R;
        __IO uint32_t BKP9R;
        __IO uint32_t BKP10R;
        __IO uint32_t BKP11R;
        __IO uint32_t BKP12R;
        __IO uint32_t BKP13R;
        __IO uint32_t BKP14R;
        __IO uint32_t BKP15R;
        __IO uint32_t BKP16R;
        __IO uint32_t BKP17R;
        __IO uint32_t BKP18R;
        __IO uint32_t BKP19R;
    } RTC_TypeDef;

    typedef struct
    {
        __IO uint32_t GCR;
    } SAI_TypeDef;

    typedef struct
    {
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t FRCR;
        __IO uint32_t SLOTR;
        __IO uint32_t IMR;
        __IO uint32_t SR;
        __IO uint32_t CLRFR;
        __IO uint32_t DR;
    } SAI_Block_TypeDef;

    typedef struct
    {
        __IO uint32_t POWER;
        __IO uint32_t CLKCR;
        __IO uint32_t ARG;
        __IO uint32_t CMD;
        __I uint32_t RESPCMD;
        __I uint32_t RESP1;
        __I uint32_t RESP2;
        __I uint32_t RESP3;
        __I uint32_t RESP4;
        __IO uint32_t DTIMER;
        __IO uint32_t DLEN;
        __IO uint32_t DCTRL;
        __I uint32_t DCOUNT;
        __I uint32_t STA;
        __IO uint32_t ICR;
        __IO uint32_t MASK;
        uint32_t RESERVED0[2];
        __I uint32_t FIFOCNT;
        uint32_t RESERVED1[13];
        __IO uint32_t FIFO;
    } SDIO_TypeDef;

    typedef struct
    {
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t SR;
        __IO uint32_t DR;
        __IO uint32_t CRCPR;
        __IO uint32_t RXCRCR;
        __IO uint32_t TXCRCR;
        __IO uint32_t I2SCFGR;
        __IO uint32_t I2SPR;
    } SPI_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t DCR;
        __IO uint32_t SR;
        __IO uint32_t FCR;
        __IO uint32_t DLR;
        __IO uint32_t CCR;
        __IO uint32_t AR;
        __IO uint32_t ABR;
        __IO uint32_t DR;
        __IO uint32_t PSMKR;
        __IO uint32_t PSMAR;
        __IO uint32_t PIR;
        __IO uint32_t LPTR;
    } QUADSPI_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint16_t IMR;
        uint16_t RESERVED0;
        __IO uint32_t SR;
        __IO uint16_t IFCR;
        uint16_t RESERVED1;
        __IO uint32_t DR;
        __IO uint32_t CSR;
        __IO uint32_t DIR;
        uint16_t RESERVED2;
    } SPDIFRX_TypeDef;

    typedef struct
    {
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t SMCR;
        __IO uint32_t DIER;
        __IO uint32_t SR;
        __IO uint32_t EGR;
        __IO uint32_t CCMR1;
        __IO uint32_t CCMR2;
        __IO uint32_t CCER;
        __IO uint32_t CNT;
        __IO uint32_t PSC;
        __IO uint32_t ARR;
        __IO uint32_t RCR;
        __IO uint32_t CCR1;
        __IO uint32_t CCR2;
        __IO uint32_t CCR3;
        __IO uint32_t CCR4;
        __IO uint32_t BDTR;
        __IO uint32_t DCR;
        __IO uint32_t DMAR;
        __IO uint32_t OR;
    } TIM_TypeDef;

    typedef struct
    {
        __IO uint32_t SR;
        __IO uint32_t DR;
        __IO uint32_t BRR;
        __IO uint32_t CR1;
        __IO uint32_t CR2;
        __IO uint32_t CR3;
        __IO uint32_t GTPR;
    } USART_TypeDef;

    typedef struct
    {
        __IO uint32_t CR;
        __IO uint32_t CFR;
        __IO uint32_t SR;
    } WWDG_TypeDef;

    typedef struct
    {
        __IO uint32_t GOTGCTL;
        __IO uint32_t GOTGINT;
        __IO uint32_t GAHBCFG;
        __IO uint32_t GUSBCFG;
        __IO uint32_t GRSTCTL;
        __IO uint32_t GINTSTS;
        __IO uint32_t GINTMSK;
        __IO uint32_t GRXSTSR;
        __IO uint32_t GRXSTSP;
        __IO uint32_t GRXFSIZ;
        __IO uint32_t DIEPTXF0_HNPTXFSIZ;
        __IO uint32_t HNPTXSTS;
        uint32_t Reserved30[2];
        __IO uint32_t GCCFG;
        __IO uint32_t CID;
        uint32_t Reserved5[3];
        __IO uint32_t GHWCFG3;
        uint32_t Reserved6;
        __IO uint32_t GLPMCFG;
        uint32_t Reserved;
        __IO uint32_t GDFIFOCFG;
        uint32_t Reserved43[40];
        __IO uint32_t HPTXFSIZ;
        __IO uint32_t DIEPTXF[0x0F];
    } USB_OTG_GlobalTypeDef;

    typedef struct
    {
        __IO uint32_t DCFG;
        __IO uint32_t DCTL;
        __IO uint32_t DSTS;
        uint32_t Reserved0C;
        __IO uint32_t DIEPMSK;
        __IO uint32_t DOEPMSK;
        __IO uint32_t DAINT;
        __IO uint32_t DAINTMSK;
        uint32_t Reserved20;
        uint32_t Reserved9;
        __IO uint32_t DVBUSDIS;
        __IO uint32_t DVBUSPULSE;
        __IO uint32_t DTHRCTL;
        __IO uint32_t DIEPEMPMSK;
        __IO uint32_t DEACHINT;
        __IO uint32_t DEACHMSK;
        uint32_t Reserved40;
        __IO uint32_t DINEP1MSK;
        uint32_t Reserved44[15];
        __IO uint32_t DOUTEP1MSK;
    } USB_OTG_DeviceTypeDef;

    typedef struct
    {
        __IO uint32_t DIEPCTL;
        uint32_t Reserved04;
        __IO uint32_t DIEPINT;
        uint32_t Reserved0C;
        __IO uint32_t DIEPTSIZ;
        __IO uint32_t DIEPDMA;
        __IO uint32_t DTXFSTS;
        uint32_t Reserved18;
    } USB_OTG_INEndpointTypeDef;

    typedef struct
    {
        __IO uint32_t DOEPCTL;
        uint32_t Reserved04;
        __IO uint32_t DOEPINT;
        uint32_t Reserved0C;
        __IO uint32_t DOEPTSIZ;
        __IO uint32_t DOEPDMA;
        uint32_t Reserved18[2];
    } USB_OTG_OUTEndpointTypeDef;

    typedef struct
    {
        __IO uint32_t HCFG;
        __IO uint32_t HFIR;
        __IO uint32_t HFNUM;
        uint32_t Reserved40C;
        __IO uint32_t HPTXSTS;
        __IO uint32_t HAINT;
        __IO uint32_t HAINTMSK;
    } USB_OTG_HostTypeDef;

    typedef struct
    {
        __IO uint32_t HCCHAR;
        __IO uint32_t HCSPLT;
        __IO uint32_t HCINT;
        __IO uint32_t HCINTMSK;
        __IO uint32_t HCTSIZ;
        __IO uint32_t HCDMA;
        uint32_t Reserved[2];
    } USB_OTG_HostChannelTypeDef;

#define FLASH_BASE      0x08000000U
#define SRAM1_BASE      0x20000000U
#define SRAM2_BASE      0x2001C000U
#define PERIPH_BASE     0x40000000U
#define BKPSRAM_BASE    0x40024000U
#define FMC_R_BASE      0xA0000000U
#define QSPI_R_BASE     0xA0001000U
#define SRAM1_BB_BASE   0x22000000U
#define SRAM2_BB_BASE   0x22380000U
#define PERIPH_BB_BASE  0x42000000U
#define BKPSRAM_BB_BASE 0x42480000U
#define FLASH_END       0x0807FFFFU
/* Legacy defines */
#define SRAM_BASE    SRAM1_BASE
#define SRAM_BB_BASE SRAM1_BB_BASE

#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000U)
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000U)
#define AHB2PERIPH_BASE (PERIPH_BASE + 0x10000000U)

#define TIM2_BASE    (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASE    (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASE    (APB1PERIPH_BASE + 0x0800U)
#define TIM5_BASE    (APB1PERIPH_BASE + 0x0C00U)
#define TIM6_BASE    (APB1PERIPH_BASE + 0x1000U)
#define TIM7_BASE    (APB1PERIPH_BASE + 0x1400U)
#define TIM12_BASE   (APB1PERIPH_BASE + 0x1800U)
#define TIM13_BASE   (APB1PERIPH_BASE + 0x1C00U)
#define TIM14_BASE   (APB1PERIPH_BASE + 0x2000U)
#define RTC_BASE     (APB1PERIPH_BASE + 0x2800U)
#define WWDG_BASE    (APB1PERIPH_BASE + 0x2C00U)
#define IWDG_BASE    (APB1PERIPH_BASE + 0x3000U)
#define SPI2_BASE    (APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASE    (APB1PERIPH_BASE + 0x3C00U)
#define SPDIFRX_BASE (APB1PERIPH_BASE + 0x4000U)
#define USART2_BASE  (APB1PERIPH_BASE + 0x4400U)
#define USART3_BASE  (APB1PERIPH_BASE + 0x4800U)
#define UART4_BASE   (APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASE   (APB1PERIPH_BASE + 0x5000U)
#define I2C1_BASE    (APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASE    (APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASE    (APB1PERIPH_BASE + 0x5C00U)
#define FMPI2C1_BASE (APB1PERIPH_BASE + 0x6000U)
#define CAN1_BASE    (APB1PERIPH_BASE + 0x6400U)
#define CAN2_BASE    (APB1PERIPH_BASE + 0x6800U)
#define CEC_BASE     (APB1PERIPH_BASE + 0x6C00U)
#define PWR_BASE     (APB1PERIPH_BASE + 0x7000U)
#define DAC_BASE     (APB1PERIPH_BASE + 0x7400U)

#define TIM1_BASE         (APB2PERIPH_BASE + 0x0000U)
#define TIM8_BASE         (APB2PERIPH_BASE + 0x0400U)
#define USART1_BASE       (APB2PERIPH_BASE + 0x1000U)
#define USART6_BASE       (APB2PERIPH_BASE + 0x1400U)
#define ADC1_BASE         (APB2PERIPH_BASE + 0x2000U)
#define ADC2_BASE         (APB2PERIPH_BASE + 0x2100U)
#define ADC3_BASE         (APB2PERIPH_BASE + 0x2200U)
#define ADC_BASE          (APB2PERIPH_BASE + 0x2300U)
#define SDIO_BASE         (APB2PERIPH_BASE + 0x2C00U)
#define SPI1_BASE         (APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASE         (APB2PERIPH_BASE + 0x3400U)
#define SYSCFG_BASE       (APB2PERIPH_BASE + 0x3800U)
#define EXTI_BASE         (APB2PERIPH_BASE + 0x3C00U)
#define TIM9_BASE         (APB2PERIPH_BASE + 0x4000U)
#define TIM10_BASE        (APB2PERIPH_BASE + 0x4400U)
#define TIM11_BASE        (APB2PERIPH_BASE + 0x4800U)
#define SAI1_BASE         (APB2PERIPH_BASE + 0x5800U)
#define SAI1_Block_A_BASE (SAI1_BASE + 0x004U)
#define SAI1_Block_B_BASE (SAI1_BASE + 0x024U)
#define SAI2_BASE         (APB2PERIPH_BASE + 0x5C00U)
#define SAI2_Block_A_BASE (SAI2_BASE + 0x004U)
#define SAI2_Block_B_BASE (SAI2_BASE + 0x024U)

#define GPIOA_BASE        (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE        (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE        (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE        (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE        (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE        (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE        (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE        (AHB1PERIPH_BASE + 0x1C00U)
#define CRC_BASE          (AHB1PERIPH_BASE + 0x3000U)
#define RCC_BASE          (AHB1PERIPH_BASE + 0x3800U)
#define FLASH_R_BASE      (AHB1PERIPH_BASE + 0x3C00U)
#define DMA1_BASE         (AHB1PERIPH_BASE + 0x6000U)
#define DMA1_Stream0_BASE (DMA1_BASE + 0x010U)
#define DMA1_Stream1_BASE (DMA1_BASE + 0x028U)
#define DMA1_Stream2_BASE (DMA1_BASE + 0x040U)
#define DMA1_Stream3_BASE (DMA1_BASE + 0x058U)
#define DMA1_Stream4_BASE (DMA1_BASE + 0x070U)
#define DMA1_Stream5_BASE (DMA1_BASE + 0x088U)
#define DMA1_Stream6_BASE (DMA1_BASE + 0x0A0U)
#define DMA1_Stream7_BASE (DMA1_BASE + 0x0B8U)
#define DMA2_BASE         (AHB1PERIPH_BASE + 0x6400U)
#define DMA2_Stream0_BASE (DMA2_BASE + 0x010U)
#define DMA2_Stream1_BASE (DMA2_BASE + 0x028U)
#define DMA2_Stream2_BASE (DMA2_BASE + 0x040U)
#define DMA2_Stream3_BASE (DMA2_BASE + 0x058U)
#define DMA2_Stream4_BASE (DMA2_BASE + 0x070U)
#define DMA2_Stream5_BASE (DMA2_BASE + 0x088U)
#define DMA2_Stream6_BASE (DMA2_BASE + 0x0A0U)
#define DMA2_Stream7_BASE (DMA2_BASE + 0x0B8U)

#define DCMI_BASE (AHB2PERIPH_BASE + 0x50000U)

#define FMC_Bank1_R_BASE   (FMC_R_BASE + 0x0000U)
#define FMC_Bank1E_R_BASE  (FMC_R_BASE + 0x0104U)
#define FMC_Bank3_R_BASE   (FMC_R_BASE + 0x0080U)
#define FMC_Bank5_6_R_BASE (FMC_R_BASE + 0x0140U)

#define DBGMCU_BASE 0xE0042000U

#define USB_OTG_HS_PERIPH_BASE 0x40040000U
#define USB_OTG_FS_PERIPH_BASE 0x50000000U

#define USB_OTG_GLOBAL_BASE       0x000U
#define USB_OTG_DEVICE_BASE       0x800U
#define USB_OTG_IN_ENDPOINT_BASE  0x900U
#define USB_OTG_OUT_ENDPOINT_BASE 0xB00U
#define USB_OTG_EP_REG_SIZE       0x20U
#define USB_OTG_HOST_BASE         0x400U
#define USB_OTG_HOST_PORT_BASE    0x440U
#define USB_OTG_HOST_CHANNEL_BASE 0x500U
#define USB_OTG_HOST_CHANNEL_SIZE 0x20U
#define USB_OTG_PCGCCTL_BASE      0xE00U
#define USB_OTG_FIFO_BASE         0x1000U
#define USB_OTG_FIFO_SIZE         0x1000U

#define TIM2         ((TIM_TypeDef *)TIM2_BASE)
#define TIM3         ((TIM_TypeDef *)TIM3_BASE)
#define TIM4         ((TIM_TypeDef *)TIM4_BASE)
#define TIM5         ((TIM_TypeDef *)TIM5_BASE)
#define TIM6         ((TIM_TypeDef *)TIM6_BASE)
#define TIM7         ((TIM_TypeDef *)TIM7_BASE)
#define TIM12        ((TIM_TypeDef *)TIM12_BASE)
#define TIM13        ((TIM_TypeDef *)TIM13_BASE)
#define TIM14        ((TIM_TypeDef *)TIM14_BASE)
#define RTC          ((RTC_TypeDef *)RTC_BASE)
#define WWDG         ((WWDG_TypeDef *)WWDG_BASE)
#define IWDG         ((IWDG_TypeDef *)IWDG_BASE)
#define SPI2         ((SPI_TypeDef *)SPI2_BASE)
#define SPI3         ((SPI_TypeDef *)SPI3_BASE)
#define SPDIFRX      ((SPDIFRX_TypeDef *)SPDIFRX_BASE)
#define USART2       ((USART_TypeDef *)USART2_BASE)
#define USART3       ((USART_TypeDef *)USART3_BASE)
#define UART4        ((USART_TypeDef *)UART4_BASE)
#define UART5        ((USART_TypeDef *)UART5_BASE)
#define I2C1         ((I2C_TypeDef *)I2C1_BASE)
#define I2C2         ((I2C_TypeDef *)I2C2_BASE)
#define I2C3         ((I2C_TypeDef *)I2C3_BASE)
#define FMPI2C1      ((FMPI2C_TypeDef *)FMPI2C1_BASE)
#define CAN1         ((CAN_TypeDef *)CAN1_BASE)
#define CAN2         ((CAN_TypeDef *)CAN2_BASE)
#define CEC          ((CEC_TypeDef *)CEC_BASE)
#define PWR          ((PWR_TypeDef *)PWR_BASE)
#define DAC          ((DAC_TypeDef *)DAC_BASE)
#define TIM1         ((TIM_TypeDef *)TIM1_BASE)
#define TIM8         ((TIM_TypeDef *)TIM8_BASE)
#define USART1       ((USART_TypeDef *)USART1_BASE)
#define USART6       ((USART_TypeDef *)USART6_BASE)
#define ADC          ((ADC_Common_TypeDef *)ADC_BASE)
#define ADC1         ((ADC_TypeDef *)ADC1_BASE)
#define ADC2         ((ADC_TypeDef *)ADC2_BASE)
#define ADC3         ((ADC_TypeDef *)ADC3_BASE)
#define SDIO         ((SDIO_TypeDef *)SDIO_BASE)
#define SPI1         ((SPI_TypeDef *)SPI1_BASE)
#define SPI4         ((SPI_TypeDef *)SPI4_BASE)
#define SYSCFG       ((SYSCFG_TypeDef *)SYSCFG_BASE)
#define EXTI         ((EXTI_TypeDef *)EXTI_BASE)
#define TIM9         ((TIM_TypeDef *)TIM9_BASE)
#define TIM10        ((TIM_TypeDef *)TIM10_BASE)
#define TIM11        ((TIM_TypeDef *)TIM11_BASE)
#define SAI1         ((SAI_TypeDef *)SAI1_BASE)
#define SAI1_Block_A ((SAI_Block_TypeDef *)SAI1_Block_A_BASE)
#define SAI1_Block_B ((SAI_Block_TypeDef *)SAI1_Block_B_BASE)
#define SAI2         ((SAI_TypeDef *)SAI2_BASE)
#define SAI2_Block_A ((SAI_Block_TypeDef *)SAI2_Block_A_BASE)
#define SAI2_Block_B ((SAI_Block_TypeDef *)SAI2_Block_B_BASE)

#define GPIOA        ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB        ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC        ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD        ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE        ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF        ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG        ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH        ((GPIO_TypeDef *)GPIOH_BASE)
#define CRC          ((CRC_TypeDef *)CRC_BASE)
#define RCC          ((RCC_TypeDef *)RCC_BASE)
#define FLASH        ((FLASH_TypeDef *)FLASH_R_BASE)
#define DMA1         ((DMA_TypeDef *)DMA1_BASE)
#define DMA1_Stream0 ((DMA_Stream_TypeDef *)DMA1_Stream0_BASE)
#define DMA1_Stream1 ((DMA_Stream_TypeDef *)DMA1_Stream1_BASE)
#define DMA1_Stream2 ((DMA_Stream_TypeDef *)DMA1_Stream2_BASE)
#define DMA1_Stream3 ((DMA_Stream_TypeDef *)DMA1_Stream3_BASE)
#define DMA1_Stream4 ((DMA_Stream_TypeDef *)DMA1_Stream4_BASE)
#define DMA1_Stream5 ((DMA_Stream_TypeDef *)DMA1_Stream5_BASE)
#define DMA1_Stream6 ((DMA_Stream_TypeDef *)DMA1_Stream6_BASE)
#define DMA1_Stream7 ((DMA_Stream_TypeDef *)DMA1_Stream7_BASE)
#define DMA2         ((DMA_TypeDef *)DMA2_BASE)
#define DMA2_Stream0 ((DMA_Stream_TypeDef *)DMA2_Stream0_BASE)
#define DMA2_Stream1 ((DMA_Stream_TypeDef *)DMA2_Stream1_BASE)
#define DMA2_Stream2 ((DMA_Stream_TypeDef *)DMA2_Stream2_BASE)
#define DMA2_Stream3 ((DMA_Stream_TypeDef *)DMA2_Stream3_BASE)
#define DMA2_Stream4 ((DMA_Stream_TypeDef *)DMA2_Stream4_BASE)
#define DMA2_Stream5 ((DMA_Stream_TypeDef *)DMA2_Stream5_BASE)
#define DMA2_Stream6 ((DMA_Stream_TypeDef *)DMA2_Stream6_BASE)
#define DMA2_Stream7 ((DMA_Stream_TypeDef *)DMA2_Stream7_BASE)
#define DCMI         ((DCMI_TypeDef *)DCMI_BASE)
#define FMC_Bank1    ((FMC_Bank1_TypeDef *)FMC_Bank1_R_BASE)
#define FMC_Bank1E   ((FMC_Bank1E_TypeDef *)FMC_Bank1E_R_BASE)
#define FMC_Bank3    ((FMC_Bank3_TypeDef *)FMC_Bank3_R_BASE)
#define FMC_Bank5_6  ((FMC_Bank5_6_TypeDef *)FMC_Bank5_6_R_BASE)
#define QUADSPI      ((QUADSPI_TypeDef *)QSPI_R_BASE)

#define DBGMCU ((DBGMCU_TypeDef *)DBGMCU_BASE)

#define USB_OTG_FS ((USB_OTG_GlobalTypeDef *)USB_OTG_FS_PERIPH_BASE)
#define USB_OTG_HS ((USB_OTG_GlobalTypeDef *)USB_OTG_HS_PERIPH_BASE)

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD   0x00000001U
#define ADC_SR_EOC   0x00000002U
#define ADC_SR_JEOC  0x00000004U
#define ADC_SR_JSTRT 0x00000008U
#define ADC_SR_STRT  0x00000010U
#define ADC_SR_OVR   0x00000020U
/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH     0x0000001FU
#define ADC_CR1_AWDCH_0   0x00000001U
#define ADC_CR1_AWDCH_1   0x00000002U
#define ADC_CR1_AWDCH_2   0x00000004U
#define ADC_CR1_AWDCH_3   0x00000008U
#define ADC_CR1_AWDCH_4   0x00000010U
#define ADC_CR1_EOCIE     0x00000020U
#define ADC_CR1_AWDIE     0x00000040U
#define ADC_CR1_JEOCIE    0x00000080U
#define ADC_CR1_SCAN      0x00000100U
#define ADC_CR1_AWDSGL    0x00000200U
#define ADC_CR1_JAUTO     0x00000400U
#define ADC_CR1_DISCEN    0x00000800U
#define ADC_CR1_JDISCEN   0x00001000U
#define ADC_CR1_DISCNUM   0x0000E000U
#define ADC_CR1_DISCNUM_0 0x00002000U
#define ADC_CR1_DISCNUM_1 0x00004000U
#define ADC_CR1_DISCNUM_2 0x00008000U
#define ADC_CR1_JAWDEN    0x00400000U
#define ADC_CR1_AWDEN     0x00800000U
#define ADC_CR1_RES       0x03000000U
#define ADC_CR1_RES_0     0x01000000U
#define ADC_CR1_RES_1     0x02000000U
#define ADC_CR1_OVRIE     0x04000000U
/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON      0x00000001U
#define ADC_CR2_CONT      0x00000002U
#define ADC_CR2_DMA       0x00000100U
#define ADC_CR2_DDS       0x00000200U
#define ADC_CR2_EOCS      0x00000400U
#define ADC_CR2_ALIGN     0x00000800U
#define ADC_CR2_JEXTSEL   0x000F0000U
#define ADC_CR2_JEXTSEL_0 0x00010000U
#define ADC_CR2_JEXTSEL_1 0x00020000U
#define ADC_CR2_JEXTSEL_2 0x00040000U
#define ADC_CR2_JEXTSEL_3 0x00080000U
#define ADC_CR2_JEXTEN    0x00300000U
#define ADC_CR2_JEXTEN_0  0x00100000U
#define ADC_CR2_JEXTEN_1  0x00200000U
#define ADC_CR2_JSWSTART  0x00400000U
#define ADC_CR2_EXTSEL    0x0F000000U
#define ADC_CR2_EXTSEL_0  0x01000000U
#define ADC_CR2_EXTSEL_1  0x02000000U
#define ADC_CR2_EXTSEL_2  0x04000000U
#define ADC_CR2_EXTSEL_3  0x08000000U
#define ADC_CR2_EXTEN     0x30000000U
#define ADC_CR2_EXTEN_0   0x10000000U
#define ADC_CR2_EXTEN_1   0x20000000U
#define ADC_CR2_SWSTART   0x40000000U
/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP10   0x00000007U
#define ADC_SMPR1_SMP10_0 0x00000001U
#define ADC_SMPR1_SMP10_1 0x00000002U
#define ADC_SMPR1_SMP10_2 0x00000004U
#define ADC_SMPR1_SMP11   0x00000038U
#define ADC_SMPR1_SMP11_0 0x00000008U
#define ADC_SMPR1_SMP11_1 0x00000010U
#define ADC_SMPR1_SMP11_2 0x00000020U
#define ADC_SMPR1_SMP12   0x000001C0U
#define ADC_SMPR1_SMP12_0 0x00000040U
#define ADC_SMPR1_SMP12_1 0x00000080U
#define ADC_SMPR1_SMP12_2 0x00000100U
#define ADC_SMPR1_SMP13   0x00000E00U
#define ADC_SMPR1_SMP13_0 0x00000200U
#define ADC_SMPR1_SMP13_1 0x00000400U
#define ADC_SMPR1_SMP13_2 0x00000800U
#define ADC_SMPR1_SMP14   0x00007000U
#define ADC_SMPR1_SMP14_0 0x00001000U
#define ADC_SMPR1_SMP14_1 0x00002000U
#define ADC_SMPR1_SMP14_2 0x00004000U
#define ADC_SMPR1_SMP15   0x00038000U
#define ADC_SMPR1_SMP15_0 0x00008000U
#define ADC_SMPR1_SMP15_1 0x00010000U
#define ADC_SMPR1_SMP15_2 0x00020000U
#define ADC_SMPR1_SMP16   0x001C0000U
#define ADC_SMPR1_SMP16_0 0x00040000U
#define ADC_SMPR1_SMP16_1 0x00080000U
#define ADC_SMPR1_SMP16_2 0x00100000U
#define ADC_SMPR1_SMP17   0x00E00000U
#define ADC_SMPR1_SMP17_0 0x00200000U
#define ADC_SMPR1_SMP17_1 0x00400000U
#define ADC_SMPR1_SMP17_2 0x00800000U
#define ADC_SMPR1_SMP18   0x07000000U
#define ADC_SMPR1_SMP18_0 0x01000000U
#define ADC_SMPR1_SMP18_1 0x02000000U
#define ADC_SMPR1_SMP18_2 0x04000000U
/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP0   0x00000007U
#define ADC_SMPR2_SMP0_0 0x00000001U
#define ADC_SMPR2_SMP0_1 0x00000002U
#define ADC_SMPR2_SMP0_2 0x00000004U
#define ADC_SMPR2_SMP1   0x00000038U
#define ADC_SMPR2_SMP1_0 0x00000008U
#define ADC_SMPR2_SMP1_1 0x00000010U
#define ADC_SMPR2_SMP1_2 0x00000020U
#define ADC_SMPR2_SMP2   0x000001C0U
#define ADC_SMPR2_SMP2_0 0x00000040U
#define ADC_SMPR2_SMP2_1 0x00000080U
#define ADC_SMPR2_SMP2_2 0x00000100U
#define ADC_SMPR2_SMP3   0x00000E00U
#define ADC_SMPR2_SMP3_0 0x00000200U
#define ADC_SMPR2_SMP3_1 0x00000400U
#define ADC_SMPR2_SMP3_2 0x00000800U
#define ADC_SMPR2_SMP4   0x00007000U
#define ADC_SMPR2_SMP4_0 0x00001000U
#define ADC_SMPR2_SMP4_1 0x00002000U
#define ADC_SMPR2_SMP4_2 0x00004000U
#define ADC_SMPR2_SMP5   0x00038000U
#define ADC_SMPR2_SMP5_0 0x00008000U
#define ADC_SMPR2_SMP5_1 0x00010000U
#define ADC_SMPR2_SMP5_2 0x00020000U
#define ADC_SMPR2_SMP6   0x001C0000U
#define ADC_SMPR2_SMP6_0 0x00040000U
#define ADC_SMPR2_SMP6_1 0x00080000U
#define ADC_SMPR2_SMP6_2 0x00100000U
#define ADC_SMPR2_SMP7   0x00E00000U
#define ADC_SMPR2_SMP7_0 0x00200000U
#define ADC_SMPR2_SMP7_1 0x00400000U
#define ADC_SMPR2_SMP7_2 0x00800000U
#define ADC_SMPR2_SMP8   0x07000000U
#define ADC_SMPR2_SMP8_0 0x01000000U
#define ADC_SMPR2_SMP8_1 0x02000000U
#define ADC_SMPR2_SMP8_2 0x04000000U
#define ADC_SMPR2_SMP9   0x38000000U
#define ADC_SMPR2_SMP9_0 0x08000000U
#define ADC_SMPR2_SMP9_1 0x10000000U
#define ADC_SMPR2_SMP9_2 0x20000000U
/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1 0x0FFFU
/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2 0x0FFFU
/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3 0x0FFFU
/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4 0x0FFFU
/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT 0x0FFFU
/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT 0x0FFFU
/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13   0x0000001FU
#define ADC_SQR1_SQ13_0 0x00000001U
#define ADC_SQR1_SQ13_1 0x00000002U
#define ADC_SQR1_SQ13_2 0x00000004U
#define ADC_SQR1_SQ13_3 0x00000008U
#define ADC_SQR1_SQ13_4 0x00000010U
#define ADC_SQR1_SQ14   0x000003E0U
#define ADC_SQR1_SQ14_0 0x00000020U
#define ADC_SQR1_SQ14_1 0x00000040U
#define ADC_SQR1_SQ14_2 0x00000080U
#define ADC_SQR1_SQ14_3 0x00000100U
#define ADC_SQR1_SQ14_4 0x00000200U
#define ADC_SQR1_SQ15   0x00007C00U
#define ADC_SQR1_SQ15_0 0x00000400U
#define ADC_SQR1_SQ15_1 0x00000800U
#define ADC_SQR1_SQ15_2 0x00001000U
#define ADC_SQR1_SQ15_3 0x00002000U
#define ADC_SQR1_SQ15_4 0x00004000U
#define ADC_SQR1_SQ16   0x000F8000U
#define ADC_SQR1_SQ16_0 0x00008000U
#define ADC_SQR1_SQ16_1 0x00010000U
#define ADC_SQR1_SQ16_2 0x00020000U
#define ADC_SQR1_SQ16_3 0x00040000U
#define ADC_SQR1_SQ16_4 0x00080000U
#define ADC_SQR1_L      0x00F00000U
#define ADC_SQR1_L_0    0x00100000U
#define ADC_SQR1_L_1    0x00200000U
#define ADC_SQR1_L_2    0x00400000U
#define ADC_SQR1_L_3    0x00800000U
/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ7    0x0000001FU
#define ADC_SQR2_SQ7_0  0x00000001U
#define ADC_SQR2_SQ7_1  0x00000002U
#define ADC_SQR2_SQ7_2  0x00000004U
#define ADC_SQR2_SQ7_3  0x00000008U
#define ADC_SQR2_SQ7_4  0x00000010U
#define ADC_SQR2_SQ8    0x000003E0U
#define ADC_SQR2_SQ8_0  0x00000020U
#define ADC_SQR2_SQ8_1  0x00000040U
#define ADC_SQR2_SQ8_2  0x00000080U
#define ADC_SQR2_SQ8_3  0x00000100U
#define ADC_SQR2_SQ8_4  0x00000200U
#define ADC_SQR2_SQ9    0x00007C00U
#define ADC_SQR2_SQ9_0  0x00000400U
#define ADC_SQR2_SQ9_1  0x00000800U
#define ADC_SQR2_SQ9_2  0x00001000U
#define ADC_SQR2_SQ9_3  0x00002000U
#define ADC_SQR2_SQ9_4  0x00004000U
#define ADC_SQR2_SQ10   0x000F8000U
#define ADC_SQR2_SQ10_0 0x00008000U
#define ADC_SQR2_SQ10_1 0x00010000U
#define ADC_SQR2_SQ10_2 0x00020000U
#define ADC_SQR2_SQ10_3 0x00040000U
#define ADC_SQR2_SQ10_4 0x00080000U
#define ADC_SQR2_SQ11   0x01F00000U
#define ADC_SQR2_SQ11_0 0x00100000U
#define ADC_SQR2_SQ11_1 0x00200000U
#define ADC_SQR2_SQ11_2 0x00400000U
#define ADC_SQR2_SQ11_3 0x00800000U
#define ADC_SQR2_SQ11_4 0x01000000U
#define ADC_SQR2_SQ12   0x3E000000U
#define ADC_SQR2_SQ12_0 0x02000000U
#define ADC_SQR2_SQ12_1 0x04000000U
#define ADC_SQR2_SQ12_2 0x08000000U
#define ADC_SQR2_SQ12_3 0x10000000U
#define ADC_SQR2_SQ12_4 0x20000000U
/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1   0x0000001FU
#define ADC_SQR3_SQ1_0 0x00000001U
#define ADC_SQR3_SQ1_1 0x00000002U
#define ADC_SQR3_SQ1_2 0x00000004U
#define ADC_SQR3_SQ1_3 0x00000008U
#define ADC_SQR3_SQ1_4 0x00000010U
#define ADC_SQR3_SQ2   0x000003E0U
#define ADC_SQR3_SQ2_0 0x00000020U
#define ADC_SQR3_SQ2_1 0x00000040U
#define ADC_SQR3_SQ2_2 0x00000080U
#define ADC_SQR3_SQ2_3 0x00000100U
#define ADC_SQR3_SQ2_4 0x00000200U
#define ADC_SQR3_SQ3   0x00007C00U
#define ADC_SQR3_SQ3_0 0x00000400U
#define ADC_SQR3_SQ3_1 0x00000800U
#define ADC_SQR3_SQ3_2 0x00001000U
#define ADC_SQR3_SQ3_3 0x00002000U
#define ADC_SQR3_SQ3_4 0x00004000U
#define ADC_SQR3_SQ4   0x000F8000U
#define ADC_SQR3_SQ4_0 0x00008000U
#define ADC_SQR3_SQ4_1 0x00010000U
#define ADC_SQR3_SQ4_2 0x00020000U
#define ADC_SQR3_SQ4_3 0x00040000U
#define ADC_SQR3_SQ4_4 0x00080000U
#define ADC_SQR3_SQ5   0x01F00000U
#define ADC_SQR3_SQ5_0 0x00100000U
#define ADC_SQR3_SQ5_1 0x00200000U
#define ADC_SQR3_SQ5_2 0x00400000U
#define ADC_SQR3_SQ5_3 0x00800000U
#define ADC_SQR3_SQ5_4 0x01000000U
#define ADC_SQR3_SQ6   0x3E000000U
#define ADC_SQR3_SQ6_0 0x02000000U
#define ADC_SQR3_SQ6_1 0x04000000U
#define ADC_SQR3_SQ6_2 0x08000000U
#define ADC_SQR3_SQ6_3 0x10000000U
#define ADC_SQR3_SQ6_4 0x20000000U
/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1   0x0000001FU
#define ADC_JSQR_JSQ1_0 0x00000001U
#define ADC_JSQR_JSQ1_1 0x00000002U
#define ADC_JSQR_JSQ1_2 0x00000004U
#define ADC_JSQR_JSQ1_3 0x00000008U
#define ADC_JSQR_JSQ1_4 0x00000010U
#define ADC_JSQR_JSQ2   0x000003E0U
#define ADC_JSQR_JSQ2_0 0x00000020U
#define ADC_JSQR_JSQ2_1 0x00000040U
#define ADC_JSQR_JSQ2_2 0x00000080U
#define ADC_JSQR_JSQ2_3 0x00000100U
#define ADC_JSQR_JSQ2_4 0x00000200U
#define ADC_JSQR_JSQ3   0x00007C00U
#define ADC_JSQR_JSQ3_0 0x00000400U
#define ADC_JSQR_JSQ3_1 0x00000800U
#define ADC_JSQR_JSQ3_2 0x00001000U
#define ADC_JSQR_JSQ3_3 0x00002000U
#define ADC_JSQR_JSQ3_4 0x00004000U
#define ADC_JSQR_JSQ4   0x000F8000U
#define ADC_JSQR_JSQ4_0 0x00008000U
#define ADC_JSQR_JSQ4_1 0x00010000U
#define ADC_JSQR_JSQ4_2 0x00020000U
#define ADC_JSQR_JSQ4_3 0x00040000U
#define ADC_JSQR_JSQ4_4 0x00080000U
#define ADC_JSQR_JL     0x00300000U
#define ADC_JSQR_JL_0   0x00100000U
#define ADC_JSQR_JL_1   0x00200000U
/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA 0xFFFFU
/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA 0xFFFFU
/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA 0xFFFFU
/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA 0xFFFFU
/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA     0x0000FFFFU
#define ADC_DR_ADC2DATA 0xFFFF0000U
/*******************  Bit definition for ADC_CSR register  ********************/
#define ADC_CSR_AWD1   0x00000001U
#define ADC_CSR_EOC1   0x00000002U
#define ADC_CSR_JEOC1  0x00000004U
#define ADC_CSR_JSTRT1 0x00000008U
#define ADC_CSR_STRT1  0x00000010U
#define ADC_CSR_OVR1   0x00000020U
#define ADC_CSR_AWD2   0x00000100U
#define ADC_CSR_EOC2   0x00000200U
#define ADC_CSR_JEOC2  0x00000400U
#define ADC_CSR_JSTRT2 0x00000800U
#define ADC_CSR_STRT2  0x00001000U
#define ADC_CSR_OVR2   0x00002000U
#define ADC_CSR_AWD3   0x00010000U
#define ADC_CSR_EOC3   0x00020000U
#define ADC_CSR_JEOC3  0x00040000U
#define ADC_CSR_JSTRT3 0x00080000U
#define ADC_CSR_STRT3  0x00100000U
#define ADC_CSR_OVR3   0x00200000U
/* Legacy defines */
#define ADC_CSR_DOVR1 ADC_CSR_OVR1
#define ADC_CSR_DOVR2 ADC_CSR_OVR2
#define ADC_CSR_DOVR3 ADC_CSR_OVR3

/*******************  Bit definition for ADC_CCR register  ********************/
#define ADC_CCR_MULTI    0x0000001FU
#define ADC_CCR_MULTI_0  0x00000001U
#define ADC_CCR_MULTI_1  0x00000002U
#define ADC_CCR_MULTI_2  0x00000004U
#define ADC_CCR_MULTI_3  0x00000008U
#define ADC_CCR_MULTI_4  0x00000010U
#define ADC_CCR_DELAY    0x00000F00U
#define ADC_CCR_DELAY_0  0x00000100U
#define ADC_CCR_DELAY_1  0x00000200U
#define ADC_CCR_DELAY_2  0x00000400U
#define ADC_CCR_DELAY_3  0x00000800U
#define ADC_CCR_DDS      0x00002000U
#define ADC_CCR_DMA      0x0000C000U
#define ADC_CCR_DMA_0    0x00004000U
#define ADC_CCR_DMA_1    0x00008000U
#define ADC_CCR_ADCPRE   0x00030000U
#define ADC_CCR_ADCPRE_0 0x00010000U
#define ADC_CCR_ADCPRE_1 0x00020000U
#define ADC_CCR_VBATE    0x00400000U
#define ADC_CCR_TSVREFE  0x00800000U
/*******************  Bit definition for ADC_CDR register  ********************/
#define ADC_CDR_DATA1 0x0000FFFFU
#define ADC_CDR_DATA2 0xFFFF0000U
/******************************************************************************/
/*                                                                            */
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ  0x00000001U
#define CAN_MCR_SLEEP 0x00000002U
#define CAN_MCR_TXFP  0x00000004U
#define CAN_MCR_RFLM  0x00000008U
#define CAN_MCR_NART  0x00000010U
#define CAN_MCR_AWUM  0x00000020U
#define CAN_MCR_ABOM  0x00000040U
#define CAN_MCR_TTCM  0x00000080U
#define CAN_MCR_RESET 0x00008000U
#define CAN_MCR_DBF   0x00010000U
/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK  0x0001U
#define CAN_MSR_SLAK  0x0002U
#define CAN_MSR_ERRI  0x0004U
#define CAN_MSR_WKUI  0x0008U
#define CAN_MSR_SLAKI 0x0010U
#define CAN_MSR_TXM   0x0100U
#define CAN_MSR_RXM   0x0200U
#define CAN_MSR_SAMP  0x0400U
#define CAN_MSR_RX    0x0800U
/*******************  Bit definition for CAN_TSR register  ********************/
#define CAN_TSR_RQCP0 0x00000001U
#define CAN_TSR_TXOK0 0x00000002U
#define CAN_TSR_ALST0 0x00000004U
#define CAN_TSR_TERR0 0x00000008U
#define CAN_TSR_ABRQ0 0x00000080U
#define CAN_TSR_RQCP1 0x00000100U
#define CAN_TSR_TXOK1 0x00000200U
#define CAN_TSR_ALST1 0x00000400U
#define CAN_TSR_TERR1 0x00000800U
#define CAN_TSR_ABRQ1 0x00008000U
#define CAN_TSR_RQCP2 0x00010000U
#define CAN_TSR_TXOK2 0x00020000U
#define CAN_TSR_ALST2 0x00040000U
#define CAN_TSR_TERR2 0x00080000U
#define CAN_TSR_ABRQ2 0x00800000U
#define CAN_TSR_CODE  0x03000000U
#define CAN_TSR_TME   0x1C000000U
#define CAN_TSR_TME0  0x04000000U
#define CAN_TSR_TME1  0x08000000U
#define CAN_TSR_TME2  0x10000000U
#define CAN_TSR_LOW   0xE0000000U
#define CAN_TSR_LOW0  0x20000000U
#define CAN_TSR_LOW1  0x40000000U
#define CAN_TSR_LOW2  0x80000000U
/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0  0x03U
#define CAN_RF0R_FULL0 0x08U
#define CAN_RF0R_FOVR0 0x10U
#define CAN_RF0R_RFOM0 0x20U
/*******************  Bit definition for CAN_RF1R register  *******************/
#define CAN_RF1R_FMP1  0x03U
#define CAN_RF1R_FULL1 0x08U
#define CAN_RF1R_FOVR1 0x10U
#define CAN_RF1R_RFOM1 0x20U
/********************  Bit definition for CAN_IER register  *******************/
#define CAN_IER_TMEIE  0x00000001U
#define CAN_IER_FMPIE0 0x00000002U
#define CAN_IER_FFIE0  0x00000004U
#define CAN_IER_FOVIE0 0x00000008U
#define CAN_IER_FMPIE1 0x00000010U
#define CAN_IER_FFIE1  0x00000020U
#define CAN_IER_FOVIE1 0x00000040U
#define CAN_IER_EWGIE  0x00000100U
#define CAN_IER_EPVIE  0x00000200U
#define CAN_IER_BOFIE  0x00000400U
#define CAN_IER_LECIE  0x00000800U
#define CAN_IER_ERRIE  0x00008000U
#define CAN_IER_WKUIE  0x00010000U
#define CAN_IER_SLKIE  0x00020000U
#define CAN_IER_EWGIE  0x00000100U
#define CAN_IER_EPVIE  0x00000200U
#define CAN_IER_BOFIE  0x00000400U
#define CAN_IER_LECIE  0x00000800U
#define CAN_IER_ERRIE  0x00008000U
/********************  Bit definition for CAN_ESR register  *******************/
#define CAN_ESR_EWGF  0x00000001U
#define CAN_ESR_EPVF  0x00000002U
#define CAN_ESR_BOFF  0x00000004U
#define CAN_ESR_LEC   0x00000070U
#define CAN_ESR_LEC_0 0x00000010U
#define CAN_ESR_LEC_1 0x00000020U
#define CAN_ESR_LEC_2 0x00000040U
#define CAN_ESR_TEC   0x00FF0000U
#define CAN_ESR_REC   0xFF000000U
/*******************  Bit definition for CAN_BTR register  ********************/
#define CAN_BTR_BRP   0x000003FFU
#define CAN_BTR_TS1   0x000F0000U
#define CAN_BTR_TS1_0 0x00010000U
#define CAN_BTR_TS1_1 0x00020000U
#define CAN_BTR_TS1_2 0x00040000U
#define CAN_BTR_TS1_3 0x00080000U
#define CAN_BTR_TS2   0x00700000U
#define CAN_BTR_TS2_0 0x00100000U
#define CAN_BTR_TS2_1 0x00200000U
#define CAN_BTR_TS2_2 0x00400000U
#define CAN_BTR_SJW   0x03000000U
#define CAN_BTR_SJW_0 0x01000000U
#define CAN_BTR_SJW_1 0x02000000U
#define CAN_BTR_LBKM  0x40000000U
#define CAN_BTR_SILM  0x80000000U
/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ 0x00000001U
#define CAN_TI0R_RTR  0x00000002U
#define CAN_TI0R_IDE  0x00000004U
#define CAN_TI0R_EXID 0x001FFFF8U
#define CAN_TI0R_STID 0xFFE00000U
/******************  Bit definition for CAN_TDT0R register  *******************/
#define CAN_TDT0R_DLC  0x0000000FU
#define CAN_TDT0R_TGT  0x00000100U
#define CAN_TDT0R_TIME 0xFFFF0000U
/******************  Bit definition for CAN_TDL0R register  *******************/
#define CAN_TDL0R_DATA0 0x000000FFU
#define CAN_TDL0R_DATA1 0x0000FF00U
#define CAN_TDL0R_DATA2 0x00FF0000U
#define CAN_TDL0R_DATA3 0xFF000000U
/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4 0x000000FFU
#define CAN_TDH0R_DATA5 0x0000FF00U
#define CAN_TDH0R_DATA6 0x00FF0000U
#define CAN_TDH0R_DATA7 0xFF000000U
/*******************  Bit definition for CAN_TI1R register  *******************/
#define CAN_TI1R_TXRQ 0x00000001U
#define CAN_TI1R_RTR  0x00000002U
#define CAN_TI1R_IDE  0x00000004U
#define CAN_TI1R_EXID 0x001FFFF8U
#define CAN_TI1R_STID 0xFFE00000U
/*******************  Bit definition for CAN_TDT1R register  ******************/
#define CAN_TDT1R_DLC  0x0000000FU
#define CAN_TDT1R_TGT  0x00000100U
#define CAN_TDT1R_TIME 0xFFFF0000U
/*******************  Bit definition for CAN_TDL1R register  ******************/
#define CAN_TDL1R_DATA0 0x000000FFU
#define CAN_TDL1R_DATA1 0x0000FF00U
#define CAN_TDL1R_DATA2 0x00FF0000U
#define CAN_TDL1R_DATA3 0xFF000000U
/*******************  Bit definition for CAN_TDH1R register  ******************/
#define CAN_TDH1R_DATA4 0x000000FFU
#define CAN_TDH1R_DATA5 0x0000FF00U
#define CAN_TDH1R_DATA6 0x00FF0000U
#define CAN_TDH1R_DATA7 0xFF000000U
/*******************  Bit definition for CAN_TI2R register  *******************/
#define CAN_TI2R_TXRQ 0x00000001U
#define CAN_TI2R_RTR  0x00000002U
#define CAN_TI2R_IDE  0x00000004U
#define CAN_TI2R_EXID 0x001FFFF8U
#define CAN_TI2R_STID 0xFFE00000U
/*******************  Bit definition for CAN_TDT2R register  ******************/
#define CAN_TDT2R_DLC  0x0000000FU
#define CAN_TDT2R_TGT  0x00000100U
#define CAN_TDT2R_TIME 0xFFFF0000U
/*******************  Bit definition for CAN_TDL2R register  ******************/
#define CAN_TDL2R_DATA0 0x000000FFU
#define CAN_TDL2R_DATA1 0x0000FF00U
#define CAN_TDL2R_DATA2 0x00FF0000U
#define CAN_TDL2R_DATA3 0xFF000000U
/*******************  Bit definition for CAN_TDH2R register  ******************/
#define CAN_TDH2R_DATA4 0x000000FFU
#define CAN_TDH2R_DATA5 0x0000FF00U
#define CAN_TDH2R_DATA6 0x00FF0000U
#define CAN_TDH2R_DATA7 0xFF000000U
/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR  0x00000002U
#define CAN_RI0R_IDE  0x00000004U
#define CAN_RI0R_EXID 0x001FFFF8U
#define CAN_RI0R_STID 0xFFE00000U
/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC  0x0000000FU
#define CAN_RDT0R_FMI  0x0000FF00U
#define CAN_RDT0R_TIME 0xFFFF0000U
/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0 0x000000FFU
#define CAN_RDL0R_DATA1 0x0000FF00U
#define CAN_RDL0R_DATA2 0x00FF0000U
#define CAN_RDL0R_DATA3 0xFF000000U
/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4 0x000000FFU
#define CAN_RDH0R_DATA5 0x0000FF00U
#define CAN_RDH0R_DATA6 0x00FF0000U
#define CAN_RDH0R_DATA7 0xFF000000U
/*******************  Bit definition for CAN_RI1R register  *******************/
#define CAN_RI1R_RTR  0x00000002U
#define CAN_RI1R_IDE  0x00000004U
#define CAN_RI1R_EXID 0x001FFFF8U
#define CAN_RI1R_STID 0xFFE00000U
/*******************  Bit definition for CAN_RDT1R register  ******************/
#define CAN_RDT1R_DLC  0x0000000FU
#define CAN_RDT1R_FMI  0x0000FF00U
#define CAN_RDT1R_TIME 0xFFFF0000U
/*******************  Bit definition for CAN_RDL1R register  ******************/
#define CAN_RDL1R_DATA0 0x000000FFU
#define CAN_RDL1R_DATA1 0x0000FF00U
#define CAN_RDL1R_DATA2 0x00FF0000U
#define CAN_RDL1R_DATA3 0xFF000000U
/*******************  Bit definition for CAN_RDH1R register  ******************/
#define CAN_RDH1R_DATA4 0x000000FFU
#define CAN_RDH1R_DATA5 0x0000FF00U
#define CAN_RDH1R_DATA6 0x00FF0000U
#define CAN_RDH1R_DATA7 0xFF000000U
/*******************  Bit definition for CAN_FMR register  ********************/
#define CAN_FMR_FINIT  0x01U
#define CAN_FMR_CAN2SB 0x00003F00U
/*******************  Bit definition for CAN_FM1R register  *******************/
#define CAN_FM1R_FBM   0x0FFFFFFFU
#define CAN_FM1R_FBM0  0x00000001U
#define CAN_FM1R_FBM1  0x00000002U
#define CAN_FM1R_FBM2  0x00000004U
#define CAN_FM1R_FBM3  0x00000008U
#define CAN_FM1R_FBM4  0x00000010U
#define CAN_FM1R_FBM5  0x00000020U
#define CAN_FM1R_FBM6  0x00000040U
#define CAN_FM1R_FBM7  0x00000080U
#define CAN_FM1R_FBM8  0x00000100U
#define CAN_FM1R_FBM9  0x00000200U
#define CAN_FM1R_FBM10 0x00000400U
#define CAN_FM1R_FBM11 0x00000800U
#define CAN_FM1R_FBM12 0x00001000U
#define CAN_FM1R_FBM13 0x00002000U
#define CAN_FM1R_FBM14 0x00004000U
#define CAN_FM1R_FBM15 0x00008000U
#define CAN_FM1R_FBM16 0x00010000U
#define CAN_FM1R_FBM17 0x00020000U
#define CAN_FM1R_FBM18 0x00040000U
#define CAN_FM1R_FBM19 0x00080000U
#define CAN_FM1R_FBM20 0x00100000U
#define CAN_FM1R_FBM21 0x00200000U
#define CAN_FM1R_FBM22 0x00400000U
#define CAN_FM1R_FBM23 0x00800000U
#define CAN_FM1R_FBM24 0x01000000U
#define CAN_FM1R_FBM25 0x02000000U
#define CAN_FM1R_FBM26 0x04000000U
#define CAN_FM1R_FBM27 0x08000000U
/*******************  Bit definition for CAN_FS1R register  *******************/
#define CAN_FS1R_FSC   0x0FFFFFFFU
#define CAN_FS1R_FSC0  0x00000001U
#define CAN_FS1R_FSC1  0x00000002U
#define CAN_FS1R_FSC2  0x00000004U
#define CAN_FS1R_FSC3  0x00000008U
#define CAN_FS1R_FSC4  0x00000010U
#define CAN_FS1R_FSC5  0x00000020U
#define CAN_FS1R_FSC6  0x00000040U
#define CAN_FS1R_FSC7  0x00000080U
#define CAN_FS1R_FSC8  0x00000100U
#define CAN_FS1R_FSC9  0x00000200U
#define CAN_FS1R_FSC10 0x00000400U
#define CAN_FS1R_FSC11 0x00000800U
#define CAN_FS1R_FSC12 0x00001000U
#define CAN_FS1R_FSC13 0x00002000U
#define CAN_FS1R_FSC14 0x00004000U
#define CAN_FS1R_FSC15 0x00008000U
#define CAN_FS1R_FSC16 0x00010000U
#define CAN_FS1R_FSC17 0x00020000U
#define CAN_FS1R_FSC18 0x00040000U
#define CAN_FS1R_FSC19 0x00080000U
#define CAN_FS1R_FSC20 0x00100000U
#define CAN_FS1R_FSC21 0x00200000U
#define CAN_FS1R_FSC22 0x00400000U
#define CAN_FS1R_FSC23 0x00800000U
#define CAN_FS1R_FSC24 0x01000000U
#define CAN_FS1R_FSC25 0x02000000U
#define CAN_FS1R_FSC26 0x04000000U
#define CAN_FS1R_FSC27 0x08000000U
/******************  Bit definition for CAN_FFA1R register  *******************/
#define CAN_FFA1R_FFA   0x0FFFFFFFU
#define CAN_FFA1R_FFA0  0x00000001U
#define CAN_FFA1R_FFA1  0x00000002U
#define CAN_FFA1R_FFA2  0x00000004U
#define CAN_FFA1R_FFA3  0x00000008U
#define CAN_FFA1R_FFA4  0x00000010U
#define CAN_FFA1R_FFA5  0x00000020U
#define CAN_FFA1R_FFA6  0x00000040U
#define CAN_FFA1R_FFA7  0x00000080U
#define CAN_FFA1R_FFA8  0x00000100U
#define CAN_FFA1R_FFA9  0x00000200U
#define CAN_FFA1R_FFA10 0x00000400U
#define CAN_FFA1R_FFA11 0x00000800U
#define CAN_FFA1R_FFA12 0x00001000U
#define CAN_FFA1R_FFA13 0x00002000U
#define CAN_FFA1R_FFA14 0x00004000U
#define CAN_FFA1R_FFA15 0x00008000U
#define CAN_FFA1R_FFA16 0x00010000U
#define CAN_FFA1R_FFA17 0x00020000U
#define CAN_FFA1R_FFA18 0x00040000U
#define CAN_FFA1R_FFA19 0x00080000U
#define CAN_FFA1R_FFA20 0x00100000U
#define CAN_FFA1R_FFA21 0x00200000U
#define CAN_FFA1R_FFA22 0x00400000U
#define CAN_FFA1R_FFA23 0x00800000U
#define CAN_FFA1R_FFA24 0x01000000U
#define CAN_FFA1R_FFA25 0x02000000U
#define CAN_FFA1R_FFA26 0x04000000U
#define CAN_FFA1R_FFA27 0x08000000U
/*******************  Bit definition for CAN_FA1R register  *******************/
#define CAN_FA1R_FACT   0x0FFFFFFFU
#define CAN_FA1R_FACT0  0x00000001U
#define CAN_FA1R_FACT1  0x00000002U
#define CAN_FA1R_FACT2  0x00000004U
#define CAN_FA1R_FACT3  0x00000008U
#define CAN_FA1R_FACT4  0x00000010U
#define CAN_FA1R_FACT5  0x00000020U
#define CAN_FA1R_FACT6  0x00000040U
#define CAN_FA1R_FACT7  0x00000080U
#define CAN_FA1R_FACT8  0x00000100U
#define CAN_FA1R_FACT9  0x00000200U
#define CAN_FA1R_FACT10 0x00000400U
#define CAN_FA1R_FACT11 0x00000800U
#define CAN_FA1R_FACT12 0x00001000U
#define CAN_FA1R_FACT13 0x00002000U
#define CAN_FA1R_FACT14 0x00004000U
#define CAN_FA1R_FACT15 0x00008000U
#define CAN_FA1R_FACT16 0x00010000U
#define CAN_FA1R_FACT17 0x00020000U
#define CAN_FA1R_FACT18 0x00040000U
#define CAN_FA1R_FACT19 0x00080000U
#define CAN_FA1R_FACT20 0x00100000U
#define CAN_FA1R_FACT21 0x00200000U
#define CAN_FA1R_FACT22 0x00400000U
#define CAN_FA1R_FACT23 0x00800000U
#define CAN_FA1R_FACT24 0x01000000U
#define CAN_FA1R_FACT25 0x02000000U
#define CAN_FA1R_FACT26 0x04000000U
#define CAN_FA1R_FACT27 0x08000000U
/*******************  Bit definition for CAN_F0R1 register  *******************/
#define CAN_F0R1_FB0  0x00000001U
#define CAN_F0R1_FB1  0x00000002U
#define CAN_F0R1_FB2  0x00000004U
#define CAN_F0R1_FB3  0x00000008U
#define CAN_F0R1_FB4  0x00000010U
#define CAN_F0R1_FB5  0x00000020U
#define CAN_F0R1_FB6  0x00000040U
#define CAN_F0R1_FB7  0x00000080U
#define CAN_F0R1_FB8  0x00000100U
#define CAN_F0R1_FB9  0x00000200U
#define CAN_F0R1_FB10 0x00000400U
#define CAN_F0R1_FB11 0x00000800U
#define CAN_F0R1_FB12 0x00001000U
#define CAN_F0R1_FB13 0x00002000U
#define CAN_F0R1_FB14 0x00004000U
#define CAN_F0R1_FB15 0x00008000U
#define CAN_F0R1_FB16 0x00010000U
#define CAN_F0R1_FB17 0x00020000U
#define CAN_F0R1_FB18 0x00040000U
#define CAN_F0R1_FB19 0x00080000U
#define CAN_F0R1_FB20 0x00100000U
#define CAN_F0R1_FB21 0x00200000U
#define CAN_F0R1_FB22 0x00400000U
#define CAN_F0R1_FB23 0x00800000U
#define CAN_F0R1_FB24 0x01000000U
#define CAN_F0R1_FB25 0x02000000U
#define CAN_F0R1_FB26 0x04000000U
#define CAN_F0R1_FB27 0x08000000U
#define CAN_F0R1_FB28 0x10000000U
#define CAN_F0R1_FB29 0x20000000U
#define CAN_F0R1_FB30 0x40000000U
#define CAN_F0R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F1R1 register  *******************/
#define CAN_F1R1_FB0  0x00000001U
#define CAN_F1R1_FB1  0x00000002U
#define CAN_F1R1_FB2  0x00000004U
#define CAN_F1R1_FB3  0x00000008U
#define CAN_F1R1_FB4  0x00000010U
#define CAN_F1R1_FB5  0x00000020U
#define CAN_F1R1_FB6  0x00000040U
#define CAN_F1R1_FB7  0x00000080U
#define CAN_F1R1_FB8  0x00000100U
#define CAN_F1R1_FB9  0x00000200U
#define CAN_F1R1_FB10 0x00000400U
#define CAN_F1R1_FB11 0x00000800U
#define CAN_F1R1_FB12 0x00001000U
#define CAN_F1R1_FB13 0x00002000U
#define CAN_F1R1_FB14 0x00004000U
#define CAN_F1R1_FB15 0x00008000U
#define CAN_F1R1_FB16 0x00010000U
#define CAN_F1R1_FB17 0x00020000U
#define CAN_F1R1_FB18 0x00040000U
#define CAN_F1R1_FB19 0x00080000U
#define CAN_F1R1_FB20 0x00100000U
#define CAN_F1R1_FB21 0x00200000U
#define CAN_F1R1_FB22 0x00400000U
#define CAN_F1R1_FB23 0x00800000U
#define CAN_F1R1_FB24 0x01000000U
#define CAN_F1R1_FB25 0x02000000U
#define CAN_F1R1_FB26 0x04000000U
#define CAN_F1R1_FB27 0x08000000U
#define CAN_F1R1_FB28 0x10000000U
#define CAN_F1R1_FB29 0x20000000U
#define CAN_F1R1_FB30 0x40000000U
#define CAN_F1R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F2R1 register  *******************/
#define CAN_F2R1_FB0  0x00000001U
#define CAN_F2R1_FB1  0x00000002U
#define CAN_F2R1_FB2  0x00000004U
#define CAN_F2R1_FB3  0x00000008U
#define CAN_F2R1_FB4  0x00000010U
#define CAN_F2R1_FB5  0x00000020U
#define CAN_F2R1_FB6  0x00000040U
#define CAN_F2R1_FB7  0x00000080U
#define CAN_F2R1_FB8  0x00000100U
#define CAN_F2R1_FB9  0x00000200U
#define CAN_F2R1_FB10 0x00000400U
#define CAN_F2R1_FB11 0x00000800U
#define CAN_F2R1_FB12 0x00001000U
#define CAN_F2R1_FB13 0x00002000U
#define CAN_F2R1_FB14 0x00004000U
#define CAN_F2R1_FB15 0x00008000U
#define CAN_F2R1_FB16 0x00010000U
#define CAN_F2R1_FB17 0x00020000U
#define CAN_F2R1_FB18 0x00040000U
#define CAN_F2R1_FB19 0x00080000U
#define CAN_F2R1_FB20 0x00100000U
#define CAN_F2R1_FB21 0x00200000U
#define CAN_F2R1_FB22 0x00400000U
#define CAN_F2R1_FB23 0x00800000U
#define CAN_F2R1_FB24 0x01000000U
#define CAN_F2R1_FB25 0x02000000U
#define CAN_F2R1_FB26 0x04000000U
#define CAN_F2R1_FB27 0x08000000U
#define CAN_F2R1_FB28 0x10000000U
#define CAN_F2R1_FB29 0x20000000U
#define CAN_F2R1_FB30 0x40000000U
#define CAN_F2R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F3R1 register  *******************/
#define CAN_F3R1_FB0  0x00000001U
#define CAN_F3R1_FB1  0x00000002U
#define CAN_F3R1_FB2  0x00000004U
#define CAN_F3R1_FB3  0x00000008U
#define CAN_F3R1_FB4  0x00000010U
#define CAN_F3R1_FB5  0x00000020U
#define CAN_F3R1_FB6  0x00000040U
#define CAN_F3R1_FB7  0x00000080U
#define CAN_F3R1_FB8  0x00000100U
#define CAN_F3R1_FB9  0x00000200U
#define CAN_F3R1_FB10 0x00000400U
#define CAN_F3R1_FB11 0x00000800U
#define CAN_F3R1_FB12 0x00001000U
#define CAN_F3R1_FB13 0x00002000U
#define CAN_F3R1_FB14 0x00004000U
#define CAN_F3R1_FB15 0x00008000U
#define CAN_F3R1_FB16 0x00010000U
#define CAN_F3R1_FB17 0x00020000U
#define CAN_F3R1_FB18 0x00040000U
#define CAN_F3R1_FB19 0x00080000U
#define CAN_F3R1_FB20 0x00100000U
#define CAN_F3R1_FB21 0x00200000U
#define CAN_F3R1_FB22 0x00400000U
#define CAN_F3R1_FB23 0x00800000U
#define CAN_F3R1_FB24 0x01000000U
#define CAN_F3R1_FB25 0x02000000U
#define CAN_F3R1_FB26 0x04000000U
#define CAN_F3R1_FB27 0x08000000U
#define CAN_F3R1_FB28 0x10000000U
#define CAN_F3R1_FB29 0x20000000U
#define CAN_F3R1_FB30 0x40000000U
#define CAN_F3R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F4R1 register  *******************/
#define CAN_F4R1_FB0  0x00000001U
#define CAN_F4R1_FB1  0x00000002U
#define CAN_F4R1_FB2  0x00000004U
#define CAN_F4R1_FB3  0x00000008U
#define CAN_F4R1_FB4  0x00000010U
#define CAN_F4R1_FB5  0x00000020U
#define CAN_F4R1_FB6  0x00000040U
#define CAN_F4R1_FB7  0x00000080U
#define CAN_F4R1_FB8  0x00000100U
#define CAN_F4R1_FB9  0x00000200U
#define CAN_F4R1_FB10 0x00000400U
#define CAN_F4R1_FB11 0x00000800U
#define CAN_F4R1_FB12 0x00001000U
#define CAN_F4R1_FB13 0x00002000U
#define CAN_F4R1_FB14 0x00004000U
#define CAN_F4R1_FB15 0x00008000U
#define CAN_F4R1_FB16 0x00010000U
#define CAN_F4R1_FB17 0x00020000U
#define CAN_F4R1_FB18 0x00040000U
#define CAN_F4R1_FB19 0x00080000U
#define CAN_F4R1_FB20 0x00100000U
#define CAN_F4R1_FB21 0x00200000U
#define CAN_F4R1_FB22 0x00400000U
#define CAN_F4R1_FB23 0x00800000U
#define CAN_F4R1_FB24 0x01000000U
#define CAN_F4R1_FB25 0x02000000U
#define CAN_F4R1_FB26 0x04000000U
#define CAN_F4R1_FB27 0x08000000U
#define CAN_F4R1_FB28 0x10000000U
#define CAN_F4R1_FB29 0x20000000U
#define CAN_F4R1_FB30 0x40000000U
#define CAN_F4R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F5R1 register  *******************/
#define CAN_F5R1_FB0  0x00000001U
#define CAN_F5R1_FB1  0x00000002U
#define CAN_F5R1_FB2  0x00000004U
#define CAN_F5R1_FB3  0x00000008U
#define CAN_F5R1_FB4  0x00000010U
#define CAN_F5R1_FB5  0x00000020U
#define CAN_F5R1_FB6  0x00000040U
#define CAN_F5R1_FB7  0x00000080U
#define CAN_F5R1_FB8  0x00000100U
#define CAN_F5R1_FB9  0x00000200U
#define CAN_F5R1_FB10 0x00000400U
#define CAN_F5R1_FB11 0x00000800U
#define CAN_F5R1_FB12 0x00001000U
#define CAN_F5R1_FB13 0x00002000U
#define CAN_F5R1_FB14 0x00004000U
#define CAN_F5R1_FB15 0x00008000U
#define CAN_F5R1_FB16 0x00010000U
#define CAN_F5R1_FB17 0x00020000U
#define CAN_F5R1_FB18 0x00040000U
#define CAN_F5R1_FB19 0x00080000U
#define CAN_F5R1_FB20 0x00100000U
#define CAN_F5R1_FB21 0x00200000U
#define CAN_F5R1_FB22 0x00400000U
#define CAN_F5R1_FB23 0x00800000U
#define CAN_F5R1_FB24 0x01000000U
#define CAN_F5R1_FB25 0x02000000U
#define CAN_F5R1_FB26 0x04000000U
#define CAN_F5R1_FB27 0x08000000U
#define CAN_F5R1_FB28 0x10000000U
#define CAN_F5R1_FB29 0x20000000U
#define CAN_F5R1_FB30 0x40000000U
#define CAN_F5R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F6R1 register  *******************/
#define CAN_F6R1_FB0  0x00000001U
#define CAN_F6R1_FB1  0x00000002U
#define CAN_F6R1_FB2  0x00000004U
#define CAN_F6R1_FB3  0x00000008U
#define CAN_F6R1_FB4  0x00000010U
#define CAN_F6R1_FB5  0x00000020U
#define CAN_F6R1_FB6  0x00000040U
#define CAN_F6R1_FB7  0x00000080U
#define CAN_F6R1_FB8  0x00000100U
#define CAN_F6R1_FB9  0x00000200U
#define CAN_F6R1_FB10 0x00000400U
#define CAN_F6R1_FB11 0x00000800U
#define CAN_F6R1_FB12 0x00001000U
#define CAN_F6R1_FB13 0x00002000U
#define CAN_F6R1_FB14 0x00004000U
#define CAN_F6R1_FB15 0x00008000U
#define CAN_F6R1_FB16 0x00010000U
#define CAN_F6R1_FB17 0x00020000U
#define CAN_F6R1_FB18 0x00040000U
#define CAN_F6R1_FB19 0x00080000U
#define CAN_F6R1_FB20 0x00100000U
#define CAN_F6R1_FB21 0x00200000U
#define CAN_F6R1_FB22 0x00400000U
#define CAN_F6R1_FB23 0x00800000U
#define CAN_F6R1_FB24 0x01000000U
#define CAN_F6R1_FB25 0x02000000U
#define CAN_F6R1_FB26 0x04000000U
#define CAN_F6R1_FB27 0x08000000U
#define CAN_F6R1_FB28 0x10000000U
#define CAN_F6R1_FB29 0x20000000U
#define CAN_F6R1_FB30 0x40000000U
#define CAN_F6R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F7R1 register  *******************/
#define CAN_F7R1_FB0  0x00000001U
#define CAN_F7R1_FB1  0x00000002U
#define CAN_F7R1_FB2  0x00000004U
#define CAN_F7R1_FB3  0x00000008U
#define CAN_F7R1_FB4  0x00000010U
#define CAN_F7R1_FB5  0x00000020U
#define CAN_F7R1_FB6  0x00000040U
#define CAN_F7R1_FB7  0x00000080U
#define CAN_F7R1_FB8  0x00000100U
#define CAN_F7R1_FB9  0x00000200U
#define CAN_F7R1_FB10 0x00000400U
#define CAN_F7R1_FB11 0x00000800U
#define CAN_F7R1_FB12 0x00001000U
#define CAN_F7R1_FB13 0x00002000U
#define CAN_F7R1_FB14 0x00004000U
#define CAN_F7R1_FB15 0x00008000U
#define CAN_F7R1_FB16 0x00010000U
#define CAN_F7R1_FB17 0x00020000U
#define CAN_F7R1_FB18 0x00040000U
#define CAN_F7R1_FB19 0x00080000U
#define CAN_F7R1_FB20 0x00100000U
#define CAN_F7R1_FB21 0x00200000U
#define CAN_F7R1_FB22 0x00400000U
#define CAN_F7R1_FB23 0x00800000U
#define CAN_F7R1_FB24 0x01000000U
#define CAN_F7R1_FB25 0x02000000U
#define CAN_F7R1_FB26 0x04000000U
#define CAN_F7R1_FB27 0x08000000U
#define CAN_F7R1_FB28 0x10000000U
#define CAN_F7R1_FB29 0x20000000U
#define CAN_F7R1_FB30 0x40000000U
#define CAN_F7R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F8R1 register  *******************/
#define CAN_F8R1_FB0  0x00000001U
#define CAN_F8R1_FB1  0x00000002U
#define CAN_F8R1_FB2  0x00000004U
#define CAN_F8R1_FB3  0x00000008U
#define CAN_F8R1_FB4  0x00000010U
#define CAN_F8R1_FB5  0x00000020U
#define CAN_F8R1_FB6  0x00000040U
#define CAN_F8R1_FB7  0x00000080U
#define CAN_F8R1_FB8  0x00000100U
#define CAN_F8R1_FB9  0x00000200U
#define CAN_F8R1_FB10 0x00000400U
#define CAN_F8R1_FB11 0x00000800U
#define CAN_F8R1_FB12 0x00001000U
#define CAN_F8R1_FB13 0x00002000U
#define CAN_F8R1_FB14 0x00004000U
#define CAN_F8R1_FB15 0x00008000U
#define CAN_F8R1_FB16 0x00010000U
#define CAN_F8R1_FB17 0x00020000U
#define CAN_F8R1_FB18 0x00040000U
#define CAN_F8R1_FB19 0x00080000U
#define CAN_F8R1_FB20 0x00100000U
#define CAN_F8R1_FB21 0x00200000U
#define CAN_F8R1_FB22 0x00400000U
#define CAN_F8R1_FB23 0x00800000U
#define CAN_F8R1_FB24 0x01000000U
#define CAN_F8R1_FB25 0x02000000U
#define CAN_F8R1_FB26 0x04000000U
#define CAN_F8R1_FB27 0x08000000U
#define CAN_F8R1_FB28 0x10000000U
#define CAN_F8R1_FB29 0x20000000U
#define CAN_F8R1_FB30 0x40000000U
#define CAN_F8R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F9R1 register  *******************/
#define CAN_F9R1_FB0  0x00000001U
#define CAN_F9R1_FB1  0x00000002U
#define CAN_F9R1_FB2  0x00000004U
#define CAN_F9R1_FB3  0x00000008U
#define CAN_F9R1_FB4  0x00000010U
#define CAN_F9R1_FB5  0x00000020U
#define CAN_F9R1_FB6  0x00000040U
#define CAN_F9R1_FB7  0x00000080U
#define CAN_F9R1_FB8  0x00000100U
#define CAN_F9R1_FB9  0x00000200U
#define CAN_F9R1_FB10 0x00000400U
#define CAN_F9R1_FB11 0x00000800U
#define CAN_F9R1_FB12 0x00001000U
#define CAN_F9R1_FB13 0x00002000U
#define CAN_F9R1_FB14 0x00004000U
#define CAN_F9R1_FB15 0x00008000U
#define CAN_F9R1_FB16 0x00010000U
#define CAN_F9R1_FB17 0x00020000U
#define CAN_F9R1_FB18 0x00040000U
#define CAN_F9R1_FB19 0x00080000U
#define CAN_F9R1_FB20 0x00100000U
#define CAN_F9R1_FB21 0x00200000U
#define CAN_F9R1_FB22 0x00400000U
#define CAN_F9R1_FB23 0x00800000U
#define CAN_F9R1_FB24 0x01000000U
#define CAN_F9R1_FB25 0x02000000U
#define CAN_F9R1_FB26 0x04000000U
#define CAN_F9R1_FB27 0x08000000U
#define CAN_F9R1_FB28 0x10000000U
#define CAN_F9R1_FB29 0x20000000U
#define CAN_F9R1_FB30 0x40000000U
#define CAN_F9R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F10R1 register  ******************/
#define CAN_F10R1_FB0  0x00000001U
#define CAN_F10R1_FB1  0x00000002U
#define CAN_F10R1_FB2  0x00000004U
#define CAN_F10R1_FB3  0x00000008U
#define CAN_F10R1_FB4  0x00000010U
#define CAN_F10R1_FB5  0x00000020U
#define CAN_F10R1_FB6  0x00000040U
#define CAN_F10R1_FB7  0x00000080U
#define CAN_F10R1_FB8  0x00000100U
#define CAN_F10R1_FB9  0x00000200U
#define CAN_F10R1_FB10 0x00000400U
#define CAN_F10R1_FB11 0x00000800U
#define CAN_F10R1_FB12 0x00001000U
#define CAN_F10R1_FB13 0x00002000U
#define CAN_F10R1_FB14 0x00004000U
#define CAN_F10R1_FB15 0x00008000U
#define CAN_F10R1_FB16 0x00010000U
#define CAN_F10R1_FB17 0x00020000U
#define CAN_F10R1_FB18 0x00040000U
#define CAN_F10R1_FB19 0x00080000U
#define CAN_F10R1_FB20 0x00100000U
#define CAN_F10R1_FB21 0x00200000U
#define CAN_F10R1_FB22 0x00400000U
#define CAN_F10R1_FB23 0x00800000U
#define CAN_F10R1_FB24 0x01000000U
#define CAN_F10R1_FB25 0x02000000U
#define CAN_F10R1_FB26 0x04000000U
#define CAN_F10R1_FB27 0x08000000U
#define CAN_F10R1_FB28 0x10000000U
#define CAN_F10R1_FB29 0x20000000U
#define CAN_F10R1_FB30 0x40000000U
#define CAN_F10R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F11R1 register  ******************/
#define CAN_F11R1_FB0  0x00000001U
#define CAN_F11R1_FB1  0x00000002U
#define CAN_F11R1_FB2  0x00000004U
#define CAN_F11R1_FB3  0x00000008U
#define CAN_F11R1_FB4  0x00000010U
#define CAN_F11R1_FB5  0x00000020U
#define CAN_F11R1_FB6  0x00000040U
#define CAN_F11R1_FB7  0x00000080U
#define CAN_F11R1_FB8  0x00000100U
#define CAN_F11R1_FB9  0x00000200U
#define CAN_F11R1_FB10 0x00000400U
#define CAN_F11R1_FB11 0x00000800U
#define CAN_F11R1_FB12 0x00001000U
#define CAN_F11R1_FB13 0x00002000U
#define CAN_F11R1_FB14 0x00004000U
#define CAN_F11R1_FB15 0x00008000U
#define CAN_F11R1_FB16 0x00010000U
#define CAN_F11R1_FB17 0x00020000U
#define CAN_F11R1_FB18 0x00040000U
#define CAN_F11R1_FB19 0x00080000U
#define CAN_F11R1_FB20 0x00100000U
#define CAN_F11R1_FB21 0x00200000U
#define CAN_F11R1_FB22 0x00400000U
#define CAN_F11R1_FB23 0x00800000U
#define CAN_F11R1_FB24 0x01000000U
#define CAN_F11R1_FB25 0x02000000U
#define CAN_F11R1_FB26 0x04000000U
#define CAN_F11R1_FB27 0x08000000U
#define CAN_F11R1_FB28 0x10000000U
#define CAN_F11R1_FB29 0x20000000U
#define CAN_F11R1_FB30 0x40000000U
#define CAN_F11R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F12R1 register  ******************/
#define CAN_F12R1_FB0  0x00000001U
#define CAN_F12R1_FB1  0x00000002U
#define CAN_F12R1_FB2  0x00000004U
#define CAN_F12R1_FB3  0x00000008U
#define CAN_F12R1_FB4  0x00000010U
#define CAN_F12R1_FB5  0x00000020U
#define CAN_F12R1_FB6  0x00000040U
#define CAN_F12R1_FB7  0x00000080U
#define CAN_F12R1_FB8  0x00000100U
#define CAN_F12R1_FB9  0x00000200U
#define CAN_F12R1_FB10 0x00000400U
#define CAN_F12R1_FB11 0x00000800U
#define CAN_F12R1_FB12 0x00001000U
#define CAN_F12R1_FB13 0x00002000U
#define CAN_F12R1_FB14 0x00004000U
#define CAN_F12R1_FB15 0x00008000U
#define CAN_F12R1_FB16 0x00010000U
#define CAN_F12R1_FB17 0x00020000U
#define CAN_F12R1_FB18 0x00040000U
#define CAN_F12R1_FB19 0x00080000U
#define CAN_F12R1_FB20 0x00100000U
#define CAN_F12R1_FB21 0x00200000U
#define CAN_F12R1_FB22 0x00400000U
#define CAN_F12R1_FB23 0x00800000U
#define CAN_F12R1_FB24 0x01000000U
#define CAN_F12R1_FB25 0x02000000U
#define CAN_F12R1_FB26 0x04000000U
#define CAN_F12R1_FB27 0x08000000U
#define CAN_F12R1_FB28 0x10000000U
#define CAN_F12R1_FB29 0x20000000U
#define CAN_F12R1_FB30 0x40000000U
#define CAN_F12R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F13R1 register  ******************/
#define CAN_F13R1_FB0  0x00000001U
#define CAN_F13R1_FB1  0x00000002U
#define CAN_F13R1_FB2  0x00000004U
#define CAN_F13R1_FB3  0x00000008U
#define CAN_F13R1_FB4  0x00000010U
#define CAN_F13R1_FB5  0x00000020U
#define CAN_F13R1_FB6  0x00000040U
#define CAN_F13R1_FB7  0x00000080U
#define CAN_F13R1_FB8  0x00000100U
#define CAN_F13R1_FB9  0x00000200U
#define CAN_F13R1_FB10 0x00000400U
#define CAN_F13R1_FB11 0x00000800U
#define CAN_F13R1_FB12 0x00001000U
#define CAN_F13R1_FB13 0x00002000U
#define CAN_F13R1_FB14 0x00004000U
#define CAN_F13R1_FB15 0x00008000U
#define CAN_F13R1_FB16 0x00010000U
#define CAN_F13R1_FB17 0x00020000U
#define CAN_F13R1_FB18 0x00040000U
#define CAN_F13R1_FB19 0x00080000U
#define CAN_F13R1_FB20 0x00100000U
#define CAN_F13R1_FB21 0x00200000U
#define CAN_F13R1_FB22 0x00400000U
#define CAN_F13R1_FB23 0x00800000U
#define CAN_F13R1_FB24 0x01000000U
#define CAN_F13R1_FB25 0x02000000U
#define CAN_F13R1_FB26 0x04000000U
#define CAN_F13R1_FB27 0x08000000U
#define CAN_F13R1_FB28 0x10000000U
#define CAN_F13R1_FB29 0x20000000U
#define CAN_F13R1_FB30 0x40000000U
#define CAN_F13R1_FB31 0x80000000U
/*******************  Bit definition for CAN_F0R2 register  *******************/
#define CAN_F0R2_FB0  0x00000001U
#define CAN_F0R2_FB1  0x00000002U
#define CAN_F0R2_FB2  0x00000004U
#define CAN_F0R2_FB3  0x00000008U
#define CAN_F0R2_FB4  0x00000010U
#define CAN_F0R2_FB5  0x00000020U
#define CAN_F0R2_FB6  0x00000040U
#define CAN_F0R2_FB7  0x00000080U
#define CAN_F0R2_FB8  0x00000100U
#define CAN_F0R2_FB9  0x00000200U
#define CAN_F0R2_FB10 0x00000400U
#define CAN_F0R2_FB11 0x00000800U
#define CAN_F0R2_FB12 0x00001000U
#define CAN_F0R2_FB13 0x00002000U
#define CAN_F0R2_FB14 0x00004000U
#define CAN_F0R2_FB15 0x00008000U
#define CAN_F0R2_FB16 0x00010000U
#define CAN_F0R2_FB17 0x00020000U
#define CAN_F0R2_FB18 0x00040000U
#define CAN_F0R2_FB19 0x00080000U
#define CAN_F0R2_FB20 0x00100000U
#define CAN_F0R2_FB21 0x00200000U
#define CAN_F0R2_FB22 0x00400000U
#define CAN_F0R2_FB23 0x00800000U
#define CAN_F0R2_FB24 0x01000000U
#define CAN_F0R2_FB25 0x02000000U
#define CAN_F0R2_FB26 0x04000000U
#define CAN_F0R2_FB27 0x08000000U
#define CAN_F0R2_FB28 0x10000000U
#define CAN_F0R2_FB29 0x20000000U
#define CAN_F0R2_FB30 0x40000000U
#define CAN_F0R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F1R2 register  *******************/
#define CAN_F1R2_FB0  0x00000001U
#define CAN_F1R2_FB1  0x00000002U
#define CAN_F1R2_FB2  0x00000004U
#define CAN_F1R2_FB3  0x00000008U
#define CAN_F1R2_FB4  0x00000010U
#define CAN_F1R2_FB5  0x00000020U
#define CAN_F1R2_FB6  0x00000040U
#define CAN_F1R2_FB7  0x00000080U
#define CAN_F1R2_FB8  0x00000100U
#define CAN_F1R2_FB9  0x00000200U
#define CAN_F1R2_FB10 0x00000400U
#define CAN_F1R2_FB11 0x00000800U
#define CAN_F1R2_FB12 0x00001000U
#define CAN_F1R2_FB13 0x00002000U
#define CAN_F1R2_FB14 0x00004000U
#define CAN_F1R2_FB15 0x00008000U
#define CAN_F1R2_FB16 0x00010000U
#define CAN_F1R2_FB17 0x00020000U
#define CAN_F1R2_FB18 0x00040000U
#define CAN_F1R2_FB19 0x00080000U
#define CAN_F1R2_FB20 0x00100000U
#define CAN_F1R2_FB21 0x00200000U
#define CAN_F1R2_FB22 0x00400000U
#define CAN_F1R2_FB23 0x00800000U
#define CAN_F1R2_FB24 0x01000000U
#define CAN_F1R2_FB25 0x02000000U
#define CAN_F1R2_FB26 0x04000000U
#define CAN_F1R2_FB27 0x08000000U
#define CAN_F1R2_FB28 0x10000000U
#define CAN_F1R2_FB29 0x20000000U
#define CAN_F1R2_FB30 0x40000000U
#define CAN_F1R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F2R2 register  *******************/
#define CAN_F2R2_FB0  0x00000001U
#define CAN_F2R2_FB1  0x00000002U
#define CAN_F2R2_FB2  0x00000004U
#define CAN_F2R2_FB3  0x00000008U
#define CAN_F2R2_FB4  0x00000010U
#define CAN_F2R2_FB5  0x00000020U
#define CAN_F2R2_FB6  0x00000040U
#define CAN_F2R2_FB7  0x00000080U
#define CAN_F2R2_FB8  0x00000100U
#define CAN_F2R2_FB9  0x00000200U
#define CAN_F2R2_FB10 0x00000400U
#define CAN_F2R2_FB11 0x00000800U
#define CAN_F2R2_FB12 0x00001000U
#define CAN_F2R2_FB13 0x00002000U
#define CAN_F2R2_FB14 0x00004000U
#define CAN_F2R2_FB15 0x00008000U
#define CAN_F2R2_FB16 0x00010000U
#define CAN_F2R2_FB17 0x00020000U
#define CAN_F2R2_FB18 0x00040000U
#define CAN_F2R2_FB19 0x00080000U
#define CAN_F2R2_FB20 0x00100000U
#define CAN_F2R2_FB21 0x00200000U
#define CAN_F2R2_FB22 0x00400000U
#define CAN_F2R2_FB23 0x00800000U
#define CAN_F2R2_FB24 0x01000000U
#define CAN_F2R2_FB25 0x02000000U
#define CAN_F2R2_FB26 0x04000000U
#define CAN_F2R2_FB27 0x08000000U
#define CAN_F2R2_FB28 0x10000000U
#define CAN_F2R2_FB29 0x20000000U
#define CAN_F2R2_FB30 0x40000000U
#define CAN_F2R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F3R2 register  *******************/
#define CAN_F3R2_FB0  0x00000001U
#define CAN_F3R2_FB1  0x00000002U
#define CAN_F3R2_FB2  0x00000004U
#define CAN_F3R2_FB3  0x00000008U
#define CAN_F3R2_FB4  0x00000010U
#define CAN_F3R2_FB5  0x00000020U
#define CAN_F3R2_FB6  0x00000040U
#define CAN_F3R2_FB7  0x00000080U
#define CAN_F3R2_FB8  0x00000100U
#define CAN_F3R2_FB9  0x00000200U
#define CAN_F3R2_FB10 0x00000400U
#define CAN_F3R2_FB11 0x00000800U
#define CAN_F3R2_FB12 0x00001000U
#define CAN_F3R2_FB13 0x00002000U
#define CAN_F3R2_FB14 0x00004000U
#define CAN_F3R2_FB15 0x00008000U
#define CAN_F3R2_FB16 0x00010000U
#define CAN_F3R2_FB17 0x00020000U
#define CAN_F3R2_FB18 0x00040000U
#define CAN_F3R2_FB19 0x00080000U
#define CAN_F3R2_FB20 0x00100000U
#define CAN_F3R2_FB21 0x00200000U
#define CAN_F3R2_FB22 0x00400000U
#define CAN_F3R2_FB23 0x00800000U
#define CAN_F3R2_FB24 0x01000000U
#define CAN_F3R2_FB25 0x02000000U
#define CAN_F3R2_FB26 0x04000000U
#define CAN_F3R2_FB27 0x08000000U
#define CAN_F3R2_FB28 0x10000000U
#define CAN_F3R2_FB29 0x20000000U
#define CAN_F3R2_FB30 0x40000000U
#define CAN_F3R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F4R2 register  *******************/
#define CAN_F4R2_FB0  0x00000001U
#define CAN_F4R2_FB1  0x00000002U
#define CAN_F4R2_FB2  0x00000004U
#define CAN_F4R2_FB3  0x00000008U
#define CAN_F4R2_FB4  0x00000010U
#define CAN_F4R2_FB5  0x00000020U
#define CAN_F4R2_FB6  0x00000040U
#define CAN_F4R2_FB7  0x00000080U
#define CAN_F4R2_FB8  0x00000100U
#define CAN_F4R2_FB9  0x00000200U
#define CAN_F4R2_FB10 0x00000400U
#define CAN_F4R2_FB11 0x00000800U
#define CAN_F4R2_FB12 0x00001000U
#define CAN_F4R2_FB13 0x00002000U
#define CAN_F4R2_FB14 0x00004000U
#define CAN_F4R2_FB15 0x00008000U
#define CAN_F4R2_FB16 0x00010000U
#define CAN_F4R2_FB17 0x00020000U
#define CAN_F4R2_FB18 0x00040000U
#define CAN_F4R2_FB19 0x00080000U
#define CAN_F4R2_FB20 0x00100000U
#define CAN_F4R2_FB21 0x00200000U
#define CAN_F4R2_FB22 0x00400000U
#define CAN_F4R2_FB23 0x00800000U
#define CAN_F4R2_FB24 0x01000000U
#define CAN_F4R2_FB25 0x02000000U
#define CAN_F4R2_FB26 0x04000000U
#define CAN_F4R2_FB27 0x08000000U
#define CAN_F4R2_FB28 0x10000000U
#define CAN_F4R2_FB29 0x20000000U
#define CAN_F4R2_FB30 0x40000000U
#define CAN_F4R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F5R2 register  *******************/
#define CAN_F5R2_FB0  0x00000001U
#define CAN_F5R2_FB1  0x00000002U
#define CAN_F5R2_FB2  0x00000004U
#define CAN_F5R2_FB3  0x00000008U
#define CAN_F5R2_FB4  0x00000010U
#define CAN_F5R2_FB5  0x00000020U
#define CAN_F5R2_FB6  0x00000040U
#define CAN_F5R2_FB7  0x00000080U
#define CAN_F5R2_FB8  0x00000100U
#define CAN_F5R2_FB9  0x00000200U
#define CAN_F5R2_FB10 0x00000400U
#define CAN_F5R2_FB11 0x00000800U
#define CAN_F5R2_FB12 0x00001000U
#define CAN_F5R2_FB13 0x00002000U
#define CAN_F5R2_FB14 0x00004000U
#define CAN_F5R2_FB15 0x00008000U
#define CAN_F5R2_FB16 0x00010000U
#define CAN_F5R2_FB17 0x00020000U
#define CAN_F5R2_FB18 0x00040000U
#define CAN_F5R2_FB19 0x00080000U
#define CAN_F5R2_FB20 0x00100000U
#define CAN_F5R2_FB21 0x00200000U
#define CAN_F5R2_FB22 0x00400000U
#define CAN_F5R2_FB23 0x00800000U
#define CAN_F5R2_FB24 0x01000000U
#define CAN_F5R2_FB25 0x02000000U
#define CAN_F5R2_FB26 0x04000000U
#define CAN_F5R2_FB27 0x08000000U
#define CAN_F5R2_FB28 0x10000000U
#define CAN_F5R2_FB29 0x20000000U
#define CAN_F5R2_FB30 0x40000000U
#define CAN_F5R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F6R2 register  *******************/
#define CAN_F6R2_FB0  0x00000001U
#define CAN_F6R2_FB1  0x00000002U
#define CAN_F6R2_FB2  0x00000004U
#define CAN_F6R2_FB3  0x00000008U
#define CAN_F6R2_FB4  0x00000010U
#define CAN_F6R2_FB5  0x00000020U
#define CAN_F6R2_FB6  0x00000040U
#define CAN_F6R2_FB7  0x00000080U
#define CAN_F6R2_FB8  0x00000100U
#define CAN_F6R2_FB9  0x00000200U
#define CAN_F6R2_FB10 0x00000400U
#define CAN_F6R2_FB11 0x00000800U
#define CAN_F6R2_FB12 0x00001000U
#define CAN_F6R2_FB13 0x00002000U
#define CAN_F6R2_FB14 0x00004000U
#define CAN_F6R2_FB15 0x00008000U
#define CAN_F6R2_FB16 0x00010000U
#define CAN_F6R2_FB17 0x00020000U
#define CAN_F6R2_FB18 0x00040000U
#define CAN_F6R2_FB19 0x00080000U
#define CAN_F6R2_FB20 0x00100000U
#define CAN_F6R2_FB21 0x00200000U
#define CAN_F6R2_FB22 0x00400000U
#define CAN_F6R2_FB23 0x00800000U
#define CAN_F6R2_FB24 0x01000000U
#define CAN_F6R2_FB25 0x02000000U
#define CAN_F6R2_FB26 0x04000000U
#define CAN_F6R2_FB27 0x08000000U
#define CAN_F6R2_FB28 0x10000000U
#define CAN_F6R2_FB29 0x20000000U
#define CAN_F6R2_FB30 0x40000000U
#define CAN_F6R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F7R2 register  *******************/
#define CAN_F7R2_FB0  0x00000001U
#define CAN_F7R2_FB1  0x00000002U
#define CAN_F7R2_FB2  0x00000004U
#define CAN_F7R2_FB3  0x00000008U
#define CAN_F7R2_FB4  0x00000010U
#define CAN_F7R2_FB5  0x00000020U
#define CAN_F7R2_FB6  0x00000040U
#define CAN_F7R2_FB7  0x00000080U
#define CAN_F7R2_FB8  0x00000100U
#define CAN_F7R2_FB9  0x00000200U
#define CAN_F7R2_FB10 0x00000400U
#define CAN_F7R2_FB11 0x00000800U
#define CAN_F7R2_FB12 0x00001000U
#define CAN_F7R2_FB13 0x00002000U
#define CAN_F7R2_FB14 0x00004000U
#define CAN_F7R2_FB15 0x00008000U
#define CAN_F7R2_FB16 0x00010000U
#define CAN_F7R2_FB17 0x00020000U
#define CAN_F7R2_FB18 0x00040000U
#define CAN_F7R2_FB19 0x00080000U
#define CAN_F7R2_FB20 0x00100000U
#define CAN_F7R2_FB21 0x00200000U
#define CAN_F7R2_FB22 0x00400000U
#define CAN_F7R2_FB23 0x00800000U
#define CAN_F7R2_FB24 0x01000000U
#define CAN_F7R2_FB25 0x02000000U
#define CAN_F7R2_FB26 0x04000000U
#define CAN_F7R2_FB27 0x08000000U
#define CAN_F7R2_FB28 0x10000000U
#define CAN_F7R2_FB29 0x20000000U
#define CAN_F7R2_FB30 0x40000000U
#define CAN_F7R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F8R2 register  *******************/
#define CAN_F8R2_FB0  0x00000001U
#define CAN_F8R2_FB1  0x00000002U
#define CAN_F8R2_FB2  0x00000004U
#define CAN_F8R2_FB3  0x00000008U
#define CAN_F8R2_FB4  0x00000010U
#define CAN_F8R2_FB5  0x00000020U
#define CAN_F8R2_FB6  0x00000040U
#define CAN_F8R2_FB7  0x00000080U
#define CAN_F8R2_FB8  0x00000100U
#define CAN_F8R2_FB9  0x00000200U
#define CAN_F8R2_FB10 0x00000400U
#define CAN_F8R2_FB11 0x00000800U
#define CAN_F8R2_FB12 0x00001000U
#define CAN_F8R2_FB13 0x00002000U
#define CAN_F8R2_FB14 0x00004000U
#define CAN_F8R2_FB15 0x00008000U
#define CAN_F8R2_FB16 0x00010000U
#define CAN_F8R2_FB17 0x00020000U
#define CAN_F8R2_FB18 0x00040000U
#define CAN_F8R2_FB19 0x00080000U
#define CAN_F8R2_FB20 0x00100000U
#define CAN_F8R2_FB21 0x00200000U
#define CAN_F8R2_FB22 0x00400000U
#define CAN_F8R2_FB23 0x00800000U
#define CAN_F8R2_FB24 0x01000000U
#define CAN_F8R2_FB25 0x02000000U
#define CAN_F8R2_FB26 0x04000000U
#define CAN_F8R2_FB27 0x08000000U
#define CAN_F8R2_FB28 0x10000000U
#define CAN_F8R2_FB29 0x20000000U
#define CAN_F8R2_FB30 0x40000000U
#define CAN_F8R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F9R2 register  *******************/
#define CAN_F9R2_FB0  0x00000001U
#define CAN_F9R2_FB1  0x00000002U
#define CAN_F9R2_FB2  0x00000004U
#define CAN_F9R2_FB3  0x00000008U
#define CAN_F9R2_FB4  0x00000010U
#define CAN_F9R2_FB5  0x00000020U
#define CAN_F9R2_FB6  0x00000040U
#define CAN_F9R2_FB7  0x00000080U
#define CAN_F9R2_FB8  0x00000100U
#define CAN_F9R2_FB9  0x00000200U
#define CAN_F9R2_FB10 0x00000400U
#define CAN_F9R2_FB11 0x00000800U
#define CAN_F9R2_FB12 0x00001000U
#define CAN_F9R2_FB13 0x00002000U
#define CAN_F9R2_FB14 0x00004000U
#define CAN_F9R2_FB15 0x00008000U
#define CAN_F9R2_FB16 0x00010000U
#define CAN_F9R2_FB17 0x00020000U
#define CAN_F9R2_FB18 0x00040000U
#define CAN_F9R2_FB19 0x00080000U
#define CAN_F9R2_FB20 0x00100000U
#define CAN_F9R2_FB21 0x00200000U
#define CAN_F9R2_FB22 0x00400000U
#define CAN_F9R2_FB23 0x00800000U
#define CAN_F9R2_FB24 0x01000000U
#define CAN_F9R2_FB25 0x02000000U
#define CAN_F9R2_FB26 0x04000000U
#define CAN_F9R2_FB27 0x08000000U
#define CAN_F9R2_FB28 0x10000000U
#define CAN_F9R2_FB29 0x20000000U
#define CAN_F9R2_FB30 0x40000000U
#define CAN_F9R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F10R2 register  ******************/
#define CAN_F10R2_FB0  0x00000001U
#define CAN_F10R2_FB1  0x00000002U
#define CAN_F10R2_FB2  0x00000004U
#define CAN_F10R2_FB3  0x00000008U
#define CAN_F10R2_FB4  0x00000010U
#define CAN_F10R2_FB5  0x00000020U
#define CAN_F10R2_FB6  0x00000040U
#define CAN_F10R2_FB7  0x00000080U
#define CAN_F10R2_FB8  0x00000100U
#define CAN_F10R2_FB9  0x00000200U
#define CAN_F10R2_FB10 0x00000400U
#define CAN_F10R2_FB11 0x00000800U
#define CAN_F10R2_FB12 0x00001000U
#define CAN_F10R2_FB13 0x00002000U
#define CAN_F10R2_FB14 0x00004000U
#define CAN_F10R2_FB15 0x00008000U
#define CAN_F10R2_FB16 0x00010000U
#define CAN_F10R2_FB17 0x00020000U
#define CAN_F10R2_FB18 0x00040000U
#define CAN_F10R2_FB19 0x00080000U
#define CAN_F10R2_FB20 0x00100000U
#define CAN_F10R2_FB21 0x00200000U
#define CAN_F10R2_FB22 0x00400000U
#define CAN_F10R2_FB23 0x00800000U
#define CAN_F10R2_FB24 0x01000000U
#define CAN_F10R2_FB25 0x02000000U
#define CAN_F10R2_FB26 0x04000000U
#define CAN_F10R2_FB27 0x08000000U
#define CAN_F10R2_FB28 0x10000000U
#define CAN_F10R2_FB29 0x20000000U
#define CAN_F10R2_FB30 0x40000000U
#define CAN_F10R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F11R2 register  ******************/
#define CAN_F11R2_FB0  0x00000001U
#define CAN_F11R2_FB1  0x00000002U
#define CAN_F11R2_FB2  0x00000004U
#define CAN_F11R2_FB3  0x00000008U
#define CAN_F11R2_FB4  0x00000010U
#define CAN_F11R2_FB5  0x00000020U
#define CAN_F11R2_FB6  0x00000040U
#define CAN_F11R2_FB7  0x00000080U
#define CAN_F11R2_FB8  0x00000100U
#define CAN_F11R2_FB9  0x00000200U
#define CAN_F11R2_FB10 0x00000400U
#define CAN_F11R2_FB11 0x00000800U
#define CAN_F11R2_FB12 0x00001000U
#define CAN_F11R2_FB13 0x00002000U
#define CAN_F11R2_FB14 0x00004000U
#define CAN_F11R2_FB15 0x00008000U
#define CAN_F11R2_FB16 0x00010000U
#define CAN_F11R2_FB17 0x00020000U
#define CAN_F11R2_FB18 0x00040000U
#define CAN_F11R2_FB19 0x00080000U
#define CAN_F11R2_FB20 0x00100000U
#define CAN_F11R2_FB21 0x00200000U
#define CAN_F11R2_FB22 0x00400000U
#define CAN_F11R2_FB23 0x00800000U
#define CAN_F11R2_FB24 0x01000000U
#define CAN_F11R2_FB25 0x02000000U
#define CAN_F11R2_FB26 0x04000000U
#define CAN_F11R2_FB27 0x08000000U
#define CAN_F11R2_FB28 0x10000000U
#define CAN_F11R2_FB29 0x20000000U
#define CAN_F11R2_FB30 0x40000000U
#define CAN_F11R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F12R2 register  ******************/
#define CAN_F12R2_FB0  0x00000001U
#define CAN_F12R2_FB1  0x00000002U
#define CAN_F12R2_FB2  0x00000004U
#define CAN_F12R2_FB3  0x00000008U
#define CAN_F12R2_FB4  0x00000010U
#define CAN_F12R2_FB5  0x00000020U
#define CAN_F12R2_FB6  0x00000040U
#define CAN_F12R2_FB7  0x00000080U
#define CAN_F12R2_FB8  0x00000100U
#define CAN_F12R2_FB9  0x00000200U
#define CAN_F12R2_FB10 0x00000400U
#define CAN_F12R2_FB11 0x00000800U
#define CAN_F12R2_FB12 0x00001000U
#define CAN_F12R2_FB13 0x00002000U
#define CAN_F12R2_FB14 0x00004000U
#define CAN_F12R2_FB15 0x00008000U
#define CAN_F12R2_FB16 0x00010000U
#define CAN_F12R2_FB17 0x00020000U
#define CAN_F12R2_FB18 0x00040000U
#define CAN_F12R2_FB19 0x00080000U
#define CAN_F12R2_FB20 0x00100000U
#define CAN_F12R2_FB21 0x00200000U
#define CAN_F12R2_FB22 0x00400000U
#define CAN_F12R2_FB23 0x00800000U
#define CAN_F12R2_FB24 0x01000000U
#define CAN_F12R2_FB25 0x02000000U
#define CAN_F12R2_FB26 0x04000000U
#define CAN_F12R2_FB27 0x08000000U
#define CAN_F12R2_FB28 0x10000000U
#define CAN_F12R2_FB29 0x20000000U
#define CAN_F12R2_FB30 0x40000000U
#define CAN_F12R2_FB31 0x80000000U
/*******************  Bit definition for CAN_F13R2 register  ******************/
#define CAN_F13R2_FB0  0x00000001U
#define CAN_F13R2_FB1  0x00000002U
#define CAN_F13R2_FB2  0x00000004U
#define CAN_F13R2_FB3  0x00000008U
#define CAN_F13R2_FB4  0x00000010U
#define CAN_F13R2_FB5  0x00000020U
#define CAN_F13R2_FB6  0x00000040U
#define CAN_F13R2_FB7  0x00000080U
#define CAN_F13R2_FB8  0x00000100U
#define CAN_F13R2_FB9  0x00000200U
#define CAN_F13R2_FB10 0x00000400U
#define CAN_F13R2_FB11 0x00000800U
#define CAN_F13R2_FB12 0x00001000U
#define CAN_F13R2_FB13 0x00002000U
#define CAN_F13R2_FB14 0x00004000U
#define CAN_F13R2_FB15 0x00008000U
#define CAN_F13R2_FB16 0x00010000U
#define CAN_F13R2_FB17 0x00020000U
#define CAN_F13R2_FB18 0x00040000U
#define CAN_F13R2_FB19 0x00080000U
#define CAN_F13R2_FB20 0x00100000U
#define CAN_F13R2_FB21 0x00200000U
#define CAN_F13R2_FB22 0x00400000U
#define CAN_F13R2_FB23 0x00800000U
#define CAN_F13R2_FB24 0x01000000U
#define CAN_F13R2_FB25 0x02000000U
#define CAN_F13R2_FB26 0x04000000U
#define CAN_F13R2_FB27 0x08000000U
#define CAN_F13R2_FB28 0x10000000U
#define CAN_F13R2_FB29 0x20000000U
#define CAN_F13R2_FB30 0x40000000U
#define CAN_F13R2_FB31 0x80000000U
/******************************************************************************/
/*                                                                            */
/*                          HDMI-CEC (CEC)                                    */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for CEC_CR register  *********************/
#define CEC_CR_CECEN 0x00000001U
#define CEC_CR_TXSOM 0x00000002U
#define CEC_CR_TXEOM 0x00000004U
/*******************  Bit definition for CEC_CFGR register  *******************/
#define CEC_CFGR_SFT      0x00000007U
#define CEC_CFGR_RXTOL    0x00000008U
#define CEC_CFGR_BRESTP   0x00000010U
#define CEC_CFGR_BREGEN   0x00000020U
#define CEC_CFGR_LBPEGEN  0x00000040U
#define CEC_CFGR_SFTOPT   0x00000100U
#define CEC_CFGR_BRDNOGEN 0x00000080U
#define CEC_CFGR_OAR      0x7FFF0000U
#define CEC_CFGR_LSTN     0x80000000U
/*******************  Bit definition for CEC_TXDR register  *******************/
#define CEC_TXDR_TXD 0x000000FFU
/*******************  Bit definition for CEC_RXDR register  *******************/
#define CEC_TXDR_RXD 0x000000FFU
/*******************  Bit definition for CEC_ISR register  ********************/
#define CEC_ISR_RXBR   0x00000001U
#define CEC_ISR_RXEND  0x00000002U
#define CEC_ISR_RXOVR  0x00000004U
#define CEC_ISR_BRE    0x00000008U
#define CEC_ISR_SBPE   0x00000010U
#define CEC_ISR_LBPE   0x00000020U
#define CEC_ISR_RXACKE 0x00000040U
#define CEC_ISR_ARBLST 0x00000080U
#define CEC_ISR_TXBR   0x00000100U
#define CEC_ISR_TXEND  0x00000200U
#define CEC_ISR_TXUDR  0x00000400U
#define CEC_ISR_TXERR  0x00000800U
#define CEC_ISR_TXACKE 0x00001000U
/*******************  Bit definition for CEC_IER register  ********************/
#define CEC_IER_RXBRIE   0x00000001U
#define CEC_IER_RXENDIE  0x00000002U
#define CEC_IER_RXOVRIE  0x00000004U
#define CEC_IER_BREIE    0x00000008U
#define CEC_IER_SBPEIE   0x00000010U
#define CEC_IER_LBPEIE   0x00000020U
#define CEC_IER_RXACKEIE 0x00000040U
#define CEC_IER_ARBLSTIE 0x00000080U
#define CEC_IER_TXBRIE   0x00000100U
#define CEC_IER_TXENDIE  0x00000200U
#define CEC_IER_TXUDRIE  0x00000400U
#define CEC_IER_TXERRIE  0x00000800U
#define CEC_IER_TXACKEIE 0x00001000U
/******************************************************************************/
/*                                                                            */
/*                          CRC calculation unit                              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR 0xFFFFFFFFU
/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR 0xFFU
/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET 0x01U
/******************************************************************************/
/*                                                                            */
/*                      Digital to Analog Converter                           */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1       0x00000001U
#define DAC_CR_BOFF1     0x00000002U
#define DAC_CR_TEN1      0x00000004U
#define DAC_CR_TSEL1     0x00000038U
#define DAC_CR_TSEL1_0   0x00000008U
#define DAC_CR_TSEL1_1   0x00000010U
#define DAC_CR_TSEL1_2   0x00000020U
#define DAC_CR_WAVE1     0x000000C0U
#define DAC_CR_WAVE1_0   0x00000040U
#define DAC_CR_WAVE1_1   0x00000080U
#define DAC_CR_MAMP1     0x00000F00U
#define DAC_CR_MAMP1_0   0x00000100U
#define DAC_CR_MAMP1_1   0x00000200U
#define DAC_CR_MAMP1_2   0x00000400U
#define DAC_CR_MAMP1_3   0x00000800U
#define DAC_CR_DMAEN1    0x00001000U
#define DAC_CR_DMAUDRIE1 0x00002000U
#define DAC_CR_EN2       0x00010000U
#define DAC_CR_BOFF2     0x00020000U
#define DAC_CR_TEN2      0x00040000U
#define DAC_CR_TSEL2     0x00380000U
#define DAC_CR_TSEL2_0   0x00080000U
#define DAC_CR_TSEL2_1   0x00100000U
#define DAC_CR_TSEL2_2   0x00200000U
#define DAC_CR_WAVE2     0x00C00000U
#define DAC_CR_WAVE2_0   0x00400000U
#define DAC_CR_WAVE2_1   0x00800000U
#define DAC_CR_MAMP2     0x0F000000U
#define DAC_CR_MAMP2_0   0x01000000U
#define DAC_CR_MAMP2_1   0x02000000U
#define DAC_CR_MAMP2_2   0x04000000U
#define DAC_CR_MAMP2_3   0x08000000U
#define DAC_CR_DMAEN2    0x10000000U
#define DAC_CR_DMAUDRIE2 0x20000000U
/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1 0x01U
#define DAC_SWTRIGR_SWTRIG2 0x02U
/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR 0x0FFFU
/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR 0xFFF0U
/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR 0xFFU
/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR 0x0FFFU
/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR 0xFFF0U
/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR 0xFFU
/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR 0x00000FFFU
#define DAC_DHR12RD_DACC2DHR 0x0FFF0000U
/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR 0x0000FFF0U
#define DAC_DHR12LD_DACC2DHR 0xFFF00000U
/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR 0x00FFU
#define DAC_DHR8RD_DACC2DHR 0xFF00U
/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR 0x0FFFU
/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR 0x0FFFU
/********************  Bit definition for DAC_SR register  ********************/
#define DAC_SR_DMAUDR1 0x00002000U
#define DAC_SR_DMAUDR2 0x20000000U
/******************************************************************************/
/*                                                                            */
/*                                 Debug MCU                                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                    DCMI                                    */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DCMI_CR register  ******************/
#define DCMI_CR_CAPTURE 0x00000001U
#define DCMI_CR_CM      0x00000002U
#define DCMI_CR_CROP    0x00000004U
#define DCMI_CR_JPEG    0x00000008U
#define DCMI_CR_ESS     0x00000010U
#define DCMI_CR_PCKPOL  0x00000020U
#define DCMI_CR_HSPOL   0x00000040U
#define DCMI_CR_VSPOL   0x00000080U
#define DCMI_CR_FCRC_0  0x00000100U
#define DCMI_CR_FCRC_1  0x00000200U
#define DCMI_CR_EDM_0   0x00000400U
#define DCMI_CR_EDM_1   0x00000800U
#define DCMI_CR_OUTEN   0x00002000U
#define DCMI_CR_ENABLE  0x00004000U
#define DCMI_CR_BSM_0   0x00010000U
#define DCMI_CR_BSM_1   0x00020000U
#define DCMI_CR_OEBS    0x00040000U
#define DCMI_CR_LSM     0x00080000U
#define DCMI_CR_OELS    0x00100000U

/********************  Bits definition for DCMI_SR register  ******************/
#define DCMI_SR_HSYNC 0x00000001U
#define DCMI_SR_VSYNC 0x00000002U
#define DCMI_SR_FNE   0x00000004U

/********************  Bits definition for DCMI_RIS register  ****************/
#define DCMI_RIS_FRAME_RIS 0x00000001U
#define DCMI_RIS_OVR_RIS   0x00000002U
#define DCMI_RIS_ERR_RIS   0x00000004U
#define DCMI_RIS_VSYNC_RIS 0x00000008U
#define DCMI_RIS_LINE_RIS  0x00000010U
/* Legacy defines */
#define DCMI_RISR_FRAME_RIS DCMI_RIS_FRAME_RIS
#define DCMI_RISR_OVR_RIS   DCMI_RIS_OVR_RIS
#define DCMI_RISR_ERR_RIS   DCMI_RIS_ERR_RIS
#define DCMI_RISR_VSYNC_RIS DCMI_RIS_VSYNC_RIS
#define DCMI_RISR_LINE_RIS  DCMI_RIS_LINE_RIS
#define DCMI_RISR_OVF_RIS   DCMI_RIS_OVR_RIS

/********************  Bits definition for DCMI_IER register  *****************/
#define DCMI_IER_FRAME_IE 0x00000001U
#define DCMI_IER_OVR_IE   0x00000002U
#define DCMI_IER_ERR_IE   0x00000004U
#define DCMI_IER_VSYNC_IE 0x00000008U
#define DCMI_IER_LINE_IE  0x00000010U
/* Legacy defines */
#define DCMI_IER_OVF_IE DCMI_IER_OVR_IE

/********************  Bits definition for DCMI_MIS register  *****************/
#define DCMI_MIS_FRAME_MIS 0x00000001U
#define DCMI_MIS_OVR_MIS   0x00000002U
#define DCMI_MIS_ERR_MIS   0x00000004U
#define DCMI_MIS_VSYNC_MIS 0x00000008U
#define DCMI_MIS_LINE_MIS  0x00000010U

/* Legacy defines */
#define DCMI_MISR_FRAME_MIS DCMI_MIS_FRAME_MIS
#define DCMI_MISR_OVF_MIS   DCMI_MIS_OVR_MIS
#define DCMI_MISR_ERR_MIS   DCMI_MIS_ERR_MIS
#define DCMI_MISR_VSYNC_MIS DCMI_MIS_VSYNC_MIS
#define DCMI_MISR_LINE_MIS  DCMI_MIS_LINE_MIS

/********************  Bits definition for DCMI_ICR register  *****************/
#define DCMI_ICR_FRAME_ISC 0x00000001U
#define DCMI_ICR_OVR_ISC   0x00000002U
#define DCMI_ICR_ERR_ISC   0x00000004U
#define DCMI_ICR_VSYNC_ISC 0x00000008U
#define DCMI_ICR_LINE_ISC  0x00000010U

/* Legacy defines */
#define DCMI_ICR_OVF_ISC DCMI_ICR_OVR_ISC

/********************  Bits definition for DCMI_ESCR register  ******************/
#define DCMI_ESCR_FSC 0x000000FFU
#define DCMI_ESCR_LSC 0x0000FF00U
#define DCMI_ESCR_LEC 0x00FF0000U
#define DCMI_ESCR_FEC 0xFF000000U

/********************  Bits definition for DCMI_ESUR register  ******************/
#define DCMI_ESUR_FSU 0x000000FFU
#define DCMI_ESUR_LSU 0x0000FF00U
#define DCMI_ESUR_LEU 0x00FF0000U
#define DCMI_ESUR_FEU 0xFF000000U

/********************  Bits definition for DCMI_CWSTRT register  ******************/
#define DCMI_CWSTRT_HOFFCNT 0x00003FFFU
#define DCMI_CWSTRT_VST     0x1FFF0000U

/********************  Bits definition for DCMI_CWSIZE register  ******************/
#define DCMI_CWSIZE_CAPCNT 0x00003FFFU
#define DCMI_CWSIZE_VLINE  0x3FFF0000U

/********************  Bits definition for DCMI_DR register  ******************/
#define DCMI_DR_BYTE0 0x000000FFU
#define DCMI_DR_BYTE1 0x0000FF00U
#define DCMI_DR_BYTE2 0x00FF0000U
#define DCMI_DR_BYTE3 0xFF000000U

/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_CHSEL    0x0E000000U
#define DMA_SxCR_CHSEL_0  0x02000000U
#define DMA_SxCR_CHSEL_1  0x04000000U
#define DMA_SxCR_CHSEL_2  0x08000000U
#define DMA_SxCR_MBURST   0x01800000U
#define DMA_SxCR_MBURST_0 0x00800000U
#define DMA_SxCR_MBURST_1 0x01000000U
#define DMA_SxCR_PBURST   0x00600000U
#define DMA_SxCR_PBURST_0 0x00200000U
#define DMA_SxCR_PBURST_1 0x00400000U
#define DMA_SxCR_CT       0x00080000U
#define DMA_SxCR_DBM      0x00040000U
#define DMA_SxCR_PL       0x00030000U
#define DMA_SxCR_PL_0     0x00010000U
#define DMA_SxCR_PL_1     0x00020000U
#define DMA_SxCR_PINCOS   0x00008000U
#define DMA_SxCR_MSIZE    0x00006000U
#define DMA_SxCR_MSIZE_0  0x00002000U
#define DMA_SxCR_MSIZE_1  0x00004000U
#define DMA_SxCR_PSIZE    0x00001800U
#define DMA_SxCR_PSIZE_0  0x00000800U
#define DMA_SxCR_PSIZE_1  0x00001000U
#define DMA_SxCR_MINC     0x00000400U
#define DMA_SxCR_PINC     0x00000200U
#define DMA_SxCR_CIRC     0x00000100U
#define DMA_SxCR_DIR      0x000000C0U
#define DMA_SxCR_DIR_0    0x00000040U
#define DMA_SxCR_DIR_1    0x00000080U
#define DMA_SxCR_PFCTRL   0x00000020U
#define DMA_SxCR_TCIE     0x00000010U
#define DMA_SxCR_HTIE     0x00000008U
#define DMA_SxCR_TEIE     0x00000004U
#define DMA_SxCR_DMEIE    0x00000002U
#define DMA_SxCR_EN       0x00000001U

/* Legacy defines */
#define DMA_SxCR_ACK 0x00100000U

/********************  Bits definition for DMA_SxCNDTR register  **************/
#define DMA_SxNDT    0x0000FFFFU
#define DMA_SxNDT_0  0x00000001U
#define DMA_SxNDT_1  0x00000002U
#define DMA_SxNDT_2  0x00000004U
#define DMA_SxNDT_3  0x00000008U
#define DMA_SxNDT_4  0x00000010U
#define DMA_SxNDT_5  0x00000020U
#define DMA_SxNDT_6  0x00000040U
#define DMA_SxNDT_7  0x00000080U
#define DMA_SxNDT_8  0x00000100U
#define DMA_SxNDT_9  0x00000200U
#define DMA_SxNDT_10 0x00000400U
#define DMA_SxNDT_11 0x00000800U
#define DMA_SxNDT_12 0x00001000U
#define DMA_SxNDT_13 0x00002000U
#define DMA_SxNDT_14 0x00004000U
#define DMA_SxNDT_15 0x00008000U

/********************  Bits definition for DMA_SxFCR register  ****************/
#define DMA_SxFCR_FEIE  0x00000080U
#define DMA_SxFCR_FS    0x00000038U
#define DMA_SxFCR_FS_0  0x00000008U
#define DMA_SxFCR_FS_1  0x00000010U
#define DMA_SxFCR_FS_2  0x00000020U
#define DMA_SxFCR_DMDIS 0x00000004U
#define DMA_SxFCR_FTH   0x00000003U
#define DMA_SxFCR_FTH_0 0x00000001U
#define DMA_SxFCR_FTH_1 0x00000002U

/********************  Bits definition for DMA_LISR register  *****************/
#define DMA_LISR_TCIF3  0x08000000U
#define DMA_LISR_HTIF3  0x04000000U
#define DMA_LISR_TEIF3  0x02000000U
#define DMA_LISR_DMEIF3 0x01000000U
#define DMA_LISR_FEIF3  0x00400000U
#define DMA_LISR_TCIF2  0x00200000U
#define DMA_LISR_HTIF2  0x00100000U
#define DMA_LISR_TEIF2  0x00080000U
#define DMA_LISR_DMEIF2 0x00040000U
#define DMA_LISR_FEIF2  0x00010000U
#define DMA_LISR_TCIF1  0x00000800U
#define DMA_LISR_HTIF1  0x00000400U
#define DMA_LISR_TEIF1  0x00000200U
#define DMA_LISR_DMEIF1 0x00000100U
#define DMA_LISR_FEIF1  0x00000040U
#define DMA_LISR_TCIF0  0x00000020U
#define DMA_LISR_HTIF0  0x00000010U
#define DMA_LISR_TEIF0  0x00000008U
#define DMA_LISR_DMEIF0 0x00000004U
#define DMA_LISR_FEIF0  0x00000001U

/********************  Bits definition for DMA_HISR register  *****************/
#define DMA_HISR_TCIF7  0x08000000U
#define DMA_HISR_HTIF7  0x04000000U
#define DMA_HISR_TEIF7  0x02000000U
#define DMA_HISR_DMEIF7 0x01000000U
#define DMA_HISR_FEIF7  0x00400000U
#define DMA_HISR_TCIF6  0x00200000U
#define DMA_HISR_HTIF6  0x00100000U
#define DMA_HISR_TEIF6  0x00080000U
#define DMA_HISR_DMEIF6 0x00040000U
#define DMA_HISR_FEIF6  0x00010000U
#define DMA_HISR_TCIF5  0x00000800U
#define DMA_HISR_HTIF5  0x00000400U
#define DMA_HISR_TEIF5  0x00000200U
#define DMA_HISR_DMEIF5 0x00000100U
#define DMA_HISR_FEIF5  0x00000040U
#define DMA_HISR_TCIF4  0x00000020U
#define DMA_HISR_HTIF4  0x00000010U
#define DMA_HISR_TEIF4  0x00000008U
#define DMA_HISR_DMEIF4 0x00000004U
#define DMA_HISR_FEIF4  0x00000001U

/********************  Bits definition for DMA_LIFCR register  ****************/
#define DMA_LIFCR_CTCIF3  0x08000000U
#define DMA_LIFCR_CHTIF3  0x04000000U
#define DMA_LIFCR_CTEIF3  0x02000000U
#define DMA_LIFCR_CDMEIF3 0x01000000U
#define DMA_LIFCR_CFEIF3  0x00400000U
#define DMA_LIFCR_CTCIF2  0x00200000U
#define DMA_LIFCR_CHTIF2  0x00100000U
#define DMA_LIFCR_CTEIF2  0x00080000U
#define DMA_LIFCR_CDMEIF2 0x00040000U
#define DMA_LIFCR_CFEIF2  0x00010000U
#define DMA_LIFCR_CTCIF1  0x00000800U
#define DMA_LIFCR_CHTIF1  0x00000400U
#define DMA_LIFCR_CTEIF1  0x00000200U
#define DMA_LIFCR_CDMEIF1 0x00000100U
#define DMA_LIFCR_CFEIF1  0x00000040U
#define DMA_LIFCR_CTCIF0  0x00000020U
#define DMA_LIFCR_CHTIF0  0x00000010U
#define DMA_LIFCR_CTEIF0  0x00000008U
#define DMA_LIFCR_CDMEIF0 0x00000004U
#define DMA_LIFCR_CFEIF0  0x00000001U

/********************  Bits definition for DMA_HIFCR  register  ****************/
#define DMA_HIFCR_CTCIF7  0x08000000U
#define DMA_HIFCR_CHTIF7  0x04000000U
#define DMA_HIFCR_CTEIF7  0x02000000U
#define DMA_HIFCR_CDMEIF7 0x01000000U
#define DMA_HIFCR_CFEIF7  0x00400000U
#define DMA_HIFCR_CTCIF6  0x00200000U
#define DMA_HIFCR_CHTIF6  0x00100000U
#define DMA_HIFCR_CTEIF6  0x00080000U
#define DMA_HIFCR_CDMEIF6 0x00040000U
#define DMA_HIFCR_CFEIF6  0x00010000U
#define DMA_HIFCR_CTCIF5  0x00000800U
#define DMA_HIFCR_CHTIF5  0x00000400U
#define DMA_HIFCR_CTEIF5  0x00000200U
#define DMA_HIFCR_CDMEIF5 0x00000100U
#define DMA_HIFCR_CFEIF5  0x00000040U
#define DMA_HIFCR_CTCIF4  0x00000020U
#define DMA_HIFCR_CHTIF4  0x00000010U
#define DMA_HIFCR_CTEIF4  0x00000008U
#define DMA_HIFCR_CDMEIF4 0x00000004U
#define DMA_HIFCR_CFEIF4  0x00000001U

/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EXTI_IMR register  *******************/
#define EXTI_IMR_MR0  0x00000001U
#define EXTI_IMR_MR1  0x00000002U
#define EXTI_IMR_MR2  0x00000004U
#define EXTI_IMR_MR3  0x00000008U
#define EXTI_IMR_MR4  0x00000010U
#define EXTI_IMR_MR5  0x00000020U
#define EXTI_IMR_MR6  0x00000040U
#define EXTI_IMR_MR7  0x00000080U
#define EXTI_IMR_MR8  0x00000100U
#define EXTI_IMR_MR9  0x00000200U
#define EXTI_IMR_MR10 0x00000400U
#define EXTI_IMR_MR11 0x00000800U
#define EXTI_IMR_MR12 0x00001000U
#define EXTI_IMR_MR13 0x00002000U
#define EXTI_IMR_MR14 0x00004000U
#define EXTI_IMR_MR15 0x00008000U
#define EXTI_IMR_MR16 0x00010000U
#define EXTI_IMR_MR17 0x00020000U
#define EXTI_IMR_MR18 0x00040000U
#define EXTI_IMR_MR19 0x00080000U
#define EXTI_IMR_MR20 0x00100000U
#define EXTI_IMR_MR21 0x00200000U
#define EXTI_IMR_MR22 0x00400000U
/*******************  Bit definition for EXTI_EMR register  *******************/
#define EXTI_EMR_MR0  0x00000001U
#define EXTI_EMR_MR1  0x00000002U
#define EXTI_EMR_MR2  0x00000004U
#define EXTI_EMR_MR3  0x00000008U
#define EXTI_EMR_MR4  0x00000010U
#define EXTI_EMR_MR5  0x00000020U
#define EXTI_EMR_MR6  0x00000040U
#define EXTI_EMR_MR7  0x00000080U
#define EXTI_EMR_MR8  0x00000100U
#define EXTI_EMR_MR9  0x00000200U
#define EXTI_EMR_MR10 0x00000400U
#define EXTI_EMR_MR11 0x00000800U
#define EXTI_EMR_MR12 0x00001000U
#define EXTI_EMR_MR13 0x00002000U
#define EXTI_EMR_MR14 0x00004000U
#define EXTI_EMR_MR15 0x00008000U
#define EXTI_EMR_MR16 0x00010000U
#define EXTI_EMR_MR17 0x00020000U
#define EXTI_EMR_MR18 0x00040000U
#define EXTI_EMR_MR19 0x00080000U
#define EXTI_EMR_MR20 0x00100000U
#define EXTI_EMR_MR21 0x00200000U
#define EXTI_EMR_MR22 0x00400000U
/******************  Bit definition for EXTI_RTSR register  *******************/
#define EXTI_RTSR_TR0  0x00000001U
#define EXTI_RTSR_TR1  0x00000002U
#define EXTI_RTSR_TR2  0x00000004U
#define EXTI_RTSR_TR3  0x00000008U
#define EXTI_RTSR_TR4  0x00000010U
#define EXTI_RTSR_TR5  0x00000020U
#define EXTI_RTSR_TR6  0x00000040U
#define EXTI_RTSR_TR7  0x00000080U
#define EXTI_RTSR_TR8  0x00000100U
#define EXTI_RTSR_TR9  0x00000200U
#define EXTI_RTSR_TR10 0x00000400U
#define EXTI_RTSR_TR11 0x00000800U
#define EXTI_RTSR_TR12 0x00001000U
#define EXTI_RTSR_TR13 0x00002000U
#define EXTI_RTSR_TR14 0x00004000U
#define EXTI_RTSR_TR15 0x00008000U
#define EXTI_RTSR_TR16 0x00010000U
#define EXTI_RTSR_TR17 0x00020000U
#define EXTI_RTSR_TR18 0x00040000U
#define EXTI_RTSR_TR19 0x00080000U
#define EXTI_RTSR_TR20 0x00100000U
#define EXTI_RTSR_TR21 0x00200000U
#define EXTI_RTSR_TR22 0x00400000U
/******************  Bit definition for EXTI_FTSR register  *******************/
#define EXTI_FTSR_TR0  0x00000001U
#define EXTI_FTSR_TR1  0x00000002U
#define EXTI_FTSR_TR2  0x00000004U
#define EXTI_FTSR_TR3  0x00000008U
#define EXTI_FTSR_TR4  0x00000010U
#define EXTI_FTSR_TR5  0x00000020U
#define EXTI_FTSR_TR6  0x00000040U
#define EXTI_FTSR_TR7  0x00000080U
#define EXTI_FTSR_TR8  0x00000100U
#define EXTI_FTSR_TR9  0x00000200U
#define EXTI_FTSR_TR10 0x00000400U
#define EXTI_FTSR_TR11 0x00000800U
#define EXTI_FTSR_TR12 0x00001000U
#define EXTI_FTSR_TR13 0x00002000U
#define EXTI_FTSR_TR14 0x00004000U
#define EXTI_FTSR_TR15 0x00008000U
#define EXTI_FTSR_TR16 0x00010000U
#define EXTI_FTSR_TR17 0x00020000U
#define EXTI_FTSR_TR18 0x00040000U
#define EXTI_FTSR_TR19 0x00080000U
#define EXTI_FTSR_TR20 0x00100000U
#define EXTI_FTSR_TR21 0x00200000U
#define EXTI_FTSR_TR22 0x00400000U
/******************  Bit definition for EXTI_SWIER register  ******************/
#define EXTI_SWIER_SWIER0  0x00000001U
#define EXTI_SWIER_SWIER1  0x00000002U
#define EXTI_SWIER_SWIER2  0x00000004U
#define EXTI_SWIER_SWIER3  0x00000008U
#define EXTI_SWIER_SWIER4  0x00000010U
#define EXTI_SWIER_SWIER5  0x00000020U
#define EXTI_SWIER_SWIER6  0x00000040U
#define EXTI_SWIER_SWIER7  0x00000080U
#define EXTI_SWIER_SWIER8  0x00000100U
#define EXTI_SWIER_SWIER9  0x00000200U
#define EXTI_SWIER_SWIER10 0x00000400U
#define EXTI_SWIER_SWIER11 0x00000800U
#define EXTI_SWIER_SWIER12 0x00001000U
#define EXTI_SWIER_SWIER13 0x00002000U
#define EXTI_SWIER_SWIER14 0x00004000U
#define EXTI_SWIER_SWIER15 0x00008000U
#define EXTI_SWIER_SWIER16 0x00010000U
#define EXTI_SWIER_SWIER17 0x00020000U
#define EXTI_SWIER_SWIER18 0x00040000U
#define EXTI_SWIER_SWIER19 0x00080000U
#define EXTI_SWIER_SWIER20 0x00100000U
#define EXTI_SWIER_SWIER21 0x00200000U
#define EXTI_SWIER_SWIER22 0x00400000U
/*******************  Bit definition for EXTI_PR register  ********************/
#define EXTI_PR_PR0  0x00000001U
#define EXTI_PR_PR1  0x00000002U
#define EXTI_PR_PR2  0x00000004U
#define EXTI_PR_PR3  0x00000008U
#define EXTI_PR_PR4  0x00000010U
#define EXTI_PR_PR5  0x00000020U
#define EXTI_PR_PR6  0x00000040U
#define EXTI_PR_PR7  0x00000080U
#define EXTI_PR_PR8  0x00000100U
#define EXTI_PR_PR9  0x00000200U
#define EXTI_PR_PR10 0x00000400U
#define EXTI_PR_PR11 0x00000800U
#define EXTI_PR_PR12 0x00001000U
#define EXTI_PR_PR13 0x00002000U
#define EXTI_PR_PR14 0x00004000U
#define EXTI_PR_PR15 0x00008000U
#define EXTI_PR_PR16 0x00010000U
#define EXTI_PR_PR17 0x00020000U
#define EXTI_PR_PR18 0x00040000U
#define EXTI_PR_PR19 0x00080000U
#define EXTI_PR_PR20 0x00100000U
#define EXTI_PR_PR21 0x00200000U
#define EXTI_PR_PR22 0x00400000U
/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY       0x0000000FU
#define FLASH_ACR_LATENCY_0WS   0x00000000U
#define FLASH_ACR_LATENCY_1WS   0x00000001U
#define FLASH_ACR_LATENCY_2WS   0x00000002U
#define FLASH_ACR_LATENCY_3WS   0x00000003U
#define FLASH_ACR_LATENCY_4WS   0x00000004U
#define FLASH_ACR_LATENCY_5WS   0x00000005U
#define FLASH_ACR_LATENCY_6WS   0x00000006U
#define FLASH_ACR_LATENCY_7WS   0x00000007U
#define FLASH_ACR_LATENCY_8WS   0x00000008U
#define FLASH_ACR_LATENCY_9WS   0x00000009U
#define FLASH_ACR_LATENCY_10WS  0x0000000AU
#define FLASH_ACR_LATENCY_11WS  0x0000000BU
#define FLASH_ACR_LATENCY_12WS  0x0000000CU
#define FLASH_ACR_LATENCY_13WS  0x0000000DU
#define FLASH_ACR_LATENCY_14WS  0x0000000EU
#define FLASH_ACR_LATENCY_15WS  0x0000000FU
#define FLASH_ACR_PRFTEN        0x00000100U
#define FLASH_ACR_ICEN          0x00000200U
#define FLASH_ACR_DCEN          0x00000400U
#define FLASH_ACR_ICRST         0x00000800U
#define FLASH_ACR_DCRST         0x00001000U
#define FLASH_ACR_BYTE0_ADDRESS 0x40023C00U
#define FLASH_ACR_BYTE2_ADDRESS 0x40023C03U

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP    0x00000001U
#define FLASH_SR_SOP    0x00000002U
#define FLASH_SR_WRPERR 0x00000010U
#define FLASH_SR_PGAERR 0x00000020U
#define FLASH_SR_PGPERR 0x00000040U
#define FLASH_SR_PGSERR 0x00000080U
#define FLASH_SR_BSY    0x00010000U

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG      0x00000001U
#define FLASH_CR_SER     0x00000002U
#define FLASH_CR_MER     0x00000004U
#define FLASH_CR_MER1    FLASH_CR_MER
#define FLASH_CR_SNB     0x000000F8U
#define FLASH_CR_SNB_0   0x00000008U
#define FLASH_CR_SNB_1   0x00000010U
#define FLASH_CR_SNB_2   0x00000020U
#define FLASH_CR_SNB_3   0x00000040U
#define FLASH_CR_SNB_4   0x00000080U
#define FLASH_CR_PSIZE   0x00000300U
#define FLASH_CR_PSIZE_0 0x00000100U
#define FLASH_CR_PSIZE_1 0x00000200U
#define FLASH_CR_MER2    0x00008000U
#define FLASH_CR_STRT    0x00010000U
#define FLASH_CR_EOPIE   0x01000000U
#define FLASH_CR_LOCK    0x80000000U

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK    0x00000001U
#define FLASH_OPTCR_OPTSTRT    0x00000002U
#define FLASH_OPTCR_BOR_LEV_0  0x00000004U
#define FLASH_OPTCR_BOR_LEV_1  0x00000008U
#define FLASH_OPTCR_BOR_LEV    0x0000000CU
#define FLASH_OPTCR_BFB2       0x00000010U
#define FLASH_OPTCR_WDG_SW     0x00000020U
#define FLASH_OPTCR_nRST_STOP  0x00000040U
#define FLASH_OPTCR_nRST_STDBY 0x00000080U
#define FLASH_OPTCR_RDP        0x0000FF00U
#define FLASH_OPTCR_RDP_0      0x00000100U
#define FLASH_OPTCR_RDP_1      0x00000200U
#define FLASH_OPTCR_RDP_2      0x00000400U
#define FLASH_OPTCR_RDP_3      0x00000800U
#define FLASH_OPTCR_RDP_4      0x00001000U
#define FLASH_OPTCR_RDP_5      0x00002000U
#define FLASH_OPTCR_RDP_6      0x00004000U
#define FLASH_OPTCR_RDP_7      0x00008000U
#define FLASH_OPTCR_nWRP       0x0FFF0000U
#define FLASH_OPTCR_nWRP_0     0x00010000U
#define FLASH_OPTCR_nWRP_1     0x00020000U
#define FLASH_OPTCR_nWRP_2     0x00040000U
#define FLASH_OPTCR_nWRP_3     0x00080000U
#define FLASH_OPTCR_nWRP_4     0x00100000U
#define FLASH_OPTCR_nWRP_5     0x00200000U
#define FLASH_OPTCR_nWRP_6     0x00400000U
#define FLASH_OPTCR_nWRP_7     0x00800000U
#define FLASH_OPTCR_nWRP_8     0x01000000U
#define FLASH_OPTCR_nWRP_9     0x02000000U
#define FLASH_OPTCR_nWRP_10    0x04000000U
#define FLASH_OPTCR_nWRP_11    0x08000000U
#define FLASH_OPTCR_DB1M       0x40000000U
#define FLASH_OPTCR_SPRMOD     0x80000000U

/******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_nWRP    0x0FFF0000U
#define FLASH_OPTCR1_nWRP_0  0x00010000U
#define FLASH_OPTCR1_nWRP_1  0x00020000U
#define FLASH_OPTCR1_nWRP_2  0x00040000U
#define FLASH_OPTCR1_nWRP_3  0x00080000U
#define FLASH_OPTCR1_nWRP_4  0x00100000U
#define FLASH_OPTCR1_nWRP_5  0x00200000U
#define FLASH_OPTCR1_nWRP_6  0x00400000U
#define FLASH_OPTCR1_nWRP_7  0x00800000U
#define FLASH_OPTCR1_nWRP_8  0x01000000U
#define FLASH_OPTCR1_nWRP_9  0x02000000U
#define FLASH_OPTCR1_nWRP_10 0x04000000U
#define FLASH_OPTCR1_nWRP_11 0x08000000U

/******************************************************************************/
/*                                                                            */
/*                          Flexible Memory Controller                        */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for FMC_BCR1 register  *******************/
#define FMC_BCR1_MBKEN     0x00000001U
#define FMC_BCR1_MUXEN     0x00000002U
#define FMC_BCR1_MTYP      0x0000000CU
#define FMC_BCR1_MTYP_0    0x00000004U
#define FMC_BCR1_MTYP_1    0x00000008U
#define FMC_BCR1_MWID      0x00000030U
#define FMC_BCR1_MWID_0    0x00000010U
#define FMC_BCR1_MWID_1    0x00000020U
#define FMC_BCR1_FACCEN    0x00000040U
#define FMC_BCR1_BURSTEN   0x00000100U
#define FMC_BCR1_WAITPOL   0x00000200U
#define FMC_BCR1_WAITCFG   0x00000800U
#define FMC_BCR1_WREN      0x00001000U
#define FMC_BCR1_WAITEN    0x00002000U
#define FMC_BCR1_EXTMOD    0x00004000U
#define FMC_BCR1_ASYNCWAIT 0x00008000U
#define FMC_BCR1_CPSIZE    0x00070000U
#define FMC_BCR1_CPSIZE_0  0x00010000U
#define FMC_BCR1_CPSIZE_1  0x00020000U
#define FMC_BCR1_CPSIZE_2  0x00040000U
#define FMC_BCR1_CBURSTRW  0x00080000U
#define FMC_BCR1_CCLKEN    0x00100000U
#define FMC_BCR1_WFDIS     0x00200000U
/******************  Bit definition for FMC_BCR2 register  *******************/
#define FMC_BCR2_MBKEN     0x00000001U
#define FMC_BCR2_MUXEN     0x00000002U
#define FMC_BCR2_MTYP      0x0000000CU
#define FMC_BCR2_MTYP_0    0x00000004U
#define FMC_BCR2_MTYP_1    0x00000008U
#define FMC_BCR2_MWID      0x00000030U
#define FMC_BCR2_MWID_0    0x00000010U
#define FMC_BCR2_MWID_1    0x00000020U
#define FMC_BCR2_FACCEN    0x00000040U
#define FMC_BCR2_BURSTEN   0x00000100U
#define FMC_BCR2_WAITPOL   0x00000200U
#define FMC_BCR2_WAITCFG   0x00000800U
#define FMC_BCR2_WREN      0x00001000U
#define FMC_BCR2_WAITEN    0x00002000U
#define FMC_BCR2_EXTMOD    0x00004000U
#define FMC_BCR2_ASYNCWAIT 0x00008000U
#define FMC_BCR2_CBURSTRW  0x00080000U
/******************  Bit definition for FMC_BCR3 register  *******************/
#define FMC_BCR3_MBKEN     0x00000001U
#define FMC_BCR3_MUXEN     0x00000002U
#define FMC_BCR3_MTYP      0x0000000CU
#define FMC_BCR3_MTYP_0    0x00000004U
#define FMC_BCR3_MTYP_1    0x00000008U
#define FMC_BCR3_MWID      0x00000030U
#define FMC_BCR3_MWID_0    0x00000010U
#define FMC_BCR3_MWID_1    0x00000020U
#define FMC_BCR3_FACCEN    0x00000040U
#define FMC_BCR3_BURSTEN   0x00000100U
#define FMC_BCR3_WAITPOL   0x00000200U
#define FMC_BCR3_WAITCFG   0x00000800U
#define FMC_BCR3_WREN      0x00001000U
#define FMC_BCR3_WAITEN    0x00002000U
#define FMC_BCR3_EXTMOD    0x00004000U
#define FMC_BCR3_ASYNCWAIT 0x00008000U
#define FMC_BCR3_CBURSTRW  0x00080000U
/******************  Bit definition for FMC_BCR4 register  *******************/
#define FMC_BCR4_MBKEN     0x00000001U
#define FMC_BCR4_MUXEN     0x00000002U
#define FMC_BCR4_MTYP      0x0000000CU
#define FMC_BCR4_MTYP_0    0x00000004U
#define FMC_BCR4_MTYP_1    0x00000008U
#define FMC_BCR4_MWID      0x00000030U
#define FMC_BCR4_MWID_0    0x00000010U
#define FMC_BCR4_MWID_1    0x00000020U
#define FMC_BCR4_FACCEN    0x00000040U
#define FMC_BCR4_BURSTEN   0x00000100U
#define FMC_BCR4_WAITPOL   0x00000200U
#define FMC_BCR4_WAITCFG   0x00000800U
#define FMC_BCR4_WREN      0x00001000U
#define FMC_BCR4_WAITEN    0x00002000U
#define FMC_BCR4_EXTMOD    0x00004000U
#define FMC_BCR4_ASYNCWAIT 0x00008000U
#define FMC_BCR4_CBURSTRW  0x00080000U
/******************  Bit definition for FMC_BTR1 register  ******************/
#define FMC_BTR1_ADDSET    0x0000000FU
#define FMC_BTR1_ADDSET_0  0x00000001U
#define FMC_BTR1_ADDSET_1  0x00000002U
#define FMC_BTR1_ADDSET_2  0x00000004U
#define FMC_BTR1_ADDSET_3  0x00000008U
#define FMC_BTR1_ADDHLD    0x000000F0U
#define FMC_BTR1_ADDHLD_0  0x00000010U
#define FMC_BTR1_ADDHLD_1  0x00000020U
#define FMC_BTR1_ADDHLD_2  0x00000040U
#define FMC_BTR1_ADDHLD_3  0x00000080U
#define FMC_BTR1_DATAST    0x0000FF00U
#define FMC_BTR1_DATAST_0  0x00000100U
#define FMC_BTR1_DATAST_1  0x00000200U
#define FMC_BTR1_DATAST_2  0x00000400U
#define FMC_BTR1_DATAST_3  0x00000800U
#define FMC_BTR1_DATAST_4  0x00001000U
#define FMC_BTR1_DATAST_5  0x00002000U
#define FMC_BTR1_DATAST_6  0x00004000U
#define FMC_BTR1_DATAST_7  0x00008000U
#define FMC_BTR1_BUSTURN   0x000F0000U
#define FMC_BTR1_BUSTURN_0 0x00010000U
#define FMC_BTR1_BUSTURN_1 0x00020000U
#define FMC_BTR1_BUSTURN_2 0x00040000U
#define FMC_BTR1_BUSTURN_3 0x00080000U
#define FMC_BTR1_CLKDIV    0x00F00000U
#define FMC_BTR1_CLKDIV_0  0x00100000U
#define FMC_BTR1_CLKDIV_1  0x00200000U
#define FMC_BTR1_CLKDIV_2  0x00400000U
#define FMC_BTR1_CLKDIV_3  0x00800000U
#define FMC_BTR1_DATLAT    0x0F000000U
#define FMC_BTR1_DATLAT_0  0x01000000U
#define FMC_BTR1_DATLAT_1  0x02000000U
#define FMC_BTR1_DATLAT_2  0x04000000U
#define FMC_BTR1_DATLAT_3  0x08000000U
#define FMC_BTR1_ACCMOD    0x30000000U
#define FMC_BTR1_ACCMOD_0  0x10000000U
#define FMC_BTR1_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_BTR2 register  *******************/
#define FMC_BTR2_ADDSET    0x0000000FU
#define FMC_BTR2_ADDSET_0  0x00000001U
#define FMC_BTR2_ADDSET_1  0x00000002U
#define FMC_BTR2_ADDSET_2  0x00000004U
#define FMC_BTR2_ADDSET_3  0x00000008U
#define FMC_BTR2_ADDHLD    0x000000F0U
#define FMC_BTR2_ADDHLD_0  0x00000010U
#define FMC_BTR2_ADDHLD_1  0x00000020U
#define FMC_BTR2_ADDHLD_2  0x00000040U
#define FMC_BTR2_ADDHLD_3  0x00000080U
#define FMC_BTR2_DATAST    0x0000FF00U
#define FMC_BTR2_DATAST_0  0x00000100U
#define FMC_BTR2_DATAST_1  0x00000200U
#define FMC_BTR2_DATAST_2  0x00000400U
#define FMC_BTR2_DATAST_3  0x00000800U
#define FMC_BTR2_DATAST_4  0x00001000U
#define FMC_BTR2_DATAST_5  0x00002000U
#define FMC_BTR2_DATAST_6  0x00004000U
#define FMC_BTR2_DATAST_7  0x00008000U
#define FMC_BTR2_BUSTURN   0x000F0000U
#define FMC_BTR2_BUSTURN_0 0x00010000U
#define FMC_BTR2_BUSTURN_1 0x00020000U
#define FMC_BTR2_BUSTURN_2 0x00040000U
#define FMC_BTR2_BUSTURN_3 0x00080000U
#define FMC_BTR2_CLKDIV    0x00F00000U
#define FMC_BTR2_CLKDIV_0  0x00100000U
#define FMC_BTR2_CLKDIV_1  0x00200000U
#define FMC_BTR2_CLKDIV_2  0x00400000U
#define FMC_BTR2_CLKDIV_3  0x00800000U
#define FMC_BTR2_DATLAT    0x0F000000U
#define FMC_BTR2_DATLAT_0  0x01000000U
#define FMC_BTR2_DATLAT_1  0x02000000U
#define FMC_BTR2_DATLAT_2  0x04000000U
#define FMC_BTR2_DATLAT_3  0x08000000U
#define FMC_BTR2_ACCMOD    0x30000000U
#define FMC_BTR2_ACCMOD_0  0x10000000U
#define FMC_BTR2_ACCMOD_1  0x20000000U
/*******************  Bit definition for FMC_BTR3 register  *******************/
#define FMC_BTR3_ADDSET    0x0000000FU
#define FMC_BTR3_ADDSET_0  0x00000001U
#define FMC_BTR3_ADDSET_1  0x00000002U
#define FMC_BTR3_ADDSET_2  0x00000004U
#define FMC_BTR3_ADDSET_3  0x00000008U
#define FMC_BTR3_ADDHLD    0x000000F0U
#define FMC_BTR3_ADDHLD_0  0x00000010U
#define FMC_BTR3_ADDHLD_1  0x00000020U
#define FMC_BTR3_ADDHLD_2  0x00000040U
#define FMC_BTR3_ADDHLD_3  0x00000080U
#define FMC_BTR3_DATAST    0x0000FF00U
#define FMC_BTR3_DATAST_0  0x00000100U
#define FMC_BTR3_DATAST_1  0x00000200U
#define FMC_BTR3_DATAST_2  0x00000400U
#define FMC_BTR3_DATAST_3  0x00000800U
#define FMC_BTR3_DATAST_4  0x00001000U
#define FMC_BTR3_DATAST_5  0x00002000U
#define FMC_BTR3_DATAST_6  0x00004000U
#define FMC_BTR3_DATAST_7  0x00008000U
#define FMC_BTR3_BUSTURN   0x000F0000U
#define FMC_BTR3_BUSTURN_0 0x00010000U
#define FMC_BTR3_BUSTURN_1 0x00020000U
#define FMC_BTR3_BUSTURN_2 0x00040000U
#define FMC_BTR3_BUSTURN_3 0x00080000U
#define FMC_BTR3_CLKDIV    0x00F00000U
#define FMC_BTR3_CLKDIV_0  0x00100000U
#define FMC_BTR3_CLKDIV_1  0x00200000U
#define FMC_BTR3_CLKDIV_2  0x00400000U
#define FMC_BTR3_CLKDIV_3  0x00800000U
#define FMC_BTR3_DATLAT    0x0F000000U
#define FMC_BTR3_DATLAT_0  0x01000000U
#define FMC_BTR3_DATLAT_1  0x02000000U
#define FMC_BTR3_DATLAT_2  0x04000000U
#define FMC_BTR3_DATLAT_3  0x08000000U
#define FMC_BTR3_ACCMOD    0x30000000U
#define FMC_BTR3_ACCMOD_0  0x10000000U
#define FMC_BTR3_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_BTR4 register  *******************/
#define FMC_BTR4_ADDSET    0x0000000FU
#define FMC_BTR4_ADDSET_0  0x00000001U
#define FMC_BTR4_ADDSET_1  0x00000002U
#define FMC_BTR4_ADDSET_2  0x00000004U
#define FMC_BTR4_ADDSET_3  0x00000008U
#define FMC_BTR4_ADDHLD    0x000000F0U
#define FMC_BTR4_ADDHLD_0  0x00000010U
#define FMC_BTR4_ADDHLD_1  0x00000020U
#define FMC_BTR4_ADDHLD_2  0x00000040U
#define FMC_BTR4_ADDHLD_3  0x00000080U
#define FMC_BTR4_DATAST    0x0000FF00U
#define FMC_BTR4_DATAST_0  0x00000100U
#define FMC_BTR4_DATAST_1  0x00000200U
#define FMC_BTR4_DATAST_2  0x00000400U
#define FMC_BTR4_DATAST_3  0x00000800U
#define FMC_BTR4_DATAST_4  0x00001000U
#define FMC_BTR4_DATAST_5  0x00002000U
#define FMC_BTR4_DATAST_6  0x00004000U
#define FMC_BTR4_DATAST_7  0x00008000U
#define FMC_BTR4_BUSTURN   0x000F0000U
#define FMC_BTR4_BUSTURN_0 0x00010000U
#define FMC_BTR4_BUSTURN_1 0x00020000U
#define FMC_BTR4_BUSTURN_2 0x00040000U
#define FMC_BTR4_BUSTURN_3 0x00080000U
#define FMC_BTR4_CLKDIV    0x00F00000U
#define FMC_BTR4_CLKDIV_0  0x00100000U
#define FMC_BTR4_CLKDIV_1  0x00200000U
#define FMC_BTR4_CLKDIV_2  0x00400000U
#define FMC_BTR4_CLKDIV_3  0x00800000U
#define FMC_BTR4_DATLAT    0x0F000000U
#define FMC_BTR4_DATLAT_0  0x01000000U
#define FMC_BTR4_DATLAT_1  0x02000000U
#define FMC_BTR4_DATLAT_2  0x04000000U
#define FMC_BTR4_DATLAT_3  0x08000000U
#define FMC_BTR4_ACCMOD    0x30000000U
#define FMC_BTR4_ACCMOD_0  0x10000000U
#define FMC_BTR4_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_BWTR1 register  ******************/
#define FMC_BWTR1_ADDSET    0x0000000FU
#define FMC_BWTR1_ADDSET_0  0x00000001U
#define FMC_BWTR1_ADDSET_1  0x00000002U
#define FMC_BWTR1_ADDSET_2  0x00000004U
#define FMC_BWTR1_ADDSET_3  0x00000008U
#define FMC_BWTR1_ADDHLD    0x000000F0U
#define FMC_BWTR1_ADDHLD_0  0x00000010U
#define FMC_BWTR1_ADDHLD_1  0x00000020U
#define FMC_BWTR1_ADDHLD_2  0x00000040U
#define FMC_BWTR1_ADDHLD_3  0x00000080U
#define FMC_BWTR1_DATAST    0x0000FF00U
#define FMC_BWTR1_DATAST_0  0x00000100U
#define FMC_BWTR1_DATAST_1  0x00000200U
#define FMC_BWTR1_DATAST_2  0x00000400U
#define FMC_BWTR1_DATAST_3  0x00000800U
#define FMC_BWTR1_DATAST_4  0x00001000U
#define FMC_BWTR1_DATAST_5  0x00002000U
#define FMC_BWTR1_DATAST_6  0x00004000U
#define FMC_BWTR1_DATAST_7  0x00008000U
#define FMC_BWTR1_BUSTURN   0x000F0000U
#define FMC_BWTR1_BUSTURN_0 0x00010000U
#define FMC_BWTR1_BUSTURN_1 0x00020000U
#define FMC_BWTR1_BUSTURN_2 0x00040000U
#define FMC_BWTR1_BUSTURN_3 0x00080000U
#define FMC_BWTR1_ACCMOD    0x30000000U
#define FMC_BWTR1_ACCMOD_0  0x10000000U
#define FMC_BWTR1_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_BWTR2 register  ******************/
#define FMC_BWTR2_ADDSET    0x0000000FU
#define FMC_BWTR2_ADDSET_0  0x00000001U
#define FMC_BWTR2_ADDSET_1  0x00000002U
#define FMC_BWTR2_ADDSET_2  0x00000004U
#define FMC_BWTR2_ADDSET_3  0x00000008U
#define FMC_BWTR2_ADDHLD    0x000000F0U
#define FMC_BWTR2_ADDHLD_0  0x00000010U
#define FMC_BWTR2_ADDHLD_1  0x00000020U
#define FMC_BWTR2_ADDHLD_2  0x00000040U
#define FMC_BWTR2_ADDHLD_3  0x00000080U
#define FMC_BWTR2_DATAST    0x0000FF00U
#define FMC_BWTR2_DATAST_0  0x00000100U
#define FMC_BWTR2_DATAST_1  0x00000200U
#define FMC_BWTR2_DATAST_2  0x00000400U
#define FMC_BWTR2_DATAST_3  0x00000800U
#define FMC_BWTR2_DATAST_4  0x00001000U
#define FMC_BWTR2_DATAST_5  0x00002000U
#define FMC_BWTR2_DATAST_6  0x00004000U
#define FMC_BWTR2_DATAST_7  0x00008000U
#define FMC_BWTR2_BUSTURN   0x000F0000U
#define FMC_BWTR2_BUSTURN_0 0x00010000U
#define FMC_BWTR2_BUSTURN_1 0x00020000U
#define FMC_BWTR2_BUSTURN_2 0x00040000U
#define FMC_BWTR2_BUSTURN_3 0x00080000U
#define FMC_BWTR2_ACCMOD    0x30000000U
#define FMC_BWTR2_ACCMOD_0  0x10000000U
#define FMC_BWTR2_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_BWTR3 register  ******************/
#define FMC_BWTR3_ADDSET    0x0000000FU
#define FMC_BWTR3_ADDSET_0  0x00000001U
#define FMC_BWTR3_ADDSET_1  0x00000002U
#define FMC_BWTR3_ADDSET_2  0x00000004U
#define FMC_BWTR3_ADDSET_3  0x00000008U
#define FMC_BWTR3_ADDHLD    0x000000F0U
#define FMC_BWTR3_ADDHLD_0  0x00000010U
#define FMC_BWTR3_ADDHLD_1  0x00000020U
#define FMC_BWTR3_ADDHLD_2  0x00000040U
#define FMC_BWTR3_ADDHLD_3  0x00000080U
#define FMC_BWTR3_DATAST    0x0000FF00U
#define FMC_BWTR3_DATAST_0  0x00000100U
#define FMC_BWTR3_DATAST_1  0x00000200U
#define FMC_BWTR3_DATAST_2  0x00000400U
#define FMC_BWTR3_DATAST_3  0x00000800U
#define FMC_BWTR3_DATAST_4  0x00001000U
#define FMC_BWTR3_DATAST_5  0x00002000U
#define FMC_BWTR3_DATAST_6  0x00004000U
#define FMC_BWTR3_DATAST_7  0x00008000U
#define FMC_BWTR3_BUSTURN   0x000F0000U
#define FMC_BWTR3_BUSTURN_0 0x00010000U
#define FMC_BWTR3_BUSTURN_1 0x00020000U
#define FMC_BWTR3_BUSTURN_2 0x00040000U
#define FMC_BWTR3_BUSTURN_3 0x00080000U
#define FMC_BWTR3_ACCMOD    0x30000000U
#define FMC_BWTR3_ACCMOD_0  0x10000000U
#define FMC_BWTR3_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_BWTR4 register  ******************/
#define FMC_BWTR4_ADDSET    0x0000000FU
#define FMC_BWTR4_ADDSET_0  0x00000001U
#define FMC_BWTR4_ADDSET_1  0x00000002U
#define FMC_BWTR4_ADDSET_2  0x00000004U
#define FMC_BWTR4_ADDSET_3  0x00000008U
#define FMC_BWTR4_ADDHLD    0x000000F0U
#define FMC_BWTR4_ADDHLD_0  0x00000010U
#define FMC_BWTR4_ADDHLD_1  0x00000020U
#define FMC_BWTR4_ADDHLD_2  0x00000040U
#define FMC_BWTR4_ADDHLD_3  0x00000080U
#define FMC_BWTR4_DATAST    0x0000FF00U
#define FMC_BWTR4_DATAST_0  0x00000100U
#define FMC_BWTR4_DATAST_1  0x00000200U
#define FMC_BWTR4_DATAST_2  0x00000400U
#define FMC_BWTR4_DATAST_3  0x00000800U
#define FMC_BWTR4_DATAST_4  0x00001000U
#define FMC_BWTR4_DATAST_5  0x00002000U
#define FMC_BWTR4_DATAST_6  0x00004000U
#define FMC_BWTR4_DATAST_7  0x00008000U
#define FMC_BWTR4_BUSTURN   0x000F0000U
#define FMC_BWTR4_BUSTURN_0 0x00010000U
#define FMC_BWTR4_BUSTURN_1 0x00020000U
#define FMC_BWTR4_BUSTURN_2 0x00040000U
#define FMC_BWTR4_BUSTURN_3 0x00080000U
#define FMC_BWTR4_ACCMOD    0x30000000U
#define FMC_BWTR4_ACCMOD_0  0x10000000U
#define FMC_BWTR4_ACCMOD_1  0x20000000U
/******************  Bit definition for FMC_PCR register  *******************/
#define FMC_PCR_PWAITEN 0x00000002U
#define FMC_PCR_PBKEN   0x00000004U
#define FMC_PCR_PTYP    0x00000008U
#define FMC_PCR_PWID    0x00000030U
#define FMC_PCR_PWID_0  0x00000010U
#define FMC_PCR_PWID_1  0x00000020U
#define FMC_PCR_ECCEN   0x00000040U
#define FMC_PCR_TCLR    0x00001E00U
#define FMC_PCR_TCLR_0  0x00000200U
#define FMC_PCR_TCLR_1  0x00000400U
#define FMC_PCR_TCLR_2  0x00000800U
#define FMC_PCR_TCLR_3  0x00001000U
#define FMC_PCR_TAR     0x0001E000U
#define FMC_PCR_TAR_0   0x00002000U
#define FMC_PCR_TAR_1   0x00004000U
#define FMC_PCR_TAR_2   0x00008000U
#define FMC_PCR_TAR_3   0x00010000U
#define FMC_PCR_ECCPS   0x000E0000U
#define FMC_PCR_ECCPS_0 0x00020000U
#define FMC_PCR_ECCPS_1 0x00040000U
#define FMC_PCR_ECCPS_2 0x00080000U
/*******************  Bit definition for FMC_SR register  *******************/
#define FMC_SR_IRS   0x01U
#define FMC_SR_ILS   0x02U
#define FMC_SR_IFS   0x04U
#define FMC_SR_IREN  0x08U
#define FMC_SR_ILEN  0x10U
#define FMC_SR_IFEN  0x20U
#define FMC_SR_FEMPT 0x40U
/******************  Bit definition for FMC_PMEM register  ******************/
#define FMC_PMEM_MEMSET2    0x000000FFU
#define FMC_PMEM_MEMSET2_0  0x00000001U
#define FMC_PMEM_MEMSET2_1  0x00000002U
#define FMC_PMEM_MEMSET2_2  0x00000004U
#define FMC_PMEM_MEMSET2_3  0x00000008U
#define FMC_PMEM_MEMSET2_4  0x00000010U
#define FMC_PMEM_MEMSET2_5  0x00000020U
#define FMC_PMEM_MEMSET2_6  0x00000040U
#define FMC_PMEM_MEMSET2_7  0x00000080U
#define FMC_PMEM_MEMWAIT2   0x0000FF00U
#define FMC_PMEM_MEMWAIT2_0 0x00000100U
#define FMC_PMEM_MEMWAIT2_1 0x00000200U
#define FMC_PMEM_MEMWAIT2_2 0x00000400U
#define FMC_PMEM_MEMWAIT2_3 0x00000800U
#define FMC_PMEM_MEMWAIT2_4 0x00001000U
#define FMC_PMEM_MEMWAIT2_5 0x00002000U
#define FMC_PMEM_MEMWAIT2_6 0x00004000U
#define FMC_PMEM_MEMWAIT2_7 0x00008000U
#define FMC_PMEM_MEMHOLD2   0x00FF0000U
#define FMC_PMEM_MEMHOLD2_0 0x00010000U
#define FMC_PMEM_MEMHOLD2_1 0x00020000U
#define FMC_PMEM_MEMHOLD2_2 0x00040000U
#define FMC_PMEM_MEMHOLD2_3 0x00080000U
#define FMC_PMEM_MEMHOLD2_4 0x00100000U
#define FMC_PMEM_MEMHOLD2_5 0x00200000U
#define FMC_PMEM_MEMHOLD2_6 0x00400000U
#define FMC_PMEM_MEMHOLD2_7 0x00800000U
#define FMC_PMEM_MEMHIZ2    0xFF000000U
#define FMC_PMEM_MEMHIZ2_0  0x01000000U
#define FMC_PMEM_MEMHIZ2_1  0x02000000U
#define FMC_PMEM_MEMHIZ2_2  0x04000000U
#define FMC_PMEM_MEMHIZ2_3  0x08000000U
#define FMC_PMEM_MEMHIZ2_4  0x10000000U
#define FMC_PMEM_MEMHIZ2_5  0x20000000U
#define FMC_PMEM_MEMHIZ2_6  0x40000000U
#define FMC_PMEM_MEMHIZ2_7  0x80000000U
/******************  Bit definition for FMC_PATT register  ******************/
#define FMC_PATT_ATTSET2    0x000000FFU
#define FMC_PATT_ATTSET2_0  0x00000001U
#define FMC_PATT_ATTSET2_1  0x00000002U
#define FMC_PATT_ATTSET2_2  0x00000004U
#define FMC_PATT_ATTSET2_3  0x00000008U
#define FMC_PATT_ATTSET2_4  0x00000010U
#define FMC_PATT_ATTSET2_5  0x00000020U
#define FMC_PATT_ATTSET2_6  0x00000040U
#define FMC_PATT_ATTSET2_7  0x00000080U
#define FMC_PATT_ATTWAIT2   0x0000FF00U
#define FMC_PATT_ATTWAIT2_0 0x00000100U
#define FMC_PATT_ATTWAIT2_1 0x00000200U
#define FMC_PATT_ATTWAIT2_2 0x00000400U
#define FMC_PATT_ATTWAIT2_3 0x00000800U
#define FMC_PATT_ATTWAIT2_4 0x00001000U
#define FMC_PATT_ATTWAIT2_5 0x00002000U
#define FMC_PATT_ATTWAIT2_6 0x00004000U
#define FMC_PATT_ATTWAIT2_7 0x00008000U
#define FMC_PATT_ATTHOLD2   0x00FF0000U
#define FMC_PATT_ATTHOLD2_0 0x00010000U
#define FMC_PATT_ATTHOLD2_1 0x00020000U
#define FMC_PATT_ATTHOLD2_2 0x00040000U
#define FMC_PATT_ATTHOLD2_3 0x00080000U
#define FMC_PATT_ATTHOLD2_4 0x00100000U
#define FMC_PATT_ATTHOLD2_5 0x00200000U
#define FMC_PATT_ATTHOLD2_6 0x00400000U
#define FMC_PATT_ATTHOLD2_7 0x00800000U
#define FMC_PATT_ATTHIZ2    0xFF000000U
#define FMC_PATT_ATTHIZ2_0  0x01000000U
#define FMC_PATT_ATTHIZ2_1  0x02000000U
#define FMC_PATT_ATTHIZ2_2  0x04000000U
#define FMC_PATT_ATTHIZ2_3  0x08000000U
#define FMC_PATT_ATTHIZ2_4  0x10000000U
#define FMC_PATT_ATTHIZ2_5  0x20000000U
#define FMC_PATT_ATTHIZ2_6  0x40000000U
#define FMC_PATT_ATTHIZ2_7  0x80000000U
/******************  Bit definition for FMC_ECCR register  ******************/
#define FMC_ECCR_ECC2 0xFFFFFFFFU
/******************  Bit definition for FMC_SDCR1 register  ******************/
#define FMC_SDCR1_NC      0x00000003U
#define FMC_SDCR1_NC_0    0x00000001U
#define FMC_SDCR1_NC_1    0x00000002U
#define FMC_SDCR1_NR      0x0000000CU
#define FMC_SDCR1_NR_0    0x00000004U
#define FMC_SDCR1_NR_1    0x00000008U
#define FMC_SDCR1_MWID    0x00000030U
#define FMC_SDCR1_MWID_0  0x00000010U
#define FMC_SDCR1_MWID_1  0x00000020U
#define FMC_SDCR1_NB      0x00000040U
#define FMC_SDCR1_CAS     0x00000180U
#define FMC_SDCR1_CAS_0   0x00000080U
#define FMC_SDCR1_CAS_1   0x00000100U
#define FMC_SDCR1_WP      0x00000200U
#define FMC_SDCR1_SDCLK   0x00000C00U
#define FMC_SDCR1_SDCLK_0 0x00000400U
#define FMC_SDCR1_SDCLK_1 0x00000800U
#define FMC_SDCR1_RBURST  0x00001000U
#define FMC_SDCR1_RPIPE   0x00006000U
#define FMC_SDCR1_RPIPE_0 0x00002000U
#define FMC_SDCR1_RPIPE_1 0x00004000U
/******************  Bit definition for FMC_SDCR2 register  ******************/
#define FMC_SDCR2_NC      0x00000003U
#define FMC_SDCR2_NC_0    0x00000001U
#define FMC_SDCR2_NC_1    0x00000002U
#define FMC_SDCR2_NR      0x0000000CU
#define FMC_SDCR2_NR_0    0x00000004U
#define FMC_SDCR2_NR_1    0x00000008U
#define FMC_SDCR2_MWID    0x00000030U
#define FMC_SDCR2_MWID_0  0x00000010U
#define FMC_SDCR2_MWID_1  0x00000020U
#define FMC_SDCR2_NB      0x00000040U
#define FMC_SDCR2_CAS     0x00000180U
#define FMC_SDCR2_CAS_0   0x00000080U
#define FMC_SDCR2_CAS_1   0x00000100U
#define FMC_SDCR2_WP      0x00000200U
#define FMC_SDCR2_SDCLK   0x00000C00U
#define FMC_SDCR2_SDCLK_0 0x00000400U
#define FMC_SDCR2_SDCLK_1 0x00000800U
#define FMC_SDCR2_RBURST  0x00001000U
#define FMC_SDCR2_RPIPE   0x00006000U
#define FMC_SDCR2_RPIPE_0 0x00002000U
#define FMC_SDCR2_RPIPE_1 0x00004000U
/******************  Bit definition for FMC_SDTR1 register  ******************/
#define FMC_SDTR1_TMRD   0x0000000FU
#define FMC_SDTR1_TMRD_0 0x00000001U
#define FMC_SDTR1_TMRD_1 0x00000002U
#define FMC_SDTR1_TMRD_2 0x00000004U
#define FMC_SDTR1_TMRD_3 0x00000008U
#define FMC_SDTR1_TXSR   0x000000F0U
#define FMC_SDTR1_TXSR_0 0x00000010U
#define FMC_SDTR1_TXSR_1 0x00000020U
#define FMC_SDTR1_TXSR_2 0x00000040U
#define FMC_SDTR1_TXSR_3 0x00000080U
#define FMC_SDTR1_TRAS   0x00000F00U
#define FMC_SDTR1_TRAS_0 0x00000100U
#define FMC_SDTR1_TRAS_1 0x00000200U
#define FMC_SDTR1_TRAS_2 0x00000400U
#define FMC_SDTR1_TRAS_3 0x00000800U
#define FMC_SDTR1_TRC    0x0000F000U
#define FMC_SDTR1_TRC_0  0x00001000U
#define FMC_SDTR1_TRC_1  0x00002000U
#define FMC_SDTR1_TRC_2  0x00004000U
#define FMC_SDTR1_TWR    0x000F0000U
#define FMC_SDTR1_TWR_0  0x00010000U
#define FMC_SDTR1_TWR_1  0x00020000U
#define FMC_SDTR1_TWR_2  0x00040000U
#define FMC_SDTR1_TRP    0x00F00000U
#define FMC_SDTR1_TRP_0  0x00100000U
#define FMC_SDTR1_TRP_1  0x00200000U
#define FMC_SDTR1_TRP_2  0x00400000U
#define FMC_SDTR1_TRCD   0x0F000000U
#define FMC_SDTR1_TRCD_0 0x01000000U
#define FMC_SDTR1_TRCD_1 0x02000000U
#define FMC_SDTR1_TRCD_2 0x04000000U
/******************  Bit definition for FMC_SDTR2 register  ******************/
#define FMC_SDTR2_TMRD   0x0000000FU
#define FMC_SDTR2_TMRD_0 0x00000001U
#define FMC_SDTR2_TMRD_1 0x00000002U
#define FMC_SDTR2_TMRD_2 0x00000004U
#define FMC_SDTR2_TMRD_3 0x00000008U
#define FMC_SDTR2_TXSR   0x000000F0U
#define FMC_SDTR2_TXSR_0 0x00000010U
#define FMC_SDTR2_TXSR_1 0x00000020U
#define FMC_SDTR2_TXSR_2 0x00000040U
#define FMC_SDTR2_TXSR_3 0x00000080U
#define FMC_SDTR2_TRAS   0x00000F00U
#define FMC_SDTR2_TRAS_0 0x00000100U
#define FMC_SDTR2_TRAS_1 0x00000200U
#define FMC_SDTR2_TRAS_2 0x00000400U
#define FMC_SDTR2_TRAS_3 0x00000800U
#define FMC_SDTR2_TRC    0x0000F000U
#define FMC_SDTR2_TRC_0  0x00001000U
#define FMC_SDTR2_TRC_1  0x00002000U
#define FMC_SDTR2_TRC_2  0x00004000U
#define FMC_SDTR2_TWR    0x000F0000U
#define FMC_SDTR2_TWR_0  0x00010000U
#define FMC_SDTR2_TWR_1  0x00020000U
#define FMC_SDTR2_TWR_2  0x00040000U
#define FMC_SDTR2_TRP    0x00F00000U
#define FMC_SDTR2_TRP_0  0x00100000U
#define FMC_SDTR2_TRP_1  0x00200000U
#define FMC_SDTR2_TRP_2  0x00400000U
#define FMC_SDTR2_TRCD   0x0F000000U
#define FMC_SDTR2_TRCD_0 0x01000000U
#define FMC_SDTR2_TRCD_1 0x02000000U
#define FMC_SDTR2_TRCD_2 0x04000000U
/******************  Bit definition for FMC_SDCMR register  ******************/
#define FMC_SDCMR_MODE   0x00000007U
#define FMC_SDCMR_MODE_0 0x00000001U
#define FMC_SDCMR_MODE_1 0x00000002U
#define FMC_SDCMR_MODE_2 0x00000004U
#define FMC_SDCMR_CTB2   0x00000008U
#define FMC_SDCMR_CTB1   0x00000010U
#define FMC_SDCMR_NRFS   0x000001E0U
#define FMC_SDCMR_NRFS_0 0x00000020U
#define FMC_SDCMR_NRFS_1 0x00000040U
#define FMC_SDCMR_NRFS_2 0x00000080U
#define FMC_SDCMR_NRFS_3 0x00000100U
#define FMC_SDCMR_MRD    0x003FFE00U
/******************  Bit definition for FMC_SDRTR register  ******************/
#define FMC_SDRTR_CRE   0x00000001U
#define FMC_SDRTR_COUNT 0x00003FFEU
#define FMC_SDRTR_REIE  0x00004000U
/******************  Bit definition for FMC_SDSR register  ******************/
#define FMC_SDSR_RE       0x00000001U
#define FMC_SDSR_MODES1   0x00000006U
#define FMC_SDSR_MODES1_0 0x00000002U
#define FMC_SDSR_MODES1_1 0x00000004U
#define FMC_SDSR_MODES2   0x00000018U
#define FMC_SDSR_MODES2_0 0x00000008U
#define FMC_SDSR_MODES2_1 0x00000010U
#define FMC_SDSR_BUSY     0x00000020U
/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0   0x00000003U
#define GPIO_MODER_MODER0_0 0x00000001U
#define GPIO_MODER_MODER0_1 0x00000002U

#define GPIO_MODER_MODER1   0x0000000CU
#define GPIO_MODER_MODER1_0 0x00000004U
#define GPIO_MODER_MODER1_1 0x00000008U

#define GPIO_MODER_MODER2   0x00000030U
#define GPIO_MODER_MODER2_0 0x00000010U
#define GPIO_MODER_MODER2_1 0x00000020U

#define GPIO_MODER_MODER3   0x000000C0U
#define GPIO_MODER_MODER3_0 0x00000040U
#define GPIO_MODER_MODER3_1 0x00000080U

#define GPIO_MODER_MODER4   0x00000300U
#define GPIO_MODER_MODER4_0 0x00000100U
#define GPIO_MODER_MODER4_1 0x00000200U

#define GPIO_MODER_MODER5   0x00000C00U
#define GPIO_MODER_MODER5_0 0x00000400U
#define GPIO_MODER_MODER5_1 0x00000800U

#define GPIO_MODER_MODER6   0x00003000U
#define GPIO_MODER_MODER6_0 0x00001000U
#define GPIO_MODER_MODER6_1 0x00002000U

#define GPIO_MODER_MODER7   0x0000C000U
#define GPIO_MODER_MODER7_0 0x00004000U
#define GPIO_MODER_MODER7_1 0x00008000U

#define GPIO_MODER_MODER8   0x00030000U
#define GPIO_MODER_MODER8_0 0x00010000U
#define GPIO_MODER_MODER8_1 0x00020000U

#define GPIO_MODER_MODER9   0x000C0000U
#define GPIO_MODER_MODER9_0 0x00040000U
#define GPIO_MODER_MODER9_1 0x00080000U

#define GPIO_MODER_MODER10   0x00300000U
#define GPIO_MODER_MODER10_0 0x00100000U
#define GPIO_MODER_MODER10_1 0x00200000U

#define GPIO_MODER_MODER11   0x00C00000U
#define GPIO_MODER_MODER11_0 0x00400000U
#define GPIO_MODER_MODER11_1 0x00800000U

#define GPIO_MODER_MODER12   0x03000000U
#define GPIO_MODER_MODER12_0 0x01000000U
#define GPIO_MODER_MODER12_1 0x02000000U

#define GPIO_MODER_MODER13   0x0C000000U
#define GPIO_MODER_MODER13_0 0x04000000U
#define GPIO_MODER_MODER13_1 0x08000000U

#define GPIO_MODER_MODER14   0x30000000U
#define GPIO_MODER_MODER14_0 0x10000000U
#define GPIO_MODER_MODER14_1 0x20000000U

#define GPIO_MODER_MODER15   0xC0000000U
#define GPIO_MODER_MODER15_0 0x40000000U
#define GPIO_MODER_MODER15_1 0x80000000U

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT_0  0x00000001U
#define GPIO_OTYPER_OT_1  0x00000002U
#define GPIO_OTYPER_OT_2  0x00000004U
#define GPIO_OTYPER_OT_3  0x00000008U
#define GPIO_OTYPER_OT_4  0x00000010U
#define GPIO_OTYPER_OT_5  0x00000020U
#define GPIO_OTYPER_OT_6  0x00000040U
#define GPIO_OTYPER_OT_7  0x00000080U
#define GPIO_OTYPER_OT_8  0x00000100U
#define GPIO_OTYPER_OT_9  0x00000200U
#define GPIO_OTYPER_OT_10 0x00000400U
#define GPIO_OTYPER_OT_11 0x00000800U
#define GPIO_OTYPER_OT_12 0x00001000U
#define GPIO_OTYPER_OT_13 0x00002000U
#define GPIO_OTYPER_OT_14 0x00004000U
#define GPIO_OTYPER_OT_15 0x00008000U

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDER_OSPEEDR0   0x00000003U
#define GPIO_OSPEEDER_OSPEEDR0_0 0x00000001U
#define GPIO_OSPEEDER_OSPEEDR0_1 0x00000002U

#define GPIO_OSPEEDER_OSPEEDR1   0x0000000CU
#define GPIO_OSPEEDER_OSPEEDR1_0 0x00000004U
#define GPIO_OSPEEDER_OSPEEDR1_1 0x00000008U

#define GPIO_OSPEEDER_OSPEEDR2   0x00000030U
#define GPIO_OSPEEDER_OSPEEDR2_0 0x00000010U
#define GPIO_OSPEEDER_OSPEEDR2_1 0x00000020U

#define GPIO_OSPEEDER_OSPEEDR3   0x000000C0U
#define GPIO_OSPEEDER_OSPEEDR3_0 0x00000040U
#define GPIO_OSPEEDER_OSPEEDR3_1 0x00000080U

#define GPIO_OSPEEDER_OSPEEDR4   0x00000300U
#define GPIO_OSPEEDER_OSPEEDR4_0 0x00000100U
#define GPIO_OSPEEDER_OSPEEDR4_1 0x00000200U

#define GPIO_OSPEEDER_OSPEEDR5   0x00000C00U
#define GPIO_OSPEEDER_OSPEEDR5_0 0x00000400U
#define GPIO_OSPEEDER_OSPEEDR5_1 0x00000800U

#define GPIO_OSPEEDER_OSPEEDR6   0x00003000U
#define GPIO_OSPEEDER_OSPEEDR6_0 0x00001000U
#define GPIO_OSPEEDER_OSPEEDR6_1 0x00002000U

#define GPIO_OSPEEDER_OSPEEDR7   0x0000C000U
#define GPIO_OSPEEDER_OSPEEDR7_0 0x00004000U
#define GPIO_OSPEEDER_OSPEEDR7_1 0x00008000U

#define GPIO_OSPEEDER_OSPEEDR8   0x00030000U
#define GPIO_OSPEEDER_OSPEEDR8_0 0x00010000U
#define GPIO_OSPEEDER_OSPEEDR8_1 0x00020000U

#define GPIO_OSPEEDER_OSPEEDR9   0x000C0000U
#define GPIO_OSPEEDER_OSPEEDR9_0 0x00040000U
#define GPIO_OSPEEDER_OSPEEDR9_1 0x00080000U

#define GPIO_OSPEEDER_OSPEEDR10   0x00300000U
#define GPIO_OSPEEDER_OSPEEDR10_0 0x00100000U
#define GPIO_OSPEEDER_OSPEEDR10_1 0x00200000U

#define GPIO_OSPEEDER_OSPEEDR11   0x00C00000U
#define GPIO_OSPEEDER_OSPEEDR11_0 0x00400000U
#define GPIO_OSPEEDER_OSPEEDR11_1 0x00800000U

#define GPIO_OSPEEDER_OSPEEDR12   0x03000000U
#define GPIO_OSPEEDER_OSPEEDR12_0 0x01000000U
#define GPIO_OSPEEDER_OSPEEDR12_1 0x02000000U

#define GPIO_OSPEEDER_OSPEEDR13   0x0C000000U
#define GPIO_OSPEEDER_OSPEEDR13_0 0x04000000U
#define GPIO_OSPEEDER_OSPEEDR13_1 0x08000000U

#define GPIO_OSPEEDER_OSPEEDR14   0x30000000U
#define GPIO_OSPEEDER_OSPEEDR14_0 0x10000000U
#define GPIO_OSPEEDER_OSPEEDR14_1 0x20000000U

#define GPIO_OSPEEDER_OSPEEDR15   0xC0000000U
#define GPIO_OSPEEDER_OSPEEDR15_0 0x40000000U
#define GPIO_OSPEEDER_OSPEEDR15_1 0x80000000U

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPDR0   0x00000003U
#define GPIO_PUPDR_PUPDR0_0 0x00000001U
#define GPIO_PUPDR_PUPDR0_1 0x00000002U

#define GPIO_PUPDR_PUPDR1   0x0000000CU
#define GPIO_PUPDR_PUPDR1_0 0x00000004U
#define GPIO_PUPDR_PUPDR1_1 0x00000008U

#define GPIO_PUPDR_PUPDR2   0x00000030U
#define GPIO_PUPDR_PUPDR2_0 0x00000010U
#define GPIO_PUPDR_PUPDR2_1 0x00000020U

#define GPIO_PUPDR_PUPDR3   0x000000C0U
#define GPIO_PUPDR_PUPDR3_0 0x00000040U
#define GPIO_PUPDR_PUPDR3_1 0x00000080U

#define GPIO_PUPDR_PUPDR4   0x00000300U
#define GPIO_PUPDR_PUPDR4_0 0x00000100U
#define GPIO_PUPDR_PUPDR4_1 0x00000200U

#define GPIO_PUPDR_PUPDR5   0x00000C00U
#define GPIO_PUPDR_PUPDR5_0 0x00000400U
#define GPIO_PUPDR_PUPDR5_1 0x00000800U

#define GPIO_PUPDR_PUPDR6   0x00003000U
#define GPIO_PUPDR_PUPDR6_0 0x00001000U
#define GPIO_PUPDR_PUPDR6_1 0x00002000U

#define GPIO_PUPDR_PUPDR7   0x0000C000U
#define GPIO_PUPDR_PUPDR7_0 0x00004000U
#define GPIO_PUPDR_PUPDR7_1 0x00008000U

#define GPIO_PUPDR_PUPDR8   0x00030000U
#define GPIO_PUPDR_PUPDR8_0 0x00010000U
#define GPIO_PUPDR_PUPDR8_1 0x00020000U

#define GPIO_PUPDR_PUPDR9   0x000C0000U
#define GPIO_PUPDR_PUPDR9_0 0x00040000U
#define GPIO_PUPDR_PUPDR9_1 0x00080000U

#define GPIO_PUPDR_PUPDR10   0x00300000U
#define GPIO_PUPDR_PUPDR10_0 0x00100000U
#define GPIO_PUPDR_PUPDR10_1 0x00200000U

#define GPIO_PUPDR_PUPDR11   0x00C00000U
#define GPIO_PUPDR_PUPDR11_0 0x00400000U
#define GPIO_PUPDR_PUPDR11_1 0x00800000U

#define GPIO_PUPDR_PUPDR12   0x03000000U
#define GPIO_PUPDR_PUPDR12_0 0x01000000U
#define GPIO_PUPDR_PUPDR12_1 0x02000000U

#define GPIO_PUPDR_PUPDR13   0x0C000000U
#define GPIO_PUPDR_PUPDR13_0 0x04000000U
#define GPIO_PUPDR_PUPDR13_1 0x08000000U

#define GPIO_PUPDR_PUPDR14   0x30000000U
#define GPIO_PUPDR_PUPDR14_0 0x10000000U
#define GPIO_PUPDR_PUPDR14_1 0x20000000U

#define GPIO_PUPDR_PUPDR15   0xC0000000U
#define GPIO_PUPDR_PUPDR15_0 0x40000000U
#define GPIO_PUPDR_PUPDR15_1 0x80000000U

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR_0  0x00000001U
#define GPIO_IDR_IDR_1  0x00000002U
#define GPIO_IDR_IDR_2  0x00000004U
#define GPIO_IDR_IDR_3  0x00000008U
#define GPIO_IDR_IDR_4  0x00000010U
#define GPIO_IDR_IDR_5  0x00000020U
#define GPIO_IDR_IDR_6  0x00000040U
#define GPIO_IDR_IDR_7  0x00000080U
#define GPIO_IDR_IDR_8  0x00000100U
#define GPIO_IDR_IDR_9  0x00000200U
#define GPIO_IDR_IDR_10 0x00000400U
#define GPIO_IDR_IDR_11 0x00000800U
#define GPIO_IDR_IDR_12 0x00001000U
#define GPIO_IDR_IDR_13 0x00002000U
#define GPIO_IDR_IDR_14 0x00004000U
#define GPIO_IDR_IDR_15 0x00008000U
/* Old GPIO_IDR register bits definition, maintained for legacy purpose */
#define GPIO_OTYPER_IDR_0  GPIO_IDR_IDR_0
#define GPIO_OTYPER_IDR_1  GPIO_IDR_IDR_1
#define GPIO_OTYPER_IDR_2  GPIO_IDR_IDR_2
#define GPIO_OTYPER_IDR_3  GPIO_IDR_IDR_3
#define GPIO_OTYPER_IDR_4  GPIO_IDR_IDR_4
#define GPIO_OTYPER_IDR_5  GPIO_IDR_IDR_5
#define GPIO_OTYPER_IDR_6  GPIO_IDR_IDR_6
#define GPIO_OTYPER_IDR_7  GPIO_IDR_IDR_7
#define GPIO_OTYPER_IDR_8  GPIO_IDR_IDR_8
#define GPIO_OTYPER_IDR_9  GPIO_IDR_IDR_9
#define GPIO_OTYPER_IDR_10 GPIO_IDR_IDR_10
#define GPIO_OTYPER_IDR_11 GPIO_IDR_IDR_11
#define GPIO_OTYPER_IDR_12 GPIO_IDR_IDR_12
#define GPIO_OTYPER_IDR_13 GPIO_IDR_IDR_13
#define GPIO_OTYPER_IDR_14 GPIO_IDR_IDR_14
#define GPIO_OTYPER_IDR_15 GPIO_IDR_IDR_15

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR_0  0x00000001U
#define GPIO_ODR_ODR_1  0x00000002U
#define GPIO_ODR_ODR_2  0x00000004U
#define GPIO_ODR_ODR_3  0x00000008U
#define GPIO_ODR_ODR_4  0x00000010U
#define GPIO_ODR_ODR_5  0x00000020U
#define GPIO_ODR_ODR_6  0x00000040U
#define GPIO_ODR_ODR_7  0x00000080U
#define GPIO_ODR_ODR_8  0x00000100U
#define GPIO_ODR_ODR_9  0x00000200U
#define GPIO_ODR_ODR_10 0x00000400U
#define GPIO_ODR_ODR_11 0x00000800U
#define GPIO_ODR_ODR_12 0x00001000U
#define GPIO_ODR_ODR_13 0x00002000U
#define GPIO_ODR_ODR_14 0x00004000U
#define GPIO_ODR_ODR_15 0x00008000U
/* Old GPIO_ODR register bits definition, maintained for legacy purpose */
#define GPIO_OTYPER_ODR_0  GPIO_ODR_ODR_0
#define GPIO_OTYPER_ODR_1  GPIO_ODR_ODR_1
#define GPIO_OTYPER_ODR_2  GPIO_ODR_ODR_2
#define GPIO_OTYPER_ODR_3  GPIO_ODR_ODR_3
#define GPIO_OTYPER_ODR_4  GPIO_ODR_ODR_4
#define GPIO_OTYPER_ODR_5  GPIO_ODR_ODR_5
#define GPIO_OTYPER_ODR_6  GPIO_ODR_ODR_6
#define GPIO_OTYPER_ODR_7  GPIO_ODR_ODR_7
#define GPIO_OTYPER_ODR_8  GPIO_ODR_ODR_8
#define GPIO_OTYPER_ODR_9  GPIO_ODR_ODR_9
#define GPIO_OTYPER_ODR_10 GPIO_ODR_ODR_10
#define GPIO_OTYPER_ODR_11 GPIO_ODR_ODR_11
#define GPIO_OTYPER_ODR_12 GPIO_ODR_ODR_12
#define GPIO_OTYPER_ODR_13 GPIO_ODR_ODR_13
#define GPIO_OTYPER_ODR_14 GPIO_ODR_ODR_14
#define GPIO_OTYPER_ODR_15 GPIO_ODR_ODR_15

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS_0  0x00000001U
#define GPIO_BSRR_BS_1  0x00000002U
#define GPIO_BSRR_BS_2  0x00000004U
#define GPIO_BSRR_BS_3  0x00000008U
#define GPIO_BSRR_BS_4  0x00000010U
#define GPIO_BSRR_BS_5  0x00000020U
#define GPIO_BSRR_BS_6  0x00000040U
#define GPIO_BSRR_BS_7  0x00000080U
#define GPIO_BSRR_BS_8  0x00000100U
#define GPIO_BSRR_BS_9  0x00000200U
#define GPIO_BSRR_BS_10 0x00000400U
#define GPIO_BSRR_BS_11 0x00000800U
#define GPIO_BSRR_BS_12 0x00001000U
#define GPIO_BSRR_BS_13 0x00002000U
#define GPIO_BSRR_BS_14 0x00004000U
#define GPIO_BSRR_BS_15 0x00008000U
#define GPIO_BSRR_BR_0  0x00010000U
#define GPIO_BSRR_BR_1  0x00020000U
#define GPIO_BSRR_BR_2  0x00040000U
#define GPIO_BSRR_BR_3  0x00080000U
#define GPIO_BSRR_BR_4  0x00100000U
#define GPIO_BSRR_BR_5  0x00200000U
#define GPIO_BSRR_BR_6  0x00400000U
#define GPIO_BSRR_BR_7  0x00800000U
#define GPIO_BSRR_BR_8  0x01000000U
#define GPIO_BSRR_BR_9  0x02000000U
#define GPIO_BSRR_BR_10 0x04000000U
#define GPIO_BSRR_BR_11 0x08000000U
#define GPIO_BSRR_BR_12 0x10000000U
#define GPIO_BSRR_BR_13 0x20000000U
#define GPIO_BSRR_BR_14 0x40000000U
#define GPIO_BSRR_BR_15 0x80000000U

/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0  0x00000001U
#define GPIO_LCKR_LCK1  0x00000002U
#define GPIO_LCKR_LCK2  0x00000004U
#define GPIO_LCKR_LCK3  0x00000008U
#define GPIO_LCKR_LCK4  0x00000010U
#define GPIO_LCKR_LCK5  0x00000020U
#define GPIO_LCKR_LCK6  0x00000040U
#define GPIO_LCKR_LCK7  0x00000080U
#define GPIO_LCKR_LCK8  0x00000100U
#define GPIO_LCKR_LCK9  0x00000200U
#define GPIO_LCKR_LCK10 0x00000400U
#define GPIO_LCKR_LCK11 0x00000800U
#define GPIO_LCKR_LCK12 0x00001000U
#define GPIO_LCKR_LCK13 0x00002000U
#define GPIO_LCKR_LCK14 0x00004000U
#define GPIO_LCKR_LCK15 0x00008000U
#define GPIO_LCKR_LCKK  0x00010000U

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface                    */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE        0x00000001U
#define I2C_CR1_SMBUS     0x00000002U
#define I2C_CR1_SMBTYPE   0x00000008U
#define I2C_CR1_ENARP     0x00000010U
#define I2C_CR1_ENPEC     0x00000020U
#define I2C_CR1_ENGC      0x00000040U
#define I2C_CR1_NOSTRETCH 0x00000080U
#define I2C_CR1_START     0x00000100U
#define I2C_CR1_STOP      0x00000200U
#define I2C_CR1_ACK       0x00000400U
#define I2C_CR1_POS       0x00000800U
#define I2C_CR1_PEC       0x00001000U
#define I2C_CR1_ALERT     0x00002000U
#define I2C_CR1_SWRST     0x00008000U
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ    0x0000003FU
#define I2C_CR2_FREQ_0  0x00000001U
#define I2C_CR2_FREQ_1  0x00000002U
#define I2C_CR2_FREQ_2  0x00000004U
#define I2C_CR2_FREQ_3  0x00000008U
#define I2C_CR2_FREQ_4  0x00000010U
#define I2C_CR2_FREQ_5  0x00000020U
#define I2C_CR2_ITERREN 0x00000100U
#define I2C_CR2_ITEVTEN 0x00000200U
#define I2C_CR2_ITBUFEN 0x00000400U
#define I2C_CR2_DMAEN   0x00000800U
#define I2C_CR2_LAST    0x00001000U
/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADD1_7  0x000000FEU
#define I2C_OAR1_ADD8_9  0x00000300U
#define I2C_OAR1_ADD0    0x00000001U
#define I2C_OAR1_ADD1    0x00000002U
#define I2C_OAR1_ADD2    0x00000004U
#define I2C_OAR1_ADD3    0x00000008U
#define I2C_OAR1_ADD4    0x00000010U
#define I2C_OAR1_ADD5    0x00000020U
#define I2C_OAR1_ADD6    0x00000040U
#define I2C_OAR1_ADD7    0x00000080U
#define I2C_OAR1_ADD8    0x00000100U
#define I2C_OAR1_ADD9    0x00000200U
#define I2C_OAR1_ADDMODE 0x00008000U
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL 0x00000001U
#define I2C_OAR2_ADD2   0x000000FEU
/********************  Bit definition for I2C_DR register  ********************/
#define I2C_DR_DR 0x000000FFU
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB       0x00000001U
#define I2C_SR1_ADDR     0x00000002U
#define I2C_SR1_BTF      0x00000004U
#define I2C_SR1_ADD10    0x00000008U
#define I2C_SR1_STOPF    0x00000010U
#define I2C_SR1_RXNE     0x00000040U
#define I2C_SR1_TXE      0x00000080U
#define I2C_SR1_BERR     0x00000100U
#define I2C_SR1_ARLO     0x00000200U
#define I2C_SR1_AF       0x00000400U
#define I2C_SR1_OVR      0x00000800U
#define I2C_SR1_PECERR   0x00001000U
#define I2C_SR1_TIMEOUT  0x00004000U
#define I2C_SR1_SMBALERT 0x00008000U
/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL        0x00000001U
#define I2C_SR2_BUSY       0x00000002U
#define I2C_SR2_TRA        0x00000004U
#define I2C_SR2_GENCALL    0x00000010U
#define I2C_SR2_SMBDEFAULT 0x00000020U
#define I2C_SR2_SMBHOST    0x00000040U
#define I2C_SR2_DUALF      0x00000080U
#define I2C_SR2_PEC        0x0000FF00U
/*******************  Bit definition for I2C_CCR register  ********************/
#define I2C_CCR_CCR  0x00000FFFU
#define I2C_CCR_DUTY 0x00004000U
#define I2C_CCR_FS   0x00008000U
/******************  Bit definition for I2C_TRISE register  *******************/
#define I2C_TRISE_TRISE 0x0000003FU
/******************  Bit definition for I2C_FLTR register  *******************/
#define I2C_FLTR_DNF   0x0000000FU
#define I2C_FLTR_ANOFF 0x00000010U
/******************************************************************************/
/*                                                                            */
/*        Fast Mode Plus Inter-integrated Circuit Interface (I2C)             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  *******************/
#define FMPI2C_CR1_PE        0x00000001U
#define FMPI2C_CR1_TXIE      0x00000002U
#define FMPI2C_CR1_RXIE      0x00000004U
#define FMPI2C_CR1_ADDRIE    0x00000008U
#define FMPI2C_CR1_NACKIE    0x00000010U
#define FMPI2C_CR1_STOPIE    0x00000020U
#define FMPI2C_CR1_TCIE      0x00000040U
#define FMPI2C_CR1_ERRIE     0x00000080U
#define FMPI2C_CR1_DFN       0x00000F00U
#define FMPI2C_CR1_ANFOFF    0x00001000U
#define FMPI2C_CR1_TXDMAEN   0x00004000U
#define FMPI2C_CR1_RXDMAEN   0x00008000U
#define FMPI2C_CR1_SBC       0x00010000U
#define FMPI2C_CR1_NOSTRETCH 0x00020000U
#define FMPI2C_CR1_GCEN      0x00080000U
#define FMPI2C_CR1_SMBHEN    0x00100000U
#define FMPI2C_CR1_SMBDEN    0x00200000U
#define FMPI2C_CR1_ALERTEN   0x00400000U
#define FMPI2C_CR1_PECEN     0x00800000U
/******************  Bit definition for I2C_CR2 register  ********************/
#define FMPI2C_CR2_SADD    0x000003FFU
#define FMPI2C_CR2_RD_WRN  0x00000400U
#define FMPI2C_CR2_ADD10   0x00000800U
#define FMPI2C_CR2_HEAD10R 0x00001000U
#define FMPI2C_CR2_START   0x00002000U
#define FMPI2C_CR2_STOP    0x00004000U
#define FMPI2C_CR2_NACK    0x00008000U
#define FMPI2C_CR2_NBYTES  0x00FF0000U
#define FMPI2C_CR2_RELOAD  0x01000000U
#define FMPI2C_CR2_AUTOEND 0x02000000U
#define FMPI2C_CR2_PECBYTE 0x04000000U
/*******************  Bit definition for I2C_OAR1 register  ******************/
#define FMPI2C_OAR1_OA1     0x000003FFU
#define FMPI2C_OAR1_OA1MODE 0x00000400U
#define FMPI2C_OAR1_OA1EN   0x00008000U
/*******************  Bit definition for I2C_OAR2 register  ******************/
#define FMPI2C_OAR2_OA2    0x000000FEU
#define FMPI2C_OAR2_OA2MSK 0x00000700U
#define FMPI2C_OAR2_OA2EN  0x00008000U
/*******************  Bit definition for I2C_TIMINGR register *******************/
#define FMPI2C_TIMINGR_SCLL   0x000000FFU
#define FMPI2C_TIMINGR_SCLH   0x0000FF00U
#define FMPI2C_TIMINGR_SDADEL 0x000F0000U
#define FMPI2C_TIMINGR_SCLDEL 0x00F00000U
#define FMPI2C_TIMINGR_PRESC  0xF0000000U
/******************* Bit definition for I2C_TIMEOUTR register *******************/
#define FMPI2C_TIMEOUTR_TIMEOUTA 0x00000FFFU
#define FMPI2C_TIMEOUTR_TIDLE    0x00001000U
#define FMPI2C_TIMEOUTR_TIMOUTEN 0x00008000U
#define FMPI2C_TIMEOUTR_TIMEOUTB 0x0FFF0000U
#define FMPI2C_TIMEOUTR_TEXTEN   0x80000000U
/******************  Bit definition for I2C_ISR register  *********************/
#define FMPI2C_ISR_TXE     0x00000001U
#define FMPI2C_ISR_TXIS    0x00000002U
#define FMPI2C_ISR_RXNE    0x00000004U
#define FMPI2C_ISR_ADDR    0x00000008U
#define FMPI2C_ISR_NACKF   0x00000010U
#define FMPI2C_ISR_STOPF   0x00000020U
#define FMPI2C_ISR_TC      0x00000040U
#define FMPI2C_ISR_TCR     0x00000080U
#define FMPI2C_ISR_BERR    0x00000100U
#define FMPI2C_ISR_ARLO    0x00000200U
#define FMPI2C_ISR_OVR     0x00000400U
#define FMPI2C_ISR_PECERR  0x00000800U
#define FMPI2C_ISR_TIMEOUT 0x00001000U
#define FMPI2C_ISR_ALERT   0x00002000U
#define FMPI2C_ISR_BUSY    0x00008000U
#define FMPI2C_ISR_DIR     0x00010000U
#define FMPI2C_ISR_ADDCODE 0x00FE0000U
/******************  Bit definition for I2C_ICR register  *********************/
#define FMPI2C_ICR_ADDRCF   0x00000008U
#define FMPI2C_ICR_NACKCF   0x00000010U
#define FMPI2C_ICR_STOPCF   0x00000020U
#define FMPI2C_ICR_BERRCF   0x00000100U
#define FMPI2C_ICR_ARLOCF   0x00000200U
#define FMPI2C_ICR_OVRCF    0x00000400U
#define FMPI2C_ICR_PECCF    0x00000800U
#define FMPI2C_ICR_TIMOUTCF 0x00001000U
#define FMPI2C_ICR_ALERTCF  0x00002000U
/******************  Bit definition for I2C_PECR register  *********************/
#define FMPI2C_PECR_PEC 0x000000FFU
/******************  Bit definition for I2C_RXDR register  *********************/
#define FMPI2C_RXDR_RXDATA 0x000000FFU
/******************  Bit definition for I2C_TXDR register  *********************/
#define FMPI2C_TXDR_TXDATA 0x000000FFU
/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY 0xFFFFU
/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR   0x07U
#define IWDG_PR_PR_0 0x01U
#define IWDG_PR_PR_1 0x02U
#define IWDG_PR_PR_2 0x04U
/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL 0x0FFFU
/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU 0x01U
#define IWDG_SR_RVU 0x02U
/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR register  ********************/
#define PWR_CR_LPDS     0x00000001U
#define PWR_CR_PDDS     0x00000002U
#define PWR_CR_CWUF     0x00000004U
#define PWR_CR_CSBF     0x00000008U
#define PWR_CR_PVDE     0x00000010U
#define PWR_CR_PLS      0x000000E0U
#define PWR_CR_PLS_0    0x00000020U
#define PWR_CR_PLS_1    0x00000040U
#define PWR_CR_PLS_2    0x00000080U
#define PWR_CR_PLS_LEV0 0x00000000U
#define PWR_CR_PLS_LEV1 0x00000020U
#define PWR_CR_PLS_LEV2 0x00000040U
#define PWR_CR_PLS_LEV3 0x00000060U
#define PWR_CR_PLS_LEV4 0x00000080U
#define PWR_CR_PLS_LEV5 0x000000A0U
#define PWR_CR_PLS_LEV6 0x000000C0U
#define PWR_CR_PLS_LEV7 0x000000E0U
#define PWR_CR_DBP      0x00000100U
#define PWR_CR_FPDS     0x00000200U
#define PWR_CR_LPLVDS   0x00000400U
#define PWR_CR_MRLVDS   0x00000800U
#define PWR_CR_ADCDC1   0x00002000U
#define PWR_CR_VOS      0x0000C000U
#define PWR_CR_VOS_0    0x00004000U
#define PWR_CR_VOS_1    0x00008000U
#define PWR_CR_ODEN     0x00010000U
#define PWR_CR_ODSWEN   0x00020000U
#define PWR_CR_UDEN     0x000C0000U
#define PWR_CR_UDEN_0   0x00040000U
#define PWR_CR_UDEN_1   0x00080000U
#define PWR_CR_FMSSR    0x00100000U
#define PWR_CR_FISSR    0x00200000U
/* Legacy define */
#define PWR_CR_PMODE PWR_CR_VOS
#define PWR_CR_LPUDS PWR_CR_LPLVDS
#define PWR_CR_MRUDS PWR_CR_MRLVDS
/*******************  Bit definition for PWR_CSR register  ********************/
#define PWR_CSR_WUF     0x00000001U
#define PWR_CSR_SBF     0x00000002U
#define PWR_CSR_PVDO    0x00000004U
#define PWR_CSR_BRR     0x00000008U
#define PWR_CSR_EWUP2   0x00000080U
#define PWR_CSR_EWUP1   0x00000100U
#define PWR_CSR_BRE     0x00000200U
#define PWR_CSR_VOSRDY  0x00004000U
#define PWR_CSR_ODRDY   0x00010000U
#define PWR_CSR_ODSWRDY 0x00020000U
#define PWR_CSR_UDSWRDY 0x000C0000U
/* Legacy define */
#define PWR_CSR_REGRDY PWR_CSR_VOSRDY

/******************************************************************************/
/*                                                                            */
/*                                    QUADSPI                                 */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for QUADSPI_CR register  *******************/
#define QUADSPI_CR_EN          0x00000001U
#define QUADSPI_CR_ABORT       0x00000002U
#define QUADSPI_CR_DMAEN       0x00000004U
#define QUADSPI_CR_TCEN        0x00000008U
#define QUADSPI_CR_SSHIFT      0x00000010U
#define QUADSPI_CR_DFM         0x00000040U
#define QUADSPI_CR_FSEL        0x00000080U
#define QUADSPI_CR_FTHRES      0x00001F00U
#define QUADSPI_CR_FTHRES_0    0x00000100U
#define QUADSPI_CR_FTHRES_1    0x00000200U
#define QUADSPI_CR_FTHRES_2    0x00000400U
#define QUADSPI_CR_FTHRES_3    0x00000800U
#define QUADSPI_CR_FTHRES_4    0x00001000U
#define QUADSPI_CR_TEIE        0x00010000U
#define QUADSPI_CR_TCIE        0x00020000U
#define QUADSPI_CR_FTIE        0x00040000U
#define QUADSPI_CR_SMIE        0x00080000U
#define QUADSPI_CR_TOIE        0x00100000U
#define QUADSPI_CR_APMS        0x00400000U
#define QUADSPI_CR_PMM         0x00800000U
#define QUADSPI_CR_PRESCALER   0xFF000000U
#define QUADSPI_CR_PRESCALER_0 0x01000000U
#define QUADSPI_CR_PRESCALER_1 0x02000000U
#define QUADSPI_CR_PRESCALER_2 0x04000000U
#define QUADSPI_CR_PRESCALER_3 0x08000000U
#define QUADSPI_CR_PRESCALER_4 0x10000000U
#define QUADSPI_CR_PRESCALER_5 0x20000000U
#define QUADSPI_CR_PRESCALER_6 0x40000000U
#define QUADSPI_CR_PRESCALER_7 0x80000000U
/*****************  Bit definition for QUADSPI_DCR register  ******************/
#define QUADSPI_DCR_CKMODE  0x00000001U
#define QUADSPI_DCR_CSHT    0x00000700U
#define QUADSPI_DCR_CSHT_0  0x00000100U
#define QUADSPI_DCR_CSHT_1  0x00000200U
#define QUADSPI_DCR_CSHT_2  0x00000400U
#define QUADSPI_DCR_FSIZE   0x001F0000U
#define QUADSPI_DCR_FSIZE_0 0x00010000U
#define QUADSPI_DCR_FSIZE_1 0x00020000U
#define QUADSPI_DCR_FSIZE_2 0x00040000U
#define QUADSPI_DCR_FSIZE_3 0x00080000U
#define QUADSPI_DCR_FSIZE_4 0x00100000U
/******************  Bit definition for QUADSPI_SR register  *******************/
#define QUADSPI_SR_TEF      0x00000001U
#define QUADSPI_SR_TCF      0x00000002U
#define QUADSPI_SR_FTF      0x00000004U
#define QUADSPI_SR_SMF      0x00000008U
#define QUADSPI_SR_TOF      0x00000010U
#define QUADSPI_SR_BUSY     0x00000020U
#define QUADSPI_SR_FLEVEL   0x00003F00U
#define QUADSPI_SR_FLEVEL_0 0x00000100U
#define QUADSPI_SR_FLEVEL_1 0x00000200U
#define QUADSPI_SR_FLEVEL_2 0x00000400U
#define QUADSPI_SR_FLEVEL_3 0x00000800U
#define QUADSPI_SR_FLEVEL_4 0x00001000U
#define QUADSPI_SR_FLEVEL_5 0x00002000U
/******************  Bit definition for QUADSPI_FCR register  ******************/
#define QUADSPI_FCR_CTEF 0x00000001U
#define QUADSPI_FCR_CTCF 0x00000002U
#define QUADSPI_FCR_CSMF 0x00000008U
#define QUADSPI_FCR_CTOF 0x00000010U
/******************  Bit definition for QUADSPI_DLR register  ******************/
#define QUADSPI_DLR_DL 0xFFFFFFFFU
/******************  Bit definition for QUADSPI_CCR register  ******************/
#define QUADSPI_CCR_INSTRUCTION   0x000000FFU
#define QUADSPI_CCR_INSTRUCTION_0 0x00000001U
#define QUADSPI_CCR_INSTRUCTION_1 0x00000002U
#define QUADSPI_CCR_INSTRUCTION_2 0x00000004U
#define QUADSPI_CCR_INSTRUCTION_3 0x00000008U
#define QUADSPI_CCR_INSTRUCTION_4 0x00000010U
#define QUADSPI_CCR_INSTRUCTION_5 0x00000020U
#define QUADSPI_CCR_INSTRUCTION_6 0x00000040U
#define QUADSPI_CCR_INSTRUCTION_7 0x00000080U
#define QUADSPI_CCR_IMODE         0x00000300U
#define QUADSPI_CCR_IMODE_0       0x00000100U
#define QUADSPI_CCR_IMODE_1       0x00000200U
#define QUADSPI_CCR_ADMODE        0x00000C00U
#define QUADSPI_CCR_ADMODE_0      0x00000400U
#define QUADSPI_CCR_ADMODE_1      0x00000800U
#define QUADSPI_CCR_ADSIZE        0x00003000U
#define QUADSPI_CCR_ADSIZE_0      0x00001000U
#define QUADSPI_CCR_ADSIZE_1      0x00002000U
#define QUADSPI_CCR_ABMODE        0x0000C000U
#define QUADSPI_CCR_ABMODE_0      0x00004000U
#define QUADSPI_CCR_ABMODE_1      0x00008000U
#define QUADSPI_CCR_ABSIZE        0x00030000U
#define QUADSPI_CCR_ABSIZE_0      0x00010000U
#define QUADSPI_CCR_ABSIZE_1      0x00020000U
#define QUADSPI_CCR_DCYC          0x007C0000U
#define QUADSPI_CCR_DCYC_0        0x00040000U
#define QUADSPI_CCR_DCYC_1        0x00080000U
#define QUADSPI_CCR_DCYC_2        0x00100000U
#define QUADSPI_CCR_DCYC_3        0x00200000U
#define QUADSPI_CCR_DCYC_4        0x00400000U
#define QUADSPI_CCR_DMODE         0x03000000U
#define QUADSPI_CCR_DMODE_0       0x01000000U
#define QUADSPI_CCR_DMODE_1       0x02000000U
#define QUADSPI_CCR_FMODE         0x0C000000U
#define QUADSPI_CCR_FMODE_0       0x04000000U
#define QUADSPI_CCR_FMODE_1       0x08000000U
#define QUADSPI_CCR_SIOO          0x10000000U
#define QUADSPI_CCR_DHHC          0x40000000U
#define QUADSPI_CCR_DDRM          0x80000000U
/******************  Bit definition for QUADSPI_AR register  *******************/
#define QUADSPI_AR_ADDRESS 0xFFFFFFFFU
/******************  Bit definition for QUADSPI_ABR register  ******************/
#define QUADSPI_ABR_ALTERNATE 0xFFFFFFFFU
/******************  Bit definition for QUADSPI_DR register  *******************/
#define QUADSPI_DR_DATA 0xFFFFFFFFU
/******************  Bit definition for QUADSPI_PSMKR register  ****************/
#define QUADSPI_PSMKR_MASK 0xFFFFFFFFU
/******************  Bit definition for QUADSPI_PSMAR register  ****************/
#define QUADSPI_PSMAR_MATCH 0xFFFFFFFFU
/******************  Bit definition for QUADSPI_PIR register  *****************/
#define QUADSPI_PIR_INTERVAL 0x0000FFFFU
/******************  Bit definition for QUADSPI_LPTR register  *****************/
#define QUADSPI_LPTR_TIMEOUT 0x0000FFFFU
/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION  0x00000001U
#define RCC_CR_HSIRDY 0x00000002U

#define RCC_CR_HSITRIM   0x000000F8U
#define RCC_CR_HSITRIM_0 0x00000008U
#define RCC_CR_HSITRIM_1 0x00000010U
#define RCC_CR_HSITRIM_2 0x00000020U
#define RCC_CR_HSITRIM_3 0x00000040U
#define RCC_CR_HSITRIM_4 0x00000080U
#define RCC_CR_HSICAL    0x0000FF00U
#define RCC_CR_HSICAL_0  0x00000100U
#define RCC_CR_HSICAL_1  0x00000200U
#define RCC_CR_HSICAL_2  0x00000400U
#define RCC_CR_HSICAL_3  0x00000800U
#define RCC_CR_HSICAL_4  0x00001000U
#define RCC_CR_HSICAL_5  0x00002000U
#define RCC_CR_HSICAL_6  0x00004000U
#define RCC_CR_HSICAL_7  0x00008000U
#define RCC_CR_HSEON     0x00010000U
#define RCC_CR_HSERDY    0x00020000U
#define RCC_CR_HSEBYP    0x00040000U
#define RCC_CR_CSSON     0x00080000U
#define RCC_CR_PLLON     0x01000000U
#define RCC_CR_PLLRDY    0x02000000U
#define RCC_CR_PLLI2SON  0x04000000U
#define RCC_CR_PLLI2SRDY 0x08000000U
#define RCC_CR_PLLSAION  0x10000000U
#define RCC_CR_PLLSAIRDY 0x20000000U

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM   0x0000003FU
#define RCC_PLLCFGR_PLLM_0 0x00000001U
#define RCC_PLLCFGR_PLLM_1 0x00000002U
#define RCC_PLLCFGR_PLLM_2 0x00000004U
#define RCC_PLLCFGR_PLLM_3 0x00000008U
#define RCC_PLLCFGR_PLLM_4 0x00000010U
#define RCC_PLLCFGR_PLLM_5 0x00000020U

#define RCC_PLLCFGR_PLLN   0x00007FC0U
#define RCC_PLLCFGR_PLLN_0 0x00000040U
#define RCC_PLLCFGR_PLLN_1 0x00000080U
#define RCC_PLLCFGR_PLLN_2 0x00000100U
#define RCC_PLLCFGR_PLLN_3 0x00000200U
#define RCC_PLLCFGR_PLLN_4 0x00000400U
#define RCC_PLLCFGR_PLLN_5 0x00000800U
#define RCC_PLLCFGR_PLLN_6 0x00001000U
#define RCC_PLLCFGR_PLLN_7 0x00002000U
#define RCC_PLLCFGR_PLLN_8 0x00004000U

#define RCC_PLLCFGR_PLLP   0x00030000U
#define RCC_PLLCFGR_PLLP_0 0x00010000U
#define RCC_PLLCFGR_PLLP_1 0x00020000U

#define RCC_PLLCFGR_PLLSRC     0x00400000U
#define RCC_PLLCFGR_PLLSRC_HSE 0x00400000U
#define RCC_PLLCFGR_PLLSRC_HSI 0x00000000U

#define RCC_PLLCFGR_PLLQ   0x0F000000U
#define RCC_PLLCFGR_PLLQ_0 0x01000000U
#define RCC_PLLCFGR_PLLQ_1 0x02000000U
#define RCC_PLLCFGR_PLLQ_2 0x04000000U
#define RCC_PLLCFGR_PLLQ_3 0x08000000U

#define RCC_PLLCFGR_PLLR   0x70000000U
#define RCC_PLLCFGR_PLLR_0 0x10000000U
#define RCC_PLLCFGR_PLLR_1 0x20000000U
#define RCC_PLLCFGR_PLLR_2 0x40000000U

/********************  Bit definition for RCC_CFGR register  ******************/
#define RCC_CFGR_SW          0x00000003U
#define RCC_CFGR_SW_0        0x00000001U
#define RCC_CFGR_SW_1        0x00000002U
#define RCC_CFGR_SW_HSI      0x00000000U
#define RCC_CFGR_SW_HSE      0x00000001U
#define RCC_CFGR_SW_PLL      0x00000002U
#define RCC_CFGR_SW_PLLR     0x00000003U
#define RCC_CFGR_SWS         0x0000000CU
#define RCC_CFGR_SWS_0       0x00000004U
#define RCC_CFGR_SWS_1       0x00000008U
#define RCC_CFGR_SWS_HSI     0x00000000U
#define RCC_CFGR_SWS_HSE     0x00000004U
#define RCC_CFGR_SWS_PLL     0x00000008U
#define RCC_CFGR_SWS_PLLR    0x0000000CU
#define RCC_CFGR_HPRE        0x000000F0U
#define RCC_CFGR_HPRE_0      0x00000010U
#define RCC_CFGR_HPRE_1      0x00000020U
#define RCC_CFGR_HPRE_2      0x00000040U
#define RCC_CFGR_HPRE_3      0x00000080U
#define RCC_CFGR_HPRE_DIV1   0x00000000U
#define RCC_CFGR_HPRE_DIV2   0x00000080U
#define RCC_CFGR_HPRE_DIV4   0x00000090U
#define RCC_CFGR_HPRE_DIV8   0x000000A0U
#define RCC_CFGR_HPRE_DIV16  0x000000B0U
#define RCC_CFGR_HPRE_DIV64  0x000000C0U
#define RCC_CFGR_HPRE_DIV128 0x000000D0U
#define RCC_CFGR_HPRE_DIV256 0x000000E0U
#define RCC_CFGR_HPRE_DIV512 0x000000F0U
#define RCC_CFGR_PPRE1       0x00001C00U
#define RCC_CFGR_PPRE1_0     0x00000400U
#define RCC_CFGR_PPRE1_1     0x00000800U
#define RCC_CFGR_PPRE1_2     0x00001000U
#define RCC_CFGR_PPRE1_DIV1  0x00000000U
#define RCC_CFGR_PPRE1_DIV2  0x00001000U
#define RCC_CFGR_PPRE1_DIV4  0x00001400U
#define RCC_CFGR_PPRE1_DIV8  0x00001800U
#define RCC_CFGR_PPRE1_DIV16 0x00001C00U
#define RCC_CFGR_PPRE2       0x0000E000U
#define RCC_CFGR_PPRE2_0     0x00002000U
#define RCC_CFGR_PPRE2_1     0x00004000U
#define RCC_CFGR_PPRE2_2     0x00008000U
#define RCC_CFGR_PPRE2_DIV1  0x00000000U
#define RCC_CFGR_PPRE2_DIV2  0x00008000U
#define RCC_CFGR_PPRE2_DIV4  0x0000A000U
#define RCC_CFGR_PPRE2_DIV8  0x0000C000U
#define RCC_CFGR_PPRE2_DIV16 0x0000E000U
#define RCC_CFGR_RTCPRE      0x001F0000U
#define RCC_CFGR_RTCPRE_0    0x00010000U
#define RCC_CFGR_RTCPRE_1    0x00020000U
#define RCC_CFGR_RTCPRE_2    0x00040000U
#define RCC_CFGR_RTCPRE_3    0x00080000U
#define RCC_CFGR_RTCPRE_4    0x00100000U

#define RCC_CFGR_MCO1   0x00600000U
#define RCC_CFGR_MCO1_0 0x00200000U
#define RCC_CFGR_MCO1_1 0x00400000U

#define RCC_CFGR_I2SSRC 0x00800000U

#define RCC_CFGR_MCO1PRE   0x07000000U
#define RCC_CFGR_MCO1PRE_0 0x01000000U
#define RCC_CFGR_MCO1PRE_1 0x02000000U
#define RCC_CFGR_MCO1PRE_2 0x04000000U

#define RCC_CFGR_MCO2PRE   0x38000000U
#define RCC_CFGR_MCO2PRE_0 0x08000000U
#define RCC_CFGR_MCO2PRE_1 0x10000000U
#define RCC_CFGR_MCO2PRE_2 0x20000000U

#define RCC_CFGR_MCO2   0xC0000000U
#define RCC_CFGR_MCO2_0 0x40000000U
#define RCC_CFGR_MCO2_1 0x80000000U

/********************  Bit definition for RCC_CIR register  *******************/
#define RCC_CIR_LSIRDYF     0x00000001U
#define RCC_CIR_LSERDYF     0x00000002U
#define RCC_CIR_HSIRDYF     0x00000004U
#define RCC_CIR_HSERDYF     0x00000008U
#define RCC_CIR_PLLRDYF     0x00000010U
#define RCC_CIR_PLLI2SRDYF  0x00000020U
#define RCC_CIR_PLLSAIRDYF  0x00000040U
#define RCC_CIR_CSSF        0x00000080U
#define RCC_CIR_LSIRDYIE    0x00000100U
#define RCC_CIR_LSERDYIE    0x00000200U
#define RCC_CIR_HSIRDYIE    0x00000400U
#define RCC_CIR_HSERDYIE    0x00000800U
#define RCC_CIR_PLLRDYIE    0x00001000U
#define RCC_CIR_PLLI2SRDYIE 0x00002000U
#define RCC_CIR_PLLSAIRDYIE 0x00004000U
#define RCC_CIR_LSIRDYC     0x00010000U
#define RCC_CIR_LSERDYC     0x00020000U
#define RCC_CIR_HSIRDYC     0x00040000U
#define RCC_CIR_HSERDYC     0x00080000U
#define RCC_CIR_PLLRDYC     0x00100000U
#define RCC_CIR_PLLI2SRDYC  0x00200000U
#define RCC_CIR_PLLSAIRDYC  0x00400000U
#define RCC_CIR_CSSC        0x00800000U

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPIOARST 0x00000001U
#define RCC_AHB1RSTR_GPIOBRST 0x00000002U
#define RCC_AHB1RSTR_GPIOCRST 0x00000004U
#define RCC_AHB1RSTR_GPIODRST 0x00000008U
#define RCC_AHB1RSTR_GPIOERST 0x00000010U
#define RCC_AHB1RSTR_GPIOFRST 0x00000020U
#define RCC_AHB1RSTR_GPIOGRST 0x00000040U
#define RCC_AHB1RSTR_GPIOHRST 0x00000080U
#define RCC_AHB1RSTR_CRCRST   0x00001000U
#define RCC_AHB1RSTR_DMA1RST  0x00200000U
#define RCC_AHB1RSTR_DMA2RST  0x00400000U
#define RCC_AHB1RSTR_OTGHRST  0x20000000U

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_DCMIRST  0x00000001U
#define RCC_AHB2RSTR_OTGFSRST 0x00000080U

/********************  Bit definition for RCC_AHB3RSTR register  **************/
#define RCC_AHB3RSTR_FMCRST  0x00000001U
#define RCC_AHB3RSTR_QSPIRST 0x00000002U

/********************  Bit definition for RCC_APB1RSTR register  **************/
#define RCC_APB1RSTR_TIM2RST    0x00000001U
#define RCC_APB1RSTR_TIM3RST    0x00000002U
#define RCC_APB1RSTR_TIM4RST    0x00000004U
#define RCC_APB1RSTR_TIM5RST    0x00000008U
#define RCC_APB1RSTR_TIM6RST    0x00000010U
#define RCC_APB1RSTR_TIM7RST    0x00000020U
#define RCC_APB1RSTR_TIM12RST   0x00000040U
#define RCC_APB1RSTR_TIM13RST   0x00000080U
#define RCC_APB1RSTR_TIM14RST   0x00000100U
#define RCC_APB1RSTR_WWDGRST    0x00000800U
#define RCC_APB1RSTR_SPI2RST    0x00004000U
#define RCC_APB1RSTR_SPI3RST    0x00008000U
#define RCC_APB1RSTR_SPDIFRXRST 0x00010000U
#define RCC_APB1RSTR_USART2RST  0x00020000U
#define RCC_APB1RSTR_USART3RST  0x00040000U
#define RCC_APB1RSTR_UART4RST   0x00080000U
#define RCC_APB1RSTR_UART5RST   0x00100000U
#define RCC_APB1RSTR_I2C1RST    0x00200000U
#define RCC_APB1RSTR_I2C2RST    0x00400000U
#define RCC_APB1RSTR_I2C3RST    0x00800000U
#define RCC_APB1RSTR_FMPI2C1RST 0x01000000U
#define RCC_APB1RSTR_CAN1RST    0x02000000U
#define RCC_APB1RSTR_CAN2RST    0x04000000U
#define RCC_APB1RSTR_CECRST     0x08000000U
#define RCC_APB1RSTR_PWRRST     0x10000000U
#define RCC_APB1RSTR_DACRST     0x20000000U

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST   0x00000001U
#define RCC_APB2RSTR_TIM8RST   0x00000002U
#define RCC_APB2RSTR_USART1RST 0x00000010U
#define RCC_APB2RSTR_USART6RST 0x00000020U
#define RCC_APB2RSTR_ADCRST    0x00000100U
#define RCC_APB2RSTR_SDIORST   0x00000800U
#define RCC_APB2RSTR_SPI1RST   0x00001000U
#define RCC_APB2RSTR_SPI4RST   0x00002000U
#define RCC_APB2RSTR_SYSCFGRST 0x00004000U
#define RCC_APB2RSTR_TIM9RST   0x00010000U
#define RCC_APB2RSTR_TIM10RST  0x00020000U
#define RCC_APB2RSTR_TIM11RST  0x00040000U
#define RCC_APB2RSTR_SAI1RST   0x00400000U
#define RCC_APB2RSTR_SAI2RST   0x00800000U

/* Old SPI1RST bit definition, maintained for legacy purpose */
#define RCC_APB2RSTR_SPI1 RCC_APB2RSTR_SPI1RST

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN 0x00000001U
#define RCC_AHB1ENR_GPIOBEN 0x00000002U
#define RCC_AHB1ENR_GPIOCEN 0x00000004U
#define RCC_AHB1ENR_GPIODEN 0x00000008U
#define RCC_AHB1ENR_GPIOEEN 0x00000010U
#define RCC_AHB1ENR_GPIOFEN 0x00000020U
#define RCC_AHB1ENR_GPIOGEN 0x00000040U
#define RCC_AHB1ENR_GPIOHEN 0x00000080U

#define RCC_AHB1ENR_CRCEN     0x00001000U
#define RCC_AHB1ENR_BKPSRAMEN 0x00040000U
#define RCC_AHB1ENR_DMA1EN    0x00200000U
#define RCC_AHB1ENR_DMA2EN    0x00400000U

#define RCC_AHB1ENR_OTGHSEN     0x20000000U
#define RCC_AHB1ENR_OTGHSULPIEN 0x40000000U

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2ENR_DCMIEN  0x00000001U
#define RCC_AHB2ENR_OTGFSEN 0x00000080U

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3ENR_FMCEN  0x00000001U
#define RCC_AHB3ENR_QSPIEN 0x00000002U

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN    0x00000001U
#define RCC_APB1ENR_TIM3EN    0x00000002U
#define RCC_APB1ENR_TIM4EN    0x00000004U
#define RCC_APB1ENR_TIM5EN    0x00000008U
#define RCC_APB1ENR_TIM6EN    0x00000010U
#define RCC_APB1ENR_TIM7EN    0x00000020U
#define RCC_APB1ENR_TIM12EN   0x00000040U
#define RCC_APB1ENR_TIM13EN   0x00000080U
#define RCC_APB1ENR_TIM14EN   0x00000100U
#define RCC_APB1ENR_WWDGEN    0x00000800U
#define RCC_APB1ENR_SPI2EN    0x00004000U
#define RCC_APB1ENR_SPI3EN    0x00008000U
#define RCC_APB1ENR_SPDIFRXEN 0x00010000U
#define RCC_APB1ENR_USART2EN  0x00020000U
#define RCC_APB1ENR_USART3EN  0x00040000U
#define RCC_APB1ENR_UART4EN   0x00080000U
#define RCC_APB1ENR_UART5EN   0x00100000U
#define RCC_APB1ENR_I2C1EN    0x00200000U
#define RCC_APB1ENR_I2C2EN    0x00400000U
#define RCC_APB1ENR_I2C3EN    0x00800000U
#define RCC_APB1ENR_FMPI2C1EN 0x01000000U
#define RCC_APB1ENR_CAN1EN    0x02000000U
#define RCC_APB1ENR_CAN2EN    0x04000000U
#define RCC_APB1ENR_CECEN     0x08000000U
#define RCC_APB1ENR_PWREN     0x10000000U
#define RCC_APB1ENR_DACEN     0x20000000U

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN   0x00000001U
#define RCC_APB2ENR_TIM8EN   0x00000002U
#define RCC_APB2ENR_USART1EN 0x00000010U
#define RCC_APB2ENR_USART6EN 0x00000020U
#define RCC_APB2ENR_ADC1EN   0x00000100U
#define RCC_APB2ENR_ADC2EN   0x00000200U
#define RCC_APB2ENR_ADC3EN   0x00000400U
#define RCC_APB2ENR_SDIOEN   0x00000800U
#define RCC_APB2ENR_SPI1EN   0x00001000U
#define RCC_APB2ENR_SPI4EN   0x00002000U
#define RCC_APB2ENR_SYSCFGEN 0x00004000U
#define RCC_APB2ENR_TIM9EN   0x00010000U
#define RCC_APB2ENR_TIM10EN  0x00020000U
#define RCC_APB2ENR_TIM11EN  0x00040000U
#define RCC_APB2ENR_SAI1EN   0x00400000U
#define RCC_APB2ENR_SAI2EN   0x00800000U

/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define RCC_AHB1LPENR_GPIOALPEN 0x00000001U
#define RCC_AHB1LPENR_GPIOBLPEN 0x00000002U
#define RCC_AHB1LPENR_GPIOCLPEN 0x00000004U
#define RCC_AHB1LPENR_GPIODLPEN 0x00000008U
#define RCC_AHB1LPENR_GPIOELPEN 0x00000010U
#define RCC_AHB1LPENR_GPIOFLPEN 0x00000020U
#define RCC_AHB1LPENR_GPIOGLPEN 0x00000040U
#define RCC_AHB1LPENR_GPIOHLPEN 0x00000080U
#define RCC_AHB1LPENR_GPIOILPEN 0x00000100U
#define RCC_AHB1LPENR_GPIOJLPEN 0x00000200U
#define RCC_AHB1LPENR_GPIOKLPEN 0x00000400U

#define RCC_AHB1LPENR_CRCLPEN     0x00001000U
#define RCC_AHB1LPENR_FLITFLPEN   0x00008000U
#define RCC_AHB1LPENR_SRAM1LPEN   0x00010000U
#define RCC_AHB1LPENR_SRAM2LPEN   0x00020000U
#define RCC_AHB1LPENR_BKPSRAMLPEN 0x00040000U
#define RCC_AHB1LPENR_DMA1LPEN    0x00200000U
#define RCC_AHB1LPENR_DMA2LPEN    0x00400000U

#define RCC_AHB1LPENR_OTGHSLPEN     0x20000000U
#define RCC_AHB1LPENR_OTGHSULPILPEN 0x40000000U

/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define RCC_AHB2LPENR_DCMILPEN  0x00000001U
#define RCC_AHB2LPENR_OTGFSLPEN 0x00000080U

/********************  Bit definition for RCC_AHB3LPENR register  *************/
#define RCC_AHB3LPENR_FMCLPEN  0x00000001U
#define RCC_AHB3LPENR_QSPILPEN 0x00000002U

/********************  Bit definition for RCC_APB1LPENR register  *************/
#define RCC_APB1LPENR_TIM2LPEN    0x00000001U
#define RCC_APB1LPENR_TIM3LPEN    0x00000002U
#define RCC_APB1LPENR_TIM4LPEN    0x00000004U
#define RCC_APB1LPENR_TIM5LPEN    0x00000008U
#define RCC_APB1LPENR_TIM6LPEN    0x00000010U
#define RCC_APB1LPENR_TIM7LPEN    0x00000020U
#define RCC_APB1LPENR_TIM12LPEN   0x00000040U
#define RCC_APB1LPENR_TIM13LPEN   0x00000080U
#define RCC_APB1LPENR_TIM14LPEN   0x00000100U
#define RCC_APB1LPENR_WWDGLPEN    0x00000800U
#define RCC_APB1LPENR_SPI2LPEN    0x00004000U
#define RCC_APB1LPENR_SPI3LPEN    0x00008000U
#define RCC_APB1LPENR_SPDIFRXLPEN 0x00010000U
#define RCC_APB1LPENR_USART2LPEN  0x00020000U
#define RCC_APB1LPENR_USART3LPEN  0x00040000U
#define RCC_APB1LPENR_UART4LPEN   0x00080000U
#define RCC_APB1LPENR_UART5LPEN   0x00100000U
#define RCC_APB1LPENR_I2C1LPEN    0x00200000U
#define RCC_APB1LPENR_I2C2LPEN    0x00400000U
#define RCC_APB1LPENR_I2C3LPEN    0x00800000U
#define RCC_APB1LPENR_FMPI2C1LPEN 0x01000000U
#define RCC_APB1LPENR_CAN1LPEN    0x02000000U
#define RCC_APB1LPENR_CAN2LPEN    0x04000000U
#define RCC_APB1LPENR_CECLPEN     0x08000000U
#define RCC_APB1LPENR_PWRLPEN     0x10000000U
#define RCC_APB1LPENR_DACLPEN     0x20000000U

/********************  Bit definition for RCC_APB2LPENR register  *************/
#define RCC_APB2LPENR_TIM1LPEN   0x00000001U
#define RCC_APB2LPENR_TIM8LPEN   0x00000002U
#define RCC_APB2LPENR_USART1LPEN 0x00000010U
#define RCC_APB2LPENR_USART6LPEN 0x00000020U
#define RCC_APB2LPENR_ADC1LPEN   0x00000100U
#define RCC_APB2LPENR_ADC2LPEN   0x00000200U
#define RCC_APB2LPENR_ADC3LPEN   0x00000400U
#define RCC_APB2LPENR_SDIOLPEN   0x00000800U
#define RCC_APB2LPENR_SPI1LPEN   0x00001000U
#define RCC_APB2LPENR_SPI4LPEN   0x00002000U
#define RCC_APB2LPENR_SYSCFGLPEN 0x00004000U
#define RCC_APB2LPENR_TIM9LPEN   0x00010000U
#define RCC_APB2LPENR_TIM10LPEN  0x00020000U
#define RCC_APB2LPENR_TIM11LPEN  0x00040000U
#define RCC_APB2LPENR_SAI1LPEN   0x00400000U
#define RCC_APB2LPENR_SAI2LPEN   0x00800000U

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON  0x00000001U
#define RCC_BDCR_LSERDY 0x00000002U
#define RCC_BDCR_LSEBYP 0x00000004U
#define RCC_BDCR_LSEMOD 0x00000008U

#define RCC_BDCR_RTCSEL   0x00000300U
#define RCC_BDCR_RTCSEL_0 0x00000100U
#define RCC_BDCR_RTCSEL_1 0x00000200U

#define RCC_BDCR_RTCEN 0x00008000U
#define RCC_BDCR_BDRST 0x00010000U

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION    0x00000001U
#define RCC_CSR_LSIRDY   0x00000002U
#define RCC_CSR_RMVF     0x01000000U
#define RCC_CSR_BORRSTF  0x02000000U
#define RCC_CSR_PADRSTF  0x04000000U
#define RCC_CSR_PORRSTF  0x08000000U
#define RCC_CSR_SFTRSTF  0x10000000U
#define RCC_CSR_WDGRSTF  0x20000000U
#define RCC_CSR_WWDGRSTF 0x40000000U
#define RCC_CSR_LPWRRSTF 0x80000000U

/********************  Bit definition for RCC_SSCGR register  *****************/
#define RCC_SSCGR_MODPER    0x00001FFFU
#define RCC_SSCGR_INCSTEP   0x0FFFE000U
#define RCC_SSCGR_SPREADSEL 0x40000000U
#define RCC_SSCGR_SSCGEN    0x80000000U

/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define RCC_PLLI2SCFGR_PLLI2SM   0x0000003FU
#define RCC_PLLI2SCFGR_PLLI2SM_0 0x00000001U
#define RCC_PLLI2SCFGR_PLLI2SM_1 0x00000002U
#define RCC_PLLI2SCFGR_PLLI2SM_2 0x00000004U
#define RCC_PLLI2SCFGR_PLLI2SM_3 0x00000008U
#define RCC_PLLI2SCFGR_PLLI2SM_4 0x00000010U
#define RCC_PLLI2SCFGR_PLLI2SM_5 0x00000020U

#define RCC_PLLI2SCFGR_PLLI2SN   0x00007FC0U
#define RCC_PLLI2SCFGR_PLLI2SN_0 0x00000040U
#define RCC_PLLI2SCFGR_PLLI2SN_1 0x00000080U
#define RCC_PLLI2SCFGR_PLLI2SN_2 0x00000100U
#define RCC_PLLI2SCFGR_PLLI2SN_3 0x00000200U
#define RCC_PLLI2SCFGR_PLLI2SN_4 0x00000400U
#define RCC_PLLI2SCFGR_PLLI2SN_5 0x00000800U
#define RCC_PLLI2SCFGR_PLLI2SN_6 0x00001000U
#define RCC_PLLI2SCFGR_PLLI2SN_7 0x00002000U
#define RCC_PLLI2SCFGR_PLLI2SN_8 0x00004000U

#define RCC_PLLI2SCFGR_PLLI2SP   0x00030000U
#define RCC_PLLI2SCFGR_PLLI2SP_0 0x00010000U
#define RCC_PLLI2SCFGR_PLLI2SP_1 0x00020000U

#define RCC_PLLI2SCFGR_PLLI2SQ   0x0F000000U
#define RCC_PLLI2SCFGR_PLLI2SQ_0 0x01000000U
#define RCC_PLLI2SCFGR_PLLI2SQ_1 0x02000000U
#define RCC_PLLI2SCFGR_PLLI2SQ_2 0x04000000U
#define RCC_PLLI2SCFGR_PLLI2SQ_3 0x08000000U

#define RCC_PLLI2SCFGR_PLLI2SR   0x70000000U
#define RCC_PLLI2SCFGR_PLLI2SR_0 0x10000000U
#define RCC_PLLI2SCFGR_PLLI2SR_1 0x20000000U
#define RCC_PLLI2SCFGR_PLLI2SR_2 0x40000000U

/********************  Bit definition for RCC_PLLSAICFGR register  ************/
#define RCC_PLLSAICFGR_PLLSAIM   0x0000003FU
#define RCC_PLLSAICFGR_PLLSAIM_0 0x00000001U
#define RCC_PLLSAICFGR_PLLSAIM_1 0x00000002U
#define RCC_PLLSAICFGR_PLLSAIM_2 0x00000004U
#define RCC_PLLSAICFGR_PLLSAIM_3 0x00000008U
#define RCC_PLLSAICFGR_PLLSAIM_4 0x00000010U
#define RCC_PLLSAICFGR_PLLSAIM_5 0x00000020U

#define RCC_PLLSAICFGR_PLLSAIN   0x00007FC0U
#define RCC_PLLSAICFGR_PLLSAIN_0 0x00000040U
#define RCC_PLLSAICFGR_PLLSAIN_1 0x00000080U
#define RCC_PLLSAICFGR_PLLSAIN_2 0x00000100U
#define RCC_PLLSAICFGR_PLLSAIN_3 0x00000200U
#define RCC_PLLSAICFGR_PLLSAIN_4 0x00000400U
#define RCC_PLLSAICFGR_PLLSAIN_5 0x00000800U
#define RCC_PLLSAICFGR_PLLSAIN_6 0x00001000U
#define RCC_PLLSAICFGR_PLLSAIN_7 0x00002000U
#define RCC_PLLSAICFGR_PLLSAIN_8 0x00004000U

#define RCC_PLLSAICFGR_PLLSAIP   0x00030000U
#define RCC_PLLSAICFGR_PLLSAIP_0 0x00010000U
#define RCC_PLLSAICFGR_PLLSAIP_1 0x00020000U

#define RCC_PLLSAICFGR_PLLSAIQ   0x0F000000U
#define RCC_PLLSAICFGR_PLLSAIQ_0 0x01000000U
#define RCC_PLLSAICFGR_PLLSAIQ_1 0x02000000U
#define RCC_PLLSAICFGR_PLLSAIQ_2 0x04000000U
#define RCC_PLLSAICFGR_PLLSAIQ_3 0x08000000U

/********************  Bit definition for RCC_DCKCFGR register  ***************/
#define RCC_DCKCFGR_PLLI2SDIVQ 0x0000001FU
#define RCC_DCKCFGR_PLLSAIDIVQ 0x00001F00U
#define RCC_DCKCFGR_SAI1SRC    0x00300000U
#define RCC_DCKCFGR_SAI1SRC_0  0x00100000U
#define RCC_DCKCFGR_SAI1SRC_1  0x00200000U
#define RCC_DCKCFGR_SAI2SRC    0x00C00000U
#define RCC_DCKCFGR_SAI2SRC_0  0x00400000U
#define RCC_DCKCFGR_SAI2SRC_1  0x00800000U
#define RCC_DCKCFGR_TIMPRE     0x01000000U
#define RCC_DCKCFGR_I2S1SRC    0x06000000U
#define RCC_DCKCFGR_I2S1SRC_0  0x02000000U
#define RCC_DCKCFGR_I2S1SRC_1  0x04000000U
#define RCC_DCKCFGR_I2S2SRC    0x18000000U
#define RCC_DCKCFGR_I2S2SRC_0  0x08000000U
#define RCC_DCKCFGR_I2S2SRC_1  0x10000000U

/********************  Bit definition for RCC_CKGATENR register  ***************/
#define RCC_CKGATENR_AHB2APB1_CKEN 0x00000001U
#define RCC_CKGATENR_AHB2APB2_CKEN 0x00000002U
#define RCC_CKGATENR_CM4DBG_CKEN   0x00000004U
#define RCC_CKGATENR_SPARE_CKEN    0x00000008U
#define RCC_CKGATENR_SRAM_CKEN     0x00000010U
#define RCC_CKGATENR_FLITF_CKEN    0x00000020U
#define RCC_CKGATENR_RCC_CKEN      0x00000040U

/********************  Bit definition for RCC_DCKCFGR2 register  ***************/
#define RCC_DCKCFGR2_FMPI2C1SEL   0x00C00000U
#define RCC_DCKCFGR2_FMPI2C1SEL_0 0x00400000U
#define RCC_DCKCFGR2_FMPI2C1SEL_1 0x00800000U
#define RCC_DCKCFGR2_CECSEL       0x04000000U
#define RCC_DCKCFGR2_CK48MSEL     0x08000000U
#define RCC_DCKCFGR2_SDIOSEL      0x10000000U
#define RCC_DCKCFGR2_SPDIFRXSEL   0x20000000U

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM    0x00400000U
#define RTC_TR_HT    0x00300000U
#define RTC_TR_HT_0  0x00100000U
#define RTC_TR_HT_1  0x00200000U
#define RTC_TR_HU    0x000F0000U
#define RTC_TR_HU_0  0x00010000U
#define RTC_TR_HU_1  0x00020000U
#define RTC_TR_HU_2  0x00040000U
#define RTC_TR_HU_3  0x00080000U
#define RTC_TR_MNT   0x00007000U
#define RTC_TR_MNT_0 0x00001000U
#define RTC_TR_MNT_1 0x00002000U
#define RTC_TR_MNT_2 0x00004000U
#define RTC_TR_MNU   0x00000F00U
#define RTC_TR_MNU_0 0x00000100U
#define RTC_TR_MNU_1 0x00000200U
#define RTC_TR_MNU_2 0x00000400U
#define RTC_TR_MNU_3 0x00000800U
#define RTC_TR_ST    0x00000070U
#define RTC_TR_ST_0  0x00000010U
#define RTC_TR_ST_1  0x00000020U
#define RTC_TR_ST_2  0x00000040U
#define RTC_TR_SU    0x0000000FU
#define RTC_TR_SU_0  0x00000001U
#define RTC_TR_SU_1  0x00000002U
#define RTC_TR_SU_2  0x00000004U
#define RTC_TR_SU_3  0x00000008U

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT    0x00F00000U
#define RTC_DR_YT_0  0x00100000U
#define RTC_DR_YT_1  0x00200000U
#define RTC_DR_YT_2  0x00400000U
#define RTC_DR_YT_3  0x00800000U
#define RTC_DR_YU    0x000F0000U
#define RTC_DR_YU_0  0x00010000U
#define RTC_DR_YU_1  0x00020000U
#define RTC_DR_YU_2  0x00040000U
#define RTC_DR_YU_3  0x00080000U
#define RTC_DR_WDU   0x0000E000U
#define RTC_DR_WDU_0 0x00002000U
#define RTC_DR_WDU_1 0x00004000U
#define RTC_DR_WDU_2 0x00008000U
#define RTC_DR_MT    0x00001000U
#define RTC_DR_MU    0x00000F00U
#define RTC_DR_MU_0  0x00000100U
#define RTC_DR_MU_1  0x00000200U
#define RTC_DR_MU_2  0x00000400U
#define RTC_DR_MU_3  0x00000800U
#define RTC_DR_DT    0x00000030U
#define RTC_DR_DT_0  0x00000010U
#define RTC_DR_DT_1  0x00000020U
#define RTC_DR_DU    0x0000000FU
#define RTC_DR_DU_0  0x00000001U
#define RTC_DR_DU_1  0x00000002U
#define RTC_DR_DU_2  0x00000004U
#define RTC_DR_DU_3  0x00000008U

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_COE       0x00800000U
#define RTC_CR_OSEL      0x00600000U
#define RTC_CR_OSEL_0    0x00200000U
#define RTC_CR_OSEL_1    0x00400000U
#define RTC_CR_POL       0x00100000U
#define RTC_CR_COSEL     0x00080000U
#define RTC_CR_BCK       0x00040000U
#define RTC_CR_SUB1H     0x00020000U
#define RTC_CR_ADD1H     0x00010000U
#define RTC_CR_TSIE      0x00008000U
#define RTC_CR_WUTIE     0x00004000U
#define RTC_CR_ALRBIE    0x00002000U
#define RTC_CR_ALRAIE    0x00001000U
#define RTC_CR_TSE       0x00000800U
#define RTC_CR_WUTE      0x00000400U
#define RTC_CR_ALRBE     0x00000200U
#define RTC_CR_ALRAE     0x00000100U
#define RTC_CR_DCE       0x00000080U
#define RTC_CR_FMT       0x00000040U
#define RTC_CR_BYPSHAD   0x00000020U
#define RTC_CR_REFCKON   0x00000010U
#define RTC_CR_TSEDGE    0x00000008U
#define RTC_CR_WUCKSEL   0x00000007U
#define RTC_CR_WUCKSEL_0 0x00000001U
#define RTC_CR_WUCKSEL_1 0x00000002U
#define RTC_CR_WUCKSEL_2 0x00000004U

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_RECALPF 0x00010000U
#define RTC_ISR_TAMP1F  0x00002000U
#define RTC_ISR_TAMP2F  0x00004000U
#define RTC_ISR_TSOVF   0x00001000U
#define RTC_ISR_TSF     0x00000800U
#define RTC_ISR_WUTF    0x00000400U
#define RTC_ISR_ALRBF   0x00000200U
#define RTC_ISR_ALRAF   0x00000100U
#define RTC_ISR_INIT    0x00000080U
#define RTC_ISR_INITF   0x00000040U
#define RTC_ISR_RSF     0x00000020U
#define RTC_ISR_INITS   0x00000010U
#define RTC_ISR_SHPF    0x00000008U
#define RTC_ISR_WUTWF   0x00000004U
#define RTC_ISR_ALRBWF  0x00000002U
#define RTC_ISR_ALRAWF  0x00000001U

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A 0x007F0000U
#define RTC_PRER_PREDIV_S 0x00007FFFU

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT 0x0000FFFFU

/********************  Bits definition for RTC_CALIBR register  ***************/
#define RTC_CALIBR_DCS 0x00000080U
#define RTC_CALIBR_DC  0x0000001FU

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4  0x80000000U
#define RTC_ALRMAR_WDSEL 0x40000000U
#define RTC_ALRMAR_DT    0x30000000U
#define RTC_ALRMAR_DT_0  0x10000000U
#define RTC_ALRMAR_DT_1  0x20000000U
#define RTC_ALRMAR_DU    0x0F000000U
#define RTC_ALRMAR_DU_0  0x01000000U
#define RTC_ALRMAR_DU_1  0x02000000U
#define RTC_ALRMAR_DU_2  0x04000000U
#define RTC_ALRMAR_DU_3  0x08000000U
#define RTC_ALRMAR_MSK3  0x00800000U
#define RTC_ALRMAR_PM    0x00400000U
#define RTC_ALRMAR_HT    0x00300000U
#define RTC_ALRMAR_HT_0  0x00100000U
#define RTC_ALRMAR_HT_1  0x00200000U
#define RTC_ALRMAR_HU    0x000F0000U
#define RTC_ALRMAR_HU_0  0x00010000U
#define RTC_ALRMAR_HU_1  0x00020000U
#define RTC_ALRMAR_HU_2  0x00040000U
#define RTC_ALRMAR_HU_3  0x00080000U
#define RTC_ALRMAR_MSK2  0x00008000U
#define RTC_ALRMAR_MNT   0x00007000U
#define RTC_ALRMAR_MNT_0 0x00001000U
#define RTC_ALRMAR_MNT_1 0x00002000U
#define RTC_ALRMAR_MNT_2 0x00004000U
#define RTC_ALRMAR_MNU   0x00000F00U
#define RTC_ALRMAR_MNU_0 0x00000100U
#define RTC_ALRMAR_MNU_1 0x00000200U
#define RTC_ALRMAR_MNU_2 0x00000400U
#define RTC_ALRMAR_MNU_3 0x00000800U
#define RTC_ALRMAR_MSK1  0x00000080U
#define RTC_ALRMAR_ST    0x00000070U
#define RTC_ALRMAR_ST_0  0x00000010U
#define RTC_ALRMAR_ST_1  0x00000020U
#define RTC_ALRMAR_ST_2  0x00000040U
#define RTC_ALRMAR_SU    0x0000000FU
#define RTC_ALRMAR_SU_0  0x00000001U
#define RTC_ALRMAR_SU_1  0x00000002U
#define RTC_ALRMAR_SU_2  0x00000004U
#define RTC_ALRMAR_SU_3  0x00000008U

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4  0x80000000U
#define RTC_ALRMBR_WDSEL 0x40000000U
#define RTC_ALRMBR_DT    0x30000000U
#define RTC_ALRMBR_DT_0  0x10000000U
#define RTC_ALRMBR_DT_1  0x20000000U
#define RTC_ALRMBR_DU    0x0F000000U
#define RTC_ALRMBR_DU_0  0x01000000U
#define RTC_ALRMBR_DU_1  0x02000000U
#define RTC_ALRMBR_DU_2  0x04000000U
#define RTC_ALRMBR_DU_3  0x08000000U
#define RTC_ALRMBR_MSK3  0x00800000U
#define RTC_ALRMBR_PM    0x00400000U
#define RTC_ALRMBR_HT    0x00300000U
#define RTC_ALRMBR_HT_0  0x00100000U
#define RTC_ALRMBR_HT_1  0x00200000U
#define RTC_ALRMBR_HU    0x000F0000U
#define RTC_ALRMBR_HU_0  0x00010000U
#define RTC_ALRMBR_HU_1  0x00020000U
#define RTC_ALRMBR_HU_2  0x00040000U
#define RTC_ALRMBR_HU_3  0x00080000U
#define RTC_ALRMBR_MSK2  0x00008000U
#define RTC_ALRMBR_MNT   0x00007000U
#define RTC_ALRMBR_MNT_0 0x00001000U
#define RTC_ALRMBR_MNT_1 0x00002000U
#define RTC_ALRMBR_MNT_2 0x00004000U
#define RTC_ALRMBR_MNU   0x00000F00U
#define RTC_ALRMBR_MNU_0 0x00000100U
#define RTC_ALRMBR_MNU_1 0x00000200U
#define RTC_ALRMBR_MNU_2 0x00000400U
#define RTC_ALRMBR_MNU_3 0x00000800U
#define RTC_ALRMBR_MSK1  0x00000080U
#define RTC_ALRMBR_ST    0x00000070U
#define RTC_ALRMBR_ST_0  0x00000010U
#define RTC_ALRMBR_ST_1  0x00000020U
#define RTC_ALRMBR_ST_2  0x00000040U
#define RTC_ALRMBR_SU    0x0000000FU
#define RTC_ALRMBR_SU_0  0x00000001U
#define RTC_ALRMBR_SU_1  0x00000002U
#define RTC_ALRMBR_SU_2  0x00000004U
#define RTC_ALRMBR_SU_3  0x00000008U

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY 0x000000FFU

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS 0x0000FFFFU

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS 0x00007FFFU
#define RTC_SHIFTR_ADD1S 0x80000000U

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM    0x00400000U
#define RTC_TSTR_HT    0x00300000U
#define RTC_TSTR_HT_0  0x00100000U
#define RTC_TSTR_HT_1  0x00200000U
#define RTC_TSTR_HU    0x000F0000U
#define RTC_TSTR_HU_0  0x00010000U
#define RTC_TSTR_HU_1  0x00020000U
#define RTC_TSTR_HU_2  0x00040000U
#define RTC_TSTR_HU_3  0x00080000U
#define RTC_TSTR_MNT   0x00007000U
#define RTC_TSTR_MNT_0 0x00001000U
#define RTC_TSTR_MNT_1 0x00002000U
#define RTC_TSTR_MNT_2 0x00004000U
#define RTC_TSTR_MNU   0x00000F00U
#define RTC_TSTR_MNU_0 0x00000100U
#define RTC_TSTR_MNU_1 0x00000200U
#define RTC_TSTR_MNU_2 0x00000400U
#define RTC_TSTR_MNU_3 0x00000800U
#define RTC_TSTR_ST    0x00000070U
#define RTC_TSTR_ST_0  0x00000010U
#define RTC_TSTR_ST_1  0x00000020U
#define RTC_TSTR_ST_2  0x00000040U
#define RTC_TSTR_SU    0x0000000FU
#define RTC_TSTR_SU_0  0x00000001U
#define RTC_TSTR_SU_1  0x00000002U
#define RTC_TSTR_SU_2  0x00000004U
#define RTC_TSTR_SU_3  0x00000008U

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU   0x0000E000U
#define RTC_TSDR_WDU_0 0x00002000U
#define RTC_TSDR_WDU_1 0x00004000U
#define RTC_TSDR_WDU_2 0x00008000U
#define RTC_TSDR_MT    0x00001000U
#define RTC_TSDR_MU    0x00000F00U
#define RTC_TSDR_MU_0  0x00000100U
#define RTC_TSDR_MU_1  0x00000200U
#define RTC_TSDR_MU_2  0x00000400U
#define RTC_TSDR_MU_3  0x00000800U
#define RTC_TSDR_DT    0x00000030U
#define RTC_TSDR_DT_0  0x00000010U
#define RTC_TSDR_DT_1  0x00000020U
#define RTC_TSDR_DU    0x0000000FU
#define RTC_TSDR_DU_0  0x00000001U
#define RTC_TSDR_DU_1  0x00000002U
#define RTC_TSDR_DU_2  0x00000004U
#define RTC_TSDR_DU_3  0x00000008U

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS 0x0000FFFFU

/********************  Bits definition for RTC_CAL register  *****************/
#define RTC_CALR_CALP   0x00008000U
#define RTC_CALR_CALW8  0x00004000U
#define RTC_CALR_CALW16 0x00002000U
#define RTC_CALR_CALM   0x000001FFU
#define RTC_CALR_CALM_0 0x00000001U
#define RTC_CALR_CALM_1 0x00000002U
#define RTC_CALR_CALM_2 0x00000004U
#define RTC_CALR_CALM_3 0x00000008U
#define RTC_CALR_CALM_4 0x00000010U
#define RTC_CALR_CALM_5 0x00000020U
#define RTC_CALR_CALM_6 0x00000040U
#define RTC_CALR_CALM_7 0x00000080U
#define RTC_CALR_CALM_8 0x00000100U

/********************  Bits definition for RTC_TAFCR register  ****************/
#define RTC_TAFCR_ALARMOUTTYPE 0x00040000U
#define RTC_TAFCR_TSINSEL      0x00020000U
#define RTC_TAFCR_TAMPINSEL    0x00010000U
#define RTC_TAFCR_TAMPPUDIS    0x00008000U
#define RTC_TAFCR_TAMPPRCH     0x00006000U
#define RTC_TAFCR_TAMPPRCH_0   0x00002000U
#define RTC_TAFCR_TAMPPRCH_1   0x00004000U
#define RTC_TAFCR_TAMPFLT      0x00001800U
#define RTC_TAFCR_TAMPFLT_0    0x00000800U
#define RTC_TAFCR_TAMPFLT_1    0x00001000U
#define RTC_TAFCR_TAMPFREQ     0x00000700U
#define RTC_TAFCR_TAMPFREQ_0   0x00000100U
#define RTC_TAFCR_TAMPFREQ_1   0x00000200U
#define RTC_TAFCR_TAMPFREQ_2   0x00000400U
#define RTC_TAFCR_TAMPTS       0x00000080U
#define RTC_TAFCR_TAMP2TRG     0x00000010U
#define RTC_TAFCR_TAMP2E       0x00000008U
#define RTC_TAFCR_TAMPIE       0x00000004U
#define RTC_TAFCR_TAMP1TRG     0x00000002U
#define RTC_TAFCR_TAMP1E       0x00000001U

/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS   0x0F000000U
#define RTC_ALRMASSR_MASKSS_0 0x01000000U
#define RTC_ALRMASSR_MASKSS_1 0x02000000U
#define RTC_ALRMASSR_MASKSS_2 0x04000000U
#define RTC_ALRMASSR_MASKSS_3 0x08000000U
#define RTC_ALRMASSR_SS       0x00007FFFU

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS   0x0F000000U
#define RTC_ALRMBSSR_MASKSS_0 0x01000000U
#define RTC_ALRMBSSR_MASKSS_1 0x02000000U
#define RTC_ALRMBSSR_MASKSS_2 0x04000000U
#define RTC_ALRMBSSR_MASKSS_3 0x08000000U
#define RTC_ALRMBSSR_SS       0x00007FFFU

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP16R register  ***************/
#define RTC_BKP16R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP17R register  ***************/
#define RTC_BKP17R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP18R register  ***************/
#define RTC_BKP18R 0xFFFFFFFFU

/********************  Bits definition for RTC_BKP19R register  ***************/
#define RTC_BKP19R 0xFFFFFFFFU

/******************************************************************************/
/*                                                                            */
/*                          Serial Audio Interface                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SAI_GCR register  *******************/
#define SAI_GCR_SYNCIN    0x00000003U
#define SAI_GCR_SYNCIN_0  0x00000001U
#define SAI_GCR_SYNCIN_1  0x00000002U
#define SAI_GCR_SYNCOUT   0x00000030U
#define SAI_GCR_SYNCOUT_0 0x00000010U
#define SAI_GCR_SYNCOUT_1 0x00000020U
/*******************  Bit definition for SAI_xCR1 register  *******************/
#define SAI_xCR1_MODE     0x00000003U
#define SAI_xCR1_MODE_0   0x00000001U
#define SAI_xCR1_MODE_1   0x00000002U
#define SAI_xCR1_PRTCFG   0x0000000CU
#define SAI_xCR1_PRTCFG_0 0x00000004U
#define SAI_xCR1_PRTCFG_1 0x00000008U
#define SAI_xCR1_DS       0x000000E0U
#define SAI_xCR1_DS_0     0x00000020U
#define SAI_xCR1_DS_1     0x00000040U
#define SAI_xCR1_DS_2     0x00000080U
#define SAI_xCR1_LSBFIRST 0x00000100U
#define SAI_xCR1_CKSTR    0x00000200U
#define SAI_xCR1_SYNCEN   0x00000C00U
#define SAI_xCR1_SYNCEN_0 0x00000400U
#define SAI_xCR1_SYNCEN_1 0x00000800U
#define SAI_xCR1_MONO     0x00001000U
#define SAI_xCR1_OUTDRIV  0x00002000U
#define SAI_xCR1_SAIEN    0x00010000U
#define SAI_xCR1_DMAEN    0x00020000U
#define SAI_xCR1_NODIV    0x00080000U
#define SAI_xCR1_MCKDIV   0x00F00000U
#define SAI_xCR1_MCKDIV_0 0x00100000U
#define SAI_xCR1_MCKDIV_1 0x00200000U
#define SAI_xCR1_MCKDIV_2 0x00400000U
#define SAI_xCR1_MCKDIV_3 0x00800000U
/*******************  Bit definition for SAI_xCR2 register  *******************/
#define SAI_xCR2_FTH       0x00000007U
#define SAI_xCR2_FTH_0     0x00000001U
#define SAI_xCR2_FTH_1     0x00000002U
#define SAI_xCR2_FTH_2     0x00000004U
#define SAI_xCR2_FFLUSH    0x00000008U
#define SAI_xCR2_TRIS      0x00000010U
#define SAI_xCR2_MUTE      0x00000020U
#define SAI_xCR2_MUTEVAL   0x00000040U
#define SAI_xCR2_MUTECNT   0x00001F80U
#define SAI_xCR2_MUTECNT_0 0x00000080U
#define SAI_xCR2_MUTECNT_1 0x00000100U
#define SAI_xCR2_MUTECNT_2 0x00000200U
#define SAI_xCR2_MUTECNT_3 0x00000400U
#define SAI_xCR2_MUTECNT_4 0x00000800U
#define SAI_xCR2_MUTECNT_5 0x00001000U
#define SAI_xCR2_CPL       0x00002000U
#define SAI_xCR2_COMP      0x0000C000U
#define SAI_xCR2_COMP_0    0x00004000U
#define SAI_xCR2_COMP_1    0x00008000U
/******************  Bit definition for SAI_xFRCR register  *******************/
#define SAI_xFRCR_FRL     0x000000FFU
#define SAI_xFRCR_FRL_0   0x00000001U
#define SAI_xFRCR_FRL_1   0x00000002U
#define SAI_xFRCR_FRL_2   0x00000004U
#define SAI_xFRCR_FRL_3   0x00000008U
#define SAI_xFRCR_FRL_4   0x00000010U
#define SAI_xFRCR_FRL_5   0x00000020U
#define SAI_xFRCR_FRL_6   0x00000040U
#define SAI_xFRCR_FRL_7   0x00000080U
#define SAI_xFRCR_FSALL   0x00007F00U
#define SAI_xFRCR_FSALL_0 0x00000100U
#define SAI_xFRCR_FSALL_1 0x00000200U
#define SAI_xFRCR_FSALL_2 0x00000400U
#define SAI_xFRCR_FSALL_3 0x00000800U
#define SAI_xFRCR_FSALL_4 0x00001000U
#define SAI_xFRCR_FSALL_5 0x00002000U
#define SAI_xFRCR_FSALL_6 0x00004000U
#define SAI_xFRCR_FSDEF   0x00010000U
#define SAI_xFRCR_FSPOL   0x00020000U
#define SAI_xFRCR_FSOFF   0x00040000U
/* Legacy defines */
#define SAI_xFRCR_FSPO SAI_xFRCR_FSPOL

/******************  Bit definition for SAI_xSLOTR register  *******************/
#define SAI_xSLOTR_FBOFF    0x0000001FU
#define SAI_xSLOTR_FBOFF_0  0x00000001U
#define SAI_xSLOTR_FBOFF_1  0x00000002U
#define SAI_xSLOTR_FBOFF_2  0x00000004U
#define SAI_xSLOTR_FBOFF_3  0x00000008U
#define SAI_xSLOTR_FBOFF_4  0x00000010U
#define SAI_xSLOTR_SLOTSZ   0x000000C0U
#define SAI_xSLOTR_SLOTSZ_0 0x00000040U
#define SAI_xSLOTR_SLOTSZ_1 0x00000080U
#define SAI_xSLOTR_NBSLOT   0x00000F00U
#define SAI_xSLOTR_NBSLOT_0 0x00000100U
#define SAI_xSLOTR_NBSLOT_1 0x00000200U
#define SAI_xSLOTR_NBSLOT_2 0x00000400U
#define SAI_xSLOTR_NBSLOT_3 0x00000800U
#define SAI_xSLOTR_SLOTEN   0xFFFF0000U
/*******************  Bit definition for SAI_xIMR register  *******************/
#define SAI_xIMR_OVRUDRIE  0x00000001U
#define SAI_xIMR_MUTEDETIE 0x00000002U
#define SAI_xIMR_WCKCFGIE  0x00000004U
#define SAI_xIMR_FREQIE    0x00000008U
#define SAI_xIMR_CNRDYIE   0x00000010U
#define SAI_xIMR_AFSDETIE  0x00000020U
#define SAI_xIMR_LFSDETIE  0x00000040U
/********************  Bit definition for SAI_xSR register  *******************/
#define SAI_xSR_OVRUDR  0x00000001U
#define SAI_xSR_MUTEDET 0x00000002U
#define SAI_xSR_WCKCFG  0x00000004U
#define SAI_xSR_FREQ    0x00000008U
#define SAI_xSR_CNRDY   0x00000010U
#define SAI_xSR_AFSDET  0x00000020U
#define SAI_xSR_LFSDET  0x00000040U
#define SAI_xSR_FLVL    0x00070000U
#define SAI_xSR_FLVL_0  0x00010000U
#define SAI_xSR_FLVL_1  0x00020000U
#define SAI_xSR_FLVL_2  0x00040000U
/******************  Bit definition for SAI_xCLRFR register  ******************/
#define SAI_xCLRFR_COVRUDR  0x00000001U
#define SAI_xCLRFR_CMUTEDET 0x00000002U
#define SAI_xCLRFR_CWCKCFG  0x00000004U
#define SAI_xCLRFR_CFREQ    0x00000008U
#define SAI_xCLRFR_CCNRDY   0x00000010U
#define SAI_xCLRFR_CAFSDET  0x00000020U
#define SAI_xCLRFR_CLFSDET  0x00000040U
/******************  Bit definition for SAI_xDR register  ******************/
#define SAI_xDR_DATA 0xFFFFFFFFU

/******************************************************************************/
/*                                                                            */
/*                              SPDIF-RX Interface                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SPDIFRX_CR register  *******************/
#define SPDIFRX_CR_SPDIFEN 0x00000003U
#define SPDIFRX_CR_RXDMAEN 0x00000004U
#define SPDIFRX_CR_RXSTEO  0x00000008U
#define SPDIFRX_CR_DRFMT   0x00000030U
#define SPDIFRX_CR_PMSK    0x00000040U
#define SPDIFRX_CR_VMSK    0x00000080U
#define SPDIFRX_CR_CUMSK   0x00000100U
#define SPDIFRX_CR_PTMSK   0x00000200U
#define SPDIFRX_CR_CBDMAEN 0x00000400U
#define SPDIFRX_CR_CHSEL   0x00000800U
#define SPDIFRX_CR_NBTR    0x00003000U
#define SPDIFRX_CR_WFA     0x00004000U
#define SPDIFRX_CR_INSEL   0x00070000U
/*******************  Bit definition for SPDIFRX_IMR register  *******************/
#define SPDIFRX_IMR_RXNEIE  0x00000001U
#define SPDIFRX_IMR_CSRNEIE 0x00000002U
#define SPDIFRX_IMR_PERRIE  0x00000004U
#define SPDIFRX_IMR_OVRIE   0x00000008U
#define SPDIFRX_IMR_SBLKIE  0x00000010U
#define SPDIFRX_IMR_SYNCDIE 0x00000020U
#define SPDIFRX_IMR_IFEIE   0x00000040U
/*******************  Bit definition for SPDIFRX_SR register  *******************/
#define SPDIFRX_SR_RXNE   0x00000001U
#define SPDIFRX_SR_CSRNE  0x00000002U
#define SPDIFRX_SR_PERR   0x00000004U
#define SPDIFRX_SR_OVR    0x00000008U
#define SPDIFRX_SR_SBD    0x00000010U
#define SPDIFRX_SR_SYNCD  0x00000020U
#define SPDIFRX_SR_FERR   0x00000040U
#define SPDIFRX_SR_SERR   0x00000080U
#define SPDIFRX_SR_TERR   0x00000100U
#define SPDIFRX_SR_WIDTH5 0x7FFF0000U
/*******************  Bit definition for SPDIFRX_IFCR register  *******************/
#define SPDIFRX_IFCR_PERRCF  0x00000004U
#define SPDIFRX_IFCR_OVRCF   0x00000008U
#define SPDIFRX_IFCR_SBDCF   0x00000010U
#define SPDIFRX_IFCR_SYNCDCF 0x00000020U
/*******************  Bit definition for SPDIFRX_DR register  (DRFMT = 0b00 case)
 * *******************/
#define SPDIFRX_DR0_DR 0x00FFFFFFU
#define SPDIFRX_DR0_PE 0x01000000U
#define SPDIFRX_DR0_V  0x02000000U
#define SPDIFRX_DR0_U  0x04000000U
#define SPDIFRX_DR0_C  0x08000000U
#define SPDIFRX_DR0_PT 0x30000000U
/*******************  Bit definition for SPDIFRX_DR register  (DRFMT = 0b01 case)
 * *******************/
#define SPDIFRX_DR1_DR 0xFFFFFF00U
#define SPDIFRX_DR1_PT 0x00000030U
#define SPDIFRX_DR1_C  0x00000008U
#define SPDIFRX_DR1_U  0x00000004U
#define SPDIFRX_DR1_V  0x00000002U
#define SPDIFRX_DR1_PE 0x00000001U
/*******************  Bit definition for SPDIFRX_DR register  (DRFMT = 0b10 case)
 * *******************/
#define SPDIFRX_DR1_DRNL1 0xFFFF0000U
#define SPDIFRX_DR1_DRNL2 0x0000FFFFU
/*******************  Bit definition for SPDIFRX_CSR register   *******************/
#define SPDIFRX_CSR_USR 0x0000FFFFU
#define SPDIFRX_CSR_CS  0x00FF0000U
#define SPDIFRX_CSR_SOB 0x01000000U
/*******************  Bit definition for SPDIFRX_DIR register    *******************/
#define SPDIFRX_DIR_THI 0x000013FFU
#define SPDIFRX_DIR_TLO 0x1FFF0000U
/******************************************************************************/
/*                                                                            */
/*                          SD host Interface                                 */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SDIO_POWER register  ******************/
#define SDIO_POWER_PWRCTRL   0x03U
#define SDIO_POWER_PWRCTRL_0 0x01U
#define SDIO_POWER_PWRCTRL_1 0x02U
/******************  Bit definition for SDIO_CLKCR register  ******************/
#define SDIO_CLKCR_CLKDIV   0x00FFU
#define SDIO_CLKCR_CLKEN    0x0100U
#define SDIO_CLKCR_PWRSAV   0x0200U
#define SDIO_CLKCR_BYPASS   0x0400U
#define SDIO_CLKCR_WIDBUS   0x1800U
#define SDIO_CLKCR_WIDBUS_0 0x0800U
#define SDIO_CLKCR_WIDBUS_1 0x1000U
#define SDIO_CLKCR_NEGEDGE  0x2000U
#define SDIO_CLKCR_HWFC_EN  0x4000U
/*******************  Bit definition for SDIO_ARG register  *******************/
#define SDIO_ARG_CMDARG 0xFFFFFFFFU
/*******************  Bit definition for SDIO_CMD register  *******************/
#define SDIO_CMD_CMDINDEX    0x003FU
#define SDIO_CMD_WAITRESP    0x00C0U
#define SDIO_CMD_WAITRESP_0  0x0040U
#define SDIO_CMD_WAITRESP_1  0x0080U
#define SDIO_CMD_WAITINT     0x0100U
#define SDIO_CMD_WAITPEND    0x0200U
#define SDIO_CMD_CPSMEN      0x0400U
#define SDIO_CMD_SDIOSUSPEND 0x0800U
/*****************  Bit definition for SDIO_RESPCMD register  *****************/
#define SDIO_RESPCMD_RESPCMD 0x3FU
/******************  Bit definition for SDIO_RESP0 register  ******************/
#define SDIO_RESP0_CARDSTATUS0 0xFFFFFFFFU
/******************  Bit definition for SDIO_RESP1 register  ******************/
#define SDIO_RESP1_CARDSTATUS1 0xFFFFFFFFU
/******************  Bit definition for SDIO_RESP2 register  ******************/
#define SDIO_RESP2_CARDSTATUS2 0xFFFFFFFFU
/******************  Bit definition for SDIO_RESP3 register  ******************/
#define SDIO_RESP3_CARDSTATUS3 0xFFFFFFFFU
/******************  Bit definition for SDIO_RESP4 register  ******************/
#define SDIO_RESP4_CARDSTATUS4 0xFFFFFFFFU
/******************  Bit definition for SDIO_DTIMER register  *****************/
#define SDIO_DTIMER_DATATIME 0xFFFFFFFFU
/******************  Bit definition for SDIO_DLEN register  *******************/
#define SDIO_DLEN_DATALENGTH 0x01FFFFFFU
/******************  Bit definition for SDIO_DCTRL register  ******************/
#define SDIO_DCTRL_DTEN         0x0001U
#define SDIO_DCTRL_DTDIR        0x0002U
#define SDIO_DCTRL_DTMODE       0x0004U
#define SDIO_DCTRL_DMAEN        0x0008U
#define SDIO_DCTRL_DBLOCKSIZE   0x00F0U
#define SDIO_DCTRL_DBLOCKSIZE_0 0x0010U
#define SDIO_DCTRL_DBLOCKSIZE_1 0x0020U
#define SDIO_DCTRL_DBLOCKSIZE_2 0x0040U
#define SDIO_DCTRL_DBLOCKSIZE_3 0x0080U
#define SDIO_DCTRL_RWSTART      0x0100U
#define SDIO_DCTRL_RWSTOP       0x0200U
#define SDIO_DCTRL_RWMOD        0x0400U
#define SDIO_DCTRL_SDIOEN       0x0800U
/******************  Bit definition for SDIO_DCOUNT register  *****************/
#define SDIO_DCOUNT_DATACOUNT 0x01FFFFFFU
/******************  Bit definition for SDIO_STA register  ********************/
#define SDIO_STA_CCRCFAIL 0x00000001U
#define SDIO_STA_DCRCFAIL 0x00000002U
#define SDIO_STA_CTIMEOUT 0x00000004U
#define SDIO_STA_DTIMEOUT 0x00000008U
#define SDIO_STA_TXUNDERR 0x00000010U
#define SDIO_STA_RXOVERR  0x00000020U
#define SDIO_STA_CMDREND  0x00000040U
#define SDIO_STA_CMDSENT  0x00000080U
#define SDIO_STA_DATAEND  0x00000100U
#define SDIO_STA_DBCKEND  0x00000400U
#define SDIO_STA_CMDACT   0x00000800U
#define SDIO_STA_TXACT    0x00001000U
#define SDIO_STA_RXACT    0x00002000U
#define SDIO_STA_TXFIFOHE 0x00004000U
#define SDIO_STA_RXFIFOHF 0x00008000U
#define SDIO_STA_TXFIFOF  0x00010000U
#define SDIO_STA_RXFIFOF  0x00020000U
#define SDIO_STA_TXFIFOE  0x00040000U
#define SDIO_STA_RXFIFOE  0x00080000U
#define SDIO_STA_TXDAVL   0x00100000U
#define SDIO_STA_RXDAVL   0x00200000U
#define SDIO_STA_SDIOIT   0x00400000U
/*******************  Bit definition for SDIO_ICR register  *******************/
#define SDIO_ICR_CCRCFAILC 0x00000001U
#define SDIO_ICR_DCRCFAILC 0x00000002U
#define SDIO_ICR_CTIMEOUTC 0x00000004U
#define SDIO_ICR_DTIMEOUTC 0x00000008U
#define SDIO_ICR_TXUNDERRC 0x00000010U
#define SDIO_ICR_RXOVERRC  0x00000020U
#define SDIO_ICR_CMDRENDC  0x00000040U
#define SDIO_ICR_CMDSENTC  0x00000080U
#define SDIO_ICR_DATAENDC  0x00000100U
#define SDIO_ICR_DBCKENDC  0x00000400U
#define SDIO_ICR_SDIOITC   0x00400000U
/******************  Bit definition for SDIO_MASK register  *******************/
#define SDIO_MASK_CCRCFAILIE 0x00000001U
#define SDIO_MASK_DCRCFAILIE 0x00000002U
#define SDIO_MASK_CTIMEOUTIE 0x00000004U
#define SDIO_MASK_DTIMEOUTIE 0x00000008U
#define SDIO_MASK_TXUNDERRIE 0x00000010U
#define SDIO_MASK_RXOVERRIE  0x00000020U
#define SDIO_MASK_CMDRENDIE  0x00000040U
#define SDIO_MASK_CMDSENTIE  0x00000080U
#define SDIO_MASK_DATAENDIE  0x00000100U
#define SDIO_MASK_DBCKENDIE  0x00000400U
#define SDIO_MASK_CMDACTIE   0x00000800U
#define SDIO_MASK_TXACTIE    0x00001000U
#define SDIO_MASK_RXACTIE    0x00002000U
#define SDIO_MASK_TXFIFOHEIE 0x00004000U
#define SDIO_MASK_RXFIFOHFIE 0x00008000U
#define SDIO_MASK_TXFIFOFIE  0x00010000U
#define SDIO_MASK_RXFIFOFIE  0x00020000U
#define SDIO_MASK_TXFIFOEIE  0x00040000U
#define SDIO_MASK_RXFIFOEIE  0x00080000U
#define SDIO_MASK_TXDAVLIE   0x00100000U
#define SDIO_MASK_RXDAVLIE   0x00200000U
#define SDIO_MASK_SDIOITIE   0x00400000U
/*****************  Bit definition for SDIO_FIFOCNT register  *****************/
#define SDIO_FIFOCNT_FIFOCOUNT 0x00FFFFFFU
/******************  Bit definition for SDIO_FIFO register  *******************/
#define SDIO_FIFO_FIFODATA 0xFFFFFFFFU
/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_CPHA     0x00000001U
#define SPI_CR1_CPOL     0x00000002U
#define SPI_CR1_MSTR     0x00000004U
#define SPI_CR1_BR       0x00000038U
#define SPI_CR1_BR_0     0x00000008U
#define SPI_CR1_BR_1     0x00000010U
#define SPI_CR1_BR_2     0x00000020U
#define SPI_CR1_SPE      0x00000040U
#define SPI_CR1_LSBFIRST 0x00000080U
#define SPI_CR1_SSI      0x00000100U
#define SPI_CR1_SSM      0x00000200U
#define SPI_CR1_RXONLY   0x00000400U
#define SPI_CR1_DFF      0x00000800U
#define SPI_CR1_CRCNEXT  0x00001000U
#define SPI_CR1_CRCEN    0x00002000U
#define SPI_CR1_BIDIOE   0x00004000U
#define SPI_CR1_BIDIMODE 0x00008000U
/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_RXDMAEN 0x00000001U
#define SPI_CR2_TXDMAEN 0x00000002U
#define SPI_CR2_SSOE    0x00000004U
#define SPI_CR2_FRF     0x00000010U
#define SPI_CR2_ERRIE   0x00000020U
#define SPI_CR2_RXNEIE  0x00000040U
#define SPI_CR2_TXEIE   0x00000080U
/********************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXNE   0x00000001U
#define SPI_SR_TXE    0x00000002U
#define SPI_SR_CHSIDE 0x00000004U
#define SPI_SR_UDR    0x00000008U
#define SPI_SR_CRCERR 0x00000010U
#define SPI_SR_MODF   0x00000020U
#define SPI_SR_OVR    0x00000040U
#define SPI_SR_BSY    0x00000080U
#define SPI_SR_FRE    0x00000100U
/********************  Bit definition for SPI_DR register  ********************/
#define SPI_DR_DR 0x0000FFFFU
/*******************  Bit definition for SPI_CRCPR register  ******************/
#define SPI_CRCPR_CRCPOLY 0x0000FFFFU
/******************  Bit definition for SPI_RXCRCR register  ******************/
#define SPI_RXCRCR_RXCRC 0x0000FFFFU
/******************  Bit definition for SPI_TXCRCR register  ******************/
#define SPI_TXCRCR_TXCRC 0x0000FFFFU
/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define SPI_I2SCFGR_CHLEN    0x00000001U
#define SPI_I2SCFGR_DATLEN   0x00000006U
#define SPI_I2SCFGR_DATLEN_0 0x00000002U
#define SPI_I2SCFGR_DATLEN_1 0x00000004U
#define SPI_I2SCFGR_CKPOL    0x00000008U
#define SPI_I2SCFGR_I2SSTD   0x00000030U
#define SPI_I2SCFGR_I2SSTD_0 0x00000010U
#define SPI_I2SCFGR_I2SSTD_1 0x00000020U
#define SPI_I2SCFGR_PCMSYNC  0x00000080U
#define SPI_I2SCFGR_I2SCFG   0x00000300U
#define SPI_I2SCFGR_I2SCFG_0 0x00000100U
#define SPI_I2SCFGR_I2SCFG_1 0x00000200U
#define SPI_I2SCFGR_I2SE     0x00000400U
#define SPI_I2SCFGR_I2SMOD   0x00000800U
#define SPI_I2SCFGR_ASTRTEN  0x00001000U
/******************  Bit definition for SPI_I2SPR register  *******************/
#define SPI_I2SPR_I2SDIV 0x000000FFU
#define SPI_I2SPR_ODD    0x00000100U
#define SPI_I2SPR_MCKOE  0x00000200U
/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SYSCFG_MEMRMP register  ***************/
#define SYSCFG_MEMRMP_MEM_MODE   0x00000007U
#define SYSCFG_MEMRMP_MEM_MODE_0 0x00000001U
#define SYSCFG_MEMRMP_MEM_MODE_1 0x00000002U
#define SYSCFG_MEMRMP_MEM_MODE_2 0x00000004U

#define SYSCFG_MEMRMP_UFB_MODE 0x00000100U
#define SYSCFG_SWP_FMC         0x00000C00U
/******************  Bit definition for SYSCFG_PMC register  ******************/
#define SYSCFG_PMC_ADCxDC2 0x00070000U
#define SYSCFG_PMC_ADC1DC2 0x00010000U
#define SYSCFG_PMC_ADC2DC2 0x00020000U
#define SYSCFG_PMC_ADC3DC2 0x00040000U
/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0    0x000FU
#define SYSCFG_EXTICR1_EXTI1    0x00F0U
#define SYSCFG_EXTICR1_EXTI2    0x0F00U
#define SYSCFG_EXTICR1_EXTI3    0xF000U
#define SYSCFG_EXTICR1_EXTI0_PA 0x0000U
#define SYSCFG_EXTICR1_EXTI0_PB 0x0001U
#define SYSCFG_EXTICR1_EXTI0_PC 0x0002U
#define SYSCFG_EXTICR1_EXTI0_PD 0x0003U
#define SYSCFG_EXTICR1_EXTI0_PE 0x0004U
#define SYSCFG_EXTICR1_EXTI0_PF 0x0005U
#define SYSCFG_EXTICR1_EXTI0_PG 0x0006U
#define SYSCFG_EXTICR1_EXTI0_PH 0x0007U
#define SYSCFG_EXTICR1_EXTI0_PI 0x0008U
#define SYSCFG_EXTICR1_EXTI0_PJ 0x0009U
#define SYSCFG_EXTICR1_EXTI0_PK 0x000AU
#define SYSCFG_EXTICR1_EXTI1_PA 0x0000U
#define SYSCFG_EXTICR1_EXTI1_PB 0x0010U
#define SYSCFG_EXTICR1_EXTI1_PC 0x0020U
#define SYSCFG_EXTICR1_EXTI1_PD 0x0030U
#define SYSCFG_EXTICR1_EXTI1_PE 0x0040U
#define SYSCFG_EXTICR1_EXTI1_PF 0x0050U
#define SYSCFG_EXTICR1_EXTI1_PG 0x0060U
#define SYSCFG_EXTICR1_EXTI1_PH 0x0070U
#define SYSCFG_EXTICR1_EXTI1_PI 0x0080U
#define SYSCFG_EXTICR1_EXTI1_PJ 0x0090U
#define SYSCFG_EXTICR1_EXTI1_PK 0x00A0U
#define SYSCFG_EXTICR1_EXTI2_PA 0x0000U
#define SYSCFG_EXTICR1_EXTI2_PB 0x0100U
#define SYSCFG_EXTICR1_EXTI2_PC 0x0200U
#define SYSCFG_EXTICR1_EXTI2_PD 0x0300U
#define SYSCFG_EXTICR1_EXTI2_PE 0x0400U
#define SYSCFG_EXTICR1_EXTI2_PF 0x0500U
#define SYSCFG_EXTICR1_EXTI2_PG 0x0600U
#define SYSCFG_EXTICR1_EXTI2_PH 0x0700U
#define SYSCFG_EXTICR1_EXTI2_PI 0x0800U
#define SYSCFG_EXTICR1_EXTI2_PJ 0x0900U
#define SYSCFG_EXTICR1_EXTI2_PK 0x0A00U
#define SYSCFG_EXTICR1_EXTI3_PA 0x0000U
#define SYSCFG_EXTICR1_EXTI3_PB 0x1000U
#define SYSCFG_EXTICR1_EXTI3_PC 0x2000U
#define SYSCFG_EXTICR1_EXTI3_PD 0x3000U
#define SYSCFG_EXTICR1_EXTI3_PE 0x4000U
#define SYSCFG_EXTICR1_EXTI3_PF 0x5000U
#define SYSCFG_EXTICR1_EXTI3_PG 0x6000U
#define SYSCFG_EXTICR1_EXTI3_PH 0x7000U
#define SYSCFG_EXTICR1_EXTI3_PI 0x8000U
#define SYSCFG_EXTICR1_EXTI3_PJ 0x9000U
#define SYSCFG_EXTICR1_EXTI3_PK 0xA000U
/*****************  Bit definition for SYSCFG_EXTICR2 register  ***************/
#define SYSCFG_EXTICR2_EXTI4    0x000FU
#define SYSCFG_EXTICR2_EXTI5    0x00F0U
#define SYSCFG_EXTICR2_EXTI6    0x0F00U
#define SYSCFG_EXTICR2_EXTI7    0xF000U
#define SYSCFG_EXTICR2_EXTI4_PA 0x0000U
#define SYSCFG_EXTICR2_EXTI4_PB 0x0001U
#define SYSCFG_EXTICR2_EXTI4_PC 0x0002U
#define SYSCFG_EXTICR2_EXTI4_PD 0x0003U
#define SYSCFG_EXTICR2_EXTI4_PE 0x0004U
#define SYSCFG_EXTICR2_EXTI4_PF 0x0005U
#define SYSCFG_EXTICR2_EXTI4_PG 0x0006U
#define SYSCFG_EXTICR2_EXTI4_PH 0x0007U
#define SYSCFG_EXTICR2_EXTI4_PI 0x0008U
#define SYSCFG_EXTICR2_EXTI4_PJ 0x0009U
#define SYSCFG_EXTICR2_EXTI4_PK 0x000AU
#define SYSCFG_EXTICR2_EXTI5_PA 0x0000U
#define SYSCFG_EXTICR2_EXTI5_PB 0x0010U
#define SYSCFG_EXTICR2_EXTI5_PC 0x0020U
#define SYSCFG_EXTICR2_EXTI5_PD 0x0030U
#define SYSCFG_EXTICR2_EXTI5_PE 0x0040U
#define SYSCFG_EXTICR2_EXTI5_PF 0x0050U
#define SYSCFG_EXTICR2_EXTI5_PG 0x0060U
#define SYSCFG_EXTICR2_EXTI5_PH 0x0070U
#define SYSCFG_EXTICR2_EXTI5_PI 0x0080U
#define SYSCFG_EXTICR2_EXTI5_PJ 0x0090U
#define SYSCFG_EXTICR2_EXTI5_PK 0x00A0U
#define SYSCFG_EXTICR2_EXTI6_PA 0x0000U
#define SYSCFG_EXTICR2_EXTI6_PB 0x0100U
#define SYSCFG_EXTICR2_EXTI6_PC 0x0200U
#define SYSCFG_EXTICR2_EXTI6_PD 0x0300U
#define SYSCFG_EXTICR2_EXTI6_PE 0x0400U
#define SYSCFG_EXTICR2_EXTI6_PF 0x0500U
#define SYSCFG_EXTICR2_EXTI6_PG 0x0600U
#define SYSCFG_EXTICR2_EXTI6_PH 0x0700U
#define SYSCFG_EXTICR2_EXTI6_PI 0x0800U
#define SYSCFG_EXTICR2_EXTI6_PJ 0x0900U
#define SYSCFG_EXTICR2_EXTI6_PK 0x0A00U
#define SYSCFG_EXTICR2_EXTI7_PA 0x0000U
#define SYSCFG_EXTICR2_EXTI7_PB 0x1000U
#define SYSCFG_EXTICR2_EXTI7_PC 0x2000U
#define SYSCFG_EXTICR2_EXTI7_PD 0x3000U
#define SYSCFG_EXTICR2_EXTI7_PE 0x4000U
#define SYSCFG_EXTICR2_EXTI7_PF 0x5000U
#define SYSCFG_EXTICR2_EXTI7_PG 0x6000U
#define SYSCFG_EXTICR2_EXTI7_PH 0x7000U
#define SYSCFG_EXTICR2_EXTI7_PI 0x8000U
#define SYSCFG_EXTICR2_EXTI7_PJ 0x9000U
#define SYSCFG_EXTICR2_EXTI7_PK 0xA000U
/*****************  Bit definition for SYSCFG_EXTICR3 register  ***************/
#define SYSCFG_EXTICR3_EXTI8     0x000FU
#define SYSCFG_EXTICR3_EXTI9     0x00F0U
#define SYSCFG_EXTICR3_EXTI10    0x0F00U
#define SYSCFG_EXTICR3_EXTI11    0xF000U
#define SYSCFG_EXTICR3_EXTI8_PA  0x0000U
#define SYSCFG_EXTICR3_EXTI8_PB  0x0001U
#define SYSCFG_EXTICR3_EXTI8_PC  0x0002U
#define SYSCFG_EXTICR3_EXTI8_PD  0x0003U
#define SYSCFG_EXTICR3_EXTI8_PE  0x0004U
#define SYSCFG_EXTICR3_EXTI8_PF  0x0005U
#define SYSCFG_EXTICR3_EXTI8_PG  0x0006U
#define SYSCFG_EXTICR3_EXTI8_PH  0x0007U
#define SYSCFG_EXTICR3_EXTI8_PI  0x0008U
#define SYSCFG_EXTICR3_EXTI8_PJ  0x0009U
#define SYSCFG_EXTICR3_EXTI9_PA  0x0000U
#define SYSCFG_EXTICR3_EXTI9_PB  0x0010U
#define SYSCFG_EXTICR3_EXTI9_PC  0x0020U
#define SYSCFG_EXTICR3_EXTI9_PD  0x0030U
#define SYSCFG_EXTICR3_EXTI9_PE  0x0040U
#define SYSCFG_EXTICR3_EXTI9_PF  0x0050U
#define SYSCFG_EXTICR3_EXTI9_PG  0x0060U
#define SYSCFG_EXTICR3_EXTI9_PH  0x0070U
#define SYSCFG_EXTICR3_EXTI9_PI  0x0080U
#define SYSCFG_EXTICR3_EXTI9_PJ  0x0090U
#define SYSCFG_EXTICR3_EXTI10_PA 0x0000U
#define SYSCFG_EXTICR3_EXTI10_PB 0x0100U
#define SYSCFG_EXTICR3_EXTI10_PC 0x0200U
#define SYSCFG_EXTICR3_EXTI10_PD 0x0300U
#define SYSCFG_EXTICR3_EXTI10_PE 0x0400U
#define SYSCFG_EXTICR3_EXTI10_PF 0x0500U
#define SYSCFG_EXTICR3_EXTI10_PG 0x0600U
#define SYSCFG_EXTICR3_EXTI10_PH 0x0700U
#define SYSCFG_EXTICR3_EXTI10_PI 0x0800U
#define SYSCFG_EXTICR3_EXTI10_PJ 0x0900U
#define SYSCFG_EXTICR3_EXTI11_PA 0x0000U
#define SYSCFG_EXTICR3_EXTI11_PB 0x1000U
#define SYSCFG_EXTICR3_EXTI11_PC 0x2000U
#define SYSCFG_EXTICR3_EXTI11_PD 0x3000U
#define SYSCFG_EXTICR3_EXTI11_PE 0x4000U
#define SYSCFG_EXTICR3_EXTI11_PF 0x5000U
#define SYSCFG_EXTICR3_EXTI11_PG 0x6000U
#define SYSCFG_EXTICR3_EXTI11_PH 0x7000U
#define SYSCFG_EXTICR3_EXTI11_PI 0x8000U
#define SYSCFG_EXTICR3_EXTI11_PJ 0x9000U
/*****************  Bit definition for SYSCFG_EXTICR4 register  ***************/
#define SYSCFG_EXTICR4_EXTI12    0x000FU
#define SYSCFG_EXTICR4_EXTI13    0x00F0U
#define SYSCFG_EXTICR4_EXTI14    0x0F00U
#define SYSCFG_EXTICR4_EXTI15    0xF000U
#define SYSCFG_EXTICR4_EXTI12_PA 0x0000U
#define SYSCFG_EXTICR4_EXTI12_PB 0x0001U
#define SYSCFG_EXTICR4_EXTI12_PC 0x0002U
#define SYSCFG_EXTICR4_EXTI12_PD 0x0003U
#define SYSCFG_EXTICR4_EXTI12_PE 0x0004U
#define SYSCFG_EXTICR4_EXTI12_PF 0x0005U
#define SYSCFG_EXTICR4_EXTI12_PG 0x0006U
#define SYSCFG_EXTICR4_EXTI12_PH 0x0007U
#define SYSCFG_EXTICR4_EXTI12_PI 0x0008U
#define SYSCFG_EXTICR4_EXTI12_PJ 0x0009U
#define SYSCFG_EXTICR4_EXTI13_PA 0x0000U
#define SYSCFG_EXTICR4_EXTI13_PB 0x0010U
#define SYSCFG_EXTICR4_EXTI13_PC 0x0020U
#define SYSCFG_EXTICR4_EXTI13_PD 0x0030U
#define SYSCFG_EXTICR4_EXTI13_PE 0x0040U
#define SYSCFG_EXTICR4_EXTI13_PF 0x0050U
#define SYSCFG_EXTICR4_EXTI13_PG 0x0060U
#define SYSCFG_EXTICR4_EXTI13_PH 0x0070U
#define SYSCFG_EXTICR4_EXTI13_PI 0x0008U
#define SYSCFG_EXTICR4_EXTI13_PJ 0x0009U
#define SYSCFG_EXTICR4_EXTI14_PA 0x0000U
#define SYSCFG_EXTICR4_EXTI14_PB 0x0100U
#define SYSCFG_EXTICR4_EXTI14_PC 0x0200U
#define SYSCFG_EXTICR4_EXTI14_PD 0x0300U
#define SYSCFG_EXTICR4_EXTI14_PE 0x0400U
#define SYSCFG_EXTICR4_EXTI14_PF 0x0500U
#define SYSCFG_EXTICR4_EXTI14_PG 0x0600U
#define SYSCFG_EXTICR4_EXTI14_PH 0x0700U
#define SYSCFG_EXTICR4_EXTI14_PI 0x0800U
#define SYSCFG_EXTICR4_EXTI14_PJ 0x0900U
#define SYSCFG_EXTICR4_EXTI15_PA 0x0000U
#define SYSCFG_EXTICR4_EXTI15_PB 0x1000U
#define SYSCFG_EXTICR4_EXTI15_PC 0x2000U
#define SYSCFG_EXTICR4_EXTI15_PD 0x3000U
#define SYSCFG_EXTICR4_EXTI15_PE 0x4000U
#define SYSCFG_EXTICR4_EXTI15_PF 0x5000U
#define SYSCFG_EXTICR4_EXTI15_PG 0x6000U
#define SYSCFG_EXTICR4_EXTI15_PH 0x7000U
#define SYSCFG_EXTICR4_EXTI15_PI 0x8000U
#define SYSCFG_EXTICR4_EXTI15_PJ 0x9000U
/******************  Bit definition for SYSCFG_CMPCR register  ****************/
#define SYSCFG_CMPCR_CMP_PD 0x00000001U
#define SYSCFG_CMPCR_READY  0x00000100U
/******************  Bit definition for SYSCFG_CFGR register  ****************/
#define SYSCFG_CFGR_FMPI2C1_SCL 0x00000001U
#define SYSCFG_CFGR_FMPI2C1_SDA 0x00000002U
/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN   0x0001U
#define TIM_CR1_UDIS  0x0002U
#define TIM_CR1_URS   0x0004U
#define TIM_CR1_OPM   0x0008U
#define TIM_CR1_DIR   0x0010U
#define TIM_CR1_CMS   0x0060U
#define TIM_CR1_CMS_0 0x0020U
#define TIM_CR1_CMS_1 0x0040U
#define TIM_CR1_ARPE  0x0080U
#define TIM_CR1_CKD   0x0300U
#define TIM_CR1_CKD_0 0x0100U
#define TIM_CR1_CKD_1 0x0200U
/*******************  Bit definition for TIM_CR2 register  ********************/
#define TIM_CR2_CCPC  0x0001U
#define TIM_CR2_CCUS  0x0004U
#define TIM_CR2_CCDS  0x0008U
#define TIM_CR2_MMS   0x0070U
#define TIM_CR2_MMS_0 0x0010U
#define TIM_CR2_MMS_1 0x0020U
#define TIM_CR2_MMS_2 0x0040U
#define TIM_CR2_TI1S  0x0080U
#define TIM_CR2_OIS1  0x0100U
#define TIM_CR2_OIS1N 0x0200U
#define TIM_CR2_OIS2  0x0400U
#define TIM_CR2_OIS2N 0x0800U
#define TIM_CR2_OIS3  0x1000U
#define TIM_CR2_OIS3N 0x2000U
#define TIM_CR2_OIS4  0x4000U
/*******************  Bit definition for TIM_SMCR register  *******************/
#define TIM_SMCR_SMS    0x0007U
#define TIM_SMCR_SMS_0  0x0001U
#define TIM_SMCR_SMS_1  0x0002U
#define TIM_SMCR_SMS_2  0x0004U
#define TIM_SMCR_TS     0x0070U
#define TIM_SMCR_TS_0   0x0010U
#define TIM_SMCR_TS_1   0x0020U
#define TIM_SMCR_TS_2   0x0040U
#define TIM_SMCR_MSM    0x0080U
#define TIM_SMCR_ETF    0x0F00U
#define TIM_SMCR_ETF_0  0x0100U
#define TIM_SMCR_ETF_1  0x0200U
#define TIM_SMCR_ETF_2  0x0400U
#define TIM_SMCR_ETF_3  0x0800U
#define TIM_SMCR_ETPS   0x3000U
#define TIM_SMCR_ETPS_0 0x1000U
#define TIM_SMCR_ETPS_1 0x2000U
#define TIM_SMCR_ECE    0x4000U
#define TIM_SMCR_ETP    0x8000U
/*******************  Bit definition for TIM_DIER register  *******************/
#define TIM_DIER_UIE   0x0001U
#define TIM_DIER_CC1IE 0x0002U
#define TIM_DIER_CC2IE 0x0004U
#define TIM_DIER_CC3IE 0x0008U
#define TIM_DIER_CC4IE 0x0010U
#define TIM_DIER_COMIE 0x0020U
#define TIM_DIER_TIE   0x0040U
#define TIM_DIER_BIE   0x0080U
#define TIM_DIER_UDE   0x0100U
#define TIM_DIER_CC1DE 0x0200U
#define TIM_DIER_CC2DE 0x0400U
#define TIM_DIER_CC3DE 0x0800U
#define TIM_DIER_CC4DE 0x1000U
#define TIM_DIER_COMDE 0x2000U
#define TIM_DIER_TDE   0x4000U
/********************  Bit definition for TIM_SR register  ********************/
#define TIM_SR_UIF   0x0001U
#define TIM_SR_CC1IF 0x0002U
#define TIM_SR_CC2IF 0x0004U
#define TIM_SR_CC3IF 0x0008U
#define TIM_SR_CC4IF 0x0010U
#define TIM_SR_COMIF 0x0020U
#define TIM_SR_TIF   0x0040U
#define TIM_SR_BIF   0x0080U
#define TIM_SR_CC1OF 0x0200U
#define TIM_SR_CC2OF 0x0400U
#define TIM_SR_CC3OF 0x0800U
#define TIM_SR_CC4OF 0x1000U
/*******************  Bit definition for TIM_EGR register  ********************/
#define TIM_EGR_UG   0x01U
#define TIM_EGR_CC1G 0x02U
#define TIM_EGR_CC2G 0x04U
#define TIM_EGR_CC3G 0x08U
#define TIM_EGR_CC4G 0x10U
#define TIM_EGR_COMG 0x20U
#define TIM_EGR_TG   0x40U
#define TIM_EGR_BG   0x80U
/******************  Bit definition for TIM_CCMR1 register  *******************/
#define TIM_CCMR1_CC1S   0x0003U
#define TIM_CCMR1_CC1S_0 0x0001U
#define TIM_CCMR1_CC1S_1 0x0002U
#define TIM_CCMR1_OC1FE  0x0004U
#define TIM_CCMR1_OC1PE  0x0008U
#define TIM_CCMR1_OC1M   0x0070U
#define TIM_CCMR1_OC1M_0 0x0010U
#define TIM_CCMR1_OC1M_1 0x0020U
#define TIM_CCMR1_OC1M_2 0x0040U
#define TIM_CCMR1_OC1CE  0x0080U
#define TIM_CCMR1_CC2S   0x0300U
#define TIM_CCMR1_CC2S_0 0x0100U
#define TIM_CCMR1_CC2S_1 0x0200U
#define TIM_CCMR1_OC2FE  0x0400U
#define TIM_CCMR1_OC2PE  0x0800U
#define TIM_CCMR1_OC2M   0x7000U
#define TIM_CCMR1_OC2M_0 0x1000U
#define TIM_CCMR1_OC2M_1 0x2000U
#define TIM_CCMR1_OC2M_2 0x4000U
#define TIM_CCMR1_OC2CE  0x8000U
    /*----------------------------------------------------------------------------*/

#define TIM_CCMR1_IC1PSC   0x000CU
#define TIM_CCMR1_IC1PSC_0 0x0004U
#define TIM_CCMR1_IC1PSC_1 0x0008U
#define TIM_CCMR1_IC1F     0x00F0U
#define TIM_CCMR1_IC1F_0   0x0010U
#define TIM_CCMR1_IC1F_1   0x0020U
#define TIM_CCMR1_IC1F_2   0x0040U
#define TIM_CCMR1_IC1F_3   0x0080U
#define TIM_CCMR1_IC2PSC   0x0C00U
#define TIM_CCMR1_IC2PSC_0 0x0400U
#define TIM_CCMR1_IC2PSC_1 0x0800U
#define TIM_CCMR1_IC2F     0xF000U
#define TIM_CCMR1_IC2F_0   0x1000U
#define TIM_CCMR1_IC2F_1   0x2000U
#define TIM_CCMR1_IC2F_2   0x4000U
#define TIM_CCMR1_IC2F_3   0x8000U
/******************  Bit definition for TIM_CCMR2 register  *******************/
#define TIM_CCMR2_CC3S   0x0003U
#define TIM_CCMR2_CC3S_0 0x0001U
#define TIM_CCMR2_CC3S_1 0x0002U
#define TIM_CCMR2_OC3FE  0x0004U
#define TIM_CCMR2_OC3PE  0x0008U
#define TIM_CCMR2_OC3M   0x0070U
#define TIM_CCMR2_OC3M_0 0x0010U
#define TIM_CCMR2_OC3M_1 0x0020U
#define TIM_CCMR2_OC3M_2 0x0040U
#define TIM_CCMR2_OC3CE  0x0080U
#define TIM_CCMR2_CC4S   0x0300U
#define TIM_CCMR2_CC4S_0 0x0100U
#define TIM_CCMR2_CC4S_1 0x0200U
#define TIM_CCMR2_OC4FE  0x0400U
#define TIM_CCMR2_OC4PE  0x0800U
#define TIM_CCMR2_OC4M   0x7000U
#define TIM_CCMR2_OC4M_0 0x1000U
#define TIM_CCMR2_OC4M_1 0x2000U
#define TIM_CCMR2_OC4M_2 0x4000U
#define TIM_CCMR2_OC4CE  0x8000U
    /*----------------------------------------------------------------------------*/

#define TIM_CCMR2_IC3PSC   0x000CU
#define TIM_CCMR2_IC3PSC_0 0x0004U
#define TIM_CCMR2_IC3PSC_1 0x0008U
#define TIM_CCMR2_IC3F     0x00F0U
#define TIM_CCMR2_IC3F_0   0x0010U
#define TIM_CCMR2_IC3F_1   0x0020U
#define TIM_CCMR2_IC3F_2   0x0040U
#define TIM_CCMR2_IC3F_3   0x0080U
#define TIM_CCMR2_IC4PSC   0x0C00U
#define TIM_CCMR2_IC4PSC_0 0x0400U
#define TIM_CCMR2_IC4PSC_1 0x0800U
#define TIM_CCMR2_IC4F     0xF000U
#define TIM_CCMR2_IC4F_0   0x1000U
#define TIM_CCMR2_IC4F_1   0x2000U
#define TIM_CCMR2_IC4F_2   0x4000U
#define TIM_CCMR2_IC4F_3   0x8000U
/*******************  Bit definition for TIM_CCER register  *******************/
#define TIM_CCER_CC1E  0x0001U
#define TIM_CCER_CC1P  0x0002U
#define TIM_CCER_CC1NE 0x0004U
#define TIM_CCER_CC1NP 0x0008U
#define TIM_CCER_CC2E  0x0010U
#define TIM_CCER_CC2P  0x0020U
#define TIM_CCER_CC2NE 0x0040U
#define TIM_CCER_CC2NP 0x0080U
#define TIM_CCER_CC3E  0x0100U
#define TIM_CCER_CC3P  0x0200U
#define TIM_CCER_CC3NE 0x0400U
#define TIM_CCER_CC3NP 0x0800U
#define TIM_CCER_CC4E  0x1000U
#define TIM_CCER_CC4P  0x2000U
#define TIM_CCER_CC4NP 0x8000U
/*******************  Bit definition for TIM_CNT register  ********************/
#define TIM_CNT_CNT 0xFFFFU
/*******************  Bit definition for TIM_PSC register  ********************/
#define TIM_PSC_PSC 0xFFFFU
/*******************  Bit definition for TIM_ARR register  ********************/
#define TIM_ARR_ARR 0xFFFFU
/*******************  Bit definition for TIM_RCR register  ********************/
#define TIM_RCR_REP 0xFFU
/*******************  Bit definition for TIM_CCR1 register  *******************/
#define TIM_CCR1_CCR1 0xFFFFU
/*******************  Bit definition for TIM_CCR2 register  *******************/
#define TIM_CCR2_CCR2 0xFFFFU
/*******************  Bit definition for TIM_CCR3 register  *******************/
#define TIM_CCR3_CCR3 0xFFFFU
/*******************  Bit definition for TIM_CCR4 register  *******************/
#define TIM_CCR4_CCR4 0xFFFFU
/*******************  Bit definition for TIM_BDTR register  *******************/
#define TIM_BDTR_DTG    0x00FFU
#define TIM_BDTR_DTG_0  0x0001U
#define TIM_BDTR_DTG_1  0x0002U
#define TIM_BDTR_DTG_2  0x0004U
#define TIM_BDTR_DTG_3  0x0008U
#define TIM_BDTR_DTG_4  0x0010U
#define TIM_BDTR_DTG_5  0x0020U
#define TIM_BDTR_DTG_6  0x0040U
#define TIM_BDTR_DTG_7  0x0080U
#define TIM_BDTR_LOCK   0x0300U
#define TIM_BDTR_LOCK_0 0x0100U
#define TIM_BDTR_LOCK_1 0x0200U
#define TIM_BDTR_OSSI   0x0400U
#define TIM_BDTR_OSSR   0x0800U
#define TIM_BDTR_BKE    0x1000U
#define TIM_BDTR_BKP    0x2000U
#define TIM_BDTR_AOE    0x4000U
#define TIM_BDTR_MOE    0x8000U
/*******************  Bit definition for TIM_DCR register  ********************/
#define TIM_DCR_DBA   0x001FU
#define TIM_DCR_DBA_0 0x0001U
#define TIM_DCR_DBA_1 0x0002U
#define TIM_DCR_DBA_2 0x0004U
#define TIM_DCR_DBA_3 0x0008U
#define TIM_DCR_DBA_4 0x0010U
#define TIM_DCR_DBL   0x1F00U
#define TIM_DCR_DBL_0 0x0100U
#define TIM_DCR_DBL_1 0x0200U
#define TIM_DCR_DBL_2 0x0400U
#define TIM_DCR_DBL_3 0x0800U
#define TIM_DCR_DBL_4 0x1000U
/*******************  Bit definition for TIM_DMAR register  *******************/
#define TIM_DMAR_DMAB 0xFFFFU
/*******************  Bit definition for TIM_OR register  *********************/
#define TIM_OR_TI4_RMP    0x00C0U
#define TIM_OR_TI4_RMP_0  0x0040U
#define TIM_OR_TI4_RMP_1  0x0080U
#define TIM_OR_ITR1_RMP   0x0C00U
#define TIM_OR_ITR1_RMP_0 0x0400U
#define TIM_OR_ITR1_RMP_1 0x0800U
/******************************************************************************/
/*                                                                            */
/*         Universal Synchronous Asynchronous Receiver Transmitter            */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for USART_SR register  *******************/
#define USART_SR_PE   0x0001U
#define USART_SR_FE   0x0002U
#define USART_SR_NE   0x0004U
#define USART_SR_ORE  0x0008U
#define USART_SR_IDLE 0x0010U
#define USART_SR_RXNE 0x0020U
#define USART_SR_TC   0x0040U
#define USART_SR_TXE  0x0080U
#define USART_SR_LBD  0x0100U
#define USART_SR_CTS  0x0200U
/*******************  Bit definition for USART_DR register  *******************/
#define USART_DR_DR 0x01FFU
/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_Fraction 0x000FU
#define USART_BRR_DIV_Mantissa 0xFFF0U
/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_SBK    0x0001U
#define USART_CR1_RWU    0x0002U
#define USART_CR1_RE     0x0004U
#define USART_CR1_TE     0x0008U
#define USART_CR1_IDLEIE 0x0010U
#define USART_CR1_RXNEIE 0x0020U
#define USART_CR1_TCIE   0x0040U
#define USART_CR1_TXEIE  0x0080U
#define USART_CR1_PEIE   0x0100U
#define USART_CR1_PS     0x0200U
#define USART_CR1_PCE    0x0400U
#define USART_CR1_WAKE   0x0800U
#define USART_CR1_M      0x1000U
#define USART_CR1_UE     0x2000U
#define USART_CR1_OVER8  0x8000U
/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_ADD    0x000FU
#define USART_CR2_LBDL   0x0020U
#define USART_CR2_LBDIE  0x0040U
#define USART_CR2_LBCL   0x0100U
#define USART_CR2_CPHA   0x0200U
#define USART_CR2_CPOL   0x0400U
#define USART_CR2_CLKEN  0x0800U
#define USART_CR2_STOP   0x3000U
#define USART_CR2_STOP_0 0x1000U
#define USART_CR2_STOP_1 0x2000U
#define USART_CR2_LINEN  0x4000U
/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE    0x0001U
#define USART_CR3_IREN   0x0002U
#define USART_CR3_IRLP   0x0004U
#define USART_CR3_HDSEL  0x0008U
#define USART_CR3_NACK   0x0010U
#define USART_CR3_SCEN   0x0020U
#define USART_CR3_DMAR   0x0040U
#define USART_CR3_DMAT   0x0080U
#define USART_CR3_RTSE   0x0100U
#define USART_CR3_CTSE   0x0200U
#define USART_CR3_CTSIE  0x0400U
#define USART_CR3_ONEBIT 0x0800U
/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC   0x00FFU
#define USART_GTPR_PSC_0 0x0001U
#define USART_GTPR_PSC_1 0x0002U
#define USART_GTPR_PSC_2 0x0004U
#define USART_GTPR_PSC_3 0x0008U
#define USART_GTPR_PSC_4 0x0010U
#define USART_GTPR_PSC_5 0x0020U
#define USART_GTPR_PSC_6 0x0040U
#define USART_GTPR_PSC_7 0x0080U
#define USART_GTPR_GT    0xFF00U
/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T   0x7FU
#define WWDG_CR_T_0 0x01U
#define WWDG_CR_T_1 0x02U
#define WWDG_CR_T_2 0x04U
#define WWDG_CR_T_3 0x08U
#define WWDG_CR_T_4 0x10U
#define WWDG_CR_T_5 0x20U
#define WWDG_CR_T_6 0x40U
/* Legacy defines */
#define WWDG_CR_T0 WWDG_CR_T_0
#define WWDG_CR_T1 WWDG_CR_T_1
#define WWDG_CR_T2 WWDG_CR_T_2
#define WWDG_CR_T3 WWDG_CR_T_3
#define WWDG_CR_T4 WWDG_CR_T_4
#define WWDG_CR_T5 WWDG_CR_T_5
#define WWDG_CR_T6 WWDG_CR_T_6

#define WWDG_CR_WDGA 0x80U
/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W   0x007FU
#define WWDG_CFR_W_0 0x0001U
#define WWDG_CFR_W_1 0x0002U
#define WWDG_CFR_W_2 0x0004U
#define WWDG_CFR_W_3 0x0008U
#define WWDG_CFR_W_4 0x0010U
#define WWDG_CFR_W_5 0x0020U
#define WWDG_CFR_W_6 0x0040U
/* Legacy defines */
#define WWDG_CFR_W0 WWDG_CFR_W_0
#define WWDG_CFR_W1 WWDG_CFR_W_1
#define WWDG_CFR_W2 WWDG_CFR_W_2
#define WWDG_CFR_W3 WWDG_CFR_W_3
#define WWDG_CFR_W4 WWDG_CFR_W_4
#define WWDG_CFR_W5 WWDG_CFR_W_5
#define WWDG_CFR_W6 WWDG_CFR_W_6

#define WWDG_CFR_WDGTB   0x0180U
#define WWDG_CFR_WDGTB_0 0x0080U
#define WWDG_CFR_WDGTB_1 0x0100U
/* Legacy defines */
#define WWDG_CFR_WDGTB0 WWDG_CFR_WDGTB_0
#define WWDG_CFR_WDGTB1 WWDG_CFR_WDGTB_1

#define WWDG_CFR_EWI 0x0200U
/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF 0x01U
/******************************************************************************/
/*                                                                            */
/*                                DBG                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define DBGMCU_IDCODE_DEV_ID 0x00000FFFU
#define DBGMCU_IDCODE_REV_ID 0xFFFF0000U

/********************  Bit definition for DBGMCU_CR register  *****************/
#define DBGMCU_CR_DBG_SLEEP   0x00000001U
#define DBGMCU_CR_DBG_STOP    0x00000002U
#define DBGMCU_CR_DBG_STANDBY 0x00000004U
#define DBGMCU_CR_TRACE_IOEN  0x00000020U

#define DBGMCU_CR_TRACE_MODE   0x000000C0U
#define DBGMCU_CR_TRACE_MODE_0 0x00000040U
#define DBGMCU_CR_TRACE_MODE_1 0x00000080U
/********************  Bit definition for DBGMCU_APB1_FZ register  ************/
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP          0x00000001U
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP          0x00000002U
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP          0x00000004U
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP          0x00000008U
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP          0x00000010U
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP          0x00000020U
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP         0x00000040U
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP         0x00000080U
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP         0x00000100U
#define DBGMCU_APB1_FZ_DBG_RTC_STOP           0x00000400U
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP          0x00000800U
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP          0x00001000U
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT 0x00200000U
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT 0x00400000U
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT 0x00800000U
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP          0x02000000U
#define DBGMCU_APB1_FZ_DBG_CAN2_STOP          0x04000000U
/* Old IWDGSTOP bit definition, maintained for legacy purpose */
#define DBGMCU_APB1_FZ_DBG_IWDEG_STOP DBGMCU_APB1_FZ_DBG_IWDG_STOP

/********************  Bit definition for DBGMCU_APB2_FZ register  ************/
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP  0x00000001U
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP  0x00000002U
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP  0x00010000U
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP 0x00020000U
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP 0x00040000U

/******************************************************************************/
/*                                                                            */
/*                                       USB_OTG                              */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for USB_OTG_GOTGCTL register  ********************/
#define USB_OTG_GOTGCTL_SRQSCS    0x00000001U
#define USB_OTG_GOTGCTL_SRQ       0x00000002U
#define USB_OTG_GOTGCTL_VBVALOEN  0x00000004U
#define USB_OTG_GOTGCTL_VBVALOVAL 0x00000008U
#define USB_OTG_GOTGCTL_AVALOEN   0x00000010U
#define USB_OTG_GOTGCTL_AVALOVAL  0x00000020U
#define USB_OTG_GOTGCTL_BVALOEN   0x00000040U
#define USB_OTG_GOTGCTL_BVALOVAL  0x00000080U
#define USB_OTG_GOTGCTL_HNGSCS    0x00000100U
#define USB_OTG_GOTGCTL_HNPRQ     0x00000200U
#define USB_OTG_GOTGCTL_HSHNPEN   0x00000400U
#define USB_OTG_GOTGCTL_DHNPEN    0x00000800U
#define USB_OTG_GOTGCTL_EHEN      0x00001000U
#define USB_OTG_GOTGCTL_CIDSTS    0x00010000U
#define USB_OTG_GOTGCTL_DBCT      0x00020000U
#define USB_OTG_GOTGCTL_ASVLD     0x00040000U
#define USB_OTG_GOTGCTL_BSESVLD   0x00080000U
#define USB_OTG_GOTGCTL_OTGVER    0x00100000U
    /********************  Bit definition for USB_OTG_HCFG register  ********************/

#define USB_OTG_HCFG_FSLSPCS   0x00000003U
#define USB_OTG_HCFG_FSLSPCS_0 0x00000001U
#define USB_OTG_HCFG_FSLSPCS_1 0x00000002U
#define USB_OTG_HCFG_FSLSS     0x00000004U
    /********************  Bit definition for USB_OTG_DCFG register  ********************/

#define USB_OTG_DCFG_DSPD        0x00000003U
#define USB_OTG_DCFG_DSPD_0      0x00000001U
#define USB_OTG_DCFG_DSPD_1      0x00000002U
#define USB_OTG_DCFG_NZLSOHSK    0x00000004U
#define USB_OTG_DCFG_DAD         0x000007F0U
#define USB_OTG_DCFG_DAD_0       0x00000010U
#define USB_OTG_DCFG_DAD_1       0x00000020U
#define USB_OTG_DCFG_DAD_2       0x00000040U
#define USB_OTG_DCFG_DAD_3       0x00000080U
#define USB_OTG_DCFG_DAD_4       0x00000100U
#define USB_OTG_DCFG_DAD_5       0x00000200U
#define USB_OTG_DCFG_DAD_6       0x00000400U
#define USB_OTG_DCFG_PFIVL       0x00001800U
#define USB_OTG_DCFG_PFIVL_0     0x00000800U
#define USB_OTG_DCFG_PFIVL_1     0x00001000U
#define USB_OTG_DCFG_PERSCHIVL   0x03000000U
#define USB_OTG_DCFG_PERSCHIVL_0 0x01000000U
#define USB_OTG_DCFG_PERSCHIVL_1 0x02000000U
/********************  Bit definition for USB_OTG_PCGCR register  ********************/
#define USB_OTG_PCGCR_STPPCLK  0x00000001U
#define USB_OTG_PCGCR_GATEHCLK 0x00000002U
#define USB_OTG_PCGCR_PHYSUSP  0x00000010U
/********************  Bit definition for USB_OTG_GOTGINT register  ********************/
#define USB_OTG_GOTGINT_SEDET   0x00000004U
#define USB_OTG_GOTGINT_SRSSCHG 0x00000100U
#define USB_OTG_GOTGINT_HNSSCHG 0x00000200U
#define USB_OTG_GOTGINT_HNGDET  0x00020000U
#define USB_OTG_GOTGINT_ADTOCHG 0x00040000U
#define USB_OTG_GOTGINT_DBCDNE  0x00080000U
#define USB_OTG_GOTGINT_IDCHNG  0x00100000U
/********************  Bit definition for USB_OTG_DCTL register  ********************/
#define USB_OTG_DCTL_RWUSIG   0x00000001U
#define USB_OTG_DCTL_SDIS     0x00000002U
#define USB_OTG_DCTL_GINSTS   0x00000004U
#define USB_OTG_DCTL_GONSTS   0x00000008U
#define USB_OTG_DCTL_TCTL     0x00000070U
#define USB_OTG_DCTL_TCTL_0   0x00000010U
#define USB_OTG_DCTL_TCTL_1   0x00000020U
#define USB_OTG_DCTL_TCTL_2   0x00000040U
#define USB_OTG_DCTL_SGINAK   0x00000080U
#define USB_OTG_DCTL_CGINAK   0x00000100U
#define USB_OTG_DCTL_SGONAK   0x00000200U
#define USB_OTG_DCTL_CGONAK   0x00000400U
#define USB_OTG_DCTL_POPRGDNE 0x00000800U
/********************  Bit definition for USB_OTG_HFIR register  ********************/
#define USB_OTG_HFIR_FRIVL 0x0000FFFFU
/********************  Bit definition for USB_OTG_HFNUM register  ********************/
#define USB_OTG_HFNUM_FRNUM 0x0000FFFFU
#define USB_OTG_HFNUM_FTREM 0xFFFF0000U
/********************  Bit definition for USB_OTG_DSTS register  ********************/
#define USB_OTG_DSTS_SUSPSTS   0x00000001U
#define USB_OTG_DSTS_ENUMSPD   0x00000006U
#define USB_OTG_DSTS_ENUMSPD_0 0x00000002U
#define USB_OTG_DSTS_ENUMSPD_1 0x00000004U
#define USB_OTG_DSTS_EERR      0x00000008U
#define USB_OTG_DSTS_FNSOF     0x003FFF00U
/********************  Bit definition for USB_OTG_GAHBCFG register  ********************/
#define USB_OTG_GAHBCFG_GINT      0x00000001U
#define USB_OTG_GAHBCFG_HBSTLEN   0x0000001EU
#define USB_OTG_GAHBCFG_HBSTLEN_0 0x00000002U
#define USB_OTG_GAHBCFG_HBSTLEN_1 0x00000004U
#define USB_OTG_GAHBCFG_HBSTLEN_2 0x00000008U
#define USB_OTG_GAHBCFG_HBSTLEN_3 0x00000010U
#define USB_OTG_GAHBCFG_DMAEN     0x00000020U
#define USB_OTG_GAHBCFG_TXFELVL   0x00000080U
#define USB_OTG_GAHBCFG_PTXFELVL  0x00000100U
    /********************  Bit definition for USB_OTG_GUSBCFG register  ********************/

#define USB_OTG_GUSBCFG_TOCAL      0x00000007U
#define USB_OTG_GUSBCFG_TOCAL_0    0x00000001U
#define USB_OTG_GUSBCFG_TOCAL_1    0x00000002U
#define USB_OTG_GUSBCFG_TOCAL_2    0x00000004U
#define USB_OTG_GUSBCFG_PHYSEL     0x00000040U
#define USB_OTG_GUSBCFG_SRPCAP     0x00000100U
#define USB_OTG_GUSBCFG_HNPCAP     0x00000200U
#define USB_OTG_GUSBCFG_TRDT       0x00003C00U
#define USB_OTG_GUSBCFG_TRDT_0     0x00000400U
#define USB_OTG_GUSBCFG_TRDT_1     0x00000800U
#define USB_OTG_GUSBCFG_TRDT_2     0x00001000U
#define USB_OTG_GUSBCFG_TRDT_3     0x00002000U
#define USB_OTG_GUSBCFG_PHYLPCS    0x00008000U
#define USB_OTG_GUSBCFG_ULPIFSLS   0x00020000U
#define USB_OTG_GUSBCFG_ULPIAR     0x00040000U
#define USB_OTG_GUSBCFG_ULPICSM    0x00080000U
#define USB_OTG_GUSBCFG_ULPIEVBUSD 0x00100000U
#define USB_OTG_GUSBCFG_ULPIEVBUSI 0x00200000U
#define USB_OTG_GUSBCFG_TSDPS      0x00400000U
#define USB_OTG_GUSBCFG_PCCI       0x00800000U
#define USB_OTG_GUSBCFG_PTCI       0x01000000U
#define USB_OTG_GUSBCFG_ULPIIPD    0x02000000U
#define USB_OTG_GUSBCFG_FHMOD      0x20000000U
#define USB_OTG_GUSBCFG_FDMOD      0x40000000U
#define USB_OTG_GUSBCFG_CTXPKT     0x80000000U
/********************  Bit definition for USB_OTG_GRSTCTL register  ********************/
#define USB_OTG_GRSTCTL_CSRST    0x00000001U
#define USB_OTG_GRSTCTL_HSRST    0x00000002U
#define USB_OTG_GRSTCTL_FCRST    0x00000004U
#define USB_OTG_GRSTCTL_RXFFLSH  0x00000010U
#define USB_OTG_GRSTCTL_TXFFLSH  0x00000020U
#define USB_OTG_GRSTCTL_TXFNUM   0x000007C0U
#define USB_OTG_GRSTCTL_TXFNUM_0 0x00000040U
#define USB_OTG_GRSTCTL_TXFNUM_1 0x00000080U
#define USB_OTG_GRSTCTL_TXFNUM_2 0x00000100U
#define USB_OTG_GRSTCTL_TXFNUM_3 0x00000200U
#define USB_OTG_GRSTCTL_TXFNUM_4 0x00000400U
#define USB_OTG_GRSTCTL_DMAREQ   0x40000000U
#define USB_OTG_GRSTCTL_AHBIDL   0x80000000U
/********************  Bit definition for USB_OTG_DIEPMSK register  ********************/
#define USB_OTG_DIEPMSK_XFRCM     0x00000001U
#define USB_OTG_DIEPMSK_EPDM      0x00000002U
#define USB_OTG_DIEPMSK_TOM       0x00000008U
#define USB_OTG_DIEPMSK_ITTXFEMSK 0x00000010U
#define USB_OTG_DIEPMSK_INEPNMM   0x00000020U
#define USB_OTG_DIEPMSK_INEPNEM   0x00000040U
#define USB_OTG_DIEPMSK_TXFURM    0x00000100U
#define USB_OTG_DIEPMSK_BIM       0x00000200U
/********************  Bit definition for USB_OTG_HPTXSTS register  ********************/
#define USB_OTG_HPTXSTS_PTXFSAVL  0x0000FFFFU
#define USB_OTG_HPTXSTS_PTXQSAV   0x00FF0000U
#define USB_OTG_HPTXSTS_PTXQSAV_0 0x00010000U
#define USB_OTG_HPTXSTS_PTXQSAV_1 0x00020000U
#define USB_OTG_HPTXSTS_PTXQSAV_2 0x00040000U
#define USB_OTG_HPTXSTS_PTXQSAV_3 0x00080000U
#define USB_OTG_HPTXSTS_PTXQSAV_4 0x00100000U
#define USB_OTG_HPTXSTS_PTXQSAV_5 0x00200000U
#define USB_OTG_HPTXSTS_PTXQSAV_6 0x00400000U
#define USB_OTG_HPTXSTS_PTXQSAV_7 0x00800000U
#define USB_OTG_HPTXSTS_PTXQTOP   0xFF000000U
#define USB_OTG_HPTXSTS_PTXQTOP_0 0x01000000U
#define USB_OTG_HPTXSTS_PTXQTOP_1 0x02000000U
#define USB_OTG_HPTXSTS_PTXQTOP_2 0x04000000U
#define USB_OTG_HPTXSTS_PTXQTOP_3 0x08000000U
#define USB_OTG_HPTXSTS_PTXQTOP_4 0x10000000U
#define USB_OTG_HPTXSTS_PTXQTOP_5 0x20000000U
#define USB_OTG_HPTXSTS_PTXQTOP_6 0x40000000U
#define USB_OTG_HPTXSTS_PTXQTOP_7 0x80000000U
/********************  Bit definition for USB_OTG_HAINT register  ********************/
#define USB_OTG_HAINT_HAINT 0x0000FFFFU
/********************  Bit definition for USB_OTG_DOEPMSK register  ********************/
#define USB_OTG_DOEPMSK_XFRCM    0x00000001U
#define USB_OTG_DOEPMSK_EPDM     0x00000002U
#define USB_OTG_DOEPMSK_STUPM    0x00000008U
#define USB_OTG_DOEPMSK_OTEPDM   0x00000010U
#define USB_OTG_DOEPMSK_OTEPSPRM 0x00000020U
#define USB_OTG_DOEPMSK_B2BSTUP  0x00000040U
#define USB_OTG_DOEPMSK_OPEM     0x00000100U
#define USB_OTG_DOEPMSK_BOIM     0x00000200U
/********************  Bit definition for USB_OTG_GINTSTS register  ********************/
#define USB_OTG_GINTSTS_CMOD              0x00000001U
#define USB_OTG_GINTSTS_MMIS              0x00000002U
#define USB_OTG_GINTSTS_OTGINT            0x00000004U
#define USB_OTG_GINTSTS_SOF               0x00000008U
#define USB_OTG_GINTSTS_RXFLVL            0x00000010U
#define USB_OTG_GINTSTS_NPTXFE            0x00000020U
#define USB_OTG_GINTSTS_GINAKEFF          0x00000040U
#define USB_OTG_GINTSTS_BOUTNAKEFF        0x00000080U
#define USB_OTG_GINTSTS_ESUSP             0x00000400U
#define USB_OTG_GINTSTS_USBSUSP           0x00000800U
#define USB_OTG_GINTSTS_USBRST            0x00001000U
#define USB_OTG_GINTSTS_ENUMDNE           0x00002000U
#define USB_OTG_GINTSTS_ISOODRP           0x00004000U
#define USB_OTG_GINTSTS_EOPF              0x00008000U
#define USB_OTG_GINTSTS_IEPINT            0x00040000U
#define USB_OTG_GINTSTS_OEPINT            0x00080000U
#define USB_OTG_GINTSTS_IISOIXFR          0x00100000U
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT 0x00200000U
#define USB_OTG_GINTSTS_DATAFSUSP         0x00400000U
#define USB_OTG_GINTSTS_RSTDET            0x00800000U
#define USB_OTG_GINTSTS_HPRTINT           0x01000000U
#define USB_OTG_GINTSTS_HCINT             0x02000000U
#define USB_OTG_GINTSTS_PTXFE             0x04000000U
#define USB_OTG_GINTSTS_LPMINT            0x08000000U
#define USB_OTG_GINTSTS_CIDSCHG           0x10000000U
#define USB_OTG_GINTSTS_DISCINT           0x20000000U
#define USB_OTG_GINTSTS_SRQINT            0x40000000U
#define USB_OTG_GINTSTS_WKUINT            0x80000000U
/********************  Bit definition for USB_OTG_GINTMSK register  ********************/
#define USB_OTG_GINTMSK_MMISM           0x00000002U
#define USB_OTG_GINTMSK_OTGINT          0x00000004U
#define USB_OTG_GINTMSK_SOFM            0x00000008U
#define USB_OTG_GINTMSK_RXFLVLM         0x00000010U
#define USB_OTG_GINTMSK_NPTXFEM         0x00000020U
#define USB_OTG_GINTMSK_GINAKEFFM       0x00000040U
#define USB_OTG_GINTMSK_GONAKEFFM       0x00000080U
#define USB_OTG_GINTMSK_ESUSPM          0x00000400U
#define USB_OTG_GINTMSK_USBSUSPM        0x00000800U
#define USB_OTG_GINTMSK_USBRST          0x00001000U
#define USB_OTG_GINTMSK_ENUMDNEM        0x00002000U
#define USB_OTG_GINTMSK_ISOODRPM        0x00004000U
#define USB_OTG_GINTMSK_EOPFM           0x00008000U
#define USB_OTG_GINTMSK_EPMISM          0x00020000U
#define USB_OTG_GINTMSK_IEPINT          0x00040000U
#define USB_OTG_GINTMSK_OEPINT          0x00080000U
#define USB_OTG_GINTMSK_IISOIXFRM       0x00100000U
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM 0x00200000U
#define USB_OTG_GINTMSK_FSUSPM          0x00400000U
#define USB_OTG_GINTMSK_RSTDEM          0x00800000U
#define USB_OTG_GINTMSK_PRTIM           0x01000000U
#define USB_OTG_GINTMSK_HCIM            0x02000000U
#define USB_OTG_GINTMSK_PTXFEM          0x04000000U
#define USB_OTG_GINTMSK_LPMINTM         0x08000000U
#define USB_OTG_GINTMSK_CIDSCHGM        0x10000000U
#define USB_OTG_GINTMSK_DISCINT         0x20000000U
#define USB_OTG_GINTMSK_SRQIM           0x40000000U
#define USB_OTG_GINTMSK_WUIM            0x80000000U
/********************  Bit definition for USB_OTG_DAINT register  ********************/
#define USB_OTG_DAINT_IEPINT 0x0000FFFFU
#define USB_OTG_DAINT_OEPINT 0xFFFF0000U
/********************  Bit definition for USB_OTG_HAINTMSK register  ********************/
#define USB_OTG_HAINTMSK_HAINTM 0x0000FFFFU
/********************  Bit definition for USB_OTG_GRXSTSP register  ********************/
#define USB_OTG_GRXSTSP_EPNUM  0x0000000FU
#define USB_OTG_GRXSTSP_BCNT   0x00007FF0U
#define USB_OTG_GRXSTSP_DPID   0x00018000U
#define USB_OTG_GRXSTSP_PKTSTS 0x001E0000U
/********************  Bit definition for USB_OTG_DAINTMSK register  ********************/
#define USB_OTG_DAINTMSK_IEPM 0x0000FFFFU
#define USB_OTG_DAINTMSK_OEPM 0xFFFF0000U
    /********************  Bit definition for OTG register  ********************/

#define USB_OTG_CHNUM    0x0000000FU
#define USB_OTG_CHNUM_0  0x00000001U
#define USB_OTG_CHNUM_1  0x00000002U
#define USB_OTG_CHNUM_2  0x00000004U
#define USB_OTG_CHNUM_3  0x00000008U
#define USB_OTG_BCNT     0x00007FF0U
#define USB_OTG_DPID     0x00018000U
#define USB_OTG_DPID_0   0x00008000U
#define USB_OTG_DPID_1   0x00010000U
#define USB_OTG_PKTSTS   0x001E0000U
#define USB_OTG_PKTSTS_0 0x00020000U
#define USB_OTG_PKTSTS_1 0x00040000U
#define USB_OTG_PKTSTS_2 0x00080000U
#define USB_OTG_PKTSTS_3 0x00100000U
#define USB_OTG_EPNUM    0x0000000FU
#define USB_OTG_EPNUM_0  0x00000001U
#define USB_OTG_EPNUM_1  0x00000002U
#define USB_OTG_EPNUM_2  0x00000004U
#define USB_OTG_EPNUM_3  0x00000008U
#define USB_OTG_FRMNUM   0x01E00000U
#define USB_OTG_FRMNUM_0 0x00200000U
#define USB_OTG_FRMNUM_1 0x00400000U
#define USB_OTG_FRMNUM_2 0x00800000U
#define USB_OTG_FRMNUM_3 0x01000000U
    /********************  Bit definition for OTG register  ********************/

#define USB_OTG_CHNUM    0x0000000FU
#define USB_OTG_CHNUM_0  0x00000001U
#define USB_OTG_CHNUM_1  0x00000002U
#define USB_OTG_CHNUM_2  0x00000004U
#define USB_OTG_CHNUM_3  0x00000008U
#define USB_OTG_BCNT     0x00007FF0U
#define USB_OTG_DPID     0x00018000U
#define USB_OTG_DPID_0   0x00008000U
#define USB_OTG_DPID_1   0x00010000U
#define USB_OTG_PKTSTS   0x001E0000U
#define USB_OTG_PKTSTS_0 0x00020000U
#define USB_OTG_PKTSTS_1 0x00040000U
#define USB_OTG_PKTSTS_2 0x00080000U
#define USB_OTG_PKTSTS_3 0x00100000U
#define USB_OTG_EPNUM    0x0000000FU
#define USB_OTG_EPNUM_0  0x00000001U
#define USB_OTG_EPNUM_1  0x00000002U
#define USB_OTG_EPNUM_2  0x00000004U
#define USB_OTG_EPNUM_3  0x00000008U
#define USB_OTG_FRMNUM   0x01E00000U
#define USB_OTG_FRMNUM_0 0x00200000U
#define USB_OTG_FRMNUM_1 0x00400000U
#define USB_OTG_FRMNUM_2 0x00800000U
#define USB_OTG_FRMNUM_3 0x01000000U
/********************  Bit definition for USB_OTG_GRXFSIZ register  ********************/
#define USB_OTG_GRXFSIZ_RXFD 0x0000FFFFU
/********************  Bit definition for USB_OTG_DVBUSDIS register  ********************/
#define USB_OTG_DVBUSDIS_VBUSDT 0x0000FFFFU
/********************  Bit definition for OTG register  ********************/
#define USB_OTG_NPTXFSA 0x0000FFFFU
#define USB_OTG_NPTXFD  0xFFFF0000U
#define USB_OTG_TX0FSA  0x0000FFFFU
#define USB_OTG_TX0FD   0xFFFF0000U
/********************  Bit definition for USB_OTG_DVBUSPULSE register  ********************/
#define USB_OTG_DVBUSPULSE_DVBUSP 0x00000FFFU
/********************  Bit definition for USB_OTG_GNPTXSTS register  ********************/
#define USB_OTG_GNPTXSTS_NPTXFSAV   0x0000FFFFU
#define USB_OTG_GNPTXSTS_NPTQXSAV   0x00FF0000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_0 0x00010000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_1 0x00020000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_2 0x00040000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_3 0x00080000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_4 0x00100000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_5 0x00200000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_6 0x00400000U
#define USB_OTG_GNPTXSTS_NPTQXSAV_7 0x00800000U
#define USB_OTG_GNPTXSTS_NPTXQTOP   0x7F000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_0 0x01000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_1 0x02000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_2 0x04000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_3 0x08000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_4 0x10000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_5 0x20000000U
#define USB_OTG_GNPTXSTS_NPTXQTOP_6 0x40000000U
/********************  Bit definition for USB_OTG_DTHRCTL register  ********************/
#define USB_OTG_DTHRCTL_NONISOTHREN 0x00000001U
#define USB_OTG_DTHRCTL_ISOTHREN    0x00000002U
#define USB_OTG_DTHRCTL_TXTHRLEN    0x000007FCU
#define USB_OTG_DTHRCTL_TXTHRLEN_0  0x00000004U
#define USB_OTG_DTHRCTL_TXTHRLEN_1  0x00000008U
#define USB_OTG_DTHRCTL_TXTHRLEN_2  0x00000010U
#define USB_OTG_DTHRCTL_TXTHRLEN_3  0x00000020U
#define USB_OTG_DTHRCTL_TXTHRLEN_4  0x00000040U
#define USB_OTG_DTHRCTL_TXTHRLEN_5  0x00000080U
#define USB_OTG_DTHRCTL_TXTHRLEN_6  0x00000100U
#define USB_OTG_DTHRCTL_TXTHRLEN_7  0x00000200U
#define USB_OTG_DTHRCTL_TXTHRLEN_8  0x00000400U
#define USB_OTG_DTHRCTL_RXTHREN     0x00010000U
#define USB_OTG_DTHRCTL_RXTHRLEN    0x03FE0000U
#define USB_OTG_DTHRCTL_RXTHRLEN_0  0x00020000U
#define USB_OTG_DTHRCTL_RXTHRLEN_1  0x00040000U
#define USB_OTG_DTHRCTL_RXTHRLEN_2  0x00080000U
#define USB_OTG_DTHRCTL_RXTHRLEN_3  0x00100000U
#define USB_OTG_DTHRCTL_RXTHRLEN_4  0x00200000U
#define USB_OTG_DTHRCTL_RXTHRLEN_5  0x00400000U
#define USB_OTG_DTHRCTL_RXTHRLEN_6  0x00800000U
#define USB_OTG_DTHRCTL_RXTHRLEN_7  0x01000000U
#define USB_OTG_DTHRCTL_RXTHRLEN_8  0x02000000U
#define USB_OTG_DTHRCTL_ARPEN       0x08000000U
/********************  Bit definition for USB_OTG_DIEPEMPMSK register  ********************/
#define USB_OTG_DIEPEMPMSK_INEPTXFEM 0x0000FFFFU
/********************  Bit definition for USB_OTG_DEACHINT register  ********************/
#define USB_OTG_DEACHINT_IEP1INT 0x00000002U
#define USB_OTG_DEACHINT_OEP1INT 0x00020000U
/********************  Bit definition for USB_OTG_GCCFG register  ********************/
#define USB_OTG_GCCFG_PWRDWN 0x00010000U
#define USB_OTG_GCCFG_VBDEN  0x00200000U
/********************  Bit definition for USB_OTG_DEACHINTMSK register  ********************/
#define USB_OTG_DEACHINTMSK_IEP1INTM 0x00000002U
#define USB_OTG_DEACHINTMSK_OEP1INTM 0x00020000U
/********************  Bit definition for USB_OTG_CID register  ********************/
#define USB_OTG_CID_PRODUCT_ID 0xFFFFFFFFU
/********************  Bit definition for USB_OTG_GLPMCFG register  ********************/
#define USB_OTG_GLPMCFG_LPMEN      0x00000001U
#define USB_OTG_GLPMCFG_LPMACK     0x00000002U
#define USB_OTG_GLPMCFG_BESL       0x0000003CU
#define USB_OTG_GLPMCFG_REMWAKE    0x00000040U
#define USB_OTG_GLPMCFG_L1SSEN     0x00000080U
#define USB_OTG_GLPMCFG_BESLTHRS   0x00000F00U
#define USB_OTG_GLPMCFG_L1DSEN     0x00001000U
#define USB_OTG_GLPMCFG_LPMRSP     0x00006000U
#define USB_OTG_GLPMCFG_SLPSTS     0x00008000U
#define USB_OTG_GLPMCFG_L1RSMOK    0x00010000U
#define USB_OTG_GLPMCFG_LPMCHIDX   0x001E0000U
#define USB_OTG_GLPMCFG_LPMRCNT    0x00E00000U
#define USB_OTG_GLPMCFG_SNDLPM     0x01000000U
#define USB_OTG_GLPMCFG_LPMRCNTSTS 0x0E000000U
#define USB_OTG_GLPMCFG_ENBESL     0x10000000U
/********************  Bit definition for USB_OTG_DIEPEACHMSK1 register  ********************/
#define USB_OTG_DIEPEACHMSK1_XFRCM     0x00000001U
#define USB_OTG_DIEPEACHMSK1_EPDM      0x00000002U
#define USB_OTG_DIEPEACHMSK1_TOM       0x00000008U
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK 0x00000010U
#define USB_OTG_DIEPEACHMSK1_INEPNMM   0x00000020U
#define USB_OTG_DIEPEACHMSK1_INEPNEM   0x00000040U
#define USB_OTG_DIEPEACHMSK1_TXFURM    0x00000100U
#define USB_OTG_DIEPEACHMSK1_BIM       0x00000200U
#define USB_OTG_DIEPEACHMSK1_NAKM      0x00002000U
/********************  Bit definition for USB_OTG_HPRT register  ********************/
#define USB_OTG_HPRT_PCSTS   0x00000001U
#define USB_OTG_HPRT_PCDET   0x00000002U
#define USB_OTG_HPRT_PENA    0x00000004U
#define USB_OTG_HPRT_PENCHNG 0x00000008U
#define USB_OTG_HPRT_POCA    0x00000010U
#define USB_OTG_HPRT_POCCHNG 0x00000020U
#define USB_OTG_HPRT_PRES    0x00000040U
#define USB_OTG_HPRT_PSUSP   0x00000080U
#define USB_OTG_HPRT_PRST    0x00000100U
#define USB_OTG_HPRT_PLSTS   0x00000C00U
#define USB_OTG_HPRT_PLSTS_0 0x00000400U
#define USB_OTG_HPRT_PLSTS_1 0x00000800U
#define USB_OTG_HPRT_PPWR    0x00001000U
#define USB_OTG_HPRT_PTCTL   0x0001E000U
#define USB_OTG_HPRT_PTCTL_0 0x00002000U
#define USB_OTG_HPRT_PTCTL_1 0x00004000U
#define USB_OTG_HPRT_PTCTL_2 0x00008000U
#define USB_OTG_HPRT_PTCTL_3 0x00010000U
#define USB_OTG_HPRT_PSPD    0x00060000U
#define USB_OTG_HPRT_PSPD_0  0x00020000U
#define USB_OTG_HPRT_PSPD_1  0x00040000U
/********************  Bit definition for USB_OTG_DOEPEACHMSK1 register  ********************/
#define USB_OTG_DOEPEACHMSK1_XFRCM     0x00000001U
#define USB_OTG_DOEPEACHMSK1_EPDM      0x00000002U
#define USB_OTG_DOEPEACHMSK1_TOM       0x00000008U
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK 0x00000010U
#define USB_OTG_DOEPEACHMSK1_INEPNMM   0x00000020U
#define USB_OTG_DOEPEACHMSK1_INEPNEM   0x00000040U
#define USB_OTG_DOEPEACHMSK1_TXFURM    0x00000100U
#define USB_OTG_DOEPEACHMSK1_BIM       0x00000200U
#define USB_OTG_DOEPEACHMSK1_BERRM     0x00001000U
#define USB_OTG_DOEPEACHMSK1_NAKM      0x00002000U
#define USB_OTG_DOEPEACHMSK1_NYETM     0x00004000U
/********************  Bit definition for USB_OTG_HPTXFSIZ register  ********************/
#define USB_OTG_HPTXFSIZ_PTXSA 0x0000FFFFU
#define USB_OTG_HPTXFSIZ_PTXFD 0xFFFF0000U
/********************  Bit definition for USB_OTG_DIEPCTL register  ********************/
#define USB_OTG_DIEPCTL_MPSIZ          0x000007FFU
#define USB_OTG_DIEPCTL_USBAEP         0x00008000U
#define USB_OTG_DIEPCTL_EONUM_DPID     0x00010000U
#define USB_OTG_DIEPCTL_NAKSTS         0x00020000U
#define USB_OTG_DIEPCTL_EPTYP          0x000C0000U
#define USB_OTG_DIEPCTL_EPTYP_0        0x00040000U
#define USB_OTG_DIEPCTL_EPTYP_1        0x00080000U
#define USB_OTG_DIEPCTL_STALL          0x00200000U
#define USB_OTG_DIEPCTL_TXFNUM         0x03C00000U
#define USB_OTG_DIEPCTL_TXFNUM_0       0x00400000U
#define USB_OTG_DIEPCTL_TXFNUM_1       0x00800000U
#define USB_OTG_DIEPCTL_TXFNUM_2       0x01000000U
#define USB_OTG_DIEPCTL_TXFNUM_3       0x02000000U
#define USB_OTG_DIEPCTL_CNAK           0x04000000U
#define USB_OTG_DIEPCTL_SNAK           0x08000000U
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM 0x10000000U
#define USB_OTG_DIEPCTL_SODDFRM        0x20000000U
#define USB_OTG_DIEPCTL_EPDIS          0x40000000U
#define USB_OTG_DIEPCTL_EPENA          0x80000000U
/********************  Bit definition for USB_OTG_HCCHAR register  ********************/
#define USB_OTG_HCCHAR_MPSIZ   0x000007FFU
#define USB_OTG_HCCHAR_EPNUM   0x00007800U
#define USB_OTG_HCCHAR_EPNUM_0 0x00000800U
#define USB_OTG_HCCHAR_EPNUM_1 0x00001000U
#define USB_OTG_HCCHAR_EPNUM_2 0x00002000U
#define USB_OTG_HCCHAR_EPNUM_3 0x00004000U
#define USB_OTG_HCCHAR_EPDIR   0x00008000U
#define USB_OTG_HCCHAR_LSDEV   0x00020000U
#define USB_OTG_HCCHAR_EPTYP   0x000C0000U
#define USB_OTG_HCCHAR_EPTYP_0 0x00040000U
#define USB_OTG_HCCHAR_EPTYP_1 0x00080000U
#define USB_OTG_HCCHAR_MC      0x00300000U
#define USB_OTG_HCCHAR_MC_0    0x00100000U
#define USB_OTG_HCCHAR_MC_1    0x00200000U
#define USB_OTG_HCCHAR_DAD     0x1FC00000U
#define USB_OTG_HCCHAR_DAD_0   0x00400000U
#define USB_OTG_HCCHAR_DAD_1   0x00800000U
#define USB_OTG_HCCHAR_DAD_2   0x01000000U
#define USB_OTG_HCCHAR_DAD_3   0x02000000U
#define USB_OTG_HCCHAR_DAD_4   0x04000000U
#define USB_OTG_HCCHAR_DAD_5   0x08000000U
#define USB_OTG_HCCHAR_DAD_6   0x10000000U
#define USB_OTG_HCCHAR_ODDFRM  0x20000000U
#define USB_OTG_HCCHAR_CHDIS   0x40000000U
#define USB_OTG_HCCHAR_CHENA   0x80000000U
    /********************  Bit definition for USB_OTG_HCSPLT register  ********************/

#define USB_OTG_HCSPLT_PRTADDR   0x0000007FU
#define USB_OTG_HCSPLT_PRTADDR_0 0x00000001U
#define USB_OTG_HCSPLT_PRTADDR_1 0x00000002U
#define USB_OTG_HCSPLT_PRTADDR_2 0x00000004U
#define USB_OTG_HCSPLT_PRTADDR_3 0x00000008U
#define USB_OTG_HCSPLT_PRTADDR_4 0x00000010U
#define USB_OTG_HCSPLT_PRTADDR_5 0x00000020U
#define USB_OTG_HCSPLT_PRTADDR_6 0x00000040U
#define USB_OTG_HCSPLT_HUBADDR   0x00003F80U
#define USB_OTG_HCSPLT_HUBADDR_0 0x00000080U
#define USB_OTG_HCSPLT_HUBADDR_1 0x00000100U
#define USB_OTG_HCSPLT_HUBADDR_2 0x00000200U
#define USB_OTG_HCSPLT_HUBADDR_3 0x00000400U
#define USB_OTG_HCSPLT_HUBADDR_4 0x00000800U
#define USB_OTG_HCSPLT_HUBADDR_5 0x00001000U
#define USB_OTG_HCSPLT_HUBADDR_6 0x00002000U
#define USB_OTG_HCSPLT_XACTPOS   0x0000C000U
#define USB_OTG_HCSPLT_XACTPOS_0 0x00004000U
#define USB_OTG_HCSPLT_XACTPOS_1 0x00008000U
#define USB_OTG_HCSPLT_COMPLSPLT 0x00010000U
#define USB_OTG_HCSPLT_SPLITEN   0x80000000U
/********************  Bit definition for USB_OTG_HCINT register  ********************/
#define USB_OTG_HCINT_XFRC   0x00000001U
#define USB_OTG_HCINT_CHH    0x00000002U
#define USB_OTG_HCINT_AHBERR 0x00000004U
#define USB_OTG_HCINT_STALL  0x00000008U
#define USB_OTG_HCINT_NAK    0x00000010U
#define USB_OTG_HCINT_ACK    0x00000020U
#define USB_OTG_HCINT_NYET   0x00000040U
#define USB_OTG_HCINT_TXERR  0x00000080U
#define USB_OTG_HCINT_BBERR  0x00000100U
#define USB_OTG_HCINT_FRMOR  0x00000200U
#define USB_OTG_HCINT_DTERR  0x00000400U
/********************  Bit definition for USB_OTG_DIEPINT register  ********************/
#define USB_OTG_DIEPINT_XFRC       0x00000001U
#define USB_OTG_DIEPINT_EPDISD     0x00000002U
#define USB_OTG_DIEPINT_TOC        0x00000008U
#define USB_OTG_DIEPINT_ITTXFE     0x00000010U
#define USB_OTG_DIEPINT_INEPNE     0x00000040U
#define USB_OTG_DIEPINT_TXFE       0x00000080U
#define USB_OTG_DIEPINT_TXFIFOUDRN 0x00000100U
#define USB_OTG_DIEPINT_BNA        0x00000200U
#define USB_OTG_DIEPINT_PKTDRPSTS  0x00000800U
#define USB_OTG_DIEPINT_BERR       0x00001000U
#define USB_OTG_DIEPINT_NAK        0x00002000U
/********************  Bit definition for USB_OTG_HCINTMSK register  ********************/
#define USB_OTG_HCINTMSK_XFRCM  0x00000001U
#define USB_OTG_HCINTMSK_CHHM   0x00000002U
#define USB_OTG_HCINTMSK_AHBERR 0x00000004U
#define USB_OTG_HCINTMSK_STALLM 0x00000008U
#define USB_OTG_HCINTMSK_NAKM   0x00000010U
#define USB_OTG_HCINTMSK_ACKM   0x00000020U
#define USB_OTG_HCINTMSK_NYET   0x00000040U
#define USB_OTG_HCINTMSK_TXERRM 0x00000080U
#define USB_OTG_HCINTMSK_BBERRM 0x00000100U
#define USB_OTG_HCINTMSK_FRMORM 0x00000200U
#define USB_OTG_HCINTMSK_DTERRM 0x00000400U
    /********************  Bit definition for USB_OTG_DIEPTSIZ register  ********************/

#define USB_OTG_DIEPTSIZ_XFRSIZ 0x0007FFFFU
#define USB_OTG_DIEPTSIZ_PKTCNT 0x1FF80000U
#define USB_OTG_DIEPTSIZ_MULCNT 0x60000000U
/********************  Bit definition for USB_OTG_HCTSIZ register  ********************/
#define USB_OTG_HCTSIZ_XFRSIZ 0x0007FFFFU
#define USB_OTG_HCTSIZ_PKTCNT 0x1FF80000U
#define USB_OTG_HCTSIZ_DOPING 0x80000000U
#define USB_OTG_HCTSIZ_DPID   0x60000000U
#define USB_OTG_HCTSIZ_DPID_0 0x20000000U
#define USB_OTG_HCTSIZ_DPID_1 0x40000000U
/********************  Bit definition for USB_OTG_DIEPDMA register  ********************/
#define USB_OTG_DIEPDMA_DMAADDR 0xFFFFFFFFU
/********************  Bit definition for USB_OTG_HCDMA register  ********************/
#define USB_OTG_HCDMA_DMAADDR 0xFFFFFFFFU
/********************  Bit definition for USB_OTG_DTXFSTS register  ********************/
#define USB_OTG_DTXFSTS_INEPTFSAV 0x0000FFFFU
/********************  Bit definition for USB_OTG_DIEPTXF register  ********************/
#define USB_OTG_DIEPTXF_INEPTXSA 0x0000FFFFU
#define USB_OTG_DIEPTXF_INEPTXFD 0xFFFF0000U
    /********************  Bit definition for USB_OTG_DOEPCTL register  ********************/

#define USB_OTG_DOEPCTL_MPSIZ          0x000007FFU
#define USB_OTG_DOEPCTL_USBAEP         0x00008000U
#define USB_OTG_DOEPCTL_NAKSTS         0x00020000U
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM 0x10000000U
#define USB_OTG_DOEPCTL_SODDFRM        0x20000000U
#define USB_OTG_DOEPCTL_EPTYP          0x000C0000U
#define USB_OTG_DOEPCTL_EPTYP_0        0x00040000U
#define USB_OTG_DOEPCTL_EPTYP_1        0x00080000U
#define USB_OTG_DOEPCTL_SNPM           0x00100000U
#define USB_OTG_DOEPCTL_STALL          0x00200000U
#define USB_OTG_DOEPCTL_CNAK           0x04000000U
#define USB_OTG_DOEPCTL_SNAK           0x08000000U
#define USB_OTG_DOEPCTL_EPDIS          0x40000000U
#define USB_OTG_DOEPCTL_EPENA          0x80000000U
/********************  Bit definition for USB_OTG_DOEPINT register  ********************/
#define USB_OTG_DOEPINT_XFRC    0x00000001U
#define USB_OTG_DOEPINT_EPDISD  0x00000002U
#define USB_OTG_DOEPINT_STUP    0x00000008U
#define USB_OTG_DOEPINT_OTEPDIS 0x00000010U
#define USB_OTG_DOEPINT_OTEPSPR 0x00000020U
#define USB_OTG_DOEPINT_B2BSTUP 0x00000040U
#define USB_OTG_DOEPINT_NYET    0x00004000U
    /********************  Bit definition for USB_OTG_DOEPTSIZ register  ********************/

#define USB_OTG_DOEPTSIZ_XFRSIZ    0x0007FFFFU
#define USB_OTG_DOEPTSIZ_PKTCNT    0x1FF80000U
#define USB_OTG_DOEPTSIZ_STUPCNT   0x60000000U
#define USB_OTG_DOEPTSIZ_STUPCNT_0 0x20000000U
#define USB_OTG_DOEPTSIZ_STUPCNT_1 0x40000000U
/********************  Bit definition for PCGCCTL register  ********************/
#define USB_OTG_PCGCCTL_STOPCLK 0x00000001U
#define USB_OTG_PCGCCTL_GATECLK 0x00000002U
#define USB_OTG_PCGCCTL_PHYSUSP 0x00000010U
/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == ADC1) || ((INSTANCE) == ADC2) || ((INSTANCE) == ADC3))

/******************************* CAN Instances ********************************/
#define IS_CAN_ALL_INSTANCE(INSTANCE) (((INSTANCE) == CAN1) || ((INSTANCE) == CAN2))

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************* DAC Instances ********************************/
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DAC)

/******************************* DCMI Instances *******************************/
#define IS_DCMI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DCMI)

/******************************** DMA Instances *******************************/
#define IS_DMA_STREAM_ALL_INSTANCE(INSTANCE)                                                       \
    (((INSTANCE) == DMA1_Stream0) || ((INSTANCE) == DMA1_Stream1) ||                               \
     ((INSTANCE) == DMA1_Stream2) || ((INSTANCE) == DMA1_Stream3) ||                               \
     ((INSTANCE) == DMA1_Stream4) || ((INSTANCE) == DMA1_Stream5) ||                               \
     ((INSTANCE) == DMA1_Stream6) || ((INSTANCE) == DMA1_Stream7) ||                               \
     ((INSTANCE) == DMA2_Stream0) || ((INSTANCE) == DMA2_Stream1) ||                               \
     ((INSTANCE) == DMA2_Stream2) || ((INSTANCE) == DMA2_Stream3) ||                               \
     ((INSTANCE) == DMA2_Stream4) || ((INSTANCE) == DMA2_Stream5) ||                               \
     ((INSTANCE) == DMA2_Stream6) || ((INSTANCE) == DMA2_Stream7))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE)                                                             \
    (((INSTANCE) == GPIOA) || ((INSTANCE) == GPIOB) || ((INSTANCE) == GPIOC) ||                    \
     ((INSTANCE) == GPIOD) || ((INSTANCE) == GPIOE) || ((INSTANCE) == GPIOF) ||                    \
     ((INSTANCE) == GPIOG) || ((INSTANCE) == GPIOH))

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == I2C1) || ((INSTANCE) == I2C2) || ((INSTANCE) == I2C3))

/******************************** I2S Instances *******************************/
#define IS_I2S_ALL_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == SPI1) || ((INSTANCE) == SPI2) || ((INSTANCE) == SPI3))

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == RTC)

/******************************* SAI Instances ********************************/
#define IS_SAI_ALL_INSTANCE(PERIPH)                                                                \
    (((PERIPH) == SAI1_Block_A) || ((PERIPH) == SAI1_Block_B) || ((PERIPH) == SAI2_Block_A) ||     \
     ((PERIPH) == SAI2_Block_B))
/* Legacy define */
#define IS_SAI_BLOCK_PERIPH IS_SAI_ALL_INSTANCE

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == SPI1) || ((INSTANCE) == SPI2) || ((INSTANCE) == SPI3) || ((INSTANCE) == SPI4))

/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE)                                                                  \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM6) ||                       \
     ((INSTANCE) == TIM7) || ((INSTANCE) == TIM8) || ((INSTANCE) == TIM9) ||                       \
     ((INSTANCE) == TIM10) || ((INSTANCE) == TIM11) || ((INSTANCE) == TIM12) ||                    \
     ((INSTANCE) == TIM13) || ((INSTANCE) == TIM14))

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8) ||                       \
     ((INSTANCE) == TIM9) || ((INSTANCE) == TIM10) || ((INSTANCE) == TIM11) ||                     \
     ((INSTANCE) == TIM12) || ((INSTANCE) == TIM13) || ((INSTANCE) == TIM14))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8) ||                       \
     ((INSTANCE) == TIM9) || ((INSTANCE) == TIM12))

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/******************** TIM Instances : Advanced-control timers *****************/
#define IS_TIM_ADVANCED_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || ((INSTANCE) == TIM8))

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/****************** TIM Instances : DMA requests generation (UDE) *************/
#define IS_TIM_DMA_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM6) ||                       \
     ((INSTANCE) == TIM7) || ((INSTANCE) == TIM8))

/************ TIM Instances : DMA requests generation (CCxDE) *****************/
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)                                                           \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/************ TIM Instances : DMA requests generation (COMDE) *****************/
#define IS_TIM_CCDMA_INSTANCE(INSTANCE)                                                            \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE)                                                         \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/****** TIM Instances : master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)                                                           \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM6) ||                       \
     ((INSTANCE) == TIM7) || ((INSTANCE) == TIM8) || ((INSTANCE) == TIM9) ||                       \
     ((INSTANCE) == TIM12))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)                                                            \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8) ||                       \
     ((INSTANCE) == TIM9) || ((INSTANCE) == TIM12))

/********************** TIM Instances : 32 bit Counter ************************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) (((INSTANCE) == TIM2) || ((INSTANCE) == TIM5))

/***************** TIM Instances : external trigger input availabe ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)                                                              \
    (((INSTANCE) == TIM1) || ((INSTANCE) == TIM2) || ((INSTANCE) == TIM3) ||                       \
     ((INSTANCE) == TIM4) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM8))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)                                                            \
    (((INSTANCE) == TIM2) || ((INSTANCE) == TIM5) || ((INSTANCE) == TIM11))

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL)                                                     \
    ((((INSTANCE) == TIM1) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3) || ((CHANNEL) == TIM_CHANNEL_4))) ||   \
     (((INSTANCE) == TIM2) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3) || ((CHANNEL) == TIM_CHANNEL_4))) ||   \
     (((INSTANCE) == TIM3) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3) || ((CHANNEL) == TIM_CHANNEL_4))) ||   \
     (((INSTANCE) == TIM4) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3) || ((CHANNEL) == TIM_CHANNEL_4))) ||   \
     (((INSTANCE) == TIM5) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3) || ((CHANNEL) == TIM_CHANNEL_4))) ||   \
     (((INSTANCE) == TIM8) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3) || ((CHANNEL) == TIM_CHANNEL_4))) ||   \
     (((INSTANCE) == TIM9) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2))) ||   \
     (((INSTANCE) == TIM10) && (((CHANNEL) == TIM_CHANNEL_1))) ||                                  \
     (((INSTANCE) == TIM11) && (((CHANNEL) == TIM_CHANNEL_1))) ||                                  \
     (((INSTANCE) == TIM12) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2))) ||  \
     (((INSTANCE) == TIM13) && (((CHANNEL) == TIM_CHANNEL_1))) ||                                  \
     (((INSTANCE) == TIM14) && (((CHANNEL) == TIM_CHANNEL_1))))

/************ TIM Instances : complementary output(s) available ***************/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL)                                                    \
    ((((INSTANCE) == TIM1) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3))) ||                                   \
     (((INSTANCE) == TIM8) && (((CHANNEL) == TIM_CHANNEL_1) || ((CHANNEL) == TIM_CHANNEL_2) ||     \
                               ((CHANNEL) == TIM_CHANNEL_3))))

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE)                                                                \
    (((INSTANCE) == USART1) || ((INSTANCE) == USART2) || ((INSTANCE) == USART3) ||                 \
     ((INSTANCE) == USART6))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE)                                                                 \
    (((INSTANCE) == USART1) || ((INSTANCE) == USART2) || ((INSTANCE) == USART3) ||                 \
     ((INSTANCE) == UART4) || ((INSTANCE) == UART5) || ((INSTANCE) == USART6))

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE)                                                          \
    (((INSTANCE) == USART1) || ((INSTANCE) == USART2) || ((INSTANCE) == USART3) ||                 \
     ((INSTANCE) == USART6))

/********************* UART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE)                                                            \
    (((INSTANCE) == USART1) || ((INSTANCE) == USART2) || ((INSTANCE) == USART3) ||                 \
     ((INSTANCE) == USART6))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE)                                                                 \
    (((INSTANCE) == USART1) || ((INSTANCE) == USART2) || ((INSTANCE) == USART3) ||                 \
     ((INSTANCE) == UART4) || ((INSTANCE) == UART5) || ((INSTANCE) == USART6))

/*********************** PCD Instances ****************************************/
#define IS_PCD_ALL_INSTANCE(INSTANCE) (((INSTANCE) == USB_OTG_FS) || ((INSTANCE) == USB_OTG_HS))

/*********************** HCD Instances ****************************************/
#define IS_HCD_ALL_INSTANCE(INSTANCE) (((INSTANCE) == USB_OTG_FS) || ((INSTANCE) == USB_OTG_HS))

/****************************** SDIO Instances ********************************/
#define IS_SDIO_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SDIO)

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE) ((INSTANCE) == IWDG)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(INSTANCE) ((INSTANCE) == WWDG)

/****************************** QSPI Instances ********************************/
#define IS_QSPI_ALL_INSTANCE(__INSTANCE__) ((__INSTANCE__) == QUADSPI)

/******************************* CEC Instances ********************************/
#define IS_CEC_ALL_INSTANCE(__INSTANCE__) ((__INSTANCE__) == CEC)

/***************************** FMPI2C Instances *******************************/
#define IS_FMPI2C_ALL_INSTANCE(__INSTANCE__) ((__INSTANCE__) == FMPI2C1)

/******************************* SPDIFRX Instances ********************************/
#define IS_SPDIFRX_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SPDIFRX)

/****************************** USB Exported Constants ************************/
#define USB_OTG_FS_HOST_MAX_CHANNEL_NBR 8U
#define USB_OTG_FS_MAX_IN_ENDPOINTS     5U    /* Including EP0 */
#define USB_OTG_FS_MAX_OUT_ENDPOINTS    5U    /* Including EP0 */
#define USB_OTG_FS_TOTAL_FIFO_SIZE      1280U /* in Bytes */

#define USB_OTG_HS_HOST_MAX_CHANNEL_NBR 16U
#define USB_OTG_HS_MAX_IN_ENDPOINTS     8U    /* Including EP0 */
#define USB_OTG_HS_MAX_OUT_ENDPOINTS    8U    /* Including EP0 */
#define USB_OTG_HS_TOTAL_FIFO_SIZE      4096U /* in Bytes */

/******************************************************************************/
/*  For a painless codes migration between the STM32F4xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same STM32F4 Family                              */
/******************************************************************************/

/* Aliases for __IRQHandler */
#define QuadSPI_IRQHandler QUADSPI_IRQHandler

// Additions for robot arm
#if !defined(HSI_VALUE)
#define HSI_VALUE ((uint32_t)16000000) /*!< Value of the Internal oscillator in Hz*/
#endif                                 /* HSI_VALUE */

#if !defined(HSE_VALUE)
// this is HSE_VALUE for STM32F446
#define HSE_VALUE ((uint32_t)8000000) /*!< Value of the External oscillator in Hz */
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32F446xx_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/