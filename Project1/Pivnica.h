#pragma once
#include "HranaEnum.h"

#ifndef PIVNICA_H
#define PIVNICA_H

void PovratakIzPivnicePoruka();
void Pivnica();
void DodajHranu(HranaEnum tipHrane);
const char* EnumHranaToString(enum HranaEnum hrana);

#endif