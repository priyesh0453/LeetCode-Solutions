class ParkingSystem 
{
    public:

    int count_Big = 0, count_Medium = 0, count_Small = 0;

    ParkingSystem(int big, int medium, int small) 
    {
        count_Big = big, count_Medium = medium, count_Small = small;
    }
    
    bool addCar(int carType) 
    {
        if(carType == 1 && count_Big >= 1)
        {
            count_Big--;
            return true;
        }
        else if(carType == 2 && count_Medium >= 1)
        {
            count_Medium--;
            return true;
        }
        else if(carType == 3 && count_Small >= 1)
        {
            count_Small--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */