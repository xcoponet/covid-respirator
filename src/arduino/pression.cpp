/*
    Copyright (C) 2020 Makers For Life
*/
/******************************************************************************
 * @author Makers For Life
 * @file pression.cpp
 * @brief Pressure sensor related functions
 *****************************************************************************/

#pragma once

// INCLUDES ==================================================================

// Associated header
#include "pression.h"

// External
#include <Arduino.h>

// Internal
#include "parameters.h"

// PROGRAM =====================================================================

double filteredVout = 0;
const double RATIO_PONT_DIVISEUR = 0.8192;
const double V_SUPPLY = 5.08;
const double KPA_MMH2O = 101.97162129779;

// Get the measured or simulated pressure for the feedback control (in mmH2O)
#if SIMULATION == 1
int readPressureSensor(uint16_t centiSec) {
    if (centiSec < uint16_t(10)) {
        return 350;
    } else if (centiSec < uint16_t(15)) {
        return 400;
    } else if (centiSec < uint16_t(30)) {
        return 600;
    } else if (centiSec < uint16_t(45)) {
        return 700;
    } else if (centiSec < uint16_t(60)) {
        return 500;
    } else if (centiSec < uint16_t(100)) {
        return 300;
    } else if (centiSec < 200) {
        return 110;
    } else if (centiSec < 250) {
        return 90;
    } else {
        return 70;
    }
}
#else
int readPressureSensor(uint16_t centiSec) {
    double rawVout = analogRead(PIN_CAPTEUR_PRESSION) * 3.3 / 1024.0;
    filteredVout = filteredVout + (rawVout - filteredVout) * 0.2;

    // Ratio a cause du pont diviseur
    double vOut = filteredVout / RATIO_PONT_DIVISEUR;

    // Pression en kPA
    double pressure = (vOut / V_SUPPLY - 0.04) / 0.09;

    if (pressure <= 0.0) {
        return 0;
    }
    return pressure * KPA_MMH2O;
}
#endif
