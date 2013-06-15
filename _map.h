#include "mydate.h"
#include "map.h"

/**
 * @author Admin
 * @date 27.05.13
 */

namespace templateSpace {

/** Hier wird die Größe des aktuellen Baumen zurückgegeben
 * @brief Map<KeyT,T>::getSize
 * @return
 */

template<class KeyT, class T>
size_t templateSpace::Map<KeyT,T>::getSize() const{

    return m_size;

}


/**
 *Methode Clont einen Knoten gibt den neuen Konten zurück.
 * @brief Map<KeyT,T>::Node::clone
 * @param parent
 * @return
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::clone(Map<KeyT,T>::Node* parent){
    Map<KeyT,T>::Node* n = new Map<KeyT,T>::Node(m_pair.first,m_pair.second,parent);

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

/**
 * Operatorüberladung, setzt die Message der aktuellen Node
 */
template<class KeyT, class T>
void Map<KeyT,T>::Node::operator= (Map<KeyT,T>::mapped_t mapped){
    this->m_pair.second = mapped;
}



/** Gibt den Root knoten der Map zurück
 * @brief Map<KeyT,T>::getRootNode
 * @return
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::getRootNode(){
     return Map<KeyT,T>::m_root;
 }

/** Setzt den Wert zu einem Key neu, konveriert einen übergebenen Int zu gültigem String
 * @brief Map<KeyT,T>::setMessage
 * @param key
 * @param nr
 */
template<class KeyT, class T>
void Map<KeyT,T>::setMessage(Map<KeyT,T>::key_t key ,Map<KeyT,T>::mapped_t str){
    Node& n = find(*m_root,key);
    n.m_pair.second = str;
}


/**
 * Methode sucht in einer Map nach der ersten Node und gibt diese zurück
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::findFirst() {
    if (m_left != 0) {
        return m_left->findFirst();
    } else {
        return this;
    }
}

/**
 * Methode sucht in einer Map nach dem letzten Node und gibt diese zurück
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::findLast() {
    if (m_right != 0) {
        return m_right->findLast();
    } else {
        return this;
    }
}



/** Operatorüberladung Methode sucht einen Node der zum gegebenen Key passt,
  * existiert dieser nicht, wird er neu angelegt und dann zurück gegeben.
  * @brief Map<KeyT,T>::operator []
  * @param key
  * @return
  */
template<class KeyT, class T>
 typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::operator[](const Map<KeyT,T>::key_t& key){

     if(this->getRootNode()==0){

         m_root = new Map<KeyT,T>::Node(key, mapped_t() ,0);

         this->m_size++;
         return m_root->m_pair.second;

      }
        else{
         return find(*m_root,key).m_pair.second;
     }


 }

 /** Methode erhöht den Map internen Counter und gibt den aktuellen Wert zurück
   * @brief Map<KeyT,T>::increaseCounter
   * @return
   */
 template<class KeyT, class T>
  int Map<KeyT,T>::increaseCounter(){
    counter++;
    return counter;

  }

  /**
   * Methode gibt einen Iterator mit dem m_root = 0 zurück als zeichen das
   * es einen Node nicht gibt.
   */
  template<class KeyT, class T>
  typename Map<KeyT,T>::Iterator Map<KeyT,T>::end() {
          return Map<KeyT,T>::Iterator(0);
      }


 /**
 *  Methode gibt den ersten Node in einer übergebenen Map als Iteratorinstanz zurück.
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Iterator Map<KeyT,T>::begin() {
          if (m_root == 0) return Map<KeyT,T>::end();
          return Map<KeyT,T>::Iterator(m_root->findFirst());
      }


 /**
 * Methode gibt den letzen Wert einer Map als Iteratorinstanz zurück
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Iterator Map<KeyT,T>::beginFromLast() {
          if (m_root == 0) return Map<KeyT,T>::end();
          return Map<KeyT,T>::Iterator(m_root->findLast());
      }

 /**
 * Methode ruft den find befehl der Map auf dieser
 * gibt den wert der find methode des Nodes zurück.
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Iterator Map<KeyT,T>::find(const Map<KeyT,T>::key_t& key) {
        return Map<KeyT,T>::Iterator(m_root->find(key));
    }


 /**
 * Methode gibt den mapped_t des m_pair des m_root des Iterators zurück.
 */
template<class KeyT, class T>
typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::Iterator::value() {
      return this->m_root->value();
  }

  /**
 * Methode gibt den mapped_t des Nodes zurück.
 */
template<class KeyT, class T>
typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::Node::value(){
      return m_pair.second;
  }


