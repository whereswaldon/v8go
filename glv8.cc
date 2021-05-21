#include <stdlib.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "v8.h"
using namespace v8;

extern bool sonic_gl_error_check;

#define GL_STENCIL_INDEX 0x1901

#define ParameterCheckFailed(isolate) { \
        std::string argsStr = "";\
        for (int c = 0; c < args.Length(); ++c) {\
            String::Utf8Value arg_utf8(isolate, args[c]);\
            std::string arg(*arg_utf8);\
            argsStr += arg;\
            if (c != args.Length() - 1) {\
                argsStr += ", ";\
            }\
        }\
        char buff[256]; sprintf( buff, "function: %s; args: %s; parameter check failed;",  __FUNCTION__, argsStr.c_str()); \
        fprintf(stderr, "function: %s; args: %s; parameter check failed;\n",  __FUNCTION__, argsStr.c_str());\
        isolate->ThrowException(Exception::Error(String::NewFromUtf8(isolate, buff).ToLocalChecked()));\
}

#define THROW_ON_GL_ERROR(isolate) { \
    int errno;\
    if (sonic_gl_error_check && (errno = glGetError()) != GL_NO_ERROR) {\
        std::string argsStr = "";\
        for (int c = 0; c < args.Length(); ++c) {\
            String::Utf8Value arg_utf8(isolate, args[c]);\
            std::string arg(*arg_utf8);\
            argsStr += arg;\
            if (c != args.Length() - 1) {\
                argsStr += ", ";\
            }\
        }\
        char buff[256]; sprintf( buff, "function: %s; args: %s; gl error: %d;",  __FUNCTION__, argsStr.c_str(), errno ); \
        fprintf(stderr, "function: %s; args: %s; gl error: %d;\n",  __FUNCTION__, argsStr.c_str(), errno ); \
        isolate->ThrowException(Exception::Error(String::NewFromUtf8(isolate, buff).ToLocalChecked()));\
    }\
}

static void glActiveTexture_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glActiveTexture(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glAttachShader_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glAttachShader(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBindAttribLocation_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	String::Utf8Value _utf0(isolate, arg_2);
	glBindAttribLocation(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), *_utf0);
	THROW_ON_GL_ERROR(isolate)
}

