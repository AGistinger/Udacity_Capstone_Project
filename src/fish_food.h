#ifndef _FISH_FOOD_H_
#define _FISH_FOOD_H_

class Fish_Food
{
public:
    Fish_Food();
    Fish_Food(int size);
    Fish_Food(const Fish_Food& source);
    Fish_Food(Fish_Food&& source);
    ~Fish_Food();

    int get_size();
    void set_size(int num);

private:
    int size;
};

#endif //_FISH_FOOD_H_