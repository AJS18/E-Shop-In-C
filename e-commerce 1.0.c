#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
char numeros[50];
char nome[50];
char email[50]; 
char end[50];
int cpf;
int telefone;
int senha;
int escolhacase;
float total=0; int tenis=0; int sandalia=0; int chinelo=0; int salto=0, tamanco=0, bota=0, sapatilha=0, sapatenis=0, rasteirinha=0, pantufa=0;
float totalT=0; float totalS=0; float totalC=0; float totalSL=0, totalTA=0, totalB=0, totalSAP=0, totalST=0, totalR=0, totalP=0;
char controle;
int main(){
	setlocale(LC_ALL,"Portuguese");
	getName();
	getPhone();
	getEmail();
    getCPF();
	getEnd();
	getPassw();
	execLoja();
	chamaCarrinho();
	FinalizaCompra();
	return 0;
}

void getPhone(){
    printf("Telefone: ");
    fgets(numeros, sizeof(numeros), stdin);
    telefone = sscanf(numeros, "%d",&telefone);
}
void getCPF(){
	printf("CPF: ");
    fgets(numeros, sizeof(numeros), stdin);
    cpf=sscanf(numeros, "%d",&cpf);
}
void getPassw(){
    printf("Senha (apenas números): ");
    fgets(numeros, sizeof(numeros), stdin);
    senha=sscanf(numeros, "%d",&senha);
	
}	
void getName(){
	printf("Nome: ");
	fgets(nome,sizeof(nome),stdin);
}
void getEmail(){
	printf("E-mail: ");
    fgets(email,sizeof(email),stdin); 
}
void getEnd(){
	printf("Endereço: ");
    fgets(end,sizeof(end),stdin);
}
void chamaCarrinho(){
	printf("---------------------------------------Seu carrinho-----------------------------------\n");
	printf("digite 0 pra finalizar a remoção de produtos\n");
	if(tenis > 0){
		printf("1-Tênis(%d) (R$%.2f) /", tenis, totalT);
	};
	if(sandalia > 0){
		printf(" 2-Sandália(%d) (R$%.2f) /", sandalia, totalS);
	};
	if(chinelo > 0){
		printf(" 3-Chinelo(%d) (R$%.2f) /", chinelo, totalC);
	};
	if(salto > 0){
		printf(" 4-Salto(%d) (R$%.2f) /", salto, totalSL);
	};
	if(tamanco > 0){
		printf(" 5-Tamanco(%d) (R$%.2f) /", tamanco, totalTA);
	};
	if(bota > 0){
		printf(" 6-Bota(%d) (R$%.2f) /", bota, totalB);
	};
	if(sapatilha > 0){
		printf(" 7-Sapatilha(%d) (R$%.2f) /", sapatilha, totalSAP);
	};
	if(sapatenis > 0){
		printf("8-Sapatênis(%d) (R$%.2f) /", sapatenis, totalST);
	};
	if(rasteirinha > 0){
		printf(" 9-Rasteirinha(%d) (R$%.2f) /", rasteirinha, totalR);
	};
	if(pantufa > 0){
		printf(" 10-Pantufa(%d) (R$%.2f) /", pantufa, totalP);
	};
	if(pantufa==0 && rasteirinha==0 && sapatenis==0 && sapatilha==0 && bota==0 && tamanco==0 && salto==0 && chinelo==0 && sandalia==0 && tenis==0){
		printf("seu carrinho está vazio \n");
	};
	printf("\n");
	printf("Total gasto = %.2f\n\n",total);
}
void FinalizaCompra(){
	printf("Total gasto = %.2f\n",total);
	printf ("Enviaremos para o endereço %s após a confirmação no e-mail %s\n",end,email);
	system ("pause");
};
void execLoja(){
	while(1){
		printf("Digite a operação: a- Adicionar um produto / r- Remover um produto / s- Sair do programa\n");
			scanf(" %c",&controle);
		if (controle == 's'){
			break;
		}
			addProduto();
			removeProduto();
	}
}
void addProduto(){
	if(controle == 'a'){
				printf ("ADICIONANDO PRODUTO\n\n");
				printf("digite 1- Tênis (R$100,00) / 2- Sandáia (R$200,00) / 3- Chinelo (R$300,00) / 4- Salto (R$400,00) / 5- Tamanco (R$500,00)/ 6- Bota (R$600,00) / 7- Sapatilha (R$700,00) / 8- Sapatêis (R$800,00) / 9- Rasteirinha (R$900,00) / 10- Pantufa (R$1000,00) 0- Sair das compras\n");
				while (1){
				scanf("%d",&escolhacase);
					if (escolhacase == 0){
						break;
					}else{
						switch(escolhacase){
				case 1: tenis+=1; total+=200; totalT+=200; break;
				case 2: sandalia+=1; total+=400; totalS+=400; break;
				case 3: chinelo+=1; total +=300; totalC+=300; break;
				case 4: salto+=1; total+=400; totalSL+=400; break;
				case 5: tamanco+=1; total+=500; totalTA+=500; break;
				case 6: bota+=1; total+=600; totalB+=600; break;
				case 7: sapatilha+=1; total +=700; totalSAP+=700; break;
				case 8: sapatenis+=1; total+=800; totalST+=800; break;
				case 9: rasteirinha+=1; total+=900; totalR+=900; break;
				case 10: pantufa+=1; total+=1000; totalP+=1000; break;
					}
						
					}
					
				}
			}
}
void removeProduto(){
	if (controle == 'r'){
					printf("REMOVENDO PRODUTO\n\n");
					chamaCarrinho();
				while (1){
				scanf("%d",&escolhacase);
					if (escolhacase == 0){
						break;
					}
					switch(escolhacase){
				case 1: if(tenis==0) printf("Não existe item para ser removido\n");
							else tenis-=1; total-=200; totalT-=200; chamaCarrinho(); break;
				case 2: if(sandalia==0) printf("Não existe item para ser removido\n");
							else sandalia-=1; total-=400; totalS-=400; chamaCarrinho(); break;
				case 3: if(chinelo==0) printf("Não existe item para ser removido\n");
							else chinelo-=1; total -=300; totalC-=300; chamaCarrinho(); break;
				case 4: if(salto==0) printf("Não existe item para ser removido\n");
							else salto-=1; total-=400; totalSL-=400; chamaCarrinho(); break;
				case 5: if(tamanco==0) printf("Não existe item para ser removido\n"); 
							else tamanco-=1; total-=500; totalTA-=500; chamaCarrinho(); break;
				case 6: if(bota==0) printf("Não existe item para ser removido\n");
							else bota-=1; total-=600; totalB-=600; chamaCarrinho(); break;
				case 7: if(sapatilha==0) printf("Não existe item para ser removido\n");
							else sapatilha-=1; total -=700; totalSAP-=700; chamaCarrinho(); break;
				case 8: if(sapatenis==0) printf("Não existe item para ser removido\n");
							else sapatenis-=1; total-=800; totalST-=800; chamaCarrinho(); break;
				case 9: if(rasteirinha==0) printf("Não existe item para ser removido\n");
							else rasteirinha-=1; total-=900; totalR-=900; chamaCarrinho(); break;
				case 10: if(pantufa==0) printf("Não existe item para ser removido\n");
							else pantufa-=1; total-=1000; totalP-=1000; chamaCarrinho(); break;			
					}					
				}
				}
}
