#include "view.h"
#pragma once

// Controller combines Model and View
class Controller {
public:
    Controller(const Model& model, const View& view) {
        this->SetModel(model);
        this->SetView(view);
    }
    void SetModel(const Model& model) {
        this->model_contr = model;
    }
    void SetView(const View& view) {
        this->view_contr = view;
    }
    void play(int a);

    void check_possibility_white(int x, int y, bool flag);
    void check_possibility_black(int x, int y, bool flag);
    void check_possibility_white_queen(int x, int y, bool flag);
    void check_possibility_black_queen(int x, int y, bool flag);
    void clear_pos();
    bool check_for_next_white(int x, int y);
    int check_for_next_black(int x, int y);
    void take_black_from_board(int x1, int x2, int y1, int y2);
    void take_white_from_board(int x1, int x2, int y1, int y2);
    bool check_for_next_white_queen(int x, int y);
    int check_for_next_black_queen(int x, int y);
    void winner();
    void comp_turn();
    void queen_turn(int x,int y, bool flag1);
   
private:
    Model model_contr;
    View view_contr;
};