// Copyright (C) 2020 Amlogic, Inc. All rights reserved.
//
// All information contained herein is Amlogic confidential.
//
// This software is provided to you pursuant to Software License
// Agreement (SLA) with Amlogic Inc ("Amlogic"). This software may be
// used only in accordance with the terms of this agreement.
//
// Redistribution and use in source and binary forms, with or without
// modification is strictly prohibited without prior written permission
// from Amlogic.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



#ifndef _SECMEM_CA_H_
#define _SECMEM_CA_H_

#include <stdint.h>
#include <stdbool.h>
#include <secmem_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FLAG_(x, mask, shift) ((x & (mask)) << shift)
#define SECMEM_V2_FLAGS_TVP(x) FLAG_(x, 0xF, 0)
#define SECMEM_V2_FLAGS_CODEC(x) FLAG_(x, 0xF, 4)
#define SECMEM_V2_FLAGS_VD_INDEX(x) FLAG_(x, 0xF, 9)
#define SECMEM_V2_FLAGS_USAGE(x) FLAG_(x, 0x7, 13)
#define SECMEM_V2_FLAGS_MEM_LEVEL(x) FLAG_(x, 0xF, 17)

#define Secure_V2_MemFillByPaddr(...)   (0)

/**
 * Common API
 */
unsigned int Secure_GetSecmemSize(void);
unsigned int Secure_GetVersion(void);
unsigned int Secure_NegotiateVersion(unsigned int expected);
unsigned int Secure_GetBufferConfig(uint32_t *count, uint32_t *size);
unsigned int Secure_GetResourceAvail(unsigned int *resource_free,
                                     unsigned int *resource_available);

/**
 * V1 API
 */
unsigned int Secure_AllocSecureMem(unsigned int length,
                            unsigned int tvp_set);
unsigned int Secure_ReleaseResource(void);
unsigned int Secure_GetCsdDataDrmInfo(unsigned int src_csd_addr,
                            unsigned int csd_len,
                            unsigned int* store_csd_phyaddr,
                            unsigned int* store_csd_size,
                            unsigned int overwrite);
unsigned int Secure_GetPadding(unsigned int* pad_addr,
                            unsigned int* pad_size,
                            unsigned int pad_type);
unsigned int Secure_GetVp9HeaderSize(void *src,
                            unsigned int size,
                            unsigned int *header_size);

/**
 * V2 API
 */
unsigned int Secure_V2_SessionCreate(void **sess);
unsigned int Secure_V2_SessionDestroy(void **sess);
unsigned int Secure_V2_Init(void *sess,
                           uint32_t source,
                           uint32_t flags,
                           uint32_t paddr,
                           uint32_t size);
unsigned int Secure_V2_MemCreate(void *sess,
                           uint32_t *handle);
unsigned int Secure_V2_MemAlloc(void *sess,
                           uint32_t handle,
                           uint32_t size,
                           uint32_t *phyaddr);
unsigned int Secure_V2_MemToPhy(void *sess,
                           uint32_t handle,
                           uint32_t *phyaddr);
unsigned int Secure_V2_MemFill(void *sess,
                           uint32_t handle,
                           uint32_t offset,
                           uint8_t *buffer,
                           uint32_t size);
unsigned int Secure_V2_MemCopy(void *sess,
                           uint32_t out_handle,
                           uint32_t in_handle,
                           uint32_t ranges,
                           uint32_t dst_offset[],
                           uint32_t src_offset[],
                           uint32_t size[]);
unsigned int Secure_V2_MemCopyPhy(uint32_t dst_handle,
                           uint32_t dst_offset,
                           uint32_t src_phyaddr,
                           uint32_t src_offset,
                           uint32_t size);
unsigned int Secure_V2_MemCheck(void *sess,
                           uint32_t handle,
                           uint8_t *buffer,
                           uint32_t len);
unsigned int Secure_V2_MemExport(void *sess,
                           uint32_t handle,
                           int *fd,
                           uint32_t *maxsize);
