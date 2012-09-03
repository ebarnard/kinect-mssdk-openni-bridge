//@COPYRIGHT@//
//
// Copyright (c) 2012, Tomoto S. Washio
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of the Tomoto S. Washio nor the names of his
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL TOMOTO S. WASHIO BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//@COPYRIGHT@//

#pragma once
#include "base.h"
#include "util.h"

class MSRKinectErrorStateCap :
	public virtual xn::ModuleErrorStateInterface
{
protected:
	virtual XnBool IsCapabilitySupported(const XnChar* strCapabilityName)
	{
		return streq(XN_CAPABILITY_ERROR_STATE, strCapabilityName);
	}

};

#define MSRKinectErrorStateCap_IMPL(pContext) \
public: \
	virtual xn::ModuleErrorStateInterface* GetErrorStateInterface() \
	{ \
		return this; \
	} \
	\
	virtual XnStatus GetErrorState() \
	{ \
		return pContext->GetRequirement()->GetState()->IsDisconnected() ? XN_STATUS_DEVICE_NOT_CONNECTED : XN_STATUS_OK; \
	} \
	\
	virtual XnStatus RegisterToErrorStateChange(XnModuleStateChangedHandler handler, void* pCookie, XnCallbackHandle& hCallback) \
	{ \
		return XN_STATUS_OK; /* not supported yet */ \
	} \
	\
	virtual void UnregisterFromErrorStateChange(XnCallbackHandle hCallback) \
	{ \
		/* not supported yet */ \
	}
