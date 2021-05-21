#ifndef _GLV8_H
#define _GLV8_H

#include "v8.h"

using namespace v8;

void bindGL(Isolate *isolate, Local<ObjectTemplate> &gl);
void bindPlato(Isolate *isolate, Local<ObjectTemplate> &plato);

#endif
