#include "Stock.h"
int Stock::getAmount()
{
	return stockAmount;
}

void Stock::updateStock(int n_s)
{
	stockAmount = n_s;
}

Stock::Stock()
{
	stockAmount = 0;
}

Stock::~Stock()
{
}