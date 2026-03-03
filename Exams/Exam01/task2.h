#ifndef TASK2_H
#define TASK2_H
 
#include <string>
#include <ostream>

namespace dse {
    enum class Suit { clubs, diamonds, hearts, spades };
    enum class Rank {two = 2, three, four, five, 
                    six, seven, eight, nine, ten,
                    jack, queen,king, ace };

class Nonable;
class Comparable;

class Card : public Nonable, public Comparable {
    public:
      Card(Suit s, Rank r);

    Suit suit() const;
    Rank rank() const;

    virtual void setSuit(Suit s) = 0;
    virtual void setRank(Rank r)= 0;

    virtual std::string toString() const override;

    virtual bool operator<(Card const& other) const override;
    virtual bool operator==(Card const& other) const override;
    virtual bool operator!=(Card const& other) const { return !(*this == other); }

private:
    Suit m_suit;
    Rank m_rank;
};

std::ostream& operator<<(std::ostream& os, Card const& c);

struct CompareBySuitThenRank {
    bool operator() (Card const& a, Card const& b) const;
};

}

#endif