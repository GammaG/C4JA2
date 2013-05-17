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
        Node *m_up, *m_left, *m_right; //pointers to other nodes

        explicit Node(const key_t key, const mapped_t mapped):
            m_pair(key,mapped), m_up(0), m_left(0), m_right(0) {}



        void setUpNode(Node& x);
        void setLeftNode(Node* x);
        void setRightNode(Node* x);
        Node* getUpNode();
        Node* getLeftNode();
        Node* getRightNode();
        void setMessage(mapped_t str);


        Node* insert(const key_t& key, const mapped_t mapped, Node& upNode);




        };

public:
    Node* m_root; //root node of the search tree
    size_t m_size; // number of elements in tree
    const mapped_t M_NOT_IN_MAP;  //return val if not in map
    int counter;

    Map():m_root(0),counter(0){}

    size_t getSize() const;

    Node* getRootNode();

    bool contains(Node& last, const key_t& key);

    mapped_t& operator[](const key_t& key);

    Node& find(Node& last ,const key_t& key);


};


#endif // MYDATE_MAP_H