  /**
  * gibt den key_t aus dem m_pair des Nodes zurück
  */
template<class KeyT, class T>
typename Map<KeyT,T>::key_t& Map<KeyT,T>::Node::key(){
      return m_pair.first;
 }

  /**
  * gibt den key_t aus dem m_pair des m_root des iterators zurück
  */
 template<class KeyT, class T>
 typename Map<KeyT,T>::key_t& Map<KeyT,T>::Iterator::key() {
      return this->m_root->key();
  }


 /**
 *  Methode überschreibt den = operator ersetzt den aktuellen m_root des Iterators
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Iterator& Map<KeyT,T>::Iterator::operator=(const Map<KeyT,T>::Iterator& rhs) {
          m_root = rhs.m_root;
          return *this;
      }

 /**
 * überscheibt den == operator, gibt true oder false zurück,
 * je nachdem ob die beiden Iteratoren gleich sind
 */
template<class KeyT, class T>
bool Map<KeyT,T>::Iterator::operator==(const Map<KeyT,T>::Iterator &rhs) {
          if(this->m_root == rhs.m_root) return true; else return false;
      }

/**
 * überscheibt den != operator und gibt true oder false zurück je nachdem ob die
 * beiden Iteratoren gleich sind
 */
template<class KeyT, class T>
bool Map<KeyT,T>::Iterator::operator!=(const Map<KeyT,T>::Iterator &rhs) {
          return !(*this == rhs);
      }



  /** Operatorüberladung, die Methode überschreibt die = Methode und bewirkt
  * das eine übergebene Map neu erzeugt und alle Werte kopiert werden
  * @brief Map<KeyT,T>::operator =
  * @param rhs
  */
 template<class KeyT, class T>
 void Map<KeyT,T>::operator= (Map& rhs){
     Map();
     this->m_root = rhs.m_root->clone(0);
     this->counter = rhs.counter;
     this->m_size = rhs.m_size;

 }



 /** Find Methode, sucht rekursiv nach dem übergebenen Key den Suchbaum durch,
  * existiert dieser nicht wird er angelegt und dann returnd
  * @brief Map<KeyT,T>::find
  * @param last - beim ersten Aufruf sollte der Root übergeben werden, danach wird in der
  * Rekursion der Nächste Node übergeben
  * @param key
  * @return Node bei dem der Key matched
  */
 template<class KeyT, class T>
 typename Map<KeyT,T>::Node& Map<KeyT,T>::find(Map<KeyT,T>::Node& last,const Map<KeyT,T>::key_t& key){
     if(last.m_pair.first==key){

         return last;
     }
     else if(last.m_pair.first<key){
         if(last.getRightNode()==0){

             last.setRightNode(*last.insert(key,last));
             m_size++;
             return *last.getRightNode();

         }  else{
            return Map<KeyT,T>::find(*last.getRightNode(),key);
            }
     } else {
         if(last.getLeftNode()==0){
             last.setLeftNode(*last.insert(key,last));
             m_size++;
             return *last.getLeftNode();
         }
         return find(*last.getLeftNode(),key);
     }


 }

 /** Sucht rekursiv den ganzen Suchbaum durch, wird der Node nicht gefunden wird eine constante
  * ohne Inhalt zurückgegeben.
  * @brief Map<KeyT,T>::findReadOnly
  * @param last
  * @param key
  * @return
  */
 template<class KeyT, class T>
 const typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::findReadOnly(Map<KeyT,T>::Node& last,const Map<KeyT,T>::key_t& key)const {
     if(last.m_pair.first==key){
         return last.m_pair.second;
     }
     else if(last.m_pair.first<key){
         if(last.getRightNode()==0){
            return Map<KeyT,T>::M_NOT_IN_MAP;

         }  else{
            return Map<KeyT,T>::findReadOnly(*last.getRightNode(),key);
            }
     } else {
         if(last.getLeftNode()==0){
             return Map<KeyT,T>::M_NOT_IN_MAP;
         }
         return findReadOnly(*last.getLeftNode(),key);
     }


 }

 /** Operatorüberladung zum suchen eines Wertes zu einem gegebenen Key,
  * ohne schreibrechte ( es wird kein neuer Node erzeugt )
  * @brief Map<KeyT,T>::operator []
  * @param key
  * @return
  */
 template<class KeyT, class T>
 const typename Map<KeyT,T>::mapped_t& Map<KeyT,T>::operator[](const key_t key) const{
     return findReadOnly(*m_root,key);

 }


 /** Methode prüft in einem Suchbaum ob ein Wert vorhanden ist
  * @brief Map<KeyT,T>::contains
  * @param last - Sollte zum Beginn der Root Node sein, wird danach
  * von der Rekursion neu gesetzt
  * @param key
  * @return
  */
 template<class KeyT, class T>
 bool Map<KeyT,T>::contains(Map<KeyT,T>::Node& last, const Map<KeyT,T>::key_t& key){
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
  * @brief Map<KeyT,T>::Node::insert
  * @param key
  * @param mapped
  * @param upNode
  * @return
  */
 template<class KeyT, class T>
 typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::insert(const Map<KeyT,T>::key_t& key, Map<KeyT,T>::Node& upNode){

     Map<KeyT,T>::Node *n = new Map<KeyT,T>::Node(key, mapped_t(),&upNode);

    return n;
}

 /** Methode überschreibt den UpNode des aktuellen Nodes
  * @brief Map<KeyT,T>::Node::setUpNode
  * @param x
  */
 template<class KeyT, class T>
 void Map<KeyT,T>::Node::setUpNode(Node& x){
    this->m_up = &x;
}

 /** Methode überschreibt den LeftNode des aktuellen Nodes
 * @brief Map<KeyT,T>::Node::setLeftNode
 * @param x
 */
template<class KeyT, class T>
void Map<KeyT,T>::Node::setLeftNode(Node& x){
    this->m_left = &x;
}

/** Methode überschreibt den RigthNode des aktuellen Nodes
 * @brief Map<KeyT,T>::Node::setRightNode
 * @param x
 */
template<class KeyT, class T>
void Map<KeyT,T>::Node::setRightNode(Node& x){
    this->m_right = &x;
}


/** Methode gibt den UpNode des aktuellen Nodes zurück
 * @brief Map<KeyT,T>::Node::getUpNode
 * @return
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::getUpNode(){
    return this->m_up;
}

/** Methode gibt den LeftNode des aktuellen Nodes zurück
 * @brief Map<KeyT,T>::Node::getLeftNode
 * @return
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::getLeftNode(){
    return this->m_left;
}

/** Methode gibt den RightNode des aktuellen Nodes zurück
 * @brief Map<KeyT,T>::Node::getRightNode
 * @return
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Node* Map<KeyT,T>::Node::getRightNode(){
    return this->m_right;
}



/**
 * operator ++ überladung .. Iterator wird ein weiter gesetzt
 * und gibt ihn zurück
 */
template<class KeyT, class T>
typename Map<KeyT,T>::Iterator& Map<KeyT,T>::Iterator::operator++() {
        Map<KeyT,T>::key_t currentKey = key();
        Map<KeyT,T>::Node* up = m_root->getUpNode();
        Map<KeyT,T>::Node* right = m_root->getRightNode();
        if (right != 0 && up != 0) {
            if (up->key() > currentKey) {
                if (up->key() < right->key()) {
                    m_root = up;
                } else {
                    m_root = right;
                    bool reachedTheBottom = false;
                    Map<KeyT,T>::Node* currentNode = m_root;
                    while (!reachedTheBottom) {
                        currentNode = currentNode->getLeftNode();
                        if (currentNode != 0) {
                            if (currentNode->key() < m_root->key()) {
                                m_root = currentNode;
                            }
                        } else {
                            reachedTheBottom = true;
                        }
                    }
                }
            } else {
                m_root = right;
                bool reachedTheBottom = false;
                Map<KeyT,T>::Node* currentNode = m_root;
                while (!reachedTheBottom) {
                    currentNode = currentNode->getLeftNode();
                    if (currentNode != 0) {
                        if (currentNode->key() < m_root->key()) {
                            m_root = currentNode;
                        }
                    } else {
                        reachedTheBottom = true;
                    }
                }
            }
        }

        if (right == 0 && up != 0) {
            if (up->key() > currentKey) {
                m_root = up;
            } else {
                bool reachedTheTop = false;
                 Map<KeyT,T>::Node* currentNode = m_root;
                while (!reachedTheTop) {
                    currentNode = currentNode->getUpNode();
                    if (currentNode != 0) {
                        if (currentNode->key() > currentKey) {
                            m_root = currentNode;
                            reachedTheTop = true;
                        }
                    } else {
                        m_root = 0;
                        reachedTheTop = true;
                    }
                }
            }
        }
        if (right != 0 && up == 0) {
            m_root = right;
            bool reachedTheBottom = false;
          Map<KeyT,T>::Node* currentNode = m_root;
            while (!reachedTheBottom) {
                currentNode = currentNode->getLeftNode();
                if (currentNode != 0) {
                    if (currentNode->key() <  m_root->key()) {
                        m_root = currentNode;
                    }
                } else {
                    reachedTheBottom = true;
                }
            }
        }
        return *this;
    }


}