unsigned int Secure_V2_MemAllocDMA(void *sess,
                           uint32_t size,
                           int *fd,
                           uint32_t *handle,
                           uint32_t *maxsize);
unsigned int Secure_V2_FdToHandle(void *sess,
                           int fd);
unsigned int Secure_V2_FdToPaddr(void *sess,
                           int fd);
unsigned int Secure_V2_MemFree(void *sess,
                           uint32_t handle);
unsigned int Secure_V2_MemRelease(void *sess,
                           uint32_t handle);
unsigned int Secure_V2_MemFlush(void *sess);
unsigned int Secure_V2_MemClear(void *sess);
unsigned int Secure_V2_SetCsdData(void*sess,
                           unsigned char *csd,
                           unsigned int csd_len);
unsigned int Secure_V2_GetCsdDataDrmInfo(void *sess,
                           unsigned int src_csd_addr,
                           unsigned int csd_len,
                           unsigned int *store_csd_phyaddr,
                           unsigned int *store_csd_size,
                           unsigned int overwrite);
unsigned int Secure_V2_GetPadding(void *sess,
                           unsigned int* pad_addr,
                           unsigned int *pad_size,
                           unsigned int pad_type);
unsigned int Secure_V2_GetVp9HeaderSize(void *sess,
                           void *src,
                           unsigned int size,
                           unsigned int *header_size,
                           uint32_t *frames);
unsigned int Secure_V2_MergeCsdDataDrmInfo(void *sess,
                           uint32_t *phyaddr,
                           uint32_t *csd_len);
unsigned int Secure_V2_MergeCsdData(void *sess,
                           uint32_t handle,
                           uint32_t *csd_len);
unsigned int Secure_V2_Parse(void *sess,
                           uint32_t type,
                           uint32_t handle,
                           uint8_t *buffer,
                           uint32_t size,
                           uint32_t *flag);
unsigned int Secure_V2_ResourceAlloc(void *sess,
                           uint32_t* phyaddr,
                           uint32_t *size);
unsigned int Secure_V2_ResourceFree(void *sess);
unsigned int Secure_V2_BindTVP(void *sess,
                           uint32_t cas_id);
unsigned int Secure_V2_AudioValid(void *sess,
                           void *src, // secure source phyaddr
                           unsigned int size, //secure packet size
                           unsigned int aud_type, // audio format AUD_VALID_TYPE
                           unsigned char *aud_buf, // nonsecure output buf
                           unsigned int buf_max_size); // aud_buf total size
unsigned int Secure_V2_GetSecmemSize(void *sess,
                           unsigned int *mem_capacity,
                           unsigned int *mem_available,
                           unsigned int *handle_capacity,
                           unsigned int *handle_available);
unsigned int Secure_V2_InitSecurePool(void *sess, uint32_t vd_index, uint32_t usage,
                           uint32_t flags, int fd);
unsigned int Secure_V2_EnableTVPMemory(void *sess, uint32_t flags);
unsigned int Secure_V2_DestroySecurePool(void *sess);
unsigned int Secure_V2_UpdateFrameInfo(void *sess,
                           uint32_t codec,
                           int fd,
                           uint32_t flags,
                           uint32_t *size);
unsigned int Secure_V2_GetFreeBlockCount(void *sess,
                            uint32_t handle,
                            uint32_t frame_size,
                            uint32_t *block_count,
                            uint32_t *block_free_count);
unsigned int Secure_V2_PoolFlush(void *sess);

unsigned int Secure_V2_ProbeProgram(void *sess,
                            uint32_t handle,
                            uint32_t size,
                            uint32_t* program_count,     // Input the number of buffers and output the actual number of programs
                            sec_ts_program_t* program_list);

unsigned int Secure_V2_GetStreamInfo(void *sess,
                            uint32_t handle,
                            uint32_t size,
                            uint32_t* program_pid,      // input and output
                            uint32_t* stream_count,     // Input the number of buffers and output the actual number of streams
                            sec_ts_component_t* stream_list);

unsigned int Secure_V2_FindPtsOffset(void *sess,
                            uint32_t handle,
                            uint32_t size,
                            uint64_t* pts,              // input and output
                            uint32_t stream_type,
                            int32_t* offset);
/*
 * Sideband API
 */
unsigned int Secure_SetHandle(uint32_t handle);
unsigned int Secure_GetHandle(uint32_t *handle);

/**
 * V3 API
 */
#define SECMEM_V3_FLAGS_TVP(x)          FLAG_(x, 0xF, 0)
#define SECMEM_V3_FLAGS_CODEC(x)        FLAG_(x, 0xF, 4)
#define SECMEM_V3_FLAGS_VD_INDEX(x)     FLAG_(x, 0xF, 9)
#define SECMEM_V3_FLAGS_USAGE(x)        FLAG_(x, 0x7, 13)
#define SECMEM_V3_FLAGS_MEM_LEVEL(x)    FLAG_(x, 0xF, 17)

uint32_t Secure_V3_SessionCreate(void **sess);
uint32_t Secure_V3_SessionDestroy(void **sess);
uint32_t Secure_V3_Enforcement(void *sess, uint32_t *enforcement);
uint32_t Secure_V3_Init(void *sess,
        uint64_t source,
        uint64_t flags,
        uint64_t paddr,
        uint64_t size);
uint32_t Secure_V3_MemCreate(void *sess, uint64_t *handle);
uint32_t Secure_V3_MemPeek(void *sess, uint64_t *handle);
uint32_t Secure_V3_MemAlloc(void *sess,
        uint64_t handle,
        uint64_t size,
        uint64_t *phyaddr);
uint32_t Secure_V3_MemToPhy(void *sess,
        uint64_t handle,
        uint64_t *phyaddr);
uint32_t Secure_V3_MemFill(void *sess,
        uint64_t handle,
        uint64_t offset,
        uint8_t *buffer,
        uint64_t size);
uint32_t Secure_V3_MemCopy(void *sess,
        uint64_t out_handle,
        uint64_t in_handle,
        uint32_t ranges,
        uint64_t dst_offset[],
        uint64_t src_offset[],
        uint64_t size[]);
uint32_t Secure_V3_MemCopyPhy(uint64_t dst_handle,
        uint64_t dst_offset,
        uint64_t src_phyaddr,
        uint64_t src_offset,
        uint64_t size);
uint32_t Secure_V3_MemCheck(void *sess,
        uint64_t handle,
        uint8_t *buffer,
        uint64_t len);
uint32_t Secure_V3_MemExport(void *sess,
        uint64_t handle,
        int *fd,
        uint64_t *maxsize);
uint32_t Secure_V3_MemAllocDMA(void *sess,
        uint64_t size,
        int *fd,
        uint64_t *handle,
        uint64_t *maxsize);
uint32_t Secure_V3_FdToHandle(void *sess, int fd);
uint32_t Secure_V3_FdToPaddr(void *sess, int fd);
uint32_t Secure_V3_MemPop(void *sess);
uint32_t Secure_V3_MemFree(void *sess, uint64_t handle);
uint32_t Secure_V3_MemRelease(void *sess, uint64_t handle);
uint32_t Secure_V3_MemFlush(void *sess);
uint32_t Secure_V3_MemClear(void *sess);
uint32_t Secure_V3_Statistic(void *sess,
        uint8_t* buffer,
        uint32_t size);
uint32_t Secure_V3_ShowResourceUsage(uint8_t *buffer, uint32_t size);
uint32_t Secure_V3_SetCsdData(void*sess,
        uint8_t *csd,
        uint32_t csd_len);
uint32_t Secure_V3_GetCsdDataDrmInfo(void *sess,
        uint64_t src_csd_addr,
        uint64_t csd_len,
        uint64_t *store_csd_phyaddr,
        uint64_t *store_csd_size,
        uint64_t overwrite);
uint32_t Secure_V3_GetPadding(void *sess,
        uint64_t* pad_addr,
        uint32_t *pad_size,
        uint32_t pad_type);
uint32_t Secure_V3_GetVp9HeaderSize(void *sess,
        void *src,
        uint64_t size,
        uint64_t *header_size,
        uint64_t *frames);
