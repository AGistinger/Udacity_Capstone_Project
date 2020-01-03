#include "fish_food.h"
#include <utility>

Fish_Food::Fish_Food()
    : size(20) 
    {}

Fish_Food::Fish_Food(int size)
    : size(size) 
    {}

Fish_Food::~Fish_Food() {}

Fish_Food::Fish_Food(const Fish_Food& source)
    : size(source.size)
    {}

Fish_Food::Fish_Food(Fish_Food&& source)
{
    size = std::move(source.size);
}

int Fish_Food::get_size()
{
    return size;
}

void Fish_Food::set_size(int num)
{
    size = num;
}