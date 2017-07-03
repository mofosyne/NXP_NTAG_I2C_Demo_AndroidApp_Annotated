#ifndef NFC_DEVICE_H
#define NFC_DEVICE_H

#include "demo_settings.h"

//change between NTAG and TNPI
#ifdef TNPI_DEVICE
#  define NFC_TEST_DEVICE         TNPI0
#  define NFC_ID_MAX_DEVICES      TNPI_ID_MAX_DEVICES
#  define NFC_INVALID_HANDLE      TNPI_INVALID_HANDLE
#  define NFC_HANDLE_T            TNPI_HANDLE_T
#  define NFC_InitDevice          TNPI_InitDevice
#  define NFC_CloseDevice         TNPI_CloseDevice
#  define NFC_ReadBytes           TNPI_ReadBytes
#  define NFC_WriteBytes          TNPI_WriteBytes
#  define NFC_GetLastError        TNPI_GetLastError
#  define NFC_WaitForEvent        TNPI_WaitForEvent
#  define NFC_ReadRegister        TNPI_ReadRegister
#  define NFC_WriteRegister       TNPI_WriteRegister

#  define NFC_SetPthruOnOff       TNPI_SetPthruOnOff
#  define NFC_SetTransferDir 	  TNPI_SetTransferDir

#  define NFC_SetFDOffFunction    TNPI_SetFDOffFunction
#  define NFC_SetFDOnFunction	  TNPI_SetFDOnFunction

#  define NFC_MEM_SRAM_SIZE	      TNPI_MEM_SIZE_SRAM
#else
#  define NFC_TEST_DEVICE         NTAG0
#  define NFC_ID_MAX_DEVICES      NTAG_ID_MAX_DEVICES
#  define NFC_INVALID_HANDLE      NTAG_INVALID_HANDLE
#  define NFC_HANDLE_T            NTAG_HANDLE_T
#  define NFC_InitDevice          NTAG_InitDevice
#  define NFC_CloseDevice         NTAG_CloseDevice
#  define NFC_ReadBytes           NTAG_ReadBytes
#  define NFC_WriteBytes          NTAG_WriteBytes
#  define NFC_GetLastError        NTAG_GetLastError
#  define NFC_WaitForEvent        NTAG_WaitForEvent
#  define NFC_ReadRegister        NTAG_ReadRegister
#  define NFC_WriteRegister       NTAG_WriteRegister
#  define NFC_WriteBlock		  NTAG_WriteBlock

#  define NFC_ReadRegister 	      NTAG_ReadRegister
#  define NFC_SetPthruOnOff       NTAG_SetPthruOnOff
#  define NFC_SetTransferDir 	  NTAG_SetTransferDir

#  define NFC_SetFDOffFunction    NTAG_SetFDOffFunction
#  define NFC_SetFDOnFunction	  NTAG_SetFDOnFunction

#  define NFC_MEM_SRAM_SIZE	      NTAG_MEM_SRAM_SIZE
#endif

#  define NFC_I2C_BLOCK_SIZE      NTAG_I2C_BLOCK_SIZE
#  define NFC_MEM_ADDR_START_SRAM         NTAG_MEM_ADDR_START_SRAM
#  define NFC_MEM_ADDR_START_USER_MEMORY  NTAG_MEM_ADDR_START_USER_MEMORY
#  define NFC_MEM_OFFSET_NC_REG   NTAG_MEM_OFFSET_NC_REG
#  define NFC_MEM_OFFSET_NS_REG   NTAG_MEM_OFFSET_NS_REG
#  define NFC_NC_REG_MASK_PTHRU_ON_OFF    NTAG_NC_REG_MASK_PTHRU_ON_OFF
#  define NFC_NS_REG_MASK_I2C_LOCKED      NTAG_NS_REG_MASK_I2C_LOCKED



//switch between Interrupt and Polling mode
#ifdef INTERRUPT
#  define NTAG_EVENT_RF_WROTE_SRAM        NTAG_EVENT_RF_WROTE_SRAM_INTERRUPT
#  define NTAG_EVENT_RF_READ_SRAM         NTAG_EVENT_RF_READ_SRAM_INTERRUPT
#  define NTAG_EVENT_RF_FIELD_PRESENT     NTAG_EVENT_RF_FIELD_PRESENT_INTERRUPT
#else
#  define NTAG_EVENT_RF_WROTE_SRAM        NTAG_EVENT_RF_WROTE_SRAM_POLLED
#  define NTAG_EVENT_RF_READ_SRAM         NTAG_EVENT_RF_READ_SRAM_POLLED
#  define NTAG_EVENT_RF_FIELD_PRESENT     NTAG_EVENT_RF_FIELD_PRESENT_POLLED
#endif

#  define SRAM_TIMEOUT 500

#endif