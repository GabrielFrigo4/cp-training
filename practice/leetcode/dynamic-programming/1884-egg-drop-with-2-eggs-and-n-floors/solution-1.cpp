class Solution {
public:
    int twoEggDrop(int n) {
        const float a = 1;
        const float b = 1;
        const float c = -2*n;
        const float delta = b*b - 4*a*c;
        const float x = (-b + sqrt(delta)) / (2*a);
        return static_cast<int>(ceil(x));
    }
};
