//######################################################################################
//####       In aceasta Biblioteca de functii se vor introduce Toate blocurile 
//####       din schema-bloc implementata sub forma unor functii C
//####  ...dupa modelul de mai jos   
//######################################################################################

#pragma once

void Constante(double Te) {
	Cee1 = Te/(Te + Tee2);
	Cee2 = Tee1/(Te + Tee2);
	Ctr1 =  Te/(Te + Ttr1);
	C1 = Te/(Te + T1);
	C2 = Te/(Te +T2);
	C3 = Te/(Te + T3);
}

double EE() {
	
	yEEk = yEEk_1 + Cee1*(server_Refk - yEEk_1) + Cee2*(server_Refk - server_Refk_1)  ;
	return yEEk;
}

double InstalatieTehnologica() {

		yITk1=yITk1_1+C1*(uITk-yITk1_1);
		uITk1=yITk1;
		yITk2=yITk2_1+C2*(uITk1-yITk2_1);
		uITk2=yITk2;
		yITk3=yITk3_1+C3*(uITk2-yITk3_1);

	// Returneaza valoarea stocata in local_yITk, iesirea functiei de tip dipol
	return 	yITk3;
} 

double Traductor() {

	yTRk1 = yTRk1_1 + Ctr1*(yITk1 - yTRk1_1);
	return yTRk1;
}

void reactualizare() {

				yITk1_1=yITk1;
	yITk2_1=yITk2;
	yITk3_1=yITk3;
	uITk_1=uITk;
	uITk1_1=uITk1;
	uITk2_1=uITk2;
	uITk3_1=uITk3;
	yEEk_1=yEEk;
	yTRk1_1=yTRk1;
	yPIDk_2=yPIDk_1;
	yPIDk_1=yPIDk;
	tk_1 = tk; 
	tk += server_Te;
	server_Refk_1 = server_Refk;
}