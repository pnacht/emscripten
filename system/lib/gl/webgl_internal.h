/*
 * Copyright 2018 The Emscripten Authors.  All rights reserved.
 * Emscripten is available under two separate licenses, the MIT license and the
 * University of Illinois/NCSA Open Source License.  Both these licenses can be
 * found in the LICENSE file.
 */
#pragma once

EMSCRIPTEN_WEBGL_CONTEXT_HANDLE emscripten_webgl_do_get_current_context(void);
EMSCRIPTEN_WEBGL_CONTEXT_HANDLE emscripten_webgl_do_create_context(const char *target, const EmscriptenWebGLContextAttributes *attributes);
EMSCRIPTEN_RESULT emscripten_webgl_make_context_current_calling_thread(EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context);
EMSCRIPTEN_RESULT emscripten_webgl_do_commit_frame(void);
EM_BOOL emscripten_supports_offscreencanvas(void);
void _emscripten_proxied_gl_context_activated_from_main_browser_thread(EMSCRIPTEN_WEBGL_CONTEXT_HANDLE context);

#if defined(__EMSCRIPTEN_PTHREADS__) && defined(__EMSCRIPTEN_OFFSCREEN_FRAMEBUFFER__)

#ifdef EMSCRIPTEN_WEBGL_TRACE
#define GL_FUNCTION_TRACE(func) printf(#func "\n")
#else
#define GL_FUNCTION_TRACE(func) ((void)0)
#endif

#define ASYNC_GL_FUNCTION_0(sig, ret, functionName) ret functionName(void) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName); }
#define ASYNC_GL_FUNCTION_1(sig, ret, functionName, t0) ret functionName(t0 p0) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0); }
#define ASYNC_GL_FUNCTION_2(sig, ret, functionName, t0, t1) ret functionName(t0 p0, t1 p1) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1); }
#define ASYNC_GL_FUNCTION_3(sig, ret, functionName, t0, t1, t2) ret functionName(t0 p0, t1 p1, t2 p2) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2); }
#define ASYNC_GL_FUNCTION_4(sig, ret, functionName, t0, t1, t2, t3) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3); }
#define ASYNC_GL_FUNCTION_5(sig, ret, functionName, t0, t1, t2, t3, t4) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4); }
#define ASYNC_GL_FUNCTION_6(sig, ret, functionName, t0, t1, t2, t3, t4, t5) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5); }
#define ASYNC_GL_FUNCTION_7(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6); }
#define ASYNC_GL_FUNCTION_8(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7); }
#define ASYNC_GL_FUNCTION_9(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8); }
#define ASYNC_GL_FUNCTION_10(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
#define ASYNC_GL_FUNCTION_11(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9, t10 p10) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); else emscripten_async_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }

#define RET_SYNC_GL_FUNCTION_0(sig, ret, functionName) ret functionName(void) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName); }
#define RET_SYNC_GL_FUNCTION_1(sig, ret, functionName, t0) ret functionName(t0 p0) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0); }
#define RET_SYNC_GL_FUNCTION_2(sig, ret, functionName, t0, t1) ret functionName(t0 p0, t1 p1) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1); }
#define RET_SYNC_GL_FUNCTION_3(sig, ret, functionName, t0, t1, t2) ret functionName(t0 p0, t1 p1, t2 p2) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2); }
#define RET_SYNC_GL_FUNCTION_4(sig, ret, functionName, t0, t1, t2, t3) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3); }
#define RET_SYNC_GL_FUNCTION_5(sig, ret, functionName, t0, t1, t2, t3, t4) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4); }
#define RET_SYNC_GL_FUNCTION_6(sig, ret, functionName, t0, t1, t2, t3, t4, t5) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4, p5); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5); }
#define RET_SYNC_GL_FUNCTION_7(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6); }
#define RET_SYNC_GL_FUNCTION_8(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7); }
#define RET_SYNC_GL_FUNCTION_9(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8); }
#define RET_SYNC_GL_FUNCTION_10(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
#define RET_SYNC_GL_FUNCTION_11(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9, t10 p10) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) return emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); else return (ret)emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }

#define VOID_SYNC_GL_FUNCTION_0(sig, ret, functionName) ret functionName(void) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName); }
#define VOID_SYNC_GL_FUNCTION_1(sig, ret, functionName, t0) ret functionName(t0 p0) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0); }
#define VOID_SYNC_GL_FUNCTION_2(sig, ret, functionName, t0, t1) ret functionName(t0 p0, t1 p1) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1); }
#define VOID_SYNC_GL_FUNCTION_3(sig, ret, functionName, t0, t1, t2) ret functionName(t0 p0, t1 p1, t2 p2) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2); }
#define VOID_SYNC_GL_FUNCTION_4(sig, ret, functionName, t0, t1, t2, t3) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3); }
#define VOID_SYNC_GL_FUNCTION_5(sig, ret, functionName, t0, t1, t2, t3, t4) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4); }
#define VOID_SYNC_GL_FUNCTION_6(sig, ret, functionName, t0, t1, t2, t3, t4, t5) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5); }
#define VOID_SYNC_GL_FUNCTION_7(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6); }
#define VOID_SYNC_GL_FUNCTION_8(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7); }
#define VOID_SYNC_GL_FUNCTION_9(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8); }
#define VOID_SYNC_GL_FUNCTION_10(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9); }
#define VOID_SYNC_GL_FUNCTION_11(sig, ret, functionName, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) ret functionName(t0 p0, t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9, t10 p10) { GL_FUNCTION_TRACE(); if (pthread_getspecific(currentThreadOwnsItsWebGLContext)) emscripten_##functionName(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); else emscripten_sync_run_in_main_runtime_thread(sig, &emscripten_##functionName, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10); }

#include <pthread.h>

extern pthread_key_t currentThreadOwnsItsWebGLContext;

// When building with multithreading, return pointers to C functions that can perform proxying.
#define RETURN_FN(functionName) if (!strcmp(name, #functionName)) return functionName;
#define RETURN_FN_WITH_SUFFIX(functionName, suffix) if (!strcmp(name, #functionName)) return functionName##suffix;

#else

// When building with singlethreading, return pointers to JS library layer so that C code (Regal library)
// can override them.
#define RETURN_FN(functionName) if (!strcmp(name, #functionName)) return emscripten_##functionName;
#define RETURN_FN_WITH_SUFFIX(functionName, suffix) if (!strcmp(name, #functionName)) return emscripten_##functionName##suffix;

#endif
