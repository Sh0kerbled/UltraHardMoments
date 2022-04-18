#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
#include <fstream>
using namespace std;

//task 1

/*template<typename p1>
class Pair1 {
    p1 a;
    p1 b;
public:
    Pair1(p1 _a, p1 _b) : a(_a), b(_b) { }
    ~Pair1() {}
    //p1<void>first() mojno lo bilo tak sdelat?
    p1 first() const;
    p1 second() const { return b; }
    void First(p1 _a) { a = _a; }
};
template<typename p1>
p1 Pair1<p1>::first() const { return a; }*/


//task 2
template<typename p1, typename p2>
class Pair1 {
protected:
    p1 a;
    p2 b;
public:
    Pair1(p1 _a, p2 _b) : a(_a), b(_b) { }
    ~Pair1() {}
    virtual p1 first() const { return a; }
    p2 second() const;
};
template<typename p1, typename p2>
p2 Pair1<p1, p2>::second() const { return b; }

template<typename Value>
class Pair2 : public Pair1<std::string, Value> {
    std::string a;
public:
    Pair2(std::string c, Value d) : Pair1<std::string, Value>(c, d), a(c) { }
    ~Pair2() {}
    std::string first() const;
};

//task 3
template <typename p6>
class StringValuePair : public Pair1 <string,p6> {
public:
    StringValuePair(const string& first, const p6& second) :
        Pair1<string,p6>(first,second) {}
};

//task 4
class Card {
public:
    enum cardvalue
    {
        one = 1,
        two = 2,
        three = 3,
        four = 4,
        five = 5,
        six = 6,
        seven = 7,
        eight = 8,
        nine = 9,
        ten = 10,
        jack = 11,
        queen = 12,
        king = 13
    };
    enum suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
};

template<typename type>
/*class Hand
{
public:
    Hand()
    {
        m_Cards.reserve(7);
    }

    virtual ~Hand()
    {
        Clear();
    }

    void Add(Card* pCard)
    {
        m_Cards.push_back(pCard);
    }

    void Clear()
    {
        std::vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete* iter;
            *iter = nullptr;
        }

        m_Cards.clear();
    }

    int GetValue() const
    {
        if (m_Cards.empty() || m_Cards[0]->GetValue() == 0)
            return 0;

        int total = 0;
        std::vector<Card*>::const_iterator iter;

        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            total += (*iter)->GetValue();

        bool containsAce = false;
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
            if ((*iter)->GetValue() == Card::ACE)
                containsAce = true;

        if (containsAce && total <= 11) total += 10;

        return total;
    }*

protected:
    std::vector<Card*> m_Cards;
};*/

class GenericPlayer : public Hand
{
private:
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
protected:
    string theName;
public:
    GenericPlayer(const string& name = " ") : theName(name) { }

    virtual ~GenericPlayer();

    virtual bool IsHitting() const = 0;

    bool IsBoosted() const
    {
        return (GetValue() > 21);
    }

    void Bust() const
    {
        cout << theName << " It's too much." << endl;
    }
};


int main()
{
    Pair1<int, double> p1(6, 7.8);
    cout << p1.first()<<" " << p1.second() << endl;

    const Pair1<double, int> p2(3.4, 5);
    cout << p2.first()<< " " << p2.second() << endl;

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}