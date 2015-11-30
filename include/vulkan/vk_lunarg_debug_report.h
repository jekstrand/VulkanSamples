//
// File: vk_lunarg_debug_report.h
//
/*
 *
 * Copyright (C) 2015 Valve Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Author: Cody Northrop <cody@lunarg.com>
 * Author: Courtney Goeltzenleuchter <courtney@LunarG.com>
 * Author: Tony Barbour <tony@LunarG.com>
 *
 */

#ifndef __VK_LUNARG_DEBUG_REPORT_H__
#define __VK_LUNARG_DEBUG_REPORT_H__

#include "vulkan/vulkan.h"

#define VK_EXT_LUNARG_DEBUG_REPORT_EXTENSION_NUMBER 11
#define VK_EXT_LUNARG_DEBUG_REPORT_EXTENSION_REVISION 1
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*
***************************************************************************************************
*   DebugReport Vulkan Extension API
***************************************************************************************************
*/
typedef enum {
    VK_OBJECT_TYPE_INSTANCE = 0,
    VK_OBJECT_TYPE_PHYSICAL_DEVICE = 1,
    VK_OBJECT_TYPE_DEVICE = 2,
    VK_OBJECT_TYPE_QUEUE = 3,
    VK_OBJECT_TYPE_COMMAND_BUFFER = 4,
    VK_OBJECT_TYPE_DEVICE_MEMORY = 5,
    VK_OBJECT_TYPE_BUFFER = 6,
    VK_OBJECT_TYPE_BUFFER_VIEW = 7,
    VK_OBJECT_TYPE_IMAGE = 8,
    VK_OBJECT_TYPE_IMAGE_VIEW = 9,
    VK_OBJECT_TYPE_ATTACHMENT_VIEW = 10,
    VK_OBJECT_TYPE_SHADER_MODULE = 12,
    VK_OBJECT_TYPE_SHADER = 13,
    VK_OBJECT_TYPE_PIPELINE = 14,
    VK_OBJECT_TYPE_PIPELINE_LAYOUT = 15,
    VK_OBJECT_TYPE_SAMPLER = 16,
    VK_OBJECT_TYPE_DESCRIPTOR_SET = 17,
    VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT = 18,
    VK_OBJECT_TYPE_DESCRIPTOR_POOL = 19,
    VK_OBJECT_TYPE_FENCE = 20,
    VK_OBJECT_TYPE_SEMAPHORE = 21,
    VK_OBJECT_TYPE_EVENT = 22,
    VK_OBJECT_TYPE_QUERY_POOL = 23,
    VK_OBJECT_TYPE_FRAMEBUFFER = 24,
    VK_OBJECT_TYPE_RENDER_PASS = 25,
    VK_OBJECT_TYPE_PIPELINE_CACHE = 26,
    VK_OBJECT_TYPE_SURFACE_KHR = 27,
    VK_OBJECT_TYPE_SWAPCHAIN_KHR = 28,
    VK_OBJECT_TYPE_COMMAND_POOL = 29,
    VK_OBJECT_TYPE_BEGIN_RANGE = VK_OBJECT_TYPE_INSTANCE,
    VK_OBJECT_TYPE_END_RANGE = VK_OBJECT_TYPE_COMMAND_POOL,
    VK_OBJECT_TYPE_NUM = (VK_OBJECT_TYPE_COMMAND_POOL - VK_OBJECT_TYPE_INSTANCE + 1),
    VK_OBJECT_TYPE_MAX_ENUM = 0x7FFFFFFF
} VkDebugReportObjectTypeLUNARG;

#define VK_EXT_LUNARG_DEBUG_REPORT_EXTENSION_NAME "VK_EXT_LUNARG_debug_report"

VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDebugReportCallbackLUNARG)

// ------------------------------------------------------------------------------------------------
// Enumerations

typedef enum VkDebugReportFlagsLUNARG_
{
    VK_DEBUG_REPORT_INFO_BIT       = 0x0001,
    VK_DEBUG_REPORT_WARN_BIT       = 0x0002,
    VK_DEBUG_REPORT_PERF_WARN_BIT  = 0x0004,
    VK_DEBUG_REPORT_ERROR_BIT      = 0x0008,
    VK_DEBUG_REPORT_DEBUG_BIT      = 0x0010,
} VkDebugReportFlagBitsLUNARG;
typedef VkFlags VkDebugReportFlagsLUNARG;

// Debug Report ERROR codes
typedef enum _DEBUG_REPORT_ERROR
{
    DEBUG_REPORT_NONE,                  // Used for INFO & other non-error messages
    DEBUG_REPORT_CALLBACK_REF,          // Callbacks were not destroyed prior to calling DestroyInstance
} DEBUG_REPORT_ERROR;

#define VK_DEBUG_REPORT_ENUM_EXTEND(type, id)    ((type)(VK_EXT_LUNARG_DEBUG_REPORT_EXTENSION_NUMBER * -1000 + (id)))

#define VK_OBJECT_TYPE_MSG_CALLBACK VK_DEBUG_REPORT_ENUM_EXTEND(VkDebugReportObjectTypeLUNARG, 0)
#define VK_ERROR_VALIDATION_FAILED VK_DEBUG_REPORT_ENUM_EXTEND(VkResult, 0)
#define VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_LUNARG VK_DEBUG_REPORT_ENUM_EXTEND(VkStructureType, 0)

// ------------------------------------------------------------------------------------------------
// Vulkan function pointers

typedef VkBool32 (*PFN_vkDebugReportCallbackLUNARG)(
    VkFlags                             msgFlags,
    VkDebugReportObjectTypeLUNARG       objType,
    uint64_t                            srcObject,
    size_t                              location,
    int32_t                             msgCode,
    const char*                         pLayerPrefix,
    const char*                         pMsg,
    const void*                         pUserData);

typedef struct VkDebugReportCallbackCreateInfoLUNARG {
    VkStructureType                     sType;
    const void*                         pNext;
    VkDebugReportFlagsLUNARG            flags;
    PFN_vkDebugReportCallbackLUNARG     pfnCallback;
    const void*                         pUserData;
} VkDebugReportCallbackCreateInfoLUNARG;

// ------------------------------------------------------------------------------------------------
// API functions

typedef VkResult (VKAPI_PTR *PFN_vkCreateDebugReportCallbackLUNARG)(VkInstance instance, VkDebugReportCallbackCreateInfoLUNARG *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDebugReportCallbackLUNARG* pCallback);
typedef void (VKAPI_PTR *PFN_vkDestroyDebugReportCallbackLUNARG)(VkInstance instance, VkDebugReportCallbackLUNARG callback, const VkAllocationCallbacks *pAllocator);

#ifdef VK_PROTOTYPES

// DebugReport extension entrypoints
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackLUNARG(
    VkInstance                                  instance,
    VkDebugReportCallbackCreateInfoLUNARG*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackLUNARG*                pCallback);

VKAPI_ATTR void VKAPI_CALL vkDestroyDebugReportCallbackLUNARG(
    VkInstance                                  instance,
    VkDebugReportCallbackLUNARG                 callback,
    const VkAllocationCallbacks*                pAllocator);
#endif // VK_PROTOTYPES

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // __VK_LUNARG_DEBUG_REPORT_H__