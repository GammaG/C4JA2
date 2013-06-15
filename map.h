#ifndef MAP_H
#define MAP_H

/**
 * @author Admin
 * @date 27.05.13
 */

namespace templateSpace {

/** Deklarartion der Klasse Map, diese beinhaltet die Klassendefinition der Node,
 * die Suchfunktionen, sowie den root Node und die Anzahl
 * @brief The Map class
 */
template<class KeyT, class T> class Map{
public:
    typedef KeyT key_t;
    typedef T mapped_t;


    /** Klasse Node behinhaltet ein Wertepaar auf einem Key und einem Wert
     * @brief The Node class
     */
    class Node{

    public:
        std::pair<key_t,mapped_t> m_pair; // key/value
        Node *m_up, *m_left, *m_right; //pointers to other nodes

        Node(const key_t key, const mapped_t mapped, Node* parent):
            m_pair(key,mapped), m_up(parent), m_left(0), m_right(0) {}


        Node(Node* clone):
            m_pair(clone->m_pair.first,clone->m_pair.second), m_up(clone->getUpNode()), m_left(clone->getLeftNode()), m_right(clone->getRightNode()) {}


        void setUpNode(Node& x);
        void setLeftNode(Node& x);
        void setRightNode(Node& x);
        Node* getUpNode();
        Node* getLeftNode();
        Node* getRightNode();
        Node* clone(Node* clone);
        Node* findFirst();
        Node* findLast();
        key_t& key();
        mapped_t& value();
        void operator= (mapped_t mapped);



        Node* insert(const key_t& key, Node& upNode);

        ~Node(){
            if(m_left != 0){
            delete(m_left);
            }
            if(m_right != 0){
            delete(m_right);
            }

        }


        };

    class Iterator{
    public:

        Node* m_root;

        Iterator(Node* node = 0 ): m_root(node){}
        Iterator(const Iterator& rhs): m_root(rhs.m_root) {}

        Iterator& operator=(const Iterator& rhs);
        mapped_t& value();
        key_t& key();
        Iterator& operator++();
        Iterator& operator--();
        bool operator==(const Iterator &rhs);
        bool operator!=(const Iterator &rhs);





    };

    Node* m_root; //root node of the search tree
    size_t m_size; // number of elements in tree
    const mapped_t M_NOT_IN_MAP;  //return val if not in map

    int counter;

    Map():m_root(0),counter(0),m_size(0){}

    size_t getSize() const;

    Node* getRootNode();

    void setMessage(key_t key ,mapped_t str);

    bool contains(Node& last, const key_t& key);

    mapped_t& operator[](const key_t& key);

    const mapped_t& operator[](const key_t key) const;

    Node& find(Node& last , const key_t& key);
    const mapped_t& findReadOnly(Node& last, const key_t& key)const;

    std::string convertInt(int number);

    int increaseCounter();

    void operator= (Map& map);

    Iterator begin();
    Iterator beginFromLast();
    Iterator end();
    Iterator find(const key_t& value);

    ~Map() {
        if(m_root != 0){
        delete(m_root);
        }}

    };
}

#include "_map.h"
#endif // MAP_H
