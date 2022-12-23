#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define TF 100

//fun��o de limpar a tela em linux ou windows
void limpa_tela()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}

main()
{
	int tlh = 0, tlq = 0, tls = 0, tlr = 0, tll = 0, vRG[TF], vNum[TF], vCod[TF], vReserva[TF], vRG_R[TF], vNum_R[TF], vNumDias_R[TF], vLancamento[TF], vReserva_L[TF], vCod_L[TF];
	int opcao, i, pos = 0, pos2 = 0, local, localR, cont_reserva = 0, novo, antigo, interno, menu;
	char vHospede[TF][TF], vQuarto[TF][TF], vServico[TF][TF], continuar, livre[] = "Livre", ocupado[] = "Ocupado";
	float vValor_R[TF], vValor_L[TF];
	
	setlocale(LC_ALL,"Portuguese");
	
	do
	{
		limpa_tela();
		printf("===== GRAND SIERRA RESORT =====\n");
		printf("\n======= MENU PRINCIPAL ========");
		printf("\n1 -------------------- CADASTRO");
		printf("\n2 --------------------- RESERVA");
		printf("\n3 ------------------ LAN�AMENTO");
		printf("\n4 ------------------ RELAT�RIOS");
		printf("\n5 ------------------- FINALIZAR");
		printf("\nInsira a op��o desejada:      ");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1: do
					{
						limpa_tela();
						printf("===== GRAND SIERRA RESORT =====\n");
						printf("\n========== CADASTRO ===========");
						printf("\n1 ---------------------- QUARTO");
						printf("\n2 -------------------- H�SPEDES");
						printf("\n3 -------------------- SERVI�OS");
						printf("\n4 ------------ ALTERAR CADASTRO");
						printf("\n5 ------------ EXCLUIR CADASTRO");												
						printf("\n6 -------------------- RETORNAR");
						printf("\nInsira a op��o desejada:      ");
						scanf("%d", &opcao);
						
						if (opcao < 1 || opcao > 6)
						{
							printf("\nEscolha uma das op��es!\n");
							system("pause");
						}
						else	
						if (opcao == 1)
						{
					    	limpa_tela();
					    	printf("===== GRAND SIERRA RESORT =====\n");
					    	printf("\n===== CADASTRO DE QUARTO ======\n");
						    printf("\nInsira o c�digo do quarto: ");
						    scanf("%d", &vNum[tlq]);
						    	
						    while (vNum[tlq] != vNum[pos] && pos < tlq)
						    	pos++;
						    				    
						    if (pos < tlq)
						    {
						    	printf("\nQuarto j� existente.\n");
								system("pause");
							}

						    else
						    {
						    	printf("\nQuarto %d cadastrado com sucesso!\n", vNum[tlq]);
						    	tlq++;
						    	fflush(stdin);
								strcpy(vQuarto[tlq-1], livre);
						    	system("pause");
						    }
						    
						    pos = 0;
						}
						else
						if (opcao == 2)
						{
					    	limpa_tela();
					    	printf("===== GRAND SIERRA RESORT =====\n");
					    	printf("\n===== CADASTRO DE H�SPEDE =====\n");
							printf("\nInsira o RG do h�spede: ");
							scanf("%d", &vRG[tlh]);
												    	
							while (vRG[tlh] != vRG[pos] && pos < tlh)
								pos++;
												    	
							if (pos < tlh)
							{
								printf("\nH�spede j� cadastrado!\n");
								system("pause");					
							}
							else
							{
								printf("Insira o nome do h�spede: ");
								fflush(stdin);
								gets(vHospede[tlh]);
								printf("\nH�spede %s cadastrado com sucesso!\n", vHospede[tlh]);
								tlh++;
								system("pause");
							}
													    	
							pos = 0;
						}
					    else
						if (opcao == 3)
						{
					    	limpa_tela();
					    	printf("===== GRAND SIERRA RESORT =====\n");
					    	printf("\n===== CADASTRO DE SERVI�O =====\n");
						    printf("\nInsira o c�digo do servi�o: ");
						    scanf("%d", &vCod[tls]);
						    	
						    while (vCod[tls] != vCod[pos] && pos < tls)
						    	pos++;
						    
						    if (pos < tls)
						    {
						    	printf("\nServi�o j� cadastrado!\n");
								system("pause");
							}
						    else
						    {
						    	printf("Insira o nome do servi�o: ");
								fflush(stdin);
								gets(vServico[tls]);
						    	printf("\nServi�o %s cadastrado com sucesso!\n", vServico[tls]);
						    	tls++;
						    	system("pause");
						    }
						    	
						    pos = 0;
						}
						else
						if (opcao == 4)
						{
							do
							{
								limpa_tela();
								printf("===== GRAND SIERRA RESORT =====\n");
								printf("\n==== ALTERA��O DE CADASTRO ====");
								printf("\n1 ---------------------- QUARTO");
								printf("\n2 -------------------- H�SPEDES");
								printf("\n3 -------------------- SERVI�OS");												
								printf("\n4 -------------------- RETORNAR");
								printf("\nInsira a op��o desejada:      ");
								scanf("%d", &interno);
								
								if (interno < 1 || interno > 4)
								{
									printf("\nEscolha uma das op��es!\n");
									system("pause");
								}
								else	
								if (interno == 1)
								{
							    	limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n======= ALTERAR QUARTO ========\n");
							    	printf("\nInsira o n�mero do quarto a ser alterado: ");
							    	scanf("%d", &antigo);
							    	
							    	while (antigo != vNum[pos] && pos < tlq)
								    	pos++;
								    
								    if (pos < tlq)
								    {
								    	local = pos;
								    	
								    	printf("\nInsira o novo n�mero do quarto: ");
									    scanf("%d", &novo);
									    
									    pos = 0;
									    
									    while (novo != vNum[pos] && pos < tlq)
									    	pos++;
									    
									    if (pos < tlq)
									    {
									    	printf("\nQuarto j� existente. Escolha outro n�mero.\n");
											system("pause");	
									    }

									    else
									    {
									    	vNum[local] = novo;
									    	printf("\nO novo n�mero do quarto � %d!\n", vNum[local]);
											system("pause");
									    }
									}
								    else
								    {
								    	printf("\nQuarto N�O est� cadastrado!\n");
										system("pause");	
								    }
							    	
								    pos = 0;
								}
								else
								if (interno == 2)
								{
							    	limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n======= ALTERAR H�SPEDE =======\n");
									printf("\nInsira o RG do h�spede: ");
									scanf("%d", &opcao);
														    	
									while (opcao != vRG[pos] && pos < tlh)
										pos++;
														    	
									if (pos < tlh)
									{
										printf("\nH�spede %s localizado!\n", vHospede[pos]);
										printf("\nInsira o novo nome do h�spede: ");
										fflush(stdin);
										gets(vHospede[pos]);
										printf("\nNome do h�spede alterado para %s.\n\n", vHospede[pos]);
										system("pause");
									}
									else
									{
										printf("\nH�spede n�o cadastrado!\n");
										system("pause");
									}
										
									pos = 0;
								}
							    else
								if (interno == 3)
								{
							    	limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n======= ALTERAR SERVI�O =======\n");
								    printf("\nInsira o c�digo do servi�o: ");
								    scanf("%d", &antigo);
								    	
								    while (antigo != vCod[pos] && pos < tls)
								    	pos++;
								    
								    if (pos < tls)
								    {
										printf("\nServi�o %s localizado!\n", vServico[pos]);
										printf("\nInsira o novo nome do servi�o: ");
										fflush(stdin);
										gets(vServico[pos]);
										printf("\nNome do servi�o alterado para %s.\n", vServico[pos]);
										system("pause");
									}
									else
									{
										printf("\nServi�o n�o cadastrado!\n");
										system("pause");
									}
								    	
								    pos = 0;
								}
								fflush(stdin);
							} while (interno != 4);
						}				
						else
						if (opcao == 5)
						{
							limpa_tela();
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n==== EXCLUS�O DE CADASTRO =====");
							printf("\n1 ---------------------- QUARTO");
							printf("\n2 -------------------- H�SPEDES");
							printf("\n3 -------------------- SERVI�OS");												
							printf("\n4 -------------------- RETORNAR");
							printf("\nInsira a op��o desejada:      ");
							scanf("%d", &interno);
							
							if (interno < 1 || interno > 4)
							{
								printf("\nEscolha uma das op��es!\n");
								system("pause");
							}
							else	
							if (interno == 1)
							{
						    	limpa_tela();
						    	printf("===== GRAND SIERRA RESORT =====\n");
						    	printf("\n====== EXCLUIR QUARTO =======\n");
						    	printf("\nInsira o n�mero do quarto a ser exclu�do: ");
						    	scanf("%d", &antigo);
						    	
						    	while (antigo != vNum_R[pos] && pos < tlr)
						    		pos++;
						    	
						    	if (pos < tlr)
						    	{
						    		printf("\nEste quarto est� reservado. N�o � poss�vel excluir!\n");
						    		system("pause");
								}
						    	else
						    	{
						    		pos = 0;
						    		
							    	while (antigo != vNum[pos] && pos < tlq)
								    	pos++;
								    
								    if (pos < tlq)
								    {
								    	printf("\nQuarto localizado!\n");
								    	printf("\nESTA A��O � IRREVERS�VEL!\nVoc� deseja excluir o quarto %d <s/N>? ", vNum[pos]);
										fflush(stdin);
									    scanf("%c", &continuar);
									    continuar = toupper(continuar);
									    
										if (continuar == 'S')
										{
											for(i = pos; i < tlq-1; i++)
											{
												vNum[i] = vNum[i+1];
												fflush(stdin);
												strcpy(vQuarto[i], vQuarto[i+1]);
											}
											tlq--;
											printf("\nQuarto EXCLU�DO com sucesso!\n");
											system("pause");
										}
										else
										{
											printf("\nA��O N�O REALIZADA! O quarto n�o foi exclu�do!\n");
											system("pause");
										}
									}
								    else
								    {
								    	printf("\nQuarto N�O est� cadastrado!\n");
								    	system("pause");
									}
								}
							    pos = 0;
							}
							else
							if (interno == 2)
							{
						    	limpa_tela();
						    	printf("===== GRAND SIERRA RESORT =====\n");
						    	printf("\n======= EXCLUIR H�SPEDE =======\n");
								printf("\nInsira o RG do h�spede: ");
								scanf("%d", &antigo);
								
								while (antigo != vRG_R[pos] && pos < tlr)
									pos++;
								
								if (pos < tlr)
								{
						    		printf("\nEste h�spede possui reserva. N�o � poss�vel a exclus�o!\n");
						    		system("pause");
								}
								else
						    	{
						    		pos = 0;
						    		
							    	while (antigo != vRG[pos] && pos < tlh)
								    	pos++;
								    
								    if (pos < tlh)
								    {
								    	printf("\nH�spede localizado!\n");
								    	printf("\nESTA A��O � IRREVERS�VEL!\nVoc� deseja excluir o h�spede %s <s/N>? ", vHospede[pos]);
										fflush(stdin);
									    scanf("%c", &continuar);
									    continuar = toupper(continuar);
									    
										if (continuar == 'S')
										{
											for(i = pos; i < tlh-1; i++)
											{
												vRG[i] = vRG[i+1];
												fflush(stdin);
												strcpy(vHospede[i], vHospede[i+1]);
											}
											tlh--;
											printf("\nH�spede EXCLU�DO com sucesso!\n");
											system("pause");
										}
										else
										{
											printf("\nA��O N�O REALIZADA! O h�spede n�o foi exclu�do!\n");
											system("pause");
										}
									}
								    else
								    {
								    	printf("\nH�spede N�O est� cadastrado!\n");
								    	system("pause");
									}
								}
								
								pos = 0;
							}
						    else
							if (interno == 3)
							{
						    	limpa_tela();
						    	printf("===== GRAND SIERRA RESORT =====\n");
						    	printf("\n======= EXCLUIR SERVI�O =======\n");
								printf("\nInsira o c�digo do servi�o: ");
								scanf("%d", &antigo);
								
								while (antigo != vCod_L[pos] && pos < tll)
									pos++;
								
								if (pos < tll)
								{
						    		printf("\nEste servi�o possui lan�amento. N�o � poss�vel a exclus�o!\n");
						    		system("pause");
								}
								else
						    	{
						    		pos = 0;
						    		
							    	while (antigo != vCod[pos] && pos < tls)
								    	pos++;
								    
								    if (pos < tls)
								    {
								    	printf("\nServi�o localizado!\n");
								    	printf("\nESTA A��O � IRREVERS�VEL!\nVoc� deseja excluir o servi�o %s <s/N>? ", vServico[pos]);
										fflush(stdin);
									    scanf("%c", &continuar);
									    continuar = toupper(continuar);
									    
										if (continuar == 'S')
										{
											for(i = pos; i < tls-1; i++)
											{
												vCod[i] = vCod[i+1];
												fflush(stdin);
												strcpy(vServico[i], vServico[i+1]);
											}
											tls--;
											printf("\nServi�o EXCLU�DO com sucesso!\n");
											system("pause");
										}
										else
										{
											printf("\nA��O N�O REALIZADA! O servi�o n�o foi exclu�do!\n");
											system("pause");
										}
									}
								    else
								    {
								    	printf("\nServi�o N�O est� cadastrado!\n");
								    	system("pause");
									}
								}
								
								pos = 0;
							}				
						}
						fflush(stdin);				
					} while (opcao != 6);
					break;
					
				
			case 2: if (tlh == 0 && tlq == 0)
					{
						printf("\nN�o h� h�spede e n�o h� quarto cadastrado.\nEfetue os CADASTROS antes de reservar!\n");
						system("pause");
					}
					else
					if (tlq == 0)
					{
						printf("\nN�o h� quarto cadastrado.\nEfetue o CADASTRO antes de reservar!\n");
						system("pause");
					}
					else
					if (tlh == 0)
					{
						printf("\nN�o h� h�spede cadastrado.\nEfetue o CADASTRO antes de reservar!\n");
						system("pause");
					}
					else
					{
						do
						{
							limpa_tela();
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n=========== RESERVA ===========");
							printf("\n1 --------------------- INCLUIR");
							printf("\n2 --------------------- ALTERAR");
							printf("\n3 --------------------- EXCLUIR");
							printf("\n4 -------------------- RETORNAR");
							printf("\nInsira a op��o desejada:    : ");
							scanf("%d", &opcao);
							
							if (opcao < 1 || opcao > 4)
							{
								printf("\nEscolha uma das op��es!\n");
								system("pause");
							}
							else
							if (opcao == 1)
							{
								limpa_tela();
								printf("===== GRAND SIERRA RESORT =====\n");
							    printf("\n===== INCLUS�O DE RESERVA =====\n");
								printf("\nInsira o RG do h�spede: ");
								scanf("%d", &vRG_R[tlr]);
								  		
								while (vRG_R[tlr] != vRG[pos] && pos < tlh)
								   	pos++;
								   	
								if (pos < tlh)
								{	
									pos = 0;
									
								    while (vRG_R[tlr] != vRG_R[pos] && pos < tlr)
								   		pos++;
								   	
								    if (pos < tlr)
								    {
								    	printf("\nH�spede j� possui reserva!N�o h� poss�vel duas reservas para o mesmo h�spede!");
								    	printf("\nCaso necess�rio, ALTERE a reserva.\n");
								    	system("pause");
								   	}
								   	else
								   	{												   							
										printf("Insira o n�mero do quarto a ser reservado: ");
									   	scanf("%d", &vNum_R[tlr]);
									
										pos = 0;	
										
										while (vNum_R[tlr] != vNum[pos] && pos < tlq)
								    		pos++;
								    	
									    if (pos < tlq)
									    {
									    	if (strcmp(vQuarto[pos], livre) == 0)
									    	{
									    		printf("Insira a quantidade de dias da reserva: ");
											   	scanf("%d", &vNumDias_R[tlr]);
											   	printf("Insira o valor da di�ria: ");
											   	scanf("%f", &vValor_R[tlr]);
										   		
										   		cont_reserva++;
										   		vReserva[tlr] = cont_reserva;
										   		
											    printf("\nReserva %d do h�spede RG n� %d efetuada com sucesso!\n", vReserva[tlr], vRG_R[tlr]);
											    tlr++;
											    fflush(stdin);
												strcpy(vQuarto[pos], ocupado);
											   	system("pause");
									    	}
									    	else
									    	{
									    		printf("\nQuarto ocupado! Escolha outro quarto.\n");
												system("pause");
											}		
									    }
									    else
									    {
									    	printf("\nQuarto n�o cadastrado!\nCADASTRE o quarto antes de efetuar a reserva!\n");
									    	system("pause");
										}
								    }
								}
								else
								{
								   	printf("\nH�spede n�o cadastrado!\nCADASTRE o h�spede antes de efetuar a reserva!\n");
								   	system("pause");
								}
								  	
								pos = 0;
							}
							else
							if (opcao == 2)
							{
								limpa_tela();
																		
								printf("===== GRAND SIERRA RESORT =====\n");
						    	printf("\n==== ALTERA��O DE RESERVA =====\n");
							    printf("\nInsira o RG do h�spede: ");
							    scanf("%d", &opcao);
							    	
							    while (opcao != vRG_R[pos] && pos < tlr)
							    	pos++;
								    	
							    if (pos < tlr)
							    {
							    	local = pos;
							    	printf("\nReserva %d do h�spede localizada!\n", vReserva[pos]);
							    	system("pause");
							    	
						    		limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n===== ALTERA��O DE RESERVA ====\n");
									printf("\n== O que alterar na reserva? ==\n");
									printf("\n1 ------------ N�MERO DO QUARTO");
									printf("\n2 --- NUMERO DE DIAS DA RESERVA");
									printf("\n3 ------------- VALOR DA DI�RIA");
									printf("\n4 -------------------- RETORNAR");
									printf("\nInsira a op��o desejada:    : ");
									scanf("%d", &opcao);
							
									if (opcao < 1 || opcao > 4)
									{
										printf("\nEscolha uma das op��es!\n");
										system("pause");
									}
									else
									if (opcao == 1)
									{	
						    			limpa_tela();						
										printf("===== GRAND SIERRA RESORT =====\n");
							    		printf("\n===== ALTERA��O DE RESERVA ====\n");
							    		printf("\nO h�spede est� com reserva no quarto %d.\n", vNum_R[pos]);
							    		
							    		pos2 = 0;
							    		
										while (vNum_R[pos] != vNum[pos2] && pos2 < tlq)
											pos2++;	
										 
								    	printf("\nInsira o n�mero do novo quarto: ");
									   	scanf("%d", &novo);
									   	
									   	pos = 0;
									   		
									   	while (novo != vNum[pos] && pos < tlq)
								    		pos++;
								    	
									    if (pos < tlq)
									    {
									    	if (strcmp(vQuarto[pos], livre) == 0)
									   		{
												vNum_R[local] = novo;
												fflush(stdin);										    	
										    	strcpy(vQuarto[pos], ocupado);
										    	fflush(stdin);
										    	strcpy(vQuarto[pos2], livre);
												printf("\nQuarto da reserva alterado com sucesso!\n");
									    		system("pause");
									   		}
									    	else
									    	{
									    		printf("\nQuarto ocupado! Escolha outro quarto.\n");
									    		system("pause");
									    	}
										}
										else
										{
											printf("\nQuarto n�o cadastrado!\nCADASTRE o quarto antes de alterar a reserva!\n");
									    	system("pause");
										}
									}
									else
									if (opcao == 2)
									{
										limpa_tela();
										printf("===== GRAND SIERRA RESORT =====\n");
							    		printf("\n==== ALTERA��O DE RESERVA =====\n");
								    	printf("\nInsira o novo n�mero de dias da reserva: ");
									   	scanf("%d", &vNumDias_R[local]);
									   	printf("\nN�mero de dias alterado com sucesso!\n");
									   	system("pause");
									}
									else
									if (opcao == 3)
									{
										limpa_tela();
										printf("===== GRAND SIERRA RESORT =====\n");
							    		printf("\n===== ALTERA��O DE RESERVA ======\n");
								    	printf("\nInsira o novo valor da di�ria: ");
									   	scanf("%f", &vValor_R[local]);
									   	printf("\nValor da di�ria alterado com sucesso!\n");
									   	system("pause");
									}
									
									pos = 0;							
							    }
							    else
							    {
							    	printf("\nH�spede n�o possui reserva! Utilize a op��o INCLUIR!\n");
							    	system("pause");
							    }
								   	
							   	pos = 0;
							}	
							else
							if (opcao == 3)
							{	
								limpa_tela();					
								printf("===== GRAND SIERRA RESORT =====\n");
							   	printf("\n===== EXCLUS�O DE RESERVA =====\n");
							    printf("\nInsira o RG do h�spede: ");
							    scanf("%d", &antigo);
								
								while (antigo != vRG[pos] && pos < tlh)
									pos++;
									
								if (pos < tlh)
								{
									local = pos;
									
									pos = 0;
									
									while (antigo != vRG_R[pos] && pos < tlr)
							    		pos++;
								    	
								    if (pos < tlr)
								    {		
										localR = pos;
										
										pos = 0;
										
										while (vReserva[localR] != vReserva_L[pos] && pos < tll)
							    			pos++;
								    	
									    if (pos < tll)
									    {		
											printf ("\nN�O � poss�vel excluir a reserva! H� lan�amento(s)!\n");
											system("pause");
										}
										else
										{
											
											pos = 0;
											
											while (vNum_R[localR] != vNum[pos] && pos < tlq)
												pos++;
											
									    	printf("\nReserva localizada!\n");
									    	printf("\nESTA A��O � IRREVERS�VEL!\nVoc� deseja excluir a reserva %d do h�spede %s <s/N>? ", vReserva[localR], vHospede[local]);
											fflush(stdin);
										    scanf("%c", &continuar);
										    continuar = toupper(continuar);
										    
											if (continuar == 'S')
											{
												for(i = localR; i < tlr-1; i++)
												{
													vReserva[i] = vReserva[i+1];
													vRG_R[i] = vRG_R[i+1];
													vNum_R[i] = vNum_R[i+1];
													vNumDias_R[i] = vNumDias_R[i+1];
													vValor_R[i] = vValor_R[i+1];
												}
												tlr--;
												fflush(stdin);
												strcpy(vQuarto[pos], livre);
												
												printf("\nReserva do h�spede %s EXCLU�DA com sucesso!\n", vHospede[local]);
												system("pause");
											}
											else
											{
												printf("\nA��O N�O REALIZADA! A reserva N�O foi cancelada!\n");
												system("pause");
											}
										}
									}
									else
									{
										printf("\nH�spede N�O possui reserva!\n");
										system("pause");
									}
								}
								else
								{
									printf("\nH�spede N�O est� cadastrado!\n");
									system("pause");
								}						
							}
							
							pos = 0;
							
							fflush(stdin);
							
						} while (opcao != 4);
					}
					break;
								
			case 3:	do
					{
						limpa_tela();
						printf("===== GRAND SIERRA RESORT =====\n");
						printf("\n========= LAN�AMENTO ==========");
						printf("\n1 --------------------- INCLUIR");
						printf("\n2 --------------------- ALTERAR");
						printf("\n3 --------------------- EXCLUIR");
						printf("\n4 -------------------- RETORNAR");
						printf("\nInsira a op��o desejada:    : ");
						scanf("%d", &opcao);
						
						if (opcao < 1 || opcao > 4)
						{
							printf("\nEscolha uma op��o!\n");
							system("pause");							
						}
						else
						if (opcao == 1)
						{
							limpa_tela();
							
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n=== INCLUS�O DE LAN�AMENTO ====\n");
							
							printf("\nInsira o c�digo do lan�amento: ");
							scanf("%d", &vLancamento[tll]);
							
							while (vLancamento[tll] != vLancamento[pos] && pos < tll)
								pos++;
								
							if (pos < tll)
							{
								printf("\nLan�amento j� existente.\n");
								system("pause");
							}
							else
							{
								pos = 0;
								
								printf("Insira o c�digo da reserva: ");
								scanf("%d", &vReserva_L[tll]);							
							
								while (vReserva_L[tll] != vReserva[pos] && pos < tlr)
									pos++;
								
								if (pos < tlr)
								{
									pos = 0;
									
									printf("Insira o c�digo do servi�o a ser lan�ado: ");
									scanf("%d", &vCod_L[tll]);
									
									while (vCod_L[tll] != vCod[pos] && pos < tls)
										pos++;
										
									if (pos < tls)
									{
										printf("Insira o valor do lan�amento: ");
										scanf("%f", &vValor_L[tll]);
										printf("\nLan�amento do servi�o %s efetuado com sucesso!\n", vServico[pos]);
										tll++;
										system("pause");
									}
									else
									{
										printf("\nC�digo de servi�o inexistente!\n");
										system("pause");
									}				
								}
								else
								{
									printf("\nReserva inexistente!\n");
									system("pause");
								}
							}
							
							pos = 0;
							
						}
						else
						if (opcao == 2)
						{
							limpa_tela();
							
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n=== ALTERA��O DE LAN�AMENTO ===\n");
							
							printf("\nInsira o c�digo de lan�amento: ");
							scanf("%d", &vLancamento[tll]);
							
							while (vLancamento[tll] != vLancamento[pos] && pos < tll)
								pos++;
							
							if (pos < tll)
							{
								local = pos;
								pos = 0;
								
								limpa_tela();
								
								printf("===== GRAND SIERRA RESORT =====\n");
								printf("\n=== ALTERA��O DE LAN�AMENTO ===\n");
								printf("\nO que alterar no lan�amento? ==\n");
								printf("\n1 ------------ N�MERO DA RESERVA");
								printf("\n2 --------- C�DIGO DO LAN�AMENTO");
								printf("\n3 ---------- VALOR DO LAN�AMENTO");
								printf("\n4 --------------------- RETORNAR");										
								printf("\nInsira a op��o desejada:     : ");
								scanf("%d", &opcao);
									
								if (opcao < 1 || opcao > 4)
								{
									printf("\nOpc�o inexistente!\n");
									system("pause");
								}
								else
								if (opcao == 1)
								{
									pos = 0;
									
									printf("\nInsira o novo n�mero da reserva: ");
									scanf("%d", &vReserva_L[tll]);
									
									while (vReserva_L[tll] != vReserva[pos] && pos < tlr)
										pos++;
										
									if (pos < tlr)
									{
										vReserva_L[local] = vReserva_L[tll];
										printf("\nLan�amento n� %d alterado para a reserva n� %d.\n", vLancamento[local], vReserva_L[local]);
										system("pause");
									}
									else
									{
										printf("\nReserva inexistente!\n");
										system("pause");
									}
									
									pos = 0;
								}
								else
								if (opcao == 2)
								{
									printf("\nInsira o novo c�digo de lan�amento: ");
									scanf("%d", &vLancamento[tll]);
									
									while(vLancamento[tll] != vLancamento[pos] && pos < tll)
										pos++;
									
									if (pos < tll)
									{
										printf("\nLan�amento j� existente!\n");
										system("pause");
									}
									else
									{
										vLancamento[local] = vLancamento[tll];
										printf("\nLan�amento alterado para o n� %d na reserva n� %d.\n", vLancamento[local], vReserva_L[local]);
										system("pause");										
									}
									
									pos = 0;
								}
								else
								if (opcao == 3)
								{
									printf("\nInsira o novo valor do lan�amento: ");
									scanf("%f", &vValor_L[local]);
									printf("\nValor do lan�amento alterado para R$%0.2f na reserva n� %d.\n", vValor_L[local], vReserva_L[local]);
									system("pause");
									
								}
							}
							else
							{
								printf("\nLan�amento n�o encontrado.\n");
								system("pause");
							}
							
							pos = 0;
						}
						else
						if (opcao == 3)
						{
							limpa_tela();
							
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n=== EXCLUS�O DE LAN�AMENTO ====\n");
							
							printf("\nInsira o c�digo de lan�amento: ");
							scanf("%d", &vLancamento[tll]);
							
							while (vLancamento[tll] != vLancamento[pos] && pos < tll)
								pos++;
							
							if (pos < tll)
							{
								printf("\nLan�amento localizado!\n");
								printf("\nESTA A��O � IRREVERS�VEL!\nVoc� deseja excluir o lan�amento %d da reserva %d <s/N>? ", vLancamento[pos], vReserva_L[pos]);
								fflush(stdin);
								scanf("%c", &continuar);
								continuar = toupper(continuar);
										    
								if (continuar == 'S')
								{
									for(i = pos; i < tll-1; i++)
									{
									vLancamento[i] = vLancamento[i+1];
									vReserva_L[i] = vReserva_L[i+1];
									vCod_L[i] = vCod_L[i+1];
									vValor_L[i] = vValor_L[i+1];
									}
									tll--;
												
									printf("\nLan�amento EXCLU�DO com sucesso!\n");
									system("pause");
								}
								else
								{
									printf("\nA��O N�O REALIZADA! O lan�amento N�O foi exclu�do!\n");
									system("pause");									
								}
							}
							else
							{
								printf("\nLan�amento n�o encontrado!\n");
								system("pause");						
							}
							
							pos = 0;						
						}
						
						fflush(stdin);										
					} while (opcao != 4);
					break;
				
				
			case 4: do
					{
						limpa_tela();
						printf("===== GRAND SIERRA RESORT =====\n");
						printf("\n========= RELAT�RIOS ==========");
						printf("\n1 ------------ QUARTOS OCUPADOS");
						printf("\n2 ----------- QUARTOS LIBERADOS");
						printf("\n3 -------------------- H�SPEDES");
						printf("\n4 -------------------- SERVI�OS");
						printf("\n5 -------------------- RETORNAR");
						printf("\nInsira a op��o desejada:    : ");
						scanf("%d", &opcao);
						
						if (opcao < 1 || opcao > 5)
						{
							printf("\nEscolha uma das op��es!\n");
							system("pause");							
						}
						else
						if (opcao == 1)
						{
							printf("\n|| QUARTOS OCUPADOS ||\n");
							for (i = 0; i < tlq; i++)
							{
								if (strcmp(vQuarto[i], ocupado) == 0)
									printf("Quarto %d\n", vNum[i]);
							}
							printf("\n");
							system("pause");
						}
						else
						if (opcao == 2)
						{
							printf("\n|| QUARTOS LIBERADOS ||\n");
							for (i = 0; i < tlq; i++)
							{
								if (strcmp(vQuarto[i], livre) == 0)
									printf("Quarto %d\n", vNum[i]);
							}
							printf("\n");
							system("pause");
						}
						else
						if (opcao == 3)
						{
							printf("\n|| H�SPEDES CADASTRADOS ||\n");
							for (i = 0; i < tlh; i++)
							{
								printf("RG n� %d - %s\n", vRG[i], vHospede[i]);
							}
							printf("\n");
							system("pause");	
						}
						else
						if (opcao == 4)
						{
							printf("\n|| SERVI�OS CADASTRADOS ||\n");
							for (i = 0; i < tls; i++)
							{
								printf("C�digo n� %d - %s\n", vCod[i], vServico[i]);
							}
							printf("\n");
							system("pause");	
						}
						fflush(stdin);		
					} while (opcao != 5);
					break;
		}
		
		if (menu < 1 || menu > 5)
		{
			printf("\nEscolha uma das op��es!\n");
			system("pause");			
		}
		
		fflush(stdin);
	} while (menu != 5);
	
	printf("\n======= FIM DO PROGRAMA =======");
}
