#pragma once

#include <stdio.h>

void error(const char *functionName);

int clamp(int val, int min, int max);

int applyDeadZoneX(int valX, int valY, double deadZone);

int applyDeadZoneY(int valX, int valY, double deadZone);
