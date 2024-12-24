#ifndef WVCAS_IPTV_HAL_H
#define WVCAS_IPTV_HAL_H

#include "wvcas_iptv_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Init WVCAS resources.
 * @param   void.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_Init();

/**
 * @brief   Release WVCAS resources.
 * @param   void.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_Term();

/**
 * @brief   Judge whether the specified ca system id
 *          is supported by WVCAS.
 * @param   ca_system_id: The specified ca system id.
 * @retval  true if the ca system id is supported.
 *          false if the ca system id isn't supported.
 */
bool WVCAS_IsSystemIdSupported(
     int ca_system_id);

/**
 * @brief   Create a new WVCAS plugin.
 * @param   plugin_info: include the basic info for
 *          create a new WVCAS plugin.
 * @param   handle: The WVCAS IPTV handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_CreateCasPlugin(
            WvCasPluginInfo *plugin_info,
            WvCasHandle *handle);

/**
 * @brief   Destroy the WVCAS Plugin.
 * @param   handle: The WVCAS IPTV handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_DestroyCasPlugin(
            WvCasHandle handle);

/**
 * @brief   Open a new WVCAS session.
 * @param   handle: The WVCAS IPTV handle.
 * @param   session_info: include the basic info
 *          for create a new WVCAS session.
 * @param   session_handle: The WV CA IPTV session handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_OpenCasSession(
            WvCasHandle handle,
            WvCasSessionInfo *session_info,
            WvCasSessionHandle* session_handle);

/**
 * @brief   Close the WVCAS session.
 * @param   session_handle: The WVCAS IPTV session handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_CloseCasSession(
            WvCasSessionHandle session_handle);

/**
 * @brief   Start descrambling with the WVCAS session.
 * @param   session_handle: The WVCAS IPTV session handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_StartDescrambling(
            WvCasSessionHandle session_handle,
            WvCasScramblingInfo *scrambling_info);

/**
 * @brief   Stop descrambling with the WVCAS session.
 * @param   session_handle: The WVCAS IPTV session handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_StopDescrambling(
            WvCasSessionHandle session_handle);

/**
 * @brief   Process ECM with the WVCAS session.
 * @param   session_handle: The WVCAS IPTV session handle.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_ProcessEcm(
            WvCasSessionHandle session_handle,
            const uint8_t *ecm_data,
            const uint32_t ecm_data_len);

/**
 * @brief   Send the command to WVCAS plugin.
 * @param   handle: The WVCAS IPTV handle.
 * @param   in_json: The json data of the input event.
 * @param   out_json: The output json data for the input event.
 * @param   out_json_len: The data length of the output json data.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_SendCommand(
            WvCasHandle handle,
            const char* in_json,
            char* out_json,
            uint32_t out_json_len);

/**
 * @brief   Send the command to the WVCAS session.
 * @param   session_handle: The WVCAS IPTV session handle.
 * @param   in_json: The json data of the input event.
 * @param   out_json: The output json data for the input event.
 * @param   out_json_len: The data length of the output json data.
 * @retval  WVCAS_OK if function succeeds.
 *          WVCAS_ERROR* if some exception occurs.
 */
WvCasResult WVCAS_SendSessionCommand(
            WvCasSessionHandle session_handle,
            const char* in_json,
            char* out_json,
            uint32_t out_json_len);

#ifdef __cplusplus
};
#endif

#endif //WVCAS_IPTV_HAL_H

