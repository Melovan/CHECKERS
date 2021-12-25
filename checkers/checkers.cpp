#include "controller.h"
int main()
{
	Model checkers;
	View view(checkers);
	Controller game(checkers, view);
	int choice = 0;
	do {

		int choice = 2;
		view.print_menu();
		cin >> choice;

		switch (choice) {
		case 1: {
			view.show_board();
			game.play(0);
			getchar();
			break;
		}
		case 2: {
			view.show_board();
			game.play(1);
			getchar();
			break;

		}
			// Exit
		case 0: break;

			// Error
		default:
			choice = 228;
			break;
		}

		if (choice == 0)
		{
			break;
		}

	} while (1);

	return 0;
}
