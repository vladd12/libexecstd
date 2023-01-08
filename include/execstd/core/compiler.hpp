#pragma once

/*! \file compiler.hpp
 *  \brief Detection compiler and version of the C++ standard
 */

// Detecting cpp standard
#ifndef EXECSTD_CPP_STANDARD

// Detecting platform
#if defined(__cplusplus)
#define EXECSTD_CPP __cplusplus
#elif defined(_MSVC_LANG)
#define EXECSTD_CPP _MSVC_LANG
#else
#define EXECSTD_CPP 0L
#endif

// Detect current cpp standard
#if EXECSTD_CPP < 201103L
#define EXECSTD_CPP_STANDARD 2003
#elif EXECSTD_CPP < 201402L
#define EXECSTD_CPP_STANDARD 2011
#elif EXECSTD_CPP < 201703L
#define EXECSTD_CPP_STANDARD 2014
#elif EXECSTD_CPP < 202002L
#define EXECSTD_CPP_STANDARD 2017
#elif EXECSTD_CPP == 202002L
#define EXECSTD_CPP_STANDARD 2020
#elif EXECSTD_CPP > 202002L
#define EXECSTD_CPP_STANDARD 2023
#endif

#endif
