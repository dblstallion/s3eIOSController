/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "s3eIOSController_autodefs.h"
#include "s3eEdk.h"
#include "s3eIOSController.h"
//Declarations of Init and Term functions
extern s3eResult s3eIOSControllerInit();
extern void s3eIOSControllerTerminate();


s3eResult s3eIOSControllerRegister(s3eIOSControllerCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_IOSCONTROLLER_HASH, S3E_IOSCONTROLLER_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult s3eIOSControllerUnRegister(s3eIOSControllerCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_IOSCONTROLLER_HASH, S3E_IOSCONTROLLER_CALLBACK_MAX, cbid, fn);
}

void s3eIOSControllerRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[10];
    funcPtrs[0] = (void*)s3eIOSControllerRegister;
    funcPtrs[1] = (void*)s3eIOSControllerUnRegister;
    funcPtrs[2] = (void*)s3eIOSControllerGetControllerCount;
    funcPtrs[3] = (void*)s3eIOSControllerGetController;
    funcPtrs[4] = (void*)s3eIOSControllerSupportsBasic;
    funcPtrs[5] = (void*)s3eIOSControllerSupportsExtended;
    funcPtrs[6] = (void*)s3eIOSControllerGetPlayerIndex;
    funcPtrs[7] = (void*)s3eIOSControllerSetPlayerIndex;
    funcPtrs[8] = (void*)s3eIOSControllerGetButtonState;
    funcPtrs[9] = (void*)s3eIOSControllerGetAxisValue;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[10] = { 0 };

    /*
     * Register the extension
     */
s3eEdkRegister("s3eIOSController", funcPtrs, sizeof(funcPtrs), flags, s3eIOSControllerInit, s3eIOSControllerTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eIOSControllerStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eIOSControllerRegisterExt;
    return 0;
}

int g_s3eIOSControllerVal = s3eIOSControllerStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eIOSControllerRegisterExt();
}
#endif

#endif
