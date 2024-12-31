#include <stdio.h>
#include <stdlib.h>
#include "Function.h" 

int main(int argc, char *argv[]) {
	int chooseMenu;
	do{
		displayMainMenu(); 
		scanf("%d", &chooseMenu);
		getchar();
		switch (chooseMenu) {
			case 1:{
				displayStudentsMenu(); 
					break;
				}
			case 2:{
				printf("CommingSoon"); 
				break;
			}
			case 3:{
				printf("CommingSoon"); 
				break;
			}
			case 0:{
				printf("Exit the program");
				break;
			}
			default:
                printf("Invalid selection. Please try again.\n");
			
		}
	}while(chooseMenu !=0);

	return 0;
}
