/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef _WVCAS_PVR_TYPES_H_
#define _WVCAS_PVR_TYPES_H_

#include <stdint.h>

#define MAX_WVCAS_PVR_KEY_SIZE 64
#define INVALID_WVCAS_PVR_HANDLE 0
#define INVALID_WVCAS_KEY_TOKEN 0

typedef int32_t WvCasPVRInt32;
typedef uint32_t WvCasPVRUInt32;
typedef uint16_t WvCasPVRUInt16;
typedef uint8_t WvCasPVRByte;
typedef size_t WvCasPVRSize;

/**
* Type used to represent WvCas session id or session key token.
*/
typedef WvCasPVRUInt32 WvCasKeyToken;

/**
* It is a machine-dependent unsigned type whose size is
* sufficient to store the object in memory.
*/
typedef WvCasPVRSize WvCasPVRHandle;

/**
* Type used to represent a bit pattern signifying
* a combination of flags that can be on or off.
*/
typedef WvCasPVRUInt32 WvCasPVRFlags;

/**
* Boolean type used for variables that can be
* true (WVCAS_PVR_TRUE) or false (WVCAS_PVR_FALSE).
*/
typedef enum {
    WVCAS_PVR_FALSE = 0,
    WVCAS_PVR_TRUE  = 1
} WvCasPVRBool;

/**
* Signed integer value representing a function result.
* When a function or method call succeeds, the return
* value is always WVCAS_PVR_OK unless otherwise documented.
*/
typedef enum {
    WVCAS_PVR_OK,
    WVCAS_PVR_ERROR,
    WVCAS_PVR_ERROR_INIT_FAILED,
    WVCAS_PVR_ERROR_MALLOC_FAILED,
    WVCAS_PVR_ERROR_ILLEGAL_INPUT_PARAMETERS,
    WVCAS_PVR_ERROR_NOT_IMPLEMENTED,
    WVCAS_PVR_ERROR_OEMCRYPTO_STATUS,
    WVCAS_PVR_ERROR_DESCRAMBLER_STATUS,
    WVCAS_PVR_ERROR_SHORT_BUFFER,
    WVCAS_PVR_UNKNOWN_ERROR,
} WvCasPVRResult;

/**
* WvCas PVR Usage.
* Indicates recording or playback scenario.
*/
typedef enum {
    WVCAS_PVR_USAGE_PLAYBACK = 1,
    WVCAS_PVR_USAGE_RECORD,
    WVCAS_PVR_USAGE_CLEAR_PLAYBACK = 20,
    WVCAS_PVR_USAGE_CLEAR_RECORD
} WvCasPVRUsage;

/**
* WvCas PVR Scrambling Mode.
* AES CBS algorithm is usually used by default.
*/
typedef enum {
    WVCAS_PVR_DSC_MODE_RESERVED = 0,
    WVCAS_PVR_DSC_MODE_DVB_CISSA_V1 = 6,
    WVCAS_PVR_DSC_MODE_AES_ECB = 10,
    WVCAS_PVR_DSC_MODE_AES_CBC = 14,
} WvCasPVRScramblingMode;

/**
* WvCas Dsc Type.
* Indicates the descrambler hardware working mode set before
* encryption or decryption.
*/
typedef enum {
    WVCAS_PVR_DSC_TYPE_COMMON,
    WVCAS_PVR_DSC_TYPE_TSD,
    WVCAS_PVR_DSC_TYPE_TSE
} WvCasPVRDscType;

/**
* WvCas PVR Metadata Usage.
* Indicates get pvr metadata or load pvr metadata scenario.
*/
typedef enum {
    WVCAS_PVR_METADATA_USAGE_GET,
    WVCAS_PVR_METADATA_USAGE_LOAD
} WvCasPVRMetadataUsage;

/**
* WvCas PVR Metadata.
* Defines the attribute information required to generate and load PVR Key.
*/
typedef struct {
    WvCasPVRByte pvr_key[MAX_WVCAS_PVR_KEY_SIZE];
    WvCasPVRSize pvr_key_size;
    WvCasPVRFlags pvr_flags;
    WvCasPVRMetadataUsage metadata_usage;

    /**
    * WvCas PVR Metadata Config.
    * Define the required attribute information according to the usage
    * scenario of generating or loading PVR Key
    */
    union {
        struct { // metadata_usage == WVCAS_PVR_METADATA_USAGE_GET
            WvCasKeyToken desc_key_token; //WvCas Descrambling Key Session ID
        } get;
        struct { // metadata_usage == WVCAS_PVR_METADATA_LOAD
            WvCasPVRUsage pvr_usage;
        } load;
    } config;
} WvCasPVRMetadata;

/**
* WvCas PVR Info.
* It defines the information needed to create a PVR Session.
*/
typedef struct {
    WvCasPVRUsage pvr_usage; // Clear/Secure Playback/Record PVR
    WvCasPVRScramblingMode pvr_algo; // Encryption/Decryption Algorithm
    WvCasPVRDscType dsc_type; // Descrambler Work Mode
    WvCasPVRInt32 dsc_fd; // Descrambler Fd
    WvCasPVRUInt32 dsc_id; // Demux/Descrambler Device ID
    WvCasPVRFlags extension_flags; //Reserved Extension Flags
} WvCasPVRInfo;

#endif
