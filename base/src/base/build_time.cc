// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/build_time.h"

// Imports the generated build date, i.e. BUILD_DATE.
//#include "base/generated_build_date.h" 此文件动态生成，只有一个生成时间宏，定义如下
#ifndef BUILD_DATE
#define BUILD_DATE "Oct 02 2018 05:00:00"
#endif // BUILD_DATE

#include "base/logging.h"
#include "base/time/time.h"

namespace base {

Time GetBuildTime() {
  Time integral_build_time;
  // BUILD_DATE is exactly "Mmm DD YYYY HH:MM:SS".
  // See //build/write_build_date_header.py. "HH:MM:SS" is normally expected to
  // be "05:00:00" but is not enforced here.
  bool result = Time::FromUTCString(BUILD_DATE, &integral_build_time);
  DCHECK(result);
  return integral_build_time;
}

}  // namespace base
