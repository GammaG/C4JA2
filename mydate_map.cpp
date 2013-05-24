#include "mydate.h"
#include "mydate_map.h"

/**
 * @author Admin
 * @date 24.05.13
 */
using namespace MyDate;

/** Hier wird die Größe des aktuellen Baumen zurückgegeben
 * @brief Map::getSize
 * @return
 */
size_t Map::getSize() const{

    return m_size;

}


/**
 *Methode Clont einen Knoten gibt den neuen Konten zurück.
 * @brief Map::Node::clone
 * @param parent
 * @return
 */
Map::Node* Map::Node::clone(Map::Node* parent){
    Map::Node* n = new Map::Node(m_pair.first,m_pair.second,parent);

    if(m_left != 0){
        n->m_left = m_left->clone(n);

    } else{
        n->m_left = 0;
    }

    if(m_right != 0){
        n->m_right = m_right->clone(n);

    } else{
        n->m_right = 0;
    }

return n;
}


/** Methode konvertiert einen übergebenen Int wert zu einem String und gibt diesen zurück.
 * @brief convertInt
 * @param number
 * @return
 */
std::string convertInt(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

/** Gibt den Root knoten der Map zurück
 * @brief Map::getRootNode
 * @return
 */
Map::Node* Map::getRootNode(){
     return Map::m_root;
 }

/** Setzt den Wert zu einem Key neu, konveriert einen übergebenen Int zu gültigem String
 * @brief Map::setMessage
 * @param key
 * @param nr
 */
void Map::setMessage(Map::key_t key ,int nr){
    Node& n = find(*m_root,key);
    n.m_pair.second = convertInt(nr);
}

/** Setzt den Wert zu einem Key neu
 * @brief Map::setMessage
 * @param key
 * @param str
 */
void Map::setMessage(Map::key_t key ,Map::mapped_t str){
    Node& n = find(*m_root,key);
    n.m_pair.second = str;
}


/** Operatorüberladung Methode sucht einen Node der zum gegebenen Key passt,
  * existiert dieser nicht, wird er neu angelegt und dann zurück gegeben.
  * @brief Map::operator []
  * @param key
  * @return
  */
 Map::mapped_t& Map::operator[](const Map::key_t& key){

     if(this->getRootNode()==0){

         m_root = new Map::Node(key, convertInt(increaseCounter()),0);

         this->m_size++;

      }
        else{
         return find(*m_root,key).m_pair.second;
     }


 }

 /** Methode erhöht den Map internen Counter und gibt den aktuellen Wert zurück
   * @brief Map::increaseCounter
   * @return
   */
  int Map::increaseCounter(){
    counter++;
    return counter;

  }

  /** Operatorüberladung, die Methode überschreibt die = Methode und bewirkt
  * das eine übergebene Map neu erzeugt und alle Werte kopiert werden
  * @brief Map::operator =
  * @param rhs
  */
 void Map::operator= (Map& rhs){
     Map();
     this->m_root = rhs.m_root->clone(0);
     this->counter = rhs.counter;
     this->m_size = rhs.m_size;

 }



 /** Find Methode, sucht rekursiv nach dem übergebenen Key den Suchbaum durch,
  * existiert dieser nicht wird er angelegt und dann returnd
  * @brief Map::find
  * @param last - beim ersten Aufruf sollte der Root übergeben werden, danach wird in der
  * Rekursion der Nächste Node übergeben
  * @param key
  * @return Node bei dem der Key matched
  */
 Map::Node& Map::find(Map::Node& last,const Map::key_t& key){
     if(last.m_pair.first==key){
         //last.setMessage(convertInt(increaseCounter()));
         return last;
     }
     else if(last.m_pair.first<key){
         if(last.getRightNode()==0){
             last.setRightNode(*last.insert(key, convertInt(increaseCounter()),last));
             m_size++;
             return *last.getRightNode();

         }  else{
            return Map::find(*last.getRightNode(),key);
            }
     } else {
         if(last.getLeftNode()==0){
             last.setLeftNode(*last.insert(key, convertInt(increaseCounter()),last));
             m_size++;
             return *last.getLeftNode();
         }
         return find(*last.getLeftNode(),key);
     }


 }

 /** Sucht rekursiv den ganzen Suchbaum durch, wird der Node nicht gefunden wird eine constante
  * ohne Inhalt zurückgegeben.
  * @brief Map::findReadOnly
  * @param last
  * @param key
  * @return
  */
 const Map::mapped_t& Map::findReadOnly(Map::Node& last,const Map::key_t& key)const {
     if(last.m_pair.first==key){
         return last.m_pair.second;
     }
     else if(last.m_pair.first<key){
         if(last.getRightNode()==0){
            return Map::M_NOT_IN_MAP;

         }  else{
            return Map::findReadOnly(*last.getRightNode(),key);
            }
     } else {
         if(last.getLeftNode()==0){
             return Map::M_NOT_IN_MAP;
         }
         return findReadOnly(*last.getLeftNode(),key);
     }


 }

 /** Operatorüberladung zum suchen eines Wertes zu einem gegebenen Key,
  * ohne schreibrechte ( es wird kein neuer Node erzeugt )
  * @brief Map::operator []
  * @param key
  * @return
  */
 const Map::mapped_t& Map::operator[](const key_t key) const{
     return findReadOnly(*m_root,key);

 }


 /** Methode prüft in einem Suchbaum ob ein Wert vorhanden ist
  * @brief Map::contains
  * @param last - Sollte zum Beginn der Root Node sein, wird danach
  * von der Rekursion neu gesetzt
  * @param key
  * @return
  */
 bool Map::contains(Map::Node& last, const Map::key_t& key){
     if(last.m_pair.first==key){
         return true;
     } else if(last.m_pair.first<key){
         if(last.getRightNode()==0){
             return false;
         }
         return contains(*last.getRightNode(),key);
     } else {
         if(last.getLeftNode()==0){
             return false;
         }
         return contains(*last.getLeftNode(),key);
     }
     return false;

 }


 /** Methode erzeugt einen Neuen Node und gibt ihn zurück
  * @brief Map::Node::insert
  * @param key
  * @param mapped
  * @param upNode
  * @return
  */
 Map::Node* Map::Node::insert(const Map::key_t& key, const Map::mapped_t mapped, Map::Node& upNode){

    Map::Node *n = new Map::Node(key,mapped,&upNode);

    return n;
}

 /** Methode überschreibt den UpNode des aktuellen Nodes
  * @brief Map::Node::setUpNode
  * @param x
  */
 void Map::Node::setUpNode(Node& x){
    this->m_up = &x;
}

 /** Methode überschreibt den LeftNode des aktuellen Nodes
 * @brief Map::Node::setLeftNode
 * @param x
 */
void Map::Node::setLeftNode(Node& x){
    this->m_left = &x;
}

/** Methode überschreibt den RigthNode des aktuellen Nodes
 * @brief Map::Node::setRightNode
 * @param x
 */
void Map::Node::setRightNode(Node& x){
    this->m_right = &x;
}


/** Methode gibt den UpNode des aktuellen Nodes zurück
 * @brief Map::Node::getUpNode
 * @return
 */
Map::Node* Map::Node::getUpNode(){
    return this->m_up;
}

/** Methode gibt den LeftNode des aktuellen Nodes zurück
 * @brief Map::Node::getLeftNode
 * @return
 */
Map::Node* Map::Node::getLeftNode(){
    return this->m_left;
}

/** Methode gibt den RightNode des aktuellen Nodes zurück
 * @brief Map::Node::getRightNode
 * @return
 */
Map::Node* Map::Node::getRightNode(){
    return this->m_right;
}

