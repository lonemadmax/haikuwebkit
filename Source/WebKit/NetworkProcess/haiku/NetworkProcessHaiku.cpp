/*
 * Copyright (C) 2019 Haiku, Inc.
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
#include "NetworkProcess.h"

#include "NetworkProcessCreationParameters.h"
#include <WebCore/NetworkStorageSession.h>
#include <WebCore/NotImplemented.h>

#include "NetworkConnectionToWebProcess.h"
#include "NetworkProcessProxyMessages.h"
#include <OS.h>
#include <String.h>

namespace WebCore
{
	class NetworkStorageSession;
}

namespace WebKit {

using namespace WebCore;

void NetworkProcess::platformInitializeNetworkProcess(const NetworkProcessCreationParameters& parameters)
{
    notImplemented();
}

void NetworkProcess::allowSpecificHTTPSCertificateForHost(const CertificateInfo& certificateInfo, const String& host)
{
    notImplemented();
}

void NetworkProcess::platformProcessDidTransitionToForeground()
{
    notImplemented();
}

void NetworkProcess::platformProcessDidTransitionToBackground()
{
    notImplemented();
}

void NetworkProcess::platformTerminate()
{
    notImplemented();
}

void NetworkProcess::clearDiskCache(WallTime modifiedSince, CompletionHandler<void()>&& completionHandler)
{
    notImplemented();
}

#if 0
void NetworkProcess::createNetworkConnectionToWebProcessHaiku(bool isServiceWorkerProcess, WebCore::RegistrableDomain&& registrableDomain,int64_t webPID)
{
	team_id webID = (team_id)webPID; 
	uint32_t connectionRandkey = (uint32_t)find_thread(NULL);
	BString key;
	key.SetToFormat("%u",connectionRandkey);
	
	/* Network Process uses current thread id as key for workqueue identification and shares its pid and key to webprocess
	So a connection can be established*/
	auto connection = NetworkConnectionToWebProcess::create(*this,{webID,key});
	m_webProcessConnections.append(WTFMove(connection));
	
	IPC::Attachment clientConnector(getpid(),connectionRandkey);
	parentProcessConnection()->send(Messages::NetworkProcessProxy::DidCreateNetworkConnectionToWebProcess(clientConnector), 0);
	createNetworkConnectionToWebProcess(isServiceWorkerProcess,std::move(registrableDomain));
}
#endif

} // namespace WebKit
