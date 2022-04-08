#include "field.h"

int main() {		
	Field MainField; //Создание нового поля
	MainField.PrintCages();	//печать поля
	std::cout << "           \n";
	std::cout << MainField.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";	
	Ship fleet[10] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 }; // 0..3 = "1", 4..6 = "2", 7..8 = "3, 9 = "4" 	

	fleet[0].SetDirection("UP");
	MainField.PutShip(-1, 0, fleet, 0);	
	fleet[1].SetDirection("RIGHT");
	MainField.PutShip(0, 9, fleet, 1);
	fleet[2].SetDirection("LEFT");
	MainField.PutShip(9, 0, fleet, 2);
	fleet[3].SetDirection("DOWN");
	MainField.PutShip(9, 9, fleet, 3);
	fleet[4].SetDirection("UP");
	fleet[4].SetDirection("DOWN");
	MainField.PutShip(3, 4, fleet, 4);
	fleet[5].SetDirection("DOWN");
	MainField.PutShip(6, 0, fleet, 5);
	fleet[6].SetDirection("RIGHT");
	MainField.PutShip(6, 8, fleet, 6);
	fleet[7].SetDirection("LEFT");
	MainField.PutShip(0, 6, fleet, 7);
	fleet[8].SetDirection("RIGHT");
	MainField.PutShip(7, 8, fleet, 8);
	MainField.PutShip(4, 7, fleet, 8);
	MainField.PutShip(4, 7, fleet, 8);
	fleet[9].SetDirection("DOWN");
	MainField.PutShip(7, 3, fleet, 9);		

	MainField.PrintCages();	//печать поля
	std::cout << "           \n";
	std::cout << MainField.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";

	MainField.StrikeCages(0, 0, fleet);
	MainField.StrikeCages(0, 9, fleet);
	MainField.StrikeCages(9, 0, fleet);
	MainField.StrikeCages(9, 9, fleet);
	MainField.StrikeCages(9, 4, fleet);
	MainField.StrikeCages(3, 4, fleet);
	MainField.StrikeCages(3, 4, fleet);
	MainField.StrikeCages(2, 2, fleet);
	MainField.StrikeCages(9, 5, fleet);
	MainField.StrikeCages(5, 0, fleet);
	MainField.StrikeCages(6, 9, fleet);
	MainField.StrikeCages(6, 7, fleet);
	MainField.StrikeCages(0, 0, fleet);
	MainField.StrikeCages(0, 6, fleet);
	MainField.StrikeCages(3, 9, fleet);	

	MainField.PrintCages();	//печать поля
	std::cout << "           \n";
	std::cout << MainField.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";

	MainField.StrikeCages(0, 4, fleet);
	MainField.StrikeCages(1, 5, fleet);
	MainField.StrikeCages(3, 7, fleet);
	MainField.StrikeCages(2, 8, fleet);
	MainField.StrikeCages(6, 4, fleet);
	MainField.StrikeCages(7, 4, fleet);

	MainField.PrintCages();	//печать поля
	std::cout << "           \n";
	std::cout << MainField.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";

	MainField.StrikeCages(0, 5, fleet);
	MainField.StrikeCages(6, 0, fleet);
	MainField.StrikeCages(8, 4, fleet);
	MainField.StrikeCages(3, 8, fleet);
	MainField.StrikeCages(6, 8, fleet);
	MainField.StrikeCages(1, 0, fleet);
	MainField.StrikeCages(2, 0, fleet);
	MainField.StrikeCages(4, 4, fleet);

	MainField.StrikeCages(-1, 4, fleet);
	MainField.StrikeCages(4, -1, fleet);
	MainField.StrikeCages(2, 10, fleet);
	MainField.StrikeCages(10, 4, fleet);
	MainField.StrikeCages(-4, -4, fleet);
	MainField.StrikeCages(10, 10, fleet);

	MainField.PrintCages();	//печать поля
	std::cout << "           \n";
	std::cout << MainField.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";

	/*fleet[9].SetDirection("RIGHT");	
	MainField.PutShip(0, 0, fleet, 9);	
	MainField.PutShip(5, 5, fleet, 4);
	fleet[4].SetDirection("LEFT");
	MainField.PutShip(6, 2, fleet, 5);
	MainField.PutShip(3, 7, fleet, 0);

	std::cout << MainField << "\n";
	std::cout << "           \n";
	std::cout << MainField.ReturnSCount() << " ship(s) on the field \n";
	std::cout << "           \n";

	std::cout << fleet[9] << "\n";
	std::cout << fleet[2] << "\n";
	std::cout << fleet[0] << "\n";*/
	return 0;
}