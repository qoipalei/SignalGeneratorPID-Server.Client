//Schema sinoptica animata
int animatie_Bazin(double input)
{
			SetCtrlVal (g_hmainPanel, MAINPNL_NUMERICTANK, input);
			if(input<20)
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 1);
			}
			if((input>=20)&&(input<40))
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 1); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
			if((input>=40)&&(input<60))
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 1); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
			if((input>=60)&&(input<80))
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 0);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 1); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
			if(input>=80)
			{
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS, ATTR_VISIBLE , 1);
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_1_2, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_DESCHIS_2_3, ATTR_VISIBLE , 0); 
				SetCtrlAttribute (g_hmainPanel, MAINPNL_R_INCHIS, ATTR_VISIBLE , 0);
			}
return 0;
}
