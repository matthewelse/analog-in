/* Copyright (c) 2016 Matthew Else. All rights reserved.
 *
 * The MIT License (MIT)
 * Copyright (c) 2016 Matthew Else
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef _JERRYSCRIPT_LIB_ANALOG_IN_H
#define _JERRYSCRIPT_LIB_ANALOG_IN_H

#include "analog-in/analog_in_js.h"
#include "jerryscript-mbed-library-registry/wrap_tools.h"

DECLARE_JS_WRAPPER_REGISTRATION (analog_in)
{
    REGISTER_CLASS_CONSTRUCTOR(AnalogIn);
}

#endif // _JERRYSCRIPT_LIB_ANALOG_IN_H
