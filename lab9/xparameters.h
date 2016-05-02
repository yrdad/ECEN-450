
/*******************************************************************
*
* CAUTION: This file is automatically generated by libgen.
* Version: Xilinx EDK 10.1.03 EDK_K_SP3.6
* DO NOT EDIT.
*
* Copyright (c) 2005 Xilinx, Inc.  All rights reserved. 
* 
* Description: Driver parameters
*
*******************************************************************/


/* Definitions for peripheral DLMB_CNTLR */
#define XPAR_DLMB_CNTLR_BASEADDR 0x00000000
#define XPAR_DLMB_CNTLR_HIGHADDR 0x00001FFF


/* Definitions for peripheral ILMB_CNTLR */
#define XPAR_ILMB_CNTLR_BASEADDR 0x00000000
#define XPAR_ILMB_CNTLR_HIGHADDR 0x00001FFF


/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 2

/* Definitions for peripheral RS232_UART_1 */
#define XPAR_RS232_UART_1_BASEADDR 0x84000000
#define XPAR_RS232_UART_1_HIGHADDR 0x8400FFFF
#define XPAR_RS232_UART_1_DEVICE_ID 0
#define XPAR_RS232_UART_1_BAUDRATE 115200
#define XPAR_RS232_UART_1_USE_PARITY 0
#define XPAR_RS232_UART_1_ODD_PARITY 0
#define XPAR_RS232_UART_1_DATA_BITS 8


/* Definitions for peripheral DEBUG_MODULE */
#define XPAR_DEBUG_MODULE_BASEADDR 0x84400000
#define XPAR_DEBUG_MODULE_HIGHADDR 0x8440FFFF
#define XPAR_DEBUG_MODULE_DEVICE_ID 1
#define XPAR_DEBUG_MODULE_BAUDRATE 0
#define XPAR_DEBUG_MODULE_USE_PARITY 0
#define XPAR_DEBUG_MODULE_ODD_PARITY 0
#define XPAR_DEBUG_MODULE_DATA_BITS 0


/******************************************************************/


/* Canonical definitions for peripheral RS232_UART_1 */
#define XPAR_UARTLITE_0_DEVICE_ID XPAR_RS232_UART_1_DEVICE_ID
#define XPAR_UARTLITE_0_BASEADDR 0x84000000
#define XPAR_UARTLITE_0_HIGHADDR 0x8400FFFF
#define XPAR_UARTLITE_0_BAUDRATE 115200
#define XPAR_UARTLITE_0_USE_PARITY 0
#define XPAR_UARTLITE_0_ODD_PARITY 0
#define XPAR_UARTLITE_0_DATA_BITS 8
#define XPAR_UARTLITE_0_SIO_CHAN 0


/* Canonical definitions for peripheral DEBUG_MODULE */
#define XPAR_UARTLITE_1_DEVICE_ID XPAR_DEBUG_MODULE_DEVICE_ID
#define XPAR_UARTLITE_1_BASEADDR 0x84400000
#define XPAR_UARTLITE_1_HIGHADDR 0x8440FFFF
#define XPAR_UARTLITE_1_BAUDRATE 0
#define XPAR_UARTLITE_1_USE_PARITY 0
#define XPAR_UARTLITE_1_ODD_PARITY 0
#define XPAR_UARTLITE_1_DATA_BITS 0
#define XPAR_UARTLITE_1_SIO_CHAN -1


/******************************************************************/

/* Definitions for driver MPMC */
#define XPAR_XMPMC_NUM_INSTANCES 1

/* Definitions for peripheral DDR2_SDRAM */
#define XPAR_DDR2_SDRAM_DEVICE_ID 0
#define XPAR_DDR2_SDRAM_MPMC_BASEADDR 0x90000000
#define XPAR_DDR2_SDRAM_MPMC_CTRL_BASEADDR 0xFFFFFFFF
#define XPAR_DDR2_SDRAM_INCLUDE_ECC_SUPPORT 0
#define XPAR_DDR2_SDRAM_USE_STATIC_PHY 0
#define XPAR_DDR2_SDRAM_PM_ENABLE 0
#define XPAR_DDR2_SDRAM_NUM_PORTS 3


/******************************************************************/


/* Definitions for peripheral DDR2_SDRAM */
#define XPAR_DDR2_SDRAM_MPMC_BASEADDR 0x90000000
#define XPAR_DDR2_SDRAM_MPMC_HIGHADDR 0x9FFFFFFF


/******************************************************************/


