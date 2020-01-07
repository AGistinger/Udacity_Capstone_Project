#ifndef _FISH_FOOD_H_
#define _FISH_FOOD_H_

//Fish Food class to set the size of the food block within the game and renderer
class Fish_Food
{
public:
    Fish_Food();
    Fish_Food(int size);
    Fish_Food(const Fish_Food& source);
    Fish_Food(Fish_Food&& source);
    ~Fish_Food();

    const double get_size() const;
    void set_size(int num);

private:
    int size;
};

#endif //_FISH_FOOD_H_