/*
 * Copyright (c) 2019 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef _WVCAS_PVR_H_
#define _WVCAS_PVR_H_

#include "wvcas_pvr_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Open a new WVCAS PVR session.
 * @param   pvr_info: include the basic info for
 *          open a new WVCAS PVR session.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_OpenPVRSession(
            WvCasPVRInfo *pvr_info,
            WvCasPVRHandle *pvr_session);

/**
 * @brief   Destroy the WVCAS PVR session.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_ClosePVRSession(
            WvCasPVRHandle pvr_session);

/**
 * @brief   Add a WVCAS PVR pid.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @param   pid: The WVCAS PVR pid.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_AddPVRPid(
            WvCasPVRHandle pvr_session, WvCasPVRUInt16 pid);

/**
 * @brief   Remove a WVCAS PVR pid.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @param   pid: The WVCAS PVR pid.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_RemovePVRPid(
            WvCasPVRHandle pvr_session, WvCasPVRUInt16 pid);

/**
 * @brief   Get the WVCAS PVR metadata.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @param   metadata: The WVCAS PVR metadata.
 * @param   metadata_size: The WVCAS PVR metadata size.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_GetPVRMetadata(
            WvCasPVRHandle pvr_session, WvCasPVRMetadata *metadata,
            WvCasPVRSize* metadata_size);

/**
 * @brief   Load the WVCAS PVR metadata.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @param   metadata: The WVCAS PVR metadata.
 * @param   metadata_size: The WVCAS PVR metadata size.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_LoadPVRMetadata(
            WvCasPVRHandle pvr_session, WvCasPVRMetadata *metadata,
            WvCasPVRSize metadata_size);

/**
 * @brief   Update the WVCAS PVR info.
 * @param   pvr_session: The WVCAS PVR session handle.
 * @param   pvr_info: The WVCAS PVR basic info.
 * @retval  WVCAS_PVR_OK if function succeeds.
 *          WVCAS_PVR_ERROR or other abnormal return values
 *          defined in WvCasPVRResult if some exception occurs.
 */
WvCasPVRResult WVCAS_UpdatePVRInfo(
            WvCasPVRHandle pvr_session, WvCasPVRInfo *pvr_info);

#ifdef __cplusplus
};
#endif

#endif
