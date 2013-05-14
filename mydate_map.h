#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H
#import "mydate.h"


using namespace MyDate;

class Map{

public:
    typedef MyDate::Date key_t;
    typedef std::string mapped_t;

protected:
    class Node{

    public:
        std::pair<key_t,mapped_t> m_pair; // key/value
        Node* m_up, *m_left, *m_right; //pointers to other nodes

    };

    Node* m_root; //root node of the search tree
    size_t m_size; // number of elements in tree
    const mapped_t M_NOT_IN_MAP;  //return val if not in map

    size_t getSize() const;
};


#endif // MYDATE_MAP_H
