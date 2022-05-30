// Chantu Bantu Question Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int testcase;
	std::cin >> testcase;

	for (int x = 0; x < testcase; x++)
	{
		int n, g;
		std::cin >> n;
		std::cin >> g;

		int a;

		std::vector<int> prices{};
		for (int i = 0; i < g; i++) {
			std::cin >> a;
			prices.push_back(a);
		}

		std::sort(prices.begin(), prices.end());

		int minSum = 0;
		for (int i = 0; i < n; i++) {
			minSum += prices[i];
		}

		std::cout << minSum << "\n";
	}

	std::cin.get();
}
