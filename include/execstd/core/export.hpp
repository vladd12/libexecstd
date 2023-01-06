#pragma once

#if defined(_MSC_VER)
#define DECL_EXPORT __declspec(dllexport)
#define DECL_IMPORT __declspec(dllimport)
#else
#define DECL_EXPORT
#define DECL_IMPORT
#endif

#if defined(EXECSTD_EXPORTS)
#define libapi DECL_EXPORT
#elif defined(EXECSTD_EXPORTS)
#define libapi DECL_IMPORT
#else
#define libapi
#endif
