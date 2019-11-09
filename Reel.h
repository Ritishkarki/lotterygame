// reel linked list template file
#include <cstdlib>
#include "iostream"
#include "ReelNode.hpp"
#include <numeric>
#include <array>
#include <random>
#include <algorithm>
template <typename T>
class ReelList{
    private:
        int length = 0;
        ReelNode* tail = nullptr;

    public:
        //constructor 
        ReelList(){
            // intialise list from the constructor
            initialiseList();
        }

        // insert all the components of the list
        void initialiseList(){
            // array containing all the elements of slots
            char ReelList[] = {'A','A','A','A','B','B','B','C','C','7'};

            // shuffle the array and put them in circular linked list
            std::array<char*, sizeof ReelList> ptrs;
            std::iota(ptrs.begin(), ptrs.end(), ReelList);
            std::mt19937 g(std::random_device{}());
            std::shuffle(ptrs.begin(), ptrs.end(), g);

            // iterate and add elements to the list
            for(char* p: ptrs) PutItem(*p);
        }

        //insert a new node in an empty list
        void insertInEmpty(ReelNode*& tail,T t){
            // if last is not nullptr then list is not empty, so return
            if (tail != nullptr)
            return;
            
            // allocate memory for node
            ReelNode* temp = new ReelNode;
            
            // Assign the data.
            temp -> data = t;
            tail = temp;
            
            // Create the link.
            tail->next = tail;
            
            length++; 
        }

        void PutItem(T t){
            //if list is empty then add the node by calling insertInEmpty
            if (tail == nullptr){
                insertInEmpty(tail, t);
                return;
            }

            //else create a new node and add in the list
            ReelNode* temp = new ReelNode;
            temp -> data = t;
            temp -> next = tail -> next;
            tail -> next = temp;
            length++;
        };

        // loop through the linked list in random fashion and return data in that node
        T spin(){
            int spinLoop = std::rand()%100 + 1;
            for (int i = 0; i < spinLoop; i++){
                tail = tail -> next;
            }
            T data = tail->data;
            return data;
        }
};
