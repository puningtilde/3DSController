#include "wireless.h"

#include "general.h"

#include <math.h>

void error(const char *functionName) {
	char errorMsg[92];
	ZeroMemory(errorMsg, 92);

	sprintf(errorMsg, "Call to %s returned error %d!", (char *)functionName, WSAGetLastError());

	MessageBox(NULL, errorMsg, "socketIndication", MB_OK);

	closesocket(client);
	closesocket(listener);
	WSACleanup();

	exit(0);
}

int clamp	(int val, int min, int max) {
	if (val < min) {
		return min;
	}

	if (val > max) {
		return max;
	}

	return val;
}

int applyDeadZoneX(int valX, int valY, double deadZone){
	double cap = 164 * deadZone;
	double module = sqrt(pow(valX,2)+pow(valY,2));

	if (module < cap) {
		return 0;
	} else {
		return valX;
	}
}

int applyDeadZoneY(int valX, int valY, double deadZone){
	double cap = 164 * deadZone;
	double module = sqrt(pow(valX,2)+pow(valY,2));

	if (module < cap) {
		return 0;
	} else {
		return valY;
	}
}
