#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define TF 100

//função de limpar a tela em linux ou windows
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
		printf("\n3 ------------------ LANÇAMENTO");
		printf("\n4 ------------------ RELATÓRIOS");
		printf("\n5 ------------------- FINALIZAR");
		printf("\nInsira a opção desejada:      ");
		scanf("%d", &menu);

		switch(menu)
		{
			case 1: do
					{
						limpa_tela();
						printf("===== GRAND SIERRA RESORT =====\n");
						printf("\n========== CADASTRO ===========");
						printf("\n1 ---------------------- QUARTO");
						printf("\n2 -------------------- HÓSPEDES");
						printf("\n3 -------------------- SERVIÇOS");
						printf("\n4 ------------ ALTERAR CADASTRO");
						printf("\n5 ------------ EXCLUIR CADASTRO");												
						printf("\n6 -------------------- RETORNAR");
						printf("\nInsira a opção desejada:      ");
						scanf("%d", &opcao);
						
						if (opcao < 1 || opcao > 6)
						{
							printf("\nEscolha uma das opções!\n");
							system("pause");
						}
						else	
						if (opcao == 1)
						{
					    	limpa_tela();
					    	printf("===== GRAND SIERRA RESORT =====\n");
					    	printf("\n===== CADASTRO DE QUARTO ======\n");
						    printf("\nInsira o código do quarto: ");
						    scanf("%d", &vNum[tlq]);
						    	
						    while (vNum[tlq] != vNum[pos] && pos < tlq)
						    	pos++;
						    				    
						    if (pos < tlq)
						    {
						    	printf("\nQuarto já existente.\n");
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
					    	printf("\n===== CADASTRO DE HÓSPEDE =====\n");
							printf("\nInsira o RG do hóspede: ");
							scanf("%d", &vRG[tlh]);
												    	
							while (vRG[tlh] != vRG[pos] && pos < tlh)
								pos++;
												    	
							if (pos < tlh)
							{
								printf("\nHóspede já cadastrado!\n");
								system("pause");					
							}
							else
							{
								printf("Insira o nome do hóspede: ");
								fflush(stdin);
								gets(vHospede[tlh]);
								printf("\nHóspede %s cadastrado com sucesso!\n", vHospede[tlh]);
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
					    	printf("\n===== CADASTRO DE SERVIÇO =====\n");
						    printf("\nInsira o código do serviço: ");
						    scanf("%d", &vCod[tls]);
						    	
						    while (vCod[tls] != vCod[pos] && pos < tls)
						    	pos++;
						    
						    if (pos < tls)
						    {
						    	printf("\nServiço já cadastrado!\n");
								system("pause");
							}
						    else
						    {
						    	printf("Insira o nome do serviço: ");
								fflush(stdin);
								gets(vServico[tls]);
						    	printf("\nServiço %s cadastrado com sucesso!\n", vServico[tls]);
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
								printf("\n==== ALTERAÇÃO DE CADASTRO ====");
								printf("\n1 ---------------------- QUARTO");
								printf("\n2 -------------------- HÓSPEDES");
								printf("\n3 -------------------- SERVIÇOS");												
								printf("\n4 -------------------- RETORNAR");
								printf("\nInsira a opção desejada:      ");
								scanf("%d", &interno);
								
								if (interno < 1 || interno > 4)
								{
									printf("\nEscolha uma das opções!\n");
									system("pause");
								}
								else	
								if (interno == 1)
								{
							    	limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n======= ALTERAR QUARTO ========\n");
							    	printf("\nInsira o número do quarto a ser alterado: ");
							    	scanf("%d", &antigo);
							    	
							    	while (antigo != vNum[pos] && pos < tlq)
								    	pos++;
								    
								    if (pos < tlq)
								    {
								    	local = pos;
								    	
								    	printf("\nInsira o novo número do quarto: ");
									    scanf("%d", &novo);
									    
									    pos = 0;
									    
									    while (novo != vNum[pos] && pos < tlq)
									    	pos++;
									    
									    if (pos < tlq)
									    {
									    	printf("\nQuarto já existente. Escolha outro número.\n");
											system("pause");	
									    }

									    else
									    {
									    	vNum[local] = novo;
									    	printf("\nO novo número do quarto é %d!\n", vNum[local]);
											system("pause");
									    }
									}
								    else
								    {
								    	printf("\nQuarto NÃO está cadastrado!\n");
										system("pause");	
								    }
							    	
								    pos = 0;
								}
								else
								if (interno == 2)
								{
							    	limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n======= ALTERAR HÓSPEDE =======\n");
									printf("\nInsira o RG do hóspede: ");
									scanf("%d", &opcao);
														    	
									while (opcao != vRG[pos] && pos < tlh)
										pos++;
														    	
									if (pos < tlh)
									{
										printf("\nHóspede %s localizado!\n", vHospede[pos]);
										printf("\nInsira o novo nome do hóspede: ");
										fflush(stdin);
										gets(vHospede[pos]);
										printf("\nNome do hóspede alterado para %s.\n\n", vHospede[pos]);
										system("pause");
									}
									else
									{
										printf("\nHóspede não cadastrado!\n");
										system("pause");
									}
										
									pos = 0;
								}
							    else
								if (interno == 3)
								{
							    	limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n======= ALTERAR SERVIÇO =======\n");
								    printf("\nInsira o código do serviço: ");
								    scanf("%d", &antigo);
								    	
								    while (antigo != vCod[pos] && pos < tls)
								    	pos++;
								    
								    if (pos < tls)
								    {
										printf("\nServiço %s localizado!\n", vServico[pos]);
										printf("\nInsira o novo nome do serviço: ");
										fflush(stdin);
										gets(vServico[pos]);
										printf("\nNome do serviço alterado para %s.\n", vServico[pos]);
										system("pause");
									}
									else
									{
										printf("\nServiço não cadastrado!\n");
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
							printf("\n==== EXCLUSÃO DE CADASTRO =====");
							printf("\n1 ---------------------- QUARTO");
							printf("\n2 -------------------- HÓSPEDES");
							printf("\n3 -------------------- SERVIÇOS");												
							printf("\n4 -------------------- RETORNAR");
							printf("\nInsira a opção desejada:      ");
							scanf("%d", &interno);
							
							if (interno < 1 || interno > 4)
							{
								printf("\nEscolha uma das opções!\n");
								system("pause");
							}
							else	
							if (interno == 1)
							{
						    	limpa_tela();
						    	printf("===== GRAND SIERRA RESORT =====\n");
						    	printf("\n====== EXCLUIR QUARTO =======\n");
						    	printf("\nInsira o número do quarto a ser excluído: ");
						    	scanf("%d", &antigo);
						    	
						    	while (antigo != vNum_R[pos] && pos < tlr)
						    		pos++;
						    	
						    	if (pos < tlr)
						    	{
						    		printf("\nEste quarto está reservado. Não é possível excluir!\n");
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
								    	printf("\nESTA AÇÃO É IRREVERSÍVEL!\nVocê deseja excluir o quarto %d <s/N>? ", vNum[pos]);
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
											printf("\nQuarto EXCLUÍDO com sucesso!\n");
											system("pause");
										}
										else
										{
											printf("\nAÇÃO NÃO REALIZADA! O quarto não foi excluído!\n");
											system("pause");
										}
									}
								    else
								    {
								    	printf("\nQuarto NÃO está cadastrado!\n");
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
						    	printf("\n======= EXCLUIR HÓSPEDE =======\n");
								printf("\nInsira o RG do hóspede: ");
								scanf("%d", &antigo);
								
								while (antigo != vRG_R[pos] && pos < tlr)
									pos++;
								
								if (pos < tlr)
								{
						    		printf("\nEste hóspede possui reserva. Não é possível a exclusão!\n");
						    		system("pause");
								}
								else
						    	{
						    		pos = 0;
						    		
							    	while (antigo != vRG[pos] && pos < tlh)
								    	pos++;
								    
								    if (pos < tlh)
								    {
								    	printf("\nHóspede localizado!\n");
								    	printf("\nESTA AÇÃO É IRREVERSÍVEL!\nVocê deseja excluir o hóspede %s <s/N>? ", vHospede[pos]);
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
											printf("\nHóspede EXCLUÍDO com sucesso!\n");
											system("pause");
										}
										else
										{
											printf("\nAÇÃO NÃO REALIZADA! O hóspede não foi excluído!\n");
											system("pause");
										}
									}
								    else
								    {
								    	printf("\nHóspede NÃO está cadastrado!\n");
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
						    	printf("\n======= EXCLUIR SERVIÇO =======\n");
								printf("\nInsira o código do serviço: ");
								scanf("%d", &antigo);
								
								while (antigo != vCod_L[pos] && pos < tll)
									pos++;
								
								if (pos < tll)
								{
						    		printf("\nEste serviço possui lançamento. Não é possível a exclusão!\n");
						    		system("pause");
								}
								else
						    	{
						    		pos = 0;
						    		
							    	while (antigo != vCod[pos] && pos < tls)
								    	pos++;
								    
								    if (pos < tls)
								    {
								    	printf("\nServiço localizado!\n");
								    	printf("\nESTA AÇÃO É IRREVERSÍVEL!\nVocê deseja excluir o serviço %s <s/N>? ", vServico[pos]);
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
											printf("\nServiço EXCLUÍDO com sucesso!\n");
											system("pause");
										}
										else
										{
											printf("\nAÇÃO NÃO REALIZADA! O serviço não foi excluído!\n");
											system("pause");
										}
									}
								    else
								    {
								    	printf("\nServiço NÃO está cadastrado!\n");
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
						printf("\nNão há hóspede e não há quarto cadastrado.\nEfetue os CADASTROS antes de reservar!\n");
						system("pause");
					}
					else
					if (tlq == 0)
					{
						printf("\nNão há quarto cadastrado.\nEfetue o CADASTRO antes de reservar!\n");
						system("pause");
					}
					else
					if (tlh == 0)
					{
						printf("\nNão há hóspede cadastrado.\nEfetue o CADASTRO antes de reservar!\n");
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
							printf("\nInsira a opção desejada:    : ");
							scanf("%d", &opcao);
							
							if (opcao < 1 || opcao > 4)
							{
								printf("\nEscolha uma das opções!\n");
								system("pause");
							}
							else
							if (opcao == 1)
							{
								limpa_tela();
								printf("===== GRAND SIERRA RESORT =====\n");
							    printf("\n===== INCLUSÃO DE RESERVA =====\n");
								printf("\nInsira o RG do hóspede: ");
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
								    	printf("\nHóspede já possui reserva!Não há possível duas reservas para o mesmo hóspede!");
								    	printf("\nCaso necessário, ALTERE a reserva.\n");
								    	system("pause");
								   	}
								   	else
								   	{												   							
										printf("Insira o número do quarto a ser reservado: ");
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
											   	printf("Insira o valor da diária: ");
											   	scanf("%f", &vValor_R[tlr]);
										   		
										   		cont_reserva++;
										   		vReserva[tlr] = cont_reserva;
										   		
											    printf("\nReserva %d do hóspede RG nº %d efetuada com sucesso!\n", vReserva[tlr], vRG_R[tlr]);
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
									    	printf("\nQuarto não cadastrado!\nCADASTRE o quarto antes de efetuar a reserva!\n");
									    	system("pause");
										}
								    }
								}
								else
								{
								   	printf("\nHóspede não cadastrado!\nCADASTRE o hóspede antes de efetuar a reserva!\n");
								   	system("pause");
								}
								  	
								pos = 0;
							}
							else
							if (opcao == 2)
							{
								limpa_tela();
																		
								printf("===== GRAND SIERRA RESORT =====\n");
						    	printf("\n==== ALTERAÇÃO DE RESERVA =====\n");
							    printf("\nInsira o RG do hóspede: ");
							    scanf("%d", &opcao);
							    	
							    while (opcao != vRG_R[pos] && pos < tlr)
							    	pos++;
								    	
							    if (pos < tlr)
							    {
							    	local = pos;
							    	printf("\nReserva %d do hóspede localizada!\n", vReserva[pos]);
							    	system("pause");
							    	
						    		limpa_tela();
							    	printf("===== GRAND SIERRA RESORT =====\n");
							    	printf("\n===== ALTERAÇÃO DE RESERVA ====\n");
									printf("\n== O que alterar na reserva? ==\n");
									printf("\n1 ------------ NÚMERO DO QUARTO");
									printf("\n2 --- NUMERO DE DIAS DA RESERVA");
									printf("\n3 ------------- VALOR DA DIÁRIA");
									printf("\n4 -------------------- RETORNAR");
									printf("\nInsira a opção desejada:    : ");
									scanf("%d", &opcao);
							
									if (opcao < 1 || opcao > 4)
									{
										printf("\nEscolha uma das opções!\n");
										system("pause");
									}
									else
									if (opcao == 1)
									{	
						    			limpa_tela();						
										printf("===== GRAND SIERRA RESORT =====\n");
							    		printf("\n===== ALTERAÇÃO DE RESERVA ====\n");
							    		printf("\nO hóspede está com reserva no quarto %d.\n", vNum_R[pos]);
							    		
							    		pos2 = 0;
							    		
										while (vNum_R[pos] != vNum[pos2] && pos2 < tlq)
											pos2++;	
										 
								    	printf("\nInsira o número do novo quarto: ");
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
											printf("\nQuarto não cadastrado!\nCADASTRE o quarto antes de alterar a reserva!\n");
									    	system("pause");
										}
									}
									else
									if (opcao == 2)
									{
										limpa_tela();
										printf("===== GRAND SIERRA RESORT =====\n");
							    		printf("\n==== ALTERAÇÃO DE RESERVA =====\n");
								    	printf("\nInsira o novo número de dias da reserva: ");
									   	scanf("%d", &vNumDias_R[local]);
									   	printf("\nNúmero de dias alterado com sucesso!\n");
									   	system("pause");
									}
									else
									if (opcao == 3)
									{
										limpa_tela();
										printf("===== GRAND SIERRA RESORT =====\n");
							    		printf("\n===== ALTERAÇÃO DE RESERVA ======\n");
								    	printf("\nInsira o novo valor da diária: ");
									   	scanf("%f", &vValor_R[local]);
									   	printf("\nValor da diária alterado com sucesso!\n");
									   	system("pause");
									}
									
									pos = 0;							
							    }
							    else
							    {
							    	printf("\nHóspede não possui reserva! Utilize a opção INCLUIR!\n");
							    	system("pause");
							    }
								   	
							   	pos = 0;
							}	
							else
							if (opcao == 3)
							{	
								limpa_tela();					
								printf("===== GRAND SIERRA RESORT =====\n");
							   	printf("\n===== EXCLUSÃO DE RESERVA =====\n");
							    printf("\nInsira o RG do hóspede: ");
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
											printf ("\nNÃO é possível excluir a reserva! Há lançamento(s)!\n");
											system("pause");
										}
										else
										{
											
											pos = 0;
											
											while (vNum_R[localR] != vNum[pos] && pos < tlq)
												pos++;
											
									    	printf("\nReserva localizada!\n");
									    	printf("\nESTA AÇÃO É IRREVERSÍVEL!\nVocê deseja excluir a reserva %d do hóspede %s <s/N>? ", vReserva[localR], vHospede[local]);
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
												
												printf("\nReserva do hóspede %s EXCLUÍDA com sucesso!\n", vHospede[local]);
												system("pause");
											}
											else
											{
												printf("\nAÇÃO NÃO REALIZADA! A reserva NÃO foi cancelada!\n");
												system("pause");
											}
										}
									}
									else
									{
										printf("\nHóspede NÃO possui reserva!\n");
										system("pause");
									}
								}
								else
								{
									printf("\nHóspede NÃO está cadastrado!\n");
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
						printf("\n========= LANÇAMENTO ==========");
						printf("\n1 --------------------- INCLUIR");
						printf("\n2 --------------------- ALTERAR");
						printf("\n3 --------------------- EXCLUIR");
						printf("\n4 -------------------- RETORNAR");
						printf("\nInsira a opção desejada:    : ");
						scanf("%d", &opcao);
						
						if (opcao < 1 || opcao > 4)
						{
							printf("\nEscolha uma opção!\n");
							system("pause");							
						}
						else
						if (opcao == 1)
						{
							limpa_tela();
							
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n=== INCLUSÃO DE LANÇAMENTO ====\n");
							
							printf("\nInsira o código do lançamento: ");
							scanf("%d", &vLancamento[tll]);
							
							while (vLancamento[tll] != vLancamento[pos] && pos < tll)
								pos++;
								
							if (pos < tll)
							{
								printf("\nLançamento já existente.\n");
								system("pause");
							}
							else
							{
								pos = 0;
								
								printf("Insira o código da reserva: ");
								scanf("%d", &vReserva_L[tll]);							
							
								while (vReserva_L[tll] != vReserva[pos] && pos < tlr)
									pos++;
								
								if (pos < tlr)
								{
									pos = 0;
									
									printf("Insira o código do serviço a ser lançado: ");
									scanf("%d", &vCod_L[tll]);
									
									while (vCod_L[tll] != vCod[pos] && pos < tls)
										pos++;
										
									if (pos < tls)
									{
										printf("Insira o valor do lançamento: ");
										scanf("%f", &vValor_L[tll]);
										printf("\nLançamento do serviço %s efetuado com sucesso!\n", vServico[pos]);
										tll++;
										system("pause");
									}
									else
									{
										printf("\nCódigo de serviço inexistente!\n");
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
							printf("\n=== ALTERAÇÃO DE LANÇAMENTO ===\n");
							
							printf("\nInsira o código de lançamento: ");
							scanf("%d", &vLancamento[tll]);
							
							while (vLancamento[tll] != vLancamento[pos] && pos < tll)
								pos++;
							
							if (pos < tll)
							{
								local = pos;
								pos = 0;
								
								limpa_tela();
								
								printf("===== GRAND SIERRA RESORT =====\n");
								printf("\n=== ALTERAÇÃO DE LANÇAMENTO ===\n");
								printf("\nO que alterar no lançamento? ==\n");
								printf("\n1 ------------ NÚMERO DA RESERVA");
								printf("\n2 --------- CÓDIGO DO LANÇAMENTO");
								printf("\n3 ---------- VALOR DO LANÇAMENTO");
								printf("\n4 --------------------- RETORNAR");										
								printf("\nInsira a opção desejada:     : ");
								scanf("%d", &opcao);
									
								if (opcao < 1 || opcao > 4)
								{
									printf("\nOpcão inexistente!\n");
									system("pause");
								}
								else
								if (opcao == 1)
								{
									pos = 0;
									
									printf("\nInsira o novo número da reserva: ");
									scanf("%d", &vReserva_L[tll]);
									
									while (vReserva_L[tll] != vReserva[pos] && pos < tlr)
										pos++;
										
									if (pos < tlr)
									{
										vReserva_L[local] = vReserva_L[tll];
										printf("\nLançamento nº %d alterado para a reserva nº %d.\n", vLancamento[local], vReserva_L[local]);
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
									printf("\nInsira o novo código de lançamento: ");
									scanf("%d", &vLancamento[tll]);
									
									while(vLancamento[tll] != vLancamento[pos] && pos < tll)
										pos++;
									
									if (pos < tll)
									{
										printf("\nLançamento já existente!\n");
										system("pause");
									}
									else
									{
										vLancamento[local] = vLancamento[tll];
										printf("\nLançamento alterado para o nº %d na reserva nº %d.\n", vLancamento[local], vReserva_L[local]);
										system("pause");										
									}
									
									pos = 0;
								}
								else
								if (opcao == 3)
								{
									printf("\nInsira o novo valor do lançamento: ");
									scanf("%f", &vValor_L[local]);
									printf("\nValor do lançamento alterado para R$%0.2f na reserva nº %d.\n", vValor_L[local], vReserva_L[local]);
									system("pause");
									
								}
							}
							else
							{
								printf("\nLançamento não encontrado.\n");
								system("pause");
							}
							
							pos = 0;
						}
						else
						if (opcao == 3)
						{
							limpa_tela();
							
							printf("===== GRAND SIERRA RESORT =====\n");
							printf("\n=== EXCLUSÃO DE LANÇAMENTO ====\n");
							
							printf("\nInsira o código de lançamento: ");
							scanf("%d", &vLancamento[tll]);
							
							while (vLancamento[tll] != vLancamento[pos] && pos < tll)
								pos++;
							
							if (pos < tll)
							{
								printf("\nLançamento localizado!\n");
								printf("\nESTA AÇÃO É IRREVERSÍVEL!\nVocê deseja excluir o lançamento %d da reserva %d <s/N>? ", vLancamento[pos], vReserva_L[pos]);
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
												
									printf("\nLançamento EXCLUÍDO com sucesso!\n");
									system("pause");
								}
								else
								{
									printf("\nAÇÃO NÃO REALIZADA! O lançamento NÃO foi excluído!\n");
									system("pause");									
								}
							}
							else
							{
								printf("\nLançamento não encontrado!\n");
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
						printf("\n========= RELATÓRIOS ==========");
						printf("\n1 ------------ QUARTOS OCUPADOS");
						printf("\n2 ----------- QUARTOS LIBERADOS");
						printf("\n3 -------------------- HÓSPEDES");
						printf("\n4 -------------------- SERVIÇOS");
						printf("\n5 -------------------- RETORNAR");
						printf("\nInsira a opção desejada:    : ");
						scanf("%d", &opcao);
						
						if (opcao < 1 || opcao > 5)
						{
							printf("\nEscolha uma das opções!\n");
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
							printf("\n|| HÓSPEDES CADASTRADOS ||\n");
							for (i = 0; i < tlh; i++)
							{
								printf("RG nº %d - %s\n", vRG[i], vHospede[i]);
							}
							printf("\n");
							system("pause");	
						}
						else
						if (opcao == 4)
						{
							printf("\n|| SERVIÇOS CADASTRADOS ||\n");
							for (i = 0; i < tls; i++)
							{
								printf("Código nº %d - %s\n", vCod[i], vServico[i]);
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
			printf("\nEscolha uma das opções!\n");
			system("pause");			
		}
		
		fflush(stdin);
	} while (menu != 5);
	
	printf("\n======= FIM DO PROGRAMA =======");
}
