#include <Windows.h>
#include "view.h"

void View::show_board() {
    system("CLS");
    std::cout << "\n\n     ";
    for (char i = '1'; i <= '8'; i++) {
        std::cout << "  " << i;
    }
    std::cout << endl;

    for (int i = 1; i < 9; i++) {
        std::cout << "    " << i << ' ';

        for (int j = 1; j < 9; j++) {
            switch (this->model.pos_matrix[i][j])
            {
            case 22:
                std::cout << "*b*";
                break;
            case -22:
                std::cout << "*B*";
                break;
            case 33:
                std::cout << "*w*";
                break;
            case -33:
                std::cout << "*W*";
                break;
            case 2:
                std::cout << " b ";
                break;
            case 3:
                std::cout << " w ";
                break;
            case 1:
                std::cout << "   ";
                break;
            case -2:
                std::cout << " B ";
                break;
            case -3:
                std::cout << " W ";
                break;
            case 5:
                std::cout << " * ";
                break;
            case 6:
                std::cout << " * ";
                break;
            default:
                std::cout << (char)219 << (char)219 << (char)219;
                break;
            }
        }
        std::cout << endl;
    }
    std::cout << "\n\n\n";
}
void View::printWinner(int a) {

    switch (a)
    {
    case 0:
        cout << "White's win!\n";
        break;
    case 1:
        cout << "Black's win!\n";
        break;
    default:
        cout << "Draw!\n";
        break;
    }

    getchar();
    return;
}

void View::print_menu() {
    system("CLS");
    cout << "Checkers" << endl << endl;
    cout << "Please choose an option" << endl;
    cout << "1 - Play Game versus the human!" << endl;
    cout << "2 - Play Game versus the computer!" << endl;
    cout << "0 - Exit." << endl;
    cout << ": ";
}
