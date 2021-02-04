//==============================================================================
//
// Title:		DebugMethods.h
// Purpose:		A short description of the interface.
//
// Created on:	1/15/2021 at 6:21:28 PM by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __DebugMethods_H__
#define __DebugMethods_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

//==============================================================================
// Global functions


void ResetAllValues(double y1k, double y1k_1, double y2k, double y2k_1, double yk_EE, double yk_1_EE, double yk_Tr1, double yk_1_Tr1, double yPIDk, double yPIDk_1, double yPIDk_2);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __DebugMethods_H__ */
