// Copyright (c) 2006-2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sandbox/src/service_resolver.h"

#include "base/logging.h"
#include "base/win/pe_image.h"

namespace sandbox {

NTSTATUS ServiceResolverThunk::ResolveInterceptor(
    const void* interceptor_module,
    const char* interceptor_name,
    const void** address) {
  // After all, we are using a locally mapped version of the exe, so the
  // action is the same as for a target function.
  return ResolveTarget(interceptor_module, interceptor_name,
                       const_cast<void**>(address));
}

// In this case all the work is done from the parent, so resolve is
// just a simple GetProcAddress.
NTSTATUS ServiceResolverThunk::ResolveTarget(const void* module,
                                             const char* function_name,
                                             void** address) {
  DCHECK(address);
  if (NULL == module)
    return STATUS_UNSUCCESSFUL;

  base::win::PEImage module_image(module);
  *address = module_image.GetProcAddress(function_name);

  if (NULL == *address) {
    NOTREACHED();
    return STATUS_UNSUCCESSFUL;
  }

  return STATUS_SUCCESS;
}

}  // namespace sandbox