/* Canonical definitions for peripheral DDR2_SDRAM */
#define XPAR_MPMC_0_DEVICE_ID XPAR_DDR2_SDRAM_DEVICE_ID
#define XPAR_MPMC_0_MPMC_BASEADDR 0x90000000
#define XPAR_MPMC_0_MPMC_CTRL_BASEADDR 0xFFFFFFFF
#define XPAR_MPMC_0_INCLUDE_ECC_SUPPORT 0
#define XPAR_MPMC_0_USE_STATIC_PHY 0
#define XPAR_MPMC_0_PM_ENABLE 0
#define XPAR_MPMC_0_NUM_PORTS 3


/******************************************************************/

#define XPAR_XSYSACE_MEM_WIDTH 16
/* Definitions for driver SYSACE */
#define XPAR_XSYSACE_NUM_INSTANCES 1

/* Definitions for peripheral SYSACE_COMPACTFLASH */
#define XPAR_SYSACE_COMPACTFLASH_DEVICE_ID 0
#define XPAR_SYSACE_COMPACTFLASH_BASEADDR 0x83600000
#define XPAR_SYSACE_COMPACTFLASH_HIGHADDR 0x8360FFFF
#define XPAR_SYSACE_COMPACTFLASH_MEM_WIDTH 16


/******************************************************************/


/* Canonical definitions for peripheral SYSACE_COMPACTFLASH */
#define XPAR_SYSACE_0_DEVICE_ID XPAR_SYSACE_COMPACTFLASH_DEVICE_ID
#define XPAR_SYSACE_0_BASEADDR 0x83600000
#define XPAR_SYSACE_0_HIGHADDR 0x8360FFFF
#define XPAR_SYSACE_0_MEM_WIDTH 16


/******************************************************************/

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 6
#define XPAR_XINTC_HAS_IPR 1
#define XPAR_XINTC_USE_DCR 0
/* Definitions for driver INTC */
#define XPAR_XINTC_NUM_INSTANCES 1

/* Definitions for peripheral XPS_INTC_0 */
#define XPAR_XPS_INTC_0_DEVICE_ID 0
#define XPAR_XPS_INTC_0_BASEADDR 0x81800000
#define XPAR_XPS_INTC_0_HIGHADDR 0x8180FFFF
#define XPAR_XPS_INTC_0_KIND_OF_INTR 0x00000028


/******************************************************************/

#define XPAR_INTC_SINGLE_BASEADDR 0x81800000
#define XPAR_INTC_SINGLE_HIGHADDR 0x8180FFFF
#define XPAR_INTC_SINGLE_DEVICE_ID XPAR_XPS_INTC_0_DEVICE_ID
#define XPAR_OPB_AC97_CONTROLLER_REF_0_RECORD_INTERRUPT_MASK 0X000001
#define XPAR_XPS_INTC_0_OPB_AC97_CONTROLLER_REF_0_RECORD_INTERRUPT_INTR 0
#define XPAR_OPB_AC97_CONTROLLER_REF_0_PLAYBACK_INTERRUPT_MASK 0X000002
#define XPAR_XPS_INTC_0_OPB_AC97_CONTROLLER_REF_0_PLAYBACK_INTERRUPT_INTR 1
#define XPAR_XPS_TIMER_0_INTERRUPT_MASK 0X000004
#define XPAR_XPS_INTC_0_XPS_TIMER_0_INTERRUPT_INTR 2
#define XPAR_IR_DEMOD_0_INTERRUPT_MASK 0X000008
#define XPAR_XPS_INTC_0_IR_DEMOD_0_INTERRUPT_INTR 3
#define XPAR_SYSACE_COMPACTFLASH_SYSACE_IRQ_MASK 0X000010
#define XPAR_XPS_INTC_0_SYSACE_COMPACTFLASH_SYSACE_IRQ_INTR 4
#define XPAR_RS232_UART_1_INTERRUPT_MASK 0X000020
#define XPAR_XPS_INTC_0_RS232_UART_1_INTERRUPT_INTR 5

/******************************************************************/


/* Canonical definitions for peripheral XPS_INTC_0 */
#define XPAR_INTC_0_DEVICE_ID XPAR_XPS_INTC_0_DEVICE_ID
#define XPAR_INTC_0_BASEADDR 0x81800000
#define XPAR_INTC_0_HIGHADDR 0x8180FFFF
#define XPAR_INTC_0_KIND_OF_INTR 0x00000028

#define XPAR_INTC_0_TMRCTR_0_VEC_ID XPAR_XPS_INTC_0_XPS_TIMER_0_INTERRUPT_INTR
#define XPAR_INTC_0_SYSACE_0_VEC_ID XPAR_XPS_INTC_0_SYSACE_COMPACTFLASH_SYSACE_IRQ_INTR
#define XPAR_INTC_0_UARTLITE_0_VEC_ID XPAR_XPS_INTC_0_RS232_UART_1_INTERRUPT_INTR

