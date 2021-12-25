#pragma once
#include <string>
using namespace std;
// Model is responsible for data get and set
#define size 10
class Model {
public:
    
    Model() 
    {
        this->SetData();
    }
   
  

    void SetData(){
        white_checks = 12;
        black_checks = 12;
        for (int i = 1; i < size-1; i++) {
            for (int j = 1; j < size-1; j++)
                if (((i % 2 == 0) && (j % 2 != 0)) || ((i % 2 != 0) && (j % 2 == 0)))
                {   
                    if (i < 4)
                        this->pos_matrix[i][j] = 2;
                    else
                    {   
                        if (i >5)
                        this->pos_matrix[i][j] = 3;
                        else
                            this->pos_matrix[i][j] = 1;
                    }
                }
                else
                    this->pos_matrix[i][j] = 0;

        }
        
    }
    int pos_matrix[size][size];
    int white_checks;
    int black_checks;
    
};