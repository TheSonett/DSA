// hh <= 23 && mm <= 59

#include <iostream>

int main()
{
	int launch_time_HH, launch_time_MM;
	int travel_time_HH, travel_time_MM;

	std::cin >> launch_time_HH;
	std::cin >> launch_time_MM;

	std::cin >> travel_time_HH;
	std::cin >> travel_time_MM;

	int totalTravelTime_MM = (travel_time_HH * 60) + travel_time_MM;

	for (int i = 1; i <= totalTravelTime_MM; i++) {
		launch_time_MM += 1;
		if (launch_time_MM > 59) {
			launch_time_MM = 0;

			launch_time_HH += 1;
			if (launch_time_HH > 23) {
				launch_time_HH = 0;
			}
		}
	}

	std::cout << launch_time_HH << " " << launch_time_MM;

	std::cin.get();
}