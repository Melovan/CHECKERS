
#include <iostream>                  
#include "model.h"
#pragma once

class View {
public:
    View(const Model& model) {
        this->model = model;
    }
    View() {}
    void SetModel(const Model& model) {
        this->model = model;
    }
    void show_board();
    void clear_board();
    void printWinner(int a);
    void print_menu();

    
private:
    Model model;
};