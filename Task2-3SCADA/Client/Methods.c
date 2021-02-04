#include "Methods.h"

/**
	Parameters for PID: Kr, Ti, Td
	Current Time Sample: Te
	Returns: the current command value
*/

double PID(double Kr, double Ti, double Td, double Te) {
	
	alpha=0.1;
	p0=Kr*((4/(Te*Te))*(alpha*Td*Ti+Ti*Td) + (2/Te)*(Ti+alpha*Td) + 1);
	p1=Kr*(-(8/(Te*Te))*(alpha* Td*Ti+Td*Ti)+2);
	p2=Kr*((4/(Te*Te))*(alpha*Td*Ti+Ti*Td) - (2/Te)*(Ti+alpha*Td) + 1); 
			
	q0=(4/(Te*Te))* Ti*alpha*Td + (2/Te)*Ti;
	q1=-(8/(Te*Te))* Ti*alpha*Td;
	q2=(4/(Te*Te))* Ti*alpha*Td - (2/Te)*Ti; 
	
	a1=q1/q0, a2=q2/q0;
	b0=p0/q0, b1=p1/q0, b2=p2/q0; 
	
	return -a1*yPIDk_1-a2*yPIDk_2+b0*epsk+b1*epsk_1+b2*epsk_2;
}

void generare_Comanda(double Kr, double Ti, double Td, double Te) {
	
	epsk = Refk - 0;	
	yPIDk = PID(Kr, Ti, Td, client_Te);

	
	// Send the current command to the Server
	transmisie_catre_server();
}