uint32_t Secure_V3_MergeCsdDataDrmInfo(void *sess,
        uint64_t *phyaddr,
        uint32_t *csd_len);
uint32_t Secure_V3_MergeCsdData(void *sess,
        uint64_t handle,
        uint64_t *csd_len);
uint32_t Secure_V3_Parse(void *sess,
        uint32_t type,
        uint64_t handle,
        uint8_t *buffer,
        uint64_t size,
        uint64_t *flag);
uint32_t Secure_V3_ResourceAlloc(void *sess,
        uint64_t* phyaddr,
        uint64_t *size);
uint32_t Secure_V3_ResourceFree(void *sess);
uint32_t Secure_V3_BindTVP(void *sess, uint32_t cas_id);
uint32_t Secure_V3_AudioValid(void *sess,
        void *src, // secure source phyaddr
        uint64_t size, //secure packet size
        uint32_t aud_type, // audio format AUD_VALID_TYPE
        uint8_t *aud_buf, // nonsecure output buf
        uint64_t buf_max_size); // aud_buf total size
uint32_t Secure_V3_GetSecmemSize(void *sess,
        uint64_t *mem_capacity,
        uint64_t *mem_available,
        uint32_t *handle_capacity,
        uint32_t *handle_available);
uint32_t Secure_V3_InitSecurePool(void *sess,
        uint64_t vd_index,
        uint64_t usage,
        uint64_t flags,
        int fd);
uint32_t Secure_V3_EnableTVPMemory(void *sess, uint64_t flags);
uint32_t Secure_V3_DestroySecurePool(void *sess);
uint32_t Secure_V3_UpdateFrameInfo(void *sess,
        uint32_t codec,
        int fd,
        uint64_t flags,
        uint64_t *size);
uint32_t Secure_V3_GetFreeBlockCount(void *sess,
        int fd,
        uint64_t frame_size,
        uint32_t *block_count,
        uint32_t *block_free_count);
uint32_t Secure_V3_PoolFlush(void *sess);
uint32_t Secure_V3_GetVersion(void);
uint32_t Secure_V3_GetResourceAddressAndSize(uint64_t *resource_address, uint32_t *resource_size);

uint32_t Secure_V3_ProbeProgram(void *sess,
                            uint64_t handle,
                            uint64_t size,
                            uint32_t* program_count,     // Input the number of buffers and output the actual number of programs
                            sec_ts_program_t* program_list);

uint32_t Secure_V3_GetStreamInfo(void *sess,
                            uint64_t handle,
                            uint64_t size,
                            uint32_t* program_pid,      // input and output
                            uint32_t* stream_count,     // Input the number of buffers and output the actual number of streams
                            sec_ts_component_t* stream_list);

uint32_t Secure_V3_FindPtsOffset(void *sess,
                            uint64_t handle,
                            uint64_t size,
                            uint64_t* pts,              // input and output
                            uint32_t stream_type,
                            int32_t* offset);

/*
 * Sideband API
 */
uint32_t Secure_V3_SetHandle(uint64_t handle);
uint32_t Secure_V3_GetHandle(uint64_t *handle);

/*
 * Dsc API
 */
int Dsc_SetTsnSource(const char *tsn_path, const char *tsn_from);
int Dsc_OpenDev(void **secmem_sess, uint32_t dsc_dev_id);
int Dsc_CloseDev(void **secmem_sess, uint32_t dsc_dev_id);
int Dsc_CreateSession(void *secmem_sess, uint32_t session_token, uint32_t dsc_dev_id);
int Dsc_ReleaseSession(void *secmem_sess, uint32_t session_token);
int Dsc_GetSessionInfo(void *secmem_sess, uint32_t session_token);
int Dsc_AllocChannel(void *secmem_sess, uint32_t session_token, uint32_t es_pid);
int Dsc_FreeChannel(void *secmem_sess, uint32_t session_token, uint32_t es_pid);
#ifdef __cplusplus
}
#endif


#endif /* _SECMEM_CA_H_ */