static void glBindBuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBindBuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBindFramebuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBindFramebuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBindRenderbuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBindRenderbuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBindTexture_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBindTexture(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBlendColor_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsNumber() && arg_1->IsNumber() && arg_2->IsNumber() && arg_3->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBlendColor((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_3->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBlendEquation_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBlendEquation(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBlendEquationSeparate_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBlendEquationSeparate(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBlendFunc_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBlendFunc(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBlendFuncSeparate_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glBlendFuncSeparate(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBufferData_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents1 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glBufferData(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents1.Data(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glBufferSubData_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents2 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glBufferSubData(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents2.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glCheckFramebufferStatus_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Integer::New(isolate, glCheckFramebufferStatus(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glClear_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glClear(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glClearColor_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsNumber() && arg_1->IsNumber() && arg_2->IsNumber() && arg_3->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glClearColor((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_3->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glClearDepthf_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glClearDepthf((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glClearStencil_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glClearStencil(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glColorMask_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsBoolean() && arg_1->IsBoolean() && arg_2->IsBoolean() && arg_3->IsBoolean()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glColorMask(arg_0->BooleanValue(args.GetIsolate()), arg_1->BooleanValue(args.GetIsolate()), arg_2->BooleanValue(args.GetIsolate()), arg_3->BooleanValue(args.GetIsolate()));
	THROW_ON_GL_ERROR(isolate)
}

static void glCompileShader_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glCompileShader(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glCompressedTexImage2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	Local<Value> arg_7 = args[7];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32() && arg_5->IsInt32() && arg_6->IsInt32() && arg_7->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents3 = Local<TypedArray>::Cast(arg_7)->Buffer()->GetContents();
	glCompressedTexImage2D(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_5->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_6->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents3.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glCompressedTexSubImage2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	Local<Value> arg_7 = args[7];
	Local<Value> arg_8 = args[8];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32() && arg_5->IsInt32() && arg_6->IsInt32() && arg_7->IsInt32() && arg_8->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents4 = Local<TypedArray>::Cast(arg_8)->Buffer()->GetContents();
	glCompressedTexSubImage2D(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_5->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_6->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_7->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents4.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glCopyTexImage2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	Local<Value> arg_7 = args[7];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32() && arg_5->IsInt32() && arg_6->IsInt32() && arg_7->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glCopyTexImage2D(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_5->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_6->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_7->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glCopyTexSubImage2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	Local<Value> arg_7 = args[7];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32() && arg_5->IsInt32() && arg_6->IsInt32() && arg_7->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glCopyTexSubImage2D(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_5->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_6->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_7->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glCreateProgram_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	args.GetReturnValue().Set(Integer::New(isolate, glCreateProgram()));
	THROW_ON_GL_ERROR(isolate)
}

static void glCreateShader_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Integer::New(isolate, glCreateShader(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glCullFace_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glCullFace(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDeleteBuffers_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents5 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glDeleteBuffers(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents5.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glDeleteFramebuffers_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents6 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glDeleteFramebuffers(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents6.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glDeleteProgram_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDeleteProgram(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDeleteRenderbuffers_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents7 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glDeleteRenderbuffers(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents7.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glDeleteShader_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDeleteShader(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDeleteTextures_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents8 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glDeleteTextures(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents8.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glDepthFunc_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDepthFunc(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDepthMask_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsBoolean()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDepthMask(arg_0->BooleanValue(args.GetIsolate()));
	THROW_ON_GL_ERROR(isolate)
}

static void glDepthRangef_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsNumber() && arg_1->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}

	glDepthRangef((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDetachShader_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDetachShader(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDisable_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDisable(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDisableVertexAttribArray_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDisableVertexAttribArray(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDrawArrays_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glDrawArrays(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glDrawElements_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32())) {
		ParameterCheckFailed(isolate)
		return;
	}
	glDrawElements(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid *) (size_t) args[3]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)

}
static void glEnable_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glEnable(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glEnableVertexAttribArray_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glEnableVertexAttribArray(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glFinish_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	glFinish();
	THROW_ON_GL_ERROR(isolate)
}

static void glFlush_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	glFlush();
	THROW_ON_GL_ERROR(isolate)
}

static void glFramebufferRenderbuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glFramebufferRenderbuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glFramebufferTexture2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glFramebufferTexture2D(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glFrontFace_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glFrontFace(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glGenBuffers_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents9 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGenBuffers(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents9.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGenerateMipmap_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glGenerateMipmap(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glGenFramebuffers_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents10 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGenFramebuffers(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents10.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGenRenderbuffers_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents11 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGenRenderbuffers(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents11.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGenTextures_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents12 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGenTextures(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents12.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetActiveAttrib_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsTypedArray() && arg_4->IsTypedArray() && arg_5->IsTypedArray() && arg_6->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents13 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	ArrayBuffer::Contents contents14 = Local<TypedArray>::Cast(arg_4)->Buffer()->GetContents();
	ArrayBuffer::Contents contents15 = Local<TypedArray>::Cast(arg_5)->Buffer()->GetContents();
	String::Utf8Value _utf16(isolate, arg_6);
	glGetActiveAttrib(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLsizei*) contents13.Data(), (GLint*) contents14.Data(), (GLenum*) contents15.Data(), *_utf16);
	THROW_ON_GL_ERROR(isolate)
}

static void glGetActiveUniform_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsTypedArray() && arg_4->IsTypedArray() && arg_5->IsTypedArray() && arg_6->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents17 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	ArrayBuffer::Contents contents18 = Local<TypedArray>::Cast(arg_4)->Buffer()->GetContents();
	ArrayBuffer::Contents contents19 = Local<TypedArray>::Cast(arg_5)->Buffer()->GetContents();
	String::Utf8Value _utf20(isolate, arg_6);
	glGetActiveUniform(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLsizei*) contents17.Data(), (GLint*) contents18.Data(), (GLenum*) contents19.Data(), *_utf20);
	THROW_ON_GL_ERROR(isolate)
}

static void glGetAttachedShaders_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray() && arg_3->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents21 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	ArrayBuffer::Contents contents22 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glGetAttachedShaders(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLsizei*) contents21.Data(), (GLuint*) contents22.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetAttribLocation_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	String::Utf8Value _utf23(isolate, arg_1);
	args.GetReturnValue().Set(Integer::New(isolate, glGetAttribLocation(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), *_utf23)));
	THROW_ON_GL_ERROR(isolate)
}

static void glGetBooleanv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents24 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGetBooleanv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLboolean*) contents24.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetBufferParameteriv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents25 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetBufferParameteriv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents25.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetError_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	args.GetReturnValue().Set(Integer::New(isolate, glGetError()));
	THROW_ON_GL_ERROR(isolate)
}

static void glGetFloatv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents26 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGetFloatv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents26.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetFramebufferAttachmentParameteriv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents27 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glGetFramebufferAttachmentParameteriv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents27.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetIntegerv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents28 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glGetIntegerv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents28.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetProgramiv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents29 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetProgramiv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents29.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetProgramInfoLog_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray() && arg_3->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents30 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	String::Utf8Value _utf31(isolate, arg_3);
	glGetProgramInfoLog(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLsizei*) contents30.Data(), *_utf31);
	THROW_ON_GL_ERROR(isolate)
}

static void glGetRenderbufferParameteriv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents32 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetRenderbufferParameteriv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents32.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetShaderiv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents33 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetShaderiv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents33.Data());
	THROW_ON_GL_ERROR(isolate)
}

/**
 * This function is totally wrong.
 * It will make some games wrong to fix it.
 */
static void glGetShaderInfoLog_binder(const FunctionCallbackInfo<Value>& args) {
    Isolate *isolate = args.GetIsolate();
    Local<Value> arg_0 = args[0];
    Local<Value> arg_1 = args[1];
    Local<Value> arg_2 = args[2];
    Local<Value> arg_3 = args[3];
    if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray() && arg_3->IsString())) {
        ParameterCheckFailed(isolate)
        return;
    }
    ArrayBuffer::Contents contents34 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
    String::Utf8Value _utf35(isolate, arg_3);
    glGetShaderInfoLog(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLsizei *) contents34.Data(),
                       *_utf35);

    THROW_ON_GL_ERROR(isolate)
}

static void glGetShaderInfoLogValid_binder(const FunctionCallbackInfo<Value>& args) {
    Isolate *isolate = args.GetIsolate();
    Local<Value> arg_0 = args[0];

	char buff[256];
	GLint len;

	glGetShaderInfoLog(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), 256, &len, buff);
	buff[len]= 0;

	v8::Local<v8::String> ret = v8::String::NewFromUtf8(args.GetIsolate(), buff).ToLocalChecked();
	args.GetReturnValue().Set(ret);

    if (len>0) {
        // LOGV("SHADERINFOLOG: %s",buff);
    }

	THROW_ON_GL_ERROR(isolate)
}

static void glGetShaderSource_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray() && arg_3->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents38 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	String::Utf8Value _utf39(isolate, arg_3);
	glGetShaderSource(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLsizei*) contents38.Data(), *_utf39);
	THROW_ON_GL_ERROR(isolate)
}

static void glGetString_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32())) {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(
			String::NewFromUtf8(
					isolate,
					(const char *) glGetString(
							(unsigned)arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())).ToLocalChecked());
	THROW_ON_GL_ERROR(isolate)

}
static void glGetTexParameterfv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents40 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetTexParameterfv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents40.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetTexParameteriv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents41 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetTexParameteriv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents41.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetUniformfv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents42 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetUniformfv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents42.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetUniformiv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents43 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetUniformiv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents43.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetUniformLocation_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsString()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	String::Utf8Value _utf44(isolate, arg_1);
	args.GetReturnValue().Set(Integer::New(isolate, glGetUniformLocation(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), *_utf44)));
	THROW_ON_GL_ERROR(isolate)
}

static void glGetVertexAttribfv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents45 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetVertexAttribfv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents45.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetVertexAttribiv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents46 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glGetVertexAttribiv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents46.Data());
	THROW_ON_GL_ERROR(isolate)
}

//GL_APICALL void         GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, GLvoid** pointer);
static void glHint_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glHint(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glIsBuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsBuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glIsEnabled_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsEnabled(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glIsFramebuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsFramebuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glIsProgram_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsProgram(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glIsRenderbuffer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsRenderbuffer(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glIsShader_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsShader(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glIsTexture_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	args.GetReturnValue().Set(Boolean::New(isolate, glIsTexture(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust())));
	THROW_ON_GL_ERROR(isolate)
}

static void glLineWidth_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glLineWidth((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glLinkProgram_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glLinkProgram(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glPixelStorei_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glPixelStorei(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glPolygonOffset_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsNumber() && arg_1->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glPolygonOffset((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glReadPixels_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32() && arg_5->IsInt32() && arg_6->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents47 = Local<TypedArray>::Cast(arg_6)->Buffer()->GetContents();
	glReadPixels(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_5->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents47.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glRenderbufferStorage_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glRenderbufferStorage(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glSampleCoverage_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsNumber() && arg_1->IsBoolean()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glSampleCoverage((float) arg_0->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_1->BooleanValue(args.GetIsolate()));
	THROW_ON_GL_ERROR(isolate)
}

static void glScissor_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glScissor(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glShaderSource_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsString())) {
		ParameterCheckFailed(isolate)
		return;
	}
	String::Utf8Value String_1(isolate, arg_1);
	const char *string_1 = *String_1;
	glShaderSource(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), 1, &string_1, NULL);
	THROW_ON_GL_ERROR(isolate)

}
static void glStencilFunc_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glStencilFunc(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glStencilFuncSeparate_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glStencilFuncSeparate(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glStencilMask_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glStencilMask(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glStencilMaskSeparate_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glStencilMaskSeparate(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glStencilOp_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glStencilOp(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glStencilOpSeparate_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glStencilOpSeparate(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glTexImage2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	for (int c = 0; c < 8; ++c) {
		if (!args[c]->IsInt32()) {
		ParameterCheckFailed(isolate)
		return;
	}
	}
	glTexImage2D(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[3]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[4]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[5]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[6]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[7]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[8]->IsTypedArray() ? (GLvoid*) Local<TypedArray>::Cast(args[8])->Buffer()->GetContents().Data() : nullptr);
	THROW_ON_GL_ERROR(isolate)

}
static void glTexParameterf_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glTexParameterf(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glTexParameterfv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents50 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glTexParameterfv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents50.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glTexParameteri_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glTexParameteri(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glTexParameteriv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents51 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glTexParameteriv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents51.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glTexSubImage2D_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	Local<Value> arg_6 = args[6];
	Local<Value> arg_7 = args[7];
	Local<Value> arg_8 = args[8];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32() && arg_5->IsInt32() && arg_6->IsInt32() && arg_7->IsInt32() && arg_8->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents52 = Local<TypedArray>::Cast(arg_8)->Buffer()->GetContents();
	glTexSubImage2D(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_5->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_6->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_7->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents52.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform1f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform1f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform1fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents53 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform1fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents53.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform1i_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform1i(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform1iv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents54 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform1iv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents54.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform2f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsNumber() && arg_2->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform2f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform2fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents55 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform2fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents55.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform2i_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform2i(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform2iv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents56 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform2iv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents56.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform3f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsNumber() && arg_2->IsNumber() && arg_3->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform3f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_3->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform3fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents57 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform3fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents57.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform3i_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform3i(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform3iv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents58 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform3iv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents58.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform4f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	if (!(arg_0->IsInt32() && arg_1->IsNumber() && arg_2->IsNumber() && arg_3->IsNumber() && arg_4->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform4f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_3->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_4->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform4fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents59 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform4fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents59.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform4i_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32() && arg_4->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUniform4i(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniform4iv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents60 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
	glUniform4iv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents60.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniformMatrix2fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsBoolean() && arg_3->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents61 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glUniformMatrix2fv(
			arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_2->BooleanValue(args.GetIsolate()),
			(GLfloat*) contents61.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniformMatrix3fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsBoolean() && arg_3->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents62 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glUniformMatrix3fv(
			arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_2->BooleanValue(args.GetIsolate()),
			(GLfloat*) contents62.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUniformMatrix4fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsBoolean() && arg_3->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents63 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glUniformMatrix4fv(
			arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(),
			arg_2->BooleanValue(args.GetIsolate()),
			(GLfloat*) contents63.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glUseProgram_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glUseProgram(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glValidateProgram_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	if (!(arg_0->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glValidateProgram(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib1f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glVertexAttrib1f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib1fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents64 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glVertexAttrib1fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents64.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib2f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	if (!(arg_0->IsInt32() && arg_1->IsNumber() && arg_2->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glVertexAttrib2f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib2fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents65 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glVertexAttrib2fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents65.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib3f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsNumber() && arg_2->IsNumber() && arg_3->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glVertexAttrib3f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_3->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib3fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents66 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glVertexAttrib3fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents66.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib4f_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	if (!(arg_0->IsInt32() && arg_1->IsNumber() && arg_2->IsNumber() && arg_3->IsNumber() && arg_4->IsNumber()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glVertexAttrib4f(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_1->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_2->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_3->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust(), (float) arg_4->NumberValue(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttrib4fv_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents67 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	glVertexAttrib4fv(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLfloat*) contents67.Data());
	THROW_ON_GL_ERROR(isolate)
}

static void glVertexAttribPointer_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	Local<Value> arg_5 = args[5];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsBoolean() && arg_4->IsInt32() && arg_5->IsInt32())) {
		ParameterCheckFailed(isolate)
		return;
	}
	glVertexAttribPointer(args[0]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[1]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[2]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), args[3]->BooleanValue(args.GetIsolate()), args[4]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid *) (size_t) args[5]->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)

}
static void glViewport_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsInt32() && arg_3->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	glViewport(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_3->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void glGetShaderPrecisionFormat_binder(const FunctionCallbackInfo<Value>& args) {
    Isolate *isolate = args.GetIsolate();
    Local<Value> arg_0 = args[0];
    Local<Value> arg_1 = args[1];
    Local<Value> arg_2 = args[2];
    Local<Value> arg_3 = args[3];
    if (!(arg_0->IsInt32() && arg_1->IsInt32() && arg_2->IsTypedArray() && arg_3->IsTypedArray()))  {
        ParameterCheckFailed(isolate)
        return;
    }
    ArrayBuffer::Contents contents36 = Local<TypedArray>::Cast(arg_2)->Buffer()->GetContents();
    ArrayBuffer::Contents contents37 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
    glGetShaderPrecisionFormat(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), arg_1->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLint*) contents36.Data(), (GLint*) contents37.Data());
    THROW_ON_GL_ERROR(isolate)
}

static void glReleaseShaderCompiler_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	glReleaseShaderCompiler();
	THROW_ON_GL_ERROR(isolate)
}

static void glShaderBinary_binder(const FunctionCallbackInfo<Value>& args) {
	Isolate *isolate = args.GetIsolate();
	Local<Value> arg_0 = args[0];
	Local<Value> arg_1 = args[1];
	Local<Value> arg_2 = args[2];
	Local<Value> arg_3 = args[3];
	Local<Value> arg_4 = args[4];
	if (!(arg_0->IsInt32() && arg_1->IsTypedArray() && arg_2->IsInt32() && arg_3->IsTypedArray() && arg_4->IsInt32()))  {
		ParameterCheckFailed(isolate)
		return;
	}
	ArrayBuffer::Contents contents48 = Local<TypedArray>::Cast(arg_1)->Buffer()->GetContents();
	ArrayBuffer::Contents contents49 = Local<TypedArray>::Cast(arg_3)->Buffer()->GetContents();
	glShaderBinary(arg_0->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLuint*) contents48.Data(), arg_2->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust(), (GLvoid*) contents49.Data(), arg_4->Int32Value(args.GetIsolate()->GetCurrentContext()).FromJust());
	THROW_ON_GL_ERROR(isolate)
}

static void log_binder(const FunctionCallbackInfo<Value>& args) {
    Isolate *isolate = args.GetIsolate();
    Local<Value> arg_0 = args[0];
    if (!arg_0->IsString()) {
        ParameterCheckFailed(isolate)
        return;
    }

    v8::String::Utf8Value str(isolate, args[0]);
    std::string cppStr(*str);
    fprintf(stdout, "Log: %s\n", cppStr.c_str());
}

void bindPlato(Isolate *isolate, Local<ObjectTemplate> &plato) {
    plato->Set(isolate, "log", FunctionTemplate::New(isolate, log_binder));
}

void bindGL(Isolate *isolate, Local<ObjectTemplate> &gl) {
	gl->Set(isolate, "DEPTH_BUFFER_BIT", Integer::New(isolate, GL_DEPTH_BUFFER_BIT));
	gl->Set(isolate, "STENCIL_BUFFER_BIT", Integer::New(isolate, GL_STENCIL_BUFFER_BIT));
	gl->Set(isolate, "COLOR_BUFFER_BIT", Integer::New(isolate, GL_COLOR_BUFFER_BIT));
	gl->Set(isolate, "FALSE", Integer::New(isolate, GL_FALSE));
	gl->Set(isolate, "TRUE", Integer::New(isolate, GL_TRUE));
	gl->Set(isolate, "POINTS", Integer::New(isolate, GL_POINTS));
	gl->Set(isolate, "LINES", Integer::New(isolate, GL_LINES));
	gl->Set(isolate, "LINE_LOOP", Integer::New(isolate, GL_LINE_LOOP));
	gl->Set(isolate, "LINE_STRIP", Integer::New(isolate, GL_LINE_STRIP));
	gl->Set(isolate, "TRIANGLES", Integer::New(isolate, GL_TRIANGLES));
	gl->Set(isolate, "TRIANGLE_STRIP", Integer::New(isolate, GL_TRIANGLE_STRIP));
	gl->Set(isolate, "TRIANGLE_FAN", Integer::New(isolate, GL_TRIANGLE_FAN));
	gl->Set(isolate, "ZERO", Integer::New(isolate, GL_ZERO));
	gl->Set(isolate, "ONE", Integer::New(isolate, GL_ONE));
	gl->Set(isolate, "SRC_COLOR", Integer::New(isolate, GL_SRC_COLOR));
	gl->Set(isolate, "ONE_MINUS_SRC_COLOR", Integer::New(isolate, GL_ONE_MINUS_SRC_COLOR));
	gl->Set(isolate, "SRC_ALPHA", Integer::New(isolate, GL_SRC_ALPHA));
	gl->Set(isolate, "ONE_MINUS_SRC_ALPHA", Integer::New(isolate, GL_ONE_MINUS_SRC_ALPHA));
	gl->Set(isolate, "DST_ALPHA", Integer::New(isolate, GL_DST_ALPHA));
	gl->Set(isolate, "ONE_MINUS_DST_ALPHA", Integer::New(isolate, GL_ONE_MINUS_DST_ALPHA));
	gl->Set(isolate, "DST_COLOR", Integer::New(isolate, GL_DST_COLOR));
	gl->Set(isolate, "ONE_MINUS_DST_COLOR", Integer::New(isolate, GL_ONE_MINUS_DST_COLOR));
	gl->Set(isolate, "SRC_ALPHA_SATURATE", Integer::New(isolate, GL_SRC_ALPHA_SATURATE));
	gl->Set(isolate, "FUNC_ADD", Integer::New(isolate, GL_FUNC_ADD));
	gl->Set(isolate, "BLEND_EQUATION", Integer::New(isolate, GL_BLEND_EQUATION));
	gl->Set(isolate, "BLEND_EQUATION_RGB", Integer::New(isolate, GL_BLEND_EQUATION_RGB));
	gl->Set(isolate, "BLEND_EQUATION_ALPHA", Integer::New(isolate, GL_BLEND_EQUATION_ALPHA));
	gl->Set(isolate, "FUNC_SUBTRACT", Integer::New(isolate, GL_FUNC_SUBTRACT));
	gl->Set(isolate, "FUNC_REVERSE_SUBTRACT", Integer::New(isolate, GL_FUNC_REVERSE_SUBTRACT));
	gl->Set(isolate, "BLEND_DST_RGB", Integer::New(isolate, GL_BLEND_DST_RGB));
	gl->Set(isolate, "BLEND_SRC_RGB", Integer::New(isolate, GL_BLEND_SRC_RGB));
	gl->Set(isolate, "BLEND_DST_ALPHA", Integer::New(isolate, GL_BLEND_DST_ALPHA));
	gl->Set(isolate, "BLEND_SRC_ALPHA", Integer::New(isolate, GL_BLEND_SRC_ALPHA));
	gl->Set(isolate, "CONSTANT_COLOR", Integer::New(isolate, GL_CONSTANT_COLOR));
	gl->Set(isolate, "ONE_MINUS_CONSTANT_COLOR", Integer::New(isolate, GL_ONE_MINUS_CONSTANT_COLOR));
	gl->Set(isolate, "CONSTANT_ALPHA", Integer::New(isolate, GL_CONSTANT_ALPHA));
	gl->Set(isolate, "ONE_MINUS_CONSTANT_ALPHA", Integer::New(isolate, GL_ONE_MINUS_CONSTANT_ALPHA));
	gl->Set(isolate, "BLEND_COLOR", Integer::New(isolate, GL_BLEND_COLOR));
	gl->Set(isolate, "ARRAY_BUFFER", Integer::New(isolate, GL_ARRAY_BUFFER));
	gl->Set(isolate, "ELEMENT_ARRAY_BUFFER", Integer::New(isolate, GL_ELEMENT_ARRAY_BUFFER));
	gl->Set(isolate, "ARRAY_BUFFER_BINDING", Integer::New(isolate, GL_ARRAY_BUFFER_BINDING));
	gl->Set(isolate, "ELEMENT_ARRAY_BUFFER_BINDING", Integer::New(isolate, GL_ELEMENT_ARRAY_BUFFER_BINDING));
	gl->Set(isolate, "STREAM_DRAW", Integer::New(isolate, GL_STREAM_DRAW));
	gl->Set(isolate, "STATIC_DRAW", Integer::New(isolate, GL_STATIC_DRAW));
	gl->Set(isolate, "DYNAMIC_DRAW", Integer::New(isolate, GL_DYNAMIC_DRAW));
	gl->Set(isolate, "BUFFER_SIZE", Integer::New(isolate, GL_BUFFER_SIZE));
	gl->Set(isolate, "BUFFER_USAGE", Integer::New(isolate, GL_BUFFER_USAGE));
	gl->Set(isolate, "CURRENT_VERTEX_ATTRIB", Integer::New(isolate, GL_CURRENT_VERTEX_ATTRIB));
	gl->Set(isolate, "FRONT", Integer::New(isolate, GL_FRONT));
	gl->Set(isolate, "BACK", Integer::New(isolate, GL_BACK));
	gl->Set(isolate, "FRONT_AND_BACK", Integer::New(isolate, GL_FRONT_AND_BACK));
	gl->Set(isolate, "TEXTURE_2D", Integer::New(isolate, GL_TEXTURE_2D));
	gl->Set(isolate, "CULL_FACE", Integer::New(isolate, GL_CULL_FACE));
	gl->Set(isolate, "BLEND", Integer::New(isolate, GL_BLEND));
	gl->Set(isolate, "DITHER", Integer::New(isolate, GL_DITHER));
	gl->Set(isolate, "STENCIL_TEST", Integer::New(isolate, GL_STENCIL_TEST));
	gl->Set(isolate, "DEPTH_TEST", Integer::New(isolate, GL_DEPTH_TEST));
	gl->Set(isolate, "SCISSOR_TEST", Integer::New(isolate, GL_SCISSOR_TEST));
	gl->Set(isolate, "POLYGON_OFFSET_FILL", Integer::New(isolate, GL_POLYGON_OFFSET_FILL));
	gl->Set(isolate, "SAMPLE_ALPHA_TO_COVERAGE", Integer::New(isolate, GL_SAMPLE_ALPHA_TO_COVERAGE));
	gl->Set(isolate, "SAMPLE_COVERAGE", Integer::New(isolate, GL_SAMPLE_COVERAGE));
	gl->Set(isolate, "NO_ERROR", Integer::New(isolate, GL_NO_ERROR));
	gl->Set(isolate, "INVALID_ENUM", Integer::New(isolate, GL_INVALID_ENUM));
	gl->Set(isolate, "INVALID_VALUE", Integer::New(isolate, GL_INVALID_VALUE));
	gl->Set(isolate, "INVALID_OPERATION", Integer::New(isolate, GL_INVALID_OPERATION));
	gl->Set(isolate, "OUT_OF_MEMORY", Integer::New(isolate, GL_OUT_OF_MEMORY));
	gl->Set(isolate, "CW", Integer::New(isolate, GL_CW));
	gl->Set(isolate, "CCW", Integer::New(isolate, GL_CCW));
	gl->Set(isolate, "LINE_WIDTH", Integer::New(isolate, GL_LINE_WIDTH));
	gl->Set(isolate, "ALIASED_POINT_SIZE_RANGE", Integer::New(isolate, GL_ALIASED_POINT_SIZE_RANGE));
	gl->Set(isolate, "ALIASED_LINE_WIDTH_RANGE", Integer::New(isolate, GL_ALIASED_LINE_WIDTH_RANGE));
	gl->Set(isolate, "CULL_FACE_MODE", Integer::New(isolate, GL_CULL_FACE_MODE));
	gl->Set(isolate, "FRONT_FACE", Integer::New(isolate, GL_FRONT_FACE));
	gl->Set(isolate, "DEPTH_RANGE", Integer::New(isolate, GL_DEPTH_RANGE));
	gl->Set(isolate, "DEPTH_WRITEMASK", Integer::New(isolate, GL_DEPTH_WRITEMASK));
	gl->Set(isolate, "DEPTH_CLEAR_VALUE", Integer::New(isolate, GL_DEPTH_CLEAR_VALUE));
	gl->Set(isolate, "DEPTH_FUNC", Integer::New(isolate, GL_DEPTH_FUNC));
	gl->Set(isolate, "STENCIL_CLEAR_VALUE", Integer::New(isolate, GL_STENCIL_CLEAR_VALUE));
	gl->Set(isolate, "STENCIL_FUNC", Integer::New(isolate, GL_STENCIL_FUNC));
	gl->Set(isolate, "STENCIL_FAIL", Integer::New(isolate, GL_STENCIL_FAIL));
	gl->Set(isolate, "STENCIL_PASS_DEPTH_FAIL", Integer::New(isolate, GL_STENCIL_PASS_DEPTH_FAIL));
	gl->Set(isolate, "STENCIL_PASS_DEPTH_PASS", Integer::New(isolate, GL_STENCIL_PASS_DEPTH_PASS));
	gl->Set(isolate, "STENCIL_REF", Integer::New(isolate, GL_STENCIL_REF));
	gl->Set(isolate, "STENCIL_VALUE_MASK", Integer::New(isolate, GL_STENCIL_VALUE_MASK));
	gl->Set(isolate, "STENCIL_WRITEMASK", Integer::New(isolate, GL_STENCIL_WRITEMASK));
	gl->Set(isolate, "STENCIL_BACK_FUNC", Integer::New(isolate, GL_STENCIL_BACK_FUNC));
	gl->Set(isolate, "STENCIL_BACK_FAIL", Integer::New(isolate, GL_STENCIL_BACK_FAIL));
	gl->Set(isolate, "STENCIL_BACK_PASS_DEPTH_FAIL", Integer::New(isolate, GL_STENCIL_BACK_PASS_DEPTH_FAIL));
	gl->Set(isolate, "STENCIL_BACK_PASS_DEPTH_PASS", Integer::New(isolate, GL_STENCIL_BACK_PASS_DEPTH_PASS));
	gl->Set(isolate, "STENCIL_BACK_REF", Integer::New(isolate, GL_STENCIL_BACK_REF));
	gl->Set(isolate, "STENCIL_BACK_VALUE_MASK", Integer::New(isolate, GL_STENCIL_BACK_VALUE_MASK));
	gl->Set(isolate, "STENCIL_BACK_WRITEMASK", Integer::New(isolate, GL_STENCIL_BACK_WRITEMASK));
	gl->Set(isolate, "VIEWPORT", Integer::New(isolate, GL_VIEWPORT));
	gl->Set(isolate, "SCISSOR_BOX", Integer::New(isolate, GL_SCISSOR_BOX));
	gl->Set(isolate, "COLOR_CLEAR_VALUE", Integer::New(isolate, GL_COLOR_CLEAR_VALUE));
	gl->Set(isolate, "COLOR_WRITEMASK", Integer::New(isolate, GL_COLOR_WRITEMASK));
	gl->Set(isolate, "UNPACK_ALIGNMENT", Integer::New(isolate, GL_UNPACK_ALIGNMENT));
	gl->Set(isolate, "PACK_ALIGNMENT", Integer::New(isolate, GL_PACK_ALIGNMENT));
	gl->Set(isolate, "MAX_TEXTURE_SIZE", Integer::New(isolate, GL_MAX_TEXTURE_SIZE));
	gl->Set(isolate, "MAX_VIEWPORT_DIMS", Integer::New(isolate, GL_MAX_VIEWPORT_DIMS));
	gl->Set(isolate, "SUBPIXEL_BITS", Integer::New(isolate, GL_SUBPIXEL_BITS));
	gl->Set(isolate, "RED_BITS", Integer::New(isolate, GL_RED_BITS));
	gl->Set(isolate, "GREEN_BITS", Integer::New(isolate, GL_GREEN_BITS));
	gl->Set(isolate, "BLUE_BITS", Integer::New(isolate, GL_BLUE_BITS));
	gl->Set(isolate, "ALPHA_BITS", Integer::New(isolate, GL_ALPHA_BITS));
	gl->Set(isolate, "DEPTH_BITS", Integer::New(isolate, GL_DEPTH_BITS));
	gl->Set(isolate, "STENCIL_BITS", Integer::New(isolate, GL_STENCIL_BITS));
	gl->Set(isolate, "POLYGON_OFFSET_UNITS", Integer::New(isolate, GL_POLYGON_OFFSET_UNITS));
	gl->Set(isolate, "POLYGON_OFFSET_FACTOR", Integer::New(isolate, GL_POLYGON_OFFSET_FACTOR));
	gl->Set(isolate, "TEXTURE_BINDING_2D", Integer::New(isolate, GL_TEXTURE_BINDING_2D));
	gl->Set(isolate, "SAMPLE_BUFFERS", Integer::New(isolate, GL_SAMPLE_BUFFERS));
	gl->Set(isolate, "SAMPLES", Integer::New(isolate, GL_SAMPLES));
	gl->Set(isolate, "SAMPLE_COVERAGE_VALUE", Integer::New(isolate, GL_SAMPLE_COVERAGE_VALUE));
	gl->Set(isolate, "SAMPLE_COVERAGE_INVERT", Integer::New(isolate, GL_SAMPLE_COVERAGE_INVERT));
	gl->Set(isolate, "NUM_COMPRESSED_TEXTURE_FORMATS", Integer::New(isolate, GL_NUM_COMPRESSED_TEXTURE_FORMATS));
	gl->Set(isolate, "COMPRESSED_TEXTURE_FORMATS", Integer::New(isolate, GL_COMPRESSED_TEXTURE_FORMATS));
	gl->Set(isolate, "DONT_CARE", Integer::New(isolate, GL_DONT_CARE));
	gl->Set(isolate, "FASTEST", Integer::New(isolate, GL_FASTEST));
	gl->Set(isolate, "NICEST", Integer::New(isolate, GL_NICEST));
	gl->Set(isolate, "GENERATE_MIPMAP_HINT", Integer::New(isolate, GL_GENERATE_MIPMAP_HINT));
	gl->Set(isolate, "BYTE", Integer::New(isolate, GL_BYTE));
	gl->Set(isolate, "UNSIGNED_BYTE", Integer::New(isolate, GL_UNSIGNED_BYTE));
	gl->Set(isolate, "SHORT", Integer::New(isolate, GL_SHORT));
	gl->Set(isolate, "UNSIGNED_SHORT", Integer::New(isolate, GL_UNSIGNED_SHORT));
	gl->Set(isolate, "INT", Integer::New(isolate, GL_INT));
	gl->Set(isolate, "UNSIGNED_INT", Integer::New(isolate, GL_UNSIGNED_INT));
	gl->Set(isolate, "FLOAT", Integer::New(isolate, GL_FLOAT));
	gl->Set(isolate, "DEPTH_COMPONENT", Integer::New(isolate, GL_DEPTH_COMPONENT));
	gl->Set(isolate, "ALPHA", Integer::New(isolate, GL_ALPHA));
	gl->Set(isolate, "RGB", Integer::New(isolate, GL_RGB));
	gl->Set(isolate, "RGBA", Integer::New(isolate, GL_RGBA));
	gl->Set(isolate, "LUMINANCE", Integer::New(isolate, GL_LUMINANCE));
	gl->Set(isolate, "LUMINANCE_ALPHA", Integer::New(isolate, GL_LUMINANCE_ALPHA));
	gl->Set(isolate, "UNSIGNED_SHORT_4_4_4_4", Integer::New(isolate, GL_UNSIGNED_SHORT_4_4_4_4));
	gl->Set(isolate, "UNSIGNED_SHORT_5_5_5_1", Integer::New(isolate, GL_UNSIGNED_SHORT_5_5_5_1));
	gl->Set(isolate, "UNSIGNED_SHORT_5_6_5", Integer::New(isolate, GL_UNSIGNED_SHORT_5_6_5));
	gl->Set(isolate, "FRAGMENT_SHADER", Integer::New(isolate, GL_FRAGMENT_SHADER));
	gl->Set(isolate, "VERTEX_SHADER", Integer::New(isolate, GL_VERTEX_SHADER));
	gl->Set(isolate, "MAX_VERTEX_ATTRIBS", Integer::New(isolate, GL_MAX_VERTEX_ATTRIBS));
	gl->Set(isolate, "MAX_COMBINED_TEXTURE_IMAGE_UNITS", Integer::New(isolate, GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS));
	gl->Set(isolate, "MAX_VERTEX_TEXTURE_IMAGE_UNITS", Integer::New(isolate, GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS));
	gl->Set(isolate, "MAX_TEXTURE_IMAGE_UNITS", Integer::New(isolate, GL_MAX_TEXTURE_IMAGE_UNITS));
	gl->Set(isolate, "SHADER_TYPE", Integer::New(isolate, GL_SHADER_TYPE));
	gl->Set(isolate, "DELETE_STATUS", Integer::New(isolate, GL_DELETE_STATUS));
	gl->Set(isolate, "LINK_STATUS", Integer::New(isolate, GL_LINK_STATUS));
	gl->Set(isolate, "VALIDATE_STATUS", Integer::New(isolate, GL_VALIDATE_STATUS));
	gl->Set(isolate, "ATTACHED_SHADERS", Integer::New(isolate, GL_ATTACHED_SHADERS));
	gl->Set(isolate, "ACTIVE_UNIFORMS", Integer::New(isolate, GL_ACTIVE_UNIFORMS));
	gl->Set(isolate, "ACTIVE_UNIFORM_MAX_LENGTH", Integer::New(isolate, GL_ACTIVE_UNIFORM_MAX_LENGTH));
	gl->Set(isolate, "ACTIVE_ATTRIBUTES", Integer::New(isolate, GL_ACTIVE_ATTRIBUTES));
	gl->Set(isolate, "ACTIVE_ATTRIBUTE_MAX_LENGTH", Integer::New(isolate, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH));
	gl->Set(isolate, "SHADING_LANGUAGE_VERSION", Integer::New(isolate, GL_SHADING_LANGUAGE_VERSION));
	gl->Set(isolate, "CURRENT_PROGRAM", Integer::New(isolate, GL_CURRENT_PROGRAM));
	gl->Set(isolate, "NEVER", Integer::New(isolate, GL_NEVER));
	gl->Set(isolate, "LESS", Integer::New(isolate, GL_LESS));
	gl->Set(isolate, "EQUAL", Integer::New(isolate, GL_EQUAL));
	gl->Set(isolate, "LEQUAL", Integer::New(isolate, GL_LEQUAL));
	gl->Set(isolate, "GREATER", Integer::New(isolate, GL_GREATER));
	gl->Set(isolate, "NOTEQUAL", Integer::New(isolate, GL_NOTEQUAL));
	gl->Set(isolate, "GEQUAL", Integer::New(isolate, GL_GEQUAL));
	gl->Set(isolate, "ALWAYS", Integer::New(isolate, GL_ALWAYS));
	gl->Set(isolate, "KEEP", Integer::New(isolate, GL_KEEP));
	gl->Set(isolate, "REPLACE", Integer::New(isolate, GL_REPLACE));
	gl->Set(isolate, "INCR", Integer::New(isolate, GL_INCR));
	gl->Set(isolate, "DECR", Integer::New(isolate, GL_DECR));
	gl->Set(isolate, "INVERT", Integer::New(isolate, GL_INVERT));
	gl->Set(isolate, "INCR_WRAP", Integer::New(isolate, GL_INCR_WRAP));
	gl->Set(isolate, "DECR_WRAP", Integer::New(isolate, GL_DECR_WRAP));
	gl->Set(isolate, "VENDOR", Integer::New(isolate, GL_VENDOR));
	gl->Set(isolate, "RENDERER", Integer::New(isolate, GL_RENDERER));
	gl->Set(isolate, "VERSION", Integer::New(isolate, GL_VERSION));
	gl->Set(isolate, "EXTENSIONS", Integer::New(isolate, GL_EXTENSIONS));
	gl->Set(isolate, "NEAREST", Integer::New(isolate, GL_NEAREST));
	gl->Set(isolate, "LINEAR", Integer::New(isolate, GL_LINEAR));
	gl->Set(isolate, "NEAREST_MIPMAP_NEAREST", Integer::New(isolate, GL_NEAREST_MIPMAP_NEAREST));
	gl->Set(isolate, "LINEAR_MIPMAP_NEAREST", Integer::New(isolate, GL_LINEAR_MIPMAP_NEAREST));
	gl->Set(isolate, "NEAREST_MIPMAP_LINEAR", Integer::New(isolate, GL_NEAREST_MIPMAP_LINEAR));
	gl->Set(isolate, "LINEAR_MIPMAP_LINEAR", Integer::New(isolate, GL_LINEAR_MIPMAP_LINEAR));
	gl->Set(isolate, "TEXTURE_MAG_FILTER", Integer::New(isolate, GL_TEXTURE_MAG_FILTER));
	gl->Set(isolate, "TEXTURE_MIN_FILTER", Integer::New(isolate, GL_TEXTURE_MIN_FILTER));
	gl->Set(isolate, "TEXTURE_WRAP_S", Integer::New(isolate, GL_TEXTURE_WRAP_S));
	gl->Set(isolate, "TEXTURE_WRAP_T", Integer::New(isolate, GL_TEXTURE_WRAP_T));
	gl->Set(isolate, "TEXTURE", Integer::New(isolate, GL_TEXTURE));
	gl->Set(isolate, "TEXTURE_CUBE_MAP", Integer::New(isolate, GL_TEXTURE_CUBE_MAP));
	gl->Set(isolate, "TEXTURE_BINDING_CUBE_MAP", Integer::New(isolate, GL_TEXTURE_BINDING_CUBE_MAP));
	gl->Set(isolate, "TEXTURE_CUBE_MAP_POSITIVE_X", Integer::New(isolate, GL_TEXTURE_CUBE_MAP_POSITIVE_X));
	gl->Set(isolate, "TEXTURE_CUBE_MAP_NEGATIVE_X", Integer::New(isolate, GL_TEXTURE_CUBE_MAP_NEGATIVE_X));
	gl->Set(isolate, "TEXTURE_CUBE_MAP_POSITIVE_Y", Integer::New(isolate, GL_TEXTURE_CUBE_MAP_POSITIVE_Y));
	gl->Set(isolate, "TEXTURE_CUBE_MAP_NEGATIVE_Y", Integer::New(isolate, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y));
	gl->Set(isolate, "TEXTURE_CUBE_MAP_POSITIVE_Z", Integer::New(isolate, GL_TEXTURE_CUBE_MAP_POSITIVE_Z));
	gl->Set(isolate, "TEXTURE_CUBE_MAP_NEGATIVE_Z", Integer::New(isolate, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z));
	gl->Set(isolate, "MAX_CUBE_MAP_TEXTURE_SIZE", Integer::New(isolate, GL_MAX_CUBE_MAP_TEXTURE_SIZE));
	gl->Set(isolate, "TEXTURE0", Integer::New(isolate, GL_TEXTURE0));
	gl->Set(isolate, "TEXTURE1", Integer::New(isolate, GL_TEXTURE1));
	gl->Set(isolate, "TEXTURE2", Integer::New(isolate, GL_TEXTURE2));
	gl->Set(isolate, "TEXTURE3", Integer::New(isolate, GL_TEXTURE3));
	gl->Set(isolate, "TEXTURE4", Integer::New(isolate, GL_TEXTURE4));
	gl->Set(isolate, "TEXTURE5", Integer::New(isolate, GL_TEXTURE5));
	gl->Set(isolate, "TEXTURE6", Integer::New(isolate, GL_TEXTURE6));
	gl->Set(isolate, "TEXTURE7", Integer::New(isolate, GL_TEXTURE7));
	gl->Set(isolate, "TEXTURE8", Integer::New(isolate, GL_TEXTURE8));
	gl->Set(isolate, "TEXTURE9", Integer::New(isolate, GL_TEXTURE9));
	gl->Set(isolate, "TEXTURE10", Integer::New(isolate, GL_TEXTURE10));
	gl->Set(isolate, "TEXTURE11", Integer::New(isolate, GL_TEXTURE11));
	gl->Set(isolate, "TEXTURE12", Integer::New(isolate, GL_TEXTURE12));
	gl->Set(isolate, "TEXTURE13", Integer::New(isolate, GL_TEXTURE13));
	gl->Set(isolate, "TEXTURE14", Integer::New(isolate, GL_TEXTURE14));
	gl->Set(isolate, "TEXTURE15", Integer::New(isolate, GL_TEXTURE15));
	gl->Set(isolate, "TEXTURE16", Integer::New(isolate, GL_TEXTURE16));
	gl->Set(isolate, "TEXTURE17", Integer::New(isolate, GL_TEXTURE17));
	gl->Set(isolate, "TEXTURE18", Integer::New(isolate, GL_TEXTURE18));
	gl->Set(isolate, "TEXTURE19", Integer::New(isolate, GL_TEXTURE19));
	gl->Set(isolate, "TEXTURE20", Integer::New(isolate, GL_TEXTURE20));
	gl->Set(isolate, "TEXTURE21", Integer::New(isolate, GL_TEXTURE21));
	gl->Set(isolate, "TEXTURE22", Integer::New(isolate, GL_TEXTURE22));
	gl->Set(isolate, "TEXTURE23", Integer::New(isolate, GL_TEXTURE23));
	gl->Set(isolate, "TEXTURE24", Integer::New(isolate, GL_TEXTURE24));
	gl->Set(isolate, "TEXTURE25", Integer::New(isolate, GL_TEXTURE25));
	gl->Set(isolate, "TEXTURE26", Integer::New(isolate, GL_TEXTURE26));
	gl->Set(isolate, "TEXTURE27", Integer::New(isolate, GL_TEXTURE27));
	gl->Set(isolate, "TEXTURE28", Integer::New(isolate, GL_TEXTURE28));
	gl->Set(isolate, "TEXTURE29", Integer::New(isolate, GL_TEXTURE29));
	gl->Set(isolate, "TEXTURE30", Integer::New(isolate, GL_TEXTURE30));
	gl->Set(isolate, "TEXTURE31", Integer::New(isolate, GL_TEXTURE31));
	gl->Set(isolate, "ACTIVE_TEXTURE", Integer::New(isolate, GL_ACTIVE_TEXTURE));
	gl->Set(isolate, "REPEAT", Integer::New(isolate, GL_REPEAT));
	gl->Set(isolate, "CLAMP_TO_EDGE", Integer::New(isolate, GL_CLAMP_TO_EDGE));
	gl->Set(isolate, "MIRRORED_REPEAT", Integer::New(isolate, GL_MIRRORED_REPEAT));
	gl->Set(isolate, "FLOAT_VEC2", Integer::New(isolate, GL_FLOAT_VEC2));
	gl->Set(isolate, "FLOAT_VEC3", Integer::New(isolate, GL_FLOAT_VEC3));
	gl->Set(isolate, "FLOAT_VEC4", Integer::New(isolate, GL_FLOAT_VEC4));
	gl->Set(isolate, "INT_VEC2", Integer::New(isolate, GL_INT_VEC2));
	gl->Set(isolate, "INT_VEC3", Integer::New(isolate, GL_INT_VEC3));
	gl->Set(isolate, "INT_VEC4", Integer::New(isolate, GL_INT_VEC4));
	gl->Set(isolate, "BOOL", Integer::New(isolate, GL_BOOL));
	gl->Set(isolate, "BOOL_VEC2", Integer::New(isolate, GL_BOOL_VEC2));
	gl->Set(isolate, "BOOL_VEC3", Integer::New(isolate, GL_BOOL_VEC3));
	gl->Set(isolate, "BOOL_VEC4", Integer::New(isolate, GL_BOOL_VEC4));
	gl->Set(isolate, "FLOAT_MAT2", Integer::New(isolate, GL_FLOAT_MAT2));
	gl->Set(isolate, "FLOAT_MAT3", Integer::New(isolate, GL_FLOAT_MAT3));
	gl->Set(isolate, "FLOAT_MAT4", Integer::New(isolate, GL_FLOAT_MAT4));
	gl->Set(isolate, "SAMPLER_2D", Integer::New(isolate, GL_SAMPLER_2D));
	gl->Set(isolate, "SAMPLER_CUBE", Integer::New(isolate, GL_SAMPLER_CUBE));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_ENABLED", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_ENABLED));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_SIZE", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_SIZE));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_STRIDE", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_STRIDE));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_TYPE", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_TYPE));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_NORMALIZED", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_NORMALIZED));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_POINTER", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_POINTER));
	gl->Set(isolate, "VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", Integer::New(isolate, GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING));
	gl->Set(isolate, "COMPILE_STATUS", Integer::New(isolate, GL_COMPILE_STATUS));
	gl->Set(isolate, "INFO_LOG_LENGTH", Integer::New(isolate, GL_INFO_LOG_LENGTH));
	gl->Set(isolate, "SHADER_SOURCE_LENGTH", Integer::New(isolate, GL_SHADER_SOURCE_LENGTH));
	gl->Set(isolate, "FRAMEBUFFER", Integer::New(isolate, GL_FRAMEBUFFER));
	gl->Set(isolate, "RENDERBUFFER", Integer::New(isolate, GL_RENDERBUFFER));
	gl->Set(isolate, "RGBA4", Integer::New(isolate, GL_RGBA4));
	gl->Set(isolate, "RGB5_A1", Integer::New(isolate, GL_RGB5_A1));
	gl->Set(isolate, "DEPTH_COMPONENT16", Integer::New(isolate, GL_DEPTH_COMPONENT16));
	gl->Set(isolate, "STENCIL_INDEX", Integer::New(isolate, GL_STENCIL_INDEX));
	gl->Set(isolate, "STENCIL_INDEX8", Integer::New(isolate, GL_STENCIL_INDEX8));
	gl->Set(isolate, "RENDERBUFFER_WIDTH", Integer::New(isolate, GL_RENDERBUFFER_WIDTH));
	gl->Set(isolate, "RENDERBUFFER_HEIGHT", Integer::New(isolate, GL_RENDERBUFFER_HEIGHT));
	gl->Set(isolate, "RENDERBUFFER_INTERNAL_FORMAT", Integer::New(isolate, GL_RENDERBUFFER_INTERNAL_FORMAT));
	gl->Set(isolate, "RENDERBUFFER_RED_SIZE", Integer::New(isolate, GL_RENDERBUFFER_RED_SIZE));
	gl->Set(isolate, "RENDERBUFFER_GREEN_SIZE", Integer::New(isolate, GL_RENDERBUFFER_GREEN_SIZE));
	gl->Set(isolate, "RENDERBUFFER_BLUE_SIZE", Integer::New(isolate, GL_RENDERBUFFER_BLUE_SIZE));
	gl->Set(isolate, "RENDERBUFFER_ALPHA_SIZE", Integer::New(isolate, GL_RENDERBUFFER_ALPHA_SIZE));
	gl->Set(isolate, "RENDERBUFFER_DEPTH_SIZE", Integer::New(isolate, GL_RENDERBUFFER_DEPTH_SIZE));
	gl->Set(isolate, "RENDERBUFFER_STENCIL_SIZE", Integer::New(isolate, GL_RENDERBUFFER_STENCIL_SIZE));
	gl->Set(isolate, "FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", Integer::New(isolate, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE));
	gl->Set(isolate, "FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", Integer::New(isolate, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME));
	gl->Set(isolate, "FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", Integer::New(isolate, GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL));
	gl->Set(isolate, "FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE", Integer::New(isolate, GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE));
	gl->Set(isolate, "COLOR_ATTACHMENT0", Integer::New(isolate, GL_COLOR_ATTACHMENT0));
	gl->Set(isolate, "DEPTH_ATTACHMENT", Integer::New(isolate, GL_DEPTH_ATTACHMENT));
	gl->Set(isolate, "STENCIL_ATTACHMENT", Integer::New(isolate, GL_STENCIL_ATTACHMENT));
	gl->Set(isolate, "NONE", Integer::New(isolate, GL_NONE));
	gl->Set(isolate, "FRAMEBUFFER_COMPLETE", Integer::New(isolate, GL_FRAMEBUFFER_COMPLETE));
	gl->Set(isolate, "FRAMEBUFFER_INCOMPLETE_ATTACHMENT", Integer::New(isolate, GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT));
	gl->Set(isolate, "FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", Integer::New(isolate, GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT));
	gl->Set(isolate, "FRAMEBUFFER_UNSUPPORTED", Integer::New(isolate, GL_FRAMEBUFFER_UNSUPPORTED));
	gl->Set(isolate, "FRAMEBUFFER_BINDING", Integer::New(isolate, GL_FRAMEBUFFER_BINDING));
	gl->Set(isolate, "RENDERBUFFER_BINDING", Integer::New(isolate, GL_RENDERBUFFER_BINDING));
	gl->Set(isolate, "MAX_RENDERBUFFER_SIZE", Integer::New(isolate, GL_MAX_RENDERBUFFER_SIZE));
	gl->Set(isolate, "INVALID_FRAMEBUFFER_OPERATION", Integer::New(isolate, GL_INVALID_FRAMEBUFFER_OPERATION));
	gl->Set(isolate, "shaderSource", FunctionTemplate::New(isolate, glShaderSource_binder));
	gl->Set(isolate, "cullFace", FunctionTemplate::New(isolate, glCullFace_binder));
	gl->Set(isolate, "getActiveUniform", FunctionTemplate::New(isolate, glGetActiveUniform_binder));
	gl->Set(isolate, "compileShader", FunctionTemplate::New(isolate, glCompileShader_binder));
	gl->Set(isolate, "renderbufferStorage", FunctionTemplate::New(isolate, glRenderbufferStorage_binder));
	gl->Set(isolate, "colorMask", FunctionTemplate::New(isolate, glColorMask_binder));
	gl->Set(isolate, "bindFramebuffer", FunctionTemplate::New(isolate, glBindFramebuffer_binder));
	gl->Set(isolate, "uniform1iv", FunctionTemplate::New(isolate, glUniform1iv_binder));
	gl->Set(isolate, "isRenderbuffer", FunctionTemplate::New(isolate, glIsRenderbuffer_binder));
	gl->Set(isolate, "depthRangef", FunctionTemplate::New(isolate, glDepthRangef_binder));
	gl->Set(isolate, "disable", FunctionTemplate::New(isolate, glDisable_binder));
	gl->Set(isolate, "vertexAttrib1fv", FunctionTemplate::New(isolate, glVertexAttrib1fv_binder));
	gl->Set(isolate, "getUniformiv", FunctionTemplate::New(isolate, glGetUniformiv_binder));
	gl->Set(isolate, "vertexAttrib4f", FunctionTemplate::New(isolate, glVertexAttrib4f_binder));
	gl->Set(isolate, "isShader", FunctionTemplate::New(isolate, glIsShader_binder));
	gl->Set(isolate, "lineWidth", FunctionTemplate::New(isolate, glLineWidth_binder));
	gl->Set(isolate, "bindAttribLocation", FunctionTemplate::New(isolate, glBindAttribLocation_binder));
	gl->Set(isolate, "stencilFuncSeparate", FunctionTemplate::New(isolate, glStencilFuncSeparate_binder));
	gl->Set(isolate, "bindTexture", FunctionTemplate::New(isolate, glBindTexture_binder));
	gl->Set(isolate, "bindRenderbuffer", FunctionTemplate::New(isolate, glBindRenderbuffer_binder));
	gl->Set(isolate, "pixelStorei", FunctionTemplate::New(isolate, glPixelStorei_binder));
	gl->Set(isolate, "getAttachedShaders", FunctionTemplate::New(isolate, glGetAttachedShaders_binder));
	gl->Set(isolate, "scissor", FunctionTemplate::New(isolate, glScissor_binder));
	gl->Set(isolate, "uniform4fv", FunctionTemplate::New(isolate, glUniform4fv_binder));
	gl->Set(isolate, "clearStencil", FunctionTemplate::New(isolate, glClearStencil_binder));
	gl->Set(isolate, "polygonOffset", FunctionTemplate::New(isolate, glPolygonOffset_binder));
	gl->Set(isolate, "getShaderInfoLog", FunctionTemplate::New(isolate, glGetShaderInfoLog_binder));
	gl->Set(isolate, "getShaderInfoLog2", FunctionTemplate::New(isolate, glGetShaderInfoLogValid_binder));
	gl->Set(isolate, "viewport", FunctionTemplate::New(isolate, glViewport_binder));
	gl->Set(isolate, "texParameterf", FunctionTemplate::New(isolate, glTexParameterf_binder));
	gl->Set(isolate, "texParameteriv", FunctionTemplate::New(isolate, glTexParameteriv_binder));
	gl->Set(isolate, "vertexAttribPointer", FunctionTemplate::New(isolate, glVertexAttribPointer_binder));
	gl->Set(isolate, "stencilOp", FunctionTemplate::New(isolate, glStencilOp_binder));
	gl->Set(isolate, "isBuffer", FunctionTemplate::New(isolate, glIsBuffer_binder));
	gl->Set(isolate, "texImage2D", FunctionTemplate::New(isolate, glTexImage2D_binder));
	gl->Set(isolate, "bindBuffer", FunctionTemplate::New(isolate, glBindBuffer_binder));
	gl->Set(isolate, "blendEquation", FunctionTemplate::New(isolate, glBlendEquation_binder));
	gl->Set(isolate, "generateMipmap", FunctionTemplate::New(isolate, glGenerateMipmap_binder));
	gl->Set(isolate, "depthFunc", FunctionTemplate::New(isolate, glDepthFunc_binder));
	gl->Set(isolate, "uniform4f", FunctionTemplate::New(isolate, glUniform4f_binder));
	gl->Set(isolate, "uniform4iv", FunctionTemplate::New(isolate, glUniform4iv_binder));
	gl->Set(isolate, "isTexture", FunctionTemplate::New(isolate, glIsTexture_binder));
	gl->Set(isolate, "uniform4i", FunctionTemplate::New(isolate, glUniform4i_binder));
	gl->Set(isolate, "clearColor", FunctionTemplate::New(isolate, glClearColor_binder));
	gl->Set(isolate, "blendColor", FunctionTemplate::New(isolate, glBlendColor_binder));
	gl->Set(isolate, "stencilFunc", FunctionTemplate::New(isolate, glStencilFunc_binder));
	gl->Set(isolate, "compressedTexSubImage2D", FunctionTemplate::New(isolate, glCompressedTexSubImage2D_binder));
	gl->Set(isolate, "vertexAttrib2fv", FunctionTemplate::New(isolate, glVertexAttrib2fv_binder));
	gl->Set(isolate, "copyTexSubImage2D", FunctionTemplate::New(isolate, glCopyTexSubImage2D_binder));
	gl->Set(isolate, "depthMask", FunctionTemplate::New(isolate, glDepthMask_binder));
	gl->Set(isolate, "validateProgram", FunctionTemplate::New(isolate, glValidateProgram_binder));
	gl->Set(isolate, "drawElements", FunctionTemplate::New(isolate, glDrawElements_binder));
	gl->Set(isolate, "deleteRenderbuffers", FunctionTemplate::New(isolate, glDeleteRenderbuffers_binder));
	gl->Set(isolate, "genBuffers", FunctionTemplate::New(isolate, glGenBuffers_binder));
	gl->Set(isolate, "uniform3fv", FunctionTemplate::New(isolate, glUniform3fv_binder));
	gl->Set(isolate, "getUniformLocation", FunctionTemplate::New(isolate, glGetUniformLocation_binder));
	gl->Set(isolate, "useProgram", FunctionTemplate::New(isolate, glUseProgram_binder));
	gl->Set(isolate, "getTexParameteriv", FunctionTemplate::New(isolate, glGetTexParameteriv_binder));
	gl->Set(isolate, "framebufferTexture2D", FunctionTemplate::New(isolate, glFramebufferTexture2D_binder));
	gl->Set(isolate, "uniformMatrix4fv", FunctionTemplate::New(isolate, glUniformMatrix4fv_binder));
	gl->Set(isolate, "getVertexAttribfv", FunctionTemplate::New(isolate, glGetVertexAttribfv_binder));
	gl->Set(isolate, "enable", FunctionTemplate::New(isolate, glEnable_binder));
	gl->Set(isolate, "getProgramiv", FunctionTemplate::New(isolate, glGetProgramiv_binder));
	gl->Set(isolate, "blendFunc", FunctionTemplate::New(isolate, glBlendFunc_binder));
	gl->Set(isolate, "getRenderbufferParameteriv", FunctionTemplate::New(isolate, glGetRenderbufferParameteriv_binder));
	gl->Set(isolate, "stencilMask", FunctionTemplate::New(isolate, glStencilMask_binder));
	gl->Set(isolate, "vertexAttrib3fv", FunctionTemplate::New(isolate, glVertexAttrib3fv_binder));
	gl->Set(isolate, "blendEquationSeparate", FunctionTemplate::New(isolate, glBlendEquationSeparate_binder));
	gl->Set(isolate, "blendFuncSeparate", FunctionTemplate::New(isolate, glBlendFuncSeparate_binder));
	gl->Set(isolate, "uniform3iv", FunctionTemplate::New(isolate, glUniform3iv_binder));
	gl->Set(isolate, "uniform2f", FunctionTemplate::New(isolate, glUniform2f_binder));
	gl->Set(isolate, "genTextures", FunctionTemplate::New(isolate, glGenTextures_binder));
	gl->Set(isolate, "uniform2i", FunctionTemplate::New(isolate, glUniform2i_binder));
	gl->Set(isolate, "bufferSubData", FunctionTemplate::New(isolate, glBufferSubData_binder));
	gl->Set(isolate, "vertexAttrib1f", FunctionTemplate::New(isolate, glVertexAttrib1f_binder));
	gl->Set(isolate, "bufferData", FunctionTemplate::New(isolate, glBufferData_binder));
	gl->Set(isolate, "detachShader", FunctionTemplate::New(isolate, glDetachShader_binder));
	gl->Set(isolate, "attachShader", FunctionTemplate::New(isolate, glAttachShader_binder));
	gl->Set(isolate, "getFloatv", FunctionTemplate::New(isolate, glGetFloatv_binder));
	gl->Set(isolate, "readPixels", FunctionTemplate::New(isolate, glReadPixels_binder));
	gl->Set(isolate, "getAttribLocation", FunctionTemplate::New(isolate, glGetAttribLocation_binder));
	gl->Set(isolate, "isEnabled", FunctionTemplate::New(isolate, glIsEnabled_binder));
	gl->Set(isolate, "copyTexImage2D", FunctionTemplate::New(isolate, glCopyTexImage2D_binder));
	gl->Set(isolate, "createShader", FunctionTemplate::New(isolate, glCreateShader_binder));
	gl->Set(isolate, "enableVertexAttribArray", FunctionTemplate::New(isolate, glEnableVertexAttribArray_binder));
	gl->Set(isolate, "deleteProgram", FunctionTemplate::New(isolate, glDeleteProgram_binder));
	gl->Set(isolate, "getBufferParameteriv", FunctionTemplate::New(isolate, glGetBufferParameteriv_binder));
	gl->Set(isolate, "genFramebuffers", FunctionTemplate::New(isolate, glGenFramebuffers_binder));
	gl->Set(isolate, "sampleCoverage", FunctionTemplate::New(isolate, glSampleCoverage_binder));
	gl->Set(isolate, "uniform3f", FunctionTemplate::New(isolate, glUniform3f_binder));
	gl->Set(isolate, "uniform2fv", FunctionTemplate::New(isolate, glUniform2fv_binder));
	gl->Set(isolate, "uniform3i", FunctionTemplate::New(isolate, glUniform3i_binder));
	gl->Set(isolate, "clearDepthf", FunctionTemplate::New(isolate, glClearDepthf_binder));
	gl->Set(isolate, "deleteTextures", FunctionTemplate::New(isolate, glDeleteTextures_binder));
	gl->Set(isolate, "getIntegerv", FunctionTemplate::New(isolate, glGetIntegerv_binder));
	gl->Set(isolate, "uniformMatrix3fv", FunctionTemplate::New(isolate, glUniformMatrix3fv_binder));
	gl->Set(isolate, "disableVertexAttribArray", FunctionTemplate::New(isolate, glDisableVertexAttribArray_binder));
	gl->Set(isolate, "getProgramInfoLog", FunctionTemplate::New(isolate, glGetProgramInfoLog_binder));
	gl->Set(isolate, "texSubImage2D", FunctionTemplate::New(isolate, glTexSubImage2D_binder));
	gl->Set(isolate, "clear", FunctionTemplate::New(isolate, glClear_binder));
	gl->Set(isolate, "deleteShader", FunctionTemplate::New(isolate, glDeleteShader_binder));
	gl->Set(isolate, "isFramebuffer", FunctionTemplate::New(isolate, glIsFramebuffer_binder));
	gl->Set(isolate, "vertexAttrib3f", FunctionTemplate::New(isolate, glVertexAttrib3f_binder));
	gl->Set(isolate, "vertexAttrib4fv", FunctionTemplate::New(isolate, glVertexAttrib4fv_binder));
	gl->Set(isolate, "getUniformfv", FunctionTemplate::New(isolate, glGetUniformfv_binder));
	gl->Set(isolate, "stencilMaskSeparate", FunctionTemplate::New(isolate, glStencilMaskSeparate_binder));
	gl->Set(isolate, "getFramebufferAttachmentParameteriv", FunctionTemplate::New(isolate, glGetFramebufferAttachmentParameteriv_binder));
	gl->Set(isolate, "texParameteri", FunctionTemplate::New(isolate, glTexParameteri_binder));
	gl->Set(isolate, "uniform2iv", FunctionTemplate::New(isolate, glUniform2iv_binder));
	gl->Set(isolate, "frontFace", FunctionTemplate::New(isolate, glFrontFace_binder));
	gl->Set(isolate, "drawArrays", FunctionTemplate::New(isolate, glDrawArrays_binder));
	gl->Set(isolate, "getShaderSource", FunctionTemplate::New(isolate, glGetShaderSource_binder));
	gl->Set(isolate, "getTexParameterfv", FunctionTemplate::New(isolate, glGetTexParameterfv_binder));
	gl->Set(isolate, "getVertexAttribiv", FunctionTemplate::New(isolate, glGetVertexAttribiv_binder));
	gl->Set(isolate, "stencilOpSeparate", FunctionTemplate::New(isolate, glStencilOpSeparate_binder));
	gl->Set(isolate, "hint", FunctionTemplate::New(isolate, glHint_binder));
	gl->Set(isolate, "texParameterfv", FunctionTemplate::New(isolate, glTexParameterfv_binder));
	gl->Set(isolate, "getBooleanv", FunctionTemplate::New(isolate, glGetBooleanv_binder));
	gl->Set(isolate, "vertexAttrib2f", FunctionTemplate::New(isolate, glVertexAttrib2f_binder));
	gl->Set(isolate, "flush", FunctionTemplate::New(isolate, glFlush_binder));
	gl->Set(isolate, "getActiveAttrib", FunctionTemplate::New(isolate, glGetActiveAttrib_binder));
	gl->Set(isolate, "isProgram", FunctionTemplate::New(isolate, glIsProgram_binder));
	gl->Set(isolate, "deleteFramebuffers", FunctionTemplate::New(isolate, glDeleteFramebuffers_binder));
	gl->Set(isolate, "uniform1fv", FunctionTemplate::New(isolate, glUniform1fv_binder));
	gl->Set(isolate, "checkFramebufferStatus", FunctionTemplate::New(isolate, glCheckFramebufferStatus_binder));
	gl->Set(isolate, "uniform1f", FunctionTemplate::New(isolate, glUniform1f_binder));
	gl->Set(isolate, "createProgram", FunctionTemplate::New(isolate, glCreateProgram_binder));
	gl->Set(isolate, "compressedTexImage2D", FunctionTemplate::New(isolate, glCompressedTexImage2D_binder));
	gl->Set(isolate, "uniform1i", FunctionTemplate::New(isolate, glUniform1i_binder));
	gl->Set(isolate, "finish", FunctionTemplate::New(isolate, glFinish_binder));
	gl->Set(isolate, "getShaderiv", FunctionTemplate::New(isolate, glGetShaderiv_binder));
	gl->Set(isolate, "uniformMatrix2fv", FunctionTemplate::New(isolate, glUniformMatrix2fv_binder));
	gl->Set(isolate, "framebufferRenderbuffer", FunctionTemplate::New(isolate, glFramebufferRenderbuffer_binder));
	gl->Set(isolate, "activeTexture", FunctionTemplate::New(isolate, glActiveTexture_binder));
	gl->Set(isolate, "deleteBuffers", FunctionTemplate::New(isolate, glDeleteBuffers_binder));
	gl->Set(isolate, "getString", FunctionTemplate::New(isolate, glGetString_binder));
	gl->Set(isolate, "linkProgram", FunctionTemplate::New(isolate, glLinkProgram_binder));
	gl->Set(isolate, "genRenderbuffers", FunctionTemplate::New(isolate, glGenRenderbuffers_binder));
	gl->Set(isolate, "getError", FunctionTemplate::New(isolate, glGetError_binder));

    gl->Set(isolate, "ES_VERSION_2_0", Integer::New(isolate, GL_ES_VERSION_2_0));
    gl->Set(isolate, "FIXED", Integer::New(isolate, GL_FIXED));
    gl->Set(isolate, "MAX_VERTEX_UNIFORM_VECTORS", Integer::New(isolate, GL_MAX_VERTEX_UNIFORM_VECTORS));
    gl->Set(isolate, "MAX_VARYING_VECTORS", Integer::New(isolate, GL_MAX_VARYING_VECTORS));
    gl->Set(isolate, "MAX_FRAGMENT_UNIFORM_VECTORS", Integer::New(isolate, GL_MAX_FRAGMENT_UNIFORM_VECTORS));
    gl->Set(isolate, "releaseShaderCompiler", FunctionTemplate::New(isolate, glReleaseShaderCompiler_binder));
    gl->Set(isolate, "getShaderPrecisionFormat", FunctionTemplate::New(isolate, glGetShaderPrecisionFormat_binder));
    gl->Set(isolate, "shaderBinary", FunctionTemplate::New(isolate, glShaderBinary_binder));
    gl->Set(isolate, "FRAMEBUFFER_INCOMPLETE_DIMENSIONS", Integer::New(isolate, GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS));
    gl->Set(isolate, "RGB565", Integer::New(isolate, GL_RGB565));
    gl->Set(isolate, "SHADER_COMPILER", Integer::New(isolate, GL_SHADER_COMPILER));
    gl->Set(isolate, "SHADER_BINARY_FORMATS", Integer::New(isolate, GL_SHADER_BINARY_FORMATS));
    gl->Set(isolate, "NUM_SHADER_BINARY_FORMATS", Integer::New(isolate, GL_NUM_SHADER_BINARY_FORMATS));
    gl->Set(isolate, "LOW_FLOAT", Integer::New(isolate, GL_LOW_FLOAT));
    gl->Set(isolate, "MEDIUM_FLOAT", Integer::New(isolate, GL_MEDIUM_FLOAT));
    gl->Set(isolate, "HIGH_FLOAT", Integer::New(isolate, GL_HIGH_FLOAT));
    gl->Set(isolate, "LOW_INT", Integer::New(isolate, GL_LOW_INT));
    gl->Set(isolate, "MEDIUM_INT", Integer::New(isolate, GL_MEDIUM_INT));
    gl->Set(isolate, "HIGH_INT", Integer::New(isolate, GL_HIGH_INT));
    gl->Set(isolate, "IMPLEMENTATION_COLOR_READ_TYPE", Integer::New(isolate, GL_IMPLEMENTATION_COLOR_READ_TYPE));
    gl->Set(isolate, "IMPLEMENTATION_COLOR_READ_FORMAT", Integer::New(isolate, GL_IMPLEMENTATION_COLOR_READ_FORMAT));
}