/******************************************************************/

/* Definitions for driver TMRCTR */
#define XPAR_XTMRCTR_NUM_INSTANCES 1

/* Definitions for peripheral XPS_TIMER_0 */
#define XPAR_XPS_TIMER_0_DEVICE_ID 0
#define XPAR_XPS_TIMER_0_BASEADDR 0x83C00000
#define XPAR_XPS_TIMER_0_HIGHADDR 0x83C0FFFF


/******************************************************************/


/* Canonical definitions for peripheral XPS_TIMER_0 */
#define XPAR_TMRCTR_0_DEVICE_ID XPAR_XPS_TIMER_0_DEVICE_ID
#define XPAR_TMRCTR_0_BASEADDR 0x83C00000
#define XPAR_TMRCTR_0_HIGHADDR 0x83C0FFFF


/******************************************************************/


/* Definitions for peripheral MULTIPLY_0 */
#define XPAR_MULTIPLY_0_BASEADDR 0xC0A00000
#define XPAR_MULTIPLY_0_HIGHADDR 0xC0A0FFFF


/* Definitions for peripheral IR_DEMOD_0 */
#define XPAR_IR_DEMOD_0_BASEADDR 0xCA800000
#define XPAR_IR_DEMOD_0_HIGHADDR 0xCA80FFFF


/* Definitions for peripheral OPB_AC97_CONTROLLER_REF_0 */
#define XPAR_OPB_AC97_CONTROLLER_REF_0_BASEADDR 0x74400000
#define XPAR_OPB_AC97_CONTROLLER_REF_0_HIGHADDR 0x7440FFFF


/******************************************************************/

/* Definitions for driver OPBARB */
#define XPAR_XOPBARB_NUM_INSTANCES 1

/* Definitions for peripheral OPB_V20_0 */
#define XPAR_OPB_V20_0_BASEADDR 0xFFFFFFFF
#define XPAR_OPB_V20_0_HIGHADDR 0x00000000
#define XPAR_OPB_V20_0_DEVICE_ID 0
#define XPAR_OPB_V20_0_NUM_MASTERS 1


/******************************************************************/

#define XPAR_CPU_CORE_CLOCK_FREQ_HZ 75000000

/******************************************************************/


