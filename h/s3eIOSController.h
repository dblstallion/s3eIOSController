/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_IOSCONTROLLER_H
#define S3E_EXT_IOSCONTROLLER_H

#include <s3eTypes.h>

// Opaque pointer struct
typedef struct s3eIOSController s3eIOSController;

typedef enum s3eIOSControllerCallback
{
	/**
	 * Called when a new controller is connected
	 * systemData will be a pointer to an s3eISOController for the connected device.
	 */
	S3E_IOSCONTROLLER_CALLBACK_CONNECTED,
	/**
	 * Called when a controller is disconnected
	 * systemData will be a pointer to an s3eISOController for the disconnected device.
	 */
	S3E_IOSCONTROLLER_CALLBACK_DISCONNECTED,
    /**
	 * Called when the pause button is pressed on a controller
	 * systemData will be a pointer to an s3eISOController for the connected device.
	 */
    S3E_IOSCONTROLLER_CALLBACK_PAUSE_PRESSED,
	
	// Marker for the last callback
	S3E_IOSCONTROLLER_CALLBACK_MAX
} s3eIOSControllerCallback;

typedef enum s3eIOSControllerButton
{
    // Basic controller
    S3E_IOSCONTROLLER_BUTTON_A,
    S3E_IOSCONTROLLER_BUTTON_B,
    S3E_IOSCONTROLLER_BUTTON_X,
    S3E_IOSCONTROLLER_BUTTON_Y,
    S3E_IOSCONTROLLER_BUTTON_DPAD_UP,
    S3E_IOSCONTROLLER_BUTTON_DPAD_DOWN,
    S3E_IOSCONTROLLER_BUTTON_DPAD_LEFT,
    S3E_IOSCONTROLLER_BUTTON_DPAD_RIGHT,
    S3E_IOSCONTROLLER_BUTTON_LEFT_SHOULDER,
    S3E_IOSCONTROLLER_BUTTON_RIGHT_SHOULDER,
    
    // Extended controller
    S3E_IOSCONTROLLER_BUTTON_LEFT_TRIGGER,
    S3E_IOSCONTROLLER_BUTTON_RIGHT_TRIGGER,
    S3E_IOSCONTROLLER_BUTTON_LEFT_THUMBSTICK_UP,
    S3E_IOSCONTROLLER_BUTTON_LEFT_THUMBSTICK_DOWN,
    S3E_IOSCONTROLLER_BUTTON_LEFT_THUMBSTICK_LEFT,
    S3E_IOSCONTROLLER_BUTTON_LEFT_THUMBSTICK_RIGHT,
    S3E_IOSCONTROLLER_BUTTON_RIGHT_THUMBSTICK_UP,
    S3E_IOSCONTROLLER_BUTTON_RIGHT_THUMBSTICK_DOWN,
    S3E_IOSCONTROLLER_BUTTON_RIGHT_THUMBSTICK_LEFT,
    S3E_IOSCONTROLLER_BUTTON_RIGHT_THUMBSTICK_RIGHT,
} s3eIOSControllerButton;

typedef enum s3eIOSControllerAxis
{
    S3E_IOSCONTROLLER_AXIS_DPAD_X,
    S3E_IOSCONTROLLER_AXIS_DPAD_Y,
    S3E_IOSCONTROLLER_AXIS_LEFT_THUMBSTICK_X,
    S3E_IOSCONTROLLER_AXIS_LEFT_THUMBSTICK_Y,
    S3E_IOSCONTROLLER_AXIS_RIGHT_THUMBSTICK_X,
    S3E_IOSCONTROLLER_AXIS_RIGHT_THUMBSTICK_Y,
    S3E_IOSCONTROLLER_AXIS_LEFT_TRIGGER,
    S3E_IOSCONTROLLER_AXIS_RIGHT_TRIGGER,
} s3eIOSControllerAxis;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Report if the IOSController extension is available.
 * @return S3E_TRUE if the IOSController extension is available. S3E_FALSE otherwise.
 */
s3eBool s3eIOSControllerAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref s3eIOSControllerCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userData Value to pass to the @e userData parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see s3eIOSControllerUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref s3eIOSControllerCallback enum.
 */
s3eResult s3eIOSControllerRegister(s3eIOSControllerCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback to unregister.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the s3eIOSControllerCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see s3eIOSControllerRegister
 */
s3eResult s3eIOSControllerUnRegister(s3eIOSControllerCallback cbid, s3eCallback fn);

uint32 s3eIOSControllerGetControllerCount();

s3eIOSController* s3eIOSControllerGetController(uint32 index);

s3eBool s3eIOSControllerSupportsBasic(s3eIOSController* controller);

s3eBool s3eIOSControllerSupportsExtended(s3eIOSController* controller);

s3eBool s3eIOSControllerSupportsMicro(s3eIOSController* controller);

s3eBool s3eIOSControllerGetReportsAbsoluteDpadValues(s3eIOSController* controller);

void s3eIOSControllerSetReportsAbsoluteDpadValues(s3eIOSController* controller, s3eBool value);

s3eBool s3eIOSControllerGetAllowsRotation(s3eIOSController* controller);

void s3eIOSControllerSetAllowsRotation(s3eIOSController* controller, s3eBool value);

int32 s3eIOSControllerGetPlayerIndex(s3eIOSController* controller);

void s3eIOSControllerSetPlayerIndex(s3eIOSController* controller, int32 index);

s3eBool s3eIOSControllerGetButtonState(s3eIOSController* controller, s3eIOSControllerButton button);

float s3eIOSControllerGetAxisValue(s3eIOSController* controller, s3eIOSControllerAxis axis);

// \cond HIDDEN_DEFINES
S3E_END_C_DECL
// \endcond

#endif /* !S3E_EXT_IOSCONTROLLER_H */
