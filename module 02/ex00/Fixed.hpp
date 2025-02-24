#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
    private:
        static const int FRACT_BIT = 8;
        int fix_point;

    public:
        Fixed(){
            fix_point = 0;
        };
        ~Fixed(){};
    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif