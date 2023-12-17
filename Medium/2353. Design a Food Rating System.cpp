class FoodRatings 
{
    public:

    unordered_map <string, int> rating;
    unordered_map <string, string> food2Cuisine;
    unordered_map <string, set <pair <int, string>>> cuisineRating;

    FoodRatings(vector <string>& foods, vector <string>& cuisines, vector <int>& ratings) 
    {    
        int i = 0, noOfFoods = foods.size();

        for(; i < noOfFoods; i++)
        {
            rating[foods[i]] = ratings[i];
            food2Cuisine[foods[i]] = cuisines[i];
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) 
    {  
        auto& cuisine = food2Cuisine[food];

        cuisineRating[cuisine].erase({-rating[food], food});
        cuisineRating[cuisine].insert({-newRating, food});

        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) 
    {    
        return (*cuisineRating[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */