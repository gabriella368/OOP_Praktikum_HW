#include <iostream>
#include <cstring>

class Film {
public:
	//defaut constructor
	Film() {
		this->filmName = new char[1];
		this->producerName = new char[1];
		this->awards = 0;
	}

	//parametarized constructor
	Film(const Film& other) {
		this->copy(other);
	}

	Film& operator=(const Film& other) {
		if (this != &other) {
			this->erase();
			this->copy(other);
		}
		return *this;
	}

	~Film() {
		this->erase();
	}

	void print() const {
		std::cout << "The name of the film is: " << filmName << std::endl;
		std::cout << "The name of the producer is: " << producerName << std::endl;
		std::cout << "The number of awards that the film has is: " << awards << std::endl;
	}

	void setFilmName(const char* other_filmName) {
		strcpy_s(this->filmName, strlen(other_filmName) + 1, other_filmName);
	}
	void setProducerName(const char* other_producerName) {
		strcpy_s(this->producerName, strlen(other_producerName) + 1, other_producerName);
	}
	void setAwards(int other_awards) {
		this->awards = other_awards;
	}

	const char* getFilmName() const {
		return filmName;
	}
	const char* getProducerName() const {
		return producerName;
	}
	int getAwards() const {
		return awards;
	}
private:
	char* filmName;
	char* producerName;
	int awards;

	void copy(const Film& other) {
		this->filmName = new char[strlen(other.filmName) + 1];
		strcpy_s(this->filmName, strlen(other.filmName) + 1, other.filmName);

		this->producerName = new char[strlen(other.producerName) + 1];
		strcpy_s(this->producerName, strlen(other.producerName) + 1, other.producerName);
		this->awards = other.awards;
	}
	void erase() {
		delete[] this->filmName;
		delete[] this->producerName;
	}
};

int main()
{
	Film film1;
	film1.setFilmName("The closed door");
	film1.setProducerName("Luise Frank");
	film1.setAwards(2);
	film1.print();
}