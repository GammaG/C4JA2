#include "mydate.h"
#include "mydate_map.h"

using namespace MyDate;


size_t Map::getSize() const{

    return m_size;

}

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




Map::Node* Map::getRootNode(){
     return Map::m_root;
 }

void Map::Node::setMessage(Map::mapped_t str){
    this->m_pair.second = str;

}

 Map::mapped_t& Map::operator[](const Map::key_t& key){

     if(this->getRootNode()==0){
        m_root = new Map::Node(key,""+this->counter++,0);

         this->m_size++;

      }
        else{
         return find(*m_root,key).m_pair.second;
     }


 }

 void Map::operator= (Map& rhs){
     Map();
     this->m_root = rhs.m_root->clone(0);
     this->counter = rhs.counter;
     this->m_size = rhs.m_size;

 }


 Map::Node& Map::find(Map::Node& last,const Map::key_t& key){
     if(last.m_pair.first==key){
         last.setMessage(""+this->counter++);
         return last;
     }
     else if(last.m_pair.first<key){
         if(last.getRightNode()==0){
             last.setRightNode(*last.insert(key, ""+this->counter++,last));
             m_size++;

         }  else{
            return Map::find(*last.getRightNode(),key);
            }
     } else {
         if(last.getLeftNode()==0){
             last.setLeftNode(*last.insert(key, ""+this->counter++,last));
             m_size++;
         }
         return find(*last.getLeftNode(),key);
     }


 }


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

 const Map::mapped_t& Map::operator[](const key_t key) const{
     return findReadOnly(*m_root,key);

 }



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


 Map::Node* Map::Node::insert(const Map::key_t& key, const Map::mapped_t mapped, Map::Node& upNode){

    Map::Node *n = new Map::Node(key,mapped,&upNode);

    return n;
}


 void Map::Node::setUpNode(Node& x){
    this->m_up = &x;
}

void Map::Node::setLeftNode(Node& x){
    this->m_left = &x;
}

void Map::Node::setRightNode(Node& x){
    this->m_right = &x;
}

Map::Node* Map::Node::getUpNode(){
    return this->m_up;
}

Map::Node* Map::Node::getLeftNode(){
    return this->m_left;
}

Map::Node* Map::Node::getRightNode(){
    return this->m_right;
}

