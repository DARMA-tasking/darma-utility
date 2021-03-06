/*
//@HEADER
// ************************************************************************
//
//                          compatibility.h
//                         dharma_new
//              Copyright (C) 2017 NTESS, LLC
//
// Under the terms of Contract DE-NA-0003525 with NTESS, LLC,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact darma@sandia.gov
//
// ************************************************************************
//@HEADER
*/

#ifndef FRONTEND_INCLUDE_DARMA_COMPATIBILITY_H_
#define FRONTEND_INCLUDE_DARMA_COMPATIBILITY_H_

#include <darma/utility/config.h>

// TODO move this to a configure test instead
#if __cpp_constexpr >= 201304
#  define DARMA_CONSTEXPR_14 constexpr
#else
#  define DARMA_CONSTEXPR_14
#endif

#ifdef DARMA_HAVE_ATTRIBUTE_NONNULL
#  define DARMA_ATTRIBUTE_NONNULL(...) [[ gnu::nonnull (__VA_ARGS__) ]]
#  define DARMA_ATTRIBUTE_ALL_NONNULL [[ gnu::nonnull ]]
#endif

#ifdef DARMA_HAVE_ATTRIBUTE_DEPRECATED
#  ifdef DARMA_HAVE_ATTRIBUTE_DEPRECATED_WITH_MESSAGE
#    define DARMA_ATTRIBUTE_DEPRECATED [[ deprecated ]]
#    define DARMA_ATTRIBUTE_DEPRECATED_WITH_MESSAGE(...) [[ deprecated(__VA_ARGS__) ]]
#  else
#    define DARMA_ATTRIBUTE_DEPRECATED [[deprecated]]
#    define DARMA_ATTRIBUTE_DEPRECATED_WITH_MESSAGE(...) [[deprecated]]
#  endif
#else
#  define DARMA_ATTRIBUTE_DEPRECATED
#  define DARMA_ATTRIBUTE_DEPRECATED_WITH_MESSAGE(...)
#endif

#ifdef DARMA_HAVE_CONCEPTS
#  define _darma_requires(...) requires __VA_ARGS__
#else
#  define _darma_requires(...)
#endif

#ifdef DARMA_HAVE_ATTRIBUTE_ALWAYS_INLINE
#  define DARMA_FORCE_INLINE [[ gnu::always_inline ]] inline
#else
#  define DARMA_FORCE_INLINE inline
#endif

#ifdef DARMA_HAVE_ATTRIBUTE_FLATTEN
#  define DARMA_FLATTEN_FUNCTION [[ gnu::flatten ]]
#else
#  define DARMA_FLATTEN_FUNCTION
#endif


#endif /* FRONTEND_INCLUDE_DARMA_COMPATIBILITY_H_ */
