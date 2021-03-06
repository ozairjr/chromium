// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "crypto/keychain_mac.h"

namespace crypto {

MacKeychain::MacKeychain() {}

MacKeychain::~MacKeychain() {}

OSStatus MacKeychain::ItemCopyAttributesAndData(
    SecKeychainItemRef itemRef,
    SecKeychainAttributeInfo* info,
    SecItemClass* itemClass,
    SecKeychainAttributeList** attrList,
    UInt32* length,
    void** outData) const {
  return SecKeychainItemCopyAttributesAndData(itemRef, info, itemClass,
                                              attrList, length, outData);
}

OSStatus MacKeychain::ItemModifyAttributesAndData(
    SecKeychainItemRef itemRef,
    const SecKeychainAttributeList* attrList,
    UInt32 length,
    const void* data) const {
  return SecKeychainItemModifyAttributesAndData(itemRef, attrList, length,
                                                data);
}

OSStatus MacKeychain::ItemFreeAttributesAndData(
    SecKeychainAttributeList* attrList,
    void* data) const {
  return SecKeychainItemFreeAttributesAndData(attrList, data);
}

OSStatus MacKeychain::ItemDelete(SecKeychainItemRef itemRef) const {
  return SecKeychainItemDelete(itemRef);
}

OSStatus MacKeychain::SearchCreateFromAttributes(
    CFTypeRef keychainOrArray,
    SecItemClass itemClass,
    const SecKeychainAttributeList* attrList,
    SecKeychainSearchRef* searchRef) const {
  return SecKeychainSearchCreateFromAttributes(keychainOrArray, itemClass,
                                               attrList, searchRef);
}

OSStatus MacKeychain::SearchCopyNext(SecKeychainSearchRef searchRef,
                                     SecKeychainItemRef* itemRef) const {
  return SecKeychainSearchCopyNext(searchRef, itemRef);
}

OSStatus MacKeychain::AddInternetPassword(
    SecKeychainRef keychain,
    UInt32 serverNameLength,
    const char* serverName,
    UInt32 securityDomainLength,
    const char* securityDomain,
    UInt32 accountNameLength,
    const char* accountName,
    UInt32 pathLength,
    const char* path,
    UInt16 port,
    SecProtocolType protocol,
    SecAuthenticationType authenticationType,
    UInt32 passwordLength,
    const void* passwordData,
    SecKeychainItemRef* itemRef) const {
  return SecKeychainAddInternetPassword(keychain,
                                        serverNameLength, serverName,
                                        securityDomainLength, securityDomain,
                                        accountNameLength, accountName,
                                        pathLength, path,
                                        port, protocol, authenticationType,
                                        passwordLength, passwordData,
                                        itemRef);
}

OSStatus MacKeychain::FindGenericPassword(CFTypeRef keychainOrArray,
                                          UInt32 serviceNameLength,
                                          const char* serviceName,
                                          UInt32 accountNameLength,
                                          const char* accountName,
                                          UInt32* passwordLength,
                                          void** passwordData,
                                          SecKeychainItemRef* itemRef) const {
  return SecKeychainFindGenericPassword(keychainOrArray,
                                        serviceNameLength,
                                        serviceName,
                                        accountNameLength,
                                        accountName,
                                        passwordLength,
                                        passwordData,
                                        itemRef);
}

OSStatus MacKeychain::ItemFreeContent(SecKeychainAttributeList* attrList,
                                      void* data) const {
  return SecKeychainItemFreeContent(attrList, data);
}

OSStatus MacKeychain::AddGenericPassword(SecKeychainRef keychain,
                                         UInt32 serviceNameLength,
                                         const char* serviceName,
                                         UInt32 accountNameLength,
                                         const char* accountName,
                                         UInt32 passwordLength,
                                         const void* passwordData,
                                         SecKeychainItemRef* itemRef) const {
  return SecKeychainAddGenericPassword(keychain,
                                       serviceNameLength,
                                       serviceName,
                                       accountNameLength,
                                       accountName,
                                       passwordLength,
                                       passwordData,
                                       itemRef);
}

void MacKeychain::Free(CFTypeRef ref) const {
  if (ref)
    CFRelease(ref);
}

}  // namespace crypto
