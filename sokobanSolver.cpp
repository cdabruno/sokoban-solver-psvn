/* This program reads a state from stdin and prints out its successors.

Copyright (C) 2013 by the PSVN Research Group, University of Alberta
*/


#include <queue>
#include <unordered_set>
#include <stack>
#include <climits>
#include <fstream>
#include <iostream>

#define  MAX_LINE_LENGTH 999 
#define HAVE_BWD_MOVES

using namespace std;



struct StateNode{
    state_t data;
    int hValue;
    int cost;

    public:
        StateNode(state_t st, int hV, int c){
            data = st;
            hValue = hV;
            cost = c;
        }

};

struct Comparator
{
    bool operator()(const StateNode& lhs, const StateNode& rhs)
    {
        return (lhs.hValue + lhs.cost) > (rhs.cost + rhs.hValue);
    }
};

struct Comparator2
{
    bool operator()(const StateNode& lhs, const StateNode& rhs)
    {
        return (lhs.hValue + lhs.cost) < (rhs.cost + rhs.hValue);
    }
};

inline bool operator == (state_t const& lhs, state_t const& rhs)
{
    return !compare_states(&lhs, &rhs);
}

namespace std {
  template <>
  struct hash<state_t>
  {
    size_t operator()(const state_t & t) const
    {
        return hash_state(&t);

        /*char stringState[100];
        sprint_state(stringState, 100, &t);
        char * pch;
        pch = strtok (stringState," ");
        int counter = 1;
        int hashValue = 0;
        while (pch != NULL)
        {
            hashValue += atoi(pch) * counter;
            pch = strtok (NULL, " ,.-");
            counter++;
        }

        return hashValue; */
    }
  };
  
}





int heuristic(state_t state){
    return 1;
}

int testGoal(state_t state){
    if(is_goal(&state)){
        return 1;
    }
    else{
        return 0;
    }
}





int search(stack<StateNode> path, unordered_set<state_t> visited, int bound){
    StateNode node = path.top();
    


    //print_state(stdout, &node.data);
    //printf("\n");

    int aux;



    int estimate = node.cost + node.hValue;

   

    if(testGoal(node.data)){
        *solutionLength = node.cost;
        return -1;
    }

    if(estimate > bound){ 
        return estimate;
    }


    int min = INT_MAX;

    state_t state;
    state_t child;
    ruleid_iterator_t iter; 
    int ruleid; 

    state = node.data;


    init_fwd_iter( &iter, &state );  // initialize the child iterator 
    while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {

	    apply_fwd_rule( ruleid, &state, &child );

        priority_queue<StateNode, vector<StateNode>, Comparator2> auxQueue;
        
        if(visited.count(child) == 0){
            auxQueue.push(StateNode(child, heuristic(child), 1+ node.cost));
            visited.insert(child);
        }
        //print_state(stdout, &child);
        //printf("\n");
        while(!auxQueue.empty()){
            path.push(auxQueue.top());
            aux = search(path, visited, bound);

            if(aux == -1){
                return -1;
            }
            if(aux < min){
                min = aux;
                //std::cout << "\nMin: " << min << "\n";
            }
            auxQueue.pop();
            path.pop();
        }
        
        
    }
    
    return min;
    

}

void IDA_Star(state_t startState){
    

    stack<StateNode> path;
    unordered_set<state_t> visitedList;

    //cost
    
    int bound = heuristic(startState);

    path.push(StateNode(startState, bound, 0));
    visitedList.emplace(startState);

    while(true){
        
  
        //std::cout << " bound " << bound << "\n";

        int aux = search(path, visitedList, bound);
        
        if (aux == -1){
            break;
        }
        else if(aux == INT_MAX){
            break;
        }
        else{
            bound = aux;

        } 
        
          
    }
    //std::cout << "Estados por bucket IDA*: " << visitedList.size()  << "\n";
}

int a_Star(state_t startState){

    

    priority_queue<StateNode, vector<StateNode>, Comparator> fringe;
    unordered_set<state_t> visitedList;

    //starting fringe with start state
    fringe.push(StateNode(startState, heuristic(startState), 0));

    //new visited list
    visitedList.emplace(startState);

    state_t state;
    // VARIABLES FOR ITERATING THROUGH state's SUCCESSORS
    state_t child;
    ruleid_iterator_t iter; // ruleid_terator_t is the type defined by the PSVN API successor/predecessor iterators.
    int ruleid ; // an iterator returns a number identifying a rule
    //int childCount;
    //int heu;

    
    //int i = 0;
    while(!testGoal(fringe.top().data)){
   // while(i < 5){
        //i++;


        state = fringe.top().data;
        fringe.pop();

      

        //print_state(stdout, &state);
        //printf("\n");
        //heu = heuristic(state);
        //printf("%d", heu);
        //printf("\n");

        init_fwd_iter( &iter, &state );  // initialize the child iterator 
        while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {

	        apply_fwd_rule( ruleid, &state, &child );

            
            if(visitedList.count(child) == 0){
                fringe.push(StateNode(child, heuristic(child), 1+fringe.top().cost));
                visitedList.emplace(child);
            }
        }
        
    }

    //std::cout << "Estados por bucket A*: " << visitedList.size() << "\n";

    return fringe.top().cost;

}


int main( int argc, char **argv )
{
    
    ruleid_iterator_t bwdIter; // ruleid_terator_t is the type defined by the PSVN API successor/predecessor iterators.
    int bwdruleid ; // an iterator returns a number identifying a rule
  

    state_t child;


// VARIABLES FOR INPUT
    char str[ MAX_LINE_LENGTH +1 ] ;
    
    state_t state; // state_t is defined by the PSVN API. It is the type used for individual states.
   

// CONVERT THE STRING TO A STATE
    int flag = 0;
    int maxDim = 0;

    string mapa;
    string startState = "";
    ifstream file("sokobanTest.txt");

    while (getline (MyReadFile, mapa)) {
        if(mapa.length() > maxDim){
            maxDim = mapa.length();
        }
    }

    file.close();

    ifstream file("sokobanTest.txt");

    for(int i = 0;i < maxDim;i++){
        if(getline(file, mapa)){
            flag = 0;
            for(string::size_type x = 0; x < mapa.size(); x++){
                if(!flag){
                    if(mapa[x] != "#"){
                        startState = startState + "W "; 
                    }
                    else{
                        startState = startState + "W ";
                        flag = 1;
                    }
                }
                else{
                    if(mapa[x] == "#"){
                        startState = startState + "W "; 
                        flag = 0;
                    }
                    else{
                        if(mapa[x] == "@"){
                            startState = startState + "P ";
                        }
                        if(mapa[x] == "."){
                            startState = startState + "R ";
                        }
                        else{
                            startState = startState + "N ";
                        }
                    }
                }
            }
        }
        else{
            for(int j = 0; j < maxDim;j++){
                startState = startState + "W ";
            }
        }
    }

    

    
            
    read_state(startState, &state );
    
   


            a_Star(state);
          
            
        }

        cout << "sucesso";
        
    }


    return 0;
} // end main




