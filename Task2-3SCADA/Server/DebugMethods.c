//==============================================================================
//
// Title:		DebugMethods.c
// Purpose:		A short description of the implementation.
//
// Created on:	1/6/2021 at 6:21:28 PM by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "DebugMethods.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  What does your function do?
/// HIPAR x/What inputs does your function expect?
/// HIRET What does your function return?


// ResetAllValues(y1k,  y1k_1,  y2k,  y2k_1,  yk_EE,  yk_1_EE,  yk_Tr1,  yk_1_Tr1,  yPIDk,  yPIDk_1,  yPIDk_2);
void ResetAllValues(double y1k, double y1k_1, double y2k, double y2k_1, double yk_EE, double yk_1_EE, double yk_Tr1, double yk_1_Tr1, double yPIDk, double yPIDk_1, double yPIDk_2) {

	y1k = y1k_1 = y2k = y2k_1 = yk_EE = yk_1_EE = yk_Tr1 = yk_1_Tr1 = yPIDk = yPIDk_1 = yPIDk_2 = 0;
}

