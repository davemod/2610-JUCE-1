#include "Tempo.h"

#pragma message("Compiling Tempo.cpp")

double beatDurationMs(double bpm)
{
    return 60000.0 / bpm;
}
