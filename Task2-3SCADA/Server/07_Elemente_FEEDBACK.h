//######################################################################################
//####       In aceasta Biblioteca de functii se vor introduce Toate blocurile 
//####       din schema-bloc implementata sub forma unor functii C
//####  ...dupa modelul de mai jos   
//######################################################################################

#pragma once

void SeteazaValorileConstantelor(double Te) {
	
	// Elementul de executie este un dipol
	C1_EE = Te/(Te + T_EE2);
	C2_EE = T_EE1/(Te + T_EE2);
	
	// Traductorul are o singura functie de ordinul 1 la numitor
	C_Tr1 =  Te/(Te + T1_Tr1);
	
	// Functia de transfer, formata dintr-un element de tip aperiodic si unul de tip dipol (iesirea functiei de transfer)
	C = Te/(Te + constantaT);
	C1 = Te/(Te + constantaT2);
	C2 = constantaT1/(Te + constantaT2);
}

double ElementDeExecutie() {
	
	yk_EE = var_A_M == AUTOMAT? ( yk_1_EE + C1_EE*(yPIDk - yk_1_EE) + C2_EE*(yPIDk - yPIDk_1) ) : ( yk_1_EE + C1_EE*(server_Refk - yk_1_EE) + C2_EE*(server_Refk - server_Refk_1) ) ;
	return yk_EE;
}

double InstalatieTehnologica(double uk) {

	y1k = y1k_1 + C*(uk - y1k_1);
	y2k = y2k_1 + C1*(y1k - y2k_1) + C2*(y1k - y1k_1);
	
	// Returneaza valoarea stocata in y2k, iesirea functiei de tip dipol
	return y2k;
} 

double Traductor(double yIT) {

	yk_Tr1 = yk_1_Tr1 + C_Tr1*(yIT - yk_1_Tr1);
	return yk_Tr1;
}

void UpdateValues() {

	yPIDk_2=yPIDk_1;
	yPIDk_1=yPIDk;
	
	y1k_1 = y1k;
	y2k_1 = y2k;
	yk_1_EE = yk_EE;
	yk_1_Tr1 = yk_Tr1;
	
	tk_1 = tk; 
	tk += server_Te;
	server_Refk_1 = server_Refk;
}


