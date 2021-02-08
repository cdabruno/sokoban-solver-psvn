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
	if(is_goal(&state)){
        return 0;
    }
    else{
        return 1;
    }
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
    while(fringe.empty() == false) {
		StateNode node = fringe.top();
        state = node.data;
        fringe.pop();

        if(is_goal(&state) == true) {
			return node.cost;
		}			
			
		if (visitedList.find(state) !=  visitedList.end()) {
			print_state(stdout, &state);
			printf("\n");
			visitedList.insert(state);
			//heu = heuristic(state);
			//printf("%d", heu);
			//printf("\n");

			init_fwd_iter( &iter, &state );  // initialize the child iterator 
			while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
				apply_fwd_rule( ruleid, &state, &child );
				fringe.push(StateNode(child, heuristic(child), 1+fringe.top().cost));
			}	
		}      
    }

    //std::cout << "Estados por bucket A*: " << visitedList.size() << "\n";

    cout << "Estado atingido: ";

    state = fringe.top().data;
    print_state(stdout, &state);
    printf("\n");

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

    int auxDim = 0;
    while (getline (file, mapa)) {
        if(int(mapa.length()) > maxDim){
            maxDim = mapa.length();
        }
        auxDim++;
    }
    if(auxDim > maxDim){
        maxDim = auxDim;
    }

    file.close();

    ifstream file2("sokobanTest.txt");
    string hash = "# a";
    string cpyright = "@";
    string dot = ".";
    string blank = " ";
    string goalSymbol = "$";

    for(int i = 0;i < maxDim;i++){
        if(getline(file2, mapa)){
            flag = 0;
            for(int x = 0;x < maxDim; x++){
                if(x < int(mapa.length())){
                    if(!flag){
                        if(mapa[x] == hash[0]){
                            startState = startState + "W "; 
                            flag = 1;
                        }
                        else{
                            startState = startState + "W ";
                        }
                    }
                    else{
                        if(mapa[x] == hash[0]){
                            startState = startState + "W "; 
                        }
                        if(mapa[x] == cpyright[0]){
                            startState = startState + "P ";
                        }
                        if(mapa[x] == dot[0]){
                            startState = startState + "R ";
                        }
                        if(mapa[x] == blank[0]){
                            startState = startState + "N ";
                        }
                        if(mapa[x] == goalSymbol[0]){
                            startState = startState + "N ";
                        }
                    }
                }else{
                    startState = startState + "W ";
                }
            }
        }
        else{
            for(int j = 0; j < maxDim;j++){
                startState = startState + "W ";
            }
        }
    }

    
    const char * c = startState.c_str();
    
    
      
    read_state(c, &state );
    
   
   

    a_Star(state);
          
            
        

   
        
    


    return 0;
} // end main




