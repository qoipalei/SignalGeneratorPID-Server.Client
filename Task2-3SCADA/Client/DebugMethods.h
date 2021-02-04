//==============================================================================
//
// Title:		DebugMethods.h
// Purpose:		A short description of the interface.
//
// Created on:	1/6/2021 at 6:32:00 PM by .
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

void DebugServerSend ();
void DebugTraductorReadFromServer();

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __DebugMethods_H__ */
