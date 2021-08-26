#pragma once
class Stock {
private:
	int stockAmount;
public:
	int getAmount();
	void updateStock(int n_s);
	Stock();
	~Stock();
};

