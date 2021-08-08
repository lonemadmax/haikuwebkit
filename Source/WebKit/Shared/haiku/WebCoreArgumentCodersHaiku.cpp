/*
 * Copyright (C) 2014,2019 Haiku, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "DataReference.h"
#include "WebCoreArgumentCoders.h"

#include "NotImplemented.h"
#include <WebCore/CertificateInfo.h>
#include <WebCore/DictionaryPopupInfo.h>
#include <WebCore/FontAttributes.h>
#include <WebCore/ResourceError.h>
#include <WebCore/ResourceRequest.h>
#include <WebCore/ResourceResponse.h>
#include <wtf/text/CString.h>

using namespace WebCore;

namespace IPC {

void ArgumentCoder<ResourceRequest>::encodePlatformData(Encoder& encoder, const ResourceRequest& resourceRequest)
{
    resourceRequest.encodePlatformData(encoder);
}

bool ArgumentCoder<ResourceRequest>::decodePlatformData(Decoder& decoder, ResourceRequest& resourceRequest)
{
    return resourceRequest.decodePlatformData(decoder);
}

void ArgumentCoder<CertificateInfo>::encode(Encoder& encoder, const CertificateInfo& certificateInfo)
{
    //nothing to encode ceriticateinfo is null
}

bool ArgumentCoder<CertificateInfo>::decode(Decoder& decoder, CertificateInfo& certificateInfo)
{
    //nothing to decode just return true
    return true;
}

void ArgumentCoder<ResourceError>::encodePlatformData(Encoder& encoder, const ResourceError& resourceError)
{
    encoder << resourceError.domain();
    encoder << resourceError.errorCode();
    encoder << resourceError.failingURL().string();
    encoder << resourceError.localizedDescription();
}

bool ArgumentCoder<ResourceError>::decodePlatformData(Decoder& decoder, ResourceError& resourceError)
{
    String domain;
    if (!decoder.decode(domain))
        return false;

    int errorCode;
    if (!decoder.decode(errorCode))
        return false;

    String failingURL;
    if (!decoder.decode(failingURL))
        return false;

    String localizedDescription;
    if (!decoder.decode(localizedDescription))
        return false;

    resourceError = ResourceError(domain, errorCode, URL(URL(), failingURL), localizedDescription);
    return true;
}

void ArgumentCoder<ProtectionSpace>::encodePlatformData(Encoder&, const ProtectionSpace&)
{
    ASSERT_NOT_REACHED();
}

bool ArgumentCoder<ProtectionSpace>::decodePlatformData(Decoder&, ProtectionSpace&)
{
    ASSERT_NOT_REACHED();
    return false;
}

void ArgumentCoder<Credential>::encodePlatformData(Encoder&, const Credential&)
{
    ASSERT_NOT_REACHED();
}

bool ArgumentCoder<Credential>::decodePlatformData(Decoder&, Credential&)
{
    ASSERT_NOT_REACHED();
    return false;
}

Optional<FontAttributes> ArgumentCoder<FontAttributes>::decodePlatformData(Decoder&, FontAttributes&)
{
    ASSERT_NOT_REACHED();
    return WTF::nullopt;
}

bool ArgumentCoder<DictionaryPopupInfo>::decodePlatformData(Decoder&, DictionaryPopupInfo&)
{
    ASSERT_NOT_REACHED();
    return false;
}

}


