#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {

    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(const Brain &other);
        ~Brain(void);
        Brain &operator=(const Brain &other);

        std::string getIdea(int index) const;
        void        setIdea(std::string idea);
        void        replaceIdea(std::string idea, int index);
};

#endif // !BRAIN_HPP
