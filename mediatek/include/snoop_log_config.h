/* Copyright Statement:
 * *
 * * This software/firmware and related documentation ("MediaTek Software") are
 * * protected under relevant copyright laws. The information contained herein
 * * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * * Without the prior written permission of MediaTek inc. and/or its licensors,
 * * any reproduction, modification, use or disclosure of MediaTek Software,
 * * and information contained herein, in whole or in part, shall be strictly prohibited.
 * *
 * * MediaTek Inc. (C) 2016. All rights reserved.
 * *
 * * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 * *
 * * The following software/firmware and/or related documentation ("MediaTek Software")
 * * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * * applicable license agreements with MediaTek Inc.
 * */

#pragma once

#if defined(MTK_STACK_CONFIG_LOG) && (MTK_STACK_CONFIG_LOG == TRUE)

#include <memory>

#include <base/macros.h>

namespace base {
template <typename T>
struct DefaultSingletonTraits;
}  // namespace base

namespace vendor {
namespace mediatek {
namespace bluetooth {
namespace stack {

constexpr char RECYCLE_RATE_KEY[] = "RECYCLE_RATE";
constexpr char PACKETS_CACHE_UPPER_LIMIT_KEY[] = "PACKETS_CACHE_UPPER_LIMIT";
constexpr char MAX_LOG_SIZE_PER_FILE_KEY[] = "MAX_LOG_SIZE_PER_FILE";

class SnoopLogConfigImpl;

class SnoopLogConfig {
 public:
  static SnoopLogConfig* GetInstance();

  void Setup();
  void TearDown();
  void Refresh();
  int64_t GetMaxTotalLogsSize() const;
  int64_t GetMaxLogSizePerFile() const;
  int GetPacketCacheUpperLimit() const;
  int64_t GetRecycleLogsSize() const;

 private:
  SnoopLogConfig();
  friend struct base::DefaultSingletonTraits<SnoopLogConfig>;
  std::unique_ptr<SnoopLogConfigImpl> config_impl_;

  DISALLOW_COPY_AND_ASSIGN(SnoopLogConfig);
};

}  // namespace stack
}  // namespace bluetooth
}  // namespace mediatek
}  // namespace vendor

#endif
