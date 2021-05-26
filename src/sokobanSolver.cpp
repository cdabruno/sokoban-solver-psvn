/* This program reads a state from stdin and prints out its successors.

Copyright (C) 2013 by the PSVN Research Group, University of Alberta
*/


#include <queue>
#include <unordered_set>
#include <stack>
#include <climits>
#include <fstream>
#include <iostream>
#include <ctime>
#include <string.h>

#define  MAX_LINE_LENGTH 999 
#define HAVE_BWD_MOVES

using namespace std;



struct StateNode{
    state_t data;
    int hValue;
    int cost;
    string path;

    public:
        StateNode(state_t st, int hV, int c, string p){
            data = st;
            hValue = hV;
            cost = c;
            path = p;
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



// if flagHeuristic == 1: goal count
// else: blind

int heuristic(state_t state, int flagHeuristic, int goalVector[], int goalIndex){
	if(is_goal(&state)){
        return 0;
    }

    if(!(flagHeuristic == 1)){
        return 1;
    }
    else{

 
        char stringState[MAX_LINE_LENGTH] = ""; 
 

        int heuristicValue = 0;

        int stringLen = sprint_state(stringState, MAX_LINE_LENGTH, &state);
       
        
        for(int i = 0; i < goalIndex;i++){
            if(stringState[goalVector[i]] != 'R'){
                heuristicValue++;
            }
        }

        
        
        return heuristicValue;
    }


}







/*
int search(stack<StateNode> path, unordered_set<state_t> visited, int bound, int flagHeuristic){
    StateNode node = path.top();
    


    //print_state(stdout, &node.data);
    //printf("\n");

    int aux;



    int estimate = node.cost + node.hValue;

   

    if(is_goal(&(node.data))){
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
            auxQueue.push(StateNode(child, heuristic(child, flagHeuristic), 1+ node.cost, node.path+" "+get_fwd_rule_label(ruleid)));
            visited.insert(child);
        }
        //print_state(stdout, &child);
        //printf("\n");
        while(!auxQueue.empty()){
            path.push(auxQueue.top());
            aux = search(path, visited, bound, flagHeuristic);

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

void IDA_Star(state_t startState, int flagHeuristic){
    

    stack<StateNode> path;
    unordered_set<state_t> visitedList;

    //cost
    
    int bound = heuristic(startState, flagHeuristic);

    path.push(StateNode(startState, bound, 0, ""));
    visitedList.emplace(startState);

    while(true){
        
  
        //std::cout << " bound " << bound << "\n";

        int aux = search(path, visitedList, bound, flagHeuristic);
        
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
}*/

int a_Star(state_t startState, int flagHeuristic, int *nodesExpanded, int goalVector[], int goalIndex, int showSteps){
    priority_queue<StateNode, vector<StateNode>, Comparator> fringe;
    unordered_set<state_t> visitedList;

    //starting fringe with start state
    fringe.push(StateNode(startState, heuristic(startState, flagHeuristic, goalVector, goalIndex), 0, ""));

    *nodesExpanded = 1;

    //new visited list
    //visitedList.emplace(startState);

    state_t state;
    // VARIABLES FOR ITERATING THROUGH state's SUCCESSORS
    state_t child;
    ruleid_iterator_t iter; // ruleid_terator_t is the type defined by the PSVN API successor/predecessor iterators.
    int ruleid ; // an iterator returns a number identifying a rule
    //int childCount;
    //int heu;

    int i = 0;
    
    //int i = 0;
    while(fringe.empty() == false) {
        i++;

        

		StateNode node = fringe.top();
        state = node.data;
        string auxPath = node.path;
        int auxCost = fringe.top().cost;
        fringe.pop();

        *nodesExpanded = *nodesExpanded + 1;

        if(is_goal(&state) == true) {
            if(showSteps){
                cout << "Passos: ";
			    cout << auxPath;
                cout << "\n";
            }
            
            return auxCost;
		}			
			
		if (visitedList.find(state) == visitedList.end()) {
            
           

			visitedList.insert(state);
			//heu = heuristic(state);
			//printf("%d", heu);
			//printf("\n");

			init_fwd_iter( &iter, &state );  // initialize the child iterator 
			while( ( ruleid = next_ruleid( &iter ) ) >= 0 ) {
				apply_fwd_rule( ruleid, &state, &child );
				fringe.push(StateNode(child, heuristic(child, flagHeuristic, goalVector, goalIndex), get_fwd_rule_cost(ruleid)+auxCost, auxPath+" "+get_fwd_rule_label(ruleid)));
			}	
		}      
    }

    //std::cout << "Estados por bucket A*: " << visitedList.size() << "\n";

    //print_state(stdout, &state);
    printf("\n");

    return -1;

}


int main( int argc, char **argv )
{
    
    ruleid_iterator_t bwdIter; // ruleid_terator_t is the type defined by the PSVN API successor/predecessor iterators.
    int bwdruleid ; // an iterator returns a number identifying a rule
  

    int flagHeuristic = 0;
    int flagSteps = 0;

    state_t child;

    if(argc > 1){
        for(int i = 0; i < argc; i++){
            if(strcmp(argv[i], "goalCount") == 0){
                flagHeuristic = 1;
            }
            if(strcmp(argv[1], "showSteps") == 0){
                flagSteps = 1;
            }
        }
    }


// VARIABLES FOR INPUT
    char str[ MAX_LINE_LENGTH +1 ] ;
    
    state_t state; // state_t is defined by the PSVN API. It is the type used for individual states.
   

// CONVERT THE STRING TO A STATE
    int flag = 0;
    int maxDim = 0;


// DEFINING INITIAL STATE
    string mapa;
    string startState = "";
    ifstream file("sokobanLevel.txt");

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

    ifstream file2("sokobanLevel.txt");
    string hash = "#";
    string cpyright = "@";
    string dot = ".";
    string blank = " ";
    string dollarSign = "$";
    string plusSign = "+";
    string starSign = "*";

    
    int goalVector[50];
    int goalIndex = 0;

    //generate initial state

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
                        if(mapa[x] == dollarSign[0]){
                            startState = startState + "R ";
                        }
                        if(mapa[x] == blank[0]){
                            startState = startState + "N ";
                        }
                        if(mapa[x] == dot[0]){
                            startState = startState + "N ";
                            goalVector[goalIndex] = ((i*maxDim) + x)*2;
                            goalIndex++; 
                        }
                        if(mapa[x] == plusSign[0]){
                            startState = startState + "P ";
                            goalVector[goalIndex] = ((i*maxDim) + x)*2;
                            goalIndex++; 
                        }
                        if(mapa[x] == starSign[0]){
                            startState = startState + "R ";
                            goalVector[goalIndex] = ((i*maxDim) + x)*2;
                            goalIndex++; 
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

    //cout << "Estado inicial: ";

    //print_state(stdout, &state);

    //cout << "\n";

    int nodesExpanded;
    
   
    clock_t begin = clock();

    int result = a_Star(state, flagHeuristic, &nodesExpanded, goalVector, goalIndex, flagSteps);

    clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    if(result == -1){
        cout << "Sem solução.\nNodos expandidos: " << nodesExpanded << "\nTempo decorrido: " << elapsed_secs << "\n\n";
    }
    else{
        cout << "Solução encontrada!\nCusto: " << result << "\nNodos expandidos: " << nodesExpanded << "\nTempo decorrido: " << elapsed_secs << "\n\n";
    }

          
            
        

   
        
    


    return 0;
} // end main




