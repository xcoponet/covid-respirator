/*
    Copyright (C) 2020 Makers For Life
*/
/******************************************************************************
 * @author Makers For Life
 * @file affichage.h
 * @brief Display and LCD screen related functions
 *
 * This relies on the LiquidCrystal library (https://github.com/arduino-libraries/LiquidCrystal).
 * LCD screen must have 4 lines of 20 characters.
 *****************************************************************************/

#pragma once

// INCLUDES ===================================================================

// External
#include <LiquidCrystal.h>

// Internal
#include "common.h"
#include "parameters.h"

// INITIALISATION =============================================================

/// Instance of the screen controller
extern LiquidCrystal screen;

// FUNCTIONS ==================================================================

/**
 * Start the screen
 *
 * @warning It must be called once to be able to use the screen
 */
void startScreen();

/// Erase everything that is on the screen
void resetScreen();

/// Display the current step of the breathing
void displaySubPhase(CycleSubPhases phase);

/**
 * Display relevant values from the ongoing cycle
 *
 * @param peakPressure     The peak pressure [mmH2O]
 * @param plateauPressure  The plateau pressure [mmH2O]
 * @param peep             The Positive End Expiratory Pressure (PEEP) [mmH2O]
 * @param pressure         The current pressure [mmH2O]
 */
void displayInstantInfo(int peakPressure, int plateauPressure, int peep, int pressure);

/**
 * Display the current settings
 *
 * @param peakPressureMax      PeakPressureMax [mmH2O]
 * @param plateauPressureMax   Next maximal plateau pressure [mmH2O]
 * @param peepMin              Next desired Positive End Expiratory Pressure (PEEP) [mmH2O]
 * @param cyclesPerMinute      Next desired number of cycles per minute
 */
void displaySettings(int peakPressureMax,
                     int plateauPressureMax,
                     int peepMin,
                     int cyclesPerMinute);
