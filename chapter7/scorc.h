#ifndef SCORC_H
#define SCORC_H



class Score
    {
    private:
        double score;
    public:
        Score();
        ~Score();
        double getscore() const;
        void setscore(double value);
    };

#endif

