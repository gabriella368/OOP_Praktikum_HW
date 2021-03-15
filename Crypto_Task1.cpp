#include <iostream>
#include <cstring>

class Crypto {
public:

	//defaut constructor
	Crypto() {
		strcpy_s(this->name, 9, "currency");
		this->lastPrice = 0;
		this->currentPrice = 0;
	}

	//parameterized constructor
	Crypto(const char* other_name, double other_lastPrice, double other_currentPrice) {
		strcpy_s(this->name, strlen(other_name) + 1, other_name);
		lastPrice = other_lastPrice;
		currentPrice = other_currentPrice;
	}

	void percentageDifference(double lastPrice, double currentPrice) {
		double result = 100 * abs(currentPrice - lastPrice) / ((currentPrice + lastPrice) / 2);
		std::cout << "The percentage difference between the two prices is: " << result << "%" << std::endl;
	}

	void printCrypto() const {
		std::cout << "The name of this crypto currency is: " << name << std::endl;
		std::cout << "The last price of this crypto currency is: " << lastPrice << "$" <<std::endl;
		std::cout << "The current price of this crypto currency is: " << currentPrice << "$" << std::endl;
	}

	//setters 
	void setName(const char* other_name) {
		strcpy_s(this->name, strlen(other_name) + 1, other_name);
	}
	void setLastPrice(double other_lastPrice) {
		this->lastPrice = other_lastPrice;
	}
	void setCurrentPrice(double other_currentPrice) {
		this->currentPrice = other_currentPrice;
	}

	//getters
	const char* getName() const {
		return name;
	}
	double getLastPrice() const {
		return lastPrice;
	}
	double getCurrentPrice() const {
		return currentPrice;
	}

private:
	char name[31];
	double lastPrice;
	double currentPrice;
};

int main()
{
	Crypto currency1;
	currency1.setName("Gcoin");
	currency1.setLastPrice(90);
	currency1.setCurrentPrice(200);
	currency1.printCrypto();
	currency1.percentageDifference(90, 200);
	
}