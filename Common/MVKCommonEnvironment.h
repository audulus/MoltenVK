/*
 * MVKCommonEnvironment.h
 *
 * Copyright (c) 2015-2020 The Brenwill Workshop Ltd. (http://www.brenwill.com)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#pragma once

#ifdef __cplusplus
extern "C" {
#endif	//  __cplusplus


#include <TargetConditionals.h>


/**
 * Compiler build setting that ensures a definite value for whether this
 * build is a debug build or not.
 *
 * If the standard DEBUG build setting is defined, MVK_DEBUG is set to true,
 * otherwise, it is set to false.
 */
#ifndef MVK_DEBUG
#	ifdef DEBUG
#		define MVK_DEBUG			1
#	else
#		define MVK_DEBUG			0
#	endif
#endif

/** Building for macOS. */
#ifndef MVK_MACOS
#	define MVK_MACOS				TARGET_OS_OSX
#endif

/** Building for iOS. */
#ifndef MVK_IOS
#	define MVK_IOS					TARGET_OS_IOS
#endif

/** Building for tvOS. */
#ifndef MVK_TVOS
#	define MVK_TVOS					TARGET_OS_TV
#endif

/** Building for iOS or tvOS. */
#ifndef MVK_IOS_OR_TVOS
#	define MVK_IOS_OR_TVOS			(MVK_IOS || MVK_TVOS)
#endif

/** Building for macOS or iOS. */
#ifndef MVK_MACOS_OR_IOS
#	define MVK_MACOS_OR_IOS			(MVK_MACOS || MVK_IOS)
#endif

/** Building for a Simulator. */
#ifndef MVK_OS_SIMULATOR
#	define MVK_OS_SIMULATOR			TARGET_OS_SIMULATOR
#endif

/** Directive to identify public symbols. */
#define MVK_PUBLIC_SYMBOL        __attribute__((visibility("default")))

/** Directive to make a public alias of another symbol. */
#define MVK_PUBLIC_ALIAS(ALIAS, TARGET)   asm(".globl _" #ALIAS "\n\t_" #ALIAS " = _" #TARGET)


#ifdef __cplusplus
}
#endif	//  __cplusplus

