#pragma once
#include <stdbool.h>
#include "Header.h"

#ifndef KATAKOMBE_H
#define KATAKOMBE_H

void Katakombe();
bool PotezNeprijatelj(int dgNeprijatelj, int ggNeprijatelj, int jacinaNeprijatelja);
bool PotezJa(int dgNeprijatelj, int ggNeprijatelj, int jacinaNeprijatelja);
void ProlazJedanSobaJedan();
void BorbaNeprijateljPrvi();
void ProlazDvaSobaJedan();
void BorbaNeprijateljDrugi();
void ProlazTriSobaJedan();
void BorbaNeprijateljTreci();
static void FunkcijaPobjeda();
#endif