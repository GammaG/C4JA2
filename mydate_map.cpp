#include "mydate.h"
#include "mydate_map.h"

using namespace MyDate;


size_t Map::getSize() const{

    return m_size;

}

Map::Node* Map::getRootNode(){
     return Map::m_root;
 }

void Map::Node::setMessage(Map::mapped_t str){
    this->m_pair.second = str;

}

 Map::mapped_t& Map::operator[](const Map::key_t& key){

     if(this->getRootNode()==0){
         Map::Node(key,""+this->counter++);
         this->m_size++;
        //return this->M_NOT_IN_MAP;
      }
        else{
         return find(*this->getRootNode(),key);
     }



   // return this->M_NOT_IN_MAP;
 }

 Map::Node& Map::find(Map::Node& last,const Map::key_t& key){
     if(last.m_pair.first==key){
         return last;
     }
     else if(last.m_pair.first<key){
         if(last.getRightNode()==0){
             last.setRightNode(last.insert(key, ""+this->counter++,last));

         }  else{
            return Map::find(*last.getRightNode(),key);
            }
     } else {
         if(last.getLeftNode()==0){
             last.setLeftNode(last.insert(key, ""+this->counter++,last));
         }
         return find(*last.getLeftNode(),key);
     }


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

     Map::Node node(key,mapped);
     node.setUpNode(upNode);
     return &node;
}


 void Map::Node::setUpNode(Node& x){
    this->m_up = x;
}

void Map::Node::setLeftNode(Node* x){
    this->m_left = x;
}

void Map::Node::setRightNode(Node* x){
    this->m_right = x;
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

