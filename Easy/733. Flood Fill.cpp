class Solution 
{
    private:
        void fillColor(vector<vector<int>>& image, int sr, int sc, int color, int current_Color)
        {
            if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != current_Color) return;

            image[sr][sc] = color;

            fillColor(image, sr + 1, sc, color, current_Color);
            fillColor(image, sr - 1, sc, color, current_Color);
            fillColor(image, sr, sc + 1, color, current_Color);
            fillColor(image, sr, sc - 1, color, current_Color);
        }

    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
        {
            if(image[sr][sc] == color) return image;

            fillColor(image, sr, sc, color, image[sr][sc]);

            return image;           
        }
};