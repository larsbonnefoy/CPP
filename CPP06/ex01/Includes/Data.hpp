#ifndef DATA_HPP
#define DATA_HPP
struct Data {
    private:
        int _randomInt;

    public:
        Data(void);
        Data(int randonData);
        Data(const Data &other);
        ~Data(void);
        Data &operator=(const Data &other);
    
        int     getData(void);
        void    setData(int randonDatavoid);
};
#endif