/* Definitions for peripheral MICROBLAZE_0 */
#define XPAR_MICROBLAZE_0_SCO 0
#define XPAR_MICROBLAZE_0_DATA_SIZE 32
#define XPAR_MICROBLAZE_0_DYNAMIC_BUS_SIZING 1
#define XPAR_MICROBLAZE_0_AREA_OPTIMIZED 0
#define XPAR_MICROBLAZE_0_INTERCONNECT 1
#define XPAR_MICROBLAZE_0_DPLB_DWIDTH 64
#define XPAR_MICROBLAZE_0_DPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_0_DPLB_BURST_EN 0
#define XPAR_MICROBLAZE_0_DPLB_P2P 0
#define XPAR_MICROBLAZE_0_IPLB_DWIDTH 64
#define XPAR_MICROBLAZE_0_IPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_0_IPLB_BURST_EN 0
#define XPAR_MICROBLAZE_0_IPLB_P2P 0
#define XPAR_MICROBLAZE_0_D_PLB 1
#define XPAR_MICROBLAZE_0_D_OPB 0
#define XPAR_MICROBLAZE_0_D_LMB 1
#define XPAR_MICROBLAZE_0_I_PLB 1
#define XPAR_MICROBLAZE_0_I_OPB 0
#define XPAR_MICROBLAZE_0_I_LMB 1
#define XPAR_MICROBLAZE_0_USE_MSR_INSTR 1
#define XPAR_MICROBLAZE_0_USE_PCMP_INSTR 1
#define XPAR_MICROBLAZE_0_USE_BARREL 1
#define XPAR_MICROBLAZE_0_USE_DIV 0
#define XPAR_MICROBLAZE_0_USE_HW_MUL 1
#define XPAR_MICROBLAZE_0_USE_FPU 0
#define XPAR_MICROBLAZE_0_UNALIGNED_EXCEPTIONS 0
#define XPAR_MICROBLAZE_0_ILL_OPCODE_EXCEPTION 0
#define XPAR_MICROBLAZE_0_IOPB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_DOPB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_IPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_DPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_0_DIV_ZERO_EXCEPTION 0
#define XPAR_MICROBLAZE_0_FPU_EXCEPTION 0
#define XPAR_MICROBLAZE_0_FSL_EXCEPTION 0
#define XPAR_MICROBLAZE_0_PVR 0
#define XPAR_MICROBLAZE_0_PVR_USER1 0x00
#define XPAR_MICROBLAZE_0_PVR_USER2 0x00000000
#define XPAR_MICROBLAZE_0_DEBUG_ENABLED 1
#define XPAR_MICROBLAZE_0_NUMBER_OF_PC_BRK 1
#define XPAR_MICROBLAZE_0_NUMBER_OF_RD_ADDR_BRK 0
#define XPAR_MICROBLAZE_0_NUMBER_OF_WR_ADDR_BRK 0
#define XPAR_MICROBLAZE_0_INTERRUPT_IS_EDGE 0
#define XPAR_MICROBLAZE_0_EDGE_IS_POSITIVE 1
#define XPAR_MICROBLAZE_0_RESET_MSR 0x00000000
#define XPAR_MICROBLAZE_0_OPCODE_0X0_ILLEGAL 0
#define XPAR_MICROBLAZE_0_FSL_LINKS 0
#define XPAR_MICROBLAZE_0_FSL_DATA_SIZE 32
#define XPAR_MICROBLAZE_0_USE_EXTENDED_FSL_INSTR 0
#define XPAR_MICROBLAZE_0_ICACHE_BASEADDR 0x90000000
#define XPAR_MICROBLAZE_0_ICACHE_HIGHADDR 0x9FFFFFFF
#define XPAR_MICROBLAZE_0_USE_ICACHE 1
#define XPAR_MICROBLAZE_0_ALLOW_ICACHE_WR 1
#define XPAR_MICROBLAZE_0_ADDR_TAG_BITS 17
#define XPAR_MICROBLAZE_0_CACHE_BYTE_SIZE 2048
#define XPAR_MICROBLAZE_0_ICACHE_USE_FSL 1
#define XPAR_MICROBLAZE_0_ICACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_0_ICACHE_ALWAYS_USED 0
#define XPAR_MICROBLAZE_0_DCACHE_BASEADDR 0x90000000
#define XPAR_MICROBLAZE_0_DCACHE_HIGHADDR 0x9FFFFFFF
#define XPAR_MICROBLAZE_0_USE_DCACHE 1
#define XPAR_MICROBLAZE_0_ALLOW_DCACHE_WR 1
#define XPAR_MICROBLAZE_0_DCACHE_ADDR_TAG 16
#define XPAR_MICROBLAZE_0_DCACHE_BYTE_SIZE 4096
#define XPAR_MICROBLAZE_0_DCACHE_USE_FSL 1
#define XPAR_MICROBLAZE_0_DCACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_0_DCACHE_ALWAYS_USED 0
#define XPAR_MICROBLAZE_0_USE_MMU 3
#define XPAR_MICROBLAZE_0_MMU_DTLB_SIZE 4
#define XPAR_MICROBLAZE_0_MMU_ITLB_SIZE 2
#define XPAR_MICROBLAZE_0_MMU_TLB_ACCESS 3
#define XPAR_MICROBLAZE_0_MMU_ZONES 2
#define XPAR_MICROBLAZE_0_USE_INTERRUPT 1
#define XPAR_MICROBLAZE_0_USE_EXT_BRK 1
#define XPAR_MICROBLAZE_0_USE_EXT_NM_BRK 1

/******************************************************************/

#define XPAR_CPU_ID 0
#define XPAR_MICROBLAZE_ID 0
#define XPAR_MICROBLAZE_CORE_CLOCK_FREQ_HZ 100000000
#define XPAR_MICROBLAZE_SCO 0
#define XPAR_MICROBLAZE_DATA_SIZE 32
#define XPAR_MICROBLAZE_DYNAMIC_BUS_SIZING 1
#define XPAR_MICROBLAZE_AREA_OPTIMIZED 0
#define XPAR_MICROBLAZE_INTERCONNECT 1
#define XPAR_MICROBLAZE_DPLB_DWIDTH 64
#define XPAR_MICROBLAZE_DPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_DPLB_BURST_EN 0
#define XPAR_MICROBLAZE_DPLB_P2P 0
#define XPAR_MICROBLAZE_IPLB_DWIDTH 64
#define XPAR_MICROBLAZE_IPLB_NATIVE_DWIDTH 32
#define XPAR_MICROBLAZE_IPLB_BURST_EN 0
#define XPAR_MICROBLAZE_IPLB_P2P 0
#define XPAR_MICROBLAZE_D_PLB 1
#define XPAR_MICROBLAZE_D_OPB 0
#define XPAR_MICROBLAZE_D_LMB 1
#define XPAR_MICROBLAZE_I_PLB 1
#define XPAR_MICROBLAZE_I_OPB 0
#define XPAR_MICROBLAZE_I_LMB 1
#define XPAR_MICROBLAZE_USE_MSR_INSTR 1
#define XPAR_MICROBLAZE_USE_PCMP_INSTR 1
#define XPAR_MICROBLAZE_USE_BARREL 1
#define XPAR_MICROBLAZE_USE_DIV 0
#define XPAR_MICROBLAZE_USE_HW_MUL 1
#define XPAR_MICROBLAZE_USE_FPU 0
#define XPAR_MICROBLAZE_UNALIGNED_EXCEPTIONS 0
#define XPAR_MICROBLAZE_ILL_OPCODE_EXCEPTION 0
#define XPAR_MICROBLAZE_IOPB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_DOPB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_IPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_DPLB_BUS_EXCEPTION 0
#define XPAR_MICROBLAZE_DIV_ZERO_EXCEPTION 0
#define XPAR_MICROBLAZE_FPU_EXCEPTION 0
#define XPAR_MICROBLAZE_FSL_EXCEPTION 0
#define XPAR_MICROBLAZE_PVR 0
#define XPAR_MICROBLAZE_PVR_USER1 0x00
#define XPAR_MICROBLAZE_PVR_USER2 0x00000000
#define XPAR_MICROBLAZE_DEBUG_ENABLED 1
#define XPAR_MICROBLAZE_NUMBER_OF_PC_BRK 1
#define XPAR_MICROBLAZE_NUMBER_OF_RD_ADDR_BRK 0
#define XPAR_MICROBLAZE_NUMBER_OF_WR_ADDR_BRK 0
#define XPAR_MICROBLAZE_INTERRUPT_IS_EDGE 0
#define XPAR_MICROBLAZE_EDGE_IS_POSITIVE 1
#define XPAR_MICROBLAZE_RESET_MSR 0x00000000
#define XPAR_MICROBLAZE_OPCODE_0X0_ILLEGAL 0
#define XPAR_MICROBLAZE_FSL_LINKS 0
#define XPAR_MICROBLAZE_FSL_DATA_SIZE 32
#define XPAR_MICROBLAZE_USE_EXTENDED_FSL_INSTR 0
#define XPAR_MICROBLAZE_ICACHE_BASEADDR 0x90000000
#define XPAR_MICROBLAZE_ICACHE_HIGHADDR 0x9FFFFFFF
#define XPAR_MICROBLAZE_USE_ICACHE 1
#define XPAR_MICROBLAZE_ALLOW_ICACHE_WR 1
#define XPAR_MICROBLAZE_ADDR_TAG_BITS 17
#define XPAR_MICROBLAZE_CACHE_BYTE_SIZE 2048
#define XPAR_MICROBLAZE_ICACHE_USE_FSL 1
#define XPAR_MICROBLAZE_ICACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_ICACHE_ALWAYS_USED 0
#define XPAR_MICROBLAZE_DCACHE_BASEADDR 0x90000000
#define XPAR_MICROBLAZE_DCACHE_HIGHADDR 0x9FFFFFFF
#define XPAR_MICROBLAZE_USE_DCACHE 1
#define XPAR_MICROBLAZE_ALLOW_DCACHE_WR 1
#define XPAR_MICROBLAZE_DCACHE_ADDR_TAG 16
#define XPAR_MICROBLAZE_DCACHE_BYTE_SIZE 4096
#define XPAR_MICROBLAZE_DCACHE_USE_FSL 1
#define XPAR_MICROBLAZE_DCACHE_LINE_LEN 4
#define XPAR_MICROBLAZE_DCACHE_ALWAYS_USED 0
#define XPAR_MICROBLAZE_USE_MMU 3
#define XPAR_MICROBLAZE_MMU_DTLB_SIZE 4
#define XPAR_MICROBLAZE_MMU_ITLB_SIZE 2
#define XPAR_MICROBLAZE_MMU_TLB_ACCESS 3
#define XPAR_MICROBLAZE_MMU_ZONES 2
#define XPAR_MICROBLAZE_USE_INTERRUPT 1
#define XPAR_MICROBLAZE_USE_EXT_BRK 1
#define XPAR_MICROBLAZE_USE_EXT_NM_BRK 1
#define XPAR_MICROBLAZE_HW_VER "7.10.d"

/******************************************************************/

