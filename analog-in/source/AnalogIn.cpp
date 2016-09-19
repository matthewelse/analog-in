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
#include "jerryscript-mbed-util/logging.h"
#include "jerryscript-mbed-library-registry/wrap_tools.h"

#include "mbed.h"

DECLARE_CLASS_FUNCTION(AnalogIn, read)
{
    CHECK_ARGUMENT_COUNT(AnalogIn, read, (args_count == 0));

    uintptr_t native_ptr;
    jerry_get_object_native_handle(this_obj, &native_ptr);

    return jerry_create_number(((AnalogIn*)native_ptr)->read());
}

void NAME_FOR_CLASS_NATIVE_DESTRUCTOR(AnalogIn) (uintptr_t handle) {
    delete (AnalogIn*) handle;
}

DECLARE_CLASS_CONSTRUCTOR(AnalogIn) {
    CHECK_ARGUMENT_COUNT(AnalogIn, __constructor, (args_count == 1));
    CHECK_ARGUMENT_TYPE_ALWAYS(AnalogIn, __constructor, 0, number);

    int pin = jerry_get_number_value(args[0]);

    uintptr_t native_ptr = (uintptr_t)new AnalogIn((PinName)pin);

    jerry_value_t js_object = jerry_create_object();
    jerry_set_object_native_handle(js_object, native_ptr, NAME_FOR_CLASS_NATIVE_DESTRUCTOR(AnalogIn));

    ATTACH_CLASS_FUNCTION(js_object, AnalogIn, read);

    return js_object;
}
