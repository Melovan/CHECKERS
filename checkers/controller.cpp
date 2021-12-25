#include "controller.h"

void Controller::play(int a) {
	int player = 0;
	while (1)
	{
		if (!this->model_contr.white_checks || !this->model_contr.black_checks)
			break;
		switch (player)
		{
		case 0:
		{	bool flag1 = false;
		bool flag = false;
		this->view_contr.show_board();
		cout << "Player1 choose a check(Y X):";
		int x1, y1;
		cin >> y1 >> x1;
		if (x1 > 8 || y1 > 8 || x1 < 1 || y1 < 1)
			continue;
		if (this->model_contr.pos_matrix[y1][x1] != 3 && this->model_contr.pos_matrix[y1][x1] != -3)
			continue;
		if (this->model_contr.pos_matrix[y1][x1] == 3)
		{
			while (1)
			{

				this->model_contr.pos_matrix[y1][x1] = 33;
				this->check_possibility_white(x1, y1, flag1);
				this->view_contr.SetModel(this->model_contr);
				this->view_contr.show_board();
				cout << "Choose a square(Y,X)(to change check type 11 11):";
				int x2, y2;
				cin >> y2 >> x2;
				if (x2 == 11)
				{
					flag = true;
					this->model_contr.pos_matrix[y1][x1] = 3;
					this->clear_pos();
					this->view_contr.SetModel(this->model_contr);
					break;
				}
				if (this->model_contr.pos_matrix[y2][x2] < 5 || this->model_contr.pos_matrix[y2][x2] > 6)
					continue;
				if (y2 != 1)
				{
					this->model_contr.pos_matrix[y2][x2] = 3;
					if (y2 - y1 < -1 || y2 - y1 > 1) {
						this->model_contr.pos_matrix[y1 + (y2 - y1) / 2][x1 + (x2 - x1) / 2] = 1;
						this->model_contr.black_checks -= 1;
						this->model_contr.pos_matrix[y1][x1] = 1;
						if (this->check_for_next_white(x2, y2))
						{
							x1 = x2; y1 = y2;
							this->clear_pos();
							flag1 = true;
							continue;
						}

					}


				}
				else
				{
					this->model_contr.pos_matrix[y2][x2] = -3;
					if (y2 - y1 < -1 || y2 - y1 > 1) {
						this->model_contr.black_checks -= 1;
						this->model_contr.pos_matrix[y1 + (y2 - y1) / 2][x1 + (x2 - x1) / 2] = 1;
						this->model_contr.pos_matrix[y1][x1] = 1;
						if (this->check_for_next_white(x2, y2))
						{
							x1 = x2; y1 = y2;
							this->clear_pos();
							flag1 = true;
							continue;
						}
					}
				}
				this->model_contr.pos_matrix[y1][x1] = 1;
				this->clear_pos();
				break;


			}
			if (flag)
				continue;
			this->view_contr.SetModel(this->model_contr);
		}
		else
		{
			while (1)
			{

				this->model_contr.pos_matrix[y1][x1] = -33;
				this->check_possibility_white_queen(x1, y1, flag1);
				this->view_contr.SetModel(this->model_contr);
				this->view_contr.show_board();
				cout << "Choose a square(Y,X)(to change check type 11 11):";
				int x2, y2;
				cin >> y2 >> x2;
				if (x2 == 11)
				{
					flag = true;
					this->model_contr.pos_matrix[y1][x1] = -3;
					this->clear_pos();
					this->view_contr.SetModel(this->model_contr);
					break;
				}
				if (this->model_contr.pos_matrix[y2][x2] < 5 || this->model_contr.pos_matrix[y2][x2] > 6)
					continue;
				this->model_contr.pos_matrix[y2][x2] = -3;
				if (y2 - y1 < -1 || y2 - y1 > 1) {
					this->take_black_from_board(x1, x2, y1, y2);
					this->model_contr.pos_matrix[y1][x1] = 1;
					if (this->check_for_next_white_queen(x2, y2))
					{
						x1 = x2; y1 = y2;
						this->clear_pos();
						flag1 = true;
						continue;
					}
					break;

				}


			}
			this->model_contr.pos_matrix[y1][x1] = 1;
			this->clear_pos();
			this->view_contr.SetModel(this->model_contr);
			break;

		}
		if (flag)
			continue;
		this->view_contr.SetModel(this->model_contr);
		break;

		}
		case 1:
		{
			if (!a)
			{

				bool flag1 = false;
				bool flag = false;
				this->view_contr.show_board();
				cout << "Player2 choose a check(Y X):";
				int x1, y1;
				cin >> y1 >> x1;
				if (x1 > 8 || y1 > 8 || x1 < 1 || y1 < 1)
					continue;
				if (this->model_contr.pos_matrix[y1][x1] != 2 && this->model_contr.pos_matrix[y1][x1] != -2)
					continue;
				if (this->model_contr.pos_matrix[y1][x1] == 2)
				{
					while (1)
					{
						this->model_contr.pos_matrix[y1][x1] = 22;
						this->check_possibility_black(x1, y1, flag1);
						this->view_contr.SetModel(this->model_contr);
						this->view_contr.show_board();
						cout << "Choose a square(Y,X)(to change check type 11 11):";
						int x2, y2;
						cin >> y2 >> x2;
						if (x2 == 11)
						{
							flag = true;
							this->model_contr.pos_matrix[y1][x1] = 2;
							this->clear_pos();
							this->view_contr.SetModel(this->model_contr);
							break;
						}
						if (this->model_contr.pos_matrix[y2][x2] < 5 || this->model_contr.pos_matrix[y2][x2] > 6)
							continue;
						if (y2 != 8)
						{
							this->model_contr.pos_matrix[y2][x2] = 2;
							if (y2 - y1 < -1 || y2 - y1 > 1)
							{
								this->model_contr.pos_matrix[y1 + (y2 - y1) / 2][x1 + (x2 - x1) / 2] = 1;
								this->model_contr.white_checks -= 1;
								this->model_contr.pos_matrix[y1][x1] = 1;

								if (this->check_for_next_black(x2, y2))
								{
									x1 = x2; y1 = y2;
									this->clear_pos();
									flag1 = true;
									continue;
								}
							}

						}
						else
						{
							this->model_contr.pos_matrix[y2][x2] = -2;
							if (y2 - y1 < -1 || y2 - y1 > 1) {
								this->model_contr.pos_matrix[y1 + (y2 - y1) / 2][x1 + (x2 - x1) / 2] = 1;
								this->model_contr.white_checks -= 1;
								this->model_contr.pos_matrix[y1][x1] = 1;
								if (this->check_for_next_black(x2, y2))
								{
									x1 = x2; y1 = y2;
									this->clear_pos();
									flag1 = true;
									continue;
								}
							}
						}
						this->model_contr.pos_matrix[y1][x1] = 1;
						this->clear_pos();
						break;
					}

				}
				else
				{

					while (1)
					{
						this->model_contr.pos_matrix[y1][x1] = -22;
						this->check_possibility_black_queen(x1, y1, flag1);
						this->view_contr.SetModel(this->model_contr);
						this->view_contr.show_board();
						cout << "Choose a square(Y,X)(to change check type 11 11):";
						int x2, y2;
						cin >> y2 >> x2;
						if (x2 == 11)
						{
							flag = true;
							this->model_contr.pos_matrix[y1][x1] = -2;
							this->clear_pos();
							this->view_contr.SetModel(this->model_contr);
							break;
						}
						if (this->model_contr.pos_matrix[y2][x2] < 5 || this->model_contr.pos_matrix[y2][x2] > 6)
							continue;
						this->model_contr.pos_matrix[y2][x2] = -2;
						if (y2 - y1 < -1 || y2 - y1 > 1) {
							this->take_white_from_board(x1, x2, y1, y2);
							this->model_contr.pos_matrix[y1][x1] = 1;
							if (this->check_for_next_black_queen(x2, y2))
							{
								x1 = x2; y1 = y2;
								this->clear_pos();
								flag1 = true;
								continue;
							}
							break;
						}


					}
					this->model_contr.pos_matrix[y1][x1] = 1;
					this->clear_pos();
					this->view_contr.SetModel(this->model_contr);
					break;


				}
				if (flag)
					continue;
				this->view_contr.SetModel(this->model_contr);
				break;
			}
			else
			{
				this->view_contr.show_board();
				this->comp_turn();
				this->view_contr.SetModel(this->model_contr);
				break;
			}
			
		}
		default:
			break;
		}

		if (!player)
			player = 1;
		else
			player = 0;
	}
	
	this->winner();
	
}
void Controller::comp_turn()
{
	bool flag = false;
	for (int j = 1; j < 9; j++)
	{
		if (this->model_contr.pos_matrix[6][j] == 2)
		{
			bool flag1 = true;
				int x = j, y = 6;
				this->check_possibility_black(x, y, flag1);
				if (this->model_contr.pos_matrix[y + 2][x - 2] == 6)
				{
					this->model_contr.pos_matrix[y + 1][x - 1] = 1;
						this->model_contr.pos_matrix[y][x] = 1;
						this->model_contr.white_checks--;
						this->model_contr.pos_matrix[y + 2][x - 2] = -2;
						this->clear_pos();
					x = x - 2;
					y = y + 2;
					queen_turn(x, y, flag1);
					this->view_contr.SetModel(this->model_contr);
					return;
				}
			if (this->model_contr.pos_matrix[y + 2][x + 2] == 6)
			{
				this->model_contr.pos_matrix[y + 1][x + 1] = 1;
				this->model_contr.pos_matrix[y][x] = 1;
				this->model_contr.white_checks--;
				this->model_contr.pos_matrix[y + 2][x + 2] = -2;
				this->clear_pos();
				x = x - 2;
				y = y + 2;
				queen_turn(x, y, flag1);
				this->view_contr.SetModel(this->model_contr);
				return;
			}
		}
	}
	for (int j = 1; j < 9; j++)
	{
		if (this->model_contr.pos_matrix[7][j] == 2)
		{
			bool flag1 = false;
			int x = j, y = 7;
			this->check_possibility_black(x, y, flag1);
			if (this->model_contr.pos_matrix[y + 1][x - 1] == 5)
			{
				this->model_contr.pos_matrix[y][x] = 1;
				this->model_contr.pos_matrix[y + 1][x - 1] = -2;
				this->clear_pos();
				this->view_contr.SetModel(this->model_contr);
				return;
			}
			if (this->model_contr.pos_matrix[y + 1][x + 1] == 6)
			{
				this->model_contr.pos_matrix[y][x] = 1;
				this->model_contr.pos_matrix[y + 1][x + 1] = -2;
				this->clear_pos();
				this->view_contr.SetModel(this->model_contr);
				return;
			}
		}
		flag = false;
		for (int i = 1; i < 9; i++)
			for (int j = 1; j < 9; j++)
			{
				int x = j,  y = i;
				if (this->model_contr.pos_matrix[y][x] == 2)
				{
					while (check_for_next_black(x, y))
						switch (this->check_for_next_black(x, y))
						{
						case 1://up right
						{
							this->model_contr.pos_matrix[y][x] = 1;
							this->model_contr.pos_matrix[y - 1][x + 1] = 1;
							this->model_contr.pos_matrix[y - 2][x + 2] = 2;
							this->model_contr.white_checks--;
							x = x + 2; y = y - 2;
							flag = true;
							break;
						}
						case 2://down right
						{
							this->model_contr.pos_matrix[y][x] = 1;
							this->model_contr.pos_matrix[y + 1][x + 1] = 1;
							this->model_contr.pos_matrix[y + 2][x + 2] = 2;
							this->model_contr.white_checks--;
							x = x + 2; y = y + 2;
							flag = true;
							break;
						}
						case 3://up left
						{
							this->model_contr.pos_matrix[y][x] = 1;
							this->model_contr.pos_matrix[y - 1][x - 1] = 1;
							this->model_contr.pos_matrix[y - 2][x - 2] = 2;
							this->model_contr.white_checks--;
							x = x - 2; y = y - 2;
							flag = true;
							break;
						}
						case 4://down left
						{
							this->model_contr.pos_matrix[y][x] = 1;
							this->model_contr.pos_matrix[y + 1][x - 1] = 1;
							this->model_contr.pos_matrix[y + 2][x - 2] = 2;
							this->model_contr.white_checks--;
							x = x - 2; y = y + 2;
							flag = true;
							break;
						}
						default:
							break;
						}
					if (flag)
						return;
				}
				
				if (this->model_contr.pos_matrix[y][x] == -2)
				{
					
					while (check_for_next_black_queen(x, y))
					{	
						int x1 = 0, y1 = 0;
						switch (this->check_for_next_black_queen(x, y))
						{
						case 1://up left diag
						{
							x1 = x;
							y1 = y;
							this -> check_possibility_black_queen(x, y, true);
							this->model_contr.pos_matrix[y][x] = 1;
							while (this->model_contr.pos_matrix[y1][x1] != 6)
							{
								x1--; y1--;
							}
							this->model_contr.pos_matrix[y1][x1] = -2;
							this->take_white_from_board(x, x1, y, y1);
							x = x1; y =y1;
							flag = true;
							this->clear_pos();
							break;
						}
						case 2://up right diag
						{
							x1 = x;
							y1 = y;
							this->check_possibility_black_queen(x, y, true);
							this->model_contr.pos_matrix[y][x] = 1;
							while (this->model_contr.pos_matrix[y1][x1] != 6)
							{
								x1++; y1--;
							}
							this->model_contr.pos_matrix[y1][x1] = -2;
							this->take_white_from_board(x, x1, y, y1);
							x = x1; y = y1;
							flag = true;
							this->clear_pos();
							break;
						}
						case 3://down left diag
						{
							x1 = x;
							y1 = y;
							this->check_possibility_black_queen(x, y, true);
							this->model_contr.pos_matrix[y][x] = 1;
							while (this->model_contr.pos_matrix[y1][x1] != 6)
							{
								x1--; y1--;
							}
							this->model_contr.pos_matrix[y1][x1] = -2;
							this->take_white_from_board(x, x1, y, y1);
							x = x1; y = y1;
							flag = true;
							this->clear_pos();
							break;
						}
						case 4://down right diag
						{
							x1 = x;
							y1 = y;
							this->check_possibility_black_queen(x, y, true);
							this->model_contr.pos_matrix[y][x] = 1;
							while (this->model_contr.pos_matrix[y1][x1] != 6)
							{
								x1++; y1++;
							}
							this->model_contr.pos_matrix[y1][x1] = -2;
							this->take_white_from_board(x, x1, y, y1);
							x = x1; y = y1;
							flag = true;
							this->clear_pos();
							break;
						}
						default:
							break;
						}
					}
					if (flag)
						return;

				}

			}
			for(int i = 8 ; i>0; i--)
				for (int j = 8; j > 0; j--)
				{
					if (this->model_contr.pos_matrix[i][j] == 2)
					{
						if (this->model_contr.pos_matrix[i + 1][j + 1] == 1)
						{
							this->model_contr.pos_matrix[i + 1][j + 1] = 2;
							this->model_contr.pos_matrix[i][j] = 1;
							return;
						}
						if (this->model_contr.pos_matrix[i + 1][j - 1] == 1)
						{
							this->model_contr.pos_matrix[i + 1][j - 1] = 2;
							this->model_contr.pos_matrix[i][j] = 1;
							return;
						}
					}
					if (this->model_contr.pos_matrix[i][j] == -2)
					{
						if (this->model_contr.pos_matrix[i + 1][j + 1] == 1)
						{
							this->model_contr.pos_matrix[i + 1][j + 1] = 2;
							this->model_contr.pos_matrix[i][j] = 1;
							return;
						}
						if (this->model_contr.pos_matrix[i + 1][j - 1] == 1)
						{
							this->model_contr.pos_matrix[i + 1][j - 1] = 2;
							this->model_contr.pos_matrix[i][j] = 1;
							return;
						}
						if (this->model_contr.pos_matrix[i - 1][j + 1] == 1)
						{
							this->model_contr.pos_matrix[i + 1][j + 1] = 2;
							this->model_contr.pos_matrix[i][j] = 1;
							return;
						}
						if (this->model_contr.pos_matrix[i - 1][j - 1] == 1)
						{
							this->model_contr.pos_matrix[i + 1][j - 1] = 2;
							this->model_contr.pos_matrix[i][j] = 1;
							return;
						}
					}
				}
	}
	this->view_contr.SetModel(this->model_contr);
}
void Controller::check_possibility_white(int x, int y,bool flag) {
	switch (x)
	{
	case 1:
			if (this->model_contr.pos_matrix[y - 1][x + 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
				if (this->model_contr.pos_matrix[y - 2][x + 2] == 1)
					this->model_contr.pos_matrix[y - 2][x + 2] = 6;
				else;
			else
				if (this->model_contr.pos_matrix[y - 1][x + 1] == 1)
					if (!flag)
						this->model_contr.pos_matrix[y - 1][x + 1] = 5;

			if (this->model_contr.pos_matrix[y + 1][x + 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
				if (this->model_contr.pos_matrix[y + 2][x + 2] == 1)
					this->model_contr.pos_matrix[y + 2][x + 2] = 6;
			break;
	case 8:
		if (this->model_contr.pos_matrix[y - 1][x - 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
			if (this->model_contr.pos_matrix[y - 2][x - 2] == 1)
				this->model_contr.pos_matrix[y - 2][x - 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y - 1][x - 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y - 1][x - 1] = 5;

		if (this->model_contr.pos_matrix[y + 1][x - 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
			if (this->model_contr.pos_matrix[y + 2][x - 2] == 1)
				this->model_contr.pos_matrix[y + 2][x - 2] = 6;
		break;

	default:
		if (this->model_contr.pos_matrix[y - 1][x + 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
			if (this->model_contr.pos_matrix[y - 2][x + 2] == 1)
				this->model_contr.pos_matrix[y - 2][x + 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y - 1][x + 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y - 1][x + 1] = 5;

		if (this->model_contr.pos_matrix[y + 1][x + 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
			if (this->model_contr.pos_matrix[y + 2][x + 2] == 1)
				this->model_contr.pos_matrix[y + 2][x + 2] = 6;

		if (this->model_contr.pos_matrix[y - 1][x - 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
			if (this->model_contr.pos_matrix[y - 2][x - 2] == 1)
				this->model_contr.pos_matrix[y - 2][x - 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y - 1][x - 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y - 1][x - 1] = 5;

		if (this->model_contr.pos_matrix[y + 1][x - 1] == 2 || this->model_contr.pos_matrix[y - 1][x + 1] == -2)
			if (this->model_contr.pos_matrix[y + 2][x - 2] == 1)
				this->model_contr.pos_matrix[y + 2][x - 2] = 6;
		break;
	}
}
void Controller::check_possibility_black(int x, int y, bool flag) {
	switch (x)
	{
	case 1:
		if (this->model_contr.pos_matrix[y + 1][x + 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y + 2][x + 2] == 1)
				this->model_contr.pos_matrix[y + 2][x + 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y + 1][x + 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y + 1][x + 1] = 5;

		if (this->model_contr.pos_matrix[y - 1][x + 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y - 2][x + 2] == 1)
				this->model_contr.pos_matrix[y - 2][x + 2] = 6;
		break;
		
	case 8:
		if (this->model_contr.pos_matrix[y + 1][x - 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y + 2][x - 2] == 1)
				this->model_contr.pos_matrix[y + 2][x - 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y + 1][x - 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y + 1][x - 1] = 5;

		if (this->model_contr.pos_matrix[y - 1][x - 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y - 2][x - 2] == 1)
				this->model_contr.pos_matrix[y - 2][x - 2] = 6;
		break;

	default:
		if (this->model_contr.pos_matrix[y + 1][x + 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y + 2][x + 2] == 1)
				this->model_contr.pos_matrix[y + 2][x + 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y + 1][x + 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y + 1][x + 1] = 5;

		if (this->model_contr.pos_matrix[y - 1 ][x + 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y - 2][x + 2] == 1)
				this->model_contr.pos_matrix[y - 2][x + 2] = 6;

		if (this->model_contr.pos_matrix[y + 1][x - 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y + 2][x - 2] == 1)
				this->model_contr.pos_matrix[y + 2][x - 2] = 6;
			else;
		else
			if (this->model_contr.pos_matrix[y + 1][x - 1] == 1)
				if (!flag)
					this->model_contr.pos_matrix[y + 1][x - 1] = 5;

		if (this->model_contr.pos_matrix[y - 1][x - 1] == 3 || this->model_contr.pos_matrix[y - 1][x + 1] == -3)
			if (this->model_contr.pos_matrix[y - 2][x - 2] == 1)
				this->model_contr.pos_matrix[y - 2][x - 2] = 6;
		break;
	}
}
void Controller::clear_pos()
{
	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (this->model_contr.pos_matrix[i][j] == 5 || this->model_contr.pos_matrix[i][j] == 6)
				this->model_contr.pos_matrix[i][j] = 1;
		}
	}
}

bool Controller::check_for_next_white(int x, int y)
{
	if (this->model_contr.pos_matrix[y - 1][x + 1] == 2)
		if (this->model_contr.pos_matrix[y - 2][x + 2] == 1)
			return true;

	if (this->model_contr.pos_matrix[y + 1][x + 1] == 2)
		if (this->model_contr.pos_matrix[y + 2][x + 2] == 1)
			return true;

	if (this->model_contr.pos_matrix[y - 1][x - 1] == 2)
		if (this->model_contr.pos_matrix[y - 2][x - 2] == 1)
			return true;
	if (this->model_contr.pos_matrix[y + 1][x - 1] == 2)
		if (this->model_contr.pos_matrix[y + 2][x - 2] == 1)
			return true;
	return false;
}
int Controller::check_for_next_black(int x, int y)
{
	if (this->model_contr.pos_matrix[y - 1][x + 1] == 3)
		if (this->model_contr.pos_matrix[y - 2][x + 2] == 1)
			return 1;

	if (this->model_contr.pos_matrix[y + 1][x + 1] == 3)
		if (this->model_contr.pos_matrix[y + 2][x + 2] == 1)
			return 2;

	if (this->model_contr.pos_matrix[y - 1][x - 1] == 3)
		if (this->model_contr.pos_matrix[y - 2][x - 2] == 1)
			return 3;
	if (this->model_contr.pos_matrix[y + 1][x - 1] == 3)
		if (this->model_contr.pos_matrix[y + 2][x - 2] == 1)
			return 4;
	return 0;

}
void Controller::check_possibility_white_queen(int x, int y, bool flag)
{
	bool flag1 = false;
	int right = x;
	int left = x;
	int j = y;
	while (left > 0 && j > 0)
	{
		left--; j--;
		if ((this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2) && this->model_contr.pos_matrix[j + 1][left + 1] != -33 && this->model_contr.pos_matrix[j + 1][left + 1]  != 5 && this->model_contr.pos_matrix[j + 1][left + 1] !=6)
			break;

		if (this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3)
			break;

		if ((this->model_contr.pos_matrix[j + 1][left + 1] == 2 || this->model_contr.pos_matrix[j + 1][left + 1] == -2) && this->model_contr.pos_matrix[j][left] == 1 )
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][left] = 6;
		}

		if (this->model_contr.pos_matrix[j][left] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][left] = 6;
			else
				if (!flag)
					this->model_contr.pos_matrix[j][left] = 5;
	}
	 j = y; flag1 = false;
	while (j > 0 && right < 9)
	{
		right++; j--;
		if ((this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2) && this->model_contr.pos_matrix[j + 1][right - 1] != -33 && this->model_contr.pos_matrix[j + 1][right - 1] != 5 && this->model_contr.pos_matrix[j + 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3)
			break;
		if ((this->model_contr.pos_matrix[j + 1][right - 1] == 2 || this->model_contr.pos_matrix[j + 1][right - 1] == -2) && this->model_contr.pos_matrix[j][right] == 1)
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][right] = 6;

		}
		if (this->model_contr.pos_matrix[j][right] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][right] = 6;
			else
				if (!flag)
					this->model_contr.pos_matrix[j][right] = 5;
	}
	 right = x;
	 left = x;
	 j = y; flag1 = false;
	while (left > 0 && j < 9)
	{
		left--;  j++;
		if ((this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2) && this->model_contr.pos_matrix[j - 1][left + 1] != 5 && this->model_contr.pos_matrix[j - 1][left + 1] != -33 && this->model_contr.pos_matrix[j - 1][left + 1] != 6)
			break;

		if (this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3)
			break;

		if ((this->model_contr.pos_matrix[j - 1][left + 1] == 2 || this->model_contr.pos_matrix[j - 1][left + 1] == -2) && this->model_contr.pos_matrix[j][left] == 1)
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][left] = 6;
		}

		if (this->model_contr.pos_matrix[j][left] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][left] = 6;
			else
				if(!flag)
					this->model_contr.pos_matrix[j][left] = 5;
	}
	 j = y; flag1 = false;
	while (j < 9 && right < 9)
	{
		right++; j++;
		if ((this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2) && this->model_contr.pos_matrix[j - 1][right - 1] != -33 && this->model_contr.pos_matrix[j - 1][right - 1] != 5 && this->model_contr.pos_matrix[j - 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3)
			break;
		if ((this->model_contr.pos_matrix[j - 1][right - 1] == 2 || this->model_contr.pos_matrix[j - 1][right - 1] == -2) && this->model_contr.pos_matrix[j][right] == 1)
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][right] = 6;
		}
		if (this->model_contr.pos_matrix[j][right] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][right] = 6;
			else
				if(!flag)
					this->model_contr.pos_matrix[j][right] = 5;

	}
}
void Controller::check_possibility_black_queen(int x, int y, bool flag)
{
	bool flag1 = false;
	int right = x;
	int left = x;
	int j = y;
	while (left > 0 && j > 0)
	{
		left--; j--;
		if ((this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3) && this->model_contr.pos_matrix[j + 1][left + 1] != -22 && this->model_contr.pos_matrix[j + 1][left + 1] != 5 && this->model_contr.pos_matrix[j + 1][left + 1] != 6)
			break;
		
		if (this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2)
			break;
		
		if ((this->model_contr.pos_matrix[j + 1][left + 1] == 3 || this->model_contr.pos_matrix[j + 1][left + 1] == -3) && this->model_contr.pos_matrix[j][left] == 1)
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][left] = 6;
		}
		
		if (this->model_contr.pos_matrix[j][left] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][left] = 6;
			else
				if(!flag)
					this->model_contr.pos_matrix[j][left] = 5;
	}
	 j = y; flag1 = false;
	while (j > 0 && right < 9)
	{
		right++; j--;
		if ((this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3) && this->model_contr.pos_matrix[j + 1][right - 1] != -22 && this->model_contr.pos_matrix[j + 1][right - 1] != 5 && this->model_contr.pos_matrix[j + 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2)
			break;
		if ((this->model_contr.pos_matrix[j + 1][right - 1] == 3 || this->model_contr.pos_matrix[j + 1][right - 1] == -3) && this->model_contr.pos_matrix[j][right] == 1)
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][right] = 6;

		}
		if (this->model_contr.pos_matrix[j][right] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][right] = 6;
			else
				if(!flag)
					this->model_contr.pos_matrix[j][right] = 5;
	}
	 right = x;
	 left = x;
	 j = y; flag1 = false;
	while (left > 0 && j < 9)
	{
		left--;  j++;
		if ((this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3) && this->model_contr.pos_matrix[j - 1][left + 1] != -22 && this->model_contr.pos_matrix[j - 1][left + 1] != 5 && this->model_contr.pos_matrix[j - 1][left + 1] != 6)
			break;
		
		if (this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2)
			break;
		
		if ((this->model_contr.pos_matrix[j - 1][left + 1] == 3 || this->model_contr.pos_matrix[j - 1][left + 1] == -3) && this->model_contr.pos_matrix[j][left] == 1)
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][left] = 6;
		}
		
		if (this->model_contr.pos_matrix[j][left] == 1)
			if (flag1)
				this->model_contr.pos_matrix[j][left] = 6;
			else
				if(!flag)
					this->model_contr.pos_matrix[j][left] = 5;
	}
	 j = y; flag1 = false;
	while (j < 9 && right < 9)
	{
		right++; j++;
		if ((this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3) && this->model_contr.pos_matrix[j - 1][right - 1] != -22 && this->model_contr.pos_matrix[j - 1][right - 1] != 5 && this->model_contr.pos_matrix[j - 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2)
			break;
		if ((this->model_contr.pos_matrix[j - 1][right - 1] == 3 || this->model_contr.pos_matrix[j - 1][right - 1] == -3) && this->model_contr.pos_matrix[j][right] == 1 )
		{
			flag1 = true;
			this->model_contr.pos_matrix[j][right] = 6;
		}
		if (this->model_contr.pos_matrix[j][right] == 1) 
			if (flag1)
				this->model_contr.pos_matrix[j][right] = 6;
			else
				if(!flag)
					this->model_contr.pos_matrix[j][right] = 5;

	}
}
void Controller::take_black_from_board(int x1, int x2, int y1, int y2)
{
	if (y1 > y2)
		if (x1>x2)
			while (y1>y2 && x1>x2)
			{
				y1--; x1--;
				if (this->model_contr.pos_matrix[y1][x1] == 2 || this->model_contr.pos_matrix[y1][x1] == -2)
				{
					this->model_contr.black_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
		else
			while (y1 > y2 && x1 < x2)
			{
				y1--; x1++;
				if (this->model_contr.pos_matrix[y1][x1] == 2 || this->model_contr.pos_matrix[y1][x1] == -2)
				{
					this->model_contr.black_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
	else
	{
		if (x1 > x2)
			while (y1 < y2 && x1 > x2)
			{
				y1++; x1--;
				if (this->model_contr.pos_matrix[y1][x1] == 2 || this->model_contr.pos_matrix[y1][x1] == -2)
				{
					this->model_contr.black_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
		else
			while (y1 < y2 && x1 < x2)
			{
				y1++; x1++;
				if (this->model_contr.pos_matrix[y1][x1] == 2 || this->model_contr.pos_matrix[y1][x1] == -2)
				{
					this->model_contr.black_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
	}

}
void Controller::take_white_from_board(int x1, int x2, int y1, int y2)
{
	if (y1 > y2)
		if (x1 > x2)
			while (y1 > y2 && x1 > x2)
			{
				y1--; x1--;
				if (this->model_contr.pos_matrix[y1][x1] == 3 || this->model_contr.pos_matrix[y1][x1] == -3)
				{
					this->model_contr.white_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
		else
			while (y1 > y2 && x1 < x2)
			{
				y1--; x1++;
				if (this->model_contr.pos_matrix[y1][x1] == 3 || this->model_contr.pos_matrix[y1][x1] == -3)
				{
					this->model_contr.white_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
	else
	{
		if (x1 > x2)
			while (y1 < y2 && x1 > x2)
			{
				y1++; x1--;
				if (this->model_contr.pos_matrix[y1][x1] == 3 || this->model_contr.pos_matrix[y1][x1] == -3)
				{
					this->model_contr.white_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
		else
			while (y1 < y2 && x1 < x2)
			{
				y1++; x1++;
				if (this->model_contr.pos_matrix[y1][x1] == 3 || this->model_contr.pos_matrix[y1][x1] == -3)
				{
					this->model_contr.white_checks--;
					this->model_contr.pos_matrix[y1][x1] = 1;
				}

			}
	}

}
bool Controller::check_for_next_white_queen(int x, int y)
{
	int right = x;
	int left = x;
	int j = y;
	while (left > 0 && j > 0)
	{
		left--; j--;
		if ((this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2) && this->model_contr.pos_matrix[j - 1][left + 1] != -3 && this->model_contr.pos_matrix[j + 1][left + 1] != 5 && this->model_contr.pos_matrix[j + 1][left + 1] != 6)
			break;

		if (this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3)
			break;

		if ((this->model_contr.pos_matrix[j + 1][left + 1] == 2 || this->model_contr.pos_matrix[j + 1][left + 1] == -2) && this->model_contr.pos_matrix[j][left] == 1)
			return true;
	}
	j = y;
	while (j > 0 && right < 9)
	{
		right++; j--;
		if ((this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2) && this->model_contr.pos_matrix[j - 1][left + 1] != -3 && this->model_contr.pos_matrix[j + 1][right - 1] != 5 && this->model_contr.pos_matrix[j + 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3)
			break;
		if ((this->model_contr.pos_matrix[j + 1][right - 1] == 2 || this->model_contr.pos_matrix[j + 1][right - 1] == -2) && this->model_contr.pos_matrix[j][right] == 1)
			return true;
	}
	right = x;
	left = x;
	j = y; 
	while (left > 0 && j < 9)
	{
		left--;  j++;
		if ((this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2) && this->model_contr.pos_matrix[j - 1][left + 1] != -3 && this->model_contr.pos_matrix[j - 1][left + 1] != 5 && this->model_contr.pos_matrix[j - 1][left + 1] != 6)
			break;

		if (this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3)
			break;

		if ((this->model_contr.pos_matrix[j - 1][left + 1] == 2 || this->model_contr.pos_matrix[j - 1][left + 1] == -2) && this->model_contr.pos_matrix[j][left] == 1)
			return true;
	}
	j = y;
	while (j < 9 && right < 9)
	{
		right++; j++;
		if ((this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2) && this->model_contr.pos_matrix[j - 1][left + 1] != -3 && this->model_contr.pos_matrix[j - 1][right - 1] != 5 && this->model_contr.pos_matrix[j - 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3)
			break;
		if ((this->model_contr.pos_matrix[j - 1][right - 1] == 2 || this->model_contr.pos_matrix[j - 1][right - 1] == -2) && this->model_contr.pos_matrix[j][right] == 1)
			return true;
	}
	return false;
}
int Controller::check_for_next_black_queen(int x, int y)
{
	int right = x;
	int left = x;
	int j = y;
	while (left > 0 && j > 0)
	{
		left--; j--;
		if ((this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3) && this->model_contr.pos_matrix[j + 1][left + 1] != -2 && this->model_contr.pos_matrix[j + 1][left + 1] != 5 && this->model_contr.pos_matrix[j + 1][left + 1] != 6)
			break;

		if (this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2)
			break;

		if ((this->model_contr.pos_matrix[j + 1][left + 1] == 3 || this->model_contr.pos_matrix[j + 1][left + 1] == -3) && this->model_contr.pos_matrix[j][left] == 1)
			return 1;
	}
	j = y;
	while (j > 0 && right < 9)
	{
		right++; j--;
		if ((this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3) && this->model_contr.pos_matrix[j + 1][right -1] != -2 && this->model_contr.pos_matrix[j + 1][right - 1] != 5 && this->model_contr.pos_matrix[j + 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2)
			break;
		if ((this->model_contr.pos_matrix[j + 1][right - 1] == 3 || this->model_contr.pos_matrix[j + 1][right - 1] == -3) && this->model_contr.pos_matrix[j][right] == 1)
			return 2;
	}
	right = x;
	left = x;
	j = y;
	while (left > 0 && j < 9)
	{
		left--;  j++;
		if ((this->model_contr.pos_matrix[j][left] == 3 || this->model_contr.pos_matrix[j][left] == -3) && this->model_contr.pos_matrix[j - 1][left + 1] != -2 && this->model_contr.pos_matrix[j - 1][left + 1] != 5 && this->model_contr.pos_matrix[j - 1][left + 1] != 6)
			break;

		if (this->model_contr.pos_matrix[j][left] == 2 || this->model_contr.pos_matrix[j][left] == -2)
			break;

		if ((this->model_contr.pos_matrix[j - 1][left + 1] == 3 || this->model_contr.pos_matrix[j - 1][left + 1] == -3) && this->model_contr.pos_matrix[j][left] == 1)
			return 3;
	}
	j = y;
	while (j < 9 && right < 9)
	{
		right++; j++;
		if ((this->model_contr.pos_matrix[j][right] == 3 || this->model_contr.pos_matrix[j][right] == -3) && this->model_contr.pos_matrix[j - 1][right - 1] != -2 && this->model_contr.pos_matrix[j - 1][right - 1] != 5 && this->model_contr.pos_matrix[j - 1][right - 1] != 6)
			break;
		if (this->model_contr.pos_matrix[j][right] == 2 || this->model_contr.pos_matrix[j][right] == -2)
			break;
		if ((this->model_contr.pos_matrix[j - 1][right - 1] == 3 || this->model_contr.pos_matrix[j - 1][right - 1] == -3) && this->model_contr.pos_matrix[j][right] == 1)
			return 4;
	}
	return 0;
}
void Controller::winner()
{
	this->view_contr.SetModel(this->model_contr);
	this->view_contr.show_board();

	if (this->model_contr.white_checks > 0) {
		this->view_contr.printWinner(0);
	}
	else  
		this->view_contr.printWinner(1);


	return;

}
void Controller :: queen_turn(int x,int y, bool flag1)
{
	while (check_for_next_black_queen(x, y))
	{
		this->check_possibility_black_queen(x, y, flag1);
		int x1 = x, y1 = y;
		while (this->model_contr.pos_matrix[y1][x1] != 6 && x1 > 0 && y1 > 0)
		{
			x1--, y1--;
		}
		if (this->model_contr.pos_matrix[y1][x1] == 6)
		{
			this->model_contr.pos_matrix[y][x] = 1;
			this->model_contr.pos_matrix[y1][x1] = -2;
			this->take_white_from_board(x, x1, y, y1);
			this->clear_pos();
			x = x1; y = y1;
			continue;
		}
		 x1 = x, y1 = y;
		while (this->model_contr.pos_matrix[y1][x1] != 6 && x1 < 9 && y1 > 0)
		{
			x1++, y1--;
		}
		if (this->model_contr.pos_matrix[y1][x1] == 6)
		{
			this->model_contr.pos_matrix[y][x] = 1;
			this->model_contr.pos_matrix[y1][x1] = -2;
			this->take_white_from_board(x, x1, y, y1);
			this->clear_pos();
			x = x1; y = y1;
			continue;
		}
		x1 = x, y1 = y;
		while (this->model_contr.pos_matrix[y1][x1] != 6 && x1 < 9 && y1 < 9)
		{
			x1++, y1++;
		}
		if (this->model_contr.pos_matrix[y1][x1] == 6)
		{
			this->model_contr.pos_matrix[y][x] = 1;
			this->model_contr.pos_matrix[y1][x1] = -2;
			this->take_white_from_board(x, x1, y, y1);
			this->clear_pos();
			x = x1; y = y1;
			continue;
		}
		 x1 = x, y1 = y;
		while (this->model_contr.pos_matrix[y1][x1] != 6 && x1 > 0 && y1 < 9)
		{
			x1--, y1++;
		}
		if (this->model_contr.pos_matrix[y1][x1] == 6)
		{
			this->model_contr.pos_matrix[y][x] = 1;
			this->model_contr.pos_matrix[y1][x1] = -2;
			this->take_white_from_board(x, x1, y, y1);
			this->clear_pos();
			x = x1; y = y1;
			continue;
		}
	}
}