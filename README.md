s3eIOSController
================

Controller support for iOS using the Game Controller framework

Controllers must support either basic or micro profiles. Controllers can also
support extended profiles if they support basic ones. Check for support with
s3eIOSControllerSupportsBasic() etc.

New tvOS Siri Remotes are a type of micro controller. Micro controllers have A,
X and Menu buttons and a direction pad of some sort. On the Siri Remote
(currently only type of micro controller) A = click the pad, X = play/pause,
menu = menu.

Basic controllers have a D-pad, A B X Y buttons, pause button and L R shoulder
buttons.

Extended controllers add the following to basic ones: L and R trigger buttons,
left and right thumb sticks. The sticks can generate values from -1 to 1 on
each axis. The trigger buttons can also generate "axis" values from 0.0 to 1.0
depending on how far they are pressed.

Marmalade doesn't publicly support tvOS but will soon. Currently tvOS stuff is
defined out/in with standard Apple define TARGET_OS_TV in code.

If you have access to a version of Marmalade that supports tvOS, you need to
define SDK_SUPPORTS_TVOS in your MKB to pick up the tvOS extension libs.

No example is provided. It is recommened to use IwGameController
(github.com/nickchops/IwGameController) which is a high level cross platform
wrapper for this an other controller extensions. IwGameController has
an example, Quick/Lua wrapper and a remote control app for phones.


------------------------------------------------------------------------------
(C) 2014 Nick Smith.

All code is provided under the MIT license unless stated otherwise:

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
