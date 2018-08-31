#include "funcionalidades.h"

link head; //raiz da arvore binaria
Item highest; //ponteiro que vai apontar para o produto com maior numero de unidades
int main() 
{
	init();
	char command=0;
	while (1) {
		command = getchar(); 
		switch (command) {
		case 'a':
			adiciona();
			break;
		case 'l':
			lista();
			break;
		case 'm':
			maior();
			break;
		case 'r':
			retira();
			break;
		case 'x':
			termina();
			return EXIT_SUCCESS;
		default:
			getchar();
		}
	}
return EXIT_FAILURE;
}
































































// SOU BUE DEFICIENTE 
