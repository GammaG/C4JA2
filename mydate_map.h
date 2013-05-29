#ifndef MYDATE_MAP_H
#define MYDATE_MAP_H
#import "mydate.h"

/**
 * @author Admin
 * @date 24.05.13
 */
using namespace MyDate;
namespace MyDate {


/** Deklarartion der Klasse Map, diese beinhaltet die Klassendefinition der Node,
 * die Suchfunktionen, sowie den root Node und die Anzahl
 * @brief The Map class
 */
class Map{
public:
    typedef MyDate::Date key_t;
    typedef std::string mapped_t;


    /** Klasse Node behinhaltet ein Wertepaar auf einem Key und einem Wert
     * @brief The Node class
     */
    class Node{

    public:
        std::pair<key_t,mapped_t> m_pair; // key/value
        Node *m_up, *m_left, *m_right; //pointers to other nodes

        explicit Node(const key_t key, const mapped_t mapped, Node* parent):
            m_pair(key,mapped), m_up(parent), m_left(0), m_right(0) {}


        explicit Node(Node* clone):
            m_pair(clone->m_pair.first,clone->m_pair.second), m_up(clone->getUpNode()), m_left(clone->getLeftNode()), m_right(clone->getRightNode()) {}


        void setUpNode(Node& x);
        void setLeftNode(Node& x);
        void setRightNode(Node& x);
        Node* getUpNode();
        Node* getLeftNode();
        Node* getRightNode();
        Node* clone(Node* clone);




        Node* insert(const key_t& key, const mapped_t mapped, Node& upNode);

        ~Node(){

            if(m_left != 0){
            delete(m_left);
            }
            if(m_left != 0){
            delete(m_right);
            } }


        };


    Node* m_root; //root node of the search tree
    size_t m_size; // number of elements in tree
    const mapped_t M_NOT_IN_MAP;  //return val if not in map
    int counter;

    Map():m_root(0),counter(0),m_size(0){}

    size_t getSize() const;

    Node* getRootNode();

    void setMessage(key_t key ,mapped_t str);
    void setMessage(key_t key ,int nr);


    bool contains(Node& last, const key_t& key);

    mapped_t& operator[](const key_t& key);

    const mapped_t& operator[](const key_t key) const;

    Node& find(Node& last , const key_t& key);
    const mapped_t& findReadOnly(Node& last, const key_t& key)const;

    int increaseCounter();

    void operator= (Map& map);

    ~Map() {
        if(m_root != 0){
        delete(m_root);
        }

    }


};
}

#endif // MYDATE_MAP_H
