import <iostream>;
import <string>;

import airline;

int main(){

	class air::AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost{myTicket.calculatePriceInDollars()};
	std::cout << "This ticket will cost $" << cost << std::endl;

}
