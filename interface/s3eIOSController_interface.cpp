/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eIOSController.h"


// Define S3E_EXT_SKIP_LOADER_CALL_LOCK on the user-side to skip LoaderCallStart/LoaderCallDone()-entry.
// e.g. in s3eNUI this is used for generic user-side IwUI-based implementation.
#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
#if (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)) || defined I3D_ARCH_NACLX86_64
// For platforms missing stack-switching (WP8, NaCl, etc.) make loader-entry via LoaderCallStart/LoaderCallDone() on the user-side.
#define LOADER_CALL_LOCK
#endif
#endif


#include "s3eIOSController_interface.h"

static s3eIOSControllerFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x5b1cd4ff, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eIOSController");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x5b1cd4ff, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eIOSControllerAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult s3eIOSControllerRegister(s3eIOSControllerCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[0] func: s3eIOSControllerRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerRegister);
#endif

    s3eResult ret = g_Ext.m_s3eIOSControllerRegister(cbid, fn, userData);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerRegister);
#endif

    return ret;
}

s3eResult s3eIOSControllerUnRegister(s3eIOSControllerCallback cbid, s3eCallback fn)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[1] func: s3eIOSControllerUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerUnRegister);
#endif

    s3eResult ret = g_Ext.m_s3eIOSControllerUnRegister(cbid, fn);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerUnRegister);
#endif

    return ret;
}

uint32 s3eIOSControllerGetControllerCount()
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[2] func: s3eIOSControllerGetControllerCount"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetControllerCount);
#endif

    uint32 ret = g_Ext.m_s3eIOSControllerGetControllerCount();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetControllerCount);
#endif

    return ret;
}

s3eIOSController* s3eIOSControllerGetController(uint32 index)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[3] func: s3eIOSControllerGetController"));

    if (!_extLoad())
        return NULL;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetController);
#endif

    s3eIOSController* ret = g_Ext.m_s3eIOSControllerGetController(index);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetController);
#endif

    return ret;
}

s3eBool s3eIOSControllerSupportsBasic(s3eIOSController* controller)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[4] func: s3eIOSControllerSupportsBasic"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSupportsBasic);
#endif

    s3eBool ret = g_Ext.m_s3eIOSControllerSupportsBasic(controller);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSupportsBasic);
#endif

    return ret;
}

s3eBool s3eIOSControllerSupportsExtended(s3eIOSController* controller)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[5] func: s3eIOSControllerSupportsExtended"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSupportsExtended);
#endif

    s3eBool ret = g_Ext.m_s3eIOSControllerSupportsExtended(controller);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSupportsExtended);
#endif

    return ret;
}

s3eBool s3eIOSControllerSupportsMicro(s3eIOSController* controller)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[6] func: s3eIOSControllerSupportsMicro"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSupportsMicro);
#endif

    s3eBool ret = g_Ext.m_s3eIOSControllerSupportsMicro(controller);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSupportsMicro);
#endif

    return ret;
}

s3eBool s3eIOSControllerGetReportsAbsoluteDpadValues(s3eIOSController* controller)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[7] func: s3eIOSControllerGetReportsAbsoluteDpadValues"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetReportsAbsoluteDpadValues);
#endif

    s3eBool ret = g_Ext.m_s3eIOSControllerGetReportsAbsoluteDpadValues(controller);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetReportsAbsoluteDpadValues);
#endif

    return ret;
}

void s3eIOSControllerSetReportsAbsoluteDpadValues(s3eIOSController* controller, s3eBool value)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[8] func: s3eIOSControllerSetReportsAbsoluteDpadValues"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSetReportsAbsoluteDpadValues);
#endif

    g_Ext.m_s3eIOSControllerSetReportsAbsoluteDpadValues(controller, value);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSetReportsAbsoluteDpadValues);
#endif

    return;
}

s3eBool s3eIOSControllerGetAllowsRotation(s3eIOSController* controller)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[9] func: s3eIOSControllerGetAllowsRotation"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetAllowsRotation);
#endif

    s3eBool ret = g_Ext.m_s3eIOSControllerGetAllowsRotation(controller);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetAllowsRotation);
#endif

    return ret;
}

void s3eIOSControllerSetAllowsRotation(s3eIOSController* controller, s3eBool value)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[10] func: s3eIOSControllerSetAllowsRotation"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSetAllowsRotation);
#endif

    g_Ext.m_s3eIOSControllerSetAllowsRotation(controller, value);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSetAllowsRotation);
#endif

    return;
}

int32 s3eIOSControllerGetPlayerIndex(s3eIOSController* controller)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[11] func: s3eIOSControllerGetPlayerIndex"));

    if (!_extLoad())
        return -1;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetPlayerIndex);
#endif

    int32 ret = g_Ext.m_s3eIOSControllerGetPlayerIndex(controller);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetPlayerIndex);
#endif

    return ret;
}

void s3eIOSControllerSetPlayerIndex(s3eIOSController* controller, int32 index)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[12] func: s3eIOSControllerSetPlayerIndex"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSetPlayerIndex);
#endif

    g_Ext.m_s3eIOSControllerSetPlayerIndex(controller, index);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerSetPlayerIndex);
#endif

    return;
}

s3eBool s3eIOSControllerGetButtonState(s3eIOSController* controller, s3eIOSControllerButton button)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[13] func: s3eIOSControllerGetButtonState"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetButtonState);
#endif

    s3eBool ret = g_Ext.m_s3eIOSControllerGetButtonState(controller, button);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetButtonState);
#endif

    return ret;
}

float s3eIOSControllerGetAxisValue(s3eIOSController* controller, s3eIOSControllerAxis axis)
{
    IwTrace(IOSCONTROLLER_VERBOSE, ("calling s3eIOSController[14] func: s3eIOSControllerGetAxisValue"));

    if (!_extLoad())
        return 0.0f;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetAxisValue);
#endif

    float ret = g_Ext.m_s3eIOSControllerGetAxisValue(controller, axis);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, (void*)g_Ext.m_s3eIOSControllerGetAxisValue);
#endif

    return ret;
}
