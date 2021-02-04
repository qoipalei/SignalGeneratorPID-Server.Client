#pragma once

// Include files
#include "00_Variabile_Globale_Client.h"
#include "client.h"
#include "04_Formatare_Transmisie_TCP_TX_catre_Server.h"
		
// Function declarations
double PID(double Kr, double Ti, double Td, double Te);
void generare_Comanda(double Kr, double Ti, double Td, double Te);




