/*
 * Copyright (C) 2021 Apple Inc. All rights reserved.
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

#pragma once

#include <wtf/CompletionHandler.h>
#include <wtf/Vector.h>
#include <wtf/WeakPtr.h>
#include <wtf/text/CString.h>

#if PLATFORM(COCOA)
#include <wtf/RetainPtr.h>
#include <wtf/spi/darwin/XPCSPI.h>
#endif

namespace WebKit {

class NetworkSession;

namespace PCM {

enum class MessageType : uint8_t;
using EncodedMessage = Vector<uint8_t>;

class Connection : public CanMakeWeakPtr<Connection> {
public:
    Connection() = default;
#if PLATFORM(COCOA)
    explicit Connection(RetainPtr<xpc_connection_t>&& connection)
        : m_connection(WTFMove(connection)) { }
    xpc_connection_t get() const { return m_connection.get(); }
    void send(xpc_object_t) const;
    void sendWithReply(xpc_object_t, CompletionHandler<void(xpc_object_t)>&&) const;
protected:
    mutable RetainPtr<xpc_connection_t> m_connection;
#endif
};

class ConnectionToMachService : public Connection {
public:
    ConnectionToMachService(CString&& machServiceName, NetworkSession&);

    void send(MessageType, EncodedMessage&&) const;
    void sendWithReply(MessageType, EncodedMessage&&, CompletionHandler<void(EncodedMessage&&)>&&) const;

private:
    void initializeConnectionIfNeeded() const;
#if PLATFORM(COCOA)
    void checkForDebugMessageBroadcast(xpc_object_t) const;
#endif
    void sendDebugModeIsEnabledMessageIfNecessary() const;

    const CString m_machServiceName;
    WeakPtr<NetworkSession> m_networkSession;
};

} // namespace PCM

} // namespace WebKit